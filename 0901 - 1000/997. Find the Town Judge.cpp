// A 1 - Using 2 Array

// The solution uses two vectors, arr1 and arr2, to keep track of the number of people that a
// given person trusts and the number of people that trust a given person. For each trust 
// relationship in the input list, it increments the corresponding entry in arr1 and arr2.

// It then iterates through all n people and checks if any person has a count of 0 in arr1
// (indicating that they do not trust anyone) and a count of n-1 in arr2 (indicating that 
// everyone in the town trusts them). If such a person is found, it returns their index as
// the town judge. Otherwise, it returns -1 indicating that there is no town judge.

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        vector<int> a(n+1);        // Trusst Count
        vector<int> s(n+1);        // Trusted by count

        for(int i=0; i<t.size(); i++){
            a[t[i][0]]++;
            s[t[i][1]]++;
        }

        for(int i=1; i<=n; i++){
            if(a[i] == 0 && s[i] == n-1) return i;
        }
        return -1;
    }
};






// A 2 - Using 1 Array

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // int n = trust.size();
        vector<int> trustCnt(n+1, 0);
        for(auto& t : trust) {
            trustCnt[t[0]]--;
            trustCnt[t[1]]++;
        }
        for(int i=1; i<=n; i++) {
            if(trustCnt[i] == n-1) return i;
        }
        return -1;
    }
};






// A 3 

