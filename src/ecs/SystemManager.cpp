//
// Created by Cody on 11/1/2019.
//

#include "SystemManager.hpp"

namespace Reiki::ECS {

    void SystemManager::update(float ms) {
        for (auto & s : systems) s->update(ms);
        refresh();
    }

    // https://en.cppreference.com/w/cpp/algorithm/remove
    void SystemManager::refresh() {
        // This erases from the entities vector based on which entities are not active
        // see remove_if docs for more details, but it basically just shifts all
        // inactive elements end of the vector, and returns an iterator which erase uses.
        systems.erase(std::remove_if(systems.begin(), systems.end(), [this](const std::unique_ptr<System> &system) {
            if (!system->isActive()){
                systemBitSet[system->id] = false;
            }
            return !system->isActive();
        }), systems.end());
    }

    template<typename T>
    bool SystemManager::hasSystem() const {
        return systemBitSet[getSystemTypeId<T>()];
    }

    template<typename T>
    T &SystemManager::getSystem() {
        if (hasSystem<T>()) {
            auto ptr(systemArray[getSystemTypeId<T>()]);
            return static_cast<T *>(ptr);
        } else return addSystem<T>(); // TODO?
    }

    template<typename T, typename... TArgs>
    T &SystemManager::addSystem(TArgs &&... mArgs) {
        if (!hasSystem<T>()){
            T *system(new T(std::forward<TArgs>(mArgs)...));
            SystemId id = getSystemTypeId<T>();
            system->id = id;
            std::unique_ptr<System> uPtr{system};
            systems.emplace_back((std::move(uPtr)));

            systemArray[id] = system;
            systemBitSet[id] = true;

            return *system;
        } else return getSystem<T>();
    }

    void SystemManager::reset() {
        systems.clear();
        systemBitSet.reset();
    }
}
