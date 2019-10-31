//
// Created by Cody on 10/30/2019.
//

#include "vec4.hpp"

namespace Reiki::math {
    vec4::vec4() {
        x=0.f;
        y=0.f;
        z=0.f;
        w=0.f;
    }

    vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    vec4 &vec4::add(const vec4 &right) {
        x += right.x;
        y += right.y;
        z += right.z;
        w += right.w;
        return *this;
    }

    vec4 &vec4::sub(const vec4 &right) {
        x -= right.x;
        y -= right.y;
        z -= right.z;
        w -= right.w;
        return *this;
    }

    vec4 &vec4::mul(const vec4 &right) {
        x *= right.x;
        y *= right.y;
        z *= right.z;
        w *= right.w;
        return *this;
    }

    vec4 &vec4::div(const vec4 &right) {
        x /= right.x;
        y /= right.y;
        z /= right.z;
        w /= right.w;
        return *this;
    }

    bool vec4::operator==(const vec4 &right) {
        return x==right.x && y==right.y && z==right.z && w==right.w;
    }

    bool vec4::operator!=(const vec4 &right) {
        return !(*this==right);
    }

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