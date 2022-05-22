#include "CustomIterator.hpp"
#include <queue>
namespace ariel{
    class Level_order_iter: public CustomIterator{
        private:
            std::queue<Node*> q;
        public:
            Level_order_iter(Node *first);
            //++iter
            CustomIterator& operator++();
            //iter++
            //CustomIterator operator++(int);
            std::queue<Node*> Q(){return q;}
    };
}
