//
// Created by Cody on 11/1/2019.
//

#include "Entity.hpp"

namespace Reiki::ECS {

    template<typename T>
    bool Entity::hasComponent() const  {
        return componentBitSet[getComponentTypeId<T>()];
    }


    template<typename T, typename... TArgs>
    T *Entity::addComponent(TArgs &&... mArgs)  {
        T* component(new T(std::forward<TArgs>(mArgs)...));
        component->entity = this;
        std::unique_ptr<Component> uPtr{ component };
        components.emplace_back((std::move(uPtr)));

        componentArray[getComponentTypeId<T>()] = component;
        componentBitSet[getComponentTypeId<T>()] = true;

        component->init();

        return component;
    }


    template<typename T>
    T *Entity::getComponent() const {
        auto ptr(componentArray[getComponentTypeId<T>()]);
        return static_cast<T*>(ptr);
    }
}