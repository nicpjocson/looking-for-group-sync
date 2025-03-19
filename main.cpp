#include "Driver.h"

int main()
{
    Driver driver;

    bool success = driver.getConfig();
    
    if (success)
    {
        driver.initialize();
        driver.run();
    }
}

