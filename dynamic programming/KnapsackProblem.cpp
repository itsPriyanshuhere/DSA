#include <iostream>
#include <vector>
using namespace std;

int kanpsackDP(int wt[], int price[], int N, int W){
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));

    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            int inc,exc =0;
            if(wt[n-1] <= W){
                inc = price[n-1]+dp[n-1][w-wt[n-1]];
            }
            exc = dp[n-1][w];
        dp[n][w] = max(inc,exc);
        }
    }
    return dp[N][W];
}

int main(){
    int wts[] = {2,7,3,4};
    int prices[] = {5,20,20,10};

    int N = 4;
    int W = 11;

    cout<< kanpsackDP(wts,prices,N,W);
}