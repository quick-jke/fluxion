#ifndef STORE_INTERFACE_STATE_H
#define STORE_INTERFACE_STATE_H

#include <iostream>

namespace quick{
namespace fluxion{
namespace interface{

class statejke{
public:
    statejke() { std::cout << "statejke" << std::endl; }
    // virtual void info() = 0;  
    virtual ~statejke() = default;   
};


};};};

#endif