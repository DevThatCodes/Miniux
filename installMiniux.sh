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
    \"osName\": \"${miniDistros[osIndex]}\",
    \"users\": {
        \"${usrnm}\": {
            \"dsplName\": \"${dsplnm}\",
            \"password\": \"${pswd}\"
        }
    }
}
" >> Drive.json
clear
echo "Starting install!"
wget https://github.com/DevThatCodes/Miniux/releases/download/v0.01-alpha/miniux.o  
chmod +x miniux.o
clear
echo "Done installing Miniux!
To run miniux, run the command: \"cd MiniuxOS && ./miniux.o\""