#include <iostream>
#include <stdexcept>
#include <string>
#include <iterator>
#include "LevelOrder.hpp"
#include "ReverseOrder.hpp"
#include "PreOrder.hpp"
#pragma once
namespace ariel{

    class OrgChart{
        
        public:

            OrgChart add_root(const std::string& name){return *this;}
            OrgChart add_sub(const std::string& boss, const std::string& sub){return *this;}
            Level_order_iter * begin_level_order(){return NULL;}
            Level_order_iter * end_level_order(){return NULL;}
            Reverse_order_iter * begin_reverse_order(){return NULL;}
            Reverse_order_iter * end_reverse_order(){return NULL;}
            Preorder_iter * begin_preorder(){return  NULL;}
            Preorder_iter * end_preorder(){return NULL;}
            Level_order_iter * begin(){return NULL;}
            Level_order_iter * end(){return NULL;}
            friend std::ostream& operator<<(std::ostream& output, OrgChart& org){return output;}

    };
}





