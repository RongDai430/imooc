//
//	Created by Rong Dai on 8/5/19
//
//自底向上的归并排序 

#include<iostream>
#include<algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

template<typename T>
void mergeSortBU(T arr[], int n){
	for(int sz = 1; sz <=n; sz*=2)	//调整size的大小 
		for(int i = 0; i + sz < n; i += 2 * sz) 	//考虑越界问题 
			//对arr[i...i+sz-1] 和 arr[i+sz....i+sz+sz-1]进行归并 
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
	
}

int main(){
	
	int n = 500000;
	int *arr1 = SortTestHelper::generateRandomArrary(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArrary(arr1, n); 
	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("MergeBU Sort", mergeSortBU, arr2, n);
	
	delete[] arr1;
	delete[] arr2;
	
	return 0;
} 
