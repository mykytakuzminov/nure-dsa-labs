#include <iostream>

class BinarySearchTree
{
private:
    struct Node
    {
        int key;
        Node *left = nullptr;
        Node *right = nullptr;

        Node(int key)
        {
            this->key = key;
        }
    };

    Node *root = nullptr;

public:
    BinarySearchTree() {};

    void Insert(int key)
    {
        InsertRecursive(root, key);
    }

    void Delete(int key)
    {
        DeleteRecursive(root, key);
    }

    void PreorderWalk()
    {
        PreoderWalkRecursive(root);
        std::cout << std::endl;
    }

    void InorderWalk()
    {
        InorderWalkRecursive(root);
        std::cout << std::endl;
    }

    void PostorderWalk()
    {
        PostorderWalkRecursive(root);
        std::cout << std::endl;
    }

    void PrintRange(int low, int high)
    {
        PrintRangeRecursive(root, low, high);
        std::cout << std::endl;
    }

private:
    void InsertRecursive(Node *&node, int key)
    {
        if (node == nullptr)
        {
            node = new Node(key);
            return;
        }

        if (key < node->key)
        {
            InsertRecursive(node->left, key);
        }
        if (key > node->key)
        {
            InsertRecursive(node->right, key);
        }
    }

    void DeleteRecursive(Node *&node, int key)
    {
        if (node == nullptr) return;

        if (key < node->key)
        {
            DeleteRecursive(node->left, key);
        }
        else if (key > node->key)
        {
            DeleteRecursive(node->right, key);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr;
            }
            else if (node->left == nullptr)
            {
                Node *temp = node;
                node = node->right;
                delete temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node;
                node = node->left;
                delete temp;
            }
            else
            {
                Node* minRightNode = FindMin(node->right);
                node->key = minRightNode->key;
                DeleteRecursive(node->right, minRightNode->key);
            }
        }
    }

    void PreoderWalkRecursive(Node *node)
    {
        if (node == nullptr) return;

        std::cout << node->key << " ";

        PreoderWalkRecursive(node->left);
        PreoderWalkRecursive(node->right);
    }

    void InorderWalkRecursive(Node *node)
    {
        if (node == nullptr) return;

        InorderWalkRecursive(node->left);
        std::cout << node->key << " ";
        InorderWalkRecursive(node->right);
    }

    void PostorderWalkRecursive(Node *node)
    {
        if (node == nullptr) return;

        PostorderWalkRecursive(node->left);
        PostorderWalkRecursive(node->right);
        std::cout << node->key << " ";
    }

    void PrintRangeRecursive(Node *node, int low, int high)
    {
        if (node == nullptr) return;

        if (low <= node->key and node->key <= high)
        {
            std::cout << node->key << " ";
        }

        if (low < node->key)
        {
            PrintRangeRecursive(node->left, low, high);
        }

        if (high > node->key)
        {
            PrintRangeRecursive(node->right, low, high);
        }
    }

    Node* FindMin(Node *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }
};

int main()
{
    BinarySearchTree bst = BinarySearchTree();

    int arr[10] = {30, 40, 50, 24, 8, 58, 48, 26, 11, 13};

    for (int i = 0; i < 10; i++) bst.Insert(arr[i]);

    bst.PreorderWalk();
    bst.InorderWalk();
    bst.PostorderWalk();

    return 0;
}
