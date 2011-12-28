#ifndef __MANAGER_CONTAINER_EXCEPTIONS_HPP__
#define __MANAGER_CONTAINER_EXCEPTIONS_HPP__

#include <exception>

class ManagerExists: public exception
{
  virtual const char* what() const throw()
  {
    return "Manager exists";
  }
};

class ManagerNotExists: public exception
{
  virtual const char* what() const throw()
  {
    return "Manager does not exist";
  }
};

#endif // __MANAGER_CONTAINER_EXCEPTIONS_HPP__
