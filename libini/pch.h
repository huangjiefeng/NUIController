//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#if _MSC_VER
#define snprintf _snprintf
#endif