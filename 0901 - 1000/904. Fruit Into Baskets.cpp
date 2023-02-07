// https://leetcode.com/problems/fruit-into-baskets/solutions/2960000/fruit-into-baskets/

SEE IT FOR DETAIL SOLUTION 


// Focus on the mathematical part of the problem, 
// This question equals: 
// Given an array of integers, find the longest subarray that contains at most 2 unique integers.
// (We will call such subarray a valid subarray for convenience)


// APPROACH 1 :- BRUTE FORCE

// Most straight forward method, brute force! That is, to check every subarray and
// find out the longest valid one.

// Steps are :
// 1. Iterate over all subarrays.
// 2. For each subarray, we count the types of fruits it contains. 
//    If the subarray has no more than 2 types of fruits, meaning it is valid, 
//    we take its length to update the maximum length.








// APPROACH 3 :- Sliding Window

class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int, int> cnt;
        int L = 0, R = 0;
        
        while(R < f.size()){              //iterate over the array
            cnt[f[R]]++;                  //increase frequency at current index

            if(cnt.size() > 2){          //if size of map > (2)
                cnt[f[L]]--;              //decrease left index frequency

                if(cnt[f[L]] == 0) cnt.erase(f[L]);  //if freq==0
                L++;                      //left index ++(removing from window)
            }
            R++;                          //right index at each iteration ++
        }
        return R - L;                      //final window size
    }
};


// Same

class Solution {
public:
  int totalFruit(vector<int>& tree) {
    int ans = 0;
    unordered_map<int, int> count;

    for (int l = 0, r = 0; r < tree.size(); ++r) {
      ++count[tree[r]];
      while (count.size() > 2) {
        if (--count[tree[l]] == 0)
          count.erase(tree[l]);
        ++l;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};






