// A 1 

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt[26] = {};
        int ans = 0;
        for(auto ch : sentence){
            if(++cnt[ch - 'a'] == 1)
                ans++;
        }
        return ans == 26;
    }
};




// A 2 

class Solution {
    public boolean checkIfPangram(String sentence) {
        int[] freq = getFrequencyArray(sentence);
        for (int i = 0; i < freq.length; i++) {
            if (freq[i] == 0)
                return false;
        }
        return true;

    }

    public static int[] getFrequencyArray(String s1) {
        int[] freq = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            char ch = s1.charAt(i);
            freq[ch - 97]++;
        }
        return freq;
    }
}



// A 3 

class Solution {
public:
    bool checkIfPangram(string s) {
        return set<char>(s.begin(), s.end()).size() == 26;
    }
};





// A 4 


class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<int> s;
        for (auto& c: sentence)
            s.insert(c);
        return s.size() == 26;
    }
};


     
