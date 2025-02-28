#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // Peak is on the left (including mid)
                right = mid;
            } else {
                // Peak is on the right
                left = mid + 1;
            }
        }
        
        return left;  // or return right (same index)
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    
    int peakIndex = sol.findPeakElement(nums);
    cout << "Peak element index: " << peakIndex << endl;
    
    return 0;
}
