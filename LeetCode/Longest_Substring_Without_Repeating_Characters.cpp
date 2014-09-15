/*************************************************************************
	> File Name: Longest_Substring_Without_Repeating_Characters.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Mon 15 Sep 2014 06:27:19 AM PDT
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


/*解题思路:
 *用一个map[256]来记录出现过的字符位置.
 *遇到没有出现过的字符,将map对应位置标记,并且子串长度+1.
 *遇到出现过的子串,将子串自上一次出现该字符位置前面的截断,对这部分截断的字符,标记map为notFound,重新计算子串长度
 */


int lengthOfLongestSubstring(string s){
    int map[256];
	const int notFound=-1;
	for(int i=0;i<256;i++){
		map[i]=notFound;
	}

	int maxlen=0;
	int len=0;

	for(int i=0;i<s.size();i++){
		char si=s[i];
		int lastSi=map[si];

		if(lastSi==notFound){
			len++;
			map[si]=i;
			if(maxlen<len) maxlen=len;
		}

		else{
			int curStart=i-len;
            for(int j=curStart;j<lastSi;j++){
				map[si]=notFound;
			}
			curStart=si+1;
			len=i-curStart+1;
			map[si]=i;
		}
	}
	return maxlen;
}


int main(int argc,const char* argv[]){
//	string s="abcabcbb";
    string s="bbbbb";
	cout<<lengthOfLongestSubstring(s)<<endl;
}
