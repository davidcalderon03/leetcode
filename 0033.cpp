class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            if (high - low == 1) {
                if (nums[low] == target) return low;
                if (nums[high] == target) return high;
            }
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            if (nums[low] < nums[mid] && target < nums[mid] && target >= nums[low]) {
                high = mid - 1;
            } else if (nums[low] < nums[mid] && (target > nums[mid] || target < nums[low])) {
                low = mid + 1;
            } else if (nums[mid] < nums[high] && target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[high] && (target < nums[mid] || target > nums[high])) {
                high = mid - 1;
            } else {
                high = mid - 1;
            }
            std::cout << std::endl;
        }
        return -1;
    }
};
