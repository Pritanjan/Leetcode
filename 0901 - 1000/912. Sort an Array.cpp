// A 1 STL

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // stable_sort(nums.begin(), nums.end());
        return {nums.begin(),nums.end()} ;
    }
};






// A 2 - QUCIK SORT

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






// A 3 - HEAP SORT

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






// A 4 - MERGE SORT

class Solution {
    // Function to merge two sub-arrays in sorted order.
    void merge(vector<int> &arr, int L, int mid, int R, vector<int> &tempArr) {
        // Calculate the start and sizes of two halves.
        int strt1 = L;
        int strt2 = mid + 1;
        int n1 = mid - L + 1;
        int n2 = R - mid;
        
        // Copy elements of both halves into a temporary array.
        for(int i=0; i<n1; i++) tempArr[strt1 + i] = arr[strt1 + i];
        for(int i=0; i<n2; i++) tempArr[strt2 + i] = arr[strt2 + i];

        // Merge the sub-arrays 'in tempArray' back into the original array 'arr' in sorted order.
        int i = 0;
        int j = 0;
        int k = L;
        
        while(i < n1 && j < n2) {
            if(tempArr[strt1 + i] <= tempArr[strt2 + j]) {
                arr[k] = tempArr[strt1 + i];
                i++;
            } 
            else {
                arr[k] = tempArr[strt2 + j];
                j++;
            }
            k++;
        }

        // Copy remaining elements
        while(i < n1) {
            arr[k] = tempArr[strt1 + i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = tempArr[strt2 + j];
            j++;
            k++;
        }
    }

    // Recursive function to sort an array using merge sort
    void mergeSort(vector<int>& arr, int L, int R, vector<int>& tempArr) {
        if(L >= R) return ;
        int mid = L + (R - L) / 2;
        
        // Sort first and second halves recursively.
        mergeSort(arr, L, mid, tempArr);
        mergeSort(arr, mid + 1, R, tempArr);
        
        // Merge the sorted halves.
        merge(arr, L, mid, R, tempArr);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tempArr(nums.size());
        mergeSort(nums, 0, nums.size() - 1, tempArr);
        return nums;
    }
};






