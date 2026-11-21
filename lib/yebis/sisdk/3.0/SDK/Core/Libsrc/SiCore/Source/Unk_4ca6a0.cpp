// Scope: common
// The tables of SiCore's noise (0x71004c9110 reads them): a permutation of 256
// numbers and three tables of 256 random numbers from -1 to 1. The file's
// name isn't in the executable; its static initialiser is 0x71004ca7a0
// (lib/yebis/static).
#include <stdlib.h>

#include <types.h>

// 0x710276bc20, 0x710276c020, 0x710276c420, 0x710276c820
int Unk_276bc20[0x100];
float Unk_276c020[0x100];
float Unk_276c420[0x100];
float Unk_276c820[0x100];

// 0x71004ca6a0
void Unk_4ca6a0() {
    for (int i = 0; i < 0x100; i++) {
        Unk_276bc20[i] = i;
        float x = static_cast<float>(rand()) * (1.0f / 2147483648.0f);
        Unk_276c020[i] = x * 2.0f - 1.0f;
        float y = static_cast<float>(rand()) * (1.0f / 2147483648.0f);
        Unk_276c420[i] = y * 2.0f - 1.0f;
        float z = static_cast<float>(rand()) * (1.0f / 2147483648.0f);
        Unk_276c820[i] = z * 2.0f - 1.0f;
    }
    for (int i = 0; i < 0x100; i++) {
        int j = rand() % 0x100;
        int n = Unk_276bc20[i];
        Unk_276bc20[i] = Unk_276bc20[j];
        Unk_276bc20[j] = n;
    }
}
