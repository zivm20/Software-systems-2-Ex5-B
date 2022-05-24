#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#pragma once



namespace ariel{
class Node{
    private:
        std::string value;
        std::vector<Node*> children;
    public:
        Node(const std::string& s);
        ~Node();
        inline std::string getValue() const{
            return this->value;
        }
        inline void setValue(std::string s){
            this->value = s;
        }
        inline std::vector<Node*> getChildren() const{
            return this->children;
        }
        inline void addChild(const  std::string& n){
            Node* temp = new Node{n};
            this->children.push_back(temp);
        }
        inline bool operator==(const Node& node2)const{
            return this->value == node2.getValue() && this->children == node2.getChildren();
        }
        inline bool operator!=(const Node& node2)const{
            return !((*this)==node2);
        }
        inline bool operator==(const std::string& str)const{
            return this->value == str;
        }
        inline bool operator!=(const std::string& str)const{
            return !((*this)==str);
        }
        inline size_t size(){
            return this->value.size();
        }
        inline char at(const size_t& n){
            return this->value.at(n);
        }
        inline size_t length(){
            return this->value.size();
        }
        

        friend std::ostream& operator<<(std::ostream& output, const Node& node);


};


}