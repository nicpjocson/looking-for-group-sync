#include "Driver.h"

int main()
{
    Driver driver;
    bool foo = driver.inputValidation();

    if (foo)
    {
        driver.initialize();
        driver.run();
    }
}

