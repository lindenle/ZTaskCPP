#include "ManagerContainer.hpp"
#include "Client.hpp"

#include <vector>
#include <boost/scoped_ptr.hpp>
#include <boost/bind.hpp>
#include <cstdlib>

using namespace std;

/// tmc.cpp is a test of the features of the design

int main()
{

  ManagerContainer * mc = ManagerContainer::Instance();
  
  vector<string> names;
  
  names.push_back("alex");
  names.push_back("thomas");
  names.push_back("timo");
  names.push_back("kaley");
  names.push_back("qannik");
  names.push_back("marbles");
  names.push_back("boo");
  names.push_back("foo");
  names.push_back("bar");
  
  auto iter = names.begin();
  
  for ( ; iter != names.end(); iter++)
    {
      mc->add_manager(*iter);
      
      boost::shared_ptr<Client> c1(new Client("Client-one"));	  
      boost::shared_ptr<Client> c2(new Client("Client-two"));
      
      mc->connect_client(boost::bind(&Client::manager_update,c1,_1,_2), *iter);
      mc->connect_client(boost::bind(&Client::manager_update,c2,_1,_2), *iter);
      
      
      if ( ( rand() % 100 ) > 49 )
	{
	  mc->select_manager(*iter);
	}
      else
	{
	  mc->desel_manager(*iter);
	}
    }
  iter = names.begin();
  for ( ; iter != names.end(); iter++)
    {
      if ( mc->check_manager(*iter) )
	{
	  cout << "manager: " << *iter << " is selected " << endl; 
	}
      else
	{
	  cout << "manager: " << *iter << " is not selected " << endl; 
	}
    }

  cout << "Testing list set" << endl;

  vector<string> sel_names;
  sel_names.push_back("kaley");
  sel_names.push_back("qannik");
  sel_names.push_back("marbles");
  sel_names.push_back("boo");

  mc->select_managers(sel_names);
  
}
