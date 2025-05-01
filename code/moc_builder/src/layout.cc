#include "layout.hpp"

Layout::Layout(){}

Layout::Layout(int something){
    something_ = something;
}

void Layout::setSomething(int something){
    something_ = something;
}


int Layout::getSomething(){
    return something_;
}