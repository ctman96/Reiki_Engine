//
// Created by Cody on 10/30/2019.
//

#include "vec2.hpp"

Reiki::math::vec2::vec2() {
    x=0.f;
    y=0.f;
}

Reiki::math::vec2::vec2(float x, float y) : x(x), y(y) {}

Reiki::math::vec2 &Reiki::math::vec2::add(const Reiki::math::vec2 &right) {
    x += right.x;
    y += right.y;
    return *this;
}

Reiki::math::vec2 &Reiki::math::vec2::sub(const Reiki::math::vec2 &right) {
    x -= right.x;
    y -= right.y;
    return *this;
}

Reiki::math::vec2 &Reiki::math::vec2::mul(const Reiki::math::vec2 &right) {
    x *= right.x;
    y *= right.y;
    return *this;
}

Reiki::math::vec2 &Reiki::math::vec2::div(const Reiki::math::vec2 &right) {
    x /= right.x;
    y /= right.y;
    return *this;
}

bool Reiki::math::vec2::operator==(const Reiki::math::vec2 &right) {
    return x==right.x && y==right.y;
}

bool Reiki::math::vec2::operator!=(const Reiki::math::vec2 &right) {
    return !(*this==right);
}

namespace Reiki::math {
    float dot(const vec2 &left, const vec2 &right) {
        return left.x * right.x + left.y * right.y;
    }

    std::ostream &operator<<(std::ostream &os, const vec2 &vec) {
        os << "(" << vec.x << "," << vec.y << ")";
        return os;
    }

    vec2 operator+(const vec2 &left, const vec2 &right) {
        vec2 out = left;
        out.add(right);
        return out;
    }

    vec2 operator-(const vec2 &left, const vec2 &right) {
        vec2 out = left;
        out.sub(right);
        return out;
    }

    vec2 operator*(const vec2 &left, const vec2 &right) {
        vec2 out = left;
        out.mul(right);
        return out;
    }

    vec2 operator/(const vec2 &left, const vec2 &right) {
        vec2 out = left;
        out.div(right);
        return out;;
    }

    vec2 &vec2::operator+=(const vec2 &right) {
        return add(right);
    }

    vec2 &vec2::operator-=(const vec2 &right) {
        return sub(right);
    }

    vec2 &vec2::operator*=(const vec2 &right) {
        return mul(right);
    }

    vec2 &vec2::operator/=(const vec2 &right) {
        return div(right);
    }
}