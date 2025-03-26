# Looking for Group Synchronization  
This project simulates a Looking for Group (LFG) queueing system commonly found in MMORPGs. It focuses on concurrent thread execution while ensuring deadlock and starvation avoidance.  
  
## Features  
* Supports up to 4,294,967,295 Dungeons and Players per role.  
* A standard Party consists of 1 Tank, 1 Healer, and 3 DPS.  
* Dungeons continuously serve new Parties after the previous one clears.  
* Simulated dungeon clearing using sleep-based delays.  
* Once a Party clears a Dungeon, it does not requeue, while the Dungeon remains available for new Parties.  
  
### Program configuration  
The following parameters can be modified in `config.txt`:  
1. **n** - Maximum number of concurrent dungeon instances  
2. **t** - Number of Tank players in the queue  
3. **h** - Number of Healer players in the queue  
4. **d** - Number of DPS players in the queue  
5. **t1** - Minimum time (in seconds) before a Dungeon instance is finished  
6. **t2** - Maximum time (in seconds) before a Dungeon instance is finished  
  
## Output  
The program outputs the following details:  
### Dungeons  
  * **ID** - Unique identifier of each Dungeon  
  * **Status** – Indicates whether the Dungeon is active (currently occupied by a Party) or empty (waiting for a new Party) 
  * **Parties** served - Number of Parties that completed the Dungeon  
  * **Total time** served - Accumulated time spent serving Parties  
### Leftover players  
  * **Tanks** – Number of Tanks remaining in the queue
  * **Healers** – Number of Healers remaining in the queue
  * **DPS** – Number of DPS remaining in the queue
  
## Compilation and Execution Instructions  
### Command Line Interface (CLI)  
1. Install [msys2](https://www.msys2.org/) and ensure `msys64\mingw64\bin` and `msys64\ucrt64\bin` are added to your system's **Path** environment variable.  
2. Open a command line interface.  
3. Navigate to the project folder using the `cd` command.  
4. Run `main.bat` to compile and execute the program.

### Visual Studio  
1. Install **Visual Studio 2022** with C++20 support.  
2. Open `looking-for-group-sync.sln` in the project folder.
3. Build and run the program using **Local Windows Debugger**.  
  