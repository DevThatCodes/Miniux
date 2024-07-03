#include <iostream>
#include <string>
#include <fstream>

int main()
{

  std::string osOut;
  std::string osOutCl;
  std::string name;
  int dblQuotId;
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
        std::cout << "\n------> " + name + " <------\n";
        osOutCl = "\n------> " + name + " <------\n";
      }
      name = "";
      name += c;
    }
  }
  osInfo.close();
  std::cout << osOutCl;

  
  return 0;
}