// APPROACH 1 (WITHOUT USING STACK) 

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int tmp[2] = {0};
        int n = students.size();
        for(int j : students) {
            tmp[j]++;
        }   
        // In other words, "tmp[j]" counts the frequency of each unique element in "students" vector 
             
        int i = 0;
        while(i < n && tmp[sandwiches[i]] > 0) {
            tmp[sandwiches[i]]--;
            i++;
        }
        return n - i;
    }
};


// According to the meaning of the question, no matter how students take turns to get sandwiches,
// if the number is enough, they can always get sandwiches after multiple rounds. The problem can 
// be equivalent to, students go to the front of the queue to receive sandwiches one by one. 2 
// kinds of sandwiches are laid out there. In the end, the students who did not get the sandwiches
// were all because there were not enough sandwiches they liked. 

// According to this idea, first count the total number of the two kinds of sandwiches, 
// and then subtract the total number of students' demand for sandwiches, and the remaining 
// students cannot be satisfied.

// Time O(n)
// Space O(2)






// A 2 - Hash Map

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int, int> freq;
        for (int student : students) {
            freq[student]++;
        }
        
        int i = 0;
        while (i < sandwiches.size() && freq[sandwiches[i]] > 0) {
            freq[sandwiches[i]]--;
            i++;
        }
        return students.size() - i;
    }
};






// A 3 

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int unableToEat = 0;
        for (int i = 0; i < sandwiches.size(); ++i) {
            auto it = find(students.begin(), students.end(), sandwiches[i]);
            if (it == students.end()) {
                unableToEat = sandwiches.size() - i;
                break;
            }
            students.erase(it);
        }
        return unableToEat;
    }
};
