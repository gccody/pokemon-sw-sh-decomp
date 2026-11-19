// Scope: common
// NintendoSDK_gfx 7.3.2: nn::gfx::util::PrimitiveShape and CircleShape (their
// RTTI names N2nn3gfx4util14PrimitiveShapeE and N2nn3gfx4util11CircleShapeE
// are in main; CircleShape derives from PrimitiveShape). The members'
// names aren't known: placeholders, the virtual one named after its slot.
#include <nn/util.h>
#include <types.h>

namespace nn {
namespace detail {
[[noreturn]] void UnexpectedDefaultImpl(const char* condition, const char* function, int line) noexcept;
}  // namespace detail

namespace gfx {
namespace util {

class PrimitiveShape {
public:
    PrimitiveShape(int vertexFormat, int primitiveTopology);
    virtual ~PrimitiveShape();
    virtual void vf2(void* vertexMemory, size_t vertexSize, void* indexMemory,
                     size_t indexSize) = 0;

    size_t Unk_1791430() const;
    void Unk_1791520(int indexCount);

protected:
    void* field_8;
    void* field_10;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    size_t field_30;
    size_t field_38;
};

class CircleShape : public PrimitiveShape {
public:
    CircleShape(int vertexFormat, int primitiveTopology, int divisions);
    ~CircleShape() override;
    void vf2(void* vertexMemory, size_t vertexSize, void* indexMemory, size_t indexSize) override;

    void* Unk_1791600();

private:
    template <typename T>
    void CalculateIndices();

    int field_40;
};

// 0x71017913c0
PrimitiveShape::PrimitiveShape(int vertexFormat, int primitiveTopology)
    : field_8(nullptr), field_10(nullptr), field_18(vertexFormat), field_1c(2),
      field_20(primitiveTopology), field_24(0), field_28(0), field_30(0), field_38(0) {
}

// 0x71017913f0
PrimitiveShape::~PrimitiveShape() {
}

// 0x7101791430: the vertex stride (position, normal, texture coordinate).
size_t PrimitiveShape::Unk_1791430() const {
    size_t stride = 0;
    if (field_18 & 1) {
        stride += sizeof(float) * 3;
    }
    if (field_18 & 2) {
        stride += sizeof(float) * 3;
    }
    if (field_18 & 4) {
        stride += sizeof(float) * 2;
    }
    return stride;
}

// 0x7101791520
void PrimitiveShape::Unk_1791520(int indexCount) {
    field_1c = indexCount >= 0x10000 ? 2 : 1;
    field_28 = indexCount;
}

// 0x7101791540
// NON_MATCHING: the stores pair up differently: the original stores the
// vtable pointer on its own and fields 8 and 0x10 with one `stp`; here the
// vtable pointer and field 8 share one.
CircleShape::CircleShape(int vertexFormat, int primitiveTopology, int divisions)
    : PrimitiveShape(vertexFormat, primitiveTopology), field_40(divisions) {
    field_24 = divisions + 1;
    int indexCount = 0;
    switch (primitiveTopology) {
    case 2:
        indexCount = field_24;
        break;
    case 3:
        indexCount = divisions * 3;
        break;
    }
    Unk_1791520(indexCount);
    field_30 = Unk_1791430() * field_24;
    field_38 = field_28 * sizeof(u32);
}

// 0x71017913f0 (an alias of the base's; the deleting one is at 0x71017915f0)
CircleShape::~CircleShape() {
}

static inline float Unk_1791600_DegreeToRadian(float degree) {
    return nn::util::detail::FloatPi / nn::util::detail::FloatDegree180 * degree;
}

// A table lookup: the top 8 bits of the angle index pick the sample, the
// other 24 interpolate.
static inline void Unk_1791600_CosSin(float* cos, float* sin, float radian) {
    u32 index = static_cast<s64>(
        radian * (static_cast<float>(nn::util::detail::AngleIndexHalfRound) / nn::util::detail::FloatPi));
    const nn::util::detail::Unk_SinCosSample& sample = nn::util::detail::SinCosSampleTable[index >> 24];
    float rest = static_cast<float>(index & 0xffffff) * (1.0f / 0x1000000);
    *cos = sample.field_0 + sample.field_8 * rest;
    *sin = sample.field_4 + sample.field_c * rest;
}

// 0x7101791600: the vertices around the circle, then its center; returns the
// end of the vertices.
void* CircleShape::Unk_1791600() {
    float* vertex = static_cast<float*>(field_10);
    for (int i = 0; i < field_40; ++i) {
        float radian = Unk_1791600_DegreeToRadian(360.0f) * i / field_40;
        float x;
        float y;
        Unk_1791600_CosSin(&x, &y, radian);
        if (field_18 & 1) {
            *vertex++ = x;
            *vertex++ = y;
            *vertex++ = 0.0f;
        }
        if (field_18 & 2) {
            *vertex++ = 0.0f;
            *vertex++ = 0.0f;
            *vertex++ = 1.0f;
        }
        if (field_18 & 4) {
            *vertex++ = x * 0.5f + 0.5f;
            *vertex++ = 1.0f - (y * 0.5f + 0.5f);
        }
    }
    if (field_18 & 1) {
        *vertex++ = 0.0f;
        *vertex++ = 0.0f;
        *vertex++ = 0.0f;
    }
    if (field_18 & 2) {
        *vertex++ = 0.0f;
        *vertex++ = 0.0f;
        *vertex++ = 1.0f;
    }
    if (field_18 & 4) {
        *vertex++ = 0.5f;
        *vertex++ = 0.5f;
    }
    return vertex;
}

template <typename T>
void CircleShape::CalculateIndices() {
    T* index = static_cast<T*>(field_8);
    switch (field_20) {
    case 2:
        for (int i = 0; i < field_28; ++i) {
            index[i] = i % field_40;
        }
        break;
    case 3:
        for (int i = 0; i < field_40; ++i) {
            index[i * 3 + 0] = i;
            index[i * 3 + 1] = (i + 1) % field_40;
            index[i * 3 + 2] = field_40;
        }
        break;
    }
}

// 0x7101791780
void CircleShape::vf2(void* vertexMemory, size_t vertexSize, void* indexMemory,
                      size_t indexSize) {
    field_10 = vertexMemory;
    Unk_1791600();
    field_8 = indexMemory;
    switch (field_1c) {
    case 1:
        CalculateIndices<u16>();
        break;
    case 2:
        CalculateIndices<u32>();
        break;
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
}

}  // namespace util
}  // namespace gfx
}  // namespace nn
