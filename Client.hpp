#ifndef __CLIENT_HPP__
#define __CLIENT_HPP__

#include <string>
#include <iostream>

using namespace std;

class Client
{

public:
  
  Client(string name = "default" );
  
  ~Client(){;}
  
  void manager_update(bool selected, string name);
  
private:

  string _name;

};
#endif //__CLIENT_HPP__
