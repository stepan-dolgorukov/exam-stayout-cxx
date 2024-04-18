#ifndef PERSON_HH
#define PERSON_HH

#include <string>
#include <string_view>

#include "key_sort.hh"

class person
{
private:

  std::string
    _name{},
    _surname{},
    _number_phone{};

  mutable key_sort _key_output{ key_sort::NONE };

  template< typename stream_output >
  friend stream_output&
  operator<<( stream_output& s, const person& p )
  {
    if( p._key_output == key_sort::NAME )
    {
      s <<
        p.name(  ) << ' ' <<
        p.surname(  ) << ": " <<
        p.number_phone(  );
    }

    else if( p._key_output == key_sort::SURNAME )
    {
      s <<
        p.surname(  ) << ' ' <<
        p.name(  ) << ": " <<
        p.number_phone(  );
    }

    else if( p._key_output == key_sort::NUMBER_PHONE )
    {
      s <<
        p.number_phone(  ) << ": " <<
        p.surname(  ) << ' ' <<
        p.name(  );
    }

    else
    {
      s <<
        p.name(  ) << ' ' <<
        p.surname(  ) << ' ' <<
        p.number_phone(  );
    }

    return s;
  }

  template< typename stream_input >
  friend stream_input&
  operator>>( stream_input& s, person& p )
  {
    s >> p._surname >> p._name >> p._number_phone;

    // Удаление «:».
    p._name.erase( p._name.end() - 1 );
    return s;
  }

public:

  person( void ) = default;

  person( std::string_view name,
          std::string_view surname,
          std::string_view number_phone );

  person( const person& p );

  person( person&& p );

  std::string
  name( void ) const;

  std::string
  surname( void ) const;

  std::string
  number_phone( void ) const;

  void
  key_output( key_sort k ) const;

  bool
  operator==( const person& p ) const;

  person&
  operator=( const person& p );
};

#endif