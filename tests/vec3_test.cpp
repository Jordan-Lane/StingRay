#include "gtest/gtest.h"

// GTest Primer: https://github.com/google/googletest/blob/master/googletest/docs/primer.md

class Vec3Test: public ::testing::Test {

};

TEST_F(Vec3Test, GeneralTest){
    EXPECT_TRUE(true);
}



