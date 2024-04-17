#ifndef PERSON_HH
#define PERSON_HH

#include <string>
#include <string_view>

class person
{
private:

  std::string
    _name{},
    _surname{},
    _number_phone{};

  template< typename stream_output >
  friend stream_output&
  operator<<( stream_output& s, const person& p )
  {
    s << p.name(  ) << ' ' << p.surname(  ) << ' ' << p.number_phone(  );
    return s;
  }

public:

  person( void ) = delete;

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

  bool
  operator==( const person& p ) const;

  person&
  operator=( const person& p );
};

#endif