
#include <stdexcept>
#include <iterator>
#include "LevelOrder.hpp"
#include "ReverseOrder.hpp"
#include "PreOrder.hpp"
#include "Node.hpp"
#pragma once
namespace ariel{

    class OrgChart{
        private:
            Node* root;
            size_t size;
        public:
            OrgChart();
            ~OrgChart();
            OrgChart &add_root(const std::string& name);
            OrgChart &add_sub(const std::string& boss, const std::string& sub);
            Level_order_iter begin();
            Level_order_iter end();
            Level_order_iter begin_level_order();
            Level_order_iter end_level_order();
            Reverse_order_iter begin_reverse_order();
            Reverse_order_iter end_reverse_order();
            Preorder_iter begin_preorder();
            Preorder_iter end_preorder();

            friend std::ostream& operator<<(std::ostream& output, OrgChart& org){return output;}
            void delAll(Node *n);
    };
}





