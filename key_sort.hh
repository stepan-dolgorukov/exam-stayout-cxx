#ifndef KEY_SORT_HH
#define KEY_SORT_HH

#include <cstdint>

enum class key_sort : std::uint8_t
{
  NAME = 0,
  SURNAME = 1,
  NUMBER_PHONE = 2,
  NONE = 3
};

#endif