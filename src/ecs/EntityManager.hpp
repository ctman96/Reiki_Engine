//
// Created by Cody on 10/16/2019.
//

#ifndef REIKI_ENTITYMANAGER_HPP
#define REIKI_ENTITYMANAGER_HPP

#include <unordered_map>
#include "Entity.hpp"
#include "../math/math.hpp"

namespace Reiki::ECS {
    class EntityManager {
    private:
        EntityId idCounter;
        std::unordered_map<EntityId, std::unique_ptr<Entity>> entities;

    public:
        void update(float ms);
        void draw(const math::mat3& projection);

        template <typename T, typename... TArgs> T& addEntity();

        template <typename T> T& getEntity(EntityId id) { return *(entities[id]); }

        void removeEntity(EntityId id) { entities.erase(id); }

        // TODO getter to just get ones with specific components?
        std::unordered_map<EntityId, std::unique_ptr<Entity>> * getEntities() { return &entities; }

        void clear() { entities.clear(); }
    };
}

#endif //REIKI_ENTITYMANAGER_HPP
