//
//	Created by Rong Dai on 8/4/19
//
//�Ƚ������㷨�ĸ���ͷ�ļ�

#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESTHELPER_H

#include<iostream>
#include<ctime>
#include<cassert>

using namespace std; 

namespace SortTestHelper{
	//����n������������飬ÿ��Ԫ�ط�ΧΪ[rangeL, rangeR] 
	int* generateRandomArrary(int n, int rangeL, int rangeR){
		
		assert( rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for(int i = 0; i < n; i++){
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}
	
	//��ӡ������ģ�庯��
	template<typename T>
	void printArrary(T arr[], int n){
		for(int i = 0; i < n; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		return;
		}
	
	
	//�Ƿ�������жϺ�����ģ�庯��
	template<typename T>
	bool isSorted(T arr[], int n){
		
		for(int i = 0; i < n - 1; i++)
			if(arr[i] > arr[i + 1]) return false;
		
		return true;
	} 
	
	//����������ʱ�䣬ģ�庯��������sort���� 
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
		
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		
		assert(isSorted(arr,n));
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
		
		return;
	}
	
	//�������� 
	int* copyIntArrary(int a[],  int n){
		int *arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}

}
#endif
