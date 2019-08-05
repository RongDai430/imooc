//
//	Created by Rong Dai on 8/5/19
//
//���������ͷ�ļ�

#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

//��������,��arr[0....n]�������� 
template<typename T>
void insertSort(T arr[], int n){
	
	for(int i = 1; i < n; i++){
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ�� 
		T tmp = arr[i];
		int j;
		for(j = i; j > 0 && (arr[j - 1] > tmp); j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
} 

//��������,��arr[l....r]��������
template<typename T>
void insertSort_lr(T arr[], int l, int r){
	
	for(int i = l + 1; i <= r; i++){
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ�� 
		T tmp = arr[i];
		int j;
		for(j = i; j > l && (arr[j - 1] > tmp); j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
} 

#endif
