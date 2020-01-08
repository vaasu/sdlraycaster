#if 0
  std::array<std::array<int, 3>, 3> k = {{{5, 8, 2}, {8, 3, 1}, {5, 3, 9}}};
  std::array<std::array<int, 4>, 3> fourbythree = {
      {{101, 102, 103, 104}, {5, 8, 2, 7}, {8, 3, 1, 89}}};

  swm::mat4x3 mymat{fourbythree};

  mymat.PrintMatrix();
  std::cout << "------" << std::endl;
  std::cout << "transformed:" << std::endl;
  swm::mat3x4 mymat_transposed{mymat.Transpose()};
  mymat_transposed.PrintMatrix();

  std::cout << "row 3 col 2 = :" << unsigned(mymat.GetValue(3, 2)) << std::endl;
  return 0;
#endif