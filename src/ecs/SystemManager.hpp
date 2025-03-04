//
// Created by Cody on 10/16/2019.
//

#ifndef REIKI_SYSTEMMANAGER_HPP
#define REIKI_SYSTEMMANAGER_HPP

#include <cstddef>
#include <bitset>
#include <algorithm>
#include <memory>
#include <array>
#include <vector>
#include "System.hpp"

namespace Reiki::ECS {
    constexpr std::size_t maxSystems = 32;

    using SystemBitSet = std::bitset<maxSystems>;
    using SystemArray = std::array<System*, maxSystems>;



    class SystemManager {
    private:
        std::vector<std::unique_ptr<System>> systems;

        SystemArray systemArray; // Systems indexed by typeId
        SystemBitSet systemBitSet; // Quick True/False lookup for if has system;

    public:
        void update(float ms);

        void refresh();

        template <typename T> bool hasSystem() const {
            return systemBitSet[getSystemTypeId<T>()];
        };

        template<typename T> T& getSystem() {
            if (hasSystem<T>()) {
                auto ptr(systemArray[getSystemTypeId<T>()]);
                return *static_cast<T *>(ptr);
            } else return addSystem<T>(); // TODO?
        };

        template <typename T, typename... TArgs> T& addSystem(TArgs&&... mArgs) {
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
        };

        void reset();
    };
}

#endif //REIKI_SYSTEMMANAGER_HPP
