#include "CustomIterator.hpp"
#include <queue>

namespace ariel{
    class Preorder_iter: public CustomIterator{
        private:
            std::queue<Node*> q;
        public:
            Preorder_iter(Node *first);
            //++iter
            //CustomIterator& operator++();
            //iter++
            //CustomIterator operator++(int);
    };

}