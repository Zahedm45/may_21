#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
GroceryList::GroceryList() {
    this->items.push_back("Lasagne");
    this->itemsInfo["Lasagne"] = {1, "With eggs if available"};

    this->items.push_back("Salmon");
    this->itemsInfo["Salmon"] = {500, "Smoked if available"};

    this->items.push_back("Spinach");
    this->itemsInfo["Spinach"] = {300, "Fresh"};

    this->items.push_back("Dessert");
    this->itemsInfo["Dessert"] = {8, "Maybe lagkage?"};
}

// Task 3(a).  Implement this method
void GroceryList::add(string name, unsigned int quantity, string notes) {
    // Write your code here

    if (std::count(items.begin(), items.end(), name)) {

        itemsInfo[name].quantity += quantity;
        itemsInfo[name].notes += ";" + notes;

    } else {

        items.push_back(name);

        Info info = {quantity, notes};
        itemsInfo[name] = info;
    }


}

// Task 3(b).  Implement this method
bool GroceryList::remove(string name, unsigned int quantity) {
    // Write your code here


    if (itemsInfo.count(name)) {

        if (itemsInfo[name].quantity < quantity) return false;


        itemsInfo[name].quantity -= quantity;

        if (itemsInfo[name].quantity == 0) {
            itemsInfo.erase(name);

            int counter = 0;
            for (const auto &item : items){
                if (item == name) break;
                counter++;
            }
            items.erase(items.begin() + counter);
        }
        return true;


    }
    return false;

}

// Task 3(c).  Implement this method
bool GroceryList::copyEntry(string name, string newName) {
    // Write your code here

    if (std::count(items.begin(), items.end(), name)) {

        if (std::count(items.begin(), items.end(), newName)) {
            return false;
        }


        items.push_back(newName);

        itemsInfo[newName].quantity = itemsInfo[name].quantity;
        itemsInfo[newName].notes = itemsInfo[name].notes;
        return true;

    }

    return false;

}

// Do not modify
void GroceryList::display() {
    // Write your code here
    for (auto it = this->items.begin(); it != this->items.end(); it++) {
        Info &item = this->itemsInfo[*it];
        cout << "name='" << *it << "'; ";
        cout << "quantity=" << item.quantity << "; ";
        cout << "notes='" << item.notes << "'" << endl;
    }
}