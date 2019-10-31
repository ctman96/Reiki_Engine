//
// Created by Cody on 10/30/2019.
//

#include "vec2.hpp"

namespace Reiki::math {
    vec2::vec2() {
        x=0.f;
        y=0.f;
    }

    vec2::vec2(float x, float y) : x(x), y(y) {}

    vec2 &vec2::add(const vec2 &right) {
        x += right.x;
        y += right.y;
        return *this;
    }

    vec2 &vec2::sub(const vec2 &right) {
        x -= right.x;
        y -= right.y;
        return *this;
    }

    vec2 &vec2::mul(const vec2 &right) {
        x *= right.x;
        y *= right.y;
        return *this;
    }

    vec2 &vec2::div(const vec2 &right) {
        x /= right.x;
        y /= right.y;
        return *this;
    }

    bool vec2::operator==(const vec2 &right) {
        return x==right.x && y==right.y;
    }

    bool vec2::operator!=(const vec2 &right) {
        return !(*this==right);
    }

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