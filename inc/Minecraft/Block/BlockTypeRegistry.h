#pragma once

#include <string>
#include <unordered_map>

#include "Minecraft/Util/Util.h"
#include "Minecraft/Util/SharedPtr.h"

class BlockLegacy;

class BlockTypeRegistry {
public:
    static std::unordered_map<std::string, SharedPtr<BlockLegacy>>& mBlockLookupMap;

    template<typename T, typename... Args>
    static T& registerBlock(Args&&... args) {
        SharedPtr<T> blockReg = SharedPtr<T>::make(std::forward<Args>(args)...);
        mBlockLookupMap[Util::toLower(blockReg->getRawNameId())] = blockReg;
        return *blockReg;
    }
    static WeakPtr<BlockLegacy> lookupByName(const std::string&);
};

namespace BedrockBlockTypes {
	extern WeakPtr<BlockLegacy>& mAir;
}