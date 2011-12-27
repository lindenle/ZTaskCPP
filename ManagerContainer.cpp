#include "ManagerContainer.hpp"

void ManagerContainer::add_manager(string name)
{
  if ( ! _manager_exists(name) )
    {
      boost::shared_ptr<Manager> manager(new Manager(name)); 
      _manager_map.insert(std::make_pair(name, manager));
    }
  // should we throw an exception if trying to add one that exist?
}

void ManagerContainer::del_manager(string name)
{
  // iterate over the map and remove it if exists
  if ( _manager_exists(name) )
    _manager_map.erase(_manager_map.find(name));
}

void ManagerContainer::select_manager(string name)
{
  if ( _manager_exists(name) )
    _manager_map.find(name)->second->set_selected(true);

  //here we need to also update all clients that are attached to this
  //manager

}

void ManagerContainer::desel_manager(string name)
{
  if ( _manager_exists(name) )
    _manager_map.find(name)->second->set_selected(false);
}

bool ManagerContainer::check_manager(string name)
{
  if ( _manager_exists(name) )
    return _manager_map.find(name)->second->get_selected();
  //here should be an exception if manager doesnot exist
  return false;
}

bool ManagerContainer::_manager_exists(string name)
{
  
  if ( _manager_map.find(name) != _manager_map.end() )
    {
      return true;
    }
  return false;
}

Manager::connection_t ManagerContainer::connect_client( Manager::signal_t::slot_function_type client, 
							 string name)
{
  if ( _manager_exists(name) )
    return _manager_map.find(name)->second->connect_client(client);

}

void ManagerContainer::disconnect_client(Manager::connection_t client, string name)
{
  if ( _manager_exists(name) )
    return _manager_map.find(name)->second->disconnect_client(client);

}
