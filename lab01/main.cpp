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

    void Print()
    {
        PrintRecursive(root);
    }

    void Print(int low, int high)
    {
        PrintRecursive(root, low, high);
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

    void PrintRecursive(Node *node)
    {
        if (node == nullptr) return;

        std::cout << node->value << " ";

        PrintRecursive(node->left);
        PrintRecursive(node->right);
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
};

int main()
{
    BinarySearchTree tree = BinarySearchTree();

    int arr[10] = {30, 40, 50, 24, 8, 58, 48, 26, 11, 13};

    for (int i = 0; i < 10; i++) tree.Insert(arr[i]);

    tree.Print();
    std::cout << "" << std::endl;
    tree.Print(12, 45);
    return 0;
}
