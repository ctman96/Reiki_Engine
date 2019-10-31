//
// Created by Cody on 10/31/2019.
//


#include <gtest/gtest.h>
#include "../../src/math/vec4.hpp"

using namespace Reiki;

class Vec4Test : public ::testing::Test {
protected:
    //! Sets up the test
    Vec4Test() {

    }

    //! Cleans up after the test
    ~Vec4Test() {

    }
};

TEST_F(Vec4Test, DefaultConstructor) {
    vec4 v;
    ASSERT_EQ(0.f, v.x);
    ASSERT_EQ(0.f, v.y);
    ASSERT_EQ(0.f, v.z);
    ASSERT_EQ(0.f, v.w);
}

TEST_F(Vec4Test, Constructor) {
    vec4 v(1.f, 2.f, 3.f, -1.f);
    ASSERT_EQ(1.f, v.x);
    ASSERT_EQ(2.f, v.y);
    ASSERT_EQ(3.f, v.z);
    ASSERT_EQ(-1.f, v.w);
}



TEST_F(Vec4Test, Add) {
    vec4 v1(1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 4.f, 1.f, -1.f);
    v1.add(v2);

    ASSERT_EQ(3.f, v1.x);
    ASSERT_EQ(6.f, v1.y);
    ASSERT_EQ(4.f, v1.z);
    ASSERT_EQ(3.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
    ASSERT_EQ(-1.f, v2.w);
}

TEST_F(Vec4Test, Sub) {
    vec4 v1(1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 4.f, 1.f, -1.f);
    v1.sub(v2);

    ASSERT_EQ(-1.f, v1.x);
    ASSERT_EQ(-2.f, v1.y);
    ASSERT_EQ(2.f, v1.z);
    ASSERT_EQ(5.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
    ASSERT_EQ(-1.f, v2.w);
}

TEST_F(Vec4Test, Mul) {
    vec4 v1(1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 4.f, 5.f, -2.f);
    v1.mul(v2);

    ASSERT_EQ(2.f, v1.x);
    ASSERT_EQ(8.f, v1.y);
    ASSERT_EQ(15.f, v1.z);
    ASSERT_EQ(-8.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(5.f, v2.z);
    ASSERT_EQ(-2.f, v2.w);
}

TEST_F(Vec4Test, Div) {
    vec4 v1(1.f, 4.f, 9.f, 5.f);
    vec4 v2(4.f, 2.f, 3.f, -2.5f);
    v1.div(v2);

    ASSERT_EQ(0.25f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);
    ASSERT_EQ(-2.f, v1.w);

    ASSERT_EQ(4.f, v2.x);
    ASSERT_EQ(2.f, v2.y);
    ASSERT_EQ(3.f, v2.z);
    ASSERT_EQ(-2.5f, v2.w);
}


TEST_F(Vec4Test, OpEqualToFalse) {
    vec4 v1(1.f, 2.f, 3.f, 5.f);
    vec4 v2(1.f, 4.f, 6.f, 5.f);
    ASSERT_FALSE(v1 == v2);
}
TEST_F(Vec4Test, OpEqualToTrue) {
    vec4 v1(1.f, 4.f, 6.f, 5.f);
    vec4 v2(1.f, 4.f, 6.f, 5.f);
    ASSERT_TRUE(v1 == v2);
}

TEST_F(Vec4Test, OpNotEqualToFalse) {
    vec4 v1(1.f, 4.f, 6.f, 5.f);
    vec4 v2(1.f, 4.f, 6.f, 5.f);
    ASSERT_FALSE(v1 != v2);
}
TEST_F(Vec4Test, OpNotEqualToTrue) {
    vec4 v1(1.f, 2.f, 3.f, 5.f);
    vec4 v2(1.f, 4.f, 6.f, 5.f);
    ASSERT_TRUE(v1 != v2);
}

TEST_F(Vec4Test, Dot) {
    vec4 v1(1.f, 2.f, 3.f, -2.f);
    vec4 v2(2.f, 4.f, 6.f, 3.f);
    ASSERT_EQ(2+8+18-6, dot(v1,v2));
}
TEST_F(Vec4Test, Dot1) {
    vec4 v1(-1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 0.f, -1.f, 3.f);
    ASSERT_EQ(-2-3+12, dot(v1,v2));
}

TEST_F(Vec4Test, SqLen) {
    vec4 v1(-1.f, 2.f, 3.f, -4.f);
    ASSERT_EQ(1+4+9+16, v1.sq_len());
}

TEST_F(Vec4Test, Len) {
    vec4 v1(-1.f, 2.f, 3.f, -4.f);
    ASSERT_FLOAT_EQ(sqrt(1+4+9+16), v1.len());
}

// TODO how to test operator <<

TEST_F(Vec4Test, OpAddition) {
    vec4 v1(1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 4.f, 1.f, -1.f);
    vec4 out = v1 + v2;

    ASSERT_EQ(3.f, out.x);
    ASSERT_EQ(6.f, out.y);
    ASSERT_EQ(4.f, out.z);
    ASSERT_EQ(3.f, out.w);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);
    ASSERT_EQ(4.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
    ASSERT_EQ(-1.f, v2.w);
}

TEST_F(Vec4Test, OpSubtraction) {
    vec4 v1(1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 4.f, 1.f, -1.f);
    vec4 out = v1 - v2;

    ASSERT_EQ(-1.f, out.x);
    ASSERT_EQ(-2.f, out.y);
    ASSERT_EQ(2.f, out.z);
    ASSERT_EQ(5.f, out.w);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);
    ASSERT_EQ(4.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
    ASSERT_EQ(-1.f, v2.w);
}

TEST_F(Vec4Test, OpMultiplication) {
    vec4 v1(1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 4.f, 0.5f, -2.f);
    vec4 out = v1 * v2;

    ASSERT_EQ(2.f, out.x);
    ASSERT_EQ(8.f, out.y);
    ASSERT_EQ(1.5f, out.z);
    ASSERT_EQ(-8.f, out.w);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);
    ASSERT_EQ(4.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(0.5f, v2.z);
    ASSERT_EQ(-2.f, v2.w);
}

TEST_F(Vec4Test, OpDivision) {
    vec4 v1(1.f, 4.f, 9.f, 5.f);
    vec4 v2(2.f, 2.f, 3.f, -2.5f);
    vec4 out = v1 / v2;

    ASSERT_EQ(0.5f, out.x);
    ASSERT_EQ(2.f, out.y);
    ASSERT_EQ(3.f, out.z);
    ASSERT_EQ(-2.f, out.w);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(4.f, v1.y);
    ASSERT_EQ(9.f, v1.z);
    ASSERT_EQ(5.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(2.f, v2.y);
    ASSERT_EQ(3.f, v2.z);
    ASSERT_EQ(-2.5f, v2.w);
}

TEST_F(Vec4Test, OpAssignmentAddition) {
    vec4 v1(1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 4.f, 1.f, -1.f);
    v1 += v2;

    ASSERT_EQ(3.f, v1.x);
    ASSERT_EQ(6.f, v1.y);
    ASSERT_EQ(4.f, v1.z);
    ASSERT_EQ(3.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
    ASSERT_EQ(-1.f, v2.w);
}

TEST_F(Vec4Test, OpAssignmentSubtraction) {
    vec4 v1(1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 4.f, 1.f, -1.f);
    v1 -= v2;

    ASSERT_EQ(-1.f, v1.x);
    ASSERT_EQ(-2.f, v1.y);
    ASSERT_EQ(2.f, v1.z);
    ASSERT_EQ(5.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
    ASSERT_EQ(-1.f, v2.w);
}

TEST_F(Vec4Test, OpAssignmentMultiplication) {
    vec4 v1(1.f, 2.f, 3.f, 4.f);
    vec4 v2(2.f, 4.f, 5.f, -2.f);
    v1 *= v2;

    ASSERT_EQ(2.f, v1.x);
    ASSERT_EQ(8.f, v1.y);
    ASSERT_EQ(15.f, v1.z);
    ASSERT_EQ(-8.f, v1.w);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(5.f, v2.z);
    ASSERT_EQ(-2.f, v2.w);
}

TEST_F(Vec4Test, OpAssignmentDivision) {
    vec4 v1(1.f, 4.f, 9.f, 5.f);
    vec4 v2(4.f, 2.f, 3.f, -2.5f);
    v1 /= v2;

    ASSERT_EQ(0.25f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);
    ASSERT_EQ(-2.f, v1.w);

    ASSERT_EQ(4.f, v2.x);
    ASSERT_EQ(2.f, v2.y);
    ASSERT_EQ(3.f, v2.z);
    ASSERT_EQ(-2.5f, v2.w);
}
