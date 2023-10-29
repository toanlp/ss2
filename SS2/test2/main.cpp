#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Calculator {
private:
    int num1, num2;

public:
    Calculator(int a, int b) {
        num1 = a;
        num2 = b;
    }

    int getMax() {
        return MAX(num1, num2);
    }
};

int main() {
    Calculator calc(5, 10);
    int maxNum = calc.getMax();
    cout << "Max number: " << maxNum << endl;

    return 0;
}