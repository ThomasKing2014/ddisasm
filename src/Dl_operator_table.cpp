/*
 * Dl_operator_table.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: afloresmontoya
 */

#include "Dl_operator_table.h"




int64_t Dl_operator_table::add_to_dict(op_dict& dict,Dl_operator op){
    auto pair=dict.find(op);
    if(pair!=dict.end())
        return (pair->second);
    else{
        dict[op]=curr_index;
        return curr_index++;
    }
}

int64_t Dl_operator_table::add(Dl_operator op){
    return add_to_dict(dicts[op.get_type()],op);

}
void Dl_operator_table::print_operators_of_type(operator_type type,std::ofstream& fbuf){
    for(auto pair: dicts[type]){
        fbuf<<pair.first.print_tabs(pair.second)<<std::endl;
    }

}
