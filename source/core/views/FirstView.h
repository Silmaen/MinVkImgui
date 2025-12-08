/**
 * @file FirstView.h
 * @author Silmaen
 * @date 07/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */

#pragma once

#include "View.h"
#include <array>

namespace mvi::core::views {

/**
 * @brief Class FirstView.
 */
class FirstView : public View {
public:
	FirstView() = delete;
	/**
	 * @brief Default constructor.
	 */
	FirstView(bool& iShowDemoWindow, bool& iShowAnotherWindow, std::array<float, 4>& iClearColor);
	/**
	 * @brief Default destructor.
	 */
	~FirstView() override;

	FirstView(const FirstView&) = delete;
	FirstView(FirstView&&) = delete;
	auto operator=(const FirstView&) -> FirstView& = delete;
	auto operator=(FirstView&&) -> FirstView& = delete;
	/**
	 * @brief The update function to implement in derived classes.
	 */
	void onUpdate() override;

private:
	/// A simple counter.
	int m_counter = 0;
	/// A float value.
	float m_float = 0.0f;
	/// Reference to external demo window visibility flag.
	bool& m_show_demo_window;
	/// Reference to external another window visibility flag.
	bool& m_show_another_window;
	/// Reference to external clear color.
	std::array<float, 4>& m_clear_color;
};

}// namespace mvi::core::views
