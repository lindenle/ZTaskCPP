#include "Manager.hpp"
#include "Client.hpp"

#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>

int main()
{

  boost::shared_ptr<Manager> m(new Manager("alex"));
  boost::shared_ptr<Client> c(new Client("client"));
  m->connect_client(boost::bind(&Client::manager_update,c,_1,_2));

}
