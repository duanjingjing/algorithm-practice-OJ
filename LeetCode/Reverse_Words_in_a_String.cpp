/*************************************************************************
  > File Name: Reverse_Words_in_a_String.cpp
  > Author: canjian
  > Mail:410001089@qq.com 
  > Created Time: Tue 09 Sep 2014 01:12:34 AM PDT
 ************************************************************************/
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

void trim_space(string&);

void reverseWords(string& s){
	trim_space(s);
	reverse(s.begin(),s.end());

	string::iterator iter1=s.begin();
	string::iterator iter2=iter1;

	while(iter2!=s.end()){
		if(*iter2==' '){
			reverse(iter1,iter2);
			iter1=iter2;
			iter1++;
		}
		iter2++;
	}
	reverse(iter1,iter2);
}


void trim_space(string& s){
	string::iterator iter1,iter2=s.begin();
	iter1=iter2;
	bool flag=false;

	while(*iter1!='\0'){
		while(*iter1==' ') iter1++;
		if(*iter1=='\0') break;

		while(*iter1!=' ' && *iter1!='\0') *iter2++=*iter1++;

		*iter2++=' ';
	}

	*iter2='\0';
	s=s.substr(s.begin(),iter2);
}


int main(int argc,const char* argv[]){
	string s(" the          sky        is          blue     ");
    trim_space(s);
//	reverseWords(s);
	cout<<s<<endl;
}

