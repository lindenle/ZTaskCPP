#ifndef __MANAGER_CONTAINER_HH__
#define __MANAGER_CONTAINER_HH__

#include "Manager.hpp"
#include <map>
#include <boost/shared_ptr.hpp>

class ManagerContainer
{
 
 public:
  ManagerContainer(){;}
  ~ManagerContainer(){;}

  typedef map<string,boost::shared_ptr<Manager> > ManagerMap;

  void add_manager(string name);
  void del_manager(string name);

  Manager::connection_t connect_client(Manager::signal_t::slot_function_type client, string name);
  void disconnect_client(Manager::connection_t client, string name);

  void select_manager(string name);
  void desel_manager(string name);

  bool check_manager(string name);
  
 private:
  bool _manager_exists(string name);
  ManagerMap _manager_map;
};
#endif //__MANAGER_CONTAINER_HH__
