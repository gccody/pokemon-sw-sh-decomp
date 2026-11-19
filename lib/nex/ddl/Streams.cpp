// Scope: common
// NEX 4.6.8's DDL stream functions (tools/nexddl.py streams).
#include "Streams.h"

using nn::nex::EndStructure;
using nn::nex::ReadField;
using nn::nex::ReadLength;

// 0x710158bc50
void Unk_158bc50_write(nn::nex::ByteStream* s, const Unk_158bc50& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_9);
    WriteContainer(s, v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x7101589f50
void Unk_1589f50_write(nn::nex::ByteStream* s, const Unk_1589f50& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    Unk_162cec0_write(s, v.field_10);
    Unk_158bc50_write(s, v.field_38);
    Unk_158bc50_write(s, v.field_60);
    s->Write(v.field_88);
    Unk_162d630_write(s, v.field_90);
    WriteContainer(s, v.field_c8, Unk_162cec0_write);
    s->Write(v.field_e0);
    s->Write(v.field_e4);
    s->Write(v.field_e6);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158c210
void Unk_158c210_write(nn::nex::ByteStream* s, const Unk_158c210& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158a0f0
void Unk_158a0f0_write(nn::nex::ByteStream* s, const Unk_158a0f0& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)1));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    Unk_162cec0_write(s, v.field_20);
    Unk_158bc50_write(s, v.field_48);
    Unk_158bc50_write(s, v.field_70);
    s->Write(v.field_98);
    Unk_162d630_write(s, v.field_a0);
    WriteContainer(s, v.field_d8, Unk_162cec0_write);
    s->Write(v.field_f0);
    s->Write(v.field_f8);
    s->Write(v.field_fc);
    s->Write(v.field_fe);
    Unk_1589f50_write(s, v.field_100);
    if (!noHeader && v.GetVersion() >= 1) {
        Unk_158c210_write(s, v.field_1e8);
    }
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158a2d0
void Unk_158a2d0_write(nn::nex::ByteStream* s, const Unk_158a2d0& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    Unk_162cec0_write(s, v.field_20);
    Unk_158bc50_write(s, v.field_48);
    Unk_158bc50_write(s, v.field_70);
    s->Write(v.field_98);
    Unk_162d630_write(s, v.field_a0);
    WriteContainer(s, v.field_d8, Unk_162cec0_write);
    s->Write(v.field_f0);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158a460
void Unk_158a460_write(nn::nex::ByteStream* s, const Unk_158a460& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    Unk_15c8ca0_write(s, v.field_18);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158a540
void Unk_158a540_write(nn::nex::ByteStream* s, const Unk_158a540& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    Unk_15c8ca0_write(s, v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158a620
void Unk_158a620_write(nn::nex::ByteStream* s, const Unk_158a620& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    Unk_15c8ca0_write(s, v.field_1c);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158a880
void Unk_158a880_write(nn::nex::ByteStream* s, const Unk_158a880& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158a970
void Unk_158a970_write(nn::nex::ByteStream* s, const Unk_158a970& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    Unk_158c210_write(s, v.field_18);
    s->Write(v.field_38);
    s->Write(v.field_40);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158aa70
void Unk_158aa70_write(nn::nex::ByteStream* s, const Unk_158aa70& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158ac40
void Unk_158ac40_write(nn::nex::ByteStream* s, const Unk_158ac40& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    WriteContainer(s, v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158ad60
void Unk_158ad60_write(nn::nex::ByteStream* s, const Unk_158ad60& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    WriteContainer(s, v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158ae80
void Unk_158ae80_read(nn::nex::ByteStream* s, Unk_158ae80& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (s->m_error) return;
    Unk_162d000_read(s, v.field_10);
    if (s->m_error) return;
    if (s->m_error) return;
    Unk_162d000_read(s, v.field_38);
    bool err = s->m_error;
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x710158b6f0
void Unk_158b6f0_read(nn::nex::ByteStream* s, Unk_158b6f0& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (!ReadField(s, v.field_10)) return;
    bool err = !ReadField(s, v.field_18);
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x710158b890
void Unk_158b890_read(nn::nex::ByteStream* s, Unk_158b890& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (!ReadField(s, v.field_10)) return;
    bool err = !ReadField(s, v.field_18);
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x710158ba20
void Unk_158ba20_read(nn::nex::ByteStream* s, Unk_158ba20& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (!ReadField(s, v.field_10)) return;
    if (!ReadField(s, v.field_18)) return;
    bool err = !ReadField(s, v.field_20);
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x710158bf20
void Unk_158bf20_read(nn::nex::ByteStream* s, Unk_158bf20& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (!ReadField(s, v.field_10)) return;
    if (!ReadField(s, v.field_18)) return;
    bool err = !ReadField(s, v.field_20);
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x710158c110
void Unk_158c110_write(nn::nex::ByteStream* s, const Unk_158c110& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_a);
    Unk_15c8ca0_write(s, v.field_c);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158c300
void Unk_158c300_write(nn::nex::ByteStream* s, const Unk_158c300& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    Unk_158c210_write(s, v.field_20);
    s->Write(v.field_40);
    WriteContainer(s, v.field_48, Unk_162cec0_write);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158c460
void Unk_158c460_write(nn::nex::ByteStream* s, const Unk_158c460& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    s->Write(v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158f110
void Unk_158f110_write(nn::nex::ByteStream* s, const Unk_158f110& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_9);
    s->Write(v.field_a);
    s->Write(v.field_b);
    s->Write(v.field_10);
    s->Write(v.field_18);
    s->Write(v.field_1c);
    s->Write(v.field_20);
    s->Write(v.field_22);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158f260
void Unk_158f260_write(nn::nex::ByteStream* s, const Unk_158f260& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_9);
    Unk_158f110_write(s, v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158c980
void Unk_158c980_write(nn::nex::ByteStream* s, const Unk_158c980& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    Unk_162cec0_write(s, v.field_10);
    s->Write(v.field_38);
    Unk_162d630_write(s, v.field_40);
    Unk_158bc50_write(s, v.field_78);
    Unk_158bc50_write(s, v.field_a0);
    s->Write(v.field_c8);
    s->Write(v.field_cc);
    s->Write(v.field_d0);
    WriteContainer(s, v.field_d8, Unk_162cec0_write);
    WriteContainer(s, v.field_f0, Unk_158f260_write);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158cb70
void Unk_158cb70_write(nn::nex::ByteStream* s, const Unk_158cb70& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    s->Write(v.field_20);
    WriteContainer(s, v.field_28, Unk_162cec0_write);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158ec60
void Unk_158ec60_write(nn::nex::ByteStream* s, const Unk_158ec60& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    s->Write(v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710158ed50
void Unk_158ed50_read(nn::nex::ByteStream* s, Unk_158ed50& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (!ReadField(s, v.field_10)) return;
    if (!ReadField(s, v.field_18)) return;
    bool err = !ReadField(s, v.field_20);
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x710158f560
void Unk_158f560_write(nn::nex::ByteStream* s, const Unk_158f560& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x7101591630
void Unk_1591630_write(nn::nex::ByteStream* s, const Unk_1591630& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    s->Write(v.field_20);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x7101591910
void Unk_1591910_write(nn::nex::ByteStream* s, const Unk_1591910& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x7101591a00
void Unk_1591a00_write(nn::nex::ByteStream* s, const Unk_1591a00& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_9);
    s->Write(v.field_a);
    Unk_162d630_write(s, v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71016345b0
void Unk_16345b0_write(nn::nex::ByteStream* s, const Unk_16345b0& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    s->Write(v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015a6e50
void Unk_15a6e50_write(nn::nex::ByteStream* s, const Unk_15a6e50& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    WriteContainer(s, v.field_10, Unk_162cec0_write);
    Unk_162cec0_write(s, v.field_28);
    Unk_162cec0_write(s, v.field_50);
    Unk_162cec0_write(s, v.field_78);
    Unk_162cec0_write(s, v.field_a0);
    Unk_15c8ca0_write(s, v.field_c8);
    Unk_15c8ca0_write(s, v.field_c9);
    Unk_15c8ca0_write(s, v.field_ca);
    s->Write(v.field_cc);
    s->Write(v.field_d0);
    Unk_15a4f80_write(s, v.field_d8);
    Unk_15c8ca0_write(s, v.field_100);
    Unk_15c8ca0_write(s, v.field_101);
    s->Write(v.field_104);
    Unk_162cec0_write(s, v.field_108);
    Unk_16345b0_write(s, v.field_130);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015a1f30
void Unk_15a1f30_write(nn::nex::ByteStream* s, const Unk_15a1f30& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    Unk_15a5a50_write(s, v.field_10);
    WriteContainer(s, v.field_160);
    s->Write(v.field_178);
    s->Write(v.field_17c);
    Unk_162cec0_write(s, v.field_180);
    s->Write(v.field_1a8);
    WriteContainer(s, v.field_1b0, Unk_15a6e50_write);
    WriteContainer(s, v.field_1c8);
    Unk_15a3800_write(s, v.field_1e0);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015a2850
void Unk_15a2850_write(nn::nex::ByteStream* s, const Unk_15a2850& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    Unk_162cec0_write(s, v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015a2e20
void Unk_15a2e20_read(nn::nex::ByteStream* s, Unk_15a2e20& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (s->m_error) return;
    Unk_15a2fc0_read(s, v.field_10);
    if (s->m_error) return;
    bool err = !ReadField(s, v.field_28);
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x71015a3220
void Unk_15a3220_write(nn::nex::ByteStream* s, const Unk_15a3220& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    Unk_15a5a50_write(s, v.field_10);
    WriteContainer(s, v.field_160);
    s->Write(v.field_178);
    s->Write(v.field_17c);
    Unk_162cec0_write(s, v.field_180);
    s->Write(v.field_1a8);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015a3380
void Unk_15a3380_write(nn::nex::ByteStream* s, const Unk_15a3380& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    WriteContainer(s, v.field_10);
    s->Write(v.field_28);
    Unk_15a3800_write(s, v.field_30);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015a3640
void Unk_15a3640_write(nn::nex::ByteStream* s, const Unk_15a3640& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    WriteContainer(s, v.field_10);
    s->Write(v.field_28);
    s->Write(v.field_2c);
    s->Write(v.field_30);
    Unk_162cec0_write(s, v.field_38);
    Unk_162cec0_write(s, v.field_60);
    Unk_162cec0_write(s, v.field_88);
    s->Write(v.field_b0);
    s->Write(v.field_b2);
    Unk_15a3800_write(s, v.field_b8);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015a50e0
void Unk_15a50e0_read(nn::nex::ByteStream* s, Unk_15a50e0& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (s->m_error) return;
    Unk_15a5230_read(s, v.field_10);
    bool err = s->m_error;
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x71015a86c0
void Unk_15a86c0_read(nn::nex::ByteStream* s, Unk_15a86c0& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (s->m_error) return;
    Unk_15a8860_read(s, v.field_10);
    if (s->m_error) return;
    bool err = !ReadField(s, v.field_28);
    if (noHeader | err) return;
    EndStructure(s, start, length);
}

// 0x71015aefd0
void Unk_15aefd0_write(nn::nex::ByteStream* s, const Unk_15aefd0& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015af470
void Unk_15af470_write(nn::nex::ByteStream* s, const Unk_15af470& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    s->Write(v.field_1c);
    s->Write(v.field_20);
    Unk_162d630_write(s, v.field_28);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015af2e0
void Unk_15af2e0_write(nn::nex::ByteStream* s, const Unk_15af2e0& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    WriteContainer(s, v.field_18, Unk_15af470_write);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015af9d0
void Unk_15af9d0_write(nn::nex::ByteStream* s, const Unk_15af9d0& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    s->Write(v.field_10);
    WriteContainer(s, v.field_18);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015b04b0
void Unk_15b04b0_write(nn::nex::ByteStream* s, const Unk_15b04b0& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    s->Write(v.field_10);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015b05c0
void Unk_15b05c0_write(nn::nex::ByteStream* s, const Unk_15b05c0& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_10);
    s->Write(v.field_18);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x71015b2dc0
void Unk_15b2dc0_write(nn::nex::ByteStream* s, const Unk_15b2dc0& v) {
    bool noHeader = s->m_noHeader;
    size_t start = 0;
    if (!noHeader) {
        s->Write(std::min(v.GetVersion(), (u8)0));
        start = s->m_buffer->m_size;
        s->Write((u32)0);
    }
    s->Write(v.field_c);
    s->Write(v.field_10);
    s->Write(v.field_18);
    s->Write(v.field_20);
    s->Write(v.field_22);
    s->Write(v.field_24);
    s->Write(v.field_28);
    s->Write(v.field_2c);
    s->Write(v.field_30);
    Unk_162cec0_write(s, v.field_38);
    if (!noHeader) {
        size_t end = s->m_buffer->m_size;
        s->Unk_15c8aa0(start);
        s->Write((u32)(end - start - 4));
        s->Unk_15c8aa0(end);
    }
}

// 0x710162f8a0
void Unk_162f8a0_read(nn::nex::ByteStream* s, Unk_162f8a0& v) {
    v.m_version = 0;
    bool noHeader = s->m_noHeader;
    u32 length = 0;
    if (!noHeader) {
        ReadField(s, v.m_version);
        if (s->m_error) return;
        if (!ReadLength(s, length)) return;
    }
    size_t start = s->m_pos;
    if (s->m_error) return;
    if (s->m_error) return;
    Unk_162d5a0_read(s, v.field_10);
    if (s->m_error) return;
    bool err = !ReadField(s, v.field_80);
    if (noHeader | err) return;
    EndStructure(s, start, length);
}
