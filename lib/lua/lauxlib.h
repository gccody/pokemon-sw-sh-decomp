#pragma once
// Lua (C library) - decompiled/identified pieces. The Lua version still needs
// pinning down; luaL_error at 0x7101548870 (Sword) matches the 5.3 shape.
struct lua_State;

extern "C" {
int luaL_error(lua_State* L, const char* fmt, ...);
}
