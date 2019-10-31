//
// Created by Cody on 10/31/2019.
//

#include <gtest/gtest.h>
#include "../../src/math/vec2.hpp"

using namespace Reiki;

class Vec2Test : public ::testing::Test {
protected:
    //! Sets up the test
    Vec2Test() {

    }

    //! Cleans up after the test
    ~Vec2Test() {

    }
};

TEST_F(Vec2Test, DefaultConstructor) {
    vec2 v;
    ASSERT_EQ(0.f, v.x);
    ASSERT_EQ(0.f, v.y);
}

TEST_F(Vec2Test, Constructor) {
    vec2 v(1.f, 2.f);
    ASSERT_EQ(1.f, v.x);
    ASSERT_EQ(2.f, v.y);
}



TEST_F(Vec2Test, Add) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    v1.add(v2);
    ASSERT_EQ(3.f, v1.x);
    ASSERT_EQ(6.f, v1.y);
    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
}

TEST_F(Vec2Test, Sub) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    v1.sub(v2);
    ASSERT_EQ(-1.f, v1.x);
    ASSERT_EQ(-2.f, v1.y);
    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
}

TEST_F(Vec2Test, Mul) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    v1.mul(v2);
    ASSERT_EQ(2.f, v1.x);
    ASSERT_EQ(8.f, v1.y);
    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
}

TEST_F(Vec2Test, Div) {
    vec2 v1(1.f, 4.f);
    vec2 v2(4.f, 2.f);
    v1.div(v2);
    ASSERT_EQ(0.25f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(4.f, v2.x);
    ASSERT_EQ(2.f, v2.y);
}


TEST_F(Vec2Test, OpEqualToFalse) {
    vec2 v1(1.f, 2.f);
    vec2 v2(1.f, 4.f);
    ASSERT_FALSE(v1 == v2);
}
TEST_F(Vec2Test, OpEqualToTrue) {
    vec2 v1(1.f, 4.f);
    vec2 v2(1.f, 4.f);
    ASSERT_TRUE(v1 == v2);
}

TEST_F(Vec2Test, OpNotEqualToFalse) {
    vec2 v1(1.f, 4.f);
    vec2 v2(1.f, 4.f);
    ASSERT_FALSE(v1 != v2);
}
TEST_F(Vec2Test, OpNotEqualToTrue) {
    vec2 v1(1.f, 2.f);
    vec2 v2(1.f, 4.f);
    ASSERT_TRUE(v1 != v2);
}

TEST_F(Vec2Test, Dot) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    ASSERT_EQ(2+8, dot(v1,v2));
}
TEST_F(Vec2Test, Dot1) {
    vec2 v1(-1.f, 2.f);
    vec2 v2(2.f, 0.f);
    ASSERT_EQ(-2, dot(v1,v2));
}

TEST_F(Vec2Test, SqLen) {
    vec2 v1(-1.f, 2.f);
    ASSERT_EQ(1+4, v1.sq_len());
}

TEST_F(Vec2Test, Len) {
    vec2 v1(-1.f, 2.f);
    ASSERT_EQ(sqrt(1+4), v1.sq_len());
}

// TODO how to test operator <<

TEST_F(Vec2Test, OpAddition) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    vec2 out = v1 + v2;

    ASSERT_EQ(3.f, out.x);
    ASSERT_EQ(6.f, out.y);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(2.f, v1.y);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
}

TEST_F(Vec2Test, OpSubtraction) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    vec2 out = v1 - v2;

    ASSERT_EQ(-1.f, out.x);
    ASSERT_EQ(-2.f, out.y);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(2.f, v1.y);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
}

TEST_F(Vec2Test, OpMultiplication) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    vec2 out = v1 * v2;

    ASSERT_EQ(2.f, out.x);
    ASSERT_EQ(8.f, out.y);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(2.f, v1.y);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
}

TEST_F(Vec2Test, OpDivision) {
    vec2 v1(1.f, 4.f);
    vec2 v2(2.f, 2.f);
    vec2 out = v1 / v2;

    ASSERT_EQ(0.5f, out.x);
    ASSERT_EQ(2.f, out.y);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(4.f, v1.y);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(2.f, v2.y);
}

TEST_F(Vec2Test, OpAssignmentAddition) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    v1 += v2;

    ASSERT_EQ(3.f, v1.x);
    ASSERT_EQ(6.f, v1.y);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
}

TEST_F(Vec2Test, OpAssignmentSubtraction) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    v1 -= v2;

    ASSERT_EQ(-1.f, v1.x);
    ASSERT_EQ(-2.f, v1.y);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
}

TEST_F(Vec2Test, OpAssignmentMultiplication) {
    vec2 v1(1.f, 2.f);
    vec2 v2(2.f, 4.f);
    v1 *= v2;

    ASSERT_EQ(2.f, v1.x);
    ASSERT_EQ(8.f, v1.y);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
}

TEST_F(Vec2Test, OpAssignmentDivision) {
    vec2 v1(1.f, 4.f);
    vec2 v2(4.f, 2.f);
    v1 /= v2;

    ASSERT_EQ(0.25f, v1.x);
    ASSERT_EQ(2.f, v1.y);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(2.f, v2.y);
}