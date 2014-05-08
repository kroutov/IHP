/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-05-05 14:18:42
* @Last update   : 2014-05-06 12:34:31
*/

#ifndef ICLIENT_HPP
#define ICLIENT_HPP

#include <string.h>
#include <KError.hh>
#include <KSocket.hh>
#include <KSocket_pool.hh>
#include <KThread.hpp>
#include <KLog.hh>
//#include <KModule.hpp>
#include "iFirewall.hpp"
#include "iIDS.hpp"

using namespace KNM;

/**
 * Client interface.
 * Client act as an intelligent proxy and IDS.
 */
class 	iClient: public KThread<>
{
public:
	iClient(){};
	virtual ~iClient(){};

	virtual void 	configure(KSocket *, signed int, KLog *,
							  iFirewall *, KModule<iIDS>&) = 0;		/**< Configure client. */
							  
	virtual void 	*tmain(void *) = 0;								/**< Thread entry point. */
};

#endif