// To remove duplicates from an unsorted array, we can use a hash set to track the elements we've already encountered. This ensures that we only keep unique elements. By using a hash set, we can efficiently check for duplicates while traversing the array.

// Approach:
// Initialize an empty hash set to store unique elements.
// Traverse the array, and for each element:
// If the element is not in the set, add it to the set and place it in the result.
// If it is already in the set, skip it.
// The array is modified in place to only contain unique elements, and we return the new length of the array.

#include <iostream>
#include <vector>
#include <unordered_set> // For using unordered_set

using namespace std;

// Function to remove duplicates from an unsorted array
int removeDuplicates(vector<int> &nums)
{
    unordered_set<int> seen; // To store unique elements
    int j = 0;               // Pointer to store the next unique element position

    // Traverse the array
    for (int i = 0; i < nums.size(); ++i)
    {
        // If the element is not seen before
        if (seen.find(nums[i]) == seen.end())
        {
            seen.insert(nums[i]); // Add the element to the set
            nums[j] = nums[i];    // Place the unique element at position j
            j++;                  // Increment j for the next unique element
        }
    }

    return j; // Return the number of unique elements
}

// Driver code
int main()
{
    // Example unsorted array
    vector<int> nums = {4, 2, 3, 2, 4, 1, 5, 3};

    // Call the function and print the result
    int newLength = removeDuplicates(nums);

    // Print the array after removing duplicates
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    // Print the new length of the array
    cout << "New length of the array: " << newLength << endl;

    return 0;
}
