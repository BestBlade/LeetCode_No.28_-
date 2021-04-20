/* ------------------------------------------------------------------|
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

 

说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

 

示例 1：

输入：haystack = "hello", needle = "ll"
输出：2
示例 2：

输入：haystack = "aaaaa", needle = "bba"
输出：-1
示例 3：

输入：haystack = "", needle = ""
输出：0
 

提示：

0 <= haystack.length, needle.length <= 5 * 104
haystack 和 needle 仅由小写英文字符组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.6 MB, 在所有 C++ 提交中击败了82.71%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();

    if (!n) {
        return 0;
    }
    if (m == n) {
        return haystack == needle ? 0 : -1;
    }
    if (m < n) {
        return -1;
    }

    for (int i = 0; i <= m - n; ++i) {
        if (haystack[i] == needle[0]) {

            string tmp = haystack.substr(i, n);
            if (tmp == needle) {
                return i;
            }

            //for (int j = 0; j < n; ++j) {
            //    if (haystack[i + j] == needle[j]) {
            //        if (j == n - 1) {
            //            return i;
            //        }
            //    }
            //    else {
            //        break;
            //    }
            //}

        }
    }
    return -1;
}