#include "Items/ItemManager.h"

class ActorInfoRegistry;
class BlockDefinitionGroup;

class Hooks {
public:
	inline static void (*RegisterItemsTrampoline)(bool flag);
	static void RegisterItemsHook(bool flag) {
		RegisterItemsTrampoline(flag);
		ItemManager::Initialize();
	}

	inline static void (*InitializeCreativeItemsTrampoline)(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
	static void InitializeCreativeItemsHook(class ActorInfoRegistry* actorInfoRegistry, class BlockDefinitionGroup* blockDefinitionGroup, bool flag) {
		InitializeCreativeItemsTrampoline(actorInfoRegistry, blockDefinitionGroup, flag);
		ItemManager::InitializeCreative();
	}

	inline static void (*InitializeClientTrampoline)();
	static void InitializeClientHook() {
		InitializeClientTrampoline();
		ItemManager::InitializeTextures();
	}
};