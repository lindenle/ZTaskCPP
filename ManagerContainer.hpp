#ifndef __MANAGER_CONTAINER_HPP__
#define __MANAGER_CONTAINER_HPP__

#include "Manager.hpp"
#include "ManagerContainerExceptions.hpp"
#include <map>
#include <boost/shared_ptr.hpp>

/// The ManagerContainer class is a singleton that manages all manager
/// classes. It allows adding, removing and setting the selection
/// state of a manager. It also allows clients to connect to a given
/// manager.

class ManagerContainer
{
  // should this be a singleton?
 public:
  //  static ManagerContainer * _instance
  
  ManagerContainer(){;}

  ~ManagerContainer(){;}

  typedef map<string,boost::shared_ptr<Manager> > ManagerMap;

  /// add_manager : Add a new manager the manager is created.
  void add_manager(const string & name);

  /// del_manager : Delete a manager.
  void del_manager(const string & name);

  /// select_manager :  toggle the selected state to true for a manager.
  void select_manager(const string & name);

  /// desel_manager :  toggle the selected state to false for a manager.
  void desel_manager(const string & name);

  /// check_manager :  get the selection state of a manager.
  bool check_manager(const string & name);
  
  ///connect_client : connect a client slot to a manager signal specified by name.
  Manager::connection_t connect_client(Manager::signal_t::slot_function_type client, const string & name);

  ///disconnect_client : disconnect a client slot from a managare signal by name.
  void disconnect_client(Manager::connection_t client, const string & name);

 private:

  /// _manager_exists : provate function to verify the existence of a manger in the map
  bool _manager_exists(const string & name);

  /// _manager_map : unique string id key to shared_ptr map. erasing the entry deletes the manager object.
  ManagerMap _manager_map;

  /// _exists : exception to be thrown when a manager exists and shouldn't
  ManagerExists _exists;
  
  ///_not_exists : exception to be thrown when a manger does not exist and should.
  ManagerNotExists _not_exists;

};
#endif //__MANAGER_CONTAINER_HPP__
