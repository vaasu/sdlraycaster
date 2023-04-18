#include <array>
#include <iostream>
#include <string>
#include <vector>
#pragma once
// this is c++14
namespace swm {

template <typename T, unsigned int R, unsigned int C>
class _MatrixBase {
 public:
  // store as colmn major
  std::array<std::array<T, R>, C> d_{};
  int GetRowCount() const { return r_; };
  int GetColumnCount() const { return c_; };

  void FillDiagnoal(T value) {
    for (int i = 0; i < r_; i++) {
      d_[i][i] = value;
    }
  }
  void SetValue(int row_index, int col_index, T value) {
    // todo bounds check
    d_[col_index][row_index] = value;
  }

  T GetValue(int row_index, int col_index) const {
    return d_[col_index][row_index];
  }

  _MatrixBase<T, C, R> Transpose() const {
    _MatrixBase<T, C, R> tx{};
    for (int i = 0; i < C; i++) {
      for (int k = 0; k < R; k++) {
        tx.SetValue(i, k, d_[i][k]);
      }
    }
    return tx;
  }
  _MatrixBase(const std::array<std::array<T, R>, C>& values) : d_{values} {
    static_assert(std::is_integral<T>::value, "Integral required.");
  }
  _MatrixBase() = default;

  _MatrixBase(const _MatrixBase& other) { d_ = other.d_; }

  void clear() {
    // todo use iterator
    for (int i = 0; i < C; i++) {
      for (int k = 0; k < R; k++) {
        SetValue(k, i, 0);
      }
    }
  }

  virtual void PrintMatrix() {
    std::cout << "{" << std::endl;
    // print in row major order:

    for (int i = 0; i < R; i++) {
      std::cout << "{";
      for (int j = 0; j < C; j++) {
        std::cout << unsigned(d_[j][i]) << " , ";
      }
      std::cout << "}" << std::endl;
    }
    // for (int i = 0; i < c_; i++) {
    //   std::cout << "{";
    //   for (int j = 0; j < r_; j++) {
    //     std::cout << unsigned(d_[i][j]) << " , ";
    //   }
    //   std::cout << "}" << std::endl;
    // }
    std::cout << "}" << std::endl;
  }
  template <unsigned int X>
  _MatrixBase<T, R, X> operator*(const& _MatrixBase<T, C, X> other) {
    _MatrixBase<T, R, X> output{};
  }

 private:
  const int r_{R};
  const int c_{C};
};

using mat3x3 = _MatrixBase<int, 3, 3>;
using mat4x3 = _MatrixBase<int, 4, 3>;
using mat3x4 = _MatrixBase<int, 3, 4>;

}  // namespace swm