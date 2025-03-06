#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// Optimized BFS approach to generate all unique super bit strings
unordered_set<int> generateSuperBitStrings(int num, int n) {
    unordered_set<int> super_strings;
    queue<int> q;

    // Start with the original number
    q.push(num);
    super_strings.insert(num);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // Try flipping each '0' to '1'
        for (int i = 0; i < n; i++) {
            if ((curr & (1 << i)) == 0) {  // If bit i is 0
                int new_num = curr | (1 << i);  // Flip it to 1
                
                if (super_strings.find(new_num) == super_strings.end()) {
                    super_strings.insert(new_num);
                    q.push(new_num);
                }
            }
        }
    }

    return super_strings;
}

// Function to count unique super bit strings across all numbers
int superBitStrings(int n, const vector<int> &bitStrings) {
    unordered_set<int> unique_super_strings;
    unordered_set<int> vis(bitStrings.begin(), bitStrings.end()); // Remove duplicates

    for (int num : vis) {
        unordered_set<int> super_strings = generateSuperBitStrings(num, n);
        unique_super_strings.insert(super_strings.begin(), super_strings.end());
    }

    return unique_super_strings.size();
}

// Main function
int main() {
    int n = 5;
    vector<int> bitStrings = {10, 26}; // Example case

    cout << superBitStrings(n, bitStrings) << endl; // Expected output: 8
    

    n=3;
    bitStrings = {2,2,6};
    
    cout << superBitStrings(n, bitStrings) << endl; // Expected output: 4

    n=10;
    bitStrings = {200000, 103000, 190000, 134000, 100900, 199933};
    
    cout << superBitStrings(n, bitStrings) << endl; // Expected output: 8

    return 0;
}