//
//	Created by Rong Dai on 8/4/19
//
#include<iostream>
#include<algorithm> 
#include "SortTestHelper.h"
//选择排序和插入排序 
//插入排序对近乎有序的数组效率非常高 

using namespace std;

//选择排序,从小到大排序 
template<typename T>
void selectionSort(T arr[], int n){
	for(int i = 0; i < n; i++){
		int minIndex = i; 
		for(int j = i + 1; j < n; j++)
			if(arr[j] < arr[minIndex])
			minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}

//插入排序
template<typename T>
void insertSort(T arr[], int n){
	
	for(int i = 1; i < n; i++){
		//寻找元素arr[i]合适的插入位置 
		T tmp = arr[i];
		int j;
		for(j = i; j > 0 && (arr[j - 1] > tmp); j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
} 
int main(){
	
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArrary(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArrary(arr,n); 
	
	//selectionSort(arr, n);
	//SortTestHelper::printArrary(arr, n);
	
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n); 
	SortTestHelper::testSort("Insert Sort", insertSort, arr2, n); 
	
	delete[] arr;
	delete[] arr2;
	return 0;
}
