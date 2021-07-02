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


using test5 = Program<Add<Mem<Num<0>>, Num<4>>,
                      Add<Mem<Num<1>>, Num<4>>,
                      Add<Mem<Num<2>>, Num<4>>,
                      Add<Mem<Num<1>>, Num<-4>>,
                      Add<Mem<Num<2>>, Num<-4>>


                      >;
void
t202();


void
t203();
void
t204();
void
t205();

void
t400();
void
t500();
int
main()
{  constexpr auto error = Computer<11, int>::boot<Program<D<Id("a"), Mem<Num<0>>>>>();
  t202();
  t203();
  t204();
  t205();
  t400();
  static_assert(
    compare(Computer<3, int>::boot<test5>(), std::array<int, 3>({4, 0, 0})));
  /*
    auto tmp = Computer<3, int>::boot<test4f>();
    for (const auto &it : tmp)
      {
        std::cout << it << "\n";
      }*/
}
void
t500()
{
  struct test
  {
    using tmpasm_and = Program<D<Id("a"), Num<0xff>>,
                               D<Id("b"), Num<0xff>>,
                               D<Id("c"), Num<0xf0>>,
                               And<Mem<Num<0>>, Num<1>>,
                               And<Mem<Num<1>>, Num<13>>,
                               And<Mem<Num<2>>, Num<0x0f>>>;
    using tmpasm_or  = Program<D<Id("a"), Num<0>>,
                              D<Id("b"), Num<1>>,
                              D<Id("c"), Num<0xf0>>,
                              Or<Mem<Num<0>>, Num<1>>,
                              Or<Mem<Num<1>>, Num<13>>,
                              Or<Mem<Num<2>>, Num<0x0f>>>;
    using tmpasm_not = Program<D<Id("a"), Num<1>>,
                               D<Id("b"), Num<0xff>>,
                               D<Id("c"), Num<0xf0>>,
                               Not<Mem<Num<0>>>,
                               Not<Mem<Num<1>>>,
                               Not<Mem<Num<2>>>>;
  };

  static_assert(compare(Computer<3, int>::boot<test::tmpasm_and>(),
                        std::array<int, 3>({1, 13, 0})));

  static_assert(compare(Computer<3, int>::boot<test::tmpasm_or>(),
                        std::array<int, 3>({1, 13, 0xff})));

  static_assert(compare(Computer<3, uint8_t>::boot<test::tmpasm_not>(),
                        std::array<uint8_t, 3>({0xff - 1, 0, 0x0f})));

  static_assert(compare(Computer<3, uint16_t>::boot<test::tmpasm_not>(),
                        std::array<uint16_t, 3>({0xffff - 1, 0xff00, 0xff0f})));
}

void
t400()
{
  struct test
  {
    using tmpasm_add_inc = Program<D<Id("a"), Num<3>>,
                                   D<Id("b"), Num<3>>,
                                   D<Id("c"), Num<3>>,
                                   D<Id("d"), Num<3>>,
                                   D<Id("e"), Num<3>>,
                                   Add<Mem<Num<0>>, Num<2>>,
                                   Add<Mem<Num<1>>, Mem<Num<4>>>,
                                   Add<Mem<Num<2>>, Lea<Id("e")>>,
                                   Inc<Mem<Lea<Id("e")>>>>;
    using tmpasm_sub_dec = Program<D<Id("a"), Num<3>>,
                                   D<Id("b"), Num<3>>,
                                   D<Id("c"), Num<3>>,
                                   D<Id("d"), Num<3>>,
                                   D<Id("e"), Num<3>>,
                                   Sub<Mem<Num<0>>, Num<2>>,
                                   Sub<Mem<Num<1>>, Mem<Num<4>>>,
                                   Sub<Mem<Num<2>>, Lea<Id("e")>>,
                                   Dec<Mem<Lea<Id("e")>>>>;
    using tmpasm_mixed   = Program<D<Id("a"), Num<3>>,
                                 D<Id("b"), Num<3>>,
                                 D<Id("c"), Num<3>>,
                                 D<Id("d"), Num<3>>,
                                 D<Id("e"), Num<3>>,
                                 Add<Mem<Num<0>>, Num<2>>,
                                 Sub<Mem<Num<1>>, Mem<Num<4>>>,
                                 Add<Mem<Num<2>>, Mem<Num<4>>>,
                                 Sub<Mem<Num<2>>, Lea<Id("e")>>,
                                 Inc<Mem<Lea<Id("e")>>>,
                                 Dec<Mem<Lea<Id("e")>>>>;
    using tmpasm_min_max = Program<D<Id("a"), Num<127>>,
                                   D<Id("b"), Num<-128>>,
                                   D<Id("c"), Num<255>>,
                                   D<Id("d"), Num<0>>,
                                   D<Id("e"), Num<100>>,
                                   D<Id("f"), Num<100>>,
                                   Add<Mem<Num<0>>, Num<1>>,
                                   Sub<Mem<Num<1>>, Num<1>>,
                                   Add<Mem<Num<2>>, Num<1>>,
                                   Sub<Mem<Num<3>>, Num<1>>,
                                   Add<Mem<Num<4>>, Num<29>>,
                                   Add<Mem<Num<5>>, Num<156>>>;
  };

  static_assert(compare(Computer<8, int>::boot<test::tmpasm_add_inc>(),
                        std::array<int, 8>({5, 6, 7, 3, 4, 0, 0, 0})));

  static_assert(compare(Computer<8, int>::boot<test::tmpasm_sub_dec>(),
                        std::array<int, 8>({1, 0, -1, 3, 2, 0, 0, 0})));

  static_assert(compare(Computer<8, int>::boot<test::tmpasm_mixed>(),
                        std::array<int, 8>({5, 0, 2, 3, 3, 0, 0, 0})));

  static_assert(compare(Computer<6, int>::boot<test::tmpasm_min_max>(),
                        std::array<int, 6>({128, -129, 256, -1, 129, 256})));

  static_assert(compare(Computer<6, int8_t>::boot<test::tmpasm_min_max>(),
                        std::array<int8_t, 6>({-128, 127, 0, -1, -127, 0})));

  static_assert(compare(Computer<6, uint8_t>::boot<test::tmpasm_min_max>(),
                        std::array<uint8_t, 6>({128, 127, 0, 255, 129, 0})));
}
void
t205()
{
  struct test
  {
    using tmpasm_move_lea_1var = Program<D<Id("a"), Num<42>>,
                                         Mov<Mem<Num<1>>, Lea<Id("a")>>,
                                         Mov<Mem<Num<2>>, Mem<Lea<Id("a")>>>,
                                         Mov<Mem<Lea<Id("a")>>, Num<5>>>;
    using tmpasm_move_lea_3vars_read =
      Program<Mov<Mem<Num<5>>, Mem<Lea<Id("a")>>>,
              Mov<Mem<Num<6>>, Mem<Lea<Id("b")>>>,
              Mov<Mem<Num<7>>, Mem<Lea<Id("c")>>>,
              D<Id("a"), Num<7>>,
              D<Id("b"), Num<8>>,
              D<Id("c"), Num<9>>>;
    using tmpasm_move_lea_3vars_write =
      Program<Mov<Mem<Num<5>>, Mem<Lea<Id("a")>>>,
              D<Id("a"), Num<7>>,
              Mov<Mem<Num<6>>, Mem<Lea<Id("b")>>>,
              D<Id("b"), Num<8>>,
              Mov<Mem<Num<7>>, Mem<Lea<Id("c")>>>,
              Mov<Mem<Lea<Id("c")>>, Num<13>>,
              Mov<Mem<Lea<Id("b")>>, Num<14>>,
              D<Id("c"), Num<9>>,
              Mov<Mem<Lea<Id("a")>>, Num<14>>,
              Mov<Mem<Lea<Id("a")>>, Num<15>>>;
  };

  static_assert(compare(Computer<3, int>::boot<test::tmpasm_move_lea_1var>(),
                        std::array<int, 3>({5, 0, 42})));

  static_assert(
    compare(Computer<8, int>::boot<test::tmpasm_move_lea_3vars_read>(),
            std::array<int, 8>({7, 8, 9, 0, 0, 7, 8, 9})));

  static_assert(
    compare(Computer<8, int>::boot<test::tmpasm_move_lea_3vars_write>(),
            std::array<int, 8>({15, 14, 13, 0, 0, 7, 8, 9})));
}
void
t204()
{
  struct test
  {
    using tmpasm_move_mem     = Program<Mov<Mem<Num<1>>, Num<2>>,
                                    Mov<Mem<Num<2>>, Num<9>>,
                                    Mov<Mem<Num<3>>, Mem<Num<1>>>,
                                    Mov<Mem<Num<4>>, Mem<Num<2>>>>;
    using tmpasm_move_mem_mem = Program<Mov<Mem<Num<0>>, Num<1>>,
                                        Mov<Mem<Num<1>>, Num<2>>,
                                        Mov<Mem<Num<2>>, Num<9>>,
                                        Mov<Mem<Num<3>>, Mem<Num<1>>>,
                                        Mov<Mem<Num<4>>, Mem<Num<2>>>,
                                        Mov<Mem<Num<5>>, Mem<Mem<Num<0>>>>,
                                        Mov<Mem<Mem<Num<0>>>, Num<42>>>;
  };

  static_assert(compare(Computer<8, int>::boot<test::tmpasm_move_mem>(),
                        std::array<int, 8>({0, 2, 9, 2, 9, 0, 0, 0})));

  static_assert(compare(Computer<8, int>::boot<test::tmpasm_move_mem_mem>(),
                        std::array<int, 8>({1, 42, 9, 2, 9, 2, 0, 0})));


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


  static_assert(Id("abcdef") == Id("ABCDEF"));
  static_assert(Id("0") == Id("0"));
  static_assert(Id("0") != Id("000"));
  static_assert(Id("012345") == Id("012345"));
  static_assert(Id("zz") == Id("ZZ"));
  static_assert(Id("a") != Id("aa"));
  static_assert(Id("A") != Id("AA"));
  static_assert(Id("z") != Id("zz"));
  static_assert(Id("Z") != Id("ZZ"));
  static_assert(Id("9") != Id("Z"));
}
void
t203()
{
  struct test
  {
    using tmpasm_1var       = Program<D<Id("a"), Num<42>>>;
    using tmpasm_10diffvars = Program<D<Id("a1"), Num<1>>,
                                      D<Id("a2"), Num<2>>,
                                      D<Id("a3"), Num<3>>,
                                      D<Id("a4"), Num<4>>,
                                      D<Id("a5"), Num<5>>,
                                      D<Id("a6"), Num<6>>,
                                      D<Id("a7"), Num<7>>,
                                      D<Id("a8"), Num<8>>,
                                      D<Id("a9"), Num<9>>,
                                      D<Id("a10"), Num<10>>>;
    using tmpasm_10samevars = Program<D<Id("a"), Num<42>>,
                                      D<Id("a"), Num<42>>,
                                      D<Id("a"), Num<42>>,
                                      D<Id("a"), Num<42>>,
                                      D<Id("a"), Num<42>>,
                                      D<Id("a"), Num<42>>,
                                      D<Id("a"), Num<42>>,
                                      D<Id("a"), Num<42>>,
                                      D<Id("a"), Num<42>>,
                                      D<Id("a"), Num<42>>>;
  };

  static_assert(
    compare(Computer<11, int>::boot<test::tmpasm_1var>(),
            std::array<int, 11>({42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})));

  static_assert(
    compare(Computer<11, int>::boot<test::tmpasm_10diffvars>(),
            std::array<int, 11>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0})));

  static_assert(Computer<11, int>::boot<test::tmpasm_10samevars>()[10] == 0);

  static_assert(compare(Computer<1, int>::boot<test::tmpasm_1var>(),
                        std::array<int, 1>({42})));

  static_assert(compare(Computer<10, int>::boot<test::tmpasm_10diffvars>(),
                        std::array<int, 10>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10})));
}


void
t202()
{
  struct test
  {
    using tmpasm_neg1 = Program<D<Id("a"), Num<-1>>>;
    using tmpasm_129  = Program<D<Id("a"), Num<129>>>;
    using tmpasm_255  = Program<D<Id("a"), Num<255>>>;
    using tmpasm_256  = Program<D<Id("a"), Num<256>>>;
    using tmpasm_max  = Program<D<Id("a"), Num<UINT64_MAX>>>;
    using tmpasm_min  = Program<D<Id("a"), Num<INT64_MIN>>>;
  };

  static_assert(compare(Computer<1, int8_t>::boot<test::tmpasm_neg1>(),
                        std::array<int8_t, 1>({-1})));

  static_assert(compare(Computer<1, uint8_t>::boot<test::tmpasm_neg1>(),
                        std::array<uint8_t, 1>({255})));

  static_assert(compare(Computer<1, int8_t>::boot<test::tmpasm_129>(),
                        std::array<int8_t, 1>({-127})));

  static_assert(compare(Computer<1, uint8_t>::boot<test::tmpasm_129>(),
                        std::array<uint8_t, 1>({129})));

  static_assert(compare(Computer<1, int8_t>::boot<test::tmpasm_255>(),
                        std::array<int8_t, 1>({-1})));

  static_assert(compare(Computer<1, uint8_t>::boot<test::tmpasm_255>(),
                        std::array<uint8_t, 1>({255})));

  static_assert(compare(Computer<1, int8_t>::boot<test::tmpasm_256>(),
                        std::array<int8_t, 1>({0})));

  static_assert(compare(Computer<1, uint8_t>::boot<test::tmpasm_256>(),
                        std::array<uint8_t, 1>({0})));

  static_assert(compare(Computer<1, int16_t>::boot<test::tmpasm_256>(),
                        std::array<int16_t, 1>({256})));

  static_assert(compare(Computer<1, int32_t>::boot<test::tmpasm_256>(),
                        std::array<int32_t, 1>({256})));

  static_assert(compare(Computer<1, int64_t>::boot<test::tmpasm_256>(),
                        std::array<int64_t, 1>({256})));

  static_assert(compare(Computer<1, uint8_t>::boot<test::tmpasm_max>(),
                        std::array<uint8_t, 1>({UINT8_MAX})));

  static_assert(compare(Computer<1, int8_t>::boot<test::tmpasm_max>(),
                        std::array<int8_t, 1>({-1})));

  static_assert(compare(Computer<1, uint16_t>::boot<test::tmpasm_max>(),
                        std::array<uint16_t, 1>({UINT16_MAX})));

  static_assert(compare(Computer<1, uint32_t>::boot<test::tmpasm_max>(),
                        std::array<uint32_t, 1>({UINT32_MAX})));

  static_assert(compare(Computer<1, uint64_t>::boot<test::tmpasm_max>(),
                        std::array<uint64_t, 1>({UINT64_MAX})));

  static_assert(compare(Computer<1, int64_t>::boot<test::tmpasm_min>(),
                        std::array<int64_t, 1>({INT64_MIN})));

  static_assert(compare(Computer<1, uint64_t>::boot<test::tmpasm_min>(),
                        std::array<uint64_t, 1>({9223372036854775808U})));

  static_assert(compare(Computer<1, int16_t>::boot<test::tmpasm_min>(),
                        std::array<int16_t, 1>({0})));

  static_assert(compare(Computer<1, uint16_t>::boot<test::tmpasm_min>(),
                        std::array<uint16_t, 1>({0})));
}

void
fail()
{
  /*
  constexpr auto error = Computer<11, int>::boot<Program<D<Id(""),
  Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("abcdefg"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("0123456"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a!"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a@"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a#"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a$"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a%"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a^"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a&"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a*"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a("), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a "), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a_"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a-"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a+"), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a."), Num<42>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a,"), Num<42>>>>();

  // Niepoprawne Num oraz D - nie powinny się kompilować.
  constexpr auto error = Computer<11, int>::boot<Program<D<Id("a"),
  Num<>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a"), Num<Num<1>>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a"), Lea<Id("a")>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<D<Id("a"), Mem<Num<0>>>>>();

  // Niepoprawne Mov, Mem, Lea - nie powinno się kompilować.

  constexpr auto error =
    Computer<11, int>::boot<Program<Mov<Num<1>, Num<2>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<Mov<Lea<Id("a")>, Num<2>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<Mov<Id("a"), Num<2>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<Mov<Mem<Num<7>>, Id("a")>>>();
  constexpr auto error =
    Computer<11, int>::boot<Program<Mov<Mem<Num<7>>, Lea<Num<2>>>>>();

  constexpr auto error =
    Computer<11, int>::boot<Program<Mov<Mem<7>, Num<2>>>>();

    // Odwołanie poza pamięć - nie powinno się kompilować.
    constexpr auto error =
      Computer<11, int>::boot<Program<Mov<Mem<Num<100>>, Num<2>>>>();*/
}