// Unk_23d4470's own definitions (src/unsorted/Unk_23d4470.h). Included by
// the file tools/vtables.py writes for its TU, the one with the 63 classes
// derived from it: written by hand, but part of that TU.

// 0x7100bd0880, 0x7100bc9dc0 (D0), thunks 0x7100bc9e00/0x7100bc9e10 (+0x48)
// and 0x7100bc9e40/0x7100bc9e50 (+0x50)
Unk_23d4470::~Unk_23d4470() {}

// 0x7100bc9dd0, thunks 0x7100bc9e20 (+0x48) and 0x7100bc9e30 (+0x50); its
// type getter 0x7100bc8a00 stays out of line (it has many callers)
const Unk_239a418_Type* Unk_23d4470::vf_type() {
    return Unk_GetType();
}

// 0x7100bc9de0
void Unk_23d4470::vf7(u64, const Unk_23d4470_Desc&) {}

// 0x7100bc9df0
u32 Unk_23d4470::vf8() {
    return 1;
}
