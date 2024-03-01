// A 1 

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt0 = 0, cnt1 = 0;
        for(char c : s) {
            if(c == '0') cnt0++;
            else cnt1++;
        }
        string res = "";
        while(cnt1 > 1) {
            res += '1';
            cnt1--;
        }
        while(cnt0 > 0) {
            res += '0';
            cnt0--;
        }
        res += '1';
        return res;
    }
};






// A 2 - Greeedy

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // create char array
        const int N = s.length();
        char* arr = new char[N + 1];
        strcpy(arr, s.c_str());

        sort(arr, arr + N);

        // Reverse order for the first N - 1 elements of the array
        // Because we want to keep a 1 at the last index
        // The last element of the array is index N - 1, and the second to last
        // is at N - 2
        int secondLast = N - 2;
        for (int i = 0; i < N / 2; i++) {
            char temp = arr[i];
            arr[i] = arr[secondLast - i];
            arr[secondLast - i] = temp;
        }

        // Return result
        return arr;
    }
};

// T.C. --> O(N log N)

