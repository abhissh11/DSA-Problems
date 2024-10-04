// To remove duplicates from a sorted array in place, the approach is simple. Since the array is already sorted, the duplicates will be adjacent. We can maintain two pointers:

// One to track the position where the next unique element should be placed.
// Another to traverse the array and identify unique elements.
// Approach:
// Use a pointer j to track the position for placing the next unique element.
// Traverse the array using another pointer i and compare each element with the previous one.
// If an element is different from the last unique element, place it in the next position of j, and increment j.
// Return the length of the modified array (number of unique elements).

#include <iostream>
#include <vector>

using namespace std;

// Function to remove duplicates from a sorted array and return the new length
int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0; // If the array is empty, return 0

    int j = 1; // Initialize j to 1 as the first element is always unique

    // Traverse the array starting from the second element
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] != nums[i - 1])
        {                      // Check if the current element is different from the previous one
            nums[j] = nums[i]; // Place the unique element at position j
            j++;               // Increment j for the next unique element
        }
    }

    return j; // Return the number of unique elements
}

// Driver code
int main()
{
    // Example sorted array
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

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
