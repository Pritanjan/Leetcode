// A 1

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        for(string & word :words){
            bool flag = true;
            for(int i=0; i<word.length(); i++) {
                char currChar = word.at(i);
                bool isFind = false;

                for(int j=0; j<allowed.size(); j++) {
                    if(allowed[j] == currChar) {
                        isFind = true;
                        break;
                    }
                }

                if(!isFind) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};





// A 2 

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int consistentCount = 0;

        for (const string& word : words) {
            bool isConsistent = true;
            for (char ch : word) {
                if (allowedSet.find(ch) == allowedSet.end()) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
