#pragma once
#include "gflib3/Unk_239a418.h"

// Called with an object and a holder of it (a class with two callables and a
// reference to the object), before the holder lets go of it. Two holder
// classes pass themselves (Unk_23c14c0 and Unk_23dba98, both 0x110 bytes from
// their vptr to their second callable's end), and it only stores and
// compares the pointer: its type is a placeholder.
void Unk_5e2bc0(Unk_239a418* object, void* holder);
