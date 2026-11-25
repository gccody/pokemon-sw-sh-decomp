// Scope: common
// transport::StationManager's station lookups and transport::ThreadStreamManager
// (lib/pia/common/Unk_174aea0.h). StationManager::vf19 and
// ThreadStreamManager::vf2 are in lib/nx_middleware/class.
#include "pia/common/Unk_174aea0.h"

#include "pia/common/Unk_17162d0.h"

struct Unk_174b770;
struct Unk_174c7a0;
void Unk_174b770_call(Unk_174b770* self);  // SendThreadStream's, clears its buffer
void Unk_174c7a0_call(Unk_174c7a0* self);  // ReceiveThreadStream's, clears its buffer

namespace nn {
namespace pia {
namespace transport {

// 0x710174aea0
Station* StationManager::vf13(const Unk_1652c70* address) {
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        StationManagerNode* node = static_cast<StationManagerNode*>(link);
        if (Unk_1653b50(reinterpret_cast<const Unk_1653890_arg0*>(&node->station->field_10.field_8),
                        reinterpret_cast<const Unk_1653890_arg0*>(address))) {
            return node->station;
        }
    }
    return nullptr;
}

// 0x710174af20
Station* StationManager::vf14(const Unk_1652c70* address) {
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        StationManagerNode* node = static_cast<StationManagerNode*>(link);
        if (Unk_1653b50(reinterpret_cast<const Unk_1653890_arg0*>(&node->station->field_10.field_8),
                        reinterpret_cast<const Unk_1653890_arg0*>(address))) {
            return node->station;
        }
    }
    return nullptr;
}

// 0x710174afa0
Station* StationManager::vf15(u64 id) {
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        Station* station = static_cast<StationManagerNode*>(link)->station;
        if (station->field_40 == id) {
            return station;
        }
    }
    return nullptr;
}

// 0x710174afe0
Station* StationManager::vf16(u64 id) {
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        Station* station = static_cast<StationManagerNode*>(link)->station;
        if (station->field_40 == id) {
            return station;
        }
    }
    return nullptr;
}

// 0x710174b020
Unk_165e060 StationManager::Unk_174b020(Unk_165fb30* address, u8 index) {
    if (address == nullptr || !vf20(index)) {
        return Unk_165e060Value<0x10c07>();
    }
    Station* station = vf10(index);
    if (station == nullptr) {
        return Unk_165e060Value<0x2c0a>();
    }
    *address = station->field_10;
    return Unk_165e060Value<0>();
}

// 0x710174b0f0
u32 StationManager::Unk_174b0f0(bool withOwn) {
    u32 mask = 0;
    for (StationManagerLink* link = field_18.next; link != &field_18; link = link->next) {
        Station* station = static_cast<StationManagerNode*>(link)->station;
        if (station->field_38 < 0x20 && station->field_48 == 5) {
            mask |= 1u << station->field_38;
        }
    }
    if (!withOwn && field_98 != nullptr && field_98->field_38 < 0x20) {
        mask &= ~(1u << field_98->field_38);
    }
    return mask;
}

// 0x710174b180
ThreadStreamManager::ThreadStreamManager(Unk_174e330_object* factory, u32 sendArg2, u32 receiveArg2,
                                         u32 sendArg4, u32 receiveArg4, bool arg5)
    : field_8(nullptr), field_10(nullptr), field_18(nullptr), field_20(nullptr) {
    Unk_165e060 result(0);
    field_8 = factory->vf19();
    field_18 = new (Unk_1652bd0()) ReceiveThreadStream();
    result = field_18->Unk_174c650(field_8, receiveArg2, 10, receiveArg4, arg5);
    field_18->field_c4 = 5;
    field_10 = factory->vf20();
    field_20 = new (Unk_1652bd0()) SendThreadStream();
    result = field_20->Unk_174b620(field_10, sendArg2, 10, sendArg4, arg5);
    field_20->field_c4 = 5;
}

// 0x710174b2f0 (and 0x710174b3e0, deleting)
ThreadStreamManager::~ThreadStreamManager() {
    if (field_20 != nullptr) {
        Unk_174b770_call(reinterpret_cast<Unk_174b770*>(field_20));
        SendThreadStream* stream = field_20;
        if (stream != nullptr) {
            stream->~SendThreadStream();
            Unk_1716390(stream);
        }
        field_20 = nullptr;
    }
    if (field_18 != nullptr) {
        Unk_174c7a0_call(reinterpret_cast<Unk_174c7a0*>(field_18));
        ReceiveThreadStream* stream = field_18;
        if (stream != nullptr) {
            stream->~ReceiveThreadStream();
            Unk_1716390(stream);
        }
        field_18 = nullptr;
    }
    if (field_10 != nullptr) {
        Unk_174e330_get(reinterpret_cast<const Unk_174e330*>(Unk_27fc2d8))->vf22(field_10);
        field_10 = nullptr;
    }
    if (field_8 != nullptr) {
        Unk_174e330_get(reinterpret_cast<const Unk_174e330*>(Unk_27fc2d8))->vf21(field_8);
        field_8 = nullptr;
    }
}

// 0x710174b410
Unk_165e060 ThreadStreamManager::Unk_174b410() {
    if (field_18 == nullptr || field_20 == nullptr) {
        return Unk_165e060Value<0x10c08>();
    }
    Unk_165e060 result(0);
    result = field_18->Unk_174f810();
    result = field_20->Unk_174f810();
    return Unk_165e060Value<0>();
}

// 0x710174b510
void ThreadStreamManager::Unk_174b510() {
    if (field_18 != nullptr) {
        field_18->Unk_174f970();
    }
    if (field_20 != nullptr) {
        field_20->Unk_174f970();
    }
}

// 0x710174b550
void ThreadStreamManager::Unk_174b550() {
    if (field_20 != nullptr) {
        field_20->Unk_174b970();
    }
    if (field_18 != nullptr) {
        field_18->Unk_174c9c0();
    }
}

}  // namespace transport
}  // namespace pia
}  // namespace nn
