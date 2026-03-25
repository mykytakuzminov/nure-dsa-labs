#include <random>
#include <cmath>

#include "BinarySearchTree.h"

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

    cout << "Performing 200'000 * 10 operations on BST..." << endl;

    struct OperationStats
    {
        int count = 0;
        double visited = 0;
        double ratio = 0.0;
    };

    struct HeightStats
    {
        int count = 0;
        double ratioSum = 0.0;
    };

    OperationStats searchStats;
    OperationStats insertStats;
    OperationStats deleteStats;

    HeightStats heightStats;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 200'000; j++)
        {
            int op = opDist(rng);
            int key = keyDist(rng);

            double logN_current = log2(bst.Size());

            switch (op)
            {
                case 0:
                {
                    int visited = bst.Search(key).visited;
                    searchStats.count += 1;
                    searchStats.visited += visited;
                    searchStats.ratio += visited / logN_current;
                    break;
                }
                case 1:
                {
                    int visited = bst.Insert(key);
                    insertStats.count += 1;
                    insertStats.visited += visited;
                    insertStats.ratio += visited / logN_current;
                    break;
                }
                case 2:
                {
                    int visited = bst.Delete(key);
                    deleteStats.count += 1;
                    deleteStats.visited += visited;
                    deleteStats.ratio += visited / logN_current;
                    break;
                }
            }

            if ((i * 200'000 + j) % 10000 == 0) {
                heightStats.ratioSum += double(bst.Height()) / logN_current;
                heightStats.count += 1;
            }
        }
    }

    cout << "Results: " << endl;

    double avgVisitedNodesPerSearch = searchStats.visited / searchStats.count;
    double avgVisitedNodesPerInsert = insertStats.visited / insertStats.count;
    double avgVisitedNodesPerDelete = deleteStats.visited / deleteStats.count;

    double avgRatioToLogNPerSearch = searchStats.ratio / searchStats.count;
    double avgRatioToLogNPerInsert = insertStats.ratio / insertStats.count;
    double avgRatioToLogNPerDelete = deleteStats.ratio / deleteStats.count;

    double avgHeightRatio = heightStats.ratioSum / heightStats.count;

    // 1.0 -> perfect balanced tree
    // 2.0 -> tree pases x2 nodes
    // ...
    // ~50.0 -> tree degradation
    cout << "Average visited nodes per Search: " << avgVisitedNodesPerSearch
        << " (ratio to log2(n): " << avgRatioToLogNPerSearch << ")" << endl;
    cout << "Average visited nodes per Insert: " << avgVisitedNodesPerInsert
        << " (ratio to log2(n): " << avgRatioToLogNPerInsert << ")" << endl;
    cout << "Average visited nodes per Delete: " << avgVisitedNodesPerDelete
        << " (ratio to log2(n): " << avgRatioToLogNPerDelete << ")" << endl;

    cout << "Average height ratio (Height / log2(Size)) : " << avgHeightRatio << endl;

    return 0;
}
