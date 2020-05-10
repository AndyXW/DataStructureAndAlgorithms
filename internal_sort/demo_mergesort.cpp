
#include <string>
#include <iostream>

#include "Compare.h"
#include "InternalSorting.h"

template <class Elem>
void printA(Elem A[], int n){
    for (int i = 0; i < n; ++i) 
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    string master[] = {"XieXun", "TaoGuLiuXian", "XiaoLongNv", 
                       "HuangShang", "SaoDiSeng", "ZhangSanFeng",
                       "XuZu", "ZhangWuJi", "WuYaZi"};
    string a_string [50];
    int n_string = 9;

    // check the input is right or not
    for (int i = 0; i < n_string; ++i) {
        if (master_level[master[i]] == 0) {
            cout << "Input is not valid, please check again\n";
            return 0;
        }
    }

    cout << "A set of masters: ";
    printA(master, n_string);
    MergeSort<string, MasterCompare>(master, a_string, 0, n_string-1);
    cout << "After Quicksort: ";
    printA(master, n_string);


    return 0;
}