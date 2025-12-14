/**
 * @file FileActions.h
 * @author Silmaen
 * @date 12/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */

#pragma once
#include "Action.h"

namespace mvi::core::actions {

/**
 * @brief Class QuitAction.
 */
class QuitAction final : public Action {
public:
	QuitAction();
	~QuitAction() override;
	QuitAction(const QuitAction&) = delete;
	QuitAction(QuitAction&&) = delete;
	auto operator=(const QuitAction&) -> QuitAction& = delete;
	auto operator=(QuitAction&&) -> QuitAction& = delete;
	[[nodiscard]] auto getName() const -> std::string override { return "quit_application"; }

private:
	/**
	 * @brief Execute the action.
	 */
	void onExecute() override;
};

}// namespace mvi::core::actions
