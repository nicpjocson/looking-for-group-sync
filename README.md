# Looking for Group Synchronization  
This program is a synchronization project simulating a Looking for Group queueing system commonly found in an MMORPG. It focuses on concurrently running threads while avoiding deadlocks and starvation.  

## Features  
The program can instantiate a maximum of 4,294,967,295 Dungeons and Players for each role. A standard Party of 5 contains 1 Tank, 1 Healer, and 3 DPS. To simulate a dungeon clear, a sleep is used. Once a Party clears a Dungeon, the Party does not queue again, while the Dungeon may serve another Party.

### Program configuration  
The following parameters can be modified in `config.txt`:  
    (1) n  - max. no. of concurrent instances  
    (2) t  - no. of tank players in the queue  
    (3) h  - no. of healer players in the queue  
    (4) d  - no. of DPS players in the queue  
    (5) t1 - min. time before an instance is finished  
    (6) t2 - max. time before an instance is finished  

## Compilation and Execution Instructions  
### Visual Studio  
1. Install Visual Studio 2022 with a support for C++20.  
2. Open the file `looking-for-group-sync.sln`.  
3. Build and run the program using the `Local Windows Debugger`.  
  