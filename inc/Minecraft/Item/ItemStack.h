#pragma once

#include <chrono>

#include "Minecraft/Item/Item.h"
#include "Minecraft/Block/Block.h"
#include "Minecraft/Util/CompoundTag.h"

class Tick { uint64_t tickID; };

struct SortItemInstanceIdAux {
	bool operator()(const ItemInstance&, const ItemInstance&) const;
};

class ItemStackBase {
protected:
	WeakPtr<Item> mItem;
public:
	std::unique_ptr<CompoundTag> mUserData;
protected:
	const Block* mBlock;
	short mAuxValue;
	byte mCount;
	bool mValid;
	std::chrono::steady_clock::time_point mPickupTime;
	static const std::chrono::milliseconds sPickupPopDuration;
	bool mShowPickUp;
	std::vector<BlockLegacy const*> mCanPlaceOn;
	size_t mCanPlaceOnHash;
	std::vector<BlockLegacy const*> mCanDestroy;
	size_t mCanDestroyHash;
	Tick mBlockingTick;
private:
	std::unique_ptr<ItemInstance> mChargedItem;

public:
	virtual ~ItemStackBase();
	virtual void reinit(const BlockLegacy&, int) = 0;

protected:
	ItemStackBase();
	ItemStackBase(const BlockLegacy&, int);
	ItemStackBase(const Block&, int, const CompoundTag*);
	ItemStackBase(const Item&, int, int);
	ItemStackBase(const ItemStackBase&);
	ItemStackBase& operator=(const ItemStackBase&);
	virtual void reinit(const Item&, int, int) = 0;

public:
	bool isItem() const {
		return mItem != nullptr;
	}
	void add(const int inCount) {
		set(mCount + inCount);
	}
	void remove(const int inCount) {
		set(mCount - inCount);
	}
	void set(const int);
	bool hasUserData() const {
		return mUserData != nullptr;
	}
	const Item* getItem() const;
	const Block* getBlock() const {
		return mBlock;
	}
	short getAuxValue() const;
	byte getStackSize() const {
		return mCount;
	}
	bool isEmptyStack() const {
		return mCount == 0;
	}
	bool isInstance(const Item& i) const {
		return &i == mItem.get();
	}
	bool matchesItem(const ItemStackBase&) const;
	const std::unique_ptr<CompoundTag>& getUserData() const {
		return mUserData;
	}
	short ItemStackBase::getDamageValue() const {
		return (isItem()) ? getItem()->getDamageValue(getUserData()) : 0;
	}
	void ItemStackBase::setDamageValue(short newDamage) {
		if (isItem()) {
			getItem()->setDamageValue(*this, newDamage);
		}
	}
};

class ItemStack : public ItemStackBase {
public:
	ItemStack();
	ItemStack(const BlockLegacy&, int);
	ItemStack(const Item&, int);
	ItemStack(const Item& item, int count, int aux) : ItemStackBase(item, count, aux) {}

	virtual void reinit(const BlockLegacy&, int);
	virtual void reinit(const Item&, int, int);
	void init(const Item&, int, int, const CompoundTag*);
};

class ItemInstance : public ItemStackBase {
public:
	ItemInstance();
	ItemInstance(const BlockLegacy&, int);
	ItemInstance(const Block&, int, const CompoundTag*);
	ItemInstance(const Item&, int, int);
	ItemInstance(const ItemInstance&);
	ItemInstance(const ItemStack& stack) : ItemStackBase(stack) {}

	ItemInstance clone() const { return ItemInstance(*this); }

	virtual void reinit(const BlockLegacy&, int);
	virtual void reinit(const Item&, int, int);
};