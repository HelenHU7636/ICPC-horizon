// 考场上的手写队列（原生数组实现）
const int MAXN = 100005; // 题目给的最大数据量
int q[MAXN];             // 这就是我们的队列
int head = 0;            // 队头指针
int tail = -1;           // 队尾指针

// 等价于 q.push(x)
q[++tail] = x; 

// 等价于 q.front()
int current = q[head]; 

// 等价于 q.pop()
head++; 

// 等价于 q.empty()
if (head <= tail) // 不为空