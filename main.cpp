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
	std::string cwd = usrnm + "@" + (std::string) drvDat["osName"];
	std::string usrIn;
	while (true) {
		std::cout << cwd + "> ";
		std::cin >> usrIn;
		if (usrIn == "exit") {
			return 1;
		}
	}

	return 0;
}