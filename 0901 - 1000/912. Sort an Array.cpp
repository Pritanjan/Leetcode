class Solution {
public:
    void quicksort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int pivot = arr[(left + right) / 2];
            int i = left - 1, j = right + 1;
            while (true) {
                do {
                    i++;
                } while (arr[i] < pivot);
                do {
                    j--;
                } while (arr[j] > pivot);
                if (i >= j) {
                    break;
                }
                swap(arr[i], arr[j]);
            }
            quicksort(arr, left, j);
            quicksort(arr, j + 1, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};


