// https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/451.%20Sort%20Characters%20By%20Frequency.cpp

// A1  Using Map & sorting

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(auto i : s) mp[i]++;       
        sort(s.begin(), s.end(), [&mp] (const char a, const char b){
            return (mp[a] == mp[b]) ? a < b : mp[a] > mp[b];
        });
        return s;
    }
};





// A 2 - Using a Custom Comparator with Priority Queue (Heap)

class Solution {
public:
    string frequencySort(string s) {
        // Create a map to store the frequency of each character.
        unordered_map<char, int> freq;

        // Count the frequency of each character in the string.
        for(char c : s) freq[c]++;
        
        // Create a max-heap (priority queue) based on character frequency.
        priority_queue<pair<int, char>> pq;   // maxHeap
        for(auto& it : freq) {
            pq.push({it.second, it.first});
        }

        // Reconstruct the sorted string.
        string res = "";
        while(!pq.empty()) {
            auto [f, c] = pq.top();
            pq.pop();
            result += string(f, c);
        }
        return res;
    }
};





// A 3 

class Solution {
public:
    static bool compare(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        // Create a map to store the frequency of each character.
        unordered_map<char, int> charFreq;

        // Count the frequency of each character in the string.
        for (char c : s) {
            charFreq[c]++;
        }

        // // Convert the map to a vector of pairs for sorting.
        // vector<pair<char, int>> freqVector(charFreq.begin(), charFreq.end());

        // Convert the map to a vector of pairs for sorting.
        vector<pair<char, int>> freqVector;
        for(auto& entry : charFreq) {
            freqVector.push_back(entry);
        }

        // Sort the vector based on character frequency in descending order.
        sort(freqVector.begin(), freqVector.end(), compare);

        // Reconstruct the sorted string.
        string res = "";
        for(auto& it : freqVector) {
            res += string(it.second, it.first);
        }
        return res;
    }
};





// A 4 -  Using an Array to Count Frequencies

class Solution {
public:
    string frequencySort(string s) {
        // Count the frequency of each character using an array.
        int freq[256] = {0};
        for(char c : s) freq[c]++;
        
        // Create a vector of pairs (character, frequency) for bucket sort.
        vector<pair<char, int>> freqVect;
        for(int i = 0; i < 256; i++) {
            if(freq[i] > 0) {
                freqVect.push_back({(char)(i), freq[i]});
            }
        }

        // Sort the vector based on character frequency in descending order.
        sort(freqVect.begin(), freqVect.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        // Reconstruct the sorted string.
        string res = "";
        for(auto& it : freqVect) {
            res += string(it.second, it.first);
        }
        return res;        
    }
};





// A 5 

class Solution {
public:
    string frequencySort(string s) {
        // Count the frequency of each character using an array.
        int charFreq[256] = {0};
        for(char c : s) charFreq[c]++;

        // Create an array of string buckets to store characters with the same frequency.
        vector<string> v(s.size() + 1, "");
        for(int i=0; i<256; i++) {
            if(charFreq[i] > 0) {
                v[charFreq[i]].append(charFreq[i], static_cast<char>(i));
            }
        }

        // Reconstruct the sorted string by appending characters from buckets.
        string res = "";
        for(int i=s.size(); i>=0; i--) {
            if(!v[i].empty()) {
                res += v[i];
            }
        }
        return res;
    }
};





// A 6 - Using a Multimap for Sorting:

class Solution {
public:
    string frequencySort(string s) {
         // Create a map to store the frequency of each character.
        unordered_map<char, int> charFreq;

        // Count the frequency of each character in the string.
        for(char c : s) {
            charFreq[c]++;
        }

        // Create a multimap to store characters sorted by frequency.
        multimap<int, char, greater<int>> freqMap;
        for(auto& entry : charFreq) {
            freqMap.insert({entry.second, entry.first});
        }

        // Reconstruct the sorted string.
        string res = "";
        for(auto& entry : freqMap) {
            res += string(entry.first, entry.second);
        }
        return res;
    }
};
