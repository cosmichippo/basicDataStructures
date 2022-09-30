//
// Created by Juan-Fernando Prado Morales on 5/26/21.
//

#ifndef ASGMT5_HEAPPRIORITYQUEUE_H
#define ASGMT5_HEAPPRIORITYQUEUE_H
#include "VectorCompleteTree.h"

template <typename E>
class Comparator{
public:
    bool operator()(const E& p, const E& q){
        return p < q;
    }
};

template <typename E, typename C>
class HeapPriorityQueue {
public:
    int size() const;
    bool empty() const;
    void insert(const E& e);
    void removeMin();
    const E& min();
private:
    VectorCompleteTree<E> T;
    C isLess;

    typedef typename VectorCompleteTree<E>::Position Position;

};


#endif //ASGMT5_HEAPPRIORITYQUEUE_H
