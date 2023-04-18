#pragma once
#include <string>
#include "Minecraft/Util/SharedPtr.h"
#include "Minecraft/Util/Vec3.h"
#include "Minecraft/World/BlockPos.h"
#include "Minecraft/Util/CompoundTag.h"
#include "Minecraft/World/LevelListener.h"
#include "Minecraft/World/SavedData.h"

class Level;
class Scheduler;
class Actor;
class ActorUniqueID;
class Player;
struct ActorBlockSyncMessage;
class LevelChunk;
class Packet;
class LimboEntitiesVersion;

template <typename Dimension, typename T>
class AutomaticID;

class Dimension : LevelListener, SavedData {
public:
    virtual void deserialize(CompoundTag&);
    Dimension(Level&, AutomaticID<Dimension, int>, short, Scheduler&, std::string);
    float distanceToNearestPlayerSqr2D(Vec3);
    Actor fetchEntity(ActorUniqueID, bool);
    Player* fetchNearestAttackablePlayer(BlockPos, float, Actor&);
    Player* fetchNearestAttackablePlayer(Actor&, float);
    Player* fetchNearestPlayer(Actor&, float);
    Player* fetchNearestPlayer(float, float, float, float);
    Player* findPlayer(std::function<bool(const Player&)>);
    void forEachPlayer(std::function<bool(Player&)>);
    virtual float getClearColorScale();
    virtual float getCloudHeight();
    virtual Color getFogColor(float);
    virtual float getMaxFogStart();
    float getMoonBrightness();
    int getMoonPhase();
    virtual float getSunIntensity(float, Vec3&, float);
    float getTimeOfDay(float);
    virtual void init();
    virtual bool isDay();
    virtual void onBlockChanged(BlockSource&, BlockPos&, unsigned int, Block&, Block&, int, ActorBlockSyncMessage);
    virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
    virtual void onChunkLoaded(LevelChunk&);
    virtual void onLevelDestruction(std::string&);
    virtual void onNewChunk(BlockSource&, LevelChunk&);
    virtual void sendBroadcast(Packet&, Player&);
    void sendPacketForEntity(Actor&, Packet&, Player&);
    void sendPacketForPosition(BlockPos&, Packet&, Player&);
    virtual void serialize(CompoundTag&);
    virtual void tick();
    virtual void tickRedstone();
    virtual void transferEntity(Vec3&, UniquePtr<CompoundTag, std::default_delete<CompoundTag>>);
    void transferEntityToUnloadedChunk(Vec3&, UniquePtr<CompoundTag, std::default_delete<CompoundTag>>);
    void tryGarbageCollectStructures();
    virtual void updateLightRamp();
    virtual ~Dimension();

private:
    void upgradeOldLimboEntity(CompoundTag&, LimboEntitiesVersion);

protected:
    virtual float getTimeOfDay(int, float);
};