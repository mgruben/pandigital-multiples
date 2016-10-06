#include <string>
#include <iostream>
#include <algorithm> // std::min
#include <vector>
using namespace std;

/**
 * Given a string of digits of length n, return true if those
 * digits are 1 through n, exactly once.
 * 
 * Otherwise, return false.
 */
bool isPandigital(string s) {
    sort(begin(s), end(s));
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != i+1 + '0') return false;
    }
    return true;
}

/**
 * Given a number n and a vector v, concatenate the products of each
 * integer in the vector with the number, and return the concatenation.
 * 
 * Ex. 192, (1,2,3) -> 192384576
 */
int concatenateProducts(int n, vector<int> v) {
    string ans = "";
    for (int i : v) {
        ans += to_string(n * i);
    }
    return stoi(ans);
}

/**
 * Find the largest 1-9 pandigital number that can be formed as the
 * concatenated product of (1, 2, 3, ..., n) and an integer,
 */
int largestPandigital(vector<int> v, int largest, int start, int stop) {
    int thisProd;
    for (int j = start; j < stop; j++) {
        thisProd = concatenateProducts(j, v);
        if (isPandigital(to_string(thisProd)) &&
            thisProd > largest) {
            largest = thisProd;
        }
    }
    return largest;
}
 
int main() {
    vector<int> v = {1, 2};
    int largest = 0;
    largest = largestPandigital(v, largest, 5000, 10000);
    v.push_back(3);
    largest = largestPandigital(v, largest, 100, 333);
    v.push_back(4);
    largest = largestPandigital(v, largest, 25, 33);
    v.push_back(5);
    largest = largestPandigital(v, largest, 9, 10);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    largest = largestPandigital(v, largest, 1, 2);
    cout << largest << endl;
    return 0;
}
