#include <bits/stdc++.h>

template <typename T>
class Program;


template <unsigned int memorySize, typename wordType>
class Computer
{
public:
  constexpr Computer() = default;

  template <typename T>
  static constexpr std::array<wordType, memorySize> &
  boot()
  {

    T::execute<memorySize, wordType>(mem);
    return mem;
  }

private:
  static std::array<wordType, memorySize> mem;
};


template <typename T>

class Program
{
  template <unsigned int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &mem)
  {}

public:
};

template <int Addr>
class Num
{
public:
  constexpr Num()
  {
    addrInClass = Addr;
  }
  static int addrInClass;
};

template <typename T>
class Mem
{
  constexpr Mem()
  {}
  static unsigned int
  getPos()
  {
    static_assert(T::addrInClass >= 0);
    return T::addrInClass;
  }
};

template <typename First, typename Second>
class Mov
{
public:
  static std::pair<int, int>
  execute()
  {
    return make_pair(First::getPos(), Second::getPos());
  }
};
