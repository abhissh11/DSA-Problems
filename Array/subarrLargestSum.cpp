// Problem: Given an integer array nums , find the subarray with the largest
// sum and return its sum.

// Kadane’s Algorithm Approach:

// Maintain two variables:
// currentSum: The maximum sum of the subarray that ends at the current position.
// maxSum: The maximum sum encountered so far.
// Traverse the array, updating currentSum as the maximum of the current element itself or currentSum + current element. This checks whether to continue the current subarray or start a new one.
// Update maxSum whenever currentSum exceeds it.

#include <iostream>
#include <vector>
#include <algorithm> // for max function

using namespace std;

// Function to find the subarray with the largest sum and return its sum
int maxSubArray(vector<int> &nums)
{
    int currentSum = nums[0]; // Initialize current sum as the first element
    int maxSum = nums[0];     // Initialize max sum as the first element

    // Traverse the array starting from the second element
    for (int i = 1; i < nums.size(); ++i)
    {
        // Update current sum: either extend the previous subarray or start a new one
        currentSum = max(nums[i], currentSum + nums[i]);

        // Update the max sum encountered so far
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
            currentSum = 0;
    }

    return maxSum; // Return the largest sum
}

// Driver code
int main()
{
    // Example array
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Call the function and print the result
    int result = maxSubArray(nums);
    cout << "The largest subarray sum is: " << result << endl;

    return 0;
}
