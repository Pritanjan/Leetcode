// A 1 JS

/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function (n) {
    let res = [];
    let curr = 1;

    for (let i = 0; i < n; i++) {
        res.push(curr);

        if (curr * 10 <= n) curr *= 10;
        else {
            while (curr % 10 === 9 || curr + 1 > n) {
                curr = Math.floor(curr / 10);
            }
            curr++;
        }
    }
    return res;
};


// A 2 - JS

/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function(n) {
    // Step 1: Create an array of numbers from 1 to n
    let arr = Array.from({ length: n }, (_, i) => i + 1);
    
    // Step 2: Sort the array based on lexicographical order (compare as strings)
    arr.sort((a, b) => String(a).localeCompare(String(b)));

    // Step 3: Return the sorted array
    return arr;
};



// A 3 

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        for (int i = 0; i < n; i++) {
            res.push_back(curr);
            if (curr * 10 <= n)
                curr *= 10;
            else {
                while (curr % 10 == 9 || curr + 1 > n) {
                    curr = floor(curr / 10);
                }
                curr++;
            }
        }
        return res;
    }
};

// A 4 

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        vector<int> nums(n);
        for (int i = 1; i <= n; ++i) {
            nums[i - 1] = i;
        }

        // Step 2: Sort the numbers lexicographically by converting them to
        // strings
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a) < to_string(b); // Lexicographical comparison
        });

        // Step 3: Return the sorted vector
        return nums;
    }
};
