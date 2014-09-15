/*************************************************************************
	> File Name: two_sum.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Sat 13 Sep 2014 07:21:23 AM PDT
 ************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*解题思路:
 * (1) O(nlogn).排序,然后两个指针一前一后。题目中说了只有一对答案。
 * (2) 
 *
 */

const int size=5;
struct node{
	int value;
	int pos;
};

bool cmp(node a,node b){
	return a.value<b.value;
}

vector<int> twoSum(vector<int> &numbers,int target){
	   vector<node> array;
       vector<int> result;
	   int i;
	   for(i=0;i!=numbers.size();i++){
           node tmp;
		   tmp.value=numbers[i];
		   tmp.pos=i;
		   array.push_back(tmp);
	   }

	   sort(array.begin(),array.end(),cmp);
       int ix=0,iy=array.size()-1;
	   while(ix<iy){
		   int sum=array[ix].value+array[iy].value;
		   if(sum==target){
			   if(array[ix].pos<array[iy].pos){
				   result.push_back(array[ix].pos+1);
				   result.push_back(array[iy].pos+1);
			   }
			   else{
				   result.push_back(array[iy].pos+1);
				   result.push_back(array[ix].pos+1);
			   }
			   break;
		   }
		   else if(sum<target) ix++;
		   else iy--;
	   }

	   return result;
}

vector<int> twoSum(vector<int> &number,int target){
	int len=numbers.size();
	unorders_set<int> my_hash(numbers.begin(),numbers.end());
	int i,j;
	vector<int> res;

	for(i=0;i<len;i++){
		if(myhash.find(target-numbers[i])!=myhash.end()){
			res.push_back(i+1);
			break;
		}
	}

	for(j=i+1;j<len;j++){
		if(numbers[j]==target-numbers[i]){
			res.push_back(j+1);
			return res;
		}
	}
}

int main(int argc,const char* argv[]){
	int i;
	vector<int> numbers;
	numbers.clear();
	for(i=0;i<size;i++){
		int tmp;
		cin>>tmp;
		numbers.push_back(tmp);
	}

	vector<int> result=twoSum(numbers,9);
	for(vector<int>::iterator iter=result.begin();iter!=result.end();iter++){
		cout<<*iter<<" ";
	}

	cout<<endl;
}



