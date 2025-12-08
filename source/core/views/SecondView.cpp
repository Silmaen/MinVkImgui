/**
 * @file SecondView.cpp
 * @author Silmaen
 * @date 07/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */
#include "pch.h"

#include "SecondView.h"

#include <imgui.h>

namespace mvi::core::views {

SecondView::SecondView() = default;

SecondView::~SecondView() = default;

void SecondView::onUpdate() {
	// Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
	ImGui::Begin("Another Window", &visibility());
	ImGui::Text("Hello from another window!");
	if (ImGui::Button("Close Me"))
		hide();
	ImGui::End();
}

}// namespace mvi::core::views
