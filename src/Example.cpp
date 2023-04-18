#include "Zenova.h"
#include "generated/initcpp.h"
#include "Minecraft/Item/VanillaItems.h"
#include "Minecraft/World/Dimension.h"
#include "hooks.h"
#include "Minecraft/World/VanillaDimensionFactory.h"
#include "Minecraft/World/Level.h"
#include "Minecraft/Minecraft.h"


MOD_FUNCTION void ModStart() {
	Zenova_Hook(VanillaItems::registerItems, &Hooks::RegisterItemsHook, &Hooks::RegisterItemsTrampoline);
	Zenova_Hook(VanillaItems::initCreativeItemsCallback, &Hooks::InitializeCreativeItemsHook, &Hooks::InitializeCreativeItemsTrampoline);
	Zenova_Hook(VanillaItems::initClientData, &Hooks::InitializeClientHook, &Hooks::InitializeClientTrampoline);
	Zenova_Hook(BlockDefinitionGroup::registerBlocks, &Hooks::RegisterBlocksHook, &Hooks::RegisterBlocksTrampoline);
	Zenova_Hook(Minecraft::getLevel, &Hooks::TestHook, &Hooks::TestTrampoline);

	BlockManager::Initialize();
}