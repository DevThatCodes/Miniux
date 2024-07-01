#include <iostream>
#include <string>
#include <fstream>

int main()
{

  std::string osOut;
  std::string osOutCl;
  std::string name;
  int dblQuotId;
  bool namTim = false;
  std::ifstream osInfo("/etc/os-release");

  while (getline(osInfo, osOut))
  {
    osOutCl += osOut + "\n";
  }

  for (char &c : osOutCl)
  {
    if (c == '"')
    {
      c=' ';
      dblQuotId += 1;
      std::cout << name;
      std::cout << "|\"|";
      if (dblQuotId==4)
      {
        osOutCl = "\n------> " + name + " <------\n";
      }
      name = "";
      name += c;
    }
  }
  std::cout << osOutCl;

  osInfo.close();
  return 0;
}