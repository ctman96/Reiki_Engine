//
// Created by Cody on 10/31/2019.
//

#include <gtest/gtest.h>
#include "../../src/math/vec3.hpp"

using namespace Reiki;

class Vec3Test : public ::testing::Test {
protected:
    //! Sets up the test
    Vec3Test() {

    }

    //! Cleans up after the test
    ~Vec3Test() {

    }
};

TEST_F(Vec3Test, DefaultConstructor) {
    vec3 v;
    ASSERT_EQ(0.f, v.x);
    ASSERT_EQ(0.f, v.y);
    ASSERT_EQ(0.f, v.z);
}

TEST_F(Vec3Test, Constructor) {
    vec3 v(1.f, 2.f, 3.f);
    ASSERT_EQ(1.f, v.x);
    ASSERT_EQ(2.f, v.y);
    ASSERT_EQ(3.f, v.z);
}



TEST_F(Vec3Test, Add) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 1.f);
    v1.add(v2);

    ASSERT_EQ(3.f, v1.x);
    ASSERT_EQ(6.f, v1.y);
    ASSERT_EQ(4.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
}

TEST_F(Vec3Test, Sub) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 1.f);
    v1.sub(v2);

    ASSERT_EQ(-1.f, v1.x);
    ASSERT_EQ(-2.f, v1.y);
    ASSERT_EQ(2.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
}

TEST_F(Vec3Test, Mul) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 5.f);
    v1.mul(v2);

    ASSERT_EQ(2.f, v1.x);
    ASSERT_EQ(8.f, v1.y);
    ASSERT_EQ(15.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(5.f, v2.z);
}

TEST_F(Vec3Test, Div) {
    vec3 v1(1.f, 4.f, 9.f);
    vec3 v2(4.f, 2.f, 3.f);
    v1.div(v2);

    ASSERT_EQ(0.25f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);

    ASSERT_EQ(4.f, v2.x);
    ASSERT_EQ(2.f, v2.y);
    ASSERT_EQ(3.f, v2.z);
}


TEST_F(Vec3Test, OpEqualToFalse) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(1.f, 4.f, 6.f);
    ASSERT_FALSE(v1 == v2);
}
TEST_F(Vec3Test, OpEqualToTrue) {
    vec3 v1(1.f, 4.f, 6.f);
    vec3 v2(1.f, 4.f, 6.f);
    ASSERT_TRUE(v1 == v2);
}

TEST_F(Vec3Test, OpNotEqualToFalse) {
    vec3 v1(1.f, 4.f, 6.f);
    vec3 v2(1.f, 4.f, 6.f);
    ASSERT_FALSE(v1 != v2);
}
TEST_F(Vec3Test, OpNotEqualToTrue) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(1.f, 4.f, 6.f);
    ASSERT_TRUE(v1 != v2);
}

TEST_F(Vec3Test, Dot) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 6.f);
    ASSERT_EQ(2+8+18, dot(v1,v2));
}
TEST_F(Vec3Test, Dot1) {
    vec3 v1(-1.f, 2.f, 3.f);
    vec3 v2(2.f, 0.f, -1.f);
    ASSERT_EQ(-2-3, dot(v1,v2));
}

TEST_F(Vec3Test, SqLen) {
    vec3 v1(-1.f, 2.f, 3.f);
    ASSERT_EQ(1+4+9, v1.sq_len());
}

TEST_F(Vec3Test, Len) {
    vec3 v1(-1.f, 2.f, 3.f);
    ASSERT_FLOAT_EQ(sqrt(1+4+9), v1.len());
}

// TODO how to test operator <<

TEST_F(Vec3Test, OpAddition) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 1.f);
    vec3 out = v1 + v2;

    ASSERT_EQ(3.f, out.x);
    ASSERT_EQ(6.f, out.y);
    ASSERT_EQ(4.f, out.z);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
}

TEST_F(Vec3Test, OpSubtraction) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 1.f);
    vec3 out = v1 - v2;

    ASSERT_EQ(-1.f, out.x);
    ASSERT_EQ(-2.f, out.y);
    ASSERT_EQ(2.f, out.z);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
}

TEST_F(Vec3Test, OpMultiplication) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 0.5f);
    vec3 out = v1 * v2;

    ASSERT_EQ(2.f, out.x);
    ASSERT_EQ(8.f, out.y);
    ASSERT_EQ(1.5f, out.z);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(0.5f, v2.z);
}

TEST_F(Vec3Test, OpDivision) {
    vec3 v1(1.f, 4.f, 9.f);
    vec3 v2(2.f, 2.f, 3.f);
    vec3 out = v1 / v2;

    ASSERT_EQ(0.5f, out.x);
    ASSERT_EQ(2.f, out.y);
    ASSERT_EQ(3.f, out.z);

    ASSERT_EQ(1.f, v1.x);
    ASSERT_EQ(4.f, v1.y);
    ASSERT_EQ(9.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(2.f, v2.y);
    ASSERT_EQ(3.f, v2.z);
}

TEST_F(Vec3Test, OpAssignmentAddition) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 1.f);
    v1 += v2;

    ASSERT_EQ(3.f, v1.x);
    ASSERT_EQ(6.f, v1.y);
    ASSERT_EQ(4.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
}

TEST_F(Vec3Test, OpAssignmentSubtraction) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 1.f);
    v1 -= v2;

    ASSERT_EQ(-1.f, v1.x);
    ASSERT_EQ(-2.f, v1.y);
    ASSERT_EQ(2.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(1.f, v2.z);
}

TEST_F(Vec3Test, OpAssignmentMultiplication) {
    vec3 v1(1.f, 2.f, 3.f);
    vec3 v2(2.f, 4.f, 5.f);
    v1 *= v2;

    ASSERT_EQ(2.f, v1.x);
    ASSERT_EQ(8.f, v1.y);
    ASSERT_EQ(15.f, v1.z);

    ASSERT_EQ(2.f, v2.x);
    ASSERT_EQ(4.f, v2.y);
    ASSERT_EQ(5.f, v2.z);
}

TEST_F(Vec3Test, OpAssignmentDivision) {
    vec3 v1(1.f, 4.f, 9.f);
    vec3 v2(4.f, 2.f, 3.f);
    v1 /= v2;

    ASSERT_EQ(0.25f, v1.x);
    ASSERT_EQ(2.f, v1.y);
    ASSERT_EQ(3.f, v1.z);

    ASSERT_EQ(4.f, v2.x);
    ASSERT_EQ(2.f, v2.y);
    ASSERT_EQ(3.f, v2.z);
}