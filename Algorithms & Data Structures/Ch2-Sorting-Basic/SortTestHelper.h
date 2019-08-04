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
	}

#endif
