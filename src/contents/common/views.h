#pragma once
// Unk_a7bb80_Views::Unk_a7bb80, for the TUs that inline it (see
// contents/common/framework.h).
#include "contents/common/framework.h"

template <class T>
T* Unk_a7bb80_Views::Unk_a7bb80(const Unk_5cfaf0_Name& name) {
    auto it = std::find_if(field_78.begin(), field_78.end(), [name](Unk_23f4660* view) {
        return view->field_5c0.Unk_5cfaf0() == name;
    });
    if (it == field_78.end())
        return nullptr;
    return Unk_DynamicCast<T>(*it);
}
