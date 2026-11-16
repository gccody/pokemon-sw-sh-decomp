// Scope: common
// The Lua glue of the symbol-encounter AI (bin/field/param/symbol_encount/ai.blua): it
// binds field::content's Haxe types into the global table "fromcpp" with sol2 v2.20.4
// (lib/sol). Nearly all of this TU's code is sol2's template instances, 0x7100deeb10 to
// 0x7100e366b0 in Sword; see docs/compiler.md, section sol2, for the build settings
// (src/field/content's pkmn_library_settings entry) and what is left.
#include <sol/sol.hpp>

#include <types.h>

#include "field/content/HaxeFieldFunc.h"
#include "field/content/HaxeSymbolPokemonObject.h"
#include "field/content/HaxeVector2.h"
#include "field/content/HaxeVector3.h"

using namespace field::content;

// 0x7101f25c58, 0x7101f25c5c, 0x7101f25c60 (1, 2, 0xffffffff): the values of the
// RaycastTarget enum (the mask that PokemonObject.RaycastObject takes). They are read
// through the GOT, so they are const objects defined in another TU, not literals.
extern const unsigned int Unk_1f25c58;
extern const unsigned int Unk_1f25c5c;
extern const unsigned int Unk_1f25c60;

// Owner of the PokemonObject that 0x7100dee870 hands to the script.
struct Unk_dee870_Owner {
    u8 _0[0xc18];
    HaxeSymbolPokemonObject field_c18;
};
PKMN_OFFSET_ASSERT(Unk_dee870_Owner, field_c18, 0xc18);

// 0x7100dee870
// NON_MATCHING: a guess at the shape. Its only purpose here is the two sol2 instances it
// calls (0x7100deea20, the table traversal, and 0x7100dee930, the call), which match. The
// original reaches the owner through two pointers and the table through one, and it is
// one of three copies (0x7100df2100, 0x7100df21e0) that differ only in the function name,
// each next to small functions that look like a type-erased callable's.
void Unk_dee870(Unk_dee870_Owner** const* owner, sol::table* const* scripts) {
    HaxeSymbolPokemonObject object = (**owner)->field_c18;
    const char* name = "SLNoy2O";
    sol::function function = (**scripts)["CLwixWp"][name];
    function(object);
}

// fromcpp.Log: Print, Assert and AssertMsg do nothing in this build.
// 0x7100df22c0
void Unk_df22c0(const char*) {}
// 0x7100df22d0
void Unk_df22d0(bool) {}
// 0x7100df22e0
void Unk_df22e0(bool, const char*) {}

// 0x7100df4440 (Vector2), 0x7100df4730 (Vector3), 0x7100df4a40 (Field),
// 0x7100df4ce0 (PokemonObject)
template <typename T, typename... Args>
void Unk_df4440(sol::table& table, const char* name, Args&&... args) {
    table.new_usertype<T>(name, std::forward<Args>(args)...);
}

// 0x7100df22f0
// NON_MATCHING: the original creates "fromcpp" through 0x7100df4370, a separate function
// that takes the address of a one-pointer object on the caller's stack (a lambda capturing
// lua by reference?) and returns a copy of the new table, so its frame and the order of
// the stores that build the argument lists differ. All the calls it makes match.
void Unk_df22f0(sol::state& lua) {
    // One key/value pair per line, as sol2 takes them.
    // clang-format off
    sol::table fromcpp = lua.create_named_table("fromcpp");
    Unk_df4440<HaxeVector2>(fromcpp, "Vector2",
        "X", &HaxeVector2::X,
        "Y", &HaxeVector2::Y,
        "Create", &HaxeVector2::Create,
        "CreateAdd", &HaxeVector2::CreateAdd,
        "CreateSub", &HaxeVector2::CreateSub,
        "Dot", &HaxeVector2::Dot,
        "Cross", &HaxeVector2::Cross,
        "Add", &HaxeVector2::Add,
        "Sub", &HaxeVector2::Sub,
        "Mul", &HaxeVector2::Mul,
        "Normalize", &HaxeVector2::Normalize,
        "Length", &HaxeVector2::Length,
        "LengthSq", &HaxeVector2::LengthSq,
        "Clone", &HaxeVector2::Clone);
    Unk_df4440<HaxeVector3>(fromcpp, "Vector3",
        "X", &HaxeVector3::X,
        "Y", &HaxeVector3::Y,
        "Z", &HaxeVector3::Z,
        "Create", &HaxeVector3::Create,
        "CreateAdd", &HaxeVector3::CreateAdd,
        "CreateSub", &HaxeVector3::CreateSub,
        "Dot", &HaxeVector3::Dot,
        "Cross", &HaxeVector3::Cross,
        "Add", &HaxeVector3::Add,
        "Sub", &HaxeVector3::Sub,
        "Mul", &HaxeVector3::Mul,
        "Normalize", &HaxeVector3::Normalize,
        "Length", &HaxeVector3::Length,
        "LengthSq", &HaxeVector3::LengthSq,
        "Clone", &HaxeVector3::Clone);
    Unk_df4440<HaxeFieldFunc>(fromcpp, "Field",
        "GetPlayerPos", &HaxeFieldFunc::GetPlayerPos,
        "GetPlayerRot", &HaxeFieldFunc::GetPlayerRot,
        "IsPlayerFingerWhistle", &HaxeFieldFunc::IsPlayerFingerWhistle,
        "IsPlayerSquat", &HaxeFieldFunc::IsPlayerSquat,
        "IsPlayerRegionIn", &HaxeFieldFunc::IsPlayerRegionIn,
        "GetWeather", &HaxeFieldFunc::GetWeather,
        "GetRandomInt", &HaxeFieldFunc::GetRandomInt,
        "GetRandomFloat", &HaxeFieldFunc::GetRandomFloat,
        "IsPlayerRideBicycle", &HaxeFieldFunc::IsPlayerRideBicycle,
        "IsPlayerRideBicycleType", &HaxeFieldFunc::IsPlayerRideBicycleType,
        "IsPlayerRideAndFingerWhistle", &HaxeFieldFunc::IsPlayerRideAndFingerWhistle);
    Unk_df4440<HaxeSymbolPokemonObject>(fromcpp, "PokemonObject",
        "SetPosition", &HaxeSymbolPokemonObject::SetPosition,
        "GetPosition", &HaxeSymbolPokemonObject::GetPosition,
        "SetRotation", &HaxeSymbolPokemonObject::SetRotation,
        "GetRotation", &HaxeSymbolPokemonObject::GetRotation,
        "SetScale", &HaxeSymbolPokemonObject::SetScale,
        "GetScale", &HaxeSymbolPokemonObject::GetScale,
        "SetVisible", &HaxeSymbolPokemonObject::SetVisible,
        "IsVisible", &HaxeSymbolPokemonObject::IsVisible,
        "GetUniqueHash", &HaxeSymbolPokemonObject::GetUniqueHash,
        "IsRecovery", &HaxeSymbolPokemonObject::IsRecovery,
        "RequestDelete", &HaxeSymbolPokemonObject::RequestDelete,
        "GetMonsNo", &HaxeSymbolPokemonObject::GetMonsNo,
        "GetFormNo", &HaxeSymbolPokemonObject::GetFormNo,
        "GetScriptName", &HaxeSymbolPokemonObject::GetScriptName,
        "GetReactionState", &HaxeSymbolPokemonObject::GetReactionState,
        "HasHearing", &HaxeSymbolPokemonObject::HasHearing,
        "HasHearingWhistle", &HaxeSymbolPokemonObject::HasHearingWhistle,
        "GetTurnSpeed", &HaxeSymbolPokemonObject::GetTurnSpeed,
        "GetRandomMoveFrameMin", &HaxeSymbolPokemonObject::GetRandomMoveFrameMin,
        "GetRandomMoveFrameMax", &HaxeSymbolPokemonObject::GetRandomMoveFrameMax,
        "GetWaitFrequency", &HaxeSymbolPokemonObject::GetWaitFrequency,
        "GetWaitFrameMin", &HaxeSymbolPokemonObject::GetWaitFrameMin,
        "GetWaitFrameMax", &HaxeSymbolPokemonObject::GetWaitFrameMax,
        "GetMotion1", &HaxeSymbolPokemonObject::GetMotion1,
        "GetMotion2", &HaxeSymbolPokemonObject::GetMotion2,
        "GetWatchOutRadius", &HaxeSymbolPokemonObject::GetWatchOutRadius,
        "GetWatchOutDistance", &HaxeSymbolPokemonObject::GetWatchOutDistance,
        "GetWatchOutAngle", &HaxeSymbolPokemonObject::GetWatchOutAngle,
        "IsWatchOutY", &HaxeSymbolPokemonObject::IsWatchOutY,
        "GetTouchCollision", &HaxeSymbolPokemonObject::GetTouchCollision,
        "GetEncountCollision", &HaxeSymbolPokemonObject::GetEncountCollision,
        "GetReactionParam0", &HaxeSymbolPokemonObject::GetReactionParam0,
        "GetReactionParam1", &HaxeSymbolPokemonObject::GetReactionParam1,
        "GetReactionParam2", &HaxeSymbolPokemonObject::GetReactionParam2,
        "GetReactionParam3", &HaxeSymbolPokemonObject::GetReactionParam3,
        "GetReactionTime", &HaxeSymbolPokemonObject::GetReactionTime,
        "GetSpecialLeave", &HaxeSymbolPokemonObject::GetSpecialLeave,
        "GetMoveType", &HaxeSymbolPokemonObject::GetMoveType,
        "GetWatchOutBicycleDistance", &HaxeSymbolPokemonObject::GetWatchOutBicycleDistance,
        "GetWatchOutBicycleRadius", &HaxeSymbolPokemonObject::GetWatchOutBicycleRadius,
        "GetEventCollisionDefaultOffset", &HaxeSymbolPokemonObject::GetEventCollisionDefaultOffset,
        "GetTouchCollisionDefaultOffset", &HaxeSymbolPokemonObject::GetTouchCollisionDefaultOffset,
        "IsGimmickSymbolPokemon", &HaxeSymbolPokemonObject::IsGimmickSymbolPokemon,
        "IsContainsCreateArea", &HaxeSymbolPokemonObject::IsContainsCreateArea,
        "IsContainsVanishArea", &HaxeSymbolPokemonObject::IsContainsVanishArea,
        "IsContainsMovementArea", &HaxeSymbolPokemonObject::IsContainsMovementArea,
        "IsContainsCreateAreaSelf", &HaxeSymbolPokemonObject::IsContainsCreateAreaSelf,
        "IsContainsVanishAreaSelf", &HaxeSymbolPokemonObject::IsContainsVanishAreaSelf,
        "IsContainsMovementAreaSelf", &HaxeSymbolPokemonObject::IsContainsMovementAreaSelf,
        "IsContainsCreateAreaPlayer", &HaxeSymbolPokemonObject::IsContainsCreateAreaPlayer,
        "IsContainsVanishAreaPlayer", &HaxeSymbolPokemonObject::IsContainsVanishAreaPlayer,
        "IsContainsMovementAreaPlayer", &HaxeSymbolPokemonObject::IsContainsMovementAreaPlayer,
        "GetSpawnerPos", &HaxeSymbolPokemonObject::GetSpawnerPos,
        "GetCreateAreaRandomPos", &HaxeSymbolPokemonObject::GetCreateAreaRandomPos,
        "GetVanishAreaRandomPos", &HaxeSymbolPokemonObject::GetVanishAreaRandomPos,
        "GetMovementAreaRandomPos", &HaxeSymbolPokemonObject::GetMovementAreaRandomPos,
        "GetSpawnerType", &HaxeSymbolPokemonObject::GetSpawnerType,
        "SetGimmickSpawnerVanishFlag", &HaxeSymbolPokemonObject::SetGimmickSpawnerVanishFlag,
        "GetGimmickSpawnerVanishFlag", &HaxeSymbolPokemonObject::GetGimmickSpawnerVanishFlag,
        "SetMotionState", &HaxeSymbolPokemonObject::SetMotionState,
        "GetMotionState", &HaxeSymbolPokemonObject::GetMotionState,
        "MoveStart", &HaxeSymbolPokemonObject::MoveStart,
        "MoveStop", &HaxeSymbolPokemonObject::MoveStop,
        "IsMoveEnd", &HaxeSymbolPokemonObject::IsMoveEnd,
        "SetMoveLimitFrame", &HaxeSymbolPokemonObject::SetMoveLimitFrame,
        "SetMoveLimitTurnY", &HaxeSymbolPokemonObject::SetMoveLimitTurnY,
        "MotionStart", &HaxeSymbolPokemonObject::MotionStart,
        "MotionEnd", &HaxeSymbolPokemonObject::MotionEnd,
        "IsMotionEnd", &HaxeSymbolPokemonObject::IsMotionEnd,
        "GetRotationToTarget", &HaxeSymbolPokemonObject::GetRotationToTarget,
        "GetRotationToTargetXY", &HaxeSymbolPokemonObject::GetRotationToTargetXY,
        "GetFrontVector", &HaxeSymbolPokemonObject::GetFrontVector,
        "SetCollisionOffset", &HaxeSymbolPokemonObject::SetCollisionOffset,
        "GetCollisionOffset", &HaxeSymbolPokemonObject::GetCollisionOffset,
        "SetEventCollisionOffset", &HaxeSymbolPokemonObject::SetEventCollisionOffset,
        "GetEventCollisionOffset", &HaxeSymbolPokemonObject::GetEventCollisionOffset,
        "SetCollisionR", &HaxeSymbolPokemonObject::SetCollisionR,
        "GetCollisionR", &HaxeSymbolPokemonObject::GetCollisionR,
        "SetEventCollisionR", &HaxeSymbolPokemonObject::SetEventCollisionR,
        "GetEventCollisionR", &HaxeSymbolPokemonObject::GetEventCollisionR,
        "IsWallHit", &HaxeSymbolPokemonObject::IsWallHit,
        "RaycastWallNormal", &HaxeSymbolPokemonObject::RaycastWallNormal,
        "RaycastObject", &HaxeSymbolPokemonObject::RaycastObject,
        "SetEnableGroundRaycast", &HaxeSymbolPokemonObject::SetEnableGroundRaycast,
        "GetEnableGroundRaycast", &HaxeSymbolPokemonObject::GetEnableGroundRaycast,
        "StartBalloonEffect", &HaxeSymbolPokemonObject::StartBalloonEffect,
        "GetBattleType", &HaxeSymbolPokemonObject::GetBattleType,
        "GetPopType", &HaxeSymbolPokemonObject::GetPopType,
        "StartPopEffect", &HaxeSymbolPokemonObject::StartPopEffect,
        "StartEffect1", &HaxeSymbolPokemonObject::StartEffect1,
        "StartEffect2", &HaxeSymbolPokemonObject::StartEffect2,
        "PlaySe", &HaxeSymbolPokemonObject::PlaySe,
        "PlayVoice", &HaxeSymbolPokemonObject::PlayVoice,
        "SetBackupScriptState", &HaxeSymbolPokemonObject::SetBackupScriptState,
        "GetBackupScriptState", &HaxeSymbolPokemonObject::GetBackupScriptState);
    sol::table log = fromcpp.create_with("Print", Unk_df22c0, "Assert", Unk_df22d0, "AssertMsg", Unk_df22e0);
    fromcpp.set("Log", log);
    fromcpp.new_enum("WeatherType",
        "SUNNY", 0,
        "CLOUDY", 1,
        "RAIN", 2,
        "STORM", 3,
        "SNOW", 4,
        "SNOWSTORM", 5,
        "SUNSHINE", 6,
        "SANDSTORM", 7,
        "MIST", 8);
    fromcpp.new_enum("SpawnerType",
        "GROUND", 0u,
        "SKY", 1u,
        "WATER", 2u,
        "ANY_GROUMD", 3u);
    fromcpp.new_enum("RaycastTarget",
        "CHARA", Unk_1f25c58,
        "POKEMON", Unk_1f25c5c,
        "ALL", Unk_1f25c60);
    fromcpp.new_enum("BalloonType",
        "EXCLAMATION", 0u,
        "QUESTION", 1u,
        "EXCLAMATION_2", 2u,
        "SILENCE", 3u,
        "SYMBOL_EXCLAMATION", 8u,
        "SYMBOL_SWEAT", 9u);
    fromcpp.new_enum("SeType",
        "POP", 0u,
        "LEAVE", 1u,
        "WILD_POP", 2u,
        "WILD_SHAKE", 3u);
    fromcpp.new_enum("BattleType",
        "NONE", 0u,
        "GRASS", 1u,
        "WATER", 2u);
    fromcpp.new_enum("PopType",
        "NONE", 0u,
        "GRASS", 1u,
        "DEAD_GRASS", 2u,
        "WATER", 3u,
        "SNOW", 4u,
        "ICE", 5u,
        "SAND", 6u);
    fromcpp.new_enum("MotionState",
        "BATTLE", 1u,
        "CAMP", 2u,
        "FIELD", 3u);
    fromcpp.new_enum("MotionType",
        "BATTLE_LAND_1", 0u,
        "BATTLE_LAND_2", 1u,
        "BATTLE_MEGA_APPEAL", 2u,
        "BATTLE_ROAR", 3u,
        "BATTLE_WAIT", 4u,
        "BATTLE_WAIT_ACTION", 5u,
        "BATTLE_BUTURI_1", 6u,
        "BATTLE_BUTURI_2", 7u,
        "BATTLE_BUTURI_3", 8u,
        "BATTLE_BUTURI_4", 9u,
        "BATTLE_TOKUSYU_1", 10u,
        "BATTLE_TOKUSYU_2", 11u,
        "BATTLE_TOKUSYU_3", 12u,
        "BATTLE_TOKUSYU_4", 13u,
        "BATTLE_DAMAGE", 14u,
        "BATTLE_DOWN", 15u,
        "BATTLE_WIDE_USE_1", 16u,
        "BATTLE_WIDE_USE_2", 17u,
        "BATTLE_WIDE_USE_3", 18u,
        "CAMP_WAIT", 19u,
        "CAMP_RESPOND", 20u,
        "CAMP_TURN_A", 21u,
        "CAMP_TURN_B", 22u,
        "CAMP_SLEEP_A", 23u,
        "CAMP_SLEEP_B", 24u,
        "CAMP_HATE", 25u,
        "CAMP_QUESTION", 26u,
        "CAMP_HAPPY_A", 27u,
        "CAMP_HAPPY_B", 28u,
        "CAMP_HAPPY_C", 29u,
        "CAMP_ACTION_A", 30u,
        "CAMP_ACTION_B", 31u,
        "CAMP_ACTION_C", 32u,
        "CAMP_ACTION_D", 33u,
        "CAMP_LONELY", 34u,
        "CAMP_PLAY_A", 35u,
        "CAMP_PLAY_B", 36u,
        "CAMP_ATTACK", 37u,
        "CAMP_TOUCH", 38u);
    fromcpp.new_enum("RideType",
        "NORMAL", 0u,
        "BICYCLE_GROUND", 1u,
        "BICYCLE_WATER", 2u,
        "TEACUP", 3u);
    // clang-format on
}
