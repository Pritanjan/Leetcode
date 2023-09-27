// A 0 -  Decoding from Left to Right

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long decodedLength = 0;
        int n = s.size();
        string res = "";

        for(int i=0; i<n; ++i) {
            if(isdigit(s[i])) decodedLength *= s[i] - '0';
            else decodedLength++;

            if(decodedLength >= k) {
                for(int j=i; j>=0; --j) {
                    if(isdigit(s[j])) {
                        int digit = s[j] - '0';
                        decodedLength /= digit;
                        k %= decodedLength;
                    } 
                    else {
                        if(k == 0 || k == decodedLength) {
                            res = s[j];
                            return res;
                        }
                        decodedLength--;
                    }
                }
            }
        }
        return res;
    }
};






// A 1 - Calculate Length Directly

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int N = S.size();
        long size = 0;
 
        // finding size = length of new string S'
        for(int i=0; i<N; ++i) {
            if(isdigit(S[i])) size *= (S[i] - '0');
            else size += 1;
        }
 
        // get the K-th letter
        for(int i=N-1; i>=0; --i){
            K %= size; 
            if(K == 0 && isalpha(S[i])) return (string) "" + S[i];
            if(isdigit(S[i])) size /= (S[i] - '0');
            else size -= 1;
        }
        // return empty string if K-th letter not found
        // return "";
        throw;
    }
};

// T.C. -> O(N)
// S.C. -> O(N)

// 1. The function K_thletter takes an encoded string S and an integer K as input and 
//    returns the K-th letter in the decoded string.
// 2. The variable N stores the length of the encoded string S.
// 3. The variable size is initialized to 0, & will be used to keep track of the size of current substring.
// 4. The first loop iterates through the encoded string S, and for each character, 
//    it checks whether it is a digit or a letter. 
//    If it is a digit, the code multiplies size by d-1, where d is the numerical value of the digit. 
//    If it is a letter, the code simply adds 1 to size. 
//    By the end of the loop, size will contain the length of the decoded string.
// 5. The second loop iterates through the encoded string S from the end. 
//    In each iteration, it performs the reverse operation of decoding, which means it checks whether
//    the current character is a digit or a letter, and adjusts the size of the substring accordingly. 
//    It also checks whether the K-th letter has been found yet. 
//    If it has, the function returns the current character. 
//    Otherwise, the loop continues until the K-th letter is found.
// 6. Inside the loop, the code first takes the modulo of K with size. 
//    This is done to handle cases where K is greater than the length of the decoded string. 
//    If K is a multiple of size, then the K-th letter must be the last letter of the decoded string. 
//    This is why the code checks if K is divisible by size and if the current character is a letter. 
//    If both conditions are true, the function returns the current character.
// 7. If the current character is a digit, the code divides size by d, where d is the numerical value
//    of the digit. This is because the substring that precedes the digit must be repeated d times to
//    form the current substring.
// 8. If the current character is a letter, the code simply subtracts 1 from size. 
//    This is because the current character is part of the current substring and does not need to be
//    repeated.






// A 2



