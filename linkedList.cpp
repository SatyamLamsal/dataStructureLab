#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int val = 0;
        Node* Nd = NULL;
    };

    Node* Head = NULL;
    Node* Iterator = NULL;

public:
    LinkedList() {
        Head = new Node;               // Dummy head
        Head->Nd = new Node;           // First real node
    }

    // Append to end
    bool Insert(int insertVal) {
        Iterator = Head->Nd;
        while (Iterator->Nd != NULL) {
            Iterator = Iterator->Nd;
        }
        Iterator->val = insertVal;
        Iterator->Nd = new Node;
        return true;
    }

    // View the entire list
    void ViewList() {
        Iterator = Head->Nd;
        while (Iterator->Nd != NULL) {
            cout << Iterator->val << endl;
            Iterator = Iterator->Nd;
        }
    }

    // Insert at specific index (0-based)
    bool InsertAtPosition(int val, int pos) {
        if (pos < 0) return false;

        Node* temp = Head;
        for (int i = 0; i < pos; ++i) {
            if (temp->Nd == NULL || temp->Nd->Nd == NULL) return false;
            temp = temp->Nd;
        }

        Node* newNode = new Node;
        newNode->val = val;
        newNode->Nd = temp->Nd;
        temp->Nd = newNode;
        return true;
    }

    // Remove at index (0-based)
    bool RemoveAtPosition(int pos) {
        if (pos < 0) return false;

        Node* temp = Head;
        for (int i = 0; i < pos; ++i) {
            if (temp->Nd == NULL || temp->Nd->Nd == NULL) return false;
            temp = temp->Nd;
        }

        Node* toDelete = temp->Nd;
        if (toDelete == NULL || toDelete->Nd == NULL) return false;

        temp->Nd = toDelete->Nd;
        delete toDelete;
        return true;
    }

    // Insert after a value
    bool InsertAfterValue(int targetVal, int val) {
        Iterator = Head->Nd;
        while (Iterator->Nd != NULL) {
            if (Iterator->val == targetVal) {
                Node* newNode = new Node;
                newNode->val = val;
                newNode->Nd = Iterator->Nd;
                Iterator->Nd = newNode;
                return true;
            }
            Iterator = Iterator->Nd;
        }
        return false;
    }

    // Remove after a node with target value
    bool RemoveAfterValue(int targetVal) {
        Iterator = Head->Nd;
        while (Iterator->Nd != NULL) {
            if (Iterator->val == targetVal && Iterator->Nd->Nd != NULL) {
                Node* toDelete = Iterator->Nd;
                Iterator->Nd = toDelete->Nd;
                delete toDelete;
                return true;
            }
            Iterator = Iterator->Nd;
        }
        return false;
    }

    ~LinkedList() {
        Node* Temp = NULL;
        Iterator = Head->Nd;
        delete Head;

        while (Iterator->Nd != NULL) {
            Temp = Iterator->Nd;
            delete Iterator;
            Iterator = Temp;
        }
        delete Iterator;
    }
};

// === Example Usage ===
int main() {
    LinkedList Lst1;
    Lst1.Insert(5);
    Lst1.Insert(7);
    Lst1.Insert(8);
    Lst1.Insert(9);

    cout << "\nOriginal list:\n";
    Lst1.ViewList();

    cout << "\nInsert 99 at position 2:\n";
    Lst1.InsertAtPosition(99, 2);
    Lst1.ViewList();

    cout << "\nRemove at position 1:\n";
    Lst1.RemoveAtPosition(1);
    Lst1.ViewList();

    cout << "\nInsert 88 after value 8:\n";
    Lst1.InsertAfterValue(8, 88);
    Lst1.ViewList();

    cout << "\nRemove node after value 5:\n";
    Lst1.RemoveAfterValue(5);
    Lst1.ViewList();
}
