#include <iostream>
#include "Tree24.h"
using namespace std;

int main() {
    Tree24* tree = new Tree24();

    tree->insert(13);
    tree->insert(4);
    tree->insert(26);
    tree->insert(5);
    tree->insert(17);
    tree->print();
    return 0;
}
