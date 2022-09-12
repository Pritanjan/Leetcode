// https://leetcode.com/problems/bag-of-tokens/

class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int p) {
        sort(t.begin(), t.end());
        int score = 0;
        int current_score = 0;
        int L = 0;
        int R = t.size() - 1;
        
        while(L <= R){
            if(t[L] <= p){
                current_score += 1;
                score = max(score, current_score);
                p -= t[L++];
            }
            else if(current_score > 0){
                current_score -= 1;
                p += t[R--];
            }
            else 
                break;
        }
        return score;
    }
};

// p >= t[i];  s = 1  p = p-t[i]

// s = 1;  p += t[i] s = s-1    

// 100 200 300 400 
    
// L = 0;
// R = 3;
// p = 200 



// // Step 1
// L = 0; R = 3 -->  L < R   
// t[L] = t[0] = 100 < 200
// cs = 1
// score = 1
// p = 200 - 100 = 100 

// L = 1 R = 3
    
// // step 2
// cs > 0
//     cs = 0
//     p = t[R] = t[3] = 400 + 100 = 500

// L = 1, R = 2

// // Step 3 
// t[L] = t[1] = 200 < 500
//     s = 1
//     cs = 1
//     p -= 500 - t[1] = 300
    
// L = 2, R = 2

// // step 4 
// cs > 0
// cs = 0
// p = p + t[2] = 600 
