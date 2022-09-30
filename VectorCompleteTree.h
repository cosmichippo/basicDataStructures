//
// Created by Juan-Fernando Prado Morales on 5/26/21.
//

#ifndef ASGMT5_COMPLETETREE_H
#define ASGMT5_COMPLETETREE_H
#include <vector>


template <typename  E>
class VectorCompleteTree {
public:
    typedef typename std::vector<E>::iterator Position;
    VectorCompleteTree() : V(1) {}
    int size() const {return V.size() - 1;}
    Position left (const Position& p) {return pos(2*idx(p));}
    Position right (const Position& p) {return pos(2*idx(p) + 1);}
    Position parent (const Position& p) {return pos(idx(p)/2);}
    bool hasLeft(const Position& p) const {return 2*idx(p) <= size();}
    bool hasRight(const Position& p) const {return 2*idx(p) + 1 <= size();}
    bool isRoot(const Position& p) const{return idx(p) == 1;}
    Position root() {return pos(1);}
    Position last() {return pos(size());}
    void addLast(const E& e) {V.push_back(e);}
    void removeLast() {V.pop_back();}
    void swap(const Position& p, const Position& q){
        E e = *q; *q = *p; *p = e;
    }
protected:
    Position pos(int i){
        return V.begin() + 1;
    }
    int idx(const Position& p) const{
        return p - V.begin();
    }
private:
    std::vector<E> V;
};


#endif //ASGMT5_COMPLETETREE_H
