/**
 * @file Application.h
 * @author Silmaen
 * @date 07/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */

#pragma once

#include "MainWindow.h"
#include "views/View.h"

#include <array>
#include <list>
#include <memory>

namespace mvi::core {

/**
 * @brief Class Application.
 */
class Application {
public:
	/**
	 * @brief Default constructor.
	 */
	Application();
	/**
	 * @brief Default destructor.
	 */
	virtual ~Application();

	Application(const Application&) = delete;
	Application(Application&&) = delete;
	auto operator=(const Application&) -> Application& = delete;
	auto operator=(Application&&) -> Application& = delete;

	/**
	 * @brief Access to Application instance.
	 * @return Single instance of application.
	 */
	static auto get() -> Application& { return *m_instance; }

	/**
	 * @brief Only check for app existence.
	 * @return True if application is instanced.
	 */
	static auto instanced() -> bool { return m_instance != nullptr; }

	/**
	 * @brief Application states.
	 */
	enum class State : uint8_t {
		Created,///< The application is created.
		Running,///< The application is running.
		Waiting,///< The application is waiting.
		Closed,///< The application is closed.
		Error,///< The application is in error state.
	};

	/**
	 * @brief Get the application state.
	 * @return The current state.
	 */
	[[nodiscard]]
	auto getState() const -> const State& {
		return m_state;
	}

	void run();

	/**
	 * @brief Request Error report.
	 * @param[in] iMessage The error message.
	 */
	void reportError(const std::string& iMessage);

	void setWaiting() {
		if (m_state == State::Running)
			m_state = State::Waiting;
	}
	void setRunning() {
		if (m_state == State::Waiting)
			m_state = State::Running;
	}

private:
	/// The application Instance.
	static Application* m_instance;
	/// The application state.
	State m_state = State::Created;
	/// The main window.
	MainWindow m_mainWindow;
	//// The views list.
	std::list<std::shared_ptr<views::View>> m_views;
	/// The clear color.
	std::array<float, 4> m_clear_color = {0.45f, 0.55f, 0.60f, 1.00f};
};

auto createApplication(int iArgc, char* iArgv[]) -> std::shared_ptr<Application>;

}// namespace mvi::core
