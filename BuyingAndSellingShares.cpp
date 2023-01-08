#include<bits/stdc++.h>
using namespace std;

int max(int a, int b, int c){
    return a>b && a>c?a:b>c?b:c;
}

int buyed(int i, int  arr[], int n){
    for(int k = i;k<n-1;k++){
        if(arr[k + 1]< arr[k]){
            return k;
        }
    }

    return n-1;
}

int solve(int price[], int start, int end, int k, int n){
    if(start > end || k == 0){
        return 0;
    }

    int ans = INT16_MIN;

    for(int i = start;i<=end;i++){
        int temp1 = solve(price, i + 1, end, k, n);
        int index = buyed(i, price, n);
        int temp2 = (price[index] - price[i]) + solve(price, index + 1, end, k - 1, n);

        ans = max(temp1, temp2, ans);
    }

    return ans;
}

int main(){
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = 6;
    int start = 0;
    int end = 5;
    int k = 2;

    int result = solve(price, start, end, k, n);
    cout<<result<<endl;
    return 0;
}