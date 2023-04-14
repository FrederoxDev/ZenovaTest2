#include "Zenova.h"
#include "generated/initcpp.h"
#include "Minecraft/Item/VanillaItems.h"
#include "hooks.h"

MOD_FUNCTION void ModStart() {
	Zenova_Hook(VanillaItems::registerItems, &Hooks::RegisterItemsHook, &Hooks::RegisterItemsTrampoline);
	Zenova_Hook(VanillaItems::initCreativeItemsCallback, &Hooks::InitializeCreativeItemsHook, &Hooks::InitializeCreativeItemsTrampoline);
	Zenova_Hook(VanillaItems::initClientData, &Hooks::InitializeClientHook, &Hooks::InitializeClientTrampoline);
}