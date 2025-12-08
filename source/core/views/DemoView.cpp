/**
 * @file DemoView.cpp
 * @author Silmaen
 * @date 07/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */
#include "pch.h"

#include "DemoView.h"

#include <imgui.h>

namespace mvi::core::views {

DemoView::DemoView() = default;

DemoView::~DemoView() = default;

void DemoView::onUpdate() { ImGui::ShowDemoWindow(&visibility()); }

}// namespace mvi::core::views
