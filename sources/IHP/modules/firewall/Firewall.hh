#ifndef				_FIREWALL_HH_
# define			_FIREWALL_HH_

#include			"../../iFirewall.hpp"

using namespace std;

class				Firewall : public iFirewall
{

private:
  vector<string>		ipList;

public:
  Firewall();
  ~Firewall();

  void				configure(const string&);
  bool				check(const string&);

};

extern "C" iFirewall*		build()
{
  return new Firewall;
}

extern "C" void			destroy(iFirewall* _module)
{
  if (_module)
    delete _module;
}

#endif				/* _FIREWALL_HH_ */
