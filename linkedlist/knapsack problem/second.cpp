#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct activity 
{ 
    int start, finish; 
}; 

bool activityComparator(activity s1, activity s2) 
{ 
    return (s1.finish < s2.finish); 
} 

void activitySelection(activity arr[], int n) 
{ 
    sort(arr, arr+n, activityComparator); 
  
    int i = 0; 
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 
  
    for (int j = 1; j < n; j++) 
    {  
      if (arr[j].start >= arr[i].finish) 
      { 
          cout << "(" << arr[j].start << ", "
              << arr[j].finish << ") "; 
          i = j; 
      } 
    } 
} 
  
int main() 
{ 
    int n;
    cin>>n;
    Activity arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish;
    } 
    activitySelection(arr, n); 
    return 0; 
}