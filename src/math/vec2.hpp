//
// Created by Cody on 10/30/2019.
//

#ifndef REIKI_VEC2_HPP
#define REIKI_VEC2_HPP

#include <iostream>
#include <cmath>

namespace Reiki {
    struct vec2 {
        float x,y;

        vec2();
        vec2(float x, float y);

        vec2& add(const vec2& right);
        vec2& sub(const vec2& right);
        vec2& mul(const vec2& right);
        vec2& div(const vec2& right);

        bool operator==(const vec2& right);
        bool operator!=(const vec2& right);

        friend float dot(const vec2& left, const vec2& right); // TODO cross product?
        float sq_len() { return dot(*this, *this); }
        float len() { return std::sqrt(sq_len()); }

        friend std::ostream& operator<<(std::ostream& os, const vec2& vec);

        friend vec2 operator+(const vec2& left, const vec2& right);
        friend vec2 operator-(const vec2& left, const vec2& right);
        friend vec2 operator*(const vec2& left, const vec2& right);
        friend vec2 operator/(const vec2& left, const vec2& right);

        vec2& operator+=(const vec2& right);
        vec2& operator-=(const vec2& right);
        vec2& operator*=(const vec2& right);
        vec2& operator/=(const vec2& right);
    };
}

#endif //REIKI_VEC2_HPP
