/*************************************************************************
	> File Name: Median_Of_Two_SortedArray.cpp
	> Author: canjian
	> Mail:410001089@qq.com 
	> Created Time: Sun 14 Sep 2014 08:17:33 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

/*
double findMedianSortedArrays(int A[],int m,int B[],int n){
	int result;
	int num=(m+n+1)/2;

	int i=0,j=0,cnt=0;
	while(i!=m && j!=n){
		if(A[i]<B[j]){
			result=A[i];
			i++;
			cnt++;
		}

		else{
			result=B[j];
			j++;
			cnt++;
		}

		if(cnt==num){
			break;
		}
	}


	while(i!=m){
		if(cnt==num) break;
		else{
			result=A[i];
			i++;
			cnt++;
		}
	}

	while(j!=n){
		if(cnt==num) break;
		else{
			result=B[j];
			j++;
			cnt++;
		}
	}
	return result;
}

*/


/*
*可以采用递归的方式实现寻找第k小的元素
 * 如果A或者B为空,则直接返回B[k-1]或者A[k-1];
 * 如果k为1,我们只需要返回A[0]和B[0]中的较小值;
 * 如果A[k/2-1]==B[k/2-1],则返回其中一个.
 */
 

double findKth(int A[],int m,int B[],int n,int k){
	//always assume that m is equal or smaller than n
	if(m>n)
		return findKth(B,n,A,m,k);

	if(m==0)
		return B[k-1];
	if(k==1)
		return min(A[0],B[0]);

	//divide k into two parts
	int pa=min(k/2,m),pb=k-pa;
	if(A[pa-1]<B[pb-1]){
		return findKth(A+pa,m-pa,B,n,k-pa);
	}

	else if(A[pa-1]>B[pb-1]){
		return findKth(A,m,B+pb,n-pb,k-pb);
	}

	else
		return A[pa-]1;
}

int main(int argc,char* argv[]){
	int A[5]={1,3,5,7,9},B[4]={2,4,6,8};
    cout<<findMedianSortedArrays(A,5,B,4)<<endl;
}

