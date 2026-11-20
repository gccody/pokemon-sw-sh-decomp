// Scope: common
// The arguments of the battle server's commands, as the command buffer holds
// them: big-endian bytes, packed by the command's argument format (one byte, a
// pair of bytes, three five-bit fields in two bytes, ...). The reader fills an
// array of ints from the buffer. Placeholder names: nothing names the buffer
// or the formats.
#include <types.h>

// A list of bytes: how many are written, how many are read, and the bytes
struct Unk_813d60_Buffer {
    u32 Unk_Read8() { return field_8[field_4++]; }
    u32 Unk_Read16() {
        u32 position = field_4;
        u32 value = field_8[position] << 8 | field_8[position + 1];
        field_4 = position + 2;
        return value;
    }
    u32 Unk_Read24() {
        u32 position = field_4;
        u32 value = field_8[position] << 16 | field_8[position + 1] << 8 | field_8[position + 2];
        field_4 = position + 3;
        return value;
    }
    u32 Unk_Read32() {
        u32 position = field_4;
        u32 value = field_8[position] << 24 | field_8[position + 1] << 16 |
                    field_8[position + 2] << 8 | field_8[position + 3];
        field_4 = position + 4;
        return value;
    }

    u32 field_0;
    u32 field_4;
    u8 field_8[1];
};

// 0x7100813d60: reads the arguments of a command of that format
// NON_MATCHING: 6 instructions, all in which cases share their last
// instructions. The original shares format 16's last store with format 9's
// (and so keeps the common `ret` after format 9); this shares format 100's two
// last stores with format 116's, and its `ret` is the last instruction.
void Unk_813d60(Unk_813d60_Buffer* self, u8 format, s32* out) {
    switch (format) {
        case 1: {
            out[0] = self->Unk_Read8();
            break;
        }
        case 2: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            break;
        }
        case 3: {
            u32 v0 = self->Unk_Read8();
            out[0] = v0 >> 3;
            out[1] = v0 & 0x7;
            out[2] = self->Unk_Read8();
            break;
        }
        case 4: {
            u32 v0 = self->Unk_Read8();
            out[0] = v0 >> 3;
            out[1] = v0 & 0x7;
            out[2] = self->Unk_Read8();
            out[3] = self->Unk_Read16();
            break;
        }
        case 5: {
            u32 v0 = self->Unk_Read16();
            out[0] = (v0 >> 10) & 0x1f;
            out[1] = (v0 >> 5) & 0x1f;
            out[2] = v0 & 0x1f;
            out[3] = self->Unk_Read16();
            out[4] = self->Unk_Read16();
            break;
        }
        case 6: {
            u32 v0 = self->Unk_Read16();
            u32 v1 = self->Unk_Read16();
            out[0] = (v0 >> 10) & 0x1f;
            out[1] = (v0 >> 5) & 0x1f;
            out[2] = v0 & 0x1f;
            out[3] = (v1 >> 10) & 0x1f;
            out[4] = (v1 >> 5) & 0x1f;
            out[5] = v1 & 0x1f;
            break;
        }
        case 7: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read8();
            out[3] = self->Unk_Read8();
            out[4] = self->Unk_Read8();
            out[5] = self->Unk_Read8();
            out[6] = self->Unk_Read8();
            break;
        }
        case 8: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read8();
            out[3] = self->Unk_Read8();
            out[4] = self->Unk_Read8();
            out[5] = self->Unk_Read8();
            out[6] = self->Unk_Read8();
            out[7] = self->Unk_Read8();
            break;
        }
        case 9: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read8();
            out[3] = self->Unk_Read8();
            out[4] = self->Unk_Read8();
            out[5] = self->Unk_Read8();
            out[6] = self->Unk_Read8();
            out[7] = self->Unk_Read8();
            out[8] = self->Unk_Read8();
            break;
        }
        case 16:
        case 32: {
            out[0] = self->Unk_Read16();
            out[1] = self->Unk_Read32();
            out[2] = self->Unk_Read32();
            out[3] = self->Unk_Read32();
            out[4] = self->Unk_Read32();
            out[5] = self->Unk_Read32();
            out[6] = self->Unk_Read32();
            out[7] = self->Unk_Read32();
            out[8] = self->Unk_Read32();
            break;
        }
        case 17: {
            out[0] = self->Unk_Read16();
            break;
        }
        case 18: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read16();
            break;
        }
        case 19: {
            u32 v0 = self->Unk_Read8();
            out[0] = v0 >> 3;
            out[1] = v0 & 0x7;
            out[2] = self->Unk_Read16();
            break;
        }
        case 20: {
            u32 v0 = self->Unk_Read8();
            out[0] = v0 >> 3;
            out[1] = v0 & 0x7;
            u32 v1 = self->Unk_Read8();
            out[2] = v1 >> 3;
            out[3] = v1 & 0x7;
            break;
        }
        case 21: {
            u32 v0 = self->Unk_Read8();
            u32 v1 = self->Unk_Read8();
            out[0] = v0 >> 3;
            out[1] = v0 & 0x7;
            out[2] = v1 >> 1;
            out[3] = v1 & 0x1;
            out[4] = self->Unk_Read16();
            break;
        }
        case 22: {
            u32 v0 = self->Unk_Read8();
            out[0] = v0 >> 5;
            out[1] = (v0 >> 3) & 0x3;
            out[2] = (v0 >> 2) & 0x1;
            out[3] = (v0 >> 1) & 0x1;
            out[4] = v0 & 0x1;
            out[5] = self->Unk_Read16();
            break;
        }
        case 23: {
            out[0] = self->Unk_Read16();
            out[1] = self->Unk_Read16();
            out[2] = self->Unk_Read16();
            out[3] = self->Unk_Read16();
            out[4] = self->Unk_Read16();
            out[5] = self->Unk_Read16();
            out[6] = self->Unk_Read16();
            break;
        }
        case 24: {
            out[0] = self->Unk_Read16();
            out[1] = self->Unk_Read16();
            out[2] = self->Unk_Read16();
            out[3] = self->Unk_Read16();
            out[4] = self->Unk_Read16();
            out[5] = self->Unk_Read16();
            out[6] = self->Unk_Read16();
            out[7] = self->Unk_Read16();
            break;
        }
        case 33: {
            out[0] = self->Unk_Read32();
            break;
        }
        case 34: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read32();
            break;
        }
        case 35: {
            u32 v0 = self->Unk_Read16();
            out[0] = (v0 >> 10) & 0x1f;
            out[1] = (v0 >> 5) & 0x1f;
            out[2] = v0 & 0x1f;
            break;
        }
        case 36: {
            u32 v0 = self->Unk_Read24();
            out[0] = v0 >> 19;
            out[1] = (v0 >> 14) & 0x1f;
            out[2] = v0 & 0x3fff;
            out[3] = self->Unk_Read8();
            break;
        }
        case 37: {
            u32 v0 = self->Unk_Read8();
            out[0] = v0 >> 5;
            out[1] = (v0 >> 2) & 0x7;
            out[2] = (v0 >> 1) & 0x1;
            out[3] = v0 & 0x1;
            out[4] = self->Unk_Read16();
            break;
        }
        case 38: {
            u32 v0 = self->Unk_Read24();
            out[0] = (v0 >> 15) & 0x1f;
            out[1] = (v0 >> 10) & 0x1f;
            out[2] = (v0 >> 5) & 0x1f;
            out[3] = v0 & 0x1f;
            out[4] = self->Unk_Read16();
            out[5] = self->Unk_Read16();
            break;
        }
        case 39: {
            u32 v0 = self->Unk_Read24();
            out[0] = (v0 >> 12) & 0x1f;
            out[1] = (v0 >> 7) & 0x1f;
            out[2] = (v0 >> 2) & 0x1f;
            out[3] = (v0 >> 1) & 0x1;
            out[4] = v0 & 0x1;
            out[5] = self->Unk_Read16();
            out[6] = self->Unk_Read16();
            break;
        }
        case 40: {
            out[0] = self->Unk_Read32();
            out[1] = self->Unk_Read32();
            out[2] = self->Unk_Read32();
            out[3] = self->Unk_Read32();
            out[4] = self->Unk_Read32();
            out[5] = self->Unk_Read32();
            out[6] = self->Unk_Read32();
            out[7] = self->Unk_Read32();
            break;
        }
        case 50: {
            u32 v0 = self->Unk_Read8();
            out[0] = v0 >> 4;
            out[1] = v0 & 0xf;
            break;
        }
        case 51: {
            u32 v0 = self->Unk_Read24();
            out[0] = v0 >> 19;
            out[1] = (v0 >> 14) & 0x1f;
            out[2] = v0 & 0x3fff;
            break;
        }
        case 52: {
            u32 v0 = self->Unk_Read24();
            out[0] = v0 >> 19;
            out[1] = (v0 >> 14) & 0x1f;
            out[2] = v0 & 0x3fff;
            out[3] = self->Unk_Read16();
            break;
        }
        case 53: {
            out[0] = self->Unk_Read16();
            out[1] = self->Unk_Read16();
            out[2] = self->Unk_Read16();
            out[3] = self->Unk_Read16();
            out[4] = self->Unk_Read16();
            break;
        }
        case 54: {
            u32 v0 = self->Unk_Read16();
            out[0] = v0 >> 11;
            out[1] = (v0 >> 6) & 0x1f;
            out[2] = v0 & 0x3f;
            out[3] = self->Unk_Read16();
            out[4] = self->Unk_Read16();
            out[5] = self->Unk_Read16();
            break;
        }
        case 55: {
            u32 v0 = self->Unk_Read32();
            out[0] = (v0 >> 20) & 0x1f;
            out[1] = (v0 >> 15) & 0x1f;
            out[2] = (v0 >> 10) & 0x1f;
            out[3] = (v0 >> 5) & 0x1f;
            out[4] = v0 & 0x1f;
            out[5] = self->Unk_Read16();
            out[6] = self->Unk_Read16();
            break;
        }
        case 66: {
            u32 v0 = self->Unk_Read8();
            out[0] = v0 >> 3;
            out[1] = v0 & 0x7;
            break;
        }
        case 67: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read8();
            break;
        }
        case 68: {
            u32 v0 = self->Unk_Read16();
            out[0] = v0 >> 11;
            out[1] = (v0 >> 6) & 0x1f;
            out[2] = v0 & 0x3f;
            out[3] = self->Unk_Read16();
            break;
        }
        case 70: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read8();
            out[3] = self->Unk_Read8();
            out[4] = self->Unk_Read16();
            out[5] = self->Unk_Read16();
            break;
        }
        case 71: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read8();
            out[3] = self->Unk_Read8();
            out[4] = self->Unk_Read8();
            out[5] = self->Unk_Read16();
            out[6] = self->Unk_Read16();
            break;
        }
        case 83: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read16();
            break;
        }
        case 84: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read8();
            out[3] = self->Unk_Read8();
            break;
        }
        case 86: {
            u32 v0 = self->Unk_Read24();
            out[0] = v0 >> 19;
            out[1] = (v0 >> 14) & 0x1f;
            out[2] = v0 & 0x3fff;
            u32 v1 = self->Unk_Read8();
            out[3] = v1 >> 1;
            out[4] = v1 & 0x1;
            out[5] = self->Unk_Read8();
            break;
        }
        case 99: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read32();
            break;
        }
        case 100: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read16();
            out[3] = self->Unk_Read16();
            break;
        }
        case 115: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read32();
            out[2] = self->Unk_Read32();
            break;
        }
        case 116: {
            out[0] = self->Unk_Read8();
            out[1] = self->Unk_Read8();
            out[2] = self->Unk_Read32();
            out[3] = self->Unk_Read32();
            break;
        }
        default:
            break;
    }
}
