#ifndef STORE_SLICE_H
#define STORE_SLICE_H

#include "reducer.hpp"
#include "state.hpp"
#include <string>

namespace quick{
namespace fluxion{
namespace store{

template <typename EnumType>
class Slice{
public:
    Slice(quick::fluxion::interface::statejke& state, Reducer<EnumType>& reducer) : state_(state), reducer_(reducer){}
private:
    quick::fluxion::interface::statejke state_;
    Reducer<EnumType> reducer_;

};


};};};

#endif