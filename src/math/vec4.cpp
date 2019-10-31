//
// Created by Cody on 10/30/2019.
//

#include "vec4.hpp"


Reiki::math::vec4::vec4() {
    x=0.f;
    y=0.f;
    z=0.f;
    w=0.f;
}

Reiki::math::vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Reiki::math::vec4 &Reiki::math::vec4::add(const Reiki::math::vec4 &right) {
    x += right.x;
    y += right.y;
    z += right.z;
    w += right.w;
    return *this;
}

Reiki::math::vec4 &Reiki::math::vec4::sub(const Reiki::math::vec4 &right) {
    x -= right.x;
    y -= right.y;
    z -= right.z;
    w -= right.w;
    return *this;
}

Reiki::math::vec4 &Reiki::math::vec4::mul(const Reiki::math::vec4 &right) {
    x *= right.x;
    y *= right.y;
    z *= right.z;
    w *= right.w;
    return *this;
}

Reiki::math::vec4 &Reiki::math::vec4::div(const Reiki::math::vec4 &right) {
    x /= right.x;
    y /= right.y;
    z /= right.z;
    w /= right.w;
    return *this;
}

bool Reiki::math::vec4::operator==(const Reiki::math::vec4 &right) {
    return x==right.x && y==right.y && z==right.z && w==right.w;
}

bool Reiki::math::vec4::operator!=(const Reiki::math::vec4 &right) {
    return !(*this==right);
}

namespace Reiki::math {
    float dot(const vec4 &left, const vec4 &right) {
        return left.x * right.x + left.y * right.y +  left.z * right.z +  left.w * right.w;
    }

    std::ostream &operator<<(std::ostream &os, const vec4 &vec) {
        os << "(" << vec.x << "," << vec.y << "," << vec.z << "," << vec.w << ")";
        return os;
    }

    vec4 operator+(const vec4 &left, const vec4 &right) {
        vec4 out = left;
        out.add(right);
        return out;
    }

    vec4 operator-(const vec4 &left, const vec4 &right) {
        vec4 out = left;
        out.sub(right);
        return out;
    }

    vec4 operator*(const vec4 &left, const vec4 &right) {
        vec4 out = left;
        out.mul(right);
        return out;
    }

    vec4 operator/(const vec4 &left, const vec4 &right) {
        vec4 out = left;
        out.div(right);
        return out;;
    }

    vec4 &vec4::operator+=(const vec4 &right) {
        return add(right);
    }

    vec4 &vec4::operator-=(const vec4 &right) {
        return sub(right);
    }

    vec4 &vec4::operator*=(const vec4 &right) {
        return mul(right);
    }

    vec4 &vec4::operator/=(const vec4 &right) {
        return div(right);
    }
}