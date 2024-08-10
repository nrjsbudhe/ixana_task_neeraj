#include <iostream>
#include "inc/board.h"
#include "inc/coms.h"
#include "inc/delay.h"
#include "inc/gpio.hpp"

void initialze_pins()
{
    gpio_out_t nRST = {PIN_NRST};
    while (nRST.init(PUPD::PUPD_NONE, OUT::OUT_PUSHPULL) != true)
    {
        std::cout << "Error: nRST.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "nRST.init succeeded" << std::endl;

    gpio_out_t nTEST = {PIN_NTEST};
    while (nTEST.init(PUPD::PUPD_NONE, OUT::OUT_PUSHPULL) != true)
    {
        std::cout << "Error: nTEST.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "nTEST.init succeeded" << std::endl;

    gpio_in_t DONE = {PIN_DONE};
    while (DONE.init(PUPD::PUPD_UP) != true)
    {
        std::cout << "Error: DONE.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "DONE.init succeeded" << std::endl;

    gpio_in_t SUCCESS = {PIN_SUCCESS};
    while (SUCCESS.init(PUPD::PUPD_UP) != true)
    {
        std::cout << "Error: SUCCESS.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "SUCCESS.init succeeded" << std::endl;

    gpio_out_t CTRL = {PIN_CTRL};
    while (CTRL.init(PUPD::PUPD_NONE, OUT::OUT_PUSHPULL) != true)
    {
        std::cout << "Error: CTRL.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "CTRL.init succeeded" << std::endl;

    gpio_out_t SELECT = {PIN_SELECT};
    while (SELECT.init(PUPD::PUPD_NONE, OUT::OUT_PUSHPULL) != true)
    {
        std::cout << "Error: SELECT.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "SELECT.init succeeded" << std::endl;

}

int main()
{
    initialze_pins();

}

