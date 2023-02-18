class Solution {
public:
    int minMaxDifference(int num) {
        string s1 = to_string(num);
        string s2 = to_string(num);
        
        char firstNonNineDigit = s1[0];
        char firstDigit = s1[0];
        
        int max, min;
        int n = s1.size();
    
        for(int i = 0; i < n; i++) {
            if(s1[i] != '9'){
                firstNonNineDigit  = s1[i];
                break;
            }
        }
        
        for(int i = 0; i < n; i++) 
            if(s1[i] == firstNonNineDigit) 
                s1[i] = '9';
        
        for(int i = 0; i < n; i++) 
            if(s2[i] == firstDigit) 
                s2[i] = '0';
        
        max = stoi(s1);
        min = stoi(s2);
        
        return max - min;
    }
};


