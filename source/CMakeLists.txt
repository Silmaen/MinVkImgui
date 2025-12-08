
#
# ----==== Base Library ====----
#
file(GLOB_RECURSE
        SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/core/*.h
)
add_library(${CMAKE_PROJECT_NAME}_lib ${SRCS})
target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC .)
target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC ${CMAKE_PROJECT_NAME}_Base)
# precompiled headers
if (NOT ${PROJECT_PREFIX}_ENABLE_CLANG_TIDY)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/pch.h")
        target_precompile_headers(${CMAKE_PROJECT_NAME}_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/pch.h)
    endif ()
endif ()
set_target_properties(${CMAKE_PROJECT_NAME}_lib PROPERTIES FOLDER "core_libs")

# ----==== third party ====----
#spdlog
find_package(spdlog REQUIRED)
message(STATUS "Found spdlog: ${spdlog_DIR} (found version: ${spdlog_VERSION})")
target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC spdlog::spdlog)

#magic enum
find_package(magic_enum REQUIRED)
message(STATUS "Found magic_enum: ${magic_enum_DIR} (found version: ${magic_enum_VERSION})")
target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC magic_enum::magic_enum)

# YAML
find_package(yaml-cpp REQUIRED)
message(STATUS "Found yaml-cpp: ${yaml-cpp_DIR} (found version: ${yaml-cpp_VERSION})")
target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC yaml-cpp::yaml-cpp)

find_package(ImGui REQUIRED)
message(STATUS "Found ImGui: ${ImGui_DIR} (found version: ${ImGui_VERSION})")
target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC imgui::imgui)
message(STATUS "ImGui include dirs: ${imgui_INCLUDE_DIRS}")
target_include_directories(${CMAKE_PROJECT_NAME}_lib SYSTEM PUBLIC ${imgui_INCLUDE_DIRS})

find_package(glfw3 REQUIRED)
message(STATUS "Found glfw3: ${glfw3_DIR} (found version: ${glfw3_VERSION})")
target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC glfw)

target_link_vulkan(${CMAKE_PROJECT_NAME}_lib PUBLIC)

# TBB (optionnal)
find_package(TBB QUIET)
if (TBB_FOUND)
    target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC TBB::tbb)
    target_compile_definitions(${CMAKE_PROJECT_NAME}_lib PUBLIC ${PROJECT_PREFIX}_ENGINE_USE_TBB)
endif ()
#
# ----==== Main Executable ====----
#
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
if (${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
            -Wno-reserved-identifier
            -Wno-missing-prototypes
    )
endif ()
target_link_libraries(${CMAKE_PROJECT_NAME}
        ${CMAKE_PROJECT_NAME}_lib
)
if (CMAKE_SYSTEM_NAME MATCHES "Windows" AND CMAKE_BUILD_TYPE MATCHES "Release")
    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif ()
#  Main Executable
#
