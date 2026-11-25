// Scope: common
// NintendoWare Font 7.3.2: nn::font::ResFont's (RTTI) getters of the FFNT
// resource's FINF and TGLP data, and the character -> glyph index lookup.
// Placeholder names (Unk_177baf0.h); the virtual functions are named after
// ResFont's vtable, as tools/leafgen.py names their neighbours.
#include <types.h>

#include "Unk_177baf0.h"

namespace nn {
namespace font {

// 0x710177c190
s32 ResFont::vf22() {
    return Glyph()->field_8;
}

// 0x710177c1b0
u32 ResFont::vf23() {
    return Glyph()->field_1;
}

// 0x710177c1d0
u32 ResFont::vf24() {
    return Glyph()->field_0;
}

// 0x710177c1e0
u32 ResFont::vf8() {
    return Glyph()->field_3;
}

// 0x710177c210
u32 ResFont::vf10() {
    return Glyph()->field_a & 0x3fff;
}

// 0x710177c230
s32 ResFont::vf11() {
    return field_20->field_4;
}

// 0x710177c240
Unk_177baf0_Widths ResFont::vf12() {
    return field_20->field_8;
}

// 0x710177c280
bool ResFont::vf15(u32 code) {
    u16 index = Unk_177c2d0(code);
    if (index == 0xffff) {
        return false;
    }
    field_20->field_6 = index;
    return true;
}

}  // namespace font
}  // namespace nn

// 0x710177c2d0
u16 Unk_246a5b8::Unk_177c2d0(u32 code) const {
    u32 offset = field_20->mapOffset;
    while (offset != 0) {
        const Unk_177baf0_Map* map = reinterpret_cast<const Unk_177baf0_Map*>(field_18 + offset);
        if (map->codeBegin <= code && code <= map->codeEnd) {
            if (rangeCount != 0) {
                bool inRange = false;
                for (s32 i = 0; i < rangeCount; i++) {
                    if (rangeBegin[i] <= code && code <= rangeEnd[i]) {
                        inRange = true;
                        break;
                    }
                }
                if (!inRange) {
                    return 0xffff;
                }
            }
            switch (map->method) {
            case 0:
                return map->info[0] + (code - map->codeBegin);
            case 1:
                return map->info[static_cast<s32>(code - map->codeBegin)];
            case 2: {
                const Unk_177baf0_Scan* scan = reinterpret_cast<const Unk_177baf0_Scan*>(map->info);
                const Unk_177baf0_ScanEntry* first = &scan->entries[0];
                const Unk_177baf0_ScanEntry* last = &scan->entries[scan->count - 1];
                while (first <= last) {
                    const Unk_177baf0_ScanEntry* middle = first + (last - first) / 2;
                    if (middle->code < code) {
                        first = middle + 1;
                    } else if (code < middle->code) {
                        last = middle - 1;
                    } else {
                        return middle->index;
                    }
                }
                return 0xffff;
            }
            default:
                return 0xffff;
            }
        }
        offset = map->next;
    }
    return 0xffff;
}

namespace nn {
namespace font {

// 0x710177c3f0
void ResFont::vf13(s8 value) {
    field_20->field_4 = value;
}

}  // namespace font
}  // namespace nn
