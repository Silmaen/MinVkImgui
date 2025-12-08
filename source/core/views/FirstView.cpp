/**
 * @file FirstView.cpp
 * @author Silmaen
 * @date 07/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */
#include "pch.h"

#include "FirstView.h"

#include <imgui.h>

namespace mvi::core::views {

FirstView::FirstView(bool& iShowDemoWindow, bool& iShowAnotherWindow, std::array<float, 4>& iClearColor)
	: m_show_demo_window(iShowDemoWindow), m_show_another_window(iShowAnotherWindow), m_clear_color(iClearColor) {}

FirstView::~FirstView() = default;

void FirstView::onUpdate() {
	const ImGuiIO& io = ImGui::GetIO();

	ImGui::Begin("Hello, world!");// Create a window called "Hello, world!" and append into it.

	ImGui::Text("This is some useful text.");// Display some text (you can use a format strings too)
	ImGui::Checkbox("Demo Window", &m_show_demo_window);// Edit bools storing our window open/close state
	ImGui::Checkbox("Another Window", &m_show_another_window);

	ImGui::SliderFloat("float", &m_float, 0.0f, 1.0f);// Edit 1 float using a slider from 0.0f to 1.0f
	ImGui::ColorEdit3("clear color",
					  reinterpret_cast<float*>(&m_clear_color));// Edit 3 floats representing a color

	if (ImGui::Button("Button"))// Buttons return true when clicked (most widgets return true when edited/activated)
		m_counter++;
	ImGui::SameLine();
	ImGui::Text("counter = %d", m_counter);

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0 / static_cast<double>(io.Framerate),
				static_cast<double>(io.Framerate));
	ImGui::End();
}
}// namespace mvi::core::views
