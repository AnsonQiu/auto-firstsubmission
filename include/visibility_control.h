#ifndef BEYONDTESLAOPENLOOP__VISIBILITY_CONTROL_H_
#define BEYONDTESLAOPENLOOP__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define BEYONDTESLAOPENLOOP_EXPORT __attribute__ ((dllexport))
    #define BEYONDTESLAOPENLOOP_IMPORT __attribute__ ((dllimport))
  #else
    #define BEYONDTESLAOPENLOOP_EXPORT __declspec(dllexport)
    #define BEYONDTESLAOPENLOOP_IMPORT __declspec(dllimport)
  #endif
  #ifdef BEYONDTESLAOPENLOOP_BUILDING_LIBRARY
    #define BEYONDTESLAOPENLOOP_PUBLIC BEYONDTESLAOPENLOOP_EXPORT
  #else
    #define BEYONDTESLAOPENLOOP_PUBLIC BEYONDTESLAOPENLOOP_IMPORT
  #endif
  #define BEYONDTESLAOPENLOOP_PUBLIC_TYPE BEYONDTESLAOPENLOOP_PUBLIC
  #define BEYONDTESLAOPENLOOP_LOCAL
#else
  #define BEYONDTESLAOPENLOOP_EXPORT __attribute__ ((visibility("default")))
  #define BEYONDTESLAOPENLOOP_IMPORT
  #if __GNUC__ >= 4
    #define BEYONDTESLAOPENLOOP_PUBLIC __attribute__ ((visibility("default")))
    #define BEYONDTESLAOPENLOOP_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define BEYONDTESLAOPENLOOP_PUBLIC
    #define BEYONDTESLAOPENLOOP_LOCAL
  #endif
  #define BEYONDTESLAOPENLOOP_PUBLIC_TYPE
#endif
#endif  // BEYONDTESLAOPENLOOP__VISIBILITY_CONTROL_H_
// Generated 16-Nov-2023 12:29:08
// Copyright 2019-2020 The MathWorks, Inc.
