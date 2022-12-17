#include <iostream>
#include "ex02-library.h"
#include "map"
using namespace std;

// Task 2(a).  Implement this function
Elem* reverse(Elem *list) {
    Elem *temp = list;
    Elem *reverse_list = nullptr;

    while (temp != nullptr) {
        Elem *new_n = new Elem();
        new_n->times = temp->times;
        new_n->value = temp->value;
        if (reverse_list == nullptr) {
            new_n->next = nullptr;
        } else {
            new_n->next = reverse_list;
        }

        reverse_list = new_n;
        temp = temp->next;
    }


    return reverse_list;
}

// Task 2(b).  Implement this function
Elem* concatenate(Elem *list1, Elem *list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

/*    Elem *temp2 = list2;
    while (temp2 != nullptr) {

        Elem *temp = list1;

        while (temp != nullptr) {
            if (temp->value == temp2->value) {

                temp->times += temp2->times;
                temp2->times = 0;
            }
            temp = temp->next;
        }

        temp2 = temp2->next;
    }



    Elem *temp = list1;
    while (temp->next != nullptr) temp = temp->next;

    Elem *trav = list2;
    while (trav != nullptr) {
        if (trav->times != 0) {

            Elem *new_n = new Elem();
            new_n->value = trav->value;
            new_n->times = trav->times;
            new_n->next = nullptr;

            temp->next = new_n;
            temp = temp->next;
        }

        trav = trav->next;
    }*/

    Elem *temp = list1;
    while (temp->next != nullptr) temp = temp->next;

    if (temp->value == list2->value) {
        temp->times += list2->times;
        temp->next = list2->next;

    } else temp->next = list2;


    return list1;
}




// Task 2(c).  Implement this function
int sum(Elem *list) {

    Elem *temp = list;
    int total = 0;

    while (temp != nullptr) {

        total += temp->value * temp->times;
        temp = temp->next;
    }

    return total;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}

map<int, int> insert_into_map(Elem *temp, map<int, int> map) {
    while (temp != nullptr) {

        if (map.find(temp->value) == map.end()) {
            map[temp->value] = temp->times;

        } else  {
            map[temp->value] = map[temp->value] + temp->times;
        }

        temp = temp->next;
    }

    return map;
}