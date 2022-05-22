#include "OrgChart.hpp"
using namespace ariel;
using namespace std;

OrgChart::OrgChart():root(new Node("")),size(0){

}
OrgChart &OrgChart::add_root(const string& name){
    this->root->setValue(name);
    if(this->size==0){
        this->size++;
    }
    return (*this);
}
OrgChart &OrgChart::add_sub(const std::string& boss, const std::string& sub){
    bool added = false;
    for (auto it=begin(); it!=end(); ++it) {
        if(!added && (*it).getValue() == boss){    
            it->addChild(sub);
            added = true;
        }
    }
    if(!added){
        throw runtime_error(boss + " doesn't exist!");
    }
    return(*this);
}


Level_order_iter OrgChart::begin(){
    Level_order_iter iter{(this->root)};
    return iter;
}
Level_order_iter OrgChart::end(){
    Level_order_iter iter{NULL};
    return iter;
}

Level_order_iter OrgChart::begin_level_order(){
    Level_order_iter iter{(this->root)};
    return iter;
}
Level_order_iter OrgChart::end_level_order(){
    Level_order_iter iter{NULL};
    return iter;
}

Reverse_order_iter OrgChart::begin_reverse_order(){
    Reverse_order_iter iter{(this->root)};
    return iter;
}
Reverse_order_iter OrgChart::end_reverse_order(){
    Reverse_order_iter iter{NULL};
    return iter;
}
Preorder_iter OrgChart::begin_preorder(){
    Preorder_iter iter{(this->root)};
    return iter;
}
Preorder_iter OrgChart::end_preorder(){
    Preorder_iter iter{NULL};
    return iter;
}

OrgChart::~OrgChart(){
    this->delAll(this->root);
}
void OrgChart::delAll(Node* n){
    for(auto node: n->getChildren()){
        delAll(node);
    }
    delete n;
}