#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

/*
*题目：给定整数的一个数组，其中两个数相加等于特定的数(target)
*
*/

//解法一：哈希法
vector<int> twoSum(vector<int>&numbers,int target){
    map<int,int> mapping;
    vector<int> result;

    //遍历数组发到哈希表
    for(int i=0;i<numbers.size();i++){
        mapping[numbers[i]]=i;
    }

    for(int i=0;i<numbers.size();i++){
        int searched = target - numbers[i];
        //没有找到或者是找到其实是同一个数
        if(mapping.find(searched)!= mapping.end()&&i!=mapping[searched]){
            result.push_back(i+1);
            result.push_back(mapping[searched]+1);
            break;
        }
    }

    return result;
}


int main()
{
    int numbers[4] ={2,7,11,15};
    int target = 9;
    twoSum(numbers,target);
    cout << "index1:"  << endl;
     cout << "index1:" << endl;
    //cout << "Hello world!" << endl;
    return 0;
}


