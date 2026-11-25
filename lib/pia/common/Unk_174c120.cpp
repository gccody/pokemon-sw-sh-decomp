// Scope: common
// Unk_174bc30::Unk_174c120 (lib/pia/common/Unk_174be20.h), in a file of its
// own: the members in Unk_174be20.cpp call it, and in one file clang inlines
// it.
#include "pia/common/Unk_174be20.h"

struct Unk_1653860;
struct Unk_1653860_arg1;
bool Unk_1653860_call(const Unk_1653860* self, const Unk_1653860_arg1* value);  // equal hosts

namespace nn {
namespace pia {
namespace transport {

// A random number below a bound.
static inline u32 RandomBelow(Unk_171e0e0& random, u32 bound) {
    return static_cast<u32>((static_cast<u64>(random.Unk_171e1e0()) * bound) >> 32);
}

// 0x710174c120
s32 Unk_174bc30::Unk_174c120(const Unk_1652c70& address) {
    field_58.Unk_1655c80();
    u32 max = 0;
    u32 min = 0;
    for (common::Unk_16580b0_node* node = field_6e8.m_List.m_Root.next;
         node != &field_6e8.m_List.m_Root; node = node->next) {
        Unk_174c120_data& data = reinterpret_cast<decltype(field_6e8)::Entry*>(node)->data;
        if (Unk_1653860_call(reinterpret_cast<const Unk_1653860*>(&data.field_8),
                             reinterpret_cast<const Unk_1653860_arg1*>(&address))) {
            min = data.field_0;
            max = data.field_4;
            break;
        }
    }
    field_58.Unk_1655c90();
    common::FixedString<48> text;
    address.Unk_1652fe0(&text);
    return min + RandomBelow(field_78, max - min);
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
