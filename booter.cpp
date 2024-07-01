#include <iostream>
#include <string>
#include <fstream>



int main() {

  std::string osOut;
  std::string osOutCl;
  std::ifstream osInfo("/etc/os-release");

  while ( getline(osInfo, osOut) ) {
    std::cout << osOut;
    osOutCl += osOut + "\n";
  }

  std::cout << "\n\n osOut:\n";
  std::cout << osOutCl;


  return 0;
}