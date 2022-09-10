//https://leetcode.com/problems/find-and-replace-pattern/

//Convert pattern to a code. For eg: code for abcbe will be 12324
//Step 1 requires a map. If a particular character is found eariler, its value from map will be fetched.
//Then for every word in the vector, finding its equivalent code and comparing it with the pattern's code.
//If that matches then adding the word to the answer vector.

class Solution {
public:
    // Converting pattern to code (in numbers)
//     string convertToCode(string p){
//         unordered_map <char, int> ump;
//         string code ;
//         // int cnt = 1;
        
//         for(auto i : p){
//             if(ump.find(i) == ump.end()){
//                 code += cnt + '0';
//                 ump.insert({i, cnt});
//                 cnt++;
//             }else{
//                 code += ump[i] + '0';
//             }          
//         }
//         return code;  
//     }
    // Converting pattern to code (in words)
    string convertToCode(string p){
        unordered_map <char, int> ump;
        char c = 'a';
        for(auto i : p){
            if(!ump.count(i))
                ump[i] = c++;
        }
        for(auto& i : p){
            i = ump[i];
        }
        return p;
    }
        
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        string code = convertToCode(p);
        vector<string> ans;
        for(auto i : w){
            if(convertToCode(i) == code)
                ans.push_back(i);
        }  
        return ans;
    }
};

// T.C. , S.C. --> O(N*l)
