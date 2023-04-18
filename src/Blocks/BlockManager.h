#pragma once
#include "BlockInclude.h"
#include "Minecraft/Util/SharedPtr.h"
#include "Minecraft/Block/BlockRegistry.h"

class BlockManager {
public:
	inline static WeakPtr<BlockLegacy>* baseController;

	static void Initialize();
	static void InitializeBlockItems();
	static void InitializeCreativeBlocks();
};