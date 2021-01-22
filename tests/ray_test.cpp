#include "gtest/gtest.h"
#include "stingray_util.h"

class RayTest : public::testing::Test {
    protected:
        void SetUp(){
            point3 origin1 = point3(0, 0, 0);
            point3 dir1 = point3(1, 2, 3);

            test_ray1 = ray(origin1, dir1);
        }

        ray test_ray1;
};

TEST_F(RayTest, RayCreation_Test){
    ASSERT_EQ(test_ray1.origin(), point3(0,0,0));
    ASSERT_EQ( test_ray1.direction(), vec3(1, 2, 3));
}

TEST_F(RayTest, RayAtT){
    ASSERT_EQ(test_ray1.at(0), vec3(0, 0, 0));
    ASSERT_EQ(test_ray1.at(10), vec3(10, 20, 30));
    ASSERT_EQ(test_ray1.at(-10), vec3(-10, -20, -30));
}