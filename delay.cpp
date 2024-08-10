#include <iostream>
#include "inc/delay.h"

void delay_us(uint32_t us_)
{
    std::cout << "delay_us: " << us_ << std::endl;
}

uint32_t time_us()
{
    std::cout << "time_us" << std::endl;
    return 100000000;
}
