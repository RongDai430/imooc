//
//	Created by Rong Dai on 8/5/19
//
//�Ե����ϵĹ鲢���� 

#include<iostream>
#include<algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

template<typename T>
void mergeSortBU(T arr[], int n){
	for(int sz = 1; sz <=n; sz*=2)	//����size�Ĵ�С 
		for(int i = 0; i + sz < n; i += 2 * sz) 	//����Խ������ 
			//��arr[i...i+sz-1] �� arr[i+sz....i+sz+sz-1]���й鲢 
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
