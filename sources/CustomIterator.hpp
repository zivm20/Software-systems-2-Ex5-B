#include <iostream>
#include <stdexcept>
#include <string>
#include <iterator>
#include "Node.hpp"
#pragma once

namespace ariel{

    class CustomIterator: public std::iterator<std::input_iterator_tag,int>{
        protected:
            Node * curr;
            
        public:
            CustomIterator(Node *first);
            inline Node& operator*()const{
                return *(this->curr);
            }
            inline Node* operator->(){
                return this->curr;
            }
            inline Node* start() const{
                return this->curr;
            }
            inline bool operator==(const CustomIterator& iter2)const{
                if((this->curr == NULL || iter2.start() == NULL)){
                    return (this->curr == NULL && iter2.start() == NULL);
                }
                return *this->curr == *iter2.start();
            }
            inline bool operator!=(const CustomIterator& iter2)const{
                if((this->curr == NULL || iter2.start() == NULL)){
                    return !(this->curr == NULL && iter2.start() == NULL);
                }
                return *this->curr != *iter2.start();
            }
            //++iter
            virtual CustomIterator& operator++(){
                return *this;
            }
            
            //iter++
            friend CustomIterator operator++(CustomIterator &it,int){
                CustomIterator temp = it;
                ++it;
                return temp;
            }
    };

}