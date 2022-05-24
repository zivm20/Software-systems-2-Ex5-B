#include "CustomIterator.hpp"
#include <stack>

namespace ariel{
    
    class Preorder_iter: public CustomIterator{
        private:
            std::stack<Node*> s;
        public:

            static void print_stack(std::stack<Node*> s){
                // If stack is empty then return
                if (s.empty())
                    return;
                
            
                Node* x = s.top();
            
                // Pop the top element of the stack
                s.pop();
            
                // Recursively call the function PrintStack
                print_stack(s);
            
                // Print the stack element starting
                // from the bottom
                std::cout << *x << " ";
            
                // Push the same element onto the stack
                // to preserve the order
                s.push(x);
            }

            Preorder_iter(Node *first);
            //++iter
            CustomIterator& operator++();
            
    };

}