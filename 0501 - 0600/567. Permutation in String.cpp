// APPROACH 1


class Solution {
public:
    bool checkEqual(int a[26], int b[26]){
        for(int i=0; i<26; i++)
            if(a[i] != b[i]){
                return 0;
            }
            return 1;
    }
        
    bool checkInclusion(string s1, string s2) {
        
        // count charracter array
        int count1[26] = {0};
        for(int i=0; i<s1.length(); i++){
            int index = s1[i] - 'a';
            count1[index]++;
        }
        
        // traverse s2 string string in window of size s1 and compare
        int i=0;
        int window = s1.length();
        int count2[26] = {0};
        
        //running for first window
        while(i<window && i < s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        if(checkEqual(count1, count2))
            return 1;
        
        // shift window proceess
        while(i < s2.length()){
            char newchar = s2[i];
            int index = newchar - 'a';
            count2[index]++; 
            
            char oldchar = s2[i - window];
            index = oldchar - 'a';
            count2[index]--;
            
            i++;
            
            if(checkEqual(count1, count2))
            return 1;
        }
        return 0;
    }
};








// APPROACH 2


// Here's how the code works:

// 1. First, it checks if the length of s2 is less than the length of s1. If it is,
//    the function returns false because it is not possible for a permutation of s1 to
//    exist in s2.
// 2. The vectors f1 and f2 are initialized to store 26 zero values, each corresponding
//    to a letter in the alphabet.

// 3. The for-loop using char x iterates through s1 and increments the count of each 
//    character in the f1 vector.

// 4. The next for-loop iterates through the s2 string, maintaining a sliding window 
//    of s1.length() characters.

// 5. On each iteration, the count of the character in the end of the sliding window is
//    incremented in the f2 vector.

// 6. The code then checks if f1 and f2 are equal. If they are, the function returns true,
//    indicating that a permutation of s1 exists in s2.

// 7. Finally, the count of the character in the beginning of the sliding window is
//    decremented in the f2 vector for the next iteration.

// 8. If the for-loop completes without finding a match, the function returns false.


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()){
            return false;
        }
        
        vector<int> f1(26, 0), f2(26, 0);
        
        for(char x : s1) {
            f1[x - 'a']++;
        }
        
        for(int i=0; i<=s2.length()-s1.length(); i++) {
            if(i == 0){
                for(int j=i; j<i+s1.length(); j++) {
                    f2[s2[j] - 'a']++;
                }
            }else{
                f2[s2[i+s1.length()-1] - 'a']++;
            }
            
            if(f1 == f2) {
                return true;
            }
            
            f2[s2[i] - 'a']--;
        }        
        return false;
    }
};

// Algo steps are:

// 1. if len(s1) >= len(s2) then we can return False as there can’t be a permutation 
//     of word s1 in word s2

// 2. As the words are in lowercase English chars as given in the problem statement,
//    we can use a list to populate the frequency array for both words s1 and s2.

// 3. Firstly, Iterate over the s1 word and populate the frequency array for it

// 4. Next, take the sliding window of len(s1) and slide over the s2 word. Update 
//    the frequency list for s2 word for each such window of len(s1)

// 5. For the i==0, we need to populate all the elements in the sliding window and 
//    decrement the count of the first char of the sliding window and end of the 
//    iteration

// 6. For i > 0 cases, we need to increment the last char of the sliding window and 
//    beginning of iteration and decrement the first char of the sliding window and
//    end of the iteration

// 7. If both lists are the same then return True and exit

// 8. Return False if True is not encountered.





// OR


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        if(n > m) return false;
        
        vector<int> cnt1(26, 0), cnt2(26, 0);
        
        for(int i=0; i<n; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        if(cnt1 == cnt2) return true;
        
        for(int i=n; i<m; i++) {
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - n] - 'a']--;

            if(cnt1 == cnt2) return true;
        }
        return false;
    }
};









// APPROACH 3

