#include <iostream>
#include "inc/board.h"
#include "inc/coms.h"
#include "inc/delay.h"
#include "inc/gpio.hpp"

void initialze_pins(gpio_out_t nRST, gpio_out_t nTEST, gpio_in_t DONE, gpio_in_t SUCCESS, gpio_out_t CTRL, gpio_out_t SELECT)
{   
    /*
        Initialize the board pins with suitable configurations
    */
    std::cout << "Initializing the board pins" << std::endl;

    while (nRST.init(PUPD::PUPD_NONE, OUT::OUT_PUSHPULL) != true)
    {
        std::cout << "Error: nRST.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "nRST.init succeeded" << std::endl;

    while (nTEST.init(PUPD::PUPD_NONE, OUT::OUT_PUSHPULL) != true)
    {
        std::cout << "Error: nTEST.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "nTEST.init succeeded" << std::endl;

    while (DONE.init(PUPD::PUPD_UP) != true)
    {
        std::cout << "Error: DONE.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "DONE.init succeeded" << std::endl;

    while (SUCCESS.init(PUPD::PUPD_UP) != true)
    {
        std::cout << "Error: SUCCESS.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "SUCCESS.init succeeded" << std::endl;

    while (CTRL.init(PUPD::PUPD_NONE, OUT::OUT_PUSHPULL) != true)
    {
        std::cout << "Error: CTRL.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "CTRL.init succeeded" << std::endl;

    while (SELECT.init(PUPD::PUPD_NONE, OUT::OUT_PUSHPULL) != true)
    {
        std::cout << "Error: SELECT.init failed" << std::endl;
        delay_us(1000000);
    }
    std::cout << "SELECT.init succeeded" << std::endl;

}


bool configure_mode_0()
{
    /*
        Configure the board for mode 0
    */
    std::cout << "Configuring the board for mode 0" << std::endl;
    gpio_out_t nRST = {PIN_NRST};
    gpio_out_t nTEST = {PIN_NTEST};
    gpio_in_t DONE = {PIN_DONE};
    gpio_in_t SUCCESS = {PIN_SUCCESS};
    gpio_out_t CTRL = {PIN_CTRL};
    gpio_out_t SELECT = {PIN_SELECT};

    initialze_pins(nRST, nTEST, DONE, SUCCESS, CTRL, SELECT);

    nRST.write(false);
    
    if(nRST.read() == false)
    {
        vcca(true);
        delay_us(1000000); //wait for stabilization
        vccb(true);
    }

    SELECT.write(true); // Set the select pin to high
    nTEST.write(true);  // Set the test pin to high
    CTRL.write(false); // Set the control pin to low for mode 0  

    nRST.write(true);
    
    uint32_t CURR_TIME = time_us();

    while(time_us() - CURR_TIME < 10000); // Wait for 10ms
    uint32_t size = 32;
    uint32_t data = 0x12345678;
    void *data_ptr = &data;

    send_communications(data_ptr, 5);

    // Wait for the time taken to send the data
    CURR_TIME = time_us();
    while (((1 + size*8)/1000000) * 2 > time_us() - CURR_TIME && DONE.read() == false); // Wait for the time taken to send the data or the DONE pin to go high

    return SUCCESS.read();

}   


bool configure_mode_1()
{
    /*
        Configure the board for mode 1
    */
    std::cout << "Configuring the board for mode 0" << std::endl;
    gpio_out_t nRST = {PIN_NRST};
    gpio_out_t nTEST = {PIN_NTEST};
    gpio_in_t DONE = {PIN_DONE};
    gpio_in_t SUCCESS = {PIN_SUCCESS};
    gpio_out_t CTRL = {PIN_CTRL};
    gpio_out_t SELECT = {PIN_SELECT};

    initialze_pins(nRST, nTEST, DONE, SUCCESS, CTRL, SELECT);

    nRST.write(false);
    
    if(nRST.read() == false)
    {
        vcca(true);
        delay_us(1000000); //wait for stabilization
        vccb(true);
    }

    SELECT.write(true); // Set the select pin to high
    nTEST.write(true);  // Set the test pin to high
    CTRL.write(true); // Set the control pin to low for mode 1

    nRST.write(true);
    
    uint32_t CURR_TIME = time_us();

    while(time_us() - CURR_TIME < 10000); // Wait for 10ms

    // Wait for the time taken to send the data
    CURR_TIME = time_us();
    while ( DONE.read() == false); // the DONE pin to go high

    return SUCCESS.read();
}

bool configure_mode_2()
{
    /*
        Configure the board for mode 2
    */

    std::cout << "Configuring the board for mode 2" << std::endl;
    gpio_out_t nRST = {PIN_NRST};
    gpio_out_t nTEST = {PIN_NTEST};
    gpio_in_t DONE = {PIN_DONE};
    gpio_in_t SUCCESS = {PIN_SUCCESS};
    gpio_out_t CTRL = {PIN_CTRL};
    gpio_out_t SELECT = {PIN_SELECT};

    initialze_pins(nRST, nTEST, DONE, SUCCESS, CTRL, SELECT);

    while(DONE.read() == false); // Wait for the DONE pin to go high

    return SUCCESS.read();
}


int main()
{

    bool success_status0 = configure_mode_0();

    bool success_status1 = configure_mode_1();

    bool success_status2 = configure_mode_2();

    return 0;
}

