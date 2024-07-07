#include <iostream>
#include <string>
#include <fstream>
#include "json/json.hpp"
using json = nlohmann::json;

int main()
{

  std::ifstream f("MiniuxOS/test.json");
  json drvDat = json::parse(f);
  std::string usrNm;
  std::string inPswd;
  std::vector<std::string> usrArr = {};
  std::cout << "Welcome to " + (std::string) drvDat["osName"] << "\n";
  std::cout << "Please choose a user from the list:\n";
  for (auto& usr : drvDat["users"].items()) {
    std::cout << " " + usr.key() + "\n";
    usrArr.push_back(usr.key());
  }

  // username input
  std::cin >> usrNm;
    for (int i=0; i<usrArr.size(); i++) {
      if (usrArr[i] == usrNm){
        break;
      }
      if (i == usrArr.size() -1 and usrArr[i] != usrNm) {
        std::cout << "No user called \"" + usrNm + "\". Stopping system\n";
        return 1;
      }
    }
    std::cout << "Enter your password, " + usrNm + ": \n";
    std::cin >> inPswd;

    for (int j=0; j<usrArr.size(); j++) {
      if (inPswd == drvDat["users"][usrNm]["password"]) {
        std::cout << "Correct password, Welcome " + usrNm +"\n";
        break;
      } else if (inPswd != drvDat["users"][usrNm]["password"]) {
        std::cout << "Password incorrect. Stopping system\n";
        return 1;
      }
    }
  return 0;
}