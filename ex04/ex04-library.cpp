#include "ex04-library.h"


// Task 4(a).  Write a placeholder implementation of FilteringBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and occupancy()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of reset()

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}

FilteringBuffer::FilteringBuffer(int a) {
    this->default_val = a;
}

void FilteringBuffer::write(int v) {

    if (std::count(all_list.begin(), all_list.end(), v)) {

    } else {
        fifo.push_back(v);
        all_list.push_back(v);
        buf_occu++;
    }


}

int FilteringBuffer::read() {

    if (fifo.empty()) return default_val;

    int val = fifo[0];
    fifo.erase(fifo.begin());
    buf_occu--;

    return val;
}

unsigned int FilteringBuffer::occupancy() {
    return buf_occu;
}

void FilteringBuffer::reset() {
    fifo.clear();
    all_list.clear();
    buf_occu = 0;

}

