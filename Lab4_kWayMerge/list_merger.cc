//
// Created by Bori on 10/27/2020.
//

#include "list_merger.h"

template<class T>
List<T>* ListMerger<T>::merge(Operation* op_comp, Operation* op_assign, Operation*
op_pointer_assign) {
  Node<T>** heap_content = (Node<T>**) malloc(sizeof(Node<T>*)*no_lists);
  for (int i = 0; i < no_lists; i++) {
    heap_content[i] = lists[i]->PopFrontNode();
    op_pointer_assign->count();
  }
  Heap<Node<T>> min_heap(heap_content, no_lists, Heap<Node<T>>::HeapType::kMinHeap, op_comp,
                         op_pointer_assign);
  List<T>* result = new List<int>(op_assign, op_pointer_assign);
  while (min_heap.size() > 0) {
    op_pointer_assign->count();
    Node<T>* minim = min_heap.Pop();
    if (minim->hasNext()) {
      min_heap.Push(minim->getNext());
    }
    result->PushBack(minim);
  }
  return result;
}

template<class T>
void ListMerger<T>::AddList(List<T> *list) {
  if (no_lists == kMaxNoLists) {
    cerr << "Maximum number of lists exceeded" << endl;
    exit(1);
  }
  lists[no_lists] = list;
  no_lists++;
}

template class ListMerger<int>;