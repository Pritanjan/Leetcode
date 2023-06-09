// APPROACH 1 [ BINARY SEARCH ]

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int L = 0;
        int R = letters.size();
        int mid;
        
        while(L < R){
            int mid = (L+R)/2;
            if(letters[mid] <=target) L = mid + 1; 
            else R = mid ;
        }

        if(letters[L] > target) return letters[L];
        else return letters[0];
    }
};






// APPROACH 2 [ LINEAR SEARCH ]


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        for(int i=0; i<n; i++){
            if(letters[i] > target) return letters[i];
        }
        return letters[0];
    }
};


// T.C. --> O(N)
// S.C. --> O(1)








// APPROACH 3 [ COUNTING SORT]

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> cnt(26);
        for(char c : letters) {
            cnt[c - 'a']++;
        }

        for(char c = (char)(target+1); c<='z'; c++) {
            if(cnt[c - 'a'] > 0) {
                return c;
            }
        }

        for(char c='a'; c<=target; c++) {
            if(cnt[c - 'a'] > 0) {
                return c;
            }
        }
        return letters[0];
    }
};

