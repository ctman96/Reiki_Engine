//
// Created by Cody on 10/30/2019.
//

#include "mat3.hpp"

namespace Reiki::math {
    mat3::mat3() {
        c0 = vec3();
        c1 = vec3();
        c2 = vec3();
    }

    mat3::mat3(float n) {
        c0 = vec3(n, 0.f, 0.f);
        c1 = vec3(0.f, n, 0.f);
        c2 = vec3(0.f, 0.f, n);
    }

    mat3::mat3(vec3 c0, vec3 c1, vec3 c2) : c0(c0), c1(c1), c2(c2) {}



    mat3 mat3::Identity() {
        return mat3(1);
    }

    mat3 mat3::Translation(vec2 offset) {
        mat3 T = { { 1.f, 0.f, 0.f },{ 0.f, 1.f, 0.f },{ offset.x, offset.y, 1.f }};
        return T;
    }

    mat3 mat3::Scale(vec2 scale) {
        mat3 S = { { scale.x, 0.f, 0.f },{ 0.f, scale.y, 0.f },{ 0.f, 0.f, 1.f } };
        return S;
    }

    mat3 mat3::Rotation(float radians) {
        float c = cosf(radians);
        float s = sinf(radians);
        mat3 R = { { c, s, 0.f },{ -s, c, 0.f },{ 0.f, 0.f, 1.f } };
        return R;
    }



    mat3 &mat3::mul(const mat3 &r) {
        mat3 l_t = { { c0.x, c1.x, c2.x},
                     { c0.y, c1.y, c2.y } ,
                     { c0.z, c1.z, c2.z } };

        mat3 ret;
        ret.c0.x = dot(l_t.c0, r.c0);
        ret.c0.y = dot(l_t.c1, r.c0);
        ret.c0.z = dot(l_t.c2, r.c0);

        ret.c1.x = dot(l_t.c0, r.c1);
        ret.c1.y = dot(l_t.c1, r.c1);
        ret.c1.z = dot(l_t.c2, r.c1);

        ret.c2.x = dot(l_t.c0, r.c2);
        ret.c2.y = dot(l_t.c1, r.c2);
        ret.c2.z = dot(l_t.c2, r.c2);
        c0 = ret.c0;
        c1 = ret.c1;
        c2 = ret.c2;
        return *this;
    }

    vec3 mat3::mul(const vec3 &right) const {
        return {
            dot(vec3{c0.x, c1.x, c2.x}, right),
            dot(vec3{c0.y, c1.y, c2.y}, right),
            dot(vec3{c0.z, c1.z, c2.z}, right)
        };
    }

    mat3 operator*(const mat3 &left, const mat3 &right) {
        mat3 ret = left;
        ret.mul(right);
        return ret;
    }

    vec3 operator*(const mat3 left, const vec3 &right) {
        return left.mul(right);
    }

    mat3 &mat3::operator*=(const mat3 &right) {
        return mul(right);
    }

    mat3 &mat3::translate(vec2 offset) {
        return mul(Translation(offset));
    }

    mat3 &mat3::scale(vec2 scale) {
        return mul(Scale(scale));
    }

    mat3 &mat3::rotate(float radians) {
        return mul(Rotation(radians));
    }

    std::ostream &operator<<(std::ostream &os, const mat3 &m) {
        os << "{" << m.c0 << "," << m.c1 << "," << m.c2 << ")";
        return os;
    }
}
