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

  for ( int i=0; i < 10000; i++ )
    {
      cout << "====Iteration " << i << endl;

      ManagerContainer * mc = ManagerContainer::Instance();
      
      vector<string> names = {
	"alex",
	"thomas",
	"timo",
	"kaley",
	"qannik",
	"marbles",
	"foo",
	"bar"
      };
      
      
      auto iter = names.begin();
      
      for ( ; iter != names.end(); iter++)
	{
	  try
	    {
	      mc->add_manager(*iter);
	    }
	  catch ( ManagerExists _error )
	    {
	      std::cerr << "could not add so deleting " << *iter << std::endl;
	      try
		{
		  mc->del_manager(*iter);
		}
	      catch ( ManagerNotExists _error )
		{
		  std::cerr << "something is wrong" << *iter << std::endl;
		  return -1;
		}

	      continue;
	    }

	  boost::shared_ptr<Client> c1(new Client("Client-one"));	  
	  boost::shared_ptr<Client> c2(new Client("Client-two"));
	  boost::shared_ptr<Client> c3(new Client("Client-three"));
	  
	  try 
	    {
	      mc->connect_client(boost::bind(&Client::manager_update,c1,_1,_2), *iter);
	      mc->connect_client(boost::bind(&Client::manager_update,c2,_1,_2), *iter);
	      mc->connect_client(boost::bind(&Client::manager_update,c3,_1,_2), *iter);
	    }
	  catch (ManagerNotExists _error )
	    {
	      std::cerr << "Could not connect" << std::endl;
	      return -1;
	    }
	    
	  
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
	  try 
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
	  catch (ManagerNotExists _error )
	    {
	      cerr << "Cannot check if not in list" << endl;
	    }
	}

      names.clear();
      cout << "Testing list set" << endl;
      
      vector<string> sel_names = {
	"kaley",
	"qannik",
	"marbles",
	"foo"
      };
      
      try
	{
	  mc->select_managers(sel_names);
	}
      catch (ManagerNotExists _error )
	{
	  cerr << "Skipping add by list" << endl;
	}
      sel_names.clear();
      
    }
}
