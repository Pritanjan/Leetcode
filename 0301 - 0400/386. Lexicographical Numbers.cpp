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
