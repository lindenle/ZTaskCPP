#include "ManagerContainer.hpp"
#include "Client.hpp"

#include <vector>
#include <boost/scoped_ptr.hpp>
#include <boost/bind.hpp>
#include <cstdlib>

using namespace std;

int main()
{

  for ( int i = 0 ; i < 3; i++ )
    {
      cout << "==== loop " << i << " =====" << endl;
      boost::scoped_ptr<ManagerContainer> mc(new ManagerContainer);

      vector<string> names;
      
      names.push_back("alex");
      names.push_back("alex");
      names.push_back("thomas");
      names.push_back("timo");
      names.push_back("kaley");
      names.push_back("qannik");
      names.push_back("marbles");

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
	      cout << *iter << " is selected " << endl; 
	    }
	  else
	    {
	      cout << *iter << " is not selected " << endl; 
	    }
	}
      names.clear();
    }
}
