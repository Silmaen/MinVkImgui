/**
 * @file Application.cpp
 * @author Silmaen
 * @date 07/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */
#include "pch.h"

#include "Application.h"

#include "Log.h"
#include "actions/FileActions.h"
#include "event/AppEvent.h"
#include "views/DemoView.h"
#include "views/FirstView.h"
#include "views/SecondView.h"


namespace mvi::core {

Application* Application::m_instance = nullptr;

Application::Application() {
	log_info("Starting application.");
	m_instance = this;
	m_mainWindow.init();
	if (m_state == State::Error)
		return;
	// Create views
	const auto scdV = std::make_shared<views::SecondView>();
	scdV->hide();
	const auto dmoV = std::make_shared<views::DemoView>();
	m_views.push_back(std::make_shared<views::FirstView>(dmoV->visibility(), scdV->visibility(), m_clearColor));
	m_views.push_back(scdV);
	m_views.push_back(dmoV);
	// Create actions
	m_actions.push_back(std::make_shared<actions::QuitAction>());
	m_actions.back()->setShortcut({.key = KeyCode::A, .modifiers = {.ctrl = true}});

	// Set callback for events
	m_mainWindow.setEventCallback([this]<typename T>(T&& ioEvent) -> auto { onEvent(std::forward<T>(ioEvent)); });

	m_state = State::Running;
}

Application::~Application() {
	log_info("Shutting down application.");
	// Cleanup
	m_mainWindow.close();
}

void Application::run() {
	// Main loop
	while (m_state == State::Running || m_state == State::Waiting) {
		if (m_mainWindow.shouldClose()) {
			m_state = State::Closed;
			continue;
		}
		m_mainWindow.newFrame();
		if (m_state != State::Running)
			continue;
		for (const auto& view: m_views) { view->update(); }
		m_mainWindow.render(m_clearColor);
	}
}

void Application::reportError(const std::string& iMessage) {
	log_error("Application reported error: {}", iMessage);
	m_state = State::Error;
}

void Application::requestClose() { m_state = State::Closed; }

void Application::onEvent(event::Event& ioEvent) {
	event::EventDispatcher dispatcher(ioEvent);
	dispatcher.dispatch<event::WindowCloseEvent>([this]<typename T>(const T&) -> auto {
		requestClose();
		return true;
	});
	dispatcher.dispatch<event::WindowResizeEvent>([]<typename T>(const T&) -> auto {
		log_trace("Resize Event");
		return true;
	});
	// does any action handle the event?
	for (const auto& action: m_actions) {
		if (ioEvent.handled)
			return;
		action->onEvent(ioEvent);
	}
	// does any view handle the event?
	for (const auto& view: m_views) {
		if (ioEvent.handled)
			return;
		view->onEvent(ioEvent);
	}
	m_mainWindow.onEvent(ioEvent);
}

auto Application::isKeyPressed(const KeyCode& iKeycode) const -> bool { return m_mainWindow.isKeyPressed(iKeycode); }
auto Application::getModifiers() const -> Modifiers { return m_mainWindow.getModifiers(); }

auto createApplication([[maybe_unused]] int iArgc, [[maybe_unused]] char* iArgv[]) -> std::shared_ptr<Application> {
	return std::make_shared<Application>();
}

}// namespace mvi::core
