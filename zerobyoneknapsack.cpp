//0/1 knapsack
#include <iostream>
using namespace std;
struct Item
{
    int weight;
    int value;
};

// Function to find the maximum value achievable within thce knapsack capacity
int knapsack(Item items[], int n, int capacity)
{
    int maxValue = 0;

    // There are 2^n possible subsets, represented by numbers from 0 to 2^n - 1
    int totalSubsets = 1 << n; // Equivalent to 2^n

    // Iterate through all subsets
    for (int subset = 0; subset < totalSubsets; ++subset) {
        int currentWeight = 0;
        int currentValue = 0;

        // Print subset for current subset mask
        cout << "Subset: { ";
        for (int i = 0; i < n; ++i) {
            // Check if the i-th item is included in the subset (by checking if the i-th bit is set in the subset)
            if (subset & (1 << i)) {
                currentWeight += items[i].weight;
                currentValue += items[i].value;
                cout << "Item " << i + 1 << " (Weight: " << items[i].weight << ", Value: " << items[i].value << ") ";
            }
        }
        cout << "}" << endl;

        // Update maxValue if this subset is within capacity and has a higher value
        if (currentWeight <= capacity && currentValue > maxValue) {
            maxValue = currentValue;
        }
    }

    return maxValue;
}

int main() {
    // Define items with weights and values
    Item items[] = {
        {2, 3},  // Item 1: weight = 2, value = 3
        {3, 4},  // Item 2: weight = 3, value = 4
        {4, 5},  // Item 3: weight = 4, value = 5
        {5, 6}   // Item 4: weight = 5, value = 6
    };

    int capacity = 5;  // Maximum capacity of knapsack
    int n = sizeof(items) / sizeof(items[0]); // Number of items

    // Calculate and display the maximum value that can be achieved
    int maxVal = knapsack(items, n, capacity);
    cout << "Maximum value in Knapsack: " << maxVal << endl;
    return 0;
    
}



