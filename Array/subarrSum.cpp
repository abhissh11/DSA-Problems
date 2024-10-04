//  Given an array of integers and an integer sum , return the total
// number of subarrays whose sum equals sum . give c++ code along with driver code

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int target)
{
    unordered_map<int, int> prefixSumMap; // Map to store frequency of prefix sums
    int prefixSum = 0;                    // To store the cumulative sum
    int count = 0;                        // To store the count of subarrays
    prefixSumMap[0] = 1;                  // To account for subarrays that start from index 0

    // Traverse the array
    for (int i = 0; i < nums.size(); ++i)
    {
        prefixSum += nums[i]; // Update the cumulative sum

        // Check if there is a subarray with the required sum
        if (prefixSumMap.find(prefixSum - target) != prefixSumMap.end())
        {
            count += prefixSumMap[prefixSum - target]; // Add the count of such subarrays
        }

        // Update the frequency of the current prefix sum
        prefixSumMap[prefixSum]++;
    }

    return count; // Return the total count of subarrays
}

// Driver code
int main()
{
    // Example array and sum
    vector<int> nums = {1, 2, 3, -3, 3, 4, 5, -4, 6, 3, -3, 2, 4};
    int target = 7;

    // Call the function and print the result
    int result = subarraySum(nums, target);
    cout << "The number of subarrays with sum " << target << " is: " << result << endl;

    return 0;
}
