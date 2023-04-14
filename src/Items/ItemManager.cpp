#include "ItemManager.h"
#include "Minecraft/Item/Item.h"

bool ItemManager::InitializedClientData = false;
WeakPtr<OxygenTank> ItemManager::oxygenTankItem;

void ItemManager::Initialize() {
	oxygenTankItem = ItemRegistry::registerItem<OxygenTank>("oxygen_tank", ItemRegistry::getMaxItemID());
}

void ItemManager::Deinitialize() {
	InitializedClientData = false;
}

void ItemManager::InitializeCreative() {
	Item::beginCreativeGroup("itemGroup.name.oxygen_tank", oxygenTankItem.get(), 0, nullptr);
	Item::addCreativeItem(oxygenTankItem.get(), 0);
	Item::endCreativeGroup();
}

void ItemManager::InitializeTextures() {
	InitializedClientData = true;
	oxygenTankItem->setIcon("oxygen_tank", 0);
}