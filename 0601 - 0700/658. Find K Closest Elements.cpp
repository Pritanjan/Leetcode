// A 1 - 2 Pointer
// initialize two pointers L = 0 and R = n-1. Now our window size is n and contains excess elements. 
// We will keep reducing the [L, R] window size till it becomes exactly equal to k. 
// We can do this based on the condition - x - arr[L] <= arr[R] - x. 
// If it is true, then it means arr[R] is farther away from x than arr[L] and
// thus we will eliminate arr[R]. Otherwise, we will eliminate arr[L].

class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int L = 0;
        int R = nums.size() - 1;         
        while(R - L >= k) {
            if(abs(nums[L] - x) <= abs(nums[R] - x))  R--;
            else  L++;
        }
        return vector<int> (nums.begin() + L, nums.begin() + R + 1);        
    }
};

// T.C. --> O(n-k)  as size is keep reducing intinally from n to k, Therefor it is equal to n-k 
// S.C. --> O(1)






// A 2 - Binary Search
// Use two-pointer approach for binary search

class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int L = 0;
        int R = nums.size() - k;            
        while(R > L) {
            int mid = L + (R - L)/2;
            if(x - nums[mid] > nums[mid + k] - x) L = mid + 1;
            else R = mid;
        }
        // return vector<int> (nums.begin() + L, nums.begin() + L + k);   
        
        // Modify the input vector to contain the k closest elements
        nums.erase(nums.begin() + L + k, nums.end());
        nums.erase(nums.begin(), nums.begin() + L);
        return nums;
    }
};








// A 3

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            arr[i] -= x;
        }
        
        sort(arr.begin(), arr.end(),[](int a, int s){
            if(abs(a) == abs(s))  return a < s;
            else  return abs(a) < abs(s);
        });
        
        for(int i=0; i<k; i++){
            ans.push_back(arr[i]+x);
        }            
        sort(ans.begin(), ans.end());
        return ans;
    }
};


// OR
// Custom Comparato

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto compare = [x](int a, int s) {
            if(abs(a - x) == abs(s - x)) return a < s;
            return abs(a - x) < abs(s - x);
        };

        // Sort the array using the custom comparator
        sort(arr.begin(), arr.end(), compare);

        // Take the first k elements as the result
        vector<int> res(arr.begin(), arr.begin() + k);
        sort(res.begin(), res.end());
        return res;
    }
};






// A 4  - Using STL
// Using upper_bound and lower_bound to find the start and end indices of the k closest elements
// lower_bound is used to find the lower bound of x, and then the start and end pointers are
// adjusted to include the k closest elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Find the lower bound of x in arr
        auto lower = lower_bound(arr.begin(), arr.end(), x);

        // Initialize the start and end pointers
        int strt = distance(arr.begin(), lower);
        int end = strt;

        // Expand the range to include k closest elements
        while(end - strt < k) {
            // Check if we can move left
            if(strt == 0) end++;
            // Check if we can move right
            else if(end == arr.size()) strt--;
            // Move left or right based on the absolute difference
            else if(abs(arr[strt - 1] - x) <= abs(arr[end] - x)) strt--;
            else end++;
        }
        return vector<int>(arr.begin() + strt, arr.begin() + end);
    }
};






// A 5 







// A 6 - Exception Handling
// An example that uses exception handling to handle exceptional conditions:
// Implement exception handling to gracefully handle unexpected errors or exceptional conditions 
// that may arise during execution.

vector<int> findClosestElementsWithExceptions(vector<int>& arr, int k, int x) {
    if (k < 0 || k > arr.size()) {
        throw invalid_argument("Invalid value of k");
    }

    if (!is_sorted(arr.begin(), arr.end())) {
        throw runtime_error("Input array is not sorted");
    }

    vector<int> result;
    int left = 0;
    int right = arr.size() - 1;

    // Rest of the code to find k closest elements
    while (k > 0) {
        if (left < 0) {
            result.push_back(arr[right--]);
        } else if (right >= arr.size()) {
            result.push_back(arr[left++]);
        } else {
            int diffLeft = abs(arr[left] - x);
            int diffRight = abs(arr[right] - x);

            if (diffLeft <= diffRight) {
                result.push_back(arr[left++]);
            } else {
                result.push_back(arr[right--]);
            }
        }

        k--;
    }

    reverse(result.begin(), result.end());
    return result;
}





// A 7 - Error Handling and Assertions
// Adding error handling using assertions to check preconditions:

//  assert statements are used to check preconditions, such as the validity of k and whether the 
// input array arr is sorted. Assertions help catch potential issues during development.

vector<int> findClosestElementsWithAssertions(vector<int>& arr, int k, int x) {
    // Check for valid input
    assert(k >= 0 && k <= arr.size());
    assert(is_sorted(arr.begin(), arr.end()));

    int left = 0;
    int right = arr.size() - k;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // Extract the k closest elements
    vector<int> result(arr.begin() + left, arr.begin() + left + k);

    return result;
}






// A 8  - Logging and Profiling
// Adding basic logging and profiling using chrono for timing:
// For performance-critical applications, consider adding logging and profiling to the code
// to track its performance and identify bottlenecks. 
// Profiling tools can help pinpoint areas where optimizations are neede


vector<int> findClosestElementsWithLogging(vector<int>& arr, int k, int x) {
    // Start timing
    auto start_time = high_resolution_clock::now();

    int left = 0;
    int right = arr.size() - k;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // Extract the k closest elements into the result vector
    vector<int> result(arr.begin() + left, arr.begin() + left + k);

    // Stop timing
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    // Log the execution time
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    // Return the result
    return result;
}





 
// A 9 - Handling Duplicates
// An example that handles duplicates and returns all occurrences of the k closest elements:

vector<int> findClosestElementsWithDuplicates(vector<int>& arr, int k, int x) {
    vector<int> result;
    int left = 0;
    int right = arr.size() - 1;

    while (k > 0) {
        if (left < 0) {
            result.push_back(arr[right--]);
        } else if (right >= arr.size()) {
            result.push_back(arr[left++]);
        } else {
            int diffLeft = abs(arr[left] - x);
            int diffRight = abs(arr[right] - x);

            if (diffLeft <= diffRight) {
                result.push_back(arr[left++]);
            } else {
                result.push_back(arr[right--]);
            }
        }

        k--;
    }

    reverse(result.begin(), result.end());
    return result;
}






// A 10 Optimizing for Large Datasets: 
// An example that optimizes for large datasets by using iterators instead of indices:

vector<int> findClosestElementsWithIterators(vector<int>& arr, int k, int x) {
    vector<int> result;
    auto left = arr.begin();
    auto right = arr.end() - 1;

    // Find the initial closest element using binary search
    while (distance(left, right) >= k) {
        auto mid = left + (distance(left, right) - k) / 2;
        if (abs(*mid - x) > abs(*(mid + k) - x)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // Copy the k closest elements to the result vector
    copy(left, left + k, back_inserter(result));

    return result;
}




// A 11 - Parallelization with Threads: 
// An example that uses C++ threads to parallelize the search operation:


void findClosestElementsParallelThread(vector<int>& arr, int k, int x, vector<int>& result, int start, int end) {
    // Perform the search operation on a segment of the array
    int left = start;
    int right = end - k;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    // Copy the k closest elements to the result vector
    for (int i = 0; i < k; ++i) {
        result.push_back(arr[left + i]);
    }
     // copy(arr.begin() + start, arr.begin() + start + k, back_inserter(result));
}



// A 12 

vector<int> findClosestElementsParallel(vector<int>& arr, int k, int x) {
    vector<int> result;
    vector<thread> threads;
    int numThreads = 4;  // Adjust the number of threads as needed

    for (int i = 0; i < numThreads; ++i) {
        int start = i * (arr.size() / numThreads);
        int end = (i == numThreads - 1) ? arr.size() : (i + 1) * (arr.size() / numThreads);

        threads.emplace_back(findClosestElementsParallelThread, ref(arr), k, x, ref(result), start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    // Sort the result vector
    sort(result.begin(), result.end());

    return result;
}





// A 13 

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Handle edge cases
        if(arr.empty() || k == 0) return {};        
        int n = arr.size();
        if(k >= n) return arr;
        
        // Create a multiset to maintain sorted order and handle duplicates
        multiset<pair<int, int>> ms; 
        for(int num : arr) {
            int diff = abs(num - x);
            ms.insert({diff, num});
            
            // Keep only k closest elements
            if(ms.size() > k) ms.erase(prev(ms.end()));
        }
        
        vector<int> res;
        for(auto& p : ms) {
            res.push_back(p.second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};







