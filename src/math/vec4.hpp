//
// Created by Cody on 10/30/2019.
//

#ifndef REIKI_VEC4_HPP
#define REIKI_VEC4_HPP

#include <iostream>
#include <cmath>

namespace Reiki::math {
    struct vec4 {
        float x,y,z,w;

        vec4();
        vec4(float x, float y, float z, float w);

        vec4& add(const vec4& right);
        vec4& sub(const vec4& right);
        vec4& mul(const vec4& right);
        vec4& div(const vec4& right);

        bool operator==(const vec4& right);
        bool operator!=(const vec4& right);

        friend float dot(const vec4& left, const vec4& right);
        float sq_len() { return dot(*this, *this); }
        float len() { return std::sqrt(sq_len()); }

        friend std::ostream& operator<<(std::ostream& os, const vec4& vec);

        friend vec4 operator+(const vec4& left, const vec4& right);
        friend vec4 operator-(const vec4& left, const vec4& right);
        friend vec4 operator*(const vec4& left, const vec4& right);
        friend vec4 operator/(const vec4& left, const vec4& right);

        vec4& operator+=(const vec4& right);
        vec4& operator-=(const vec4& right);
        vec4& operator*=(const vec4& right);
        vec4& operator/=(const vec4& right);
    };
}

#endif //REIKI_VEC4_HPP
