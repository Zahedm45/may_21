#ifndef EX02_LIBRARY_H_
#define EX02_LIBRARY_H_
#include "map"

using namespace std;
struct Elem {
    int value;
    unsigned int times; // Number of repetitions
    Elem *next;
};

void displayRLEList(Elem *list);

Elem* reverse(Elem *list);
Elem* concatenate(Elem *list1, Elem *list2);
int sum(Elem *list);
map<int, int> insert_into_map(Elem *temp, map<int, int> map);

#endif /* EX02_LIBRARY_H_ */
