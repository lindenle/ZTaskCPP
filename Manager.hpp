#ifndef __MANAGER_HH__
#define __MANAGER_HH__

#include <string>

using namespace std;

class Manager 
{
 public:

  //typedef vector<Client> ClientList;

  Manager():  
    _selected(false)
  {;}
  ~Manager(){;}
  const bool get_selected(void){return _selected;}
  void set_selected(bool s){_selected = s;}
  //  void add_client(Client client);
  //  void rm_client(Client

 private:
  bool _selected;
  string _name;
  //ClientList _clients;
};

#endif // __MANAGER_HH__
