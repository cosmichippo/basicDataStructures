//
// Created by Juan-Fernando Prado Morales on 5/23/21.
//

#include "LinkedList.h"

template <class NodeType>
NodeType& ListIterator<NodeType>::operator*(){
    return v->data;
}
template <class NodeType>
bool ListIterator<NodeType>::operator== (const ListIterator<NodeType>& p) const{
    return v == p.v;
}

template <class NodeType>
bool ListIterator<NodeType>::operator!= (const ListIterator<NodeType>& p) const{
    return v != p.v;
}

template <class NodeType>
ListIterator<NodeType>& ListIterator<NodeType>::operator++(){
    v = v->next;
    return *this;
}

template<class NodeType>
ListIterator<NodeType>& ListIterator<NodeType>::operator--() {
    v = v->prev;
    return *this;
}

template <class NodeType>
bool ListIterator<NodeType>::operator< (const ListIterator<NodeType>& p) const{
    if (this->v->data < p.v->data){
        return true;
    }
    return false;
}
template<class NodeType>
ListIterator<NodeType>::ListIterator(Node<NodeType>* u){
    v = u;
}
