#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

/*
*��Ŀ������������һ�����飬������������ӵ����ض�����(target)
*
*/

//�ⷨһ����ϣ��
vector<int> twoSum(vector<int>&numbers,int target){
    map<int,int> mapping;
    vector<int> result;

    //�������鷢����ϣ��
    for(int i=0;i<numbers.size();i++){
        mapping[numbers[i]]=i;
    }

    for(int i=0;i<numbers.size();i++){
        int searched = target - numbers[i];
        //û���ҵ��������ҵ���ʵ��ͬһ����
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


