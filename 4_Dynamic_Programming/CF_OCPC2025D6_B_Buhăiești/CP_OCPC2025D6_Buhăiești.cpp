#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
int mex(vector<int> arr){
    set<int> contain(arr.begin(),arr.end());
    for(int i=0;i<=arr.size();i++){
        if (!contain.count(i)){
            return i;
        }
    }
}

int count(const vector<int>& B, vector<int> A,int NEW,bool& decided,int m,int j,int& counter,int& n){
    if (j==n){return 1;}
    A.push_back(NEW);
    j++;
    for (int cur_A_digit=0;cur_A_digit<m;cur_A_digit++){
        if (!decided){
            if (cur_A_digit<B[j]){
                decided=true;
            }
            if (cur_A_digit>B[j]){
                continue;
            }
        }
        if (mex(A)>mex(B)){
            continue;
        }
        else{
            counter+=count(B,A,cur_A_digit,decided,m,j,counter,n);
        }
    }
    return counter;
}
int main(){
    // 输入总次数决定循环总次数
    int loops;
    cin>>loops;
    // 在每一次循环内部，完成当前次运算，不存
    for (int i=0;i<loops;i++){
        int n,m;
        cin>>n>>m;
        vector<int> B(n);
        vector<int> A;
        int valids;
        int counter=0;
        for (int j=0;j<n;j++){
            cin>>B[j];
        }
        bool decided=false;
        int j=0;
        int res=count(B,A,0,decided,m,j,counter,n);
        cout<<res%((int)pow(10,9)+7);
        }
    return 0;
}
    // 先记下数组总长度n和最大可能元素m
    // 读入B
    // 从头构建A
    // 条件1：A在[0,m]之间
    // 条件2：A的字典序比B小，到某一位之前，相等，某一位，小于，后面，随便
    // 条件3：mexA当前生长出来的长度<=mexB当前生长出来的长度
    // 完成运算后直接输出当前轮结果--合法次数对(10^9+7)取模