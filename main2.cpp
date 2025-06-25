#include "Stack.h"
#include <iostream>

using namespace std;


int main ()

{
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    cout << "Top element: " << intStack.peek() << endl; // Should print 30
    cout << "Stack size: " << intStack.size() << endl; // Should print 3
    
    while (!intStack.isEmpty()) {
        cout << "Popped element: " << intStack.pop() << endl;
    }
    
    cout << "Is stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;


}