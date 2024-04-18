#ifndef SORTER_HH
#define SORTER_HH

#include <vector>
#include <functional>

#include "person.hh"
#include "key_sort.hh"

class sorter
{
private:

  std::vector< person > _persons{};

  std::function< bool( person, person ) >
  comparator( key_sort key ) const;

public:

  sorter( void ) = delete;

  sorter( const std::vector< person >& persons );

  std::vector<person>
  operator()( key_sort k ) const;
};

#endif