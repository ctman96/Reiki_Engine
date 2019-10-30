//
// Created by Cody on 10/30/2019.
//

#include "vec3.hpp"


Reiki::vec3::vec3() {
    x=0.f;
    y=0.f;
}

Reiki::vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Reiki::vec3 &Reiki::vec3::add(const Reiki::vec3 &right) {
    x += right.x;
    y += right.y;
    z += right.z;
    return *this;
}

Reiki::vec3 &Reiki::vec3::sub(const Reiki::vec3 &right) {
    x -= right.x;
    y -= right.y;
    z -= right.z;
    return *this;
}

Reiki::vec3 &Reiki::vec3::mul(const Reiki::vec3 &right) {
    x *= right.x;
    y *= right.y;
    z *= right.z;
    return *this;
}

Reiki::vec3 &Reiki::vec3::div(const Reiki::vec3 &right) {
    x /= right.x;
    y /= right.y;
    z /= right.z;
    return *this;
}

bool Reiki::vec3::operator==(const Reiki::vec3 &right) {
    return x==right.x && y==right.y && z==right.z;
}

bool Reiki::vec3::operator!=(const Reiki::vec3 &right) {
    return !(*this==right);
}

namespace Reiki {
    float dot(const vec3 &left, const vec3 &right) {
        return left.x * right.x + left.y * right.y +  left.z * right.z;
    }

    std::ostream &operator<<(std::ostream &os, const vec3 &vec) {
        os << "(" << vec.x << "," << vec.y << "," << vec.z << ")";
        return os;
    }

    vec3 operator+(const vec3 &left, const vec3 &right) {
        vec3 out = left;
        out.add(right);
        return out;
    }

    vec3 operator-(const vec3 &left, const vec3 &right) {
        vec3 out = left;
        out.sub(right);
        return out;
    }

    vec3 operator*(const vec3 &left, const vec3 &right) {
        vec3 out = left;
        out.mul(right);
        return out;
    }

    vec3 operator/(const vec3 &left, const vec3 &right) {
        vec3 out = left;
        out.div(right);
        return out;;
    }

    vec3 &vec3::operator+=(const vec3 &right) {
        return add(right);
    }

    vec3 &vec3::operator-=(const vec3 &right) {
        return sub(right);
    }

    vec3 &vec3::operator*=(const vec3 &right) {
        return mul(right);
    }

    vec3 &vec3::operator/=(const vec3 &right) {
        return div(right);
    }
}