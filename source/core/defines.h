/**
 * @file defines.h
 * @author Silmaen
 * @date 02/12/2025
 * Copyright © 2025 All rights reserved.
 * All modification must get authorization from the author.
 */

#pragma once

// clang-format off
// Get which compiler...
#if defined(__clang__) && defined(_MSC_VER)
#define MVI_COMPILER clang_cl
#define MVI_COMPILER_CLANG_CL
#elifdef __clang__
#define MVI_COMPILER clang
#define MVI_COMPILER_CLANG
#elifdef _MSC_VER
#define MVI_COMPILER msvc
#define MVI_COMPILER_MSVC
#elifdef __GNUC__
#define MVI_COMPILER gcc
#define MVI_COMPILER_GCC
#else
#define MVI_COMPILER unknown
#endif

// Check supported compiler.
#if !defined(MVI_COMPILER_GCC) && !defined(MVI_COMPILER_CLANG)
#error("unsupported compiler: MVI_COMPILER")
#endif

#if defined(MVI_COMPILER_MSVC) || defined(MVI_COMPILER_CLANG_CL)
#define MVI_DO_PRAGMA(arg) __Pragma(#arg)
#elif defined(MVI_COMPILER_GCC) || defined(MVI_COMPILER_CLANG)
#define MVI_DO_PRAGMA(arg) _Pragma(#arg)
#else
#define MVI_DO_PRAGMA(arg)
#endif

#ifdef MVI_COMPILER_CLANG
#define MVI_DIAG_POP MVI_DO_PRAGMA(clang diagnostic pop)
#define MVI_DIAG_PUSH MVI_DO_PRAGMA(clang diagnostic push)
#define MVI_DIAG_DISABLE_CLANG(diag) MVI_DO_PRAGMA(clang diagnostic ignored diag)
#if __clang_major__ > 15
#define MVI_DIAG_DISABLE_CLANG16(diag) MVI_DO_PRAGMA(clang diagnostic ignored diag)
#else
#define MVI_DIAG_DISABLE_CLANG16(diag)
#endif
#if __clang_major__ > 16
#define MVI_DIAG_DISABLE_CLANG17(diag) MVI_DO_PRAGMA(clang diagnostic ignored diag)
#else
#define MVI_DIAG_DISABLE_CLANG17(diag)
#endif
#if __clang_major__ > 17
#define MVI_DIAG_DISABLE_CLANG18(diag) MVI_DO_PRAGMA(clang diagnostic ignored diag)
#else
#define MVI_DIAG_DISABLE_CLANG18(diag)
#endif
#if __clang_major__ > 18
#define MVI_DIAG_DISABLE_CLANG19(diag) MVI_DO_PRAGMA(clang diagnostic ignored diag)
#else
#define MVI_DIAG_DISABLE_CLANG19(diag)
#endif
#if __clang_major__ > 19
#define MVI_DIAG_DISABLE_CLANG20(diag) MVI_DO_PRAGMA(clang diagnostic ignored diag)
#else
#define MVI_DIAG_DISABLE_CLANG20(diag)
#endif
#if __clang_major__ > 20
#define MVI_DIAG_DISABLE_CLANG21(diag) MVI_DO_PRAGMA(clang diagnostic ignored diag)
#else
#define MVI_DIAG_DISABLE_CLANG21(diag)
#endif
#if __clang_major__ > 21
#define MVI_DIAG_DISABLE_CLANG22(diag) MVI_DO_PRAGMA(clang diagnostic ignored diag)
#else
#define MVI_DIAG_DISABLE_CLANG22(diag)
#endif
#if __clang_major__ > 22
#define MVI_DIAG_DISABLE_CLANG23(diag) MVI_DO_PRAGMA(clang diagnostic ignored diag)
#else
#define MVI_DIAG_DISABLE_CLANG23(diag)
#endif
#define MVI_DIAG_DISABLE_GCC(diag)
#define MVI_DIAG_DISABLE_CLANG_CL(diag)
#define MVI_DIAG_DISABLE_MSVC(diag)
#elifdef MVI_COMPILER_GCC
#define MVI_DIAG_POP MVI_DO_PRAGMA(GCC diagnostic pop)
#define MVI_DIAG_PUSH MVI_DO_PRAGMA(GCC diagnostic push)
#define MVI_DIAG_DISABLE_CLANG(diag)
#define MVI_DIAG_DISABLE_CLANG16(diag)
#define MVI_DIAG_DISABLE_CLANG17(diag)
#define MVI_DIAG_DISABLE_CLANG18(diag)
#define MVI_DIAG_DISABLE_CLANG19(diag)
#define MVI_DIAG_DISABLE_CLANG20(diag)
#define MVI_DIAG_DISABLE_CLANG21(diag)
#define MVI_DIAG_DISABLE_CLANG22(diag)
#define MVI_DIAG_DISABLE_CLANG23(diag)
#define MVI_DIAG_DISABLE_GCC(diag) MVI_DO_PRAGMA(GCC diagnostic ignored diag)
#define MVI_DIAG_DISABLE_CLANG_CL(diag)
#define MVI_DIAG_DISABLE_MSVC(diag)
#elifdef MVI_COMPILER_CLANG_CL
#define MVI_DIAG_POP
#define MVI_DIAG_PUSH
#define MVI_DIAG_DISABLE_CLANG(diag)
#define MVI_DIAG_DISABLE_GCC(diag)
#define MVI_DIAG_DISABLE_CLANG_CL(diag)
#define MVI_DIAG_DISABLE_CLANG16(diag)
#define MVI_DIAG_DISABLE_CLANG17(diag)
#define MVI_DIAG_DISABLE_CLANG18(diag)
#define MVI_DIAG_DISABLE_CLANG19(diag)
#define MVI_DIAG_DISABLE_CLANG20(diag)
#define MVI_DIAG_DISABLE_CLANG21(diag)
#define MVI_DIAG_DISABLE_CLANG22(diag)
#define MVI_DIAG_DISABLE_CLANG23(diag)
#define MVI_DIAG_DISABLE_MSVC(diag)
#elifdef MVI_COMPILER_MSVC
#define MVI_DIAG_POP MVI_DO_PRAGMA(warning(pop))
#define MVI_DIAG_PUSH MVI_DO_PRAGMA(warning(push))
#define MVI_DIAG_DISABLE_CLANG(diag)
#define MVI_DIAG_DISABLE_CLANG16(diag)
#define MVI_DIAG_DISABLE_CLANG17(diag)
#define MVI_DIAG_DISABLE_CLANG18(diag)
#define MVI_DIAG_DISABLE_CLANG19(diag)
#define MVI_DIAG_DISABLE_CLANG20(diag)
#define MVI_DIAG_DISABLE_GCC(diag)
#define MVI_DIAG_DISABLE_CLANG_CL(diag)
#define MVI_DIAG_DISABLE_MSVC(diag) MVI_DO_PRAGMA(warning(disable : diag))
#else
#define MVI_DIAG_POP
#define MVI_DIAG_PUSH
#define MVI_DIAG_DISABLE_CLANG(diag)
#define MVI_DIAG_DISABLE_CLANG16(diag)
#define MVI_DIAG_DISABLE_CLANG17(diag)
#define MVI_DIAG_DISABLE_CLANG18(diag)
#define MVI_DIAG_DISABLE_CLANG19(diag)
#define MVI_DIAG_DISABLE_CLANG20(diag)
#define MVI_DIAG_DISABLE_CLANG21(diag)
#define MVI_DIAG_DISABLE_CLANG22(diag)
#define MVI_DIAG_DISABLE_CLANG23(diag)
#define MVI_DIAG_DISABLE_GCC(diag)
#define MVI_DIAG_DISABLE_CLANG_CL(diag)
#define MVI_DIAG_DISABLE_MSVC(diag)
#endif

// clang-format on
