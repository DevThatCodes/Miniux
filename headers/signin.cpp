#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
#include "signin.hpp"
using json = nlohmann::json;

std::string SignIn::signin()
{

  std::ifstream f("Drive.json");
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
        std::cout << "\033[1;31mNo user called \"" + usrNm + "\". Stopping system\033[0m\n";
        return "syssd";
      }
    }
    std::cout << "Enter your password, " + usrNm + ": \n";
    std::cin >> inPswd;

    for (int j=0; j<usrArr.size(); j++) {
      if (inPswd == drvDat["users"][usrNm]["password"]) {
        std::cout << "Correct password, Welcome " + usrNm +"\n";
        break;
      } else if (inPswd != drvDat["users"][usrNm]["password"]) {
        std::cout << "\033[1;31mPassword incorrect. Stopping system\n\033[0m";
        return "syssd";
      }
    }
  return usrNm;
}