/**
 * @file SecondView.h
 * @author Silmaen
 * @date 07/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */

#pragma once

#include "View.h"

namespace mvi::core::views {

/**
 * @brief Class SecondView.
 */
class SecondView final : public View {
public:
	/**
	 * @brief Default constructor.
	 */
	SecondView();
	/**
	 * @brief Default destructor.
	 */
	~SecondView() override;

	SecondView(const SecondView&) = delete;
	SecondView(SecondView&&) = delete;
	auto operator=(const SecondView&) -> SecondView& = delete;
	auto operator=(SecondView&&) -> SecondView& = delete;
	/**
	 * @brief The update function to implement in derived classes.
	 */
	void onUpdate() override;

	/**
	 * @brief Get the view name.
	 * @return The view name.
	 */
	[[nodiscard]] auto getName() const -> std::string override { return "second_view"; }

private:
};

}// namespace mvi::core::views
