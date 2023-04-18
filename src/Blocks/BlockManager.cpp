#include "BlockManager.h"
#include "Minecraft/Block/BlockRegistry.h"
#include "Minecraft/Item/ItemRegistry.h"
#include "Minecraft/Item/BlockItem.h"
#include "Minecraft/Item/Item.h"
#include "Zenova.h"

void BlockManager::Initialize() {
	baseController = BlockRegistry::registerBlock<BaseController>("cosmos:base_controller", BlockShape::BLOCK);
}

void BlockManager::InitializeBlockItems() {
	ItemRegistry::registerBlockItem<BlockItem>(baseController->get()->getDescriptionId(), *baseController->get());
}

void BlockManager::InitializeCreativeBlocks() {
	Item::beginCreativeGroup("itemGroup.name.base_controller", &baseController->get()->getDefaultState(), nullptr);
	Item::addCreativeItem(baseController->get()->getDefaultState());
	Item::endCreativeGroup();
}