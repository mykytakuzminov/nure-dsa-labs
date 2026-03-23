#include <iostream>

class BinarySearchTree
{
private:
    struct Node
    {
        int value;
        Node *left = nullptr;
        Node *right = nullptr;

        Node(int value)
        {
            this->value = value;
        }
    };

    Node *root = nullptr;

public:
    BinarySearchTree() {};

    void Insert(int value)
    {
        InsertRecursive(root, value);
    }

    void Remove(int value)
    {
        RemoveRecursive(root, value);
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

    void Print(int low, int high)
    {
        PrintRecursive(root, low, high);
        std::cout << std::endl;
    }

private:
    void InsertRecursive(Node *&node, int value)
    {
        if (node == nullptr)
        {
            node = new Node(value);
            return;
        }

        if (value < node->value)
        {
            InsertRecursive(node->left, value);
        }
        if (value > node->value)
        {
            InsertRecursive(node->right, value);
        }
    }

    void RemoveRecursive(Node *&node, int value)
    {
        if (node == nullptr) return;

        if (value < node->value)
        {
            RemoveRecursive(node->left, value);
        }
        else if (value > node->value)
        {
            RemoveRecursive(node->right, value);
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
                node->value = minRightNode->value;
                RemoveRecursive(node->right, minRightNode->value);
            }
        }
    }

    void PreoderWalkRecursive(Node *node)
    {
        if (node == nullptr) return;

        std::cout << node->value << " ";

        PreoderWalkRecursive(node->left);
        PreoderWalkRecursive(node->right);
    }

    void InorderWalkRecursive(Node *node)
    {
        if (node == nullptr) return;

        InorderWalkRecursive(node->left);
        std::cout << node->value << " ";
        InorderWalkRecursive(node->right);
    }

    void PostorderWalkRecursive(Node *node)
    {
        if (node == nullptr) return;

        PostorderWalkRecursive(node->left);
        PostorderWalkRecursive(node->right);
        std::cout << node->value << " ";
    }

    void PrintRecursive(Node *node, int low, int high)
    {
        if (node == nullptr) return;

        if (low <= node->value and node->value <= high)
        {
            std::cout << node->value << " ";
        }

        if (low < node->value)
        {
            PrintRecursive(node->left, low, high);
        }

        if (high > node->value)
        {
            PrintRecursive(node->right, low, high);
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
