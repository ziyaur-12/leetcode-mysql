class Solution {
public:

    int partition(vector<int>& nums, int start, int end) {

        int pivot = nums[end];

        int i = start;

        for(int j = start; j < end; j++) {

            if(nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[end]);

        return i;
    }

    int quickSelect(vector<int>& nums, int start, int end, int k) {

        int pivotIndex = partition(nums, start, end);

        if(pivotIndex == k) {
            return nums[pivotIndex];
        }

        if(pivotIndex > k) {
            return quickSelect(nums, start, pivotIndex - 1, k);
        }

        return quickSelect(nums, pivotIndex + 1, end, k);
    }

    int findKthLargest(vector<int>& nums, int k) {

        int target = k - 1;

        return quickSelect(nums, 0, nums.size() - 1, target);
    }
};