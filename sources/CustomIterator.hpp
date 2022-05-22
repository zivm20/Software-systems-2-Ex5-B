#include <iostream>
#include <stdexcept>
#include <string>
#include <iterator>
#pragma once

namespace ariel{

    class CustomIterator: public std::iterator<std::input_iterator_tag,int>{
        
        public:
            int size(){return 0;}
            friend std::ostream& operator<<(std::ostream& output, CustomIterator& iter) {return output;}
            //++iter
            virtual CustomIterator& operator++(){
                return *this;
            }
            //iter++
            virtual CustomIterator operator++(int){
                return *this;
            }
            
    };

}