// 先对数组排序
// 遍历排序后的数组，计算数组前半部分i*arr[i+1]的最大值,并存入一个数组
// 遍历数组，取出部分，求剩余部分skyline
// 二者相加，取最大值。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long skyline(vector<long long>& arr, int start) {
    if (start >= arr.size()) return 0;
    sort(arr.begin() + start, arr.end(), greater<long long>());
    
    long long MAX = 1 * arr[start];
    for (int i = start; i < arr.size(); i++) {
        long long cur = (long long)(i - start + 1) * arr[i];
        if (cur > MAX) {
            MAX = cur;
        }
    }
    return MAX;
}

long long sum(vector<long long>& arr) {
    if (arr.empty()) return 0;
    sort(arr.begin(), arr.end(), greater<long long>());
    
    vector<long long> mid(arr.size());
    long long current_max = 1 * arr[0];
    mid[0] = current_max;
    
    for (int i = 1; i < arr.size(); i++) {
        long long cur = (long long)(i + 1) * arr[i];
        current_max = max(current_max, cur);
        mid[i] = current_max;
    }
    
    long long SUM_MAX = mid[0] + skyline(arr, 1);
    for (int i = 1; i < arr.size() - 1; i++) {
        long long cur = mid[i] + skyline(arr, i + 1);
        if (cur > SUM_MAX) {
            SUM_MAX = cur;
        }
    }
    return SUM_MAX;
}

int main() {
    string res = "";
    int n; 
    if (!(cin >> n)) return 0;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        vector<long long> arr(size);
        for (int j = 0; j < size; j++) {
            cin >> arr[j];
        }
        res += to_string(sum(arr)) + "\n";
    }
    cout << res;
    return 0;
}

// O(n)复杂度：
// 原来：前一半元素O(n)嵌套后一半元素O(n)->O(n^2)
// 现在: 前一半元素O(n)嵌套后一半元素O(1)->O(n)
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <deque>

// using namespace std;

// // ==========================================
// // 独立模块：CHT (斜率优化) 黑盒 API
// // ==========================================
// struct Line {
//     long long k, b;
//     long long eval(long long x) { return k * x + b; }
// };

// struct CHT {
//     deque<Line> dq;

//     // 判断直线 l2 是否是被淘汰的“废柴”
//     bool bad(Line l1, Line l2, Line l3) {
//         // 用 double 防止交叉相乘时爆 long long
//         return (double)(l1.b - l3.b) * (l2.k - l1.k) <= (double)(l1.b - l2.b) * (l3.k - l1.k);
//     }

//     // API 1: 压入新直线
//     void add(long long k, long long b) {
//         Line l3 = {k, b};
//         while (dq.size() >= 2 && bad(dq[dq.size()-2], dq.back(), l3)) {
//             dq.pop_back(); // 踢出没有前途的直线
//         }
//         dq.push_back(l3);
//     }

//     // API 2: 查询 x 处的最高 y 值
//     long long query(long long x) {
//         if (dq.empty()) return 0;
//         // 随着 x 往右走，如果栈顶直线已经被后面的超过了，直接扔掉
//         while (dq.size() >= 2 && dq[0].eval(x) <= dq[1].eval(x)) {
//             dq.pop_front();
//         }
//         return dq[0].eval(x);
//     }
// };
// // ==========================================


// // 这是你的核心解题函数
// long long solve(vector<long long>& arr) {
//     int n = arr.size();
//     if (n < 2) return 0; // 必须要切成两半，保底2个数

//     // 1. 全局降序排序 (保留了你推导出的核心结论)
//     sort(arr.begin(), arr.end(), greater<long long>());

//     // 2. 预处理左半部分 (Prefix)
//     // 就像你说的，把左边每一刀的最优解先存进小本本，O(N) 搞定
//     vector<long long> pref(n, 0);
//     long long current_left_max = 0;
//     for (int i = 0; i < n; i++) {
//         long long val = (long long)(i + 1) * arr[i];
//         current_left_max = max(current_left_max, val);
//         pref[i] = current_left_max;
//     }

//     // 3. 计算右半部分并求和
//     long long ans = 0;
//     CHT cht; // 召唤黑盒！

//     // 切分点 i：左边包含 0~i，右边包含 i+1~n-1
//     // 从右往左切，这样加进黑盒的斜率刚好是递增的，黑盒才能正常工作
//     for (long long i = n - 2; i >= 0; i--) {
//         long long j = i + 1; // 右边新加入的那个元素的索引
        
//         // 调用 API 1: 把右边的元素包装成直线扔进黑盒
//         // 斜率 k = arr[j]，截距 b = j * arr[j]
//         cht.add(arr[j], j * arr[j]);
        
//         // 调用 API 2: 黑盒，告诉我当前切分点右边能拿到的最高分是多少！
//         long long right_max = cht.query(-i); 
        
//         // 左边最高分直接从小本本里查
//         long long left_max = pref[i];
        
//         // 左右合并，打擂台留最大值
//         ans = max(ans, left_max + right_max);
//     }

//     return ans;
// }

// int main() {
//     // 竞赛必备：打消 C++ 默认的输入输出缓冲，极大加快 cin/cout 速度
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t; 
//     if (cin >> t) {
//         while (t--) {
//             int n;
//             cin >> n;
//             vector<long long> arr(n);
//             for (int i = 0; i < n; i++) {
//                 cin >> arr[i];
//             }
//             // 直接打印当前测试用例的结果
//             cout << solve(arr) << "\n";
//         }
//     }
//     return 0;
// }