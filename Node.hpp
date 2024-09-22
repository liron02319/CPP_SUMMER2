/**
 * Liron Cohen -312324247 - liron02319@gmail.com
 */


#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
//#include <iostream>
//#include <string>

/*
Node class that represents a node in a tree.
Each node contains a value and a list of pointers to its children.
*/


template <typename T>
class Node {


public:
     T value; // Value stored in the node
    std::vector<Node<T>*> children; // Vector to store pointers to child nodes

    // Constructor that initializes the node with a given value
    Node(T val) : value(val) {}
    
    // Destructor (default behavior is sufficient for this example)
    ~Node() {
        
    }

    // Getter method to retrieve the value of the node
    T get_value() const { return value; }

    // Method to add a child node to the current node
    void add_child(const Node<T>& child) {
        children.push_back(new Node<T>(child)); // Create a new node and add it to the children vector
    }

    // Getter method to retrieve the children of the node
    std::vector<Node<T>*> get_children() const { return children; }
};

#endif // NODE_HPP