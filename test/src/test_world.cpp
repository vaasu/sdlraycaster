
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>
#include <glm/glm.hpp>

#include "test_fixture.h"

TEST_F(SrcTestFixture, Test) {
  std::vector<glm::vec4> output{};
  float float_projection_matrix[16] = {
      1.0, 0,   0,   0,                             //
      0,   1.0, 0,   0,                             //
      0,   0,   1.0, static_cast<float>(-1.0 / 5),  //
      0,   0,   0,   0                              //

  };
  //   float twoex3[6] = {1, 2, 3,  //
  //                      4, 5, 6};

  //   glm::mat2x3 mat23 = glm::make_mat2x3(twoex3);
  glm::mat4 projection_matrix = glm::make_mat4(float_projection_matrix);

  //   std::cout << "raw print === " << glm::to_string(mat23) << std::endl;
  //   std::cout << "colum index 0  === " << glm::to_string(glm::column(mat23,
  //   0))
  //             << std::endl;
  //   std::cout << "row index 0  === " << glm::to_string(glm::row(mat23, 0))
  //             << std::endl;

  //   std::cout << "object count = "
  //             << unsigned(my_world_.GetAllSceneObjects().size()) <<
  //             std::endl;
  ASSERT_TRUE(true);
}