# ⚙️ C++ <algorithm> Quick Reference (算法库速查表)

**前置条件**：使用这些函数前，必须在文件开头 `#include <algorithm>`。所有操作通常通过传入起始和结束迭代器 `[begin, end)` 来界定范围。

## 1. 二分查找系列 (Binary Search)
**⚠️ 核心大前提**：操作的数组或容器**必须是有序的**（通常是升序）！

* **`lower_bound` (核心中的核心)**
  * **作用**：在有序范围里，快速找**第一个满足 `>= x`** 的元素位置。
  * **语法**：`auto it = lower_bound(a.begin(), a.end(), x);`
  * **解析返回值**：返回的是一个**迭代器 (Iterator)**。
    * 要拿具体的值：必须加星号解引用 `cout << *it;`
    * 要拿索引下标：减去 begin 指针 `int index = it - a.begin();`
    * **找不到的情况**：如果所有数都比 x 小，它会返回 `a.end()`。**千万不能**对 `end()` 直接解引用，会报错！
* **`upper_bound` (兄弟函数)**
  * **作用**：找**第一个严格 `> x`** 的元素位置。用法和 `lower_bound` 完全一致。
* **`binary_search`**
  * **作用**：仅仅回答“有没有 x”这个问题。返回 `true` 或 `false`。

---

## 2. 极值与排序系列 (Min/Max & Sorting)

* **元素比较**
  * `max(a, b);` / `min(a, b);` // 比较两个数的大小
* **范围极值查找**
  * **语法**：`auto it = max_element(v.begin(), v.end());`
  * **作用**：找到数组里的最大值。返回的同样是**迭代器**。
  * **拿值**：`int max_val = *max_element(v.begin(), v.end());`
* **全排列排序**
  * `sort(v.begin(), v.end());` // 默认从小到大升序排列 (O(N log N))
  * `sort(v.begin(), v.end(), greater<int>());` // 从大到小降序排列
* **翻转数组**
  * `reverse(v.begin(), v.end());` // 直接把数组前后倒置（不是排序，只是物理翻转）

---

## 3. 高级去重与排列 (Advanced)

* **`unique` (数组去重)**
  * **大前提**：使用前必须先 `sort()` 排序，让相同的元素挨在一起。
  * **作用**：把重复的元素“挤”到数组末尾去。
  * **语法**：`auto it = unique(v.begin(), v.end());` // 返回去重后，新数组末尾的迭代器。
  * **结合删除**：通常写成 `v.erase(unique(v.begin(), v.end()), v.end());` 真正切掉重复元素。
* **`next_permutation` (下一个字典序排列)**
  * **作用**：在做枚举题时，如果需要枚举全排列，这个函数极其好用。
  * **用法**：
    ```cpp
    vector<int> a = {1, 2, 3};
    do {
        // 会依次输出 123, 132, 213, 231, 312, 321
    } while (next_permutation(a.begin(), a.end()));
    ```