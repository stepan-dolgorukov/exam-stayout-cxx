#include <string_view>
#include <utility>

#include "person.hh"

person::person( std::string_view name,
                std::string_view surname,
                std::string_view number_phone )

  : _name{ name },
    _surname{ surname },
    _number_phone{ number_phone }
{

}

person::person( const person& p )

  : _name{ p.name(  ) },
    _surname{ p.surname(  ) },
    _number_phone{ p.number_phone(  ) }
{

}

person::person( person&& p )

  : _name{ std::move( p._name ) },
    _surname{ std::move( p._surname ) },
    _number_phone{ std::move( p._surname) }
{

}

std::string
person::name( void ) const
{
  return _name;
}

std::string
person::surname( void ) const
{
  return _surname;
}

std::string
person::number_phone( void ) const
{
  return _number_phone;
}

bool
person::operator==( const person& p ) const
{
  return
    name() == p.name() &&
    surname() == p.surname() &&
    number_phone() == p.number_phone();
}

person&
person::operator=( const person& p )
{
  _name = p.name();
  _surname = p.surname();
  _number_phone = p.number_phone();

  return *this;
}