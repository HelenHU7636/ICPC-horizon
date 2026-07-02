# LeetCode 已刷题单🚀


| 题号 | 题名 | 题解 | 解法 | 备注 | 一句话题解 |
| :--- | :--- | :---: | :--- | :--- | :--- |
| 70 | [climbing-stairs](https://leetcode.cn/problems/climbing-stairs/) | / |  | / | Hu:位置约束，无需选择 |
| 1137 | [n-th-tribonacci-number](https://leetcode.cn/problems/min-cost-climbing-stairs/) | ✅ | | / | Hu:同上 |
| 746 | [min-cost-climbing-stairs](https://leetcode.cn/problems/min-cost-climbing-stairs/) | ✅|  | / | Hu:同上 |
| 198 | [house-robber](https://leetcode.cn/problems/house-robber/) | ✅|  |  | Hu:位置约束，相邻互斥。利用单调性剪枝 |
| 300| [longest-increasing-subsequence](https://leetcode.cn/problems/longest-increasing-subsequence/)|/| https://labuladong.online/zh/algo/dynamic-programming/maximum-subarray/|xcy: 最巧妙的点在于把dp定义为“只考虑到第i个，且第i个元素术语在递增子序列当中”（类似于打家劫舍）；针对“原有的最长递增子序列不一定包含最后一个元素”的问题，解决方法是遍历之前的所有元素 | / |
|354 |[russian-doll-envelopes](https://leetcode.cn/problems/russian-doll-envelopes/) |/| https://labuladong.online/zh/algo/dynamic-programming/maximum-subarray/| | / |
|322 |[coin-change](https://leetcode.cn/problems/coin-change/description/)|/|/|ld:使用INF(ie9)表示"不可达"会更便捷,计算max就用-INF;顺便,其他很多题选最大可以用*max_element(dp.begin(), dp.end());然后正常dp比较慢别人用剪枝+贪心非常快后续需要提速可以参考这道"数学预判 (GCD) + 缩小区间枚举 + 回溯搜索 + 贪心思想辅助"| / |
|53 |[maximum-subarray](https://leetcode.cn/problems/maximum-subarray/description/)|/|/|/| / |
|887 |[super-egg-drop](https://leetcode.cn/problems/super-egg-drop/description/)|/|/|/| / |

> **2D DP 通用写法**：`vector<vector<int>> dp(m, vector<int>(n, 1));`
> ld:提醒自己最后返回不能dp[i][j],有范围问题要用dp[l1][l2]
> 
| 题号 | 题名 | 题解 | 解法 | 备注 |
| :--- | :--- | :---: | :--- | :--- |
|72 |[edit-distance](https://leetcode.cn/problems/edit-distance/)|/|/|[DP所有能踩的坑汇总](https://leetcode.cn/problems/edit-distance/solutions/3985038/yi-ti-cai-bian-dpsuo-you-de-keng-by-yi-m-yvpu)xcy:有时候要能够发现这题要用动态规划，发现是二维的，以及发现相应的指标，比方说这题“前i个替换为前j个”就要自己定义出来；注意边界，+1和-1容易弄错|
|62 |[Unique Paths](https://leetcode.com/problems/unique-paths)|/|1. DP 数组 <br>2. 数学方法,排列组合公式但是要注意溢出  |ld:针对法2,有很多提高速度的方法也有很多坑https://leetcode.com/problems/unique-paths/solutions/8334724/unique-paths-combinatorics-solution-by-d-x51j <br>xcy:带图的一看就知道是dp，不带图的就看不出来
|64 |[Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/)|/|/|ld:依旧使用inf感觉省事不知道有没有别的方法https://leetcode.com/problems/minimum-path-sum/solutions/8335368/minimum-path-sum-by-deanna-l-wqb2|
|1143 |[longest-common-subsequence](https://leetcode.cn/problems/longest-common-subsequence/)|[如何确定状态转移方程及数组的维度数](https://leetcode.cn/problems/longest-common-subsequence/solutions/3985637/ru-he-que-ding-zhuang-tai-zhuan-yi-fang-li95u)|xcy：这题有三种状态转移方式，max的运用非常巧妙|/|
|494 |[target-sum](https://leetcode.cn/problems/target-sum/)|/|xcy：我自己做麻烦了，原因是没想到做数学转换，转化成在数组 nums 中选取若干元素，使得这些元素之和等于 neg；跟“分割等和子集”有点像，提前转换一下就能把问题简化很多，正所谓“多想少算”|/|
|416 |[partition-equal-subset-sum](https://leetcode.com/problems/partition-equal-subset-sum/description/)|/|xcy：同上，数学转换很重要|ld:01背包,物品外层，容量从大往小走.遍历每一物品,然后对每一物品里倒着更新dp[i]|
