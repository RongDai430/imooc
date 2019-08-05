//
//	Created by Rong Dai on 8/5/19
//
//快速排序
//对于基本有序数列，引入随机初始化的Partition操作
//对于有很多重复元素数列，采用最优的Partition操作，进行三路排序 

#include<iostream>
#include<algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertSort.h"

using namespace std;

//对arr[l..r]进行最优的partition操作
//返回索引值，使得arr[l..p-1] < arr[p]；arr[p+1...r] > arr[p] 
template<typename T> 
int __partition(T arr[], int l, int r){
	swap(arr[rand() % (r - l + 1) + l], arr[l]); //随机标准值
	T v = arr[l];
	//arr[l+1...i) <= v; arr(j...r] >= v
	int i = l + 1, j = r;
	while(true){
		while(arr[i] < v && i <= r) i++;
		while(arr[j] > v && j >= l + 1) j--;
		if(i > j) break;
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
	//循环结束后，i停留在第一个大于等于v的索引，j停留在第一个小于等于v的索引 
	swap(arr[l], arr[j]);
	return j; 
}

//对arr[l..r]进行partition操作
//返回索引值，使得arr[l..p-1] < arr[p]；arr[p+1...r] > arr[p] 
template<typename T>
int __partition2(T arr[], int l, int r){		//对于这种Partition，对于重复元素较多的数组，会导致左右分割不平衡，效率低下 
	
	swap(arr[rand() % (r - l + 1) + l], arr[l]);	//进行优化，随机选取partition的"标准值" 
													//对于序列基本有序情况，有极大的优化效果
													//引入随机性后，快排的复杂度期望值为O(NLogN) 
	
	T v = arr[l]; 
	//arr[l+1...j] < v; arr[j+1...i) >= v
	int j = l;
	for(int i = l + 1; i <= r; i++) {	//当前考虑的索引是i 
		if(arr[i] >= v) continue;
		swap(arr[j + 1], arr[i]);
		j++;
	}
	swap(arr[l], arr[j]); 
	return j;
}



//对arr[l..r]进行快速排序 
template<typename T>
void __quickSort(T arr[], int l, int r){
	//if(l >= r) return;
	
	if(r - l <= 15){				//同理，在底层，对小数组时使用插入排序 
		insertSort_lr(arr, l, r);
		return;
	}
	
	int p = __partition(arr, l , r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n){
	srand(time(NULL));
	__quickSort(arr, 0, n - 1); 
}

int main(){
	
	int n = 100000;
	int *arr1 = SortTestHelper::generateRandomArrary(n, 0, 10);
	int *arr2 = SortTestHelper::copyIntArrary(arr1, n);
	
	SortTestHelper::testSort("Merge Sort",mergeSort,arr1, n);
	SortTestHelper::testSort("Quick Sort",quickSort,arr2, n);
	
	delete[] arr1;
	delete[] arr2;
	
	return 0;
}
