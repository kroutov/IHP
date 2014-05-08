/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-04-29 11:25:25
* @Last update   : 2014-05-04 15:50:43
*/

#include <KError.hh>
#include "server.hh"

int 		main(int ac, char **av)
{
	server 	endpoint(12000, 12001);

	try
	{
		endpoint.configure(ac, av);
		endpoint.start();
	}
	catch(KError *error)
	{
		error->dump();
		return 1;
	}
	return(0);
}