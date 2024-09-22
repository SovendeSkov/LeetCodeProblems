// You are given a sorted unique integer array nums.
// A range [a,b] is the set of all integers from a to b (inclusive).
// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
// Each range [a,b] in the list should be output as:
// "a->b" if a != b
// "a" if a == b

// Example 1:
// Input: nums = [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: The ranges are:
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"

// Example 2:
// Input: nums = [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: The ranges are:
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"

// Constraints:
// 0 <= nums.length <= 20
// -231 <= nums[i] <= 231 - 1
// All the values of nums are unique.
// nums is sorted in ascending order.

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> answer;
	
        int startRange = 0;
        int endRange = 0;
        
        // for each index check the following
        // need to check edge cases
        for (auto index = 0; index < nums.size(); index++) {
            if (index == nums.size() - 1){

                    endRange = index;
                    // Format Range & Save to answer
                    string formatRange;
                    if (startRange == endRange) {
                        formatRange = format("{}", nums.at(startRange));
                    } else {
                        formatRange = format("{}->{}", nums.at(startRange), nums.at(endRange));
                    }
                    answer.push_back(formatRange);
            } else {
                long long int numEval = (static_cast<long long int>(nums.at(index + 1))) - static_cast<long long int>(nums.at(index));
                if (numEval != 1) {

                    endRange = index;
                    // Format Range & Save to answer
                    string formatRange;
                    if (startRange == endRange) {
                        formatRange = format("{}", nums.at(startRange));
                    } else {
                        formatRange = format("{}->{}", nums.at(startRange), nums.at(endRange));
                    }
                    answer.push_back(formatRange);
                    startRange = index + 1;
                }
            }
        }
        return answer;
    }
};
