// SiSDK3::SiString's out-of-line functions (SiCore's string TU, 0x71004c4290
// to 0x71004c5eb0) as SiIO's and SiGfx's code calls them, and the inline
// members that code shows (placeholder names: free functions here, until the
// string's own TU is written).
#pragma once

#include "SiCore_String.h"
#include "Unk_4ca820_arg0.h"

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

// A string table as the other libraries' kernels use theirs (ISiStringTable's
// slots: 3 drops a reference, 8 and 9 start and end changes, 11 adds a
// language's texts).
class Unk_StringTableInterface {
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
    virtual bool vf11(const Unk_4ca820_arg0& language, const void* items);
};

// The kernel as SiIO's and SiGfx's code uses it: slot 12 is its allocator,
// slot 15 its system info, slot 23 makes a string table, slot 24 is its
// language, slots 26 and 27 add a string table under an id and remove it.
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
    // the value of a variable (SiKernel has none: slot 16 returns a constant)
    virtual u32 vf16(const char* name, SiString<char>* value);
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual Unk_StringTableInterface* vf23(ISiAllocator* pAllocator);
    virtual const Unk_4ca820_arg0* vf24();
    virtual void vf25();
    virtual bool vf26(const void* id, Unk_StringTableInterface* table);
    virtual bool vf27(Unk_StringTableInterface* table);
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
// 0x71004c49f0: a string of s's characters (in the kernel's allocator)
SiSDK3::SiString<char> Unk_4c49f0(const char* s);
// 0x71004c4f60: UTF-8 to a wide string (the string TU, which defines it,
// declares that it returns whether s wasn't null)
#ifdef UNK_SICORE_STRING_IMPL
bool Unk_4c4f60(const char* s, SiSDK3::SiString<wchar_t>* dst, s64 size);
#else
void Unk_4c4f60(const char* s, SiSDK3::SiString<wchar_t>* dst, s64 size);
#endif

// 0x71004c4700, 0x71004c42b0: assigns (they return the string: the string
// TU, which defines them, declares them so). Its callers see 0x71004c4700's
// result as a reference, as an `operator=` returns it: the reference's
// return attributes keep CodeGenPrepare from duplicating a shared return
// into the block of a call whose result is unused, so such a call isn't
// made a tail call (SiIOCSVDocument::Unk_57eb50 returns through its early
// return's epilogue after it).
#ifdef UNK_SICORE_STRING_IMPL
SiSDK3::SiString<char>* Unk_4c4700(void*, void*);
SiSDK3::SiString<wchar_t>* Unk_4c42b0(SiSDK3::SiString<wchar_t>* self, const wchar_t* s);
#else
SiSDK3::SiString<char>& Unk_4c4700(void*, void*);
void Unk_4c42b0(SiSDK3::SiString<wchar_t>* self, const wchar_t* s);
#endif
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

// Appends a string (nothing for a null or empty one). The capacity is set
// whatever it was.
template <class T>
inline void Unk_StringAppend(SiString<T>* self, const T* s) {
    if (s != nullptr && *s != 0) {
        size_t count = 0;
        while (s[count] != 0) {
            count++;
        }
        Unk_StringSetCapacity(self, self->field_10 + count + 1, true);
        size_t length = self->field_10;
        memcpy(self->m_pBuffer + length, s, count * sizeof(T));
        self->field_10 += count;
        self->m_pBuffer[length + count] = 0;
    }
}

// Appends a string (nothing for a null or empty one), growing as the
// character append does when it's full.
template <class T>
inline void Unk_StringAppendGrow(SiString<T>* self, const T* s) {
    if (s != nullptr && *s != 0) {
        size_t count = 0;
        while (s[count] != 0) {
            count++;
        }
        if (self->field_20 <= self->field_10 + count) {
            size_t step = self->field_18;
            size_t length = self->field_10 + count + 1;
            size_t capacity;
            if (step != 0) {
                capacity = step + length;
            } else {
                capacity = length > self->field_20 * 2 ? length : self->field_20 * 2;
            }
            Unk_StringSetCapacity(self, capacity, true);
        }
        size_t length = self->field_10;
        memcpy(self->m_pBuffer + length, s, count * sizeof(T));
        self->field_10 += count;
        self->m_pBuffer[length + count] = 0;
    }
}

// Appends another string (nothing for an empty one), growing as the
// character append does when it's full.
template <class T>
inline void Unk_StringAppendString(SiString<T>* self, const SiString<T>* other) {
    size_t count = other->field_10;
    if (count != 0) {
        if (self->field_20 <= self->field_10 + count) {
            size_t step = self->field_18;
            size_t length = self->field_10 + count + 1;
            size_t capacity;
            if (step != 0) {
                capacity = step + length;
            } else {
                capacity = length > self->field_20 * 2 ? length : self->field_20 * 2;
            }
            Unk_StringSetCapacity(self, capacity, true);
        }
        size_t length = self->field_10;
        const T* src = other->m_pBuffer;
        memcpy(self->m_pBuffer + length, src, count * sizeof(T));
        self->field_10 += count;
        self->m_pBuffer[length + count] = 0;
    }
}

// A string and another after it, in the kernel's allocator.
template <class T>
inline SiString<T> Unk_StringConcat(const SiString<T>& a, const T* b) {
    SiString<T> result(a, nullptr);
    Unk_StringAppendGrow(&result, b);
    return result;
}

}  // namespace SiSDK3
