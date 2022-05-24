#include "PreOrder.hpp"

using namespace ariel;
using namespace std;

Preorder_iter::Preorder_iter(Node *first):CustomIterator(first){

}

CustomIterator& Preorder_iter::operator++(){
    stack<Node*> temp;
    for(auto *node: this->curr->getChildren()){
        temp.push(node);
    }
    while(!temp.empty()){
        this->s.push(temp.top());
        temp.pop();
    }
    if(this->s.empty()){
        
        this->curr = NULL;
    }
    else{
        this->curr = this->s.top();
        this->s.pop();
    }
    return (*this);
}

