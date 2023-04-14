#include "Minecraft/World/BlockPos.h"

#include "Minecraft/Util/Facing.h"
#include "Minecraft/Util/Vec3.h"

BlockPos::BlockPos(Vec3 const& v) : BlockPos(v.x, v.y, v.z) {}

BlockPos BlockPos::neighbor(FacingID direction) const {
	return *this + Facing::DIRECTION[direction];
}
