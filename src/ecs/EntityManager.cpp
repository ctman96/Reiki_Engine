//
// Created by Cody on 11/1/2019.
//


#include "EntityManager.hpp"

namespace Reiki::ECS {
    void EntityManager::update(float ms) {
        {
            auto it = entities.begin();
            while (it != entities.end()) {
                if (!it->second->isActive())
                    it = entities.erase(it);
                else
                    it++;
            }
        }
    }

//    void EntityManager::draw(const math::mat3 &projection) {
//        for (auto & e : entities) e.second->draw(projection);
//    }
}