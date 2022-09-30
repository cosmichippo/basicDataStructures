//
// Created by Juan-Fernando Prado Morales on 5/21/21.
//

#include "PriorityQueue.h"
#include <iostream>
template <class NodeType>
void PriorityQueue<NodeType>::insert(NodeType t) {
    if(q.front() != nullptr) {
        Node<NodeType>* temp = new Node<NodeType>();
        temp->data = t;
        ListIterator<NodeType> dat = ListIterator<NodeType>(temp);
        ListIterator<NodeType> iter = ListIterator<NodeType>(q.front());
        while (iter.v->next != nullptr && iter < dat) {
            ++iter;
        }
        if(iter.v->next == nullptr && iter < dat){
            //std::cout << "next:"<< dat.v->data << std::endl;
            q.insertFromNext(iter, dat);
        }
        else{
            //std::cout << "prev:" << dat.v->data <<std::endl;
            q.insertFromPrev(iter, dat);
        }
    }
    else{
        //std::cout<< "first:" << t <<std::endl;
        q.insert_front(t);
    }
}

template <class NodeType>
ListIterator<NodeType>& PriorityQueue<NodeType>::find_min(ListIterator<NodeType> iter){
    ListIterator<NodeType> min_val = ListIterator<NodeType>(iter.v);
    while (iter != nullptr) {

        if (iter < min_val) {

            min_val.v = iter.v;
        }
        ++iter;
    }
    return min_val;
}

template <class NodeType>
NodeType& PriorityQueue<NodeType>::min(){
    return q.front()->data;
}

template <class NodeType>
bool PriorityQueue<NodeType>::is_empty() {
    return q.empty();
}

template <class NodeType>
void PriorityQueue<NodeType>::remove_min() {
    q.remove_front();
}
