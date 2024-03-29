#pragma once

#include <vector>
#include <string>

#include "Minecraft/Util/SharedPtr.h"
#include "Minecraft/Block/Block.h"
#include "Minecraft/Item/Item.h"

class ItemRegistry {
public:
	template<typename T, typename... Args>
	static WeakPtr<T> registerItem(const std::string& name, short id, Args&&... args) {
		return ItemRegistry::registerItemShared<T>(name, id + 256, std::forward<Args>(args)...);
	}

	template<typename T, typename... Args>
	static WeakPtr<T> registerBlockItem(const std::string& name, const BlockLegacy& block, Args&&... args) {
		return ItemRegistry::registerItemShared<T>(name, block.getBlockItemId(), std::forward<Args>(args)...);
	}

	template<typename T, typename... Args>
	static WeakPtr<T> registerBlockItem(const std::string& name, const Block& block, Args&&... args) {
		return ItemRegistry::registerItemShared<T>(name, block.getLegacyBlock().getBlockItemId(), std::forward<Args>(args)...);
	}

	template<typename T, typename... Args>
	static WeakPtr<T> registerItemShared(Args&&... args) {
		SharedPtr<T> itemReg = SharedPtr<T>::make(std::forward<Args>(args)...);
		ItemRegistry::registerItem(itemReg);
		return itemReg;
	}

	static void registerItem(SharedPtr<Item>);
	static void shutdown();
	

	static WeakPtr<Item> lookupByName(int&, int&, const std::string&);
	static WeakPtr<Item> lookupByName(int&, const std::string&);
	static WeakPtr<Item> lookupByName(const std::string& inString) {
		int itemAux;
		return lookupByName(itemAux, inString);
	}
	static WeakPtr<Item> getItem(const short);
	static WeakPtr<Item> getItem(const Block& block) {
		return getItem(block.getLegacyBlock());
	}
	static WeakPtr<Item> getItem(const BlockLegacy& blockLegacy) {
		return getItem(blockLegacy.getBlockItemId());
	}
	static short getMaxItemID() {
		return mMaxItemID;
	}

	static short& mMaxItemID;
	static std::vector<SharedPtr<Item>>& mItemRegistry;
};