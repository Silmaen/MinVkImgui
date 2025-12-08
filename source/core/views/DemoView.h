/**
 * @file DemoView.h
 * @author Silmaen
 * @date 07/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */

#pragma once

#include "View.h"

namespace mvi::core::views {

/**
 * @brief Class DemoView.
 */
class DemoView : public View {
public:
	/**
	 * @brief Default constructor.
	 */
	DemoView();
	/**
	 * @brief Default destructor.
	 */
	~DemoView() override;

	DemoView(const DemoView&) = delete;
	DemoView(DemoView&&) = delete;
	auto operator=(const DemoView&) -> DemoView& = delete;
	auto operator=(DemoView&&) -> DemoView& = delete;
	/**
	 * @brief The update function to implement in derived classes.
	 */
	void onUpdate() override;

private:
};

}// namespace mvi::core::views
