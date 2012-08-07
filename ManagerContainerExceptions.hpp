#ifndef __MANAGER_CONTAINER_EXCEPTIONS_HPP__
#define __MANAGER_CONTAINER_EXCEPTIONS_HPP__

#include <exception>

/// ManagerNotExists is an exception to throw when a manager does
/// exist in the ManagerContainer map but shouldn't.

class ManagerExists: public exception
{

  /// describes the error that was encountered
  virtual const char* what() const throw()
  {
    return "Manager exists";
  }

};

/// ManagerNotExists is an exception to throw when a manager does not
/// exist in the ManagerContainer map but should.

class ManagerNotExists: public exception
{
  virtual const char* what() const throw()
  {
    /// describes the error that was encountered
    return "Manager does not exist";
  }
};

#endif // __MANAGER_CONTAINER_EXCEPTIONS_HPP__
