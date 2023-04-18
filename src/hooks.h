#include "Items/ItemManager.h"
#include "Blocks/BlockManager.h"
#include "Minecraft/World/VanillaDimensionFactory.h"
#include "Zenova.h"
#include <vector>

class ActorInfoRegistry;
class BlockDefinitionGroup;

template <typename Dimension, typename T>
class AutomaticID;

class Hooks {
public:
	inline static void (*RegisterItemsTrampoline)(bool flag);
	static void RegisterItemsHook(bool flag) {
		RegisterItemsTrampoline(flag);
		ItemManager::Initialize();
		BlockManager::InitializeBlockItems();
	}

	inline static void (*InitializeCreativeItemsTrampoline)(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
	static void InitializeCreativeItemsHook(class ActorInfoRegistry* actorInfoRegistry, class BlockDefinitionGroup* blockDefinitionGroup, bool flag) {
		InitializeCreativeItemsTrampoline(actorInfoRegistry, blockDefinitionGroup, flag);
		ItemManager::InitializeCreative();
		BlockManager::InitializeCreativeBlocks();
	}

	inline static void (*InitializeClientTrampoline)();
	static void InitializeClientHook() {
		InitializeClientTrampoline();
		ItemManager::InitializeTextures();
	}

	inline static void (*RegisterBlocksTrampoline)(BlockDefinitionGroup*);
	static void RegisterBlocksHook(BlockDefinitionGroup* defGroup) {
		for (auto block : BlockRegistry::BlockRegistryList)
			block->initBlock(defGroup);

		RegisterBlocksTrampoline(defGroup);
	}

	inline static void* (*TestTrampoline)();
	static void TestHook() {
		Zenova_Info("Hello!");
		TestTrampoline();
	}
};