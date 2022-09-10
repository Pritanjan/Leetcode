//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/discuss/2326237/C%2B%2B-Easy-Solution-with-explanation

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		int n = nums.size();  // size of nums
		vector<int> ans;     // to store the count of smaller number in an array.
        
		for(int i=0; i<n; i++){
			int count = 0;         // initialize count equal to 0 before starting the count of every element. 
			for(int j=0; j<n; j++){
				if(nums[i] > nums[j])   // if number is smaller than the current the one increment the count by 1.
					count++;
			}
			ans.push_back(count);   // push the count into the array ans
		}
		return ans;
	}
};
