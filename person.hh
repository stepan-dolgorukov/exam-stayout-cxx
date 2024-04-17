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
  operator==( const person& p );

  person&
  operator=( const person& p );
};

#endif