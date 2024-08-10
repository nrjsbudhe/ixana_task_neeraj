#include<iostream>
#include "inc/board.h"
#include "inc/coms.h"

bool send_communications(const void* data, uint32_t size)
{
    std::cout << "send_configuration_data" << std::endl;
    // TO-DO : Implement the communication time equation -- (1 + size*8)/1000000
    return true;
}   

