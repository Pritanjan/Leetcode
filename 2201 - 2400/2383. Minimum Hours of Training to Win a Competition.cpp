// APPROACH 1


class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int ans = 0;
           
        for(int i=0; i<n; i++){
            if(energy[i] >= initialEnergy){
                int a = energy[i] - initialEnergy + 1;
                initialEnergy += a;
                ans += a;
            }
            if(experience[i] >= initialExperience){
                int a = experience[i] - initialExperience + 1;
                initialExperience += a;
                ans += a;
            }           
            initialExperience += experience[i];
            initialEnergy -= energy[i];
        }
        return ans;
    }
};




// APPROACH 2


class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum = 0;
        for (int e : energy) {
            sum += e;
        }
        int trainingHours = initialEnergy > sum ? 0 : sum + 1 - initialEnergy;
        for (int e : experience) {
            if (initialExperience <= e) {
                trainingHours += 1 + (e - initialExperience);
                initialExperience = 2 * e + 1;
            } else {
                initialExperience += e;
            }
        }
        return trainingHours;
    }
};








// APPROACH 2


class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum_energy = 0, all_exper = 0, summ_exper = 0, res = 0;
		for(int i : energy)
			sum_energy += i;
		all_exper = initialExperience;
		for(int i : experience){
			summ_exper += i;
			if(all_exper <= i)
				all_exper = i+1;
			all_exper += i;
		}
		if(sum_energy >= initialEnergy) res += sum_energy + 1 - initialEnergy;
		if(all_exper > initialExperience + summ_exper) res += all_exper - initialExperience - summ_exper;
		return res;
    }
};




