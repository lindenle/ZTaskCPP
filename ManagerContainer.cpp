#include "ManagerContainer.hpp"

void ManagerContainer::add_manager(const string& name)
{
  try 
    {
      
      if ( ! _manager_exists(name) )
	{
	  boost::shared_ptr<Manager> manager(new Manager(name)); 
	  _manager_map.insert(std::make_pair(name, manager));
	}
      else
	throw(_exists);
    }
  catch(exception& e)
    {
      cerr << name << " " << e.what() << endl;
    }
}

void ManagerContainer::del_manager(const string& name)
{
  // iterate over the map and remove it if exists
  try 
    {     
      if ( _manager_exists(name) )
	_manager_map.erase(_manager_map.find(name));
      else
	throw(_not_exists);
    }
  catch ( exception & e )
    {
      cerr << name << " " << e.what() << endl;
    }
}

void ManagerContainer::select_manager(const string & name)
{
  try 
    {     
      if ( _manager_exists(name) )
	_manager_map.find(name)->second->set_selected(true);
      else
	throw(_not_exists);
    }
  catch ( exception & e )
    {
      cerr << name << " " << e.what() << endl;
    }

}

void ManagerContainer::desel_manager(const string & name)
{
  try 
    {
      if ( _manager_exists(name) )
	_manager_map.find(name)->second->set_selected(false);
      else
	throw(_not_exists);
    }
  catch (exception & e )
    {
      cerr << name << " " << e.what() << endl;
    }
}

bool ManagerContainer::check_manager(const string & name)
{
  try 
    {
      
      if ( _manager_exists(name) )
	return _manager_map.find(name)->second->get_selected();
      else
	throw(_not_exists);
    }
  catch ( exception &e )
    {
      cerr << name << " " << e.what() << endl; 
    }
}


Manager::connection_t ManagerContainer::connect_client( Manager::signal_t::slot_function_type client, 
							 const string & name)
{
  try 
    {
      if ( _manager_exists(name) )
	return _manager_map.find(name)->second->connect_client(client);
      else
	throw( _not_exists );
    }
  catch ( exception & e ) 
    {
      cerr << name << " " << e.what() << endl; 
    }
}

void ManagerContainer::disconnect_client(Manager::connection_t client, 
					 const string & name)
{
  try 
    {
      if ( _manager_exists(name) )
	return _manager_map.find(name)->second->disconnect_client(client);
      else
	throw (_not_exists);
    }
  catch ( exception &e )
    {
      cerr << name << " " << e.what() << endl; 
    }
}

bool ManagerContainer::_manager_exists(const string & name)
{
  
  if ( _manager_map.find(name) != _manager_map.end() )
    {
      return true;
    }
  return false;
}
