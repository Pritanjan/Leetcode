// APPROACH 1  SORTING

class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> v = h;
        // for(auto i : h) {
        //     v.push_back(i);
        // }
        sort(h.begin(), h.end());
        int cnt = 0;
        for(int i = 0; i < h.size(); i++){
            if(h[i] != v[i]) cnt++;
        }
        return cnt;
    }
};




// APPROACH 2 COUNTING SORT

// 1. Use counting sort to count the frequency of each height in the original vector.
// 2. Use this frequency information to reconstruct the sorted order.
// 3. Compare sorted order with original vector & count number of positions where the heights differ.
// 4. Return count.

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> freq(101, 0); 

        // Count the frequency of each height
        for(auto h : heights) {
            freq[h]++;
        }
        
        int cnt = 0;
        int sortedIndex = 0;

        // Reconstruct the sorted order and compare with the original vector
        for(int i=1; i<=100; i++) {
            while(freq[i] > 0) {
                if(heights[sortedIndex] != i) cnt++;
                
                freq[i]--;
                sortedIndex++;
            }
        }        
        return cnt;
    }
};






// APPROACH 3 USE HASH MAP

// 1. Use a hash map to store the frequency of each height in the original vector.
// 2. Traverse heights array from 1 to 100.
// 3. For each height, check if it exists in the hash map. If yes, decrement its frequency and
//    compare its position in the original vector with its expected position in the sorted vector.
// 4. Count the no. of positions where the heights differ.
// 5. Return the count.


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        unordered_map<int, int> freq; // Initialize a hash map to store the frequency of each height
        
        // Count the frequency of each height
        for(int h : heights) freq[height]++;
        
        int cnt = 0;
        int sortedHeight = 1;
        
        // Traverse through heights from 1 to 100
        for(int i=0; i<heights.size(); i++) {
            while(freq[sortedHeight] == 0) sortedHeight++;
            if(heights[i] != sortedHeight) cnt++;
            
            freq[sortedHeight]--;
        }        
        return cnt;
    }
};

