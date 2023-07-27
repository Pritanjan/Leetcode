// QUCIK SORT

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



// HEAP SORT

class Solution {
private:
    void heapify(std::vector<int>& arr, int n, int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if(r < n && arr[r] > arr[largest]) largest = r;
        if(l < n && arr[l] > arr[largest]) largest = l;
        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

public:
    void buildHeap(std::vector<int>& arr, int n) {
        for(int i=(n/2)-1; i>=0; i--) heapify(arr, n, i);
        for(int i=n-1; i>=0; i--) {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        buildHeap(arr, n);
        return arr;
    }
};





