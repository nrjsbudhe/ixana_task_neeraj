#include <iostream>
#include "inc/board.h"
#include "inc/coms.h"
#include "inc/delay.h"
#include "inc/gpio.hpp"

void initialze_pins()
{   
    /*
        Initialize the board pins
    */
    std::cout << "Initializing the board pins" << std::endl;
    
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

    gpio_irq_t DONE = {PIN_DONE};
    while (DONE.init(PUPD::PUPD_UP,EDGE::EDGE_POSITIVE) != true)
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

void configure_mode_1()
{
    /*
        Configure the board for mode 1
    */
    std::cout << "Configuring the board for mode 1" << std::endl;

}

void configure_mode_2()
{
    /*
        Configure the board for mode 2
    */
    std::cout << "Configuring the board for mode 2" << std::endl;

}

void configure_mode_3()
{
    /*
        Configure the board for mode 3
    */
    std::cout << "Configuring the board for mode 3" << std::endl;
}


int main()
{
    initialze_pins();

    configure_mode_1();

    configure_mode_2();

    configure_mode_3();   
}

