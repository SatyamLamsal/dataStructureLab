#include <iostream>
#define MAX 5
using namespace std;

class LQ {
    int a[MAX], f = -1, r = -1;
public:
    void enq(int v) { if (r == MAX - 1) cout << "Overflow\n"; else { if (f == -1) f = 0; a[++r] = v; } }
    void deq() { if (f == -1 || f > r) cout << "Underflow\n"; else f++; }
    void show() { if (f == -1 || f > r) cout << "Empty\n"; else { cout << "LQ: "; for (int i = f; i <= r; i++) cout << a[i] << " "; cout << "\n"; } }
};

class CQ {
    int a[MAX], f = -1, r = -1;
public:
    void enq(int v) {
        if ((f == 0 && r == MAX - 1) || (r + 1) % MAX == f) cout << "Overflow\n";
        else { if (f == -1) f = 0; r = (r + 1) % MAX; a[r] = v; }
    }
    void deq() {
        if (f == -1) cout << "Underflow\n";
        else f == r ? f = r = -1 : f = (f + 1) % MAX;
    }
    void show() {
        if (f == -1) cout << "Empty\n";
        else { cout << "CQ: "; for (int i = f; ; i = (i + 1) % MAX) { cout << a[i] << " "; if (i == r) break; } cout << "\n"; }
    }
};

class DQ {
    int a[MAX], f = -1, r = -1;
public:
    void addF(int v) {
        if ((f == 0 && r == MAX - 1) || f == r + 1) cout << "Overflow\n";
        else { if (f == -1) f = r = 0; else f = (f == 0) ? MAX - 1 : f - 1; a[f] = v; }
    }
    void addR(int v) {
        if ((f == 0 && r == MAX - 1) || f == r + 1) cout << "Overflow\n";
        else { if (f == -1) f = r = 0; else r = (r + 1) % MAX; a[r] = v; }
    }
    void delF() {
        if (f == -1) cout << "Underflow\n";
        else f == r ? f = r = -1 : f = (f + 1) % MAX;
    }
    void delR() {
        if (f == -1) cout << "Underflow\n";
        else f == r ? f = r = -1 : r = (r == 0) ? MAX - 1 : r - 1;
    }
    void show() {
        if (f == -1) cout << "Empty\n";
        else { cout << "DQ: "; for (int i = f; ; i = (i + 1) % MAX) { cout << a[i] << " "; if (i == r) break; } cout << "\n"; }
    }
};

int main() {
    LQ l; CQ c; DQ d;
    l.enq(1); l.enq(2); l.enq(3); l.show(); l.deq(); l.show();
    c.enq(10); c.enq(20); c.enq(30); c.show(); c.deq(); c.show();
    d.addF(100); d.addR(200); d.show(); d.delF(); d.show();
}