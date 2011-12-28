#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include <string>
#include <boost/signal.hpp>

using namespace std;

class Manager 
{
 public:

  typedef boost::signal<void (bool enabled, string name )> signal_t;

  typedef boost::signals::connection connection_t;

  Manager(string name="default"):  
    _selected(false)
  {
    set_name(name);
  }

  ~Manager(){;}

  /// get_name : retrieve the name of the manager
  const string get_name(void){return _name;}

  /// set_name : set the name of the manager
  void set_name(const string & name){ _name=name; }

  /// get_selected :get the selection state of the manager
  const bool get_selected(void);

  /// set_selected : set the selection state of the manger
  void set_selected(const bool & selected);

  /// connect_client : connect a client slot to the update signal of the manager
  connection_t connect_client (signal_t::slot_function_type client);

  /// disconnect_client : disconnect a client slot to the update signal of the manager
  void disconnect_client(connection_t client);

 private:

  ///_selected : selection state of the manager
  bool _selected;
  
  /// _name : name of the manager
  string _name;

  /// _signal : the selection state update signal 
  signal_t _signal;

};

#endif // __MANAGER_HPP__
