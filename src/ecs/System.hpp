//
// Created by Cody on 10/16/2019.
//

#ifndef REIKI_SYSTEM_HPP
#define REIKI_SYSTEM_HPP

#include <cstddef>

namespace Reiki::ECS {
    using SystemId = std::size_t;

    // Returns a unique, incremeneted Id
    inline SystemId getSystemId() {
        static SystemId lastId = 0;
        return lastId++;
    };

    // Returns a unique id for each type T of component;
    template <typename T> inline SystemId getSystemTypeId() noexcept {
        static SystemId typeId = getSystemId();
        return typeId;
    }

    class System {
        friend class SystemManager;
    private:
        SystemId id;
        bool active = true;
    public:
        SystemId getId() const { return id; }

        virtual void update(float ms) {}

        bool isActive() { return active; };
        void destroy() { active = false; };
    };
}

#endif //REIKI_SYSTEM_HPP
