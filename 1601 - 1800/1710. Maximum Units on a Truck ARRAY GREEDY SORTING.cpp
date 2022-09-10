//https://leetcode.com/problems/maximum-units-on-a-truck/

class Solution {
public:
    static bool compare(vector<int> a, vector<int> s){
        if(a[1] > s[1])
            return true;
        else
            return false;
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort(boxTypes.begin(), boxTypes.end(), greater<int> ()); // greater<int> () is not supported.
        // sorting array in descending order of NumberOfUnitPerBoxi
		sort(boxTypes.begin(), boxTypes.end(), compare);
        int unit = 0;
        
        for(int i=0; i<boxTypes.size(); i++){
            if(boxTypes[i][0] < truckSize){
                unit += boxTypes[i][0] * boxTypes[i][1]; //take all the boxes and addd the units
                truckSize -= boxTypes[i][0];			 //decrement the truckSize by numberOfBoxesi
            }
            else {
                unit += truckSize * boxTypes[i][1];     //take the boxes equal to remaining size and add the units
                break;
                break;
            }
        }
        return unit;
    }
};
