/**
 * Liron Cohen -312324247 - liron02319@gmail.com
 */

#ifndef TREE_HPP
#define TREE_HPP


#include <SFML/Graphics.hpp>
#include <type_traits>
#include <string>
#include <sstream>
#include <map>
#include <iomanip> 
#include "Node.hpp"
#include <cstddef>
#include <vector>
#include <queue>
#include <stdexcept>
#include <iostream>

//For GUI
const float NODE_RADIUS = 45.0f; 

template <typename T, int K = 2> // K defaults to 2 for a binary tree



/*
    Tree: A class that represents a tree data structure. 
*/
class Tree
{


private:

    Node<T> *root; // Pointer to the root node of the tree
    bool IsBinaryTree; // Flag to check if the tree is a binary tree
    int k; // Maximum number of children per node
    

    // Vectors to store nodes during different tree traversals
    std::vector<Node<T> *> BFS_Nodes;
    std::vector<Node<T> *> DFS_NODES;
    std::vector<Node<T> *> HEAP_NODES;
    std::vector<Node<T> *> PreOrderNodes;
    std::vector<Node<T> *> PostOrderNodes;
    std::vector<Node<T> *> InOrderNodes;
   


public:

    // Constructor initializes root and sets binary tree flag

    Tree() : root(nullptr), IsBinaryTree(K == 2) {
        k = K;
    }
    // Destructor cleans up tree nodes
    ~Tree()
    {
        DeleteTree(root);
    }

     // Returns the maximum number of children per node
    int get_k() const
    {
        return k;
    }

   
    // Adds the root node to the tree
    void add_root(const Node<T> &node)
    {
        if (root != nullptr)
        {
            throw std::runtime_error("NODE Root already exists.");
        }
        root = new Node<T>(node.get_value());
    }


 // Adds a child node under a specified parent node
    void add_sub_node(const Node<T> &parent, const Node<T> &child)
    {
        
        if (root == nullptr)
        {
            throw std::runtime_error("NODE Root NOT FOUND.");
        }
        
        Node<T> *parent_ptr = find_node(root, parent.get_value());

        if (parent_ptr->children.size() >= (size_t)this->k)
        {
            throw std::runtime_error("NODE GOT TO THE maximum number of children.");
        }

        if (parent_ptr == nullptr)
        {
            throw std::runtime_error("PARENT NOT FOUND.");
        }
        parent_ptr->add_child(child);
    }



    // Returns a pointer to the root node
    Node<T>* getRoot() const
    {
        return root;
    }

/*
Post Order
*/
    // Traversal iterators for pre-order
    typename std::vector<Node<T> *>::iterator begin_pre_order()
    {
        if (K != 2)
        {
            return begin_dfs_scan();
        }
        PreOrderNodes.clear();
        preOrderHelpFunction(root, PreOrderNodes);
        return PreOrderNodes.begin();
    }

    typename std::vector<Node<T> *>::iterator end_pre_order()
    {
        if (K != 2)
        {
            return end_dfs_scan();
        }
        return PreOrderNodes.end();
    }


/*
Post Order
*/
    // Traversal iterators for post-order

    typename std::vector<Node<T> *>::iterator begin_post_order()
    {
        if (K != 2)
        {
            return begin_dfs_scan();
        }
        PostOrderNodes.clear();
        PostOrderHelpFunction(root, PostOrderNodes);
        return PostOrderNodes.begin();
    }

    typename std::vector<Node<T> *>::iterator end_post_order()
    {
        if (K != 2)
        {
            return end_dfs_scan();
        }
        return PostOrderNodes.end();
    }
/*
In Order
*/
    // Traversal iterators for in-order

    typename std::vector<Node<T> *>::iterator begin_in_order()
    {
        if (K != 2)
        {
            return begin_dfs_scan();
        }
        InOrderNodes.clear();
        InOrderHelpFunction(root, InOrderNodes);
        return InOrderNodes.begin();
    }

    typename std::vector<Node<T> *>::iterator end_in_order()
    {
        if (K != 2)
        {
            return end_dfs_scan();
        }
        return InOrderNodes.end();
    }


/*
(BFS) iterator
*/
    // Traversal iterators for breadth-first search (BFS)

    typename std::vector<Node<T> *>::iterator begin_bfs_scan()
    {
        BFS_Nodes.clear();
        BFS_HelpFuncion(root, BFS_Nodes);
        return BFS_Nodes.begin();
    }

    typename std::vector<Node<T> *>::iterator end_bfs_scan()
    {
        return BFS_Nodes.end();
    }


/*
DFS ITERATOR
*/
    // Traversal iterators for depth-first search (DFS)

    typename std::vector<Node<T> *>::iterator begin_dfs_scan()
    {
        DFS_NODES.clear();
        DFS_HELPER(root, DFS_NODES);
        return DFS_NODES.begin();
    }

    typename std::vector<Node<T> *>::iterator end_dfs_scan()
    {
        return DFS_NODES.end();
    }


/*
HEAP
*/
    // Traversal iterators for heap

        typename std::vector<Node<T> *>::iterator begin_heap()
    {
        HEAP_NODES.clear();
        myHeap(root, HEAP_NODES);
        return HEAP_NODES.begin();
    }

    typename std::vector<Node<T> *>::iterator end_heap()
    {
        return HEAP_NODES.end();
    }

    

/*
    private Functions for the tree traversal.
    The Functions store the nodes in the order of traversal.
*/

    // Helper function for preOrderHelpFunction (works for binary trees)

private:
    void preOrderHelpFunction(Node<T> *node, std::vector<Node<T> *> &result)
    {
        if (node == nullptr)
            return;
        result.push_back(node);
        for (auto child : node->get_children())
        {
            preOrderHelpFunction(child, result);
        }
    }
    // Helper function for PostOrderHelpFunction (works for binary trees)

    void PostOrderHelpFunction(Node<T> *node, std::vector<Node<T> *> &result)
    {
        if (node == nullptr)
            return;
        for (auto child : node->get_children())
        {
            PostOrderHelpFunction(child, result);
        }
        result.push_back(node);
    }

    // Helper function for in-order traversal (works for binary trees)

     void InOrderHelpFunction(Node<T> *node, std::vector<Node<T> *> &result) {
    if (node == nullptr)
        return;

    auto children = node->get_children();
    if (children.size() > 0) {
        InOrderHelpFunction(children[0], result); // Left child
    }
    result.push_back(node); // Root
    if (children.size() > 1) {
        InOrderHelpFunction(children[1], result); // Right child
    }
}

    // Helper function for breadth-first search (BFS)

    void BFS_HelpFuncion(Node<T> *node, std::vector<Node<T> *> &result)
    {
        if (node == nullptr)
            return;
        std::queue<Node<T> *> q;
        q.push(node);
        while (!q.empty())
        {
            Node<T> *current = q.front();
            q.pop();
            result.push_back(current);
            for (auto child : current->get_children())
            {
                q.push(child);
            }
        }
    }


    // Helper function for depth-first search (DFS)

    void DFS_HELPER(Node<T> *node, std::vector<Node<T> *> &result)
    {
        if (node == nullptr)
            return;
        result.push_back(node);
        for (auto child : node->get_children())
        {
            DFS_HELPER(child, result);
        }
    }


    // Deletes the entire tree recursively

    void DeleteTree(Node<T> *node)
    {
        if (node == nullptr)
            return;
        for (auto child : node->get_children())
        {
            DeleteTree(child);
            
        }
        delete node;
    }


    // Finds a node with a specific value

    Node<T> *find_node(Node<T> *node, const T &value)
    {
        if (node == nullptr)
            return nullptr;
        if (node->get_value() == value)
            return node;
        for (auto child : node->get_children())
        {
            Node<T> *found = find_node(child, value);
            if (found != nullptr)
                return found;
        }
        return nullptr;
    }

    // Constructs a heap from the tree using DFS

        void myHeap(Node<T> *node, std::vector<Node<T> *> &result)
    {
        if (node == nullptr)
            return;
        DFS_HELPER(node, result);
        auto comp = [](Node<T> *lhs, Node<T> *rhs) { return lhs->get_value() > rhs->get_value(); };
        std::make_heap(result.begin(), result.end(), comp);
        
    }

    
     /*
        Operator<< launches the GUI for the tree.
    */
    friend std::ostream &operator<<(std::ostream &os, Tree<T, K> &tree)
    {
        Node<T> *root = tree.getRoot();

        if(root == nullptr)
        {
            os << "Tree empty." << std::endl;
            return os;
        }
       
        os << "Launching TREE GUI..." << std::endl;
       
          // For GUI output, you might consider using SFML to visualize the tree
        // This is a placeholder for actual GUI logic, as SFML window setup is needed.
        sf::Font font;
        if (!font.loadFromFile("sansation.ttf")) {
            std::cerr << "Failed to load font file 'arial.ttf'" << std::endl;
            return os;
        }

        sf::RenderWindow window(sf::VideoMode(600, 600), "TREE");
        window.setVerticalSyncEnabled(true); // Attempt to enable vertical sync
        
        // Main loop to keep the window open
        while (window.isOpen())
        {
            sf::Event event; // Create an event object to handle window events
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            
            window.clear(sf::Color::Red); // Clear the window with a red background
            tree.drawTree(window, font); // Draw the tree onto the window using the specified font
            window.display(); // Display the rendered contents of the window
        }
        
             return os;
    
    }


   // Function to draw the tree onto the window

void drawTree(sf::RenderWindow &window, sf::Font &font)
{
    if (this->root == nullptr) return;

     std::map<Node<T>*, sf::Vector2f> positions; // Map to hold node positions for drawing
    float start_x = window.getSize().x / 2; // Starting x position (centered horizontally)
    float start_y = NODE_RADIUS * 2; // Starting y position (below the top of the window)
    
    // Calculate positions of each node
    calculatePositions(this->root, positions, start_x, start_y, window.getSize().x / 4);

    // Draw each node based on its calculated position

    for (auto &entry : positions)
    {
        drawNode(window, entry.first, entry.second, font, positions);
    }
}




// Function to recursively calculate positions for each node in the tree

void calculatePositions(Node<T> *node, std::map<Node<T>*, sf::Vector2f> &positions, float x, float y, float horizontal_spacing)
{
    if (node == nullptr) return;

    positions[node] = sf::Vector2f(x, y);
    float child_x = x - ((node->get_children().size() - 1) * horizontal_spacing / 2);
    float child_y = y + NODE_RADIUS * 4;

    for (auto child : node->get_children())
    {
        calculatePositions(child, positions, child_x, child_y, horizontal_spacing / 2);
        child_x += horizontal_spacing;
    }
}


// Function to draw a single node and its connections
void drawNode(sf::RenderWindow &window, Node<T> *node, sf::Vector2f position, sf::Font &font, const std::map<Node<T>*, sf::Vector2f> &positions)
{
     sf::CircleShape circle(NODE_RADIUS); // Create a circle shape for the node
    circle.setFillColor(sf::Color::Blue); // Set the fill color to blue
    circle.setOrigin(NODE_RADIUS, NODE_RADIUS); // Set the origin to the center of the circle
    circle.setPosition(position); // Set the position of the circle

    sf::Text text;
    text.setFont(font);
    if constexpr (std::is_same<T, std::string>::value)
    {
        text.setString(node->get_value());
    }
    else
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << node->get_value();
        text.setString(oss.str());
    }
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
    text.setPosition(position);

    window.draw(circle); // Draw the node circle onto the window
    window.draw(text); // Draw the node text onto the window

      // Draw lines connecting the node to its children

    for (auto child : node->get_children())
    {
        sf::Vertex line[] =
        {
            sf::Vertex(position),
            sf::Vertex(positions.at(child))
        };
        window.draw(line, 2, sf::Lines);
    }
}

};

#endif 
