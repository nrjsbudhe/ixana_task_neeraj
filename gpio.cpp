#include <iostream>
#include "inc/board.h"
#include "inc/gpio.hpp"


/*
    GPIO_IN_T : Helper functions for GPIO input pins
*/
bool gpio_in_t::init(PUPD pullup_pulldown){
    std::cout << "gpio_in_t::init" << std::endl;
    return true;
}

bool gpio_in_t::deinit(){
    std::cout << "gpio_in_t::deinit" << std::endl;
    return true;
}  

bool gpio_in_t::read(){
    std::cout << "gpio_in_t::read" << std::endl;
    return true;
}


/*
    GPIO_OUT_T : Helper functions for GPIO output pins
*/
bool gpio_out_t::init(PUPD pullup_pulldown, OUT out_type){
    std::cout << "gpio_out_t::init" << std::endl;
    return true;
}

bool gpio_out_t::deinit(){
    std::cout << "gpio_out_t::deinit" << std::endl;
    return true;
}

bool gpio_out_t::read(){
    std::cout << "gpio_out_t::read" << std::endl;
    return true;
}

void gpio_out_t::write(bool value){
    std::cout << "gpio_out_t::write" << std::endl;
}


/*
    GPIO_IRQ_T : Helper functions for GPIO interrupt pins
*/
bool gpio_irq_t::init(PUPD pullup_pulldown, EDGE edge){
    std::cout << "gpio_irq_t::init" << std::endl;
    return true;
} 

bool gpio_irq_t::deinit(){
    std::cout << "gpio_irq_t::deinit" << std::endl;
    return true;
}

void gpio_irq_t::set_callback(void (*callback)(EDGE)){
    std::cout << "IRQ on " << std::endl;
    std::cout << "gpio_irq_t::set_callback" << std::endl;
}

void gpio_irq_t::enable(){
    std::cout << "gpio_irq_t::enable" << std::endl;
}

void gpio_irq_t::disable(){
    std::cout << "gpio_irq_t::disable" << std::endl;
}

bool gpio_irq_t::read(){
    std::cout << "gpio_irq_t::read" << std::endl;
    return true;
}





