/**
 * Liron Cohen -312324247 - liron02319@gmail.com
 */


#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp" 
#include "Complex.hpp"

using namespace std;
int main()
{

/* running of the pre,post,in,bfs,dfs,complex and root with number double*/


    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << tree;



    Complex c1(2, 3);
    Complex c2(4, 5);
    Tree<Complex> tree2;
    Node<Complex> complexRoot = Node<Complex>(c1);
    tree2.add_root(complexRoot);
    Node<Complex> n12 = Node<Complex>(c2);
    tree2.add_sub_node(complexRoot, n12);
    
    cout << tree2;

    // Print various traversals
    cout << "Pre-Order Traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "Post-Order Traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "In-Order Traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "BFS Traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "DFS Traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "myHeap Traversal:" << endl;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    // 3-ary tree
    Tree<int, 3> three_ary_tree; // 3-ary tree.
    Node<int> int_root_node = Node<int>(1);
    three_ary_tree.add_root(int_root_node);

    Node<int> int_n1 = Node<int>(2);
    Node<int> int_n2 = Node<int>(3);
    Node<int> int_n3 = Node<int>(4);
    Node<int> int_n4 = Node<int>(5);
    Node<int> int_n5 = Node<int>(6);

    three_ary_tree.add_sub_node(int_root_node, int_n1);
    three_ary_tree.add_sub_node(int_root_node, int_n2);
    three_ary_tree.add_sub_node(int_root_node, int_n3);
    three_ary_tree.add_sub_node(int_n1, int_n4);
    three_ary_tree.add_sub_node(int_n2, int_n5);

    // Print 3-ary tree DFS traversal
    cout << "3-ary Tree DFS Traversal:" << endl;
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    // Complex tree - Iterator

    Tree<Complex> complex_tree;
    Node<Complex> complex_root_node = Node<Complex>(Complex(2, 3));
    complex_tree.add_root(complex_root_node);
    Node<Complex> complex_n1 = Node<Complex>(Complex(4, 5));
    complex_tree.add_sub_node(complex_root_node, complex_n1);
    Node<Complex> complex_n2 = Node<Complex>(Complex(6, 7));
    complex_tree.add_sub_node(complex_root_node, complex_n2);
    Node<Complex> complex_n3 = Node<Complex>(Complex(8, 9));
    complex_tree.add_sub_node(complex_n1, complex_n3);
    Node<Complex> complex_n4 = Node<Complex>(Complex(10, 11));
    complex_tree.add_sub_node(complex_n1, complex_n4);
    Node<Complex> complex_n5 = Node<Complex>(Complex(12, 13));
    complex_tree.add_sub_node(complex_n2, complex_n5);

    // Complex Tree GUI Launch:
    cout << complex_tree;
/*
    cout << "Complex Tree DFS Traversal:" << endl;
    for (auto node = complex_tree.begin_dfs_scan(); node != complex_tree.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "Complex Tree BFS Traversal:" << endl;
    for (auto node = complex_tree.begin_bfs_scan(); node != complex_tree.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << endl;
    }   

    cout << "Complex Tree Pre-Order Traversal:" << endl;
    for (auto node = complex_tree.begin_pre_order(); node != complex_tree.end_pre_order(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "Complex Tree Post-Order Traversal:" << endl;
    for (auto node = complex_tree.begin_post_order(); node != complex_tree.end_post_order(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "Complex Tree In-Order Traversal:" << endl;
    for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node) {
        cout << (*node)->get_value() << endl;
    }

    cout << "Complex Tree Heap Traversal:" << endl;
    for (auto node = complex_tree.begin_heap(); node != complex_tree.end_heap(); ++node) {
        cout << (*node)->get_value() << endl;
    }

*/




    return 0;
}

