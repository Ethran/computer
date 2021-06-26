#include <bits/stdc++.h>

template <typename T>
class Program;
template <int Addr>
class Num;
template <typename T>
class Mem;
template <typename First, typename Second>
class Mov;



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
public:
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



template <typename T>

class Program
{
public:
  template <unsigned int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &mem)
  {}

  static void
  inna_funkcja()
  {
    ;
    ;
    ;
  }
};

template <unsigned int memorySize, typename wordType>
class Computer
{
public:
  constexpr Computer() = default;

  template <typename T>
  static constexpr const std::array<wordType, memorySize> &
  boot()
  {
    Program<Mov<Mem<Num<0>>, Num<42>>>::execute<memorySize, wordType>(mem);
    T::execute(mem);
    T::execute<memorySize, wordType>(mem);

    return mem;
  }

private:
  static std::array<wordType, memorySize> mem;
};
