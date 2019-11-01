//
// Created by Cody on 10/30/2019.
//

#ifndef REIKI_MAT3_HPP
#define REIKI_MAT3_HPP

#include "vec3.hpp"
#include "vec2.hpp"

namespace Reiki::math {
    struct mat3 {
        vec3 c0, c1, c2; // columns

        mat3();
        explicit mat3(float n);
        mat3(vec3 c0, vec3 c1, vec3 c2);

        static mat3 Identity();
        static mat3 Orthographic(float left, float right, float bottom, float top);
        static mat3 Translation(vec2 offset);
        static mat3 Scale(vec2 scale);
        static mat3 Rotation(float radians);

        mat3& mul(const mat3& right);
        vec3 mul(const vec3& right) const;

        friend mat3 operator*(const mat3& left, const mat3& right);
        friend vec3 operator*(const mat3 left, const vec3& right);
        mat3& operator*=(const mat3& right);

        mat3& translate(vec2 offset);
        mat3& scale(vec2 scale);
        mat3& rotate(float radians);

        friend std::ostream& operator<<(std::ostream& os, const mat3& m);
        // TODO [][] lookup?
    };
}


#endif //REIKI_MAT3_HPP
