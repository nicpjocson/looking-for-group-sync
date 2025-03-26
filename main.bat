IF EXIST main.o DEL /F main.o
IF EXIST main.exe DEL /F main.exe
g++ -std=c++20 -c main.cpp Driver.cpp Dungeon.cpp DungeonManager.cpp PartyManager.cpp
g++ -std=c++20 -Wall main.o Driver.o Dungeon.o DungeonManager.o PartyManager.o -o main
IF EXIST main.exe cls
IF EXIST main.exe CALL main.exe