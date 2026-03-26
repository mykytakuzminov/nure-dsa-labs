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

    struct RangeResult
    {
        int* arr;
        int size;

        RangeResult(int* arr, int size)
        {
            this->arr = arr;
            this->size = size;
        }
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
    int Successor(int key)
    {
        int dummy = 0;
        Node *node = SearchRecursive(root, key, dummy);

        if (node == nullptr) return -1;

        // smaller node in the right tree
        if (node->right != nullptr)
        {
            return FindMin(node->right)->key;
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

            return parent->key;
        }
    }

    // previous smaller one
    int Predecessor(int key)
    {
        int dummy = 0;
        Node *node = SearchRecursive(root, key, dummy);

        if (node == nullptr) return -1;

        // bigger node in the left tree
        if (node->left != nullptr)
        {
            return FindMax(node->left)->key;
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

            return parent->key;
        }
    }

    int* GetInorderWalk()
    {
        int* arr = new int[size];
        int curr = 0;

        GetInorderWalkRecursive(root, arr, curr);

        return arr;
    }

    RangeResult GetRange(int low, int high)
    {
        int* arr = new int[size];
        int curr = 0;

        GetRangeRecursive(root, low, high, arr, curr);

        return RangeResult(arr, curr);
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
    void GetInorderWalkRecursive(Node *node, int *&arr, int &curr)
    {
        if (node == nullptr) return;

        GetInorderWalkRecursive(node->left, arr, curr);

        arr[curr] = node->key;
        curr += 1;

        GetInorderWalkRecursive(node->right, arr, curr);
    }

    // left -> parent -> right (with range)
    void GetRangeRecursive(Node *node, int low, int high, int *&arr, int &curr)
    {
        if (node == nullptr) return;

        if (low < node->key)
        {
            GetRangeRecursive(node->left, low, high, arr, curr);
        }

        if (low <= node->key && node->key <= high)
        {
            arr[curr] = node->key;
            curr += 1;
        }

        if (high > node->key)
        {
            GetRangeRecursive(node->right, low, high, arr, curr);
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
