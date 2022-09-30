//
// Name: Juan-Fernando Morales
// SSID: 1838814
// Assignment #: 5
// Submission Date: 5/27/21
//


#include <iostream>
#include <queue>
#include <ctime>
#include <random>
#include <chrono>
#include <iomanip>

#include "HeapPriorityQueue.h"
#include "HeapPriorityQueue.cpp"

#include "LinkedList.h"
#include "LinkedList.cpp"
#include "ListIterator.cpp"

#include "PriorityQueue.h"
#include "PriorityQueue.cpp"

#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"


int main() {
    int SAMPLES = 1000;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    PriorityQueue<int> pq = PriorityQueue<int>();
    std::vector<int> sorted;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SAMPLES; i++){
        pq.insert(std::rand() % 1000 + 1);
    }
    while (pq.q.front() != nullptr){
        sorted.push_back(pq.min());
        pq.remove_min();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "sorted linkedlist priority queue sequence sorting took" <<
    std::fixed << std::setprecision(2)
    << std::chrono::duration_cast<std::chrono::microseconds>(stop - start ).count() / 1000.0 << " milliseconds" <<std::endl;

    //std priority queue
    std::priority_queue<int, std::deque<int>> stl_priority_queue;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sorted.clear();
    start = std::chrono::high_resolution_clock::now();
    for (int i =0; i < SAMPLES; i++){
        stl_priority_queue.push(std::rand() % 1000 + 1);
    }
    while (!stl_priority_queue.empty()){
        sorted.push_back(stl_priority_queue.top());
        stl_priority_queue.pop();
    }

    stop = std:: chrono :: high_resolution_clock ::now ();
    std::cout  << "STL  priority  queue  time: "<< std:: fixed  << std:: setprecision (2)<< std:: chrono :: duration_cast <std:: chrono :: microseconds >(stop - start). count() / 1000.  << " milliseconds .\n";

    HeapPriorityQueue<int, Comparator<int>> heap_priority_queue;
    sorted.clear();
    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < SAMPLES; i++)
        heap_priority_queue.insert(std::rand() % 1000 + 1);


    while (!heap_priority_queue.empty()) {
        sorted.push_back(heap_priority_queue.min());
        heap_priority_queue.removeMin();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "Heap priority queue sequence sorting took: "
    << std::fixed << std::setprecision(2)
    << std::chrono::duration_cast <std::chrono::microseconds > (stop - start).count() / 1000. << " milliseconds.\n";

    std::vector<int> stl_heap;
    for (int i = 0; i < SAMPLES; i++)
        stl_heap.push_back(std::rand() % 1000 + 1);

    std::make_heap(stl_heap.begin(), stl_heap.end());
    sorted.clear();
    start = std::chrono::high_resolution_clock::now(); // created sorted vector
    while (!stl_heap.empty()) {
        sorted.push_back(stl_heap.front());
        std::pop_heap(stl_heap.begin(), stl_heap.end());
        stl_heap.pop_back();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "std::make_heap from vector sorting took: "
    << std::fixed << std::setprecision(2)
    << std::chrono::duration_cast <std::chrono::microseconds > (stop - start).count() / 1000. << " milliseconds.\n";



    int n = 10000;
    // A std :: pair can be used store the run times
    std::pair<double, double> times;
// a vector of times can be used to store many trials
    std::vector<std::pair<double, double>> trials;
//test inserting in a random BST structure

    BinarySearchTree<int, std::string> bst;
    auto start = std::chrono::high_resolution_clock::now();
    bst.addRoot(std::rand() % n + 1, "a");
    for (int i = 1; i < n; i++)
        bst.insert(std::rand() % n + 1, "a");
    auto stop = std::chrono::high_resolution_clock::now();

    times.first = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
//test inserting in the worst-case BST structure
    BinarySearchTree<int, std::string> bst_inserted_bad;
    start = std::chrono::high_resolution_clock::now();
    bst_inserted_bad.addRoot(0, "a");
    for (int i = 1; i < n; i++) {
        bst_inserted_bad.insert(i, "a");
    }
    stop = std::chrono::high_resolution_clock::now();
    times.second = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count(); // store this trial
    trials.push_back(times);

    for (int i = 0; i < trials.size(); i++){
        std::cout << "Random: "<< trials[i].first << "microseconds ... Linear: " << trials[i].second << "microseconds"<< std::endl;
    }

return 0;
}
