#include "Driver.h"

int main()
{
    Driver driver;
    
    if (driver.getConfig()) {
        driver.initialize();
        driver.run();
    }
}

