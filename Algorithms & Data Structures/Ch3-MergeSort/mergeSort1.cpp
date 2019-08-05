//
//	Created by Rong Dai on 8/5/19
//
//归并排序
//二分，复杂度为O(lgN)
//归并，复杂度为O(N)

#include<iostream>
#include<algorithm>
#include "SortTestHelper.h"
#include "InsertSort.h"
using namespace std;


//将arr[l...mid]和arr[mid+1...r]合并 
template<typename T>
void __merge(T arr[], int l, int mid, int r){
	T aux[r - l + 1];	//暂时的存放数组 
	for(int i = l; i <= r; i++) aux[i - l] = arr[i];
	
	int i = l, j = mid + 1;
	for(int k = l; k <= r; k++){
		if(i > mid){				//先判断越界问题 
			arr[k] = aux[j - l];
			j++;
		}
		else if(j > r){
			arr[k] = aux[i - l];
			i++;
		}
		else if(aux[i - l] < aux[j - l]){
			arr[k] = aux[i - l];
			i++;
		}
		else{
			arr[k] = aux[j - l];
			j++;
		}
	}
}

//递归排序,对arr[l....r]范围进行排序 
template<typename T>
void __mergeSort(T arr[], int l, int r){
	
	//if(l >= r) return;
	
	if(r - l <= 15){					//在r-l较小时，选取插入排序替代较小部分的递归归并排序 
		insertSort_lr(arr, l, r);		//因为，在小数组时，有序的情况可能性更大，插入排序效率更高 
		return;
	}
	
	int mid = (r - l)/2 + l;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if(arr[mid] <= arr[mid + 1]) return; //归并排序的优化，跳过有序数列的算法 
	__merge(arr, l, mid, r); 
}

template<typename T>
void mergeSort(T arr[], int n){
	__mergeSort(arr, 0, n - 1); 
}
 
int main(){
	
	int n = 50000;
	int *arr1 = SortTestHelper::generateRandomArrary(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArrary(arr1, n); 
	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertSort, arr2, n);
	
	delete[] arr1;
	delete[] arr2;
	
	return 0;
} 
