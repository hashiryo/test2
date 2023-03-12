#define PROBLEM "https://yukicoder.me/problems/no/1750"
// 疎行列の行列累乗
#include <iostream>
#include "src/Math/ModInt.hpp"
#include "src/LinearAlgebra/SparseMatrix.hpp"
#include "src/LinearAlgebra/MinimalPolynomial.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 using Mint= ModInt<998244353>;
 long long N, M, T;
 cin >> N >> M >> T;
 SparseMatrix<Mint> mat(N, N);
 while (M--) {
  int s, t;
  cin >> s >> t;
  mat.add_component(s, t, 1);
  mat.add_component(t, s, 1);
 }
 Vector<Mint> vec(N);
 vec[0]= 1;
 cout << MinimalPolynomial(mat, vec).pow(T)[0] << '\n';
 return 0;
}