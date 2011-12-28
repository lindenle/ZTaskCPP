#include "Manager.hpp"

const bool Manager::get_selected(void)
{
  return _selected;
}

void Manager::set_selected(const bool & selected)
{
  _selected = selected;
  _signal(_selected,_name);
}

Manager::connection_t Manager::connect_client(signal_t::slot_function_type client)
{
  return _signal.connect(client);
}

void Manager::disconnect_client(connection_t client)
{
  client.disconnect();
}


