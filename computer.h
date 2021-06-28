#include <bits/stdc++.h>

#define COUNT_OF(x) \
  ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

template <typename T>
class Program;
template <int Addr>
class Num;
template <typename T>
class Mem;
template <typename First, typename Second>
class Mov;
namespace
{
  constexpr unsigned int  maxSize   = 10;
  constexpr long long int sizeOfMem = 0;

  using typeOfIterator = long int;
  // https://stackoverflow.com/questions/16505417/input-c-style-string-and-get-the-length
  constexpr unsigned int
  strlen(const char *test)
  {
    const char *p   = test;
    unsigned    len = 0;
    while (*p != '\0')
      {
        len++;
        p++;
      }
    return len;
  }


  constexpr bool
  check(const char *varName)
  {
    auto len = strlen(varName);
    if (len == 0)
      return false;
    if (len > 6)
      return false;
    for (unsigned int i = 0; i < len; ++i)
      {
        char it = varName[i];
        if (it >= 'a' && it <= 'z')
          continue;
        if (it >= 'A' && it <= 'Z')
          continue;
        if (it >= '0' && it <= '9')
          continue;
        return false;
      }
    return true;
  }
} // namespace

constexpr const char *
Id(const char *varName)
{
  return varName;
}


template <int Addr>
class Num
{
public:
  constexpr static const typeOfIterator addrInClass = Addr;



  template <unsigned long int memorySize, typename wordType>
  static constexpr const typeOfIterator
  getValue([[maybe_unused]] std::array<wordType, memorySize> &mem,
           [[maybe_unused]] std::array<char *, memorySize> &  variables,
           [[maybe_unused]] int &                             iterator)
  {
    return addrInClass;
  }
  template <unsigned long int memorySize>
  static constexpr typeOfIterator
  findIndex([[maybe_unused]] std::array<char *, memorySize> &variables,
            [[maybe_unused]] int &                           iterator)
  {
    return addrInClass;
  }
};



template <const char *varName>
class Lea
{
public:
  template <unsigned long int memorySize>
  static constexpr typeOfIterator
  findIndex(std::array<char *, memorySize> &variables, int &iterator)
  {
    bool           ifExist = false;
    typeOfIterator result  = -1;
    if (check(varName))
      {
        for (const auto &it : variables)
          {
            if (strcmp(it, varName))
              {
                result  = variables.begin() - &it;
                ifExist = true;
                break;
              }
          }
        if (!ifExist)
          {
            variables[iterator] = varName;
            result              = iterator;
            ++iterator;
          }
      }
    return result;
  }
};


template <typename NumOrLea>
class Mem
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr wordType &
  getValue(std::array<wordType, memorySize> &mem,
           std::array<char *, memorySize> &  variables,
           int &                             iterator)
  {
    auto result = NumOrLea::template findIndex<memorySize>(variables, iterator);
    // static_assert(result >= 0);
    // static_assert(result < memorySize);
    return mem[result];
  }
};



template <typename First, typename Second>
class Mov
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &mem,
          std::array<char *, memorySize> &  variables,
          int &                             iterator)
  {
    First::template getValue<memorySize, wordType>(mem, variables, iterator) =
      Second::template getValue<memorySize, wordType>(mem, variables, iterator);
  }
};



template <typename Instruction>

class Program
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  run(std::array<wordType, memorySize> &mem,
      std::array<char *, memorySize> &  variables,
      int &                             iterator)
  {
    Instruction::template execute<memorySize, wordType>(mem,
                                                        variables,
                                                        iterator);
  }
};



template <unsigned long int memorySize, typename wordType>
class Computer
{
public:
  constexpr Computer() = default;

  template <typename Program>
  static constexpr const std::array<wordType, memorySize>
  boot()
  {
    std::array<wordType, memorySize> mem       = {};
    std::array<char *, memorySize>   variables = {};
    int                              iterator  = 0;
    for (auto &it : mem)
      {
        it = 0;
      }
    Program::template run<memorySize, wordType>(mem, variables, iterator);
    return mem;
  }

private:
};
