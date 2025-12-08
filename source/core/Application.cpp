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
	m_views.push_back(std::make_shared<views::FirstView>(dmoV->visibility(), scdV->visibility(), m_clear_color));
	m_views.push_back(scdV);
	m_views.push_back(dmoV);
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
		m_mainWindow.render(m_clear_color);
	}
}

void Application::reportError(const std::string& iMessage) {
	log_error("Application reported error: {}", iMessage);
	m_state = State::Error;
}

auto createApplication([[maybe_unused]] int iArgc, [[maybe_unused]] char* iArgv[]) -> std::shared_ptr<Application> {
	return std::make_shared<Application>();
}

}// namespace mvi::core
