#include "BinarySearchTree.h"
#include <random>

int main()
{
    BinarySearchTree bst;

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 10'000'000);

    for (int i = 0; i < 1'000'000; i++) {
        bst.Insert(dist(rng));
    }

    std::cout << bst.Height() << std::endl;

    return 0;
}
