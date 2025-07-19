#include <iostream>
#include <string>

using namespace std;

// =====================
// 1) BST-based map
// =====================
struct BSTNode {
    string key;
    int value;
    BSTNode* left;
    BSTNode* right;
    BSTNode(const string& k, int v)
        : key(k), value(v), left(nullptr), right(nullptr) {}
};

class BSTMap {
    BSTNode* root;

    BSTNode* insertRec(BSTNode* node, const string& key, int value) {
        if (!node) return new BSTNode(key, value);
        if (key == node->key) {
            node->value = value;
        } else if (key < node->key) {
            node->left = insertRec(node->left, key, value);
        } else {
            node->right = insertRec(node->right, key, value);
        }
        return node;
    }

    BSTNode* searchRec(BSTNode* node, const string& key) {
        if (!node || node->key == key) return node;
        if (key < node->key) return searchRec(node->left, key);
        else return searchRec(node->right, key);
    }

    void inorderRec(BSTNode* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->key << " -> " << node->value << "\n";
        inorderRec(node->right);
    }

    void freeRec(BSTNode* node) {
        if (!node) return;
        freeRec(node->left);
        freeRec(node->right);
        delete node;
    }

public:
    BSTMap() : root(nullptr) {}
    ~BSTMap() { freeRec(root); }

    void insert(const string& key, int value) {
        root = insertRec(root, key, value);
    }

    int get(const string& key) {
        BSTNode* p = searchRec(root, key);
        return p ? p->value : -1;
    }

    void printInOrder() {
        inorderRec(root);
    }
};

// =====================
// 2) Hash-table-based unordered_map
// =====================
const int HASH_SIZE = 101;  // prime for fewer collisions

struct HNode {
    string key;
    int value;
    HNode* next;
    HNode(const string& k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMap {
    HNode* table[HASH_SIZE];

    int hashFunc(const string& s) {
        unsigned long h = 0;
        for (char c : s) {
            h = h * 131 + c;
        }
        return h % HASH_SIZE;
    }

public:
    HashMap() {
        for (int i = 0; i < HASH_SIZE; i++)
            table[i] = nullptr;
    }

    ~HashMap() {
        for (int i = 0; i < HASH_SIZE; i++) {
            HNode* cur = table[i];
            while (cur) {
                HNode* tmp = cur;
                cur = cur->next;
                delete tmp;
            }
        }
    }

    void put(const string& key, int value) {
        int idx = hashFunc(key);
        HNode* cur = table[idx];
        while (cur) {
            if (cur->key == key) {
                cur->value = value;
                return;
            }
            cur = cur->next;
        }
        // not found, insert at head
        HNode* node = new HNode(key, value);
        node->next = table[idx];
        table[idx] = node;
    }

    int get(const string& key) {
        int idx = hashFunc(key);
        HNode* cur = table[idx];
        while (cur) {
            if (cur->key == key) return cur->value;
            cur = cur->next;
        }
        return -1;
    }

    bool contains(const string& key) {
        return get(key) != -1;
    }
};

// =====================
// Demo trong main()
// =====================
int main() {
    // BSTMap demo
    cout << "--- BSTMap demo ---\n";
    BSTMap tree;
    tree.insert("banana", 5);
    tree.insert("apple", 3);
    tree.insert("orange", 2);
    tree.insert("banana", 10);  // update
    cout << "apple = " << tree.get("apple") << "\n";
    cout << "banana = " << tree.get("banana") << "\n";
    cout << "In-order traversal:\n";
    tree.printInOrder();

    // HashMap demo
    cout << "\n--- HashMap demo ---\n";
    HashMap hm;
    hm.put("cat", 1);
    hm.put("dog", 2);
    hm.put("bird", 3);
    hm.put("cat", 9);  // update
    cout << "dog = " << hm.get("dog") << "\n";
    cout << "cat = " << hm.get("cat") << "\n";
    cout << "contains(\"lion\"): " << (hm.contains("lion") ? "yes" : "no") << "\n";

    return 0;
}
