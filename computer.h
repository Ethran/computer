#include <bits/stdc++.h>

#define COUNT_OF(x) \
  ((sizeof(x) / sizeof(0 [x])) / ((size_t)(!(sizeof(x) % sizeof(0 [x])))))

template <class Instruction, class... Rest>
class Program;
template <auto Addr>
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
  strLen(const char *const test)
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
    auto len = strLen(varName);

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


  template <typename T>
  constexpr void
  setFlagsZF(T arg)
  {
    ;
    ;
    ;
    ;
  }
  template <typename T>
  constexpr void
  setFlagsSF(T arg)
  {
    ;
    ;
    ;
    ;
  }
} // namespace

constexpr unsigned long long
Id(const char *varName)
{
  auto len = strLen(varName);

  unsigned long long result = 0;
  assert(::check(varName));

  for (unsigned int i = 0; i < len; ++i)
    {
      char it = varName[i];
      if (it >= 'a' && it <= 'z')
        {
          it -= 32;
        }
      result |= it;
      result <<= 8;
    }

  return result;
}


template <auto Addr>
class Num
{
public:
  constexpr static const typeOfIterator addrInClass = Addr;



  template <unsigned long int memorySize, typename wordType>
  static constexpr typeOfIterator
  getRValue([[maybe_unused]] const std::array<wordType, memorySize> &mem,
            [[maybe_unused]] const std::array<unsigned long long, memorySize>
              &                                    variables,
            [[maybe_unused]] const typeOfIterator &iterator)
  {
    return addrInClass;
  }
};



template <unsigned long long varNumber>
class Lea
{
public:
  template <unsigned long int memorySize, typename wordType>
  constexpr static typeOfIterator
  getRValue([[maybe_unused]] const std::array<wordType, memorySize> &mem,
            std::array<unsigned long long, memorySize> &             variables,
            typeOfIterator &                                         iterator)
  {
    bool           ifExist = false;
    typeOfIterator result  = -1;
    assert(varNumber != 0);
    for (unsigned int i = 0; i < memorySize; ++i)
      {
        if (variables[i] == varNumber)
          {
            result  = i;
            ifExist = true;
            break;
          }
      }
    if (!ifExist)
      {
        variables[iterator] = varNumber;
        result              = iterator;
        ++iterator;
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
  getLValue(std::array<wordType, memorySize> &          mem,
            std::array<unsigned long long, memorySize> &variables,
            typeOfIterator &                            iterator)
  {
    const auto result =
      NumOrLea::template getRValue<memorySize, wordType>(mem,
                                                         variables,
                                                         iterator);
    assert(result >= 0);
    assert(result < static_cast<typeOfIterator>(memorySize));

    return mem[result];
  }

  template <unsigned long int memorySize, typename wordType>
  static constexpr wordType
  getRValue(std::array<wordType, memorySize> &          mem,
            std::array<unsigned long long, memorySize> &variables,
            typeOfIterator &                            iterator)
  {
    const auto result =
      NumOrLea::template getRValue<memorySize, wordType>(mem,
                                                         variables,
                                                         iterator);
    assert(result >= 0);
    assert(result < static_cast<typeOfIterator>(memorySize));

    return mem[result];
  }
};



template <typename First, typename Second>
class Mov
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    First::template getLValue<memorySize, wordType>(mem, variables, iterator) =
      Second::template getRValue<memorySize, wordType>(mem,
                                                       variables,
                                                       iterator);
  }
};

template <unsigned long long varNumber, typename Second>
class D
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    auto &result =
      Mem<Lea<varNumber>>::template getLValue<memorySize, wordType>(mem,
                                                                    variables,
                                                                    iterator);
    const auto parSec =
      Second::template getRValue<memorySize, wordType>(mem,
                                                       variables,
                                                       iterator);
    result = parSec;
  }
};



template <typename FirstLValue, typename SecondPValue>
class Add
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    auto &result =
      FirstLValue::template getLValue<memorySize, wordType>(mem,
                                                            variables,
                                                            iterator);
    const auto parSec =
      SecondPValue::template getRValue<memorySize, wordType>(mem,
                                                             variables,
                                                             iterator);
    result += parSec;

    ::template setFlagsZF<wordType>(result);
    ::template setFlagsSF<wordType>(result);
  }
};



template <typename FirstLValue>
class Inc
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    auto &result =
      FirstLValue::template getLValue<memorySize, wordType>(mem,
                                                            variables,
                                                            iterator);
    ++result;


    ::template setFlagsZF<wordType>(result);
    ::template setFlagsSF<wordType>(result);
  }
};


template <typename FirstLValue, typename SecondPValue>
class Sub
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    auto &result =
      FirstLValue::template getLValue<memorySize, wordType>(mem,
                                                            variables,
                                                            iterator);
    const auto parSec =
      SecondPValue::template getRValue<memorySize, wordType>(mem,
                                                             variables,
                                                             iterator);
    result -= parSec;


    ::template setFlagsZF<wordType>(result);
    ::template setFlagsSF<wordType>(result);
  }
};



template <typename FirstLValue>
class Dec
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    auto &result =
      FirstLValue::template getLValue<memorySize, wordType>(mem,
                                                            variables,
                                                            iterator);

    --result;

    ::template setFlagsZF<wordType>(result);
    ::template setFlagsSF<wordType>(result);
  }
};


template <typename FirstLValue, typename SecondPValue>
class And
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    auto &result =
      FirstLValue::template getLValue<memorySize, wordType>(mem,
                                                            variables,
                                                            iterator);

    const auto parSec =
      SecondPValue::template getRValue<memorySize, wordType>(mem,
                                                             variables,
                                                             iterator);

    result &= parSec;

    ::template setFlagsZF<wordType>(result);
  }
};


template <typename FirstLValue, typename SecondPValue>
class Or
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    auto &result =
      FirstLValue::template getLValue<memorySize, wordType>(mem,
                                                            variables,
                                                            iterator);

    const auto parSec =
      SecondPValue::template getRValue<memorySize, wordType>(mem,
                                                             variables,
                                                             iterator);

    result |= parSec;

    ::template setFlagsZF<wordType>(result);
  }
};
template <typename FirstLValue>
class Not
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    auto &result =
      FirstLValue::template getLValue<memorySize, wordType>(mem,
                                                            variables,
                                                            iterator);



    result = ~result;

    ::template setFlagsZF<wordType>(result);
  }
};


template <typename FirstPValue, typename SecondPValue>
class Cmp
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  execute(std::array<wordType, memorySize> &          mem,
          std::array<unsigned long long, memorySize> &variables,
          typeOfIterator &                            iterator)
  {
    auto result =
      FirstPValue::template getPValue<memorySize, wordType>(mem,
                                                            variables,
                                                            iterator);
    const auto parSec =
      SecondPValue::template getRValue<memorySize, wordType>(mem,
                                                             variables,
                                                             iterator);
    result -= parSec;


    ::template setFlagsZF<wordType>(result);
    ::template setFlagsSF<wordType>(result);
  }
};



template <typename Instruction>

class Program<Instruction>
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  run(std::array<wordType, memorySize> &          mem,
      std::array<unsigned long long, memorySize> &variables,
      typeOfIterator &                            iterator)
  {
    Instruction::template execute<memorySize, wordType>(mem,
                                                        variables,
                                                        iterator);
  }
};

template <typename Instruction, typename... Rest>

class Program
{
public:
  template <unsigned long int memorySize, typename wordType>
  static constexpr void
  run(std::array<wordType, memorySize> &          mem,
      std::array<unsigned long long, memorySize> &variables,
      typeOfIterator &                            iterator)
  {
    Instruction::template execute<memorySize, wordType>(mem,
                                                        variables,
                                                        iterator);
    return Program<Rest...>::template run<memorySize, wordType>(mem,
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
    std::array<wordType, memorySize>           mem       = {};
    std::array<unsigned long long, memorySize> variables = {};
    typeOfIterator                             iterator  = 0;
    for (auto &it : mem)
      {
        it = 0;
      }
    Program::template run<memorySize, wordType>(mem, variables, iterator);
    return mem;
  }

private:
};
