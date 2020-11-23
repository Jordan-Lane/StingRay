#include "gtest/gtest.h"
#include "vec3.h"

// GTest Primer: https://github.com/google/googletest/blob/master/googletest/docs/primer.md

class Vec3Test: public ::testing::Test {
    protected:
        void SetUp() override {
            test_vec1 = vec3(1, 2, 3);
            test_vec2 = vec3(1, 2, 3);
            test_vec3 = vec3(5, 6, 7);
        }

        vec3 test_vec1;
        vec3 test_vec2;
        vec3 test_vec3;
};

TEST_F(Vec3Test, CreationTest){
    ASSERT_EQ(test_vec1.x(), 1);
    ASSERT_EQ(test_vec1.y(), 2);
    ASSERT_EQ(test_vec1.z(), 3);
}

TEST_F(Vec3Test, VectorEquality){
    ASSERT_TRUE(test_vec1 == test_vec2);
    ASSERT_FALSE(test_vec1 == test_vec3);
}

TEST_F(Vec3Test, VectorInequality){
    ASSERT_TRUE(test_vec1 != test_vec3);
    ASSERT_FALSE(test_vec1 != test_vec2);
}

TEST_F(Vec3Test, VectorAddition){
    vec3 result_vec = test_vec1 + test_vec2;
    vec3 expected_vec = vec3(2, 4, 6);

    ASSERT_EQ(result_vec, expected_vec);
}

TEST_F(Vec3Test, VectorSubtraction){
    vec3 result_vec = test_vec1 - test_vec2;
    vec3 expected_vec = vec3(0, 0, 0);

    ASSERT_EQ(result_vec, expected_vec);
}

TEST_F(Vec3Test, VectorScalarMultiplication){
    vec3 expected_vec = vec3(2, 4, 6);

    test_vec1 *= 2;
    ASSERT_EQ(test_vec1, expected_vec);

    vec3 result_vec1 = test_vec2 * 2;
    ASSERT_EQ(result_vec1, expected_vec);

    vec3 result_vec2 = 2 * test_vec2;
    ASSERT_EQ(result_vec2, expected_vec);
}

TEST_F(Vec3Test, VectorScalarDivision){
    vec3 expected_vec = vec3(0.5, 1, 1.5);

    test_vec1 /= 2;
    ASSERT_EQ(test_vec1, expected_vec);

    vec3 result_vec1 = test_vec2 / 2;
    ASSERT_EQ(result_vec1, expected_vec);
}

TEST_F(Vec3Test, Length){
    double expected_length = 3.7416573867739413;

    ASSERT_DOUBLE_EQ(test_vec1.length(), expected_length);
}

TEST_F(Vec3Test, VectorHadamardProduct){
    vec3 expected_vec = vec3(1, 4, 9);

    ASSERT_EQ(test_vec1 * test_vec2, expected_vec);
}

TEST_F(Vec3Test, VectorDotProduct){
    double expected_value = 14;

    ASSERT_EQ(dot(test_vec1, test_vec2), expected_value);
}

TEST_F(Vec3Test, VectorCrossProduct){
    vec3 expected_vec1 = vec3(0, 0, 0);
    vec3 expected_vec2 = vec3(-4, 8, -4);

    ASSERT_EQ(cross(test_vec1, test_vec2), expected_vec1);
    ASSERT_EQ(cross(test_vec1, test_vec3), expected_vec2);
}