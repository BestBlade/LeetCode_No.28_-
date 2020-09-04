/*--------------------------------------------------------------------------------------------------|
实现 strStr() 函数。																				|
																									|
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置|
(从0开始)。如果不存在，则返回  -1。																	|
																									|
示例 1:																								|
																									|
输入: haystack = "hello", needle = "ll"																|
输出: 2																								|
示例 2:																								|
																									|
输入: haystack = "aaaaa", needle = "bba"															|
输出: -1																							|
说明:																								|
																									|
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。							|
																									|
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义|
相符。																								|
																									|
来源：力扣（LeetCode）																				|
链接：https://leetcode-cn.com/problems/implement-strstr												|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。								|
---------------------------------------------------------------------------------------------------*/

/*
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了87.95%的用户
*	内存消耗：6.9 MB, 在所有 C++ 提交中击败了56.04%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int strStr(string haystack, string needle) 
{
	int n_size = needle.size();
	int h_size = haystack.size();

	if (n_size == 0)
	{
		return 0;
	}
	if (h_size < n_size)
	{
		return -1;
	}
	for (int i = 0; i <= h_size - n_size; i++)
	{
		for (int j = 0; j < n_size; j++)
		{
			if (haystack[i + j] != needle[j])
			{
				break;
			}
			else
			{
				if (j == n_size - 1)
				{
					return i;
				}
			}
		}
	}
	return -1;
}

int main()
{
	string haystack = "hello";
	string needle = "";

	cout << strStr(haystack, needle) << endl;
}