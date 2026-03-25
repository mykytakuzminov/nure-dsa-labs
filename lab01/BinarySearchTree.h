#include <iostream>

class BinarySearchTree
{
private:
    struct Node
    {
        int key;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent = nullptr;

        Node(int key)
        {
            this->key = key;
        }
    };

    Node *root = nullptr;
    int size = 0;

public:
    struct SearchResult
    {
        bool found = false;
        int visited = 0;
    };

    BinarySearchTree() {};

    ~BinarySearchTree()
    {
        DestroyRecursive(root);
    };

    // returns amount of visited nodes
    int Insert(int key)
    {
        int visited = 0;
        InsertRecursive(root, key, visited);
        return visited;
    }

    // returns amount of visited nodes
    int Delete(int key)
    {
        int visited = 0;
        DeleteRecursive(root, key, visited);
        return visited;
    }

    int Height()
    {
        return HeightRecursive(root);
    }

    int Size()
    {
        return size;
    }

    // returns amount of visited nodes and if it was found
    SearchResult Search(int key)
    {
        SearchResult result;
        int visited = 0;
        result.found = SearchRecursive(root, key, visited) != nullptr;
        result.visited = visited;
        return result;
    }

    // next bigger one
    Node* Successor(int key)
    {
        int dummy = 0;
        Node *node = SearchRecursive(root, key, dummy);

        if (node == nullptr) return nullptr;

        // smaller node in the right tree
        if (node->right != nullptr)
        {
            return FindMin(node->right);
        }
        // parent for the left child
        else
        {
            Node* current = node;
            Node* parent = node->parent;

            while (parent != nullptr && current == parent->right)
            {
                current = parent;
                parent = parent->parent;
            }

            return parent;
        }
    }

    // previous smaller one
    Node* Predecessor(int key)
    {
        int dummy = 0;
        Node *node = SearchRecursive(root, key, dummy);

        if (node == nullptr) return nullptr;

        // bigger node in the left tree
        if (node->left != nullptr)
        {
            return FindMax(node->left);
        }
        // parent for the right child
        else
        {
            Node* current = node;
            Node* parent = node->parent;

            while (parent != nullptr && current == parent->left)
            {
                current = parent;
                parent = parent->parent;
            }

            return parent;
        }
    }

    void InorderWalk()
    {
        InorderWalkRecursive(root);
        std::cout << std::endl;
    }

    void PrintRange(int low, int high)
    {
        PrintRangeRecursive(root, low, high);
        std::cout << std::endl;
    }

private:
    void DestroyRecursive(Node *node)
    {
        if (node == nullptr) return;
        DestroyRecursive(node->left);
        DestroyRecursive(node->right);
        delete node;
    }

    void InsertRecursive(Node *&node, int key, int &visited, Node* parent = nullptr)
    {
        // amount of visited nodes
        // calculates additionally visited nullptr nodes
        visited++;

        if (node == nullptr)
        {
            node = new Node(key);
            node->parent = parent;
            size += 1;
            return;
        }

        if (key < node->key)
        {
            InsertRecursive(node->left, key, visited, node);
        }
        else if (key > node->key)
        {
            InsertRecursive(node->right, key, visited, node);
        }
        // duplicates are ignored
    }

    void DeleteRecursive(Node *&node, int key, int &visited)
    {
        // amount of visited nodes
        // calculates additionally visited nullptr nodes
        visited++;

        if (node == nullptr) return;

        if (key < node->key)
        {
            DeleteRecursive(node->left, key, visited);
        }
        else if (key > node->key)
        {
            DeleteRecursive(node->right, key, visited);
        }
        else
        {
            // when there are no children
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr;
            }
            // when there is only a right child
            else if (node->left == nullptr)
            {
                Node *temp = node;
                node->right->parent = node->parent;
                node = node->right;
                delete temp;
            }
            // when there is only a left child
            else if (node->right == nullptr)
            {
                Node *temp = node;
                node->left->parent = node->parent;
                node = node->left;
                delete temp;
            }
            // finds the smallest node from right tree
            // swaps that node with deleted one
            // parent stays the same, because of swapping values
            else
            {
                Node* minRightNode = FindMin(node->right);
                node->key = minRightNode->key;
                DeleteRecursive(node->right, minRightNode->key, visited);
            }

            size -= 1;
        }
    }

    int HeightRecursive(Node* node) {
        if (node == nullptr) return 0;

        int leftHeight = HeightRecursive(node->left);
        int rightHeight = HeightRecursive(node->right);

        return 1 + std::max(leftHeight, rightHeight);
    }

    Node* SearchRecursive(Node* node, int key, int &visited)
    {
        // amount of visited nodes
        // calculates additionally visited nullptr nodes
        visited++;

        if (node == nullptr) return nullptr;

        if (node->key == key) return node;

        if (key < node->key)
            return SearchRecursive(node->left, key, visited);
        else
            return SearchRecursive(node->right, key, visited);
    }

    // left -> parent -> right
    void InorderWalkRecursive(Node *node)
    {
        if (node == nullptr) return;

        InorderWalkRecursive(node->left);
        std::cout << node->key << " ";
        InorderWalkRecursive(node->right);
    }

    // left -> parent -> right (with range)
    void PrintRangeRecursive(Node *node, int low, int high)
    {
        if (node == nullptr) return;

        if (low < node->key)
        {
            PrintRangeRecursive(node->left, low, high);
        }

        if (low <= node->key and node->key <= high)
        {
            std::cout << node->key << " ";
        }

        if (high > node->key)
        {
            PrintRangeRecursive(node->right, low, high);
        }
    }

    // finds minimum value in the tree of the given root
    Node* FindMin(Node *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // finds maximum value in the tree of the given root
    Node* FindMax(Node *node)
    {
        while (node->right != nullptr)
            node = node->right;
        return node;
    }
};
