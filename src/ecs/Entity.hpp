//
// Created by Cody on 10/16/2019.
//

#include <vector>
#include <memory>
#include <bitset>
#include <algorithm>
#include <array>

#ifndef REIKI_ENTITY_H
#define REIKI_ENTITY_H

#include "Component.hpp"
#include "../math/math.hpp"

namespace Reiki::ECS {
    using EntityId = std::size_t;

    constexpr std::size_t maxComponents = 32;

    using ComponentBitSet = std::bitset<maxComponents>;
    using ComponentArray = std::array<Component*, maxComponents>;
    using ComponentPtrArray = std::array<std::unique_ptr<Component>, maxComponents>;


    class Entity {
        friend class EntityManager;
    private:
        EntityId id;
        bool active = true;

        std::vector<std::unique_ptr<Component>> components; // Component pointers

        ComponentArray componentArray{}; // Components indexed by typeId
        ComponentBitSet componentBitSet; // Quick True/False lookup for if has component;
    public:
        EntityId getId() const { return id; }

        virtual void update(float ms) {};
        virtual void draw(const math::mat3& projection) {};
        virtual void destroy() { active = false; };

        bool isActive() const { return active; };

        template <typename T> bool hasComponent() const {
            return componentBitSet[getComponentTypeId<T>()];
        };

        template <typename T, typename... TArgs> T* addComponent(TArgs&&... mArgs) {
            T* component(new T(std::forward<TArgs>(mArgs)...));
            component->entity = this;
            std::unique_ptr<Component> uPtr{ component };
            components.emplace_back((std::move(uPtr)));

            componentArray[getComponentTypeId<T>()] = component;
            componentBitSet[getComponentTypeId<T>()] = true;

            component->init();

            return component;
        };

        template<typename T> T* getComponent() const {
            auto ptr(componentArray[getComponentTypeId<T>()]);
            return static_cast<T*>(ptr);
        };
    };
}

#endif //REIKI_ENTITY_H
