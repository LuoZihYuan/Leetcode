#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int a = 0, b = 1;
        for (int i = 1; i < n; i++){
          int sum = a + b;
          a = b;
          b = sum;
        }
        return b;
    }
};

int main() {

  return 0;
}