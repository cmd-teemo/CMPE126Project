#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>
#include <iostream>


class Heap {
  private:
  std::vector<int> heap;

  void heapifyDown(int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left < heap.size() && heap[left] > heap[largest])
      largest = left;

      if(right < heap.size() && heap[right] > heap[largest])
        largest = right;

        if(largest != i){
          std::swap(heap[i], heap[largest]);
          heapifyDown(largest);
        }
      }
       void heapifyUp(int i){
         int parent = (i-1)/2;
         if(parent >= 0 && heap[i]>heap[parent]){
         std::swap(heap[i], heap[parent]);
         heapifyUp(parent);
       }
    }
    public:
      void insert(int val){
        heap.push_back(val);
        heapifyUp(heap.size()-1);
      }

      int extractMax(){
        if(heap.empty()) throw std::runtime_error("Heap is empty");
        int maxval = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxval;
      }

      void display(){
        for(int value : heap){
          std::cout << value << " ";
        }
        std::cout << std::endl;
      }
};

#endif