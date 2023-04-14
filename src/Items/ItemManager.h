#pragma once

#include "ItemInclude.h"
#include "Minecraft/Util/SharedPtr.h"
#include "Minecraft/Item/ItemRegistry.h"
#include <string>

class ItemManager {
public:
	static bool InitializedClientData;
	static WeakPtr<OxygenTank> oxygenTankItem;

	static void Initialize();
	static void Deinitialize();
	static void InitializeCreative();
	static void InitializeTextures();
};