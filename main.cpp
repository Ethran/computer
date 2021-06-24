
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

using test1 = Mem<Num<0>>;

// using tmpasm_move = Program<Mem<Num<0>>>;


int
main()
{
  std::cout << "Hello World" << std::endl;

  // static_assert(compare(Computer<1, int8_t>::boot<tmpasm_move>(),
  ///              std::array<int8_t, 1>({42})),
  ///     "Failed [tmpasp_move].");
}