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
	
	
	//是否排序的判断函数，模板函数
	template<typename T>
	bool isSorted(T arr[], int n){
		
		for(int i = 0; i < n - 1; i++)
			if(arr[i] > arr[i + 1]) return false;
		
		return true;
	} 
	
	//测试排序函数时间，模板函数，传入sort函数 
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
		
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		
		assert(isSorted(arr,n));
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
		
		return;
	}
	
	//复制数组 
	int* copyIntArrary(int a[],  int n){
		int *arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}

}
#endif
