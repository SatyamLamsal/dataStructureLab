#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;
public:
    Stack(int size =10);
    ~Stack();
    bool push(T x);
    T pop();
    T peek() const;
    bool isEmpty() const;
    int size() const;

};


template <typename T>
Stack<T>::Stack(int size ) : capacity(size), top(-1) {
        arr = new T[capacity];
    }

template <typename T>
Stack<T>::~Stack() {
        delete[] arr;
    }

template <typename T>
bool Stack<T>::push(T x) {if (top == capacity - 1) return false;arr[++top] = x; return true;}

template <typename T>
T Stack<T>::pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return T(); // Return default value of T
        }
        return arr[top--];
    }

template <typename T>
T Stack<T>::peek() const{
        if (top == -1) {
            cout << "Stack is empty\n";
            return T(); // Return default value of T
        }
        return arr[top];
}

template <typename T>
bool Stack<T>::isEmpty() const {
        return top == -1;
}

template <typename T>
int Stack<T>::size() const {
        return top + 1;
    }