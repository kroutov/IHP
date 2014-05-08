/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-05-05 14:18:48
* @Last update   : 2014-05-05 20:23:52
*/

#ifndef IIDS_HPP
#define IIDS_HPP

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
class 	iIDS
{
public:
	iIDS(){};
	virtual ~iIDS(){};

	virtual void 	configure(const string &,
							  KLog *) = 0;			/**< Configure firewall. */	  
	
	virtual bool 	check(KSocket *) = 0;			/**< Check if a connection is valid. */
};

#endif