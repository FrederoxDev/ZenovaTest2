#pragma once
#include "Minecraft/World/BlockSource.h"
#include "Minecraft/World/BlockPos.h"

class BlockSourceListener {
public:
    virtual void onBrightnessChanged(BlockSource&, const BlockPos&);
    virtual ~BlockSourceListener();
};