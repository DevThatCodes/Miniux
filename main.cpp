#include <iostream>
#include <string>
#include <fstream>
#include "headers/json.hpp"
#include "headers/signin.hpp"
using json = nlohmann::json;

int main()
{
	SignIn signin;
	std::string usrnm = signin.signin();
	if (usrnm == "syssd") {
		return 1;
	}
  std::ifstream f("Drive.json");
  json drvDat = json::parse(f);
	std::string cwd = "/";
	std::string usrIn;
	while (true) {
		std::cout << "\033[1;32m" + usrnm + "@" + (std::string) drvDat["osName"] + "\033[0m:\033[1;34m~" + cwd + "\033[0m$ ";
		std::cin >> usrIn;
		if (usrIn == "exit") {
			return 1;
		} else {
			std::string cmdStr = "./pkgs/" + usrIn + ".min " + usrnm + " " + cwd;
			const char* cmd = cmdStr.c_str();
			int rtrnCd = system(cmd);
		}
	}

	return 0;
}