#include <iostream>

#include "person.hh"
#include "sorter.hh"
#include "key_sort.hh"

int
main( void )
{
  std::vector< person > persons;
  key_sort key_sort;

  switch( int key; std::cin >> key, key )
  {
    case 1u:
      key_sort = key_sort::NAME;
      break;

    case 2u:
      key_sort = key_sort::SURNAME;
      break;

    case 3u:
      key_sort = key_sort::NUMBER_PHONE;
      break;

    default:
      std::cerr << "Недопустимое значение номера колонки.\n";
      return 1;
  }

  for( person p; std::cin >> p; )
  {
    persons.push_back( p );
  }

  const sorter s{ persons };
  const std::vector< person > persons_sorted{ s.operator()( key_sort ) };

  for( auto& p : persons_sorted )
  {
    p.key_output( key_sort );
    std::cout << p << '\n';
  }
}