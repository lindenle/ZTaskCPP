#include "ManagerContainer.hpp"

ManagerContainer * ManagerContainer::_instance = nullptr;

ManagerContainer * ManagerContainer::Instance()
{
  if ( ! _instance )
    _instance = new ManagerContainer();

  return _instance;
}
      
void ManagerContainer::add_manager(const string& name) throw(ManagerExists)
{
  if ( ! _manager_exists(name) )
    {
      boost::shared_ptr<Manager> manager(new Manager(name)); 
      _manager_map.insert(std::make_pair(name, manager));
    }
  else
    throw(new ManagerExists());
}

void ManagerContainer::del_manager(const string& name) throw(ManagerNotExists)
{
  // iterate over the map and remove it if exists
  if ( _manager_exists(name) )
    _manager_map.erase(_manager_map.find(name));
  else
    throw(new ManagerNotExists() );
}

void ManagerContainer::select_manager(const string & name) throw(ManagerNotExists)
{
  if ( _manager_exists(name) )
    _manager_map.find(name)->second->set_selected(true);
  else
    throw(new ManagerNotExists());
}

void ManagerContainer::select_managers(const vector<string> & list) throw(ManagerNotExists)
{
  //first deselect all
  auto miter = _manager_map.begin();
  for ( ; miter != _manager_map.end(); miter++ )
    {
	  desel_manager(miter->first); 
    }
  //then select those in the list
  auto liter = list.begin();
  for ( ; liter != list.end(); liter++ )
    {
      try 
	{
	  select_manager(*liter); 
	}
      catch ( ... )
	{
	  throw(new ManagerNotExists());
	}
    }
    
}

void ManagerContainer::desel_manager(const string & name) throw(ManagerNotExists)
{
  if ( _manager_exists(name) )
    _manager_map.find(name)->second->set_selected(false);
  else
    throw(new ManagerNotExists());
}

bool ManagerContainer::check_manager(const string & name) throw(ManagerNotExists)
{
  if ( _manager_exists(name) )
    return _manager_map.find(name)->second->get_selected();
  else
    throw(new ManagerNotExists());
}


Manager::connection_t ManagerContainer::connect_client( Manager::signal_t::slot_function_type client, 
							 const string & name) throw(ManagerNotExists)
{
  if ( _manager_exists(name) )
    return _manager_map.find(name)->second->connect_client(client);
  else
    throw(new ManagerNotExists());
}

void ManagerContainer::disconnect_client(Manager::connection_t client, 
					 const string & name) throw(ManagerNotExists)
{
  if ( _manager_exists(name) )
    return _manager_map.find(name)->second->disconnect_client(client);
  else
    throw (new ManagerNotExists());
}

bool ManagerContainer::_manager_exists(const string & name) 
{
  
  if ( _manager_map.find(name) != _manager_map.end() )
    {
      return true;
    }
  return false;
}
