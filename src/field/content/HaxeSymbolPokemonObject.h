#pragma once
// field::content::HaxeSymbolPokemonObject: the symbol-encounter Pokemon object that
// symbol_encount's ai.blua script drives, bound to Lua as fromcpp.PokemonObject. Class
// and namespace come from sol2's type-name strings (ctti_get_type_name); the members
// and their signatures from the bound member-pointer types in the same strings, in
// registration order; the names are the Lua keys they are bound under.
#include <types.h>

#include "field/content/HaxeVector3.h"

namespace field {
namespace content {

class HaxeSymbolPokemonObject {
public:
    // 0x7100deb970 (memsets the 0x10c bytes of data)
    HaxeSymbolPokemonObject();

    void SetPosition(HaxeVector3);
    HaxeVector3 GetPosition() const;
    void SetRotation(HaxeVector3);
    HaxeVector3 GetRotation() const;
    void SetScale(HaxeVector3) const;
    HaxeVector3 GetScale() const;
    void SetVisible(bool);
    bool IsVisible() const;
    const char* GetUniqueHash() const;
    bool IsRecovery() const;
    void RequestDelete();
    int GetMonsNo() const;
    int GetFormNo() const;
    const char* GetScriptName() const;
    int GetReactionState() const;
    bool HasHearing() const;
    bool HasHearingWhistle() const;
    float GetTurnSpeed() const;
    int GetRandomMoveFrameMin() const;
    int GetRandomMoveFrameMax() const;
    int GetWaitFrequency() const;
    int GetWaitFrameMin() const;
    int GetWaitFrameMax() const;
    int GetMotion1() const;
    int GetMotion2() const;
    float GetWatchOutRadius() const;
    float GetWatchOutDistance() const;
    float GetWatchOutAngle() const;
    bool IsWatchOutY() const;
    float GetTouchCollision() const;
    float GetEncountCollision() const;
    float GetReactionParam0() const;
    float GetReactionParam1() const;
    float GetReactionParam2() const;
    float GetReactionParam3() const;
    float GetReactionTime() const;
    const char* GetSpecialLeave() const;
    const char* GetMoveType() const;
    float GetWatchOutBicycleDistance() const;
    float GetWatchOutBicycleRadius() const;
    HaxeVector3 GetEventCollisionDefaultOffset() const;
    HaxeVector3 GetTouchCollisionDefaultOffset() const;
    bool IsGimmickSymbolPokemon() const;
    bool IsContainsCreateArea(HaxeVector3) const;
    bool IsContainsVanishArea(HaxeVector3) const;
    bool IsContainsMovementArea(HaxeVector3) const;
    bool IsContainsCreateAreaSelf() const;
    bool IsContainsVanishAreaSelf() const;
    bool IsContainsMovementAreaSelf() const;
    bool IsContainsCreateAreaPlayer() const;
    bool IsContainsVanishAreaPlayer() const;
    bool IsContainsMovementAreaPlayer() const;
    HaxeVector3 GetSpawnerPos() const;
    HaxeVector3 GetCreateAreaRandomPos() const;
    HaxeVector3 GetVanishAreaRandomPos() const;
    HaxeVector3 GetMovementAreaRandomPos() const;
    int GetSpawnerType() const;
    void SetGimmickSpawnerVanishFlag(bool);
    bool GetGimmickSpawnerVanishFlag() const;
    void SetMotionState(int);
    int GetMotionState() const;
    void MoveStart(HaxeVector3, int);
    void MoveStop();
    bool IsMoveEnd() const;
    void SetMoveLimitFrame(int);
    void SetMoveLimitTurnY(float);
    void MotionStart(int);
    void MotionEnd();
    bool IsMotionEnd() const;
    float GetRotationToTarget(HaxeVector3) const;
    HaxeVector3 GetRotationToTargetXY(HaxeVector3) const;
    HaxeVector3 GetFrontVector() const;
    void SetCollisionOffset(HaxeVector3);
    HaxeVector3 GetCollisionOffset() const;
    void SetEventCollisionOffset(HaxeVector3);
    HaxeVector3 GetEventCollisionOffset() const;
    void SetCollisionR(float);
    float GetCollisionR() const;
    void SetEventCollisionR(float);
    float GetEventCollisionR() const;
    bool IsWallHit() const;
    HaxeVector3 RaycastWallNormal(HaxeVector3, HaxeVector3) const;
    bool RaycastObject(HaxeVector3, HaxeVector3, unsigned int) const;
    void SetEnableGroundRaycast(bool);
    bool GetEnableGroundRaycast() const;
    void StartBalloonEffect(int);
    int GetBattleType() const;
    int GetPopType() const;
    void StartPopEffect();
    void StartEffect1();
    void StartEffect2();
    void PlaySe(int);
    int PlayVoice(int) const;
    void SetBackupScriptState(int);
    int GetBackupScriptState() const;

    // Data: 0x7100dee870 copies 0x110 bytes from 0xc18 of its owner into a local
    // object for the script call, and the constructor zeroes 0x10c of them.
    void* field_0;
    char field_8[0x41];
    char field_49[0x41];
    char field_8a[0x41];
    char field_cb[0x41];
};
PKMN_OFFSET_ASSERT(HaxeSymbolPokemonObject, field_8, 0x8);
PKMN_OFFSET_ASSERT(HaxeSymbolPokemonObject, field_49, 0x49);
PKMN_OFFSET_ASSERT(HaxeSymbolPokemonObject, field_8a, 0x8a);
PKMN_OFFSET_ASSERT(HaxeSymbolPokemonObject, field_cb, 0xcb);
PKMN_SIZE_ASSERT(HaxeSymbolPokemonObject, 0x110);

}  // namespace content
}  // namespace field
