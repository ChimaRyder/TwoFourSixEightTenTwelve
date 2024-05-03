#include "../../AppData/Local/JetBrains/CLion 2024.1/bin/mingw/x86_64-w64-mingw32/include/stdlib.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
    int* data;
    Node** children;
    int size;
    Node* parent;

    public:
    Node(int num, Node* parent) {
        data = (int*) malloc(4*sizeof(int));
        data[0] = num;

        size = 1;
        this->parent = parent;

        children = (Node**) calloc(5, sizeof(Node*));
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 5; i++) {
            if (children[i]) {
                children[i]->print();
            }
        }
    }

    int GetData(int i) {
        return this->data[i];
    }

    Node* GetChild(int i) {
        return this->children[i];
    }

    Node* GetParent() {
        return this->parent;
    }

    int GetSize() {
        return this->size;
    }

    bool addKey(int num) {
        //return true if ok
        int i;
        for (i = size; i > 0; i--) {
            if (data[i-1] > num) {
                data[i] = data[i-1];
            } else {
                break;
            }
        }

        data[i] = num;
        //return false if not ok
        return ++size != 4;
    }

    int indexOf (int num) {
        for (int i = 0; i < size; i++) {
            if (num == data[i]) {
                return i;
            }
        }
    }

    void insertChildren(Node* wp, Node* w2p, int pos) {
        for (int i = size - 1; i > pos; i--) {
            children[i+1] = children[i];
        }
        children[pos] = wp;
        children[pos+1] = w2p;
    }
};

