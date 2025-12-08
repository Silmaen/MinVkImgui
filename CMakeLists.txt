set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")

# ---=== BASE defines ===---
set(PROJECT_NAME MinVkImgui)
set(PROJECT_VERSION 0.1.0)
set(PROJECT_PREFIX MVI)

cmake_minimum_required(VERSION 4.1)
string(TOLOWER ${PROJECT_PREFIX} PROJECT_PREFIX_LOWER)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

option(${PROJECT_PREFIX}_DOC_ONLY "To only generate documentation" OFF)
option(${PROJECT_PREFIX}_TESTING "To build the tests" ON)


set(${PROJECT_PREFIX}_ROOT_DIR "${PROJECT_SOURCE_DIR}")
#
# ---=== Base Configs ===---
#
include(cmake/BaseConfig.cmake)
if (NOT ${PROJECT_PREFIX}_DOC_ONLY)
    #
    # ---=== Sanitizers ===---
    #
    include(Sanitizers)

    #
    # ---=== The Program ===---
    #
    add_subdirectory(source)

    #
    # ---=== TESTING PROCEDURES ===---
    #

    if (${PROJECT_PREFIX}_TESTING)
        enable_testing()
        add_subdirectory(test)
    endif ()
endif ()

#
# ---=== End ===---
#
