#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 5;
const int COINS[SIZE] = {50, 10, 5, 2, 1};

unsigned int hashFunc(const char *str) {
    int i = 0, res = 0;
    while (str[i] != '\0') {
        res += str[i];
        i++;
    }
    return res;
}

bool greedyCount(int val, vector<int> &v){
    int sum = 0, i = 0;
    while (i < SIZE){
        if (sum + COINS[i] <= val){
            sum += COINS[i];
            v.push_back(COINS[i]);
        }
        else {
            i++;
        }
        if (sum == val) return true;
    }
    return false;
}


int main() {
    // Task 1
    char arr[90] = "Hello world!";
    cout << "before hash function = " << arr << endl;
    cout << "after hash function  = " << hashFunc(arr) << endl;
    cout << endl << endl;

    // Task 2
    vector<int> vec;
    int val = 98;
    greedyCount(val, vec);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if(i != vec.size() - 1) cout << " + ";
    }

    cout << " = " << val;

    return 0;
}
