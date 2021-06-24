#include <bits/stdc++.h>


template <unsigned int memorySize, typename wordType>
class Computer
{
public:
  constexpr Computer() = default;
  template <typename T>
  constexpr void
  boot(T &arg)
  {
    for (auto &it : mem)
      {
        it = 0;
      }
  }

private:
  std::array<wordType, memorySize> mem;
};
template <typename T>
class Program
{};

template <int Addr>
class Num
{
public:
  constexpr Num()
  {
    addrPrivate = Addr;
  }

private:
  static int addrPrivate;
};

template <Num Addr>
class Mem
{
  constexpr Mem()
  {}
};