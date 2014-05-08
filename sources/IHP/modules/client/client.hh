#ifndef CLIENT_HP
#define CLIENT_HP

#include <iostream>
#include <sstream>
#include <KSocket.hh>
#include <KThread.hpp>
#include <KMutex.hh>
#include <KModule.hpp>
#include "../../iClient.hpp"

using namespace std;
using namespace KNM;

/**
 * A default client class.
 * It does nothing.
 */
class 	client: public iClient
{
public:
	client();											/**< Should be the ONLY constructor. */
	~client();											/**< Destructor. */

	void 	configure(KSocket *, signed int, KLog *,
					  iFirewall *, KModule<iIDS>&);		/**< Configure client. */
	void 	*tmain(void *args);							/**< Thread main function. */

private:
	KSocket 		*isock;								/**< Client Input socket. */
	KSocket 		osock;								/**< Client Output socket. */
	signed int 		oport;								/**< Client Output port. */
	KLog 			*log;								/**< Log system instance. */
	KSocket::pool 	spot;								/**< Socket pool for I/O operations. */
	string 			name;								/**< Client 'name' for log readability. */
	iIDS 			*IDS;								/**< IDS instance. */
	iFirewall 		*firewall;							/**< Firewall instance. */
};

/**
 * Module factory.
 */
extern "C" iClient 	*build()
{
    return new client;
}

/**
 * Module destructor.
 */
extern "C" void 	destroy(iClient *_module)
{
	if (_module)
		delete _module;
}

#endif