#include <vector>
#include <algorithm>
#include <functional>

#include "sorter.hh"

sorter::sorter( const std::vector< person >& persons )
  : _persons{ persons }
{

}

std::vector<person>
sorter::operator()( key_sort k ) const
{
  if( k == key_sort::NONE )
  {
    return _persons;
  }

  std::vector
    answer{ _persons };

  std::stable_sort( answer.begin(  ),
                    answer.end(  ),
                    comparator( k )   );

  return answer;
}

std::function<bool(person, person)>
sorter::comparator( key_sort key ) const
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
          const auto
            number_phone_left{ left.number_phone() },
            number_phone_right{ right.number_phone() };

          if( number_phone_left.size() == number_phone_right.size() )
          {
            return number_phone_left <= number_phone_right;
          }

          if ( number_phone_left.size() < number_phone_right.size() )
          {
            return true;
          }

          return false;
        };
  }

  return
    []( const person& left,
        const person& right )
    {
      return false;
    };
}