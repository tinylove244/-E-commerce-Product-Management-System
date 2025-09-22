#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// template class
template <typename T>

class InventoryList{
private:
    vector <T> items;
public:
    //method: add a item to list 
    void addItem(const T& item){
         items.push_back(item);
    }
    //method: remove item from list
    void removeItem(const T& item){
        auto it = find(items.begin(), items.end(), item);
    if (it != items.end()){
        items.erase(it);
    }
    else {
        cout << "Item not found in the list." << endl;
    
}

    }
    //method: find intem in List
    T* findItem(const T& item){
        auto it = find(items.begin(), items.end(), item);
    if (it != items.end()){
        return &(*it);
    }
    else {
        cout << "Item not found in the list." << endl;
        return nullptr;
    }
    }
    //method: print all item in list
    void printAll(){
        for (const auto& item : items){
        item->printInformation();
        cout << endl;
    }
    }
};