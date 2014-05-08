/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-05-05 14:18:42
* @Last update   : 2014-05-05 20:24:40
*/

#ifndef IFIREWALL_HPP
#define IFIREWALL_HPP

#include <string.h>
#include <KError.hh>
#include <KSocket.hh>
#include <KSocket_pool.hh>
#include <KLog.hh>

using namespace KNM;

/**
 * Firewall interface.
 * Firewall check connection validity.
 */
class 	iFirewall
{
public:
	iFirewall(){};
	virtual ~iFirewall(){};

	virtual void 	configure(const string &) = 0;	/**< Configure firewall. */	  
	virtual bool 	check(const string &) = 0;		/**< Check if an IP address is valid. */
};

#endif