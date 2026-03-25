#include "BinarySearchTree.h"
#include <random>

using namespace std;

int main()
{
    BinarySearchTree bst;

    mt19937 rng(std::random_device{}());
    uniform_int_distribution<int> keyDist(1, 10'000'000);
    uniform_int_distribution<int> opDist(0, 2);

    cout << "Filling the BST with random 1'000'000 numbers..." << endl;
    for (int i = 0; i < 1'000'000; i++) {
        bst.Insert(keyDist(rng));
    }

    cout << "Generated BST's height: " << bst.Height() << endl;

    struct OperationStats
    {
        int visited = 0;
        int count = 0;
    };

    OperationStats searchStats;
    OperationStats insertStats;
    OperationStats deleteStats;

    cout << "Performing 200'000 * 10 operations on BST..." << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 200'000; j++)
        {
            int op = opDist(rng);
            int key = keyDist(rng);

            switch (op)
            {
                case 0:
                    searchStats.count += 1;
                    searchStats.visited += bst.Search(key).visited;
                    break;
                case 1:
                    insertStats.count += 1;
                    insertStats.visited += bst.Insert(key);
                    break;
                case 2:
                    deleteStats.count += 1;
                    deleteStats.visited += bst.Delete(key);
                    break;
            }
        }
    }

    cout << "Size: " << bst.Size() << endl;

    double avgSearch = double(searchStats.visited) / searchStats.count;
    double avgInsert = double(insertStats.visited) / insertStats.count;
    double avgDelete = double(deleteStats.visited) / deleteStats.count;

    cout << "Average visited nodes per Search: " << avgSearch << endl;
    cout << "Average visited nodes per Insert: " << avgInsert << endl;
    cout << "Average visited nodes per Delete: " << avgDelete << endl;

    return 0;
}
