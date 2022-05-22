#include "CustomIterator.hpp"
#include <queue>


namespace ariel{
    class Reverse_order_iter: public CustomIterator{
       private:
            std::queue<Node*> q;
        public:
            Reverse_order_iter(Node *first);
            //++iter
            //CustomIterator& operator++();
            //iter++
            //CustomIterator operator++(int);
            
    };
}