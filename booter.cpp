#include <iostream>
#include <string>
#include <fstream>
#include "json/json.hpp"
using json = nlohmann::json;

int main()
{

  std::ifstream f("test.json");
  json drvDat = json::parse(f);
  std::cout << "Welcome to " + (std::string) drvDat["osName"] << "\n";
  std::cout << "Please choose a user from the list:";
  std::cout << drvDat["users"];

  return 0;
}