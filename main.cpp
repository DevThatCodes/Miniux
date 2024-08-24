#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include "headers/json.hpp"
#include "headers/signin.hpp"
using json = nlohmann::json;

int main(int argc, char* argv[])
{
	SignIn signin;
	std::string usrnm;
	if (argc==2) {
		usrnm=argv[1];
	} else if (argc==1) {
	usrnm = signin.signin();
	}
	if (usrnm == "syssd") {
		return 1;
	}
  std::ifstream f("Drive.json");
  json drvDat = json::parse(f);
	std::string cwd = "/";
	std::string usrIn;
	while (true) {
		std::cout << "\033[1;32m" + usrnm + "@" + (std::string) drvDat["osName"] + "\033[0m:\033[1;34m~" + cwd + "\033[0m$ ";
		getline(std::cin, usrIn);
		if (usrIn == "exit") {
			return 1;
		} else {
            std::string arg = "";
            std::vector<std::string> args;
            for (int i=0;i<usrIn.size();i++) {
                if (i==usrIn.size()-1) {
                    arg += usrIn[i];
                }
                if (usrIn[i]==' ' || i==usrIn.size()-1) {
                    args.push_back(arg);
                    arg = "";
                } else {
                    arg += usrIn[i];
                }
            }
            std::string cmd = "./pkgs/" + args[0] + ".min ";
            for (auto& arg : args) {
                cmd += arg + " ";
            }
			int rtrnCd = system(cmd.c_str());
		}
	}

	f.close();
	return 0;
}
