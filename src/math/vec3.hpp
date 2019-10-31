//
// Created by Cody on 10/30/2019.
//

#ifndef REIKI_VEC3_HPP
#define REIKI_VEC3_HPP

#include <iostream>
#include <cmath>

namespace Reiki::math {
    struct vec3 {
        float x,y,z;

        vec3();
        vec3(float x, float y, float z);

        vec3& add(const vec3& right);
        vec3& sub(const vec3& right);
        vec3& mul(const vec3& right);
        vec3& div(const vec3& right);

        bool operator==(const vec3& right);
        bool operator!=(const vec3& right);

        friend float dot(const vec3& left, const vec3& right);
        float sq_len() { return dot(*this, *this); }
        float len() { return std::sqrt(sq_len()); }

        friend std::ostream& operator<<(std::ostream& os, const vec3& vec);

        friend vec3 operator+(const vec3& left, const vec3& right);
        friend vec3 operator-(const vec3& left, const vec3& right);
        friend vec3 operator*(const vec3& left, const vec3& right);
        friend vec3 operator/(const vec3& left, const vec3& right);

        vec3& operator+=(const vec3& right);
        vec3& operator-=(const vec3& right);
        vec3& operator*=(const vec3& right);
        vec3& operator/=(const vec3& right);
    };
}

#endif //REIKI_VEC3_HPP
