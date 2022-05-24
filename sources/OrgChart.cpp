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
        if(!added && (*it) == boss){    
            it->addChild(sub);
            added = true;
            this->size++;
        }
    }
    if(!added){
        throw runtime_error(boss + " doesn't exist!");
    }
    return(*this);
}


Level_order_iter OrgChart::begin(){
    if(this->size == 0){
        throw runtime_error("Chart is empty");
    }
    Level_order_iter iter{(this->root)};
    return iter;
}
Level_order_iter OrgChart::end() const{
    if(this->size == 0){
        throw runtime_error("Chart is empty");
    }
    Level_order_iter iter{NULL};
    return iter;
}

Level_order_iter OrgChart::begin_level_order(){
    if(this->size == 0){
        throw runtime_error("Chart is empty");
    }
    Level_order_iter iter{(this->root)};
    return iter;
}
Level_order_iter OrgChart::end_level_order() const{
    if(this->size == 0){
        throw runtime_error("Chart is empty");
    }
    Level_order_iter iter{NULL};
    return iter;
}

Reverse_order_iter OrgChart::begin_reverse_order(){
    if(this->size == 0){
        throw runtime_error("Chart is empty");
    }
    Reverse_order_iter iter{(this->root)};
    return iter;
}
Reverse_order_iter OrgChart::reverse_order() const{
    if(this->size == 0){
        throw runtime_error("Chart is empty");
    }
    Reverse_order_iter iter{NULL};
    return iter;
}
Preorder_iter OrgChart::begin_preorder(){
    if(this->size == 0){
        throw runtime_error("Chart is empty");
    }
    Preorder_iter iter{(this->root)};
    return iter;
}
Preorder_iter OrgChart::end_preorder() const{
    if(this->size == 0){
        throw runtime_error("Chart is empty");
    }
    Preorder_iter iter{NULL};
    return iter;
}

OrgChart::~OrgChart(){
    this->delAll(this->root);
}
void OrgChart::delAll(Node* n){
    for(auto *node: n->getChildren()){
        delAll(node);
    }
    delete n;
}