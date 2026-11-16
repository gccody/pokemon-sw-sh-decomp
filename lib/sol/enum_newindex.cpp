// sol2 (https://github.com/ThePhD/sol2) - open source Lua binding.
// Scope: common - at different addresses in each game (Sword 0x7100e337a0,
// Shield 0x7100e337d0): exercises a string literal + a named callee.
#include <lua/lua.hpp>

namespace sol {
namespace detail {

int fail_on_newindex(lua_State* L) {
    return luaL_error(L, "sol: cannot modify the elements of an enumeration table");
}

}  // namespace detail
}  // namespace sol
