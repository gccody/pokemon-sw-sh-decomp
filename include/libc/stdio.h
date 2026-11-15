#pragma once
// Imported from the SDK module (resolved through the PLT by tools/check.py).
#include <types.h>

extern "C" {
int snprintf(char* buf, size_t size, const char* fmt, ...);
}
