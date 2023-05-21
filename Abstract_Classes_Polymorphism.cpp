#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val)
        : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {
protected:
    map<int, Node*> mp; // map the key to the node in the linked list
    int cp;             // capacity
    Node* tail;         // double linked list tail pointer
    Node* head;         // double linked list head pointer
    virtual void set(int, int) = 0; // set function
    virtual int get(int) = 0;       // get function
};

class LRUCache : public Cache {
public:
    LRUCache(int cp) {
        this->cp = cp;
        this->head = NULL;
        this->tail = NULL;
    }

    void set(int key, int value) override {
        Node* curr = head;
        int count = 0;

        while (curr != NULL) {
            if (curr->key == key) {
                if (curr->value != value)
                    curr->value = value;
                if (curr == head)
                    return;
                if (curr->next)
                    curr->next->prev = curr->prev;
                if (curr->prev)
                    curr->prev->next = curr->next;
                curr->next = head;
                curr->prev = NULL;
                head->prev = curr;
                head = curr;
                return;
            }
            count++;
            curr = curr->next;
        }

        Node* newNode = new Node(NULL, head, key, value);
        if (head != NULL)
            head->prev = newNode;
        head = newNode;

        if (count == 0)
            tail = newNode;

        if (count == cp) {
            tail = tail->prev;
            tail->next = NULL;
        }

        return;
    }

    int get(int key) override {
        Node* curr = head;

        while (curr != NULL) {
            if (curr->key == key)
                return curr->value;
            curr = curr->next;
        }

        return -1;
    }
};

int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        } else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
