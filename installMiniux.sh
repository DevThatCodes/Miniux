#!/bin/bash

usrnm=""
dsplnm=""
pswd=""
osIndex=""
miniDistros=("Miniuntu" "Miniux Mint" "Minian" "Tinyjaro" "Microarch")
mkdir MiniuxOS
cd MiniuxOS
echo "Welcome to the Miniux installer!"
read -p "Please enter a new username> " usrnm
read -p "Please enter a displayname> " dsplnm
read -p "Please enter a password for ${usrnm}> " pswd
echo "Please choose a distro:"
for i in ${!miniDistros[@]}; do
    echo "${i}: ${miniDistros[$i]}"
done
read -p "> " osIndex
touch Drive.json
echo "
{
    \"osName\": \"${miniDistros[osIndex]} v0.04\",
    \"users\": {
        \"${usrnm}\": {
            \"dsplName\": \"${dsplnm}\",
            \"password\": \"${pswd}\",
            \"files\": {
                \"type\": \"directory\",
                \"content\": {

                }
            }
        }
    }
}
" >> Drive.json
clear
echo "Starting install!"
wget https://github.com/DevThatCodes/Miniux/releases/download/v0.04-alpha/miniux.o  
chmod +x miniux.o
mkdir pkgs
cd pkgs
wget https://github.com/DevThatCodes/Miniux/releases/download/v0.04-alpha/minipack.min
clear
echo "Done installing Miniux!
To run miniux, run the command: \"cd MiniuxOS && ./miniux.o\""
