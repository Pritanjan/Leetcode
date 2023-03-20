class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int m) {
        int n=f.size();
        for(int i=0;i<n;i++){
            if(f[i]==1)continue;
            else{
                if((i==0||f[i-1]==0)&&(i==n-1||f[i+1]==0)){f[i]=1;m--;}
            }
        }
        return m<=0;
    }
};







class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int cnt = 0;
        for(int i=0; i<f.size(); i++){
            if(f[i] == 0){
                bool emptyLeftPlot = (i == 0) || (f[i - 1] == 0);
                bool emptyRightPlot = (i == f.size() - 1) || (f[i + 1] == 0);

                if(emptyLeftPlot && emptyRightPlot) {
                    f[i] = 1;
                    cnt++;
                }
            }
        }
        return cnt >= n;
    }
};




// bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);

// OR 

// bool emptyLeftPlot;
// if (i == 0 || flowerbed[i - 1] == 0) {
//     emptyLeftPlot = true;
// } else {
//     emptyLeftPlot = false;
// }
