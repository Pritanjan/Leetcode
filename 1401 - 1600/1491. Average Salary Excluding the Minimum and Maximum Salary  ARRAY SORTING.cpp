// APPROACH 1

class Solution {
public:
    double average(vector<int>& salary) {
        return (accumulate(salary.begin(), salary.end(),0.) - *max_element(salary.begin(),salary.end()) - *min_element(salary.begin(), salary.end())) / (salary.size() - 2);
    }
};






// APPROACH 2

class Solution {
public:
    double average(vector<int>& salary) {
        // int mi = INT_MIN;
        // int ma = INT_MAX;
        
        int n = salary.size();
        double sum = 0;
        
        for(int i=0; i<n; i++){
            sum = sum + salary[i];
            
        }
        // return  sum/n-2;
        // cout<<sum;
        
        int mi = *min_element(salary.begin(),salary.end());
        int ma = *max_element(salary.begin(),salary.end());
        
        // cout<<mi<<" "<<ma;
        
        return (sum - mi - ma)/(n-2);
    }
};





// APPROACH 3

class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        if(n == 2)
            return 0;
        
        int mi = INT_MAX;
        int ma = INT_MIN;
        
        double sum = 0;
        for(int i : salary){
            mi = min(mi,i);
            ma = max(ma,i);
            sum += (double)i;
        }
        return (sum - (ma+mi))/ (n-2);
    }
};







// APPROACH 4

class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        sort(salary.begin(), salary.end());
        double sum = 0;
        
        for(int i=1; i<n-1; i++) {
            sum += salary[i];
        }
        
        return sum / (n - 2);
    }
};

