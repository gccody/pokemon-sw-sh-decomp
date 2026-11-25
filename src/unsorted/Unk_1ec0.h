#pragma once
// The dynamic initialisation of boost's `core_typeid_<T>::ti_` (boost/core/typeinfo.hpp,
// without RTTI), instantiated for the lambdas of gflib3's boost.signals2: a template static
// data member, so clang gives it an init function of its own with a guard, both statics
// reached through the GOT. The function's real symbol is a `__cxx_global_var_init`, written
// here as a placeholder function per original.
#include <types.h>

namespace boost {
namespace core {

// boost/core/typeinfo.hpp: the type's name, from BOOST_CURRENT_FUNCTION.
class typeinfo {
public:
    explicit typeinfo(const char* name) : name_(name) {}

private:
    const char* name_;
};

}  // namespace core
}  // namespace boost

PKMN_SIZE_ASSERT(boost::core::typeinfo, 0x8);

// `(lambda at <file>:<line>:<column>)`, a lambda of gflib3's boost headers.
#define UNK_1EC0_LAMBDA(file, location)                                                          \
    "(lambda at "                                                                                \
    "C:/"                                                                                        \
    "jenkins\\workspace\\orion\\RomBuild\\program\\lib\\gflib3\\external\\boost\\include\\boost" \
    "\\signals2\\" file ":" location ")"

// BOOST_CURRENT_FUNCTION of `core_typeid_<lambda>::name()`.
#define UNK_1EC0_TYPEID_NAME(lambda) \
    "static const char *boost::detail::core_typeid_<" lambda ">::name() [T = " lambda "]"
