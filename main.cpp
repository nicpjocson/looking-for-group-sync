#include "DungeonManager.h"

int main()
{
    DungeonManager DungeonManager;
    
    if (DungeonManager.getConfig())
    {
        DungeonManager.initialize();
        DungeonManager.run();
    }
}

