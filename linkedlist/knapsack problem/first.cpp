#include <bits/stdc++.h>
using namespace std;
//maximum possible value in a knapsack
// class Item which stores weight and
// corresponding value of Item
class Item {
    public:
        int value, weight;

        // Constructor
        Item(int value, int weight){
            this->value=value;
            this->weight=weight;
        }
};

// Comparison function to sort Item according to value/weight ratio
bool compare(Item x, Item y){
    // finding the ratio for xth item
    double ratio1 = (double)x.value / (double)x.weight;
    cout<<ratio1<<endl;
    // finding the ratio for yth item
    double ratio2 = (double)y.value / (double)y.weight;
    cout<<ratio2<<endl;
    cout<< (ratio1 > ratio2)<<endl;
    return ratio1 > ratio2;
}

// Main greedy function to solve problem
void fractionalKnapsack(int W, class Item arr[], int n){
    // sorting Item in descending order according to value/weight ratio
    sort(arr, arr + n, compare);
    // Current weight in knapsack
    int currentWeight = 0;
    // maximum possible value in knapsack
    double maxValue = 0.0;

    // Looping through all Items
    for (int i = 0; i < n; i++) {
        // If adding Item won't overflow, add it completely
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            maxValue += arr[i].value;
        }

        // If we can't add current Item, add fraction of it into knapsack and break
        else {
            int fraction = W - currentWeight;
            maxValue += arr[i].value * ((double)fraction/(double)arr[i].weight);
            break;
        }
    }

    // printing the maximum possible value
    cout << maxValue;
}

// Driver code
int main()
{
    // Weight of knapsack
    int W = 25;
    //
    Item arr[] = {{10,10},{2,5},{6,8},{4,50},{100,1}};
    int n = sizeof(arr) / sizeof(arr[0]);
    // calling the knapsack function
    fractionalKnapsack(W, arr, n);
    return 0;
}