
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n <= 0){
            return false;
        }

        while(n % 2 == 0){
            n = n / 2;
        }

        return n == 1;
    }
};

int main() {

    Solution obj;

    int n = 16;

    bool result = obj.isPowerOfTwo(n);

    if(result){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}
