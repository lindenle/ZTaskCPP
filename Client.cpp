#include "Client.hpp"

Client::Client(string name )
{
  _name = name;
}


void Client::manager_update(bool selected, string name)
{
  cout << _name << ": "<< name << " is " ;
  if (!selected )
    cout << " not ";
  cout << "selected" << endl;
}
  
