#pragma once
#include <iostream>

void assert(bool assertion, const char* message)
{
    if (!assertion)
    {
        std::cout << "error: " << message << std::endl;
        exit(1);
    }
}
