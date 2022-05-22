#include "LevelOrder.hpp"
using namespace ariel;


Level_order_iter::Level_order_iter(Node *first):CustomIterator(first), q(){

}
CustomIterator& Level_order_iter::operator++(){
    for(auto node: this->curr->getChildren()){
        this->q.push(node);
    }
    if(this->q.empty()){
        
        this->curr = NULL;
    }
    else{
        this->curr = this->q.front();
        this->q.pop();
    }
    return (*this);
}
