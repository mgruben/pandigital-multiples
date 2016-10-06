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
string concatenateProducts(int n, vector<int> v) {
    /* For each factor we find, n / (that factor) is itself
     * another factor, so add that to our sum as well.
     * 
     * Loop until i = sqrt(n), because this is the limit
     * for factors of n we haven't found yet.
     */ 
    for (int i = 1; i*i <= n; i++) {
        string s = to_string(n);
        if ((n % i) == 0) {
            s += to_string(i);
            s += to_string(n/i);
            if (s.length() == 9 && isPandigital(s)) return "true";
        }
    }
    return "false";
}

/**
 * Find the largest 1-9 pandigital number that can be formed as the
 * concatenated product of (1, 2, 3, ..., n) and an integer,
 */
int main() {
    vector<int> v = {1,2};
    
    return 0;
}
