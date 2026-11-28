// Scope: common
// The battle rule's positions (0x71007f9a10 to 0x71007fc1c0): which client
// stands at a position, which side a client is on, for each rule (0, 1 and
// 2). Placeholder names: rename once the functions are known.
#include <types.h>

// The side of each client, for each rule.
extern const u8 Unk_1f11b6c[5] __attribute__((visibility("hidden")));
extern const u8 Unk_1f11b71[5] __attribute__((visibility("hidden")));
extern const u8 Unk_1f11b76[5] __attribute__((visibility("hidden")));

u32 Unk_7f9ac0(u32 rule, u8 arg1, u8 position);

// 0x71007fa500
u8 Unk_7fa500(u32 rule, u32 client) {
    switch (rule) {
        case 0:
            if ((s32)client > 4)
                return 2;
            return Unk_1f11b6c[client];
        case 1:
            if ((s32)client > 4)
                return 2;
            return Unk_1f11b71[client];
        case 2:
            if ((s32)client > 4)
                return 2;
            return Unk_1f11b76[client];
    }
    return 2;
}

// 0x71007f9a10
u8 Unk_7f9a10(u32 rule, u8 arg1, u32 client) {
    u8 count = 0;
    for (u8 position = 0; position < 5; position++) {
        if (Unk_7f9ac0(rule, arg1, position) == client)
            count++;
    }
    return count;
}

// 0x71007f9c20
bool Unk_7f9c20(u32 rule, u8 arg1, u32 position) {
    return Unk_7f9ac0(rule, arg1, position) != 5;
}

// 0x71007f9c40
u8 Unk_7f9c40(u32 rule) {
    switch (rule) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 4;
    }
    return 3;
}

// 0x71007f9d10
u8 Unk_7f9d10(u32 rule, u8 arg1, u8 position) {
    return Unk_7fa500(rule, Unk_7f9ac0(rule, arg1, position));
}

// 0x71007fa950
bool Unk_7fa950(u8 side, u8 other) {
    if (side <= 1) {
        if (side == other)
            return true;
        switch (other) {
            case 3:
                return true;
            case 4:
                return side != 0;
            case 5:
                return side != 1;
        }
    }
    return false;
}

// 0x71007fa9c0
bool Unk_7fa9c0(u8 position) {
    return position < 2;
}

// 0x71007faa80
u8 Unk_7faa80(u32 rule, u8 position) {
    if (rule == 2)
        return position == 4 ? 0 : position;
    return position >> 1;
}

// 0x71007faf80
bool Unk_7faf80(u32 rule, u8 arg1, u32 client) {
    if ((s32)client <= 4) {
        for (u8 position = 0; position < 5; position++) {
            if (Unk_7f9ac0(rule, arg1, position) == client)
                return true;
        }
    }
    return false;
}

// 0x71007fc170
bool Unk_7fc170(u32 rule) {
    return rule == 2;
}

// 0x71007fc190
bool Unk_7fc190(u32 rule) {
    switch (rule) {
        case 0:
        case 1:
            return true;
        case 2:
            return false;
    }
    return false;
}
