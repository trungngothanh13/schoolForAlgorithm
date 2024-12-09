#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree Tree;
    srand(time(0));
    int depth;
    cin >> depth;
    while (Tree.getDepth() < depth) {
        int random_i = rand() % 2;
        switch (random_i)    
        {
        case 0:
            break;
        case 1:
            int value = rand() % 100;
            Tree.insert(value);
            break;
        }
    }

    Tree.printTreeVisually();

    return 0;
}
