//
// Created by Cody on 10/30/2019.
//

#include "vec3.hpp"

namespace Reiki::math {
    vec3::vec3() {
        x=0.f;
        y=0.f;
        z=0.f;
    }

    vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    vec3 &vec3::add(const vec3 &right) {
        x += right.x;
        y += right.y;
        z += right.z;
        return *this;
    }

    vec3 &vec3::sub(const vec3 &right) {
        x -= right.x;
        y -= right.y;
        z -= right.z;
        return *this;
    }

    vec3 &vec3::mul(const vec3 &right) {
        x *= right.x;
        y *= right.y;
        z *= right.z;
        return *this;
    }

    vec3 &vec3::div(const vec3 &right) {
        x /= right.x;
        y /= right.y;
        z /= right.z;
        return *this;
    }

    bool vec3::operator==(const vec3 &right) {
        return x==right.x && y==right.y && z==right.z;
    }

    bool vec3::operator!=(const vec3 &right) {
        return !(*this==right);
    }

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