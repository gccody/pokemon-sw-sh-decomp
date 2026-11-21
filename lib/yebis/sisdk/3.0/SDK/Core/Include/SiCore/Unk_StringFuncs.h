// SiSDK3::SiString's out-of-line functions (SiCore's string TU, 0x71004c4290
// to 0x71004c5eb0) as SiIO's and SiGfx's code calls them, and the inline
// members that code shows (placeholder names: free functions here, until the
// string's own TU is written).
#pragma once

#include "SiCore_String.h"

// 0x71004bf7b0: the kernel (leafgen's name and type)
u64 Unk_4bf7b0_get();

namespace SiSDK3 {
// What the kernel tells about the machine, as its users see it: slot 5 is a
// block that starts with the system tick's frequency.
class Unk_SystemInfoInterface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual const s64* vf5();
};

// The kernel as SiIO's and SiGfx's code uses it: slot 12 is its allocator,
// slot 15 its system info.
class Unk_KernelInterface {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual ISiAllocator* vf12();
    virtual void vf13();
    virtual void vf14();
    virtual Unk_SystemInfoInterface* vf15();
};
inline Unk_KernelInterface* Unk_GetKernel() {
    return reinterpret_cast<Unk_KernelInterface*>(Unk_4bf7b0_get());
}
}  // namespace SiSDK3

// 0x71004c4290, 0x71004c5480: a string's length (null: 0)
s64 Unk_4c4290(const char* s);
s64 Unk_4c5480(const char* s);
// 0x71004c45a0: a wide string's length
s64 Unk_4c45a0(const wchar_t* s);
// 0x71004c5170: a UTF-8 string's character count
s64 Unk_4c5170(const char* s);
// 0x71004c51e0: Latin-1 to UTF-8, 0x71004c4e80: wide to UTF-8
char* Unk_4c51e0(const char* s, char* dst, s64 size);
char* Unk_4c4e80(const wchar_t* s, char* dst, s64 size);
// 0x71004c4f60: UTF-8 to a wide string
void Unk_4c4f60(const char* s, SiSDK3::SiString<wchar_t>* dst, s64 size);

// 0x71004c4700, 0x71004c42b0: assigns
void Unk_4c4700(void*, void*);
void Unk_4c42b0(SiSDK3::SiString<wchar_t>* self, const wchar_t* s);
// 0x71004c5d50, 0x71004c5eb0: sets the capacity, keeping the contents if keep
bool Unk_4c5d50(SiSDK3::SiString<char>* self, size_t capacity, bool keep);
bool Unk_4c5eb0(SiSDK3::SiString<wchar_t>* self, size_t capacity, bool keep);
// 0x71004c5b30, 0x71004c5b50 (leafgen's names), 0x71004c5b70, 0x71004c5c60:
// assign from the other character type
bool Unk_4c5b30_call(void* self, void* value);
bool Unk_4c5b50_call(void* self, void* value);
bool Unk_4c5b70(SiSDK3::SiString<char>* self, const wchar_t* s);
bool Unk_4c5c60(SiSDK3::SiString<wchar_t>* self, const char* s);

// 0x71024e9360: the empty string a string without a buffer reads as
extern char Unk_24e9360[];

namespace SiSDK3 {

// A string's characters (the empty string's without a buffer).
inline const char* Unk_StringCStr(const SiString<char>* self) {
    return self->m_pBuffer != nullptr ? self->m_pBuffer : Unk_24e9360;
}

inline bool Unk_StringSetCapacity(SiString<char>* self, size_t capacity, bool keep) {
    return Unk_4c5d50(self, capacity, keep);
}
inline bool Unk_StringSetCapacity(SiString<wchar_t>* self, size_t capacity, bool keep) {
    return Unk_4c5eb0(self, capacity, keep);
}
inline void Unk_StringAssign(SiString<char>* self, const char* s) {
    Unk_4c4700(self, const_cast<char*>(s));
}
inline void Unk_StringAssign(SiString<wchar_t>* self, const wchar_t* s) {
    Unk_4c42b0(self, s);
}

// Makes room for capacity characters (with the terminator).
template <class T>
inline bool Unk_StringReserve(SiString<T>* self, size_t capacity) {
    if (self->field_20 < capacity) {
        return Unk_StringSetCapacity(self, capacity, true);
    }
    return true;
}

// Sets the length and terminates the string.
template <class T>
inline bool Unk_StringResize(SiString<T>* self, size_t length) {
    if (self->field_20 <= length) {
        if (!Unk_StringReserve(self, length + 1)) {
            return false;
        }
    }
    self->m_pBuffer[length] = 0;
    self->field_10 = length;
    return true;
}

// Appends a character, growing by field_18 characters or to twice the
// capacity.
template <class T>
inline void Unk_StringAppend(SiString<T>* self, T c) {
    if (self->field_20 <= self->field_10 + 1) {
        size_t step = self->field_18;
        size_t length = self->field_10 + 2;
        size_t capacity;
        if (step != 0) {
            capacity = step + length;
        } else {
            capacity = length > self->field_20 * 2 ? length : self->field_20 * 2;
        }
        Unk_StringSetCapacity(self, capacity, true);
    }
    size_t length = self->field_10;
    self->m_pBuffer[length] = c;
    self->field_10++;
    self->m_pBuffer[length + 1] = 0;
}

}  // namespace SiSDK3
