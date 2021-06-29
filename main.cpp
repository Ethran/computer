#include <bits/stdc++.h>

#include <array>

#include "computer.h"

// Operator == dla std::array jest constexpr dopiero od C++20.
template <class T, std::size_t N>
constexpr bool
compare(std::array<T, N> const &arg1, std::array<T, N> const &arg2)
{
  for (std::size_t i = 0; i < N; ++i)
    if (arg1[i] != arg2[i])
      return false;
  return true;
}



using part0  = Mov<Mem<Num<0>>, Num<42>>;
using part0a = Mov<Mem<Num<2>>, Num<42>>;


using tmpasm_move = Program<part0>;



using part1 = Mov<Mem<Lea<Id("09aZ")>>, Num<-1>>;

using test1 = Program<part1>;



using part2  = D<Id("abd"), Num<-21>>;
using part2b = D<Id("aabd"), Num<-22>>;
using part2c = D<Id("aabad"), Num<-23>>;



using test2 = Program<part2>;



using test3 = Program<part2, part0a, part1>;

using test4f = Program<part2, part0a, part1, part0, part2b, part2c>;

int
main()
{
  static_assert(compare(Computer<1, int8_t>::boot<tmpasm_move>(),
                        std::array<int8_t, 1>({42})),
                "Failed [tmpasp_move].");
  static_assert(compare(Computer<1, int8_t>::boot<test1>(),
                        std::array<int8_t, 1>({-1})),
                "Failed [test1].");
  static_assert(compare(Computer<1, int8_t>::boot<test2>(),
                        std::array<int8_t, 1>({-21})),
                "Failed [test2].");


  static_assert(compare(Computer<3, int8_t>::boot<test3>(),
                        std::array<int8_t, 3>({-21, -1, 42})),
                "Failed [test3].");

  /*
    auto tmp = Computer<3, int>::boot<test4f>();
    for (const auto &it : tmp)
      {
        std::cout << it << "\n";
      }*/
}
