#include "CustomIterator.hpp"
#include <stack>
#include <queue>

namespace ariel{
    class Reverse_order_iter: public CustomIterator{
       private:
            std::stack<Node*> s;
            
        public:
            Reverse_order_iter(Node *first);
            //++iter
            CustomIterator& operator++();
            
            
    };
}