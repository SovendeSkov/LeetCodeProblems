// 2028. Find Missing Observations
// You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.
// You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.
// Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.
// The average value of a set of k numbers is the sum of the numbers divided by k.
// Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.
// Example 1:
// Input: rolls = [3,2,4,3], mean = 4, n = 2
// Output: [6,6]
// Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
// Example 2:
// Input: rolls = [1,5,6], mean = 3, n = 4
// Output: [2,3,2,2]
// Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.
// Example 3:
// Input: rolls = [1,2,3,4], mean = 6, n = 4
// Output: []
// Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.



// For this solution you just have to return n numbers which combined with those provided in the
// array average to the given mean. 

// 1. take mean and multiple it by (n+m) = k
// 2. k - (sum of array) = q
// ATTEMPT 1
// 3.q is equal to the sum of number which all of n must add up to
// easiest solution is provide 1's for each of n except n-1 which is remainder
    // The last part was a wrong assumption. I didnt account for the fact the number is from the die so 
    // it can only be 1-6. Subtracting 1 from q and then providing remainder will generate values which violate
    // the 1-6 rule.  

// ATTEMPT 2
// 3.q/n = x
// MUST BE TRUE x <= 6
    // return average of missing values until n-1 and then return remainder
// else return empty 

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        // 1.
        const int k = mean * (n + rolls.size());

        // 2.
        int sumOfRolls = 0;
        for (int roll: rolls) {
            sumOfRolls += roll;
        }
        int q = 0;
        q = k - sumOfRolls;

        // 3.
        vector<int> missingValues;
        double missingValueAverage = q/n;
        if (missingValueAverage <= 6.0){
            int qRemainder = q;
            for (int counter = 0; counter < (n-1); counter++) {
                missingValues.push_back((int)missingValueAverage);
                qRemainder -= (int)missingValueAverage;
            }
            missingValues.push_back(qRemainder);
        }
        return missingValues;
    }
};
