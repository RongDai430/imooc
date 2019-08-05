//
//	Created by Rong Dai on 8/5/19
//
//插入排序的头文件

#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

//插入排序,对arr[0....n]进行排序 
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

//插入排序,对arr[l....r]进行排序
template<typename T>
void insertSort_lr(T arr[], int l, int r){
	
	for(int i = l + 1; i <= r; i++){
		//寻找元素arr[i]合适的插入位置 
		T tmp = arr[i];
		int j;
		for(j = i; j > l && (arr[j - 1] > tmp); j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
} 

#endif
