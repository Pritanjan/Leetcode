class Solution {
 public:
  int minDeletionSize(vector<string>& A) {
    const int n = A[0].length();
    int ans = 0;

    for (int j = 0; j < n; ++j)
      for (int i = 0; i + 1 < A.size(); ++i)
        if (A[i][j] > A[i + 1][j]) {
          ++ans;
          break;
        }

    return ans;
  }
};




class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        for(int i=0; i<A[0].size(); i++){
            string s;
            for(int j=0; j<A.size(); j++){
                s += A[j][i];
            }

            string s1 = s;
            sort(s1.begin(), s1.end());
            if(s != s1)
                res++;
        }

        return res;
    }
};


// The meaning of the title is: Given an array of strings, arrange these strings into a matrix, 
// and delete those columns that are not sorted alphabetically.

// The idea is also very straightforward. Take out each column directly, and then sort it to see
// if it is equal to the original string. Then you can count the different numbers and maintain 
// and update res



