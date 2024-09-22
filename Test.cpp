/**
 * Liron Cohen -312324247 - liron02319@gmail.com
 */

#include "Complex.hpp"

#include "doctest.h"
#include "Tree.hpp"
#include "Node.hpp"
#include <iostream>
#include <sstream>

//#include "TreeIterators.hpp"



TEST_CASE("Invalid tree operation: Adding a 3rd node to a binary tree")
{
    Node<double> root_node = Node<double>(2.1);
    Tree<double> tree;
    tree.add_root(root_node);
    Node<double> n1 = Node<double>(2.2);
    Node<double> n2 = Node<double>(2.3);
    Node<double> n3 = Node<double>(2.4);
    Node<double> n4 = Node<double>(2.5);
    Node<double> n5 = Node<double>(2.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    CHECK_THROWS(tree.add_sub_node(root_node, n1));
}

TEST_CASE("Invalid tree operation: Adding a sub-node to a non-existent parent node")
{
    Tree<double> tree;
    Node<double> parent_node = Node<double>(2.1);
    Node<double> sub_node = Node<double>(2.2);

    CHECK_THROWS(tree.add_sub_node(parent_node, sub_node));
}

TEST_CASE("Parent node not found"){
    Tree<double> tree;
    Node<double> parent_node = Node<double>(2.1);
    Node<double> sub_node = Node<double>(2.2);

    CHECK_THROWS(tree.add_sub_node(parent_node, sub_node));
}


TEST_CASE("Root already exists"){
    Node<double> root_node = Node<double>(2.1);
    Tree<double> tree;
    tree.add_root(root_node);

    CHECK_THROWS(tree.add_root(root_node));
}


TEST_CASE("Test <= operator"){
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3(1, 2);
    Complex c4(0, 0);

    CHECK(c1 <= c2);
    CHECK(c1 <= c3);
    CHECK(c1 <= c1);
    CHECK(!(c1 <= c4));
}






