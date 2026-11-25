// Scope: common
// What a Pia job reports back to (Unk_1655080, lib/pia/common/Unk_1654a80.h):
// a TU of its own, since the jobs' constructors call its constructor and reset
// out of line.
#include "pia/common/Unk_1654a80.h"

using nn::pia::Unk_165e060;
using nn::pia::Unk_165e060Value;

// 0x7101655080
Unk_1655080::Unk_1655080() : m_State(0), m_Result(0) {
    Unk_1655110();
}

// 0x7101655110
void Unk_1655080::Unk_1655110() {
    m_State = 0;
    m_Callback = nullptr;
    m_CallbackArg = nullptr;
    m_Result = Unk_165e060(0);
    field_28 = 0;
}

// 0x71016551b0
void Unk_1655080::Unk_16551b0(Unk_165e060 result) {
    SetResult(result);
    m_State = 2;
    Notify(m_Result);
}

// 0x7101655220
void Unk_1655080::Unk_1655220(Unk_165e060 result) {
    SetResult(result);
    m_State = 3;
    Notify(m_Result);
}

// 0x7101655290
void Unk_1655290(void* self) {
    Unk_1655080* context = static_cast<Unk_1655080*>(self);
    context->SetResult(Unk_165e060Value<0x6c05>());
    context->m_State = 4;
    context->Notify(context->m_Result);
}
