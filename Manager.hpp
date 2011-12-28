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

  const string get_name(void){return _name;}
  void set_name(string name){_name=name;}

  const bool get_selected(void);
  void set_selected(bool selected);

  connection_t connect_client (signal_t::slot_function_type client);
  void disconnect_client(connection_t client);

 private:
  bool _selected;
  string _name;
  signal_t _signal;

};

#endif // __MANAGER_HPP__
