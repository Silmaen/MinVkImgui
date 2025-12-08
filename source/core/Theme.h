/**
 * @file Theme.h
 * @author Silmaen
 * @date 07/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */

#pragma once

#include <array>

namespace mvi::core {

/// Type alias for a 4D vector representing RGBA colors.
using vec4 = std::array<float, 4>;

/**
 * @brief Struct Theme.
 */
struct Theme {
	vec4 text{0.753f, 0.753f, 0.753f, 1.0};
	vec4 windowBackground{0.1f, 0.105f, 0.11f, 1.0f};
	vec4 childBackground{0.141f, 0.141f, 0.141f, 1.0f};
	vec4 backgroundPopup{0.196f, 0.196f, 0.196f, 1.0f};
	vec4 border{0.102f, 0.102f, 0.102f, 1.0f};

	vec4 frameBackground{0.0588f, 0.0588f, 0.0588f, 1.0};
	vec4 frameBackgroundHovered{0.0588f, 0.0588f, 0.0588f, 1.0};
	vec4 frameBackgroundActive{0.0588f, 0.0588f, 0.0588f, 1.0};

	vec4 titleBar{0.0824f, 0.0824f, 0.0824f, 1.0f};
	vec4 titleBarActive{0.0824f, 0.0824f, 0.0824f, 1.0f};
	vec4 titleBarCollapsed{0.15f, 0.1505f, 0.151f, 1.0f};

	vec4 menubarBackground{0.0f, 0.0f, 0.0f, 0.0f};

	vec4 scrollbarBackground{0.02f, 0.02f, 0.02f, 0.53f};
	vec4 scrollbarGrab{0.31f, 0.31f, 0.31f, 1.0f};
	vec4 scrollbarGrabHovered{0.41f, 0.41f, 0.41f, 1.0f};
	vec4 scrollbarGrabActive{0.51f, 0.51f, 0.51f, 1.0f};

	vec4 checkMark{0.753f, 0.753f, 0.753f, 1.0};

	vec4 sliderGrab{0.51f, 0.51f, 0.51f, 0.7f};
	vec4 sliderGrabActive{0.66f, 0.66f, 0.66f, 1.0f};

	vec4 button{0.22f, 0.22f, 0.22f, 0.784f};
	vec4 buttonHovered{0.275f, 0.275f, 0.275f, 1.0f};
	vec4 buttonActive{0.22f, 0.22f, 0.22f, 0.588f};

	vec4 groupHeader{0.184f, 0.184f, 0.184f, 1.0f};
	vec4 groupHeaderHovered{0.184f, 0.184f, 0.184f, 1.0f};
	vec4 groupHeaderActive{0.184f, 0.184f, 0.184f, 1.0f};

	vec4 separator{0.102f, 0.102f, 0.102f, 1.0f};
	vec4 separatorActive{0.153f, 0.725f, 0.949f, 1.0f};
	vec4 separatorHovered{0.153f, 0.725f, 0.949f, 0.588f};

	vec4 resizeGrip{0.91f, 0.91f, 0.91f, 0.25f};
	vec4 resizeGripHovered{0.81f, 0.81f, 0.81f, 0.67f};
	vec4 resizeGripActive{0.46f, 0.46f, 0.46f, 0.95f};

	vec4 tabHovered{0.149f, 0.157f, 0.076f, 1.0f};
	vec4 tab{0.0824f, 0.0824f, 0.0824f, 1.0f};
	vec4 tabSelected{0.051f, 0.051f, 0.051f, 1.0f};
	vec4 tabSelectedOverline{0.898f, 0.706f, 0.051f, 1.0f};
	vec4 tabDimmed{0.0824f, 0.0824f, 0.0824f, 1.0f};
	vec4 tabDimmedSelected{0.072f, 0.072f, 0.072f, 1.0f};
	vec4 tabDimmedSelectedOverline{0.339f, 0.321f, 0.210f, 1.0f};

	vec4 dockingPreview{0.898f, 0.706f, 0.051f, 0.67f};
	vec4 dockingEmptyBackground{0.2f, 0.2f, 0.2f, 1.f};

	vec4 highlight{0.153f, 0.725f, 0.949f, 1.0f};

	vec4 propertyField{0.0588f, 0.0588f, 0.0588f, 1.0};

	float windowRounding{7.f};
	float frameRounding{2.5f};
	float frameBorderSize{1.0f};
	float indentSpacing{11.f};

	float tabRounding{10.f};
	float tabOverline{1.f};
	float tabBorder{1.f};

	float controlsRounding{9};
};

}// namespace mvi::core
