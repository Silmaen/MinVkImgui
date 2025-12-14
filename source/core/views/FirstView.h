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
class FirstView final : public View {
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
	/**
	 * @brief Get the view name.
	 * @return The view name.
	 */
	[[nodiscard]] auto getName() const -> std::string override { return "first_view"; }

private:
	/// A simple counter.
	int m_counter = 0;
	/// A float value.
	float m_float = 0.0f;
	/// Reference to external demo window visibility flag.
	bool& m_showDemoWindow;
	/// Reference to external another window visibility flag.
	bool& m_showAnotherWindow;
	/// Reference to external clear color.
	std::array<float, 4>& m_clearColor;
};

}// namespace mvi::core::views
