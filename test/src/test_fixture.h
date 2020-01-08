#include <gtest/gtest.h>
#include "world.h"
class SrcTestFixture : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}

 protected:
  sdlraycaster::World my_world_{};

 private:
};