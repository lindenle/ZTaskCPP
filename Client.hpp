#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <string>
#include <iostream>

using namespace std;

/// Client class example. The client is required to have one member
/// function that takes a boolean and a string. This slot function can
/// be connected to a managers update signal through the
/// ManagerContainer or through the Manager directly.

class Client
{

public:

  /// constructor with one parameter, the name of the client.
  Client(string name = "default" );
  
  /// destructor
  ~Client(){;}

  /// slot for signal connection
  void manager_update(bool selected, string name);
  
private:

  /// client name
  string _name;

};
#endif //__CLIENT_HPP__
