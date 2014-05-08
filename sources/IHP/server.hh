/* 
* @Author        : Jean-Philippe Clipffel
* @Creation date : 2014-04-29 11:48:55
* @Last update   : 2014-05-06 11:58:27
*/

#include <signal.h>
#include <string>
#include <KSocket.hh>
#include <KConfig.hh>
#include <KModule.hpp>
#include <KLog.hh>
#include <KError.hh>
#include "iClient.hpp"
#include "iFirewall.hpp"
#include "iIDS.hpp"

using namespace std;
using namespace KNM;

#define IPORT_DFLT 		12000
#define OPORT_DFLT		21
#define LOGFILE_DFLT	"server.log"

class 	server
{
public:
	server();							/**< Default constructor. */
	server(const string &);				/**< Construct with a configuration file path. */
	server(signed int, signed int);		/**< Specify ports. */
	~server();							/**< Destructor. */

	void 	setConf(const string &);	/**< Set configuration file path. */
	void 	configure(int, char**);		/**< (auto)Configure the server. */
	void 	start();					/**< Start the server. */

private:
	signed int 			iport;
	signed int 			oport;
	KSocket 			insock;
	KSocket 			outsock;
	KConfig 			config;
	string 				cfgpath;
	KLog 				logfile;
	KModule<iClient> 	modClient;
	KModule<iFirewall>	modFirewall;
	KModule<iIDS>		modIDS;
};