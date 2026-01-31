#include <iostream>
#include <vector>

using namespace std;

int check(vector<int>& prices){
    int MP = 0, bestBuy = prices[0];
        for(int i = 1; i<prices.size(); i++){
            if(prices[i]>MP){
                MP = max(MP, prices[i]-bestBuy);
            }
            bestBuy = min(prices[i], bestBuy);
        }
    return MP;
}

int main(){
    // Best time to buy and sell stock - LeetCode 121

    vector<int> prices = {7,1,5,3,6,4};
    //vector<int> prices = {7,6,4,3,1};

    cout<< "Maximum Profit : " << check(prices);
    return 0;
}