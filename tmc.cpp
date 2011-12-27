#include "ManagerContainer.hpp"

#include <vector>
#include <boost/scoped_ptr.hpp>
#include <cstdlib>

using namespace std;

struct client_one
{
  void operator()(bool selected,string name) const
  {
    cout << "client_one: " << name << " is ";
    if (selected)
      cout << "selected";
    else
      cout << "deselected";
    cout << endl;
  }
};

struct client_two
{
  void operator()(bool selected, string name) const
  {
    cout << "client_two: " << name << " is ";
    if (enabled)
      cout << "enabled";
    else
      cout << "deselected";
    cout << endl;
  }
};

int main()
{

  for ( int i = 0 ; i < 1000; i++ )
    {
      cout << "==== loop " << i << " =====" << endl;
      boost::scoped_ptr<ManagerContainer> mc(new ManagerContainer);

      vector<string> names;
      
      names.push_back("alex");
      names.push_back("thomas");
      names.push_back("timo");
      
      auto iter = names.begin();
      
      for ( ; iter != names.end(); iter++)
	{
	  mc->add_manager(*iter);
	  mc->connect_client(client_one(),*iter);
	  mc->connect_client(client_two(),*iter);
	  if ( ( rand() % 100 ) > 49 )
	    {
	      mc->select_manager(*iter);
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
