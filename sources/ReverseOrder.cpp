#include "ReverseOrder.hpp"
using namespace ariel;


Reverse_order_iter::Reverse_order_iter(Node *first):CustomIterator(first){
    this->s.push(NULL);
    if(this->curr != NULL){
        this->s.push(curr);
        std::stack<Node*> s2{};
        std::queue<Node*> q{};

        while(this->curr != NULL){
            for(auto *node: this->curr->getChildren()){
                s2.push(node);
            }
            while(!s2.empty()){
                q.push(s2.top());
                s2.pop();
            }
            if(q.empty()){
                this->curr = NULL;
            }
            else{
                this->curr = q.front();
                
                this->s.push(curr);
                q.pop();
            }
        }
        this->curr = this->s.top();
        this->s.pop();
        
    }
    

}

CustomIterator& Reverse_order_iter::operator++(){
    this->curr = this->s.top();
    this->s.pop();
    return (*this);
}