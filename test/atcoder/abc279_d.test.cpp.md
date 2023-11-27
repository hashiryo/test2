---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/function_traits.hpp
    title: "\u95A2\u6570\u578B\u3084\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
      \u306B\u95A2\u3059\u308B\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Optimization/MinMaxEnum.hpp
    title: "\u6700\u5927\u6700\u5C0F\u3092\u6307\u5B9A\u3059\u308B\u305F\u3081\u306E\
      \u5217\u6319\u578B"
  - icon: ':heavy_check_mark:'
    path: src/Optimization/fibonacci_search.hpp
    title: "\u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://atcoder.jp/contests/abc279/tasks/abc279_d
    links:
    - https://atcoder.jp/contests/abc279/tasks/abc279_d
  bundledCode: "#line 1 \"test/atcoder/abc279_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc279/tasks/abc279_d\"\
    \n#define ERROR \"0.00000001\"\n#include <iostream>\n#include <iomanip>\n#include\
    \ <cmath>\n#line 2 \"src/Optimization/fibonacci_search.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#line 2 \"src/Internal/function_traits.hpp\"\n#include <type_traits>\n\
    // clang-format off\nnamespace function_template_internal{\ntemplate<class C>struct\
    \ is_function_object{\n template<class U,int dummy=(&U::operator(),0)> static\
    \ std::true_type check(U *);\n static std::false_type check(...);\n static C *m;\n\
    \ static constexpr bool value= decltype(check(m))::value;\n};\ntemplate<class\
    \ F,bool,bool>struct function_type_impl{using type= void;};\ntemplate<class F>struct\
    \ function_type_impl<F,true,false>{using type= F *;};\ntemplate<class F>struct\
    \ function_type_impl<F,false,true>{using type= decltype(&F::operator());};\ntemplate<class\
    \ F> using function_type_t= typename function_type_impl<F,std::is_function_v<F>,is_function_object<F>::value>::type;\n\
    template<class... Args>struct result_type_impl{using type= void;};\ntemplate<class\
    \ R,class... Args>struct result_type_impl<R(*)(Args...)>{using type= R;};\ntemplate<class\
    \ C,class R,class... Args>struct result_type_impl<R(C::*)(Args...)>{using type=\
    \ R;};\ntemplate<class C,class R,class... Args>struct result_type_impl<R(C::*)(Args...)const>{using\
    \ type= R;};\ntemplate<class F> using result_type_t= typename result_type_impl<function_type_t<F>>::type;\n\
    template<class... Args>struct argument_type_impl{using type= void;};\ntemplate<class\
    \ R,class... Args>struct argument_type_impl<R(*)(Args...)>{using type= std::tuple<Args...>;};\n\
    template<class C,class R,class... Args>struct argument_type_impl<R(C::*)(Args...)>{using\
    \ type= std::tuple<Args...>;};\ntemplate<class C,class R,class... Args>struct\
    \ argument_type_impl<R(C::*)(Args...)const>{using type= std::tuple<Args...>;};\n\
    template<class F> using argument_type_t= typename argument_type_impl<function_type_t<F>>::type;\n\
    }\nusing function_template_internal::result_type_t,function_template_internal::argument_type_t;\n\
    // clang-format on\n#line 2 \"src/Optimization/MinMaxEnum.hpp\"\nenum MinMaxEnum\
    \ { MAXIMIZE= -1, MINIMIZE= 1 };\n#line 6 \"src/Optimization/fibonacci_search.hpp\"\
    \n// [l,r]\ntemplate <MinMaxEnum obj, class F> std::pair<int64_t, result_type_t<F>>\
    \ fibonacci_search(const F &f, int64_t l, int64_t r) {\n assert(l <= r);\n int64_t\
    \ s= 1, t= 2, a= l - 1, x, b, y;\n for (int64_t e= r - l + 2; t < e;) std::swap(s+=\
    \ t, t);\n b= a + t, x= b - s;\n result_type_t<F> fx= f(x), fy;\n for (bool g;\
    \ a + b != 2 * x;) {\n  if (y= a + b - x; r < y) b= a, a= y;\n  else {\n   if\
    \ constexpr (obj == MINIMIZE) g= fx < (fy= f(y));\n   else g= fx > (fy= f(y));\n\
    \   if (g) b= a, a= y;\n   else a= x, x= y, fx= fy;\n  }\n }\n return {x, fx};\n\
    }\n#line 7 \"test/atcoder/abc279_d.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n long long A, B;\n cin >> A >> B;\n\
    \ auto f= [&](long long n) { return (long double)B * n + A / sqrt(n + 1); };\n\
    \ auto [x, fx]= fibonacci_search<MINIMIZE>(f, 0, 1e18);\n cout << fixed << setprecision(15)\
    \ << fx << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc279/tasks/abc279_d\"\n#define\
    \ ERROR \"0.00000001\"\n#include <iostream>\n#include <iomanip>\n#include <cmath>\n\
    #include \"src/Optimization/fibonacci_search.hpp\"\nusing namespace std;\nsigned\
    \ main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n long long A, B;\n cin >>\
    \ A >> B;\n auto f= [&](long long n) { return (long double)B * n + A / sqrt(n\
    \ + 1); };\n auto [x, fx]= fibonacci_search<MINIMIZE>(f, 0, 1e18);\n cout << fixed\
    \ << setprecision(15) << fx << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Optimization/fibonacci_search.hpp
  - src/Internal/function_traits.hpp
  - src/Optimization/MinMaxEnum.hpp
  isVerificationFile: true
  path: test/atcoder/abc279_d.test.cpp
  requiredBy: []
  timestamp: '2023-10-29 17:46:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc279_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc279_d.test.cpp
- /verify/test/atcoder/abc279_d.test.cpp.html
title: test/atcoder/abc279_d.test.cpp
---