#include "OxygenTank.h"

OxygenTank::OxygenTank(const std::string& name, short id) : Item(name, id), textureItem() {
	setMaxStackSize(1);
	setCategory(CreativeItemCategory::ITEMS);
}