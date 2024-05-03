#include "Node.h"

class Tree24 {
    Node* root;
    int size;

    Node* search_node(int num, Node* n) {
        int index = n->GetSize();

        for (int i = 0; i < n->GetSize(); i++) {
            if (num == n->GetData(i)) {
                return n;
            }

            if (num < n->GetData(i)) {
                index = i;
                break;
            }
        }

        if (!n->GetChild(index)) {
            return n;
        }

        return search_node(num, n->GetChild(index));
    }

public:
    Tree24() {
        size = 0;
        root = NULL;
    }

    Node* search (int num) {
        return search_node(num, root);
    }

    void insert(int num) {

        //if walay root, add root
        if (!root) {
          root = new Node(num, NULL);
        } else {
            Node* w = search(num);
            bool ok = w->addKey(num);
            if (!ok) {

                while (!ok) {
                    Node* u;
                    int pos;

                    if (w == root) {
                        u = new Node(w->GetData(2),NULL);
                        root = u;
                        pos = 0;
                        ok = true;
                    } else {
                        u = w->GetParent();
                        ok = u->addKey(w->GetData(2));
                        pos = u->indexOf(w->GetData(2));
                    }

                    Node* wp = new Node(w->GetData(0), u);
                    wp->addKey(w->GetData(1));
                    Node* w2p = new Node(w->GetData(3), u);

                    u->insertChildren(wp, w2p, pos);
                    w = u;
                }
            }
        }

        this->size++;
    }

    void print() {
        cout << "Size: " << size << endl;
        root->print();
    }
};
