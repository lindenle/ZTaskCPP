#ifndef __MANAGER_CONTAINER_HH__
#define __MANAGER_CONTAINER_HH__

#include "Manager.hh"
#include <map>
#include <boost/shared_ptr.hpp>

class ManagerContainer
{
 
 public:
  ManagerContainer(){;}
  ~ManagerContainer(){;}

  typedef map<string,boost::shared_ptr<Manager> > ManagerMap;

  void add_manager(string name);
  // void add_client(Client client, string manager);
  //  void rm_client(Client client, string manager);
  void del_manager(string name);
  void select_manager(string name);
  void desel_manager(string name);
  bool check_manager(string name);
  
 private:
  bool _manager_exists(string name);
  ManagerMap _manager_map;
};
#endif //__MANAGER_CONTAINER_HH__
