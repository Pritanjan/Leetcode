// APPROACH 1  Using sscanf

#include <cstdio>
#include <string>

class Solution {
public:
    int dayOfYear(std::string date) {
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth[2] = 29;
        
        int dayOfYear = 0;
        for (int i = 1; i < month; ++i) {
            dayOfYear += daysInMonth[i];
        }
        dayOfYear += day;
        
        return dayOfYear;
    }
};






// APPROACH 2


#include <string>
class Solution {
public:
    int dayOfYear(string date) {
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Days in each month
        int year = stoi(date.substr(0, 4)); // Extract year
        int month = stoi(date.substr(5, 2)); // Extract month
        int day = stoi(date.substr(8, 2)); // Extract day

        // Adjust for leap year
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) days[2] = 29;

        int totalDays = 0;
        for(int i=1; i<month; ++i) {
            totalDays += days[i];
        }
        totalDays += day;

        return totalDays;
    }
};





// APPROACH 3 

#include <string>
#include <sstream>

class Solution {
public:
    int dayOfYear(string date) {
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        istringstream iss(date);
        int year, month, day;
        char dash1, dash2;
        iss >> year >> dash1 >> month >> dash2 >> day;
        
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            daysInMonth[2] = 29;
        
        int dayOfYear = 0;
        for (int i = 1; i < month; ++i) {
            dayOfYear += daysInMonth[i];
        }
        dayOfYear += day;
        
        return dayOfYear;
    }
};
