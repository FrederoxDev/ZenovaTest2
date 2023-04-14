#pragma once
#include "Minecraft/Item/Item.h"
#include "Minecraft/Client/TextureAtlasItem.h"

class OxygenTank : public Item {
private:
	TextureAtlasItem textureItem;

public:
	OxygenTank(const std::string&, short);
};