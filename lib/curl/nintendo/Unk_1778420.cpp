// Pokemon SwSh decomp: Nintendo's libcurl tag function, not public,
// reconstructed from the binary (Sword 0x7101778420). It keeps the SDK's
// middleware string referenced, like PhysX's NpSetMiddlewareInfo. Nintendo's
// global_init() calls it (lib/curl/lib/easy.c). Neither the file's nor the
// function's name is known.

#include <nn/os.h>

extern "C" void Unk_1778420(void) {
    nn::util::ReferSymbol("SDK MW+Nintendo+NintendoSDK_libcurl-7_3_2-Release");
}
