#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"
#include <iostream>
#include "src/Math/ModInt.hpp"
#include "src/LinearAlgebra/SparseMatrix.hpp"
#include "src/LinearAlgebra/MinimalPolynomial.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 using Mint= ModInt<998244353>;
 int N, K;
 cin >> N >> K;
 SparseMatrix<Mint> M(N, N);
 for (int i= 0; i < K; i++) {
  int a, b, c;
  cin >> a >> b >> c;
  M.add_component(a, b, c);
 }
 cout << det(M) << '\n';
 return 0;
}