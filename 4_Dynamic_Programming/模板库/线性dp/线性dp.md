# 线性 DP 一维递推型复习笔记

**阶段沿输入序列的下标线性排开，推进方向单一**。

> **"要到达状态 i，最后一个动作有哪些可能?"**

把这些可能**不重不漏**地列出来，每种都把问题缩小成一个更小的同类子问题——递推式就自己冒出来了。

**边界易错点：**

1. 初值给够（回看 i-2 要 2 个初值，i-3 要 3 个）
2. 特殊情况如input vector为空。

### 通用骨架——一维递推、滚动变量、O(1) 空间

```cpp
// 一维递推型线性DP 通用骨架（滚动变量版）
// 适用：dp[i] 只依赖前面固定常数个状态
long long solve(int n) {
    long long a = /*dp[0]*/, b = /*dp[1]*/;   // 初值给够（窗口=2 就 2 个）
    if (n == 0) return a;
    if (n == 1) return b;
    for (int i = 2; i <= n; i++) {
        long long cur = /* f(a, b)，即 dp[i] 的递推式 */;
        a = b; b = cur;                        // 窗口整体右移一格
    }
    return b;
}
```
```cpp
int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    // ... same as above
}
```

