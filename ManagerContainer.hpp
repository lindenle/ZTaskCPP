#ifndef __MANAGER_CONTAINER_HPP__
#define __MANAGER_CONTAINER_HPP__

#include "Manager.hpp"
#include <map>
#include <boost/shared_ptr.hpp>

/// The ManagerContainer class is a singleton that manages all manager
/// classes. It allows adding, removing and setting the selection
/// state of a manager. It also allows clients to connect to a given
/// manager.

class ManagerContainer
{
 public:

  ManagerContainer(){;}
  ~ManagerContainer(){;}

  typedef map<string,boost::shared_ptr<Manager> > ManagerMap;

  /// add_manager : Add a new manager the manager is created .
  void add_manager(string name);

  /// del_manager : Delete a manager.
  void del_manager(string name);

  Manager::connection_t connect_client(Manager::signal_t::slot_function_type client, string name);
  void disconnect_client(Manager::connection_t client, string name);

  void select_manager(string name);
  void desel_manager(string name);

  bool check_manager(string name);
  
 private:
  ///
  bool _manager_exists(string name);
  ManagerMap _manager_map;
};
#endif //__MANAGER_CONTAINER_HPP__
