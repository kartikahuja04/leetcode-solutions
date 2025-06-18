// Author: Kartik Ahuja
// Date: 18 June 2025
// Approaches: Brute Force, Hashing, Two Pointer (if sorted)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

pair<int,int> type1(int arr[] , int target, int n){
    for(int i = 0 ; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == target)
                return {i, j};
        }
    }
    return {-1, -1};
}
pair<int,int> type2(int arr[], int target , int n ){
    unordered_map<int, int> map1;
    for(int i = 0; i < n; i++){
        int var = target - arr[i];
        if(map1.find(var) != map1.end()){
            return {map1[var], i};
        }
        map1[arr[i]] = i;
    }
    return {-1, -1};
}
pair<int,int> type3(int arr[], int target , int n ){
    int left = 0;
    int right = n - 1;

    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            return {left, right};
        }
        else if(sum > target){
            right--;
        }
        else{
            left++;
        }
    }
    return {-1, -1};
}
int main(){
    int arr[] = { 1, 2 , 3 , 5 , 7, 8 , 11 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 10;

    pair<int,int> result1 = type1(arr, target, n);
    if(result1.first != -1){
        cout << "Brute Force : " << result1.first << " and " << result1.second << endl;
    }

    pair<int,int> result2 = type2(arr, target, n);
    if(result2.first != -1){
        cout << "Hash Map : " << result2.first << " and " << result2.second << endl;
    }

    pair<int,int> result3 = type3(arr, target, n);
    if(result3.first != -1){
        cout << "Two Pointer : " << result3.first << " and " << result3.second << endl;
    }

    return 0;
}
