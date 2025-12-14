/**
 * @file FileActions.cpp
 * @author Silmaen
 * @date 12/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */
#include "pch.h"

#include "FileActions.h"

#include "core/Application.h"
#include "core/Log.h"

namespace mvi::core::actions {

QuitAction::QuitAction() = default;
QuitAction::~QuitAction() = default;
void QuitAction::onExecute() {
	log_trace("Quit action executed.");
	Application::get().requestClose();
}

}// namespace mvi::core::actions
