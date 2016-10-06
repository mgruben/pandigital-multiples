#include <sstream>
#include <iostream>
#include <algorithm> // std::sort
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
    stringstream tmp;
    for (int i : v) {
        tmp << to_string(n * i);
    }
    string ans;
    tmp >> ans;
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
    int largest = 0;
    
    // Check from 500,010,000 to 999,919,998
    vector<int> v = {1, 2};
    largest = largestPandigital(v, largest, 5000, 10000);
    
    // Check from 100,200,300 to 333,666,999
    v.push_back(3);
    largest = largestPandigital(v, largest, 100, 333);
    
    // Check from 255,075,100 to 336,699,132
    v.push_back(4);
    largest = largestPandigital(v, largest, 25, 33);
    
    // Check 918,273,645
    v.push_back(5);
    largest = largestPandigital(v, largest, 9, 10);
    
    // Check 123,456,789
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    largest = largestPandigital(v, largest, 1, 2);
    
    // Display the result
    cout << largest << endl;
    return 0;
}
