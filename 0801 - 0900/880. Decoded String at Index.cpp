class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int N = S.size();
        long size = 0;
 
        // finding size = length of new string S'
        for(int i=0; i<N; ++i) {
            if(isdigit(S[i]))
                size = size*(S[i] - '0');
            else
                size += 1;
        }
 
        // get the K-th letter
        for (int i=N-1; i>=0; --i){
            K %= size;
            
            if(K == 0 && isalpha(S[i]))
                return (string) "" + S[i];
 
            if(isdigit(S[i]))
                size = size / (S[i] - '0');
            else
                size -= 1;
        }
        // return empty string if K-th letter not found
        // return "";
        throw;
    }
};




