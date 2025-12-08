/**
 * @file baseDefine.h
 * @author Silmaen
 * @date 17/10/2021
 * Copyright © 2021 All rights reserved.
 * All modification must get authorization from the author.
 */
#pragma once

#include <format>
#include <string>

/**
 * @brief namespace de base.
 */
namespace mvi {

#ifndef MVI_AUTHOR
#define MVI_AUTHOR "Damien Lachouette"
#endif
#ifndef MVI_MAJOR
#define MVI_MAJOR "0"
#endif
#ifndef MVI_MINOR
#define MVI_MINOR "xx"
#endif
#ifndef MVI_PATCH
#define MVI_PATCH "dev"
#endif
static const std::string MVI_VERSION = std::format("{}.{}.{}", MVI_MAJOR, MVI_MINOR, MVI_PATCH);
static const std::string MVI_AUTHOR_STR = std::format("{}", MVI_AUTHOR);
static const std::string MVI_APP = "Événement Loto";

}// namespace mvi
