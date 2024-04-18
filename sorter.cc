#include <vector>
#include <algorithm>
#include <functional>

#include "sorter.hh"

sorter::sorter( const std::vector< person >& persons )
  : _persons{ persons }
{

}

std::vector<person>
sorter::operator()( key_sort k )
{
  std::vector
    answer{ _persons };

  std::stable_sort( answer.begin(  ),
                    answer.end(  ),
                    comparator( k )   );

  return answer;
}

std::function<bool(person, person)>
sorter::comparator( key_sort key )
{
  switch( key )
  {
    case key_sort::NAME:
      return
        []( const person& left,
            const person& right )
        {
          return left.name() < right.name();
        };

    case key_sort::SURNAME:
      return
        []( const person& left,
            const person& right )
        {
          return left.surname() < right.surname();
        };

    case key_sort::NUMBER_PHONE:
      return
        []( const person& left,
            const person& right )
        {
          return left.number_phone() < right.number_phone();
        };
  }

  return
    []( const person& left,
        const person& right )
    {
      return false;
    };
}