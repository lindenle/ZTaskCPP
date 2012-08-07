#ifndef __MANAGER_CONTAINER_HPP__
#define __MANAGER_CONTAINER_HPP__

#include "Manager.hpp"
#include "ManagerContainerExceptions.hpp"

#include <map>
#include <boost/shared_ptr.hpp>

/// The ManagerContainer class is a singleton that manages all manager
/// classes. It allows adding, removing and setting the selection
/// state of a manager. It also allows clients to connect to a given
/// managers update signal.

class ManagerContainer
{
 public:

  /// return an instance of MangerContainer singleton, or create one if none exists.
  static ManagerContainer * Instance();
  
  /// destructor clears the map
  ~ManagerContainer(){ _manager_map.clear() ;}

  ///ManagerMap type declaration
  typedef map<string,boost::shared_ptr<Manager> > ManagerMap;

  /// add_manager : Add a new manager the manager is created.
  void add_manager(const string & name) throw(ManagerExists);

  /// del_manager : Delete a manager.
  void del_manager(const string & name) throw(ManagerNotExists);

  /// select_manager :  toggle the selected state to true for a manager.
  void select_manager(const string & name) throw(ManagerNotExists);

  /// set a list of managers to be selected.
  void select_managers(const vector<string> & list) throw(ManagerNotExists);

  /// desel_manager :  toggle the selected state to false for a manager.
  void desel_manager(const string & name) throw(ManagerNotExists);

  /// check_manager :  get the selection state of a manager.
  bool check_manager(const string & name) throw(ManagerNotExists);
  
  ///connect_client : connect a client slot to a manager signal specified by name.
  Manager::connection_t connect_client(Manager::signal_t::slot_function_type client, 
				       const string & name) throw(ManagerNotExists);

  ///disconnect_client : disconnect a client slot from a managare signal by name.
  void disconnect_client(Manager::connection_t client, const string & name) throw(ManagerNotExists);

private:

  /// constructor is private for a singleton
  ManagerContainer(){;}

  /// copy constructor is private for a singleton
  ManagerContainer(const ManagerContainer & mc);

  /// operator=() is private for a singleton
  ManagerContainer operator=(ManagerContainer);

  /// _manager_exists : private function to verify the existence of a manger in the map
  bool _manager_exists(const string & name);

  /// _manager_map : unique string id key to shared_ptr map. erasing the entry deletes the manager object.
  ManagerMap _manager_map;

  /// holds the instance of the singleton
  static ManagerContainer * _instance;

};
#endif //__MANAGER_CONTAINER_HPP__
