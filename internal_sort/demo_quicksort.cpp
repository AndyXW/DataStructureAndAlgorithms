
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
                       "XuZu", "ZhangWuJi"};
    int n_string = 8;

    string a_string [50];

    for (int i = 0; i < n_string; ++i) {
        if (master_level[master[i]] == 0) {
            cout << "Input is not valid, please check again\n";
            return 0;
        }
    }

    for (int i = 0; i < n_string; ++i){ a_string[i] = master[i];}
    cout << "A set of masters: ";
    printA(a_string, n_string);
    QuickSort<string, MasterCompare>(a_string, 0, n_string-1);
    cout << "After Quicksort: ";
    printA(a_string, n_string);




    return 0;
}