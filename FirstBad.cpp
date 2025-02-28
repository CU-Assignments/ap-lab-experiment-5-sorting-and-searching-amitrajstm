#include <iostream>

// Mock API function
bool isBadVersion(int version) {
    // Assume bad version is 4 (For testing purpose)
    return version >= 4;  
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;  // Avoid integer overflow
            if (isBadVersion(mid)) {
                high = mid;  // Search left
            } else {
                low = mid + 1;  // Search right
            }
        }
        return low;  // Found the first bad version
    }
};

int main() {
    Solution sol;
    int n = 5;  // Example input
    std::cout << "First bad version: " << sol.firstBadVersion(n) << std::endl;
    return 0;
}
