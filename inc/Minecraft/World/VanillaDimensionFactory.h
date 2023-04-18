#pragma once
#include "Minecraft/World/Dimension.h"
#include "Minecraft/Util/SharedPtr.h"

class Level;
class Scheduler;

template <typename Dimension, typename Level, typename Scheduler>
class Factory {
public:
    UniquePtr<Dimension, std::default_delete<Dimension>> create(std::string, Level&, Scheduler&);
    void registerFactory(std::string, std::function<UniquePtr<Dimension, std::default_delete<Dimension>>>);
};

class VanillaDimensionFactory {
private:
    void registerDimensionTypes(Factory<Dimension, Level&, Scheduler&>);
};