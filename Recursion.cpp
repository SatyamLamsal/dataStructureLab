#include <iostream>

class Recursion {
    private:

    public:
        Recursion(){}
        int factorial(int n)
{
    if(n<0) {
        std::cout<<"Invalid input !! "<<std::endl;
        return -1; // Indicate error
    }
    else if (n ==1 || n ==0) return 1;
    else  return n * factorial(n-1);
}

int fibonacci(int n)
{
    if(n<0) {
        std::cout<<"Invalid input !! "<<std::endl;
        return -1; // Indicate error
    }
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}

        int tailRecursionFactorial(int n)
        {
            return tailRecursionFactorialHelper(n, 1);
        }
        int tailRecursionFactorialHelper(int n, int accumulator)
        {
            if(n < 0) {
                std::cout << "Invalid input !! " << std::endl;
                return -1; // Indicating an error
            }
            else if (n == 0 || n == 1) return accumulator;
            else return tailRecursionFactorialHelper(n - 1, n * accumulator);
        }



        int tailRecursionFibonacci(int n)
        {
            return tailRecursionFibonacciHelper(n, 0, 1);
        }
        int tailRecursionFibonacciHelper(int n, int a, int b)
        {
            if(n < 0) {
                std::cout << "Invalid input !! " << std::endl;
                return -1; // Indicating an error
            }
            else if (n == 0) return a;
            else if (n == 1) return b;
            else return tailRecursionFibonacciHelper(n - 1, b, a + b);
        }

        void towerofCanoi(int n, char source, char destination, char auxiliary)
        {
            if (n < 1) {
                std::cout << "Invalid input !! " << std::endl;
                return;
            }
            if (n == 1) {
                std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
                return;
            }
            towerofCanoi(n - 1, source, auxiliary, destination);
            std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
            towerofCanoi(n - 1, auxiliary, destination, source);
        }

};


int main ()

{
    Recursion r;
    std::cout<<"Factorial of 5:"<<r.factorial(5)<<std::endl;
    std::cout<<"Fibonacci of 5:"<<r.fibonacci(5)<<std::endl;
    std::cout<<"Tail Recursion Factorial of 5:"<<r.tailRecursionFactorial(5)<<std::endl;
    std::cout<<"Tail Recursion Fibonacci of 5:"<<r.tailRecursionFibonacci(5)<<std::endl;
    std::cout<<"Tower of Hanoi with 3 disks:"<<std::endl;
    r.towerofCanoi(3, 'A', 'C', 'B');
        return 0;
}