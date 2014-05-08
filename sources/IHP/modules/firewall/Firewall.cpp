#include			<iostream>
#include			<fstream>
#include			<string>
#include			<vector>
#include			"Firewall.hh"

using namespace std;

Firewall::Firewall()
{
  
}

Firewall::~Firewall()
{
  
}

void				Firewall::configure(const string& filePath)
{
  ifstream		readFile;
  string			lineRead;

  readFile.open(filePath.c_str());

  if (readFile.is_open())
  {
    while (!readFile.eof())
    {
      readFile >> lineRead;
      this->ipList.push_back(lineRead);
    }
  }
  else
    return;
  readFile.close();
}

bool				Firewall::check(const string& ip)
{
  if (ipList.size() == 0)
    return false;
  for (unsigned int i = 0; i < ipList.size() - 1; i++)
    {
      if (ip == ipList[i])
	return (true);
    }
  return (false);
}
