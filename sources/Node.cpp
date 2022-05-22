#include "Node.hpp"
using namespace ariel;

using namespace std;

ostream& ariel::operator<<(ostream& output, const Node& node){
    output<<node.getValue();
    return output;
}
Node::Node(const string& s):value(s), children(){

}
Node::~Node(){}
