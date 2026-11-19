// Scope: common
// NEX 4.6.8's DDL data classes (tools/nexclasses.py): each _DDL_X holds a
// structure's fields, and X derives from it. Only what their destructors show
// is declared (Strings, containers, member classes); the scalars are padding.
// The class names are their RTTI's; Unk_<vtable> are placeholders.
#include <nn/nex/RefCountedObject.h>
#include <nn/nex/String.h>
#include <nn/nex/qList.h>
#include <nn/nex/qVector.h>

// An element of a container of polymorphic objects (a placeholder: which class
// isn't known, only its size).
template <size_t N>
class Unk_Element : public nn::nex::RootObject {
public:
    virtual ~Unk_Element();
    u8 _8[N - 8];
};

namespace nn {
namespace nex {

class StationURL : public nn::nex::RootObject {
public:
    virtual ~StationURL();
    u8 _8[0x68];
};

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_MatchmakeSession : public nn::nex::RootObject {
public:
    virtual ~_DDL_MatchmakeSession();
    u8 _8[0x148];
};

}  // namespace nex
}  // namespace nn

class Unk_240d1b8 : public nn::nex::RootObject {
public:
    u8 _8[0x8];
    nn::nex::qVector<u8> m_10;
};
PKMN_OFFSET_ASSERT(Unk_240d1b8, m_10, 0x10);

// Classes with nothing but an empty destructor of their own.
namespace nn {
namespace nex {

class LocalClock : public RootObject {
public:
    virtual ~LocalClock();
};

// 0x71015ce670 (D2), 0x71015ce680 (D0)
LocalClock::~LocalClock() {}

class PseudoGlobalVariableList : public RootObject {
public:
    virtual ~PseudoGlobalVariableList();
};

// 0x71015cee00 (D2), 0x71015cee10 (D0)
PseudoGlobalVariableList::~PseudoGlobalVariableList() {}

class UPnPProperties : public RootObject {
public:
    virtual ~UPnPProperties();
};

// 0x71015ed920 (D2), 0x71015ed930 (D0)
UPnPProperties::~UPnPProperties() {}

class RTT : public RootObject {
public:
    virtual ~RTT();
};

// 0x710160aff0 (D2), 0x710160b000 (D0)
RTT::~RTT() {}

class Timeout : public RootObject {
public:
    virtual ~Timeout();
};

// 0x710160fc90 (D2), 0x710160fca0 (D0)
Timeout::~Timeout() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreGetNotificationUrlParam : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreGetNotificationUrlParam();
    u8 _8[0x8];
    nn::nex::String m_10;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreGetNotificationUrlParam, m_10, 0x10);

class DataStoreGetNotificationUrlParam : public _DDL_DataStoreGetNotificationUrlParam {
public:
    virtual ~DataStoreGetNotificationUrlParam();
};

// 0x710157ec10 (D2), 0x7101592020 (D0)
_DDL_DataStoreGetNotificationUrlParam::~_DDL_DataStoreGetNotificationUrlParam() {}

// 0x7101591fd0 (D0; the D2 is _DDL_DataStoreGetNotificationUrlParam's)
DataStoreGetNotificationUrlParam::~DataStoreGetNotificationUrlParam() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreReqGetAdditionalMeta : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreReqGetAdditionalMeta();
    u8 _8[0x18];
    nn::nex::qBuffer m_20;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetAdditionalMeta, m_20, 0x20);

class DataStoreReqGetAdditionalMeta : public _DDL_DataStoreReqGetAdditionalMeta {
public:
    virtual ~DataStoreReqGetAdditionalMeta();
};

// 0x710157f300 (D2), 0x7101592390 (D0)
_DDL_DataStoreReqGetAdditionalMeta::~_DDL_DataStoreReqGetAdditionalMeta() {}

// 0x7101592350 (D0; the D2 is _DDL_DataStoreReqGetAdditionalMeta's)
DataStoreReqGetAdditionalMeta::~DataStoreReqGetAdditionalMeta() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreReqPostInfoV1 : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreReqPostInfoV1();
    u8 _8[0x8];
    nn::nex::String m_10;
    nn::nex::qVector<Unk_Element<0x60>> m_38;
    nn::nex::qVector<Unk_Element<0x60>> m_50;
    nn::nex::qVector<u8> m_68;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqPostInfoV1, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqPostInfoV1, m_38, 0x38);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqPostInfoV1, m_50, 0x50);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqPostInfoV1, m_68, 0x68);

class DataStoreReqPostInfoV1 : public _DDL_DataStoreReqPostInfoV1 {
public:
    virtual ~DataStoreReqPostInfoV1();
};

// 0x7101582fc0 (D2), 0x71015928f0 (D0)
_DDL_DataStoreReqPostInfoV1::~_DDL_DataStoreReqPostInfoV1() {}

// 0x71015928c0 (D0; the D2 is _DDL_DataStoreReqPostInfoV1's)
DataStoreReqPostInfoV1::~DataStoreReqPostInfoV1() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreGetSpecificMetaParamV1 : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreGetSpecificMetaParamV1();
    u8 _8[0x8];
    nn::nex::qVector<u8> m_10;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreGetSpecificMetaParamV1, m_10, 0x10);

class DataStoreGetSpecificMetaParamV1 : public _DDL_DataStoreGetSpecificMetaParamV1 {
public:
    virtual ~DataStoreGetSpecificMetaParamV1();
};

// 0x7101586c80 (D2), 0x7101592cc0 (D0)
_DDL_DataStoreGetSpecificMetaParamV1::~_DDL_DataStoreGetSpecificMetaParamV1() {}

// 0x7101592c80 (D0; the D2 is _DDL_DataStoreGetSpecificMetaParamV1's)
DataStoreGetSpecificMetaParamV1::~DataStoreGetSpecificMetaParamV1() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreGetSpecificMetaParam : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreGetSpecificMetaParam();
    u8 _8[0x8];
    nn::nex::qVector<u8> m_10;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreGetSpecificMetaParam, m_10, 0x10);

class DataStoreGetSpecificMetaParam : public _DDL_DataStoreGetSpecificMetaParam {
public:
    virtual ~DataStoreGetSpecificMetaParam();
};

// 0x7101588d20 (D2), 0x7101592f40 (D0)
_DDL_DataStoreGetSpecificMetaParam::~_DDL_DataStoreGetSpecificMetaParam() {}

// 0x7101592f00 (D0; the D2 is _DDL_DataStoreGetSpecificMetaParam's)
DataStoreGetSpecificMetaParam::~DataStoreGetSpecificMetaParam() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreReqUpdateInfo : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreReqUpdateInfo();
    u8 _8[0x8];
    nn::nex::String m_10;
    nn::nex::qVector<Unk_Element<0x60>> m_38;
    nn::nex::qVector<Unk_Element<0x60>> m_50;
    nn::nex::qVector<u8> m_68;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqUpdateInfo, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqUpdateInfo, m_38, 0x38);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqUpdateInfo, m_50, 0x50);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqUpdateInfo, m_68, 0x68);

class DataStoreReqUpdateInfo : public _DDL_DataStoreReqUpdateInfo {
public:
    virtual ~DataStoreReqUpdateInfo();
};

// 0x7101589070 (D2), 0x71015930c0 (D0)
_DDL_DataStoreReqUpdateInfo::~_DDL_DataStoreReqUpdateInfo() {}

// 0x7101593090 (D0; the D2 is _DDL_DataStoreReqUpdateInfo's)
DataStoreReqUpdateInfo::~DataStoreReqUpdateInfo() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreReqGetNotificationUrlInfo : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreReqGetNotificationUrlInfo();
    u8 _8[0x8];
    nn::nex::String m_10;
    nn::nex::String m_38;
    nn::nex::String m_60;
    nn::nex::qVector<u8> m_88;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetNotificationUrlInfo, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetNotificationUrlInfo, m_38, 0x38);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetNotificationUrlInfo, m_60, 0x60);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetNotificationUrlInfo, m_88, 0x88);

class DataStoreReqGetNotificationUrlInfo : public _DDL_DataStoreReqGetNotificationUrlInfo {
public:
    virtual ~DataStoreReqGetNotificationUrlInfo();
};

// 0x7101591ef0 (D2), 0x7101591f60 (D0)
_DDL_DataStoreReqGetNotificationUrlInfo::~_DDL_DataStoreReqGetNotificationUrlInfo() {}

// 0x7101591e80 (D0; the D2 is _DDL_DataStoreReqGetNotificationUrlInfo's)
DataStoreReqGetNotificationUrlInfo::~DataStoreReqGetNotificationUrlInfo() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreReqGetInfoV1 : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreReqGetInfoV1();
    u8 _8[0x8];
    nn::nex::String m_10;
    nn::nex::qVector<Unk_Element<0x60>> m_38;
    u8 _50[0x8];
    nn::nex::qVector<u8> m_58;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetInfoV1, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetInfoV1, m_38, 0x38);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetInfoV1, m_58, 0x58);

class DataStoreReqGetInfoV1 : public _DDL_DataStoreReqGetInfoV1 {
public:
    virtual ~DataStoreReqGetInfoV1();
};

// 0x7101592120 (D2), 0x71015921c0 (D0)
_DDL_DataStoreReqGetInfoV1::~_DDL_DataStoreReqGetInfoV1() {}

// 0x7101592080 (D0; the D2 is _DDL_DataStoreReqGetInfoV1's)
DataStoreReqGetInfoV1::~DataStoreReqGetInfoV1() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreReqGetInfo : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreReqGetInfo();
    u8 _8[0x8];
    nn::nex::String m_10;
    nn::nex::qVector<Unk_Element<0x60>> m_38;
    u8 _50[0x8];
    nn::nex::qVector<u8> m_58;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetInfo, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetInfo, m_38, 0x38);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqGetInfo, m_58, 0x58);

class DataStoreReqGetInfo : public _DDL_DataStoreReqGetInfo {
public:
    virtual ~DataStoreReqGetInfo();
};

// 0x7101592470 (D2), 0x7101592510 (D0)
_DDL_DataStoreReqGetInfo::~_DDL_DataStoreReqGetInfo() {}

// 0x71015923d0 (D0; the D2 is _DDL_DataStoreReqGetInfo's)
DataStoreReqGetInfo::~DataStoreReqGetInfo() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStorePreparePostParamV1 : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStorePreparePostParamV1();
    u8 _8[0x8];
    nn::nex::String m_10;
    u8 _38[0x8];
    nn::nex::qBuffer m_40;
    Unk_240d1b8 m_78;
    Unk_240d1b8 m_a0;
    u8 _c8[0x10];
    nn::nex::qVector<Unk_Element<0x28>> m_d8;
    nn::nex::qVector<Unk_Element<0x38>> m_f0;
};
PKMN_OFFSET_ASSERT(_DDL_DataStorePreparePostParamV1, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_DataStorePreparePostParamV1, m_40, 0x40);
PKMN_OFFSET_ASSERT(_DDL_DataStorePreparePostParamV1, m_78, 0x78);
PKMN_OFFSET_ASSERT(_DDL_DataStorePreparePostParamV1, m_a0, 0xa0);
PKMN_OFFSET_ASSERT(_DDL_DataStorePreparePostParamV1, m_d8, 0xd8);
PKMN_OFFSET_ASSERT(_DDL_DataStorePreparePostParamV1, m_f0, 0xf0);

class DataStorePreparePostParamV1 : public _DDL_DataStorePreparePostParamV1 {
public:
    virtual ~DataStorePreparePostParamV1();
};

// 0x7101592780 (D2), 0x7101592890 (D0)
_DDL_DataStorePreparePostParamV1::~_DDL_DataStorePreparePostParamV1() {}

// 0x7101592750 (D0; the D2 is _DDL_DataStorePreparePostParamV1's)
DataStorePreparePostParamV1::~DataStorePreparePostParamV1() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreReqPostInfo : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreReqPostInfo();
    u8 _8[0x10];
    nn::nex::String m_18;
    nn::nex::qVector<Unk_Element<0x60>> m_40;
    nn::nex::qVector<Unk_Element<0x60>> m_58;
    nn::nex::qVector<u8> m_70;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqPostInfo, m_18, 0x18);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqPostInfo, m_40, 0x40);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqPostInfo, m_58, 0x58);
PKMN_OFFSET_ASSERT(_DDL_DataStoreReqPostInfo, m_70, 0x70);

class DataStoreReqPostInfo : public _DDL_DataStoreReqPostInfo {
public:
    virtual ~DataStoreReqPostInfo();
};

// 0x7101592960 (D2), 0x7101592a40 (D0)
_DDL_DataStoreReqPostInfo::~_DDL_DataStoreReqPostInfo() {}

// 0x7101592930 (D0; the D2 is _DDL_DataStoreReqPostInfo's)
DataStoreReqPostInfo::~DataStoreReqPostInfo() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreMetaInfo : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreMetaInfo();
    u8 _8[0x20];
    nn::nex::String m_28;
    u8 _50[0x8];
    nn::nex::qBuffer m_58;
    Unk_240d1b8 m_90;
    Unk_240d1b8 m_b8;
    u8 _e0[0x30];
    nn::nex::qVector<Unk_Element<0x28>> m_110;
    nn::nex::qVector<Unk_Element<0x38>> m_128;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreMetaInfo, m_28, 0x28);
PKMN_OFFSET_ASSERT(_DDL_DataStoreMetaInfo, m_58, 0x58);
PKMN_OFFSET_ASSERT(_DDL_DataStoreMetaInfo, m_90, 0x90);
PKMN_OFFSET_ASSERT(_DDL_DataStoreMetaInfo, m_b8, 0xb8);
PKMN_OFFSET_ASSERT(_DDL_DataStoreMetaInfo, m_110, 0x110);
PKMN_OFFSET_ASSERT(_DDL_DataStoreMetaInfo, m_128, 0x128);

class DataStoreMetaInfo : public _DDL_DataStoreMetaInfo {
public:
    virtual ~DataStoreMetaInfo();
};

// 0x7101593490 (D2), 0x71015935a0 (D0)
_DDL_DataStoreMetaInfo::~_DDL_DataStoreMetaInfo() {}

// 0x7101593460 (D0; the D2 is _DDL_DataStoreMetaInfo's)
DataStoreMetaInfo::~DataStoreMetaInfo() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreChangeMetaParamV1 : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreChangeMetaParamV1();
    u8 _8[0x18];
    nn::nex::String m_20;
    Unk_240d1b8 m_48;
    Unk_240d1b8 m_70;
    u8 _98[0x8];
    nn::nex::qBuffer m_a0;
    nn::nex::qVector<Unk_Element<0x28>> m_d8;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParamV1, m_20, 0x20);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParamV1, m_48, 0x48);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParamV1, m_70, 0x70);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParamV1, m_a0, 0xa0);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParamV1, m_d8, 0xd8);

class DataStoreChangeMetaParamV1 : public _DDL_DataStoreChangeMetaParamV1 {
public:
    virtual ~DataStoreChangeMetaParamV1();
};

// 0x7101596920 (D2), 0x7101596a20 (D0)
_DDL_DataStoreChangeMetaParamV1::~_DDL_DataStoreChangeMetaParamV1() {}

// 0x71015969f0 (D0; the D2 is _DDL_DataStoreChangeMetaParamV1's)
DataStoreChangeMetaParamV1::~DataStoreChangeMetaParamV1() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreChangeMetaCompareParam : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreChangeMetaCompareParam();
    u8 _8[0x8];
    nn::nex::String m_10;
    Unk_240d1b8 m_38;
    Unk_240d1b8 m_60;
    u8 _88[0x8];
    nn::nex::qBuffer m_90;
    nn::nex::qVector<Unk_Element<0x28>> m_c8;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaCompareParam, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaCompareParam, m_38, 0x38);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaCompareParam, m_60, 0x60);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaCompareParam, m_90, 0x90);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaCompareParam, m_c8, 0xc8);

class DataStoreChangeMetaCompareParam : public _DDL_DataStoreChangeMetaCompareParam {
public:
    virtual ~DataStoreChangeMetaCompareParam();
};

// 0x7101596eb0 (D2), 0x7101596fb0 (D0)
_DDL_DataStoreChangeMetaCompareParam::~_DDL_DataStoreChangeMetaCompareParam() {}

// 0x7101596f80 (D0; the D2 is _DDL_DataStoreChangeMetaCompareParam's)
DataStoreChangeMetaCompareParam::~DataStoreChangeMetaCompareParam() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_DataStoreChangeMetaParam : public nn::nex::RootObject {
public:
    virtual ~_DDL_DataStoreChangeMetaParam();
    u8 _8[0x18];
    nn::nex::String m_20;
    Unk_240d1b8 m_48;
    Unk_240d1b8 m_70;
    u8 _98[0x8];
    nn::nex::qBuffer m_a0;
    nn::nex::qVector<Unk_Element<0x28>> m_d8;
    u8 _f0[0x10];
    nn::nex::_DDL_DataStoreChangeMetaCompareParam m_100;
};
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParam, m_20, 0x20);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParam, m_48, 0x48);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParam, m_70, 0x70);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParam, m_a0, 0xa0);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParam, m_d8, 0xd8);
PKMN_OFFSET_ASSERT(_DDL_DataStoreChangeMetaParam, m_100, 0x100);

class DataStoreChangeMetaParam : public _DDL_DataStoreChangeMetaParam {
public:
    virtual ~DataStoreChangeMetaParam();
};

// 0x7101596db0 (D2), 0x7101596e80 (D0)
_DDL_DataStoreChangeMetaParam::~_DDL_DataStoreChangeMetaParam() {}

// 0x7101596d80 (D0; the D2 is _DDL_DataStoreChangeMetaParam's)
DataStoreChangeMetaParam::~DataStoreChangeMetaParam() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_AutoMatchmakeParam : public nn::nex::RootObject {
public:
    virtual ~_DDL_AutoMatchmakeParam();
    u8 _8[0x8];
    nn::nex::_DDL_MatchmakeSession m_10;
    nn::nex::qList<u8> m_160;
    u8 _178[0x8];
    nn::nex::String m_180;
    u8 _1a8[0x8];
    nn::nex::qList<Unk_Element<0x10>> m_1b0;
    nn::nex::qList<u8> m_1c8;
};
PKMN_OFFSET_ASSERT(_DDL_AutoMatchmakeParam, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_AutoMatchmakeParam, m_160, 0x160);
PKMN_OFFSET_ASSERT(_DDL_AutoMatchmakeParam, m_180, 0x180);
PKMN_OFFSET_ASSERT(_DDL_AutoMatchmakeParam, m_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(_DDL_AutoMatchmakeParam, m_1c8, 0x1c8);

class AutoMatchmakeParam : public _DDL_AutoMatchmakeParam {
public:
    virtual ~AutoMatchmakeParam();
};

// 0x710159d030 (D2), 0x71015a98a0 (D0)
_DDL_AutoMatchmakeParam::~_DDL_AutoMatchmakeParam() {}

// 0x71015a9870 (D0; the D2 is _DDL_AutoMatchmakeParam's)
AutoMatchmakeParam::~AutoMatchmakeParam() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_FindMatchmakeSessionByParticipantResult : public nn::nex::RootObject {
public:
    virtual ~_DDL_FindMatchmakeSessionByParticipantResult();
    u8 _8[0x10];
    nn::nex::_DDL_MatchmakeSession m_18;
};
PKMN_OFFSET_ASSERT(_DDL_FindMatchmakeSessionByParticipantResult, m_18, 0x18);

class FindMatchmakeSessionByParticipantResult : public _DDL_FindMatchmakeSessionByParticipantResult {
public:
    virtual ~FindMatchmakeSessionByParticipantResult();
};

// 0x71015ab3d0 (D2), 0x71015ab3f0 (D0)
_DDL_FindMatchmakeSessionByParticipantResult::~_DDL_FindMatchmakeSessionByParticipantResult() {}

// 0x71015ab390 (D0; the D2 is _DDL_FindMatchmakeSessionByParticipantResult's)
FindMatchmakeSessionByParticipantResult::~FindMatchmakeSessionByParticipantResult() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_CreateMatchmakeSessionParam : public nn::nex::RootObject {
public:
    virtual ~_DDL_CreateMatchmakeSessionParam();
    u8 _8[0x8];
    nn::nex::_DDL_MatchmakeSession m_10;
    nn::nex::qList<u8> m_160;
    u8 _178[0x8];
    nn::nex::String m_180;
};
PKMN_OFFSET_ASSERT(_DDL_CreateMatchmakeSessionParam, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_CreateMatchmakeSessionParam, m_160, 0x160);
PKMN_OFFSET_ASSERT(_DDL_CreateMatchmakeSessionParam, m_180, 0x180);

class CreateMatchmakeSessionParam : public _DDL_CreateMatchmakeSessionParam {
public:
    virtual ~CreateMatchmakeSessionParam();
};

// 0x71015ab730 (D2), 0x71015ab7d0 (D0)
_DDL_CreateMatchmakeSessionParam::~_DDL_CreateMatchmakeSessionParam() {}

// 0x71015ab690 (D0; the D2 is _DDL_CreateMatchmakeSessionParam's)
CreateMatchmakeSessionParam::~CreateMatchmakeSessionParam() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_JoinMatchmakeSessionParam : public nn::nex::RootObject {
public:
    virtual ~_DDL_JoinMatchmakeSessionParam();
    u8 _8[0x8];
    nn::nex::qList<u8> m_10;
    u8 _28[0x10];
    nn::nex::String m_38;
    nn::nex::String m_60;
    nn::nex::String m_88;
};
PKMN_OFFSET_ASSERT(_DDL_JoinMatchmakeSessionParam, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_JoinMatchmakeSessionParam, m_38, 0x38);
PKMN_OFFSET_ASSERT(_DDL_JoinMatchmakeSessionParam, m_60, 0x60);
PKMN_OFFSET_ASSERT(_DDL_JoinMatchmakeSessionParam, m_88, 0x88);

class JoinMatchmakeSessionParam : public _DDL_JoinMatchmakeSessionParam {
public:
    virtual ~JoinMatchmakeSessionParam();
};

// 0x71015ab870 (D2), 0x71015abb40 (D0)
_DDL_JoinMatchmakeSessionParam::~_DDL_JoinMatchmakeSessionParam() {}

// 0x71015aba90 (D0; the D2 is _DDL_JoinMatchmakeSessionParam's)
JoinMatchmakeSessionParam::~JoinMatchmakeSessionParam() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_FindMatchmakeSessionByParticipantParam : public nn::nex::RootObject {
public:
    virtual ~_DDL_FindMatchmakeSessionByParticipantParam();
    u8 _8[0x8];
    nn::nex::qList<u8> m_10;
};
PKMN_OFFSET_ASSERT(_DDL_FindMatchmakeSessionByParticipantParam, m_10, 0x10);

class FindMatchmakeSessionByParticipantParam : public _DDL_FindMatchmakeSessionByParticipantParam {
public:
    virtual ~FindMatchmakeSessionByParticipantParam();
};

// 0x71015ac190 (D2), 0x71015ac200 (D0)
_DDL_FindMatchmakeSessionByParticipantParam::~_DDL_FindMatchmakeSessionByParticipantParam() {}

// 0x71015ac110 (D0; the D2 is _DDL_FindMatchmakeSessionByParticipantParam's)
FindMatchmakeSessionByParticipantParam::~FindMatchmakeSessionByParticipantParam() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_ConnectionData : public nn::nex::RootObject {
public:
    virtual ~_DDL_ConnectionData();
    u8 _8[0x8];
    nn::nex::StationURL m_10;
};
PKMN_OFFSET_ASSERT(_DDL_ConnectionData, m_10, 0x10);

class ConnectionData : public _DDL_ConnectionData {
public:
    virtual ~ConnectionData();
};

// 0x7101638a60 (D2), 0x7101638ac0 (D0)
_DDL_ConnectionData::~_DDL_ConnectionData() {}

// 0x7101638a80 (D0; the D2 is _DDL_ConnectionData's)
ConnectionData::~ConnectionData() {}

}  // namespace nex
}  // namespace nn

namespace nn {
namespace nex {

class _DDL_RVConnectionData : public nn::nex::RootObject {
public:
    virtual ~_DDL_RVConnectionData();
    u8 _8[0x8];
    nn::nex::StationURL m_10;
    nn::nex::qList<u8> m_80;
    nn::nex::StationURL m_98;
};
PKMN_OFFSET_ASSERT(_DDL_RVConnectionData, m_10, 0x10);
PKMN_OFFSET_ASSERT(_DDL_RVConnectionData, m_80, 0x80);
PKMN_OFFSET_ASSERT(_DDL_RVConnectionData, m_98, 0x98);

class RVConnectionData : public _DDL_RVConnectionData {
public:
    virtual ~RVConnectionData();
};

// 0x7101638b00 (D2), 0x7101638c10 (D0)
_DDL_RVConnectionData::~_DDL_RVConnectionData() {}

// 0x7101638b80 (D0; the D2 is _DDL_RVConnectionData's)
RVConnectionData::~RVConnectionData() {}

}  // namespace nex
}  // namespace nn
