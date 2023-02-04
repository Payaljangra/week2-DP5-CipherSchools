#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementsII(vector<int> &nums){
    stack<int> S;
    vector<int> nge(nums.size());
    for(int i=nums.size()-1; i>-0;i--){
         while(!S.empty() && nums[S.top()]< nums[i]){
            S.pop();
        }
        S.push(i);

    }
    for(int i=nums.size()-2; i>=0; i--){
        while(!S.empty() && nums[S.top()]< nums[i]){
            S.pop();
        }
        if(S.empty()){
            nge[i] = -1;

        }else{
             nge[i]= nums[S.top()];
        }
        S.push(i);
    }
    return nge;
}
int main(){

}