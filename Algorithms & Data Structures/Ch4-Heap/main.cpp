//
//	Created by Rong Dai on 8/6/19
//
//优先队列，从N个元素中取出前M大个，O(NlogM)
//堆,优先队列，入队和出队O(lgN) 

//建立堆的方式：以下两种 
//将n个元素插入空堆，算法复杂度为O(NlogN) 
//Heapify的过程，从arr[n/2]往前所有元素Shift Down，算法复杂度为O(n) 

//最大堆
//堆中某个节点的值不大于父节点的值；堆是一个完全二叉树

#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<cmath>
#include<cassert>
#include<typeinfo>

using namespace std;

template<typename Item>
class MaxHeap{
private:
	Item* data;
	int count;
	int capacity;
	void shiftUp(int k){		//Shift Up 操作（私有），与父节点直接交换 
		while(k >1 && data[k/2] < data[k]){
			swap(data[k/2], data[k]);
			k/=2;
		}
	}
	
	void shiftDown(int k){		////Shift Down 操作（私有），与孩子中大的直接交换
		while(k*2 <= count){	//判断有没有左孩子
			int j = 2*k;		//data[k]与data[j]交换
			if(j + 1 <= count && data[j + 1] > data[j])  j+=1;	//完全二叉树，可能没有左孩子 
			if(data[k] >= data[j]) break;
			swap(data[k],data[j]);
			k = j; 
		} 
	}

public:
	//堆顶索引为1！！！ 
	MaxHeap(int capacity){	//堆容量为capacity 
		data = new Item[capacity + 1];
		count = 0;
		this->capacity= capacity;
	}
	
	void insert(Item item){	//添加元素，Shift up 
		assert(count + 1 <= capacity);
		data[++count] = item;
		shiftUp(count);
	}
	
	Item extractMax(){ 	//取出最大值，即堆顶元素，然后交换堆顶和堆末，维护堆, Shift Down 
		assert(count > 0);
		Item ans = data[1];
		swap(data[1], data[count--]);
		shiftDown(1);
		return ans;
	}
	
	~MaxHeap(){				//析构函数 
		delete [] data;
	}
	
	int size(){
		return count;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	

};

int main(){
	
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	
	srand(time(NULL));
	for(int i = 0; i < 10; i++)
		maxheap.insert(rand()%10);
	while(!maxheap.isEmpty())
		cout<<maxheap.extractMax()<<" ";
	 
	return 0;
} 
