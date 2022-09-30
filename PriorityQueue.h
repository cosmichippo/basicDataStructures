//
// Created by Juan-Fernando Prado Morales on 5/21/21.
//

#ifndef ASGMT5_PRIORITYQUEUE_H
#define ASGMT5_PRIORITYQUEUE_H

#include "LinkedList.h"
template<class NodeType>
class PriorityQueue  : public LinkedList<NodeType> {
    public:
    // read up ch 8 on priority queue, and comparator objects.
        void insert(NodeType t);
        ListIterator<NodeType>& find_min(ListIterator<NodeType> iter);

        NodeType& min();

        void remove_min();


        bool is_empty();

        LinkedList<NodeType> q;

};


#endif //ASGMT5_PRIORITYQUEUE_H
