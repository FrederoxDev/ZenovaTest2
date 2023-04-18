#include "BaseController.h"

BaseController::BaseController(const std::string& name, int id) : BlockLegacy(name, id, Material::getMaterial(MaterialType::Metal)) {
	setSolid(true);
	setCategory(CreativeItemCategory::BLOCKS);
}