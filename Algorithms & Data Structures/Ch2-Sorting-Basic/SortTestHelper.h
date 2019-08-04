//
//	Created by Rong Dai on 8/4/19
//
//比较排序算法的辅助头文件

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include<iostream>
#include<ctime>
#include<cassert> 

using namespace std; 

namespace SortTestHelper{
	//生成n个数的随机数组，每个元素范围为[rangeL, rangeR] 
	int* generateRandomArrary(int n, int rangeL, int rangeR){
		
		assert( rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for(int i = 0; i < n; i++){
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}
	
	//打印函数，模板函数
	template<typename T>
	void printArrary(T arr[], int n){
		for(int i = 0; i < n; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		return;
		}
	}

#endif
