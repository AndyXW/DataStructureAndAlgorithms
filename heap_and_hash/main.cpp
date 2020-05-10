#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include "MinHeap.h"

#define HASH_M 101
#define KEY_LENGTH 300
#define NUMBER 31

using namespace std;

int ModuleHash(string key) {
    unsigned long sum;
    int a[3], k, i, nCHN = key.length()/3;
    k = 0;
    for (k=0; k<nCHN; k++){ 
        for(i=0; i<3; i++) a[i] = static_cast<unsigned char>(key[3*k+i]); 
        sum += a[0]*65536 + a[1]*256 + a[2];
    }
    return sum % HASH_M;  
}

int Probe(unsigned int hashTab[], vector<string>& keyTab, string key) {
    int h, h_org = h = ModuleHash(key);
    if (!hashTab[h]) {
        keyTab[h] = key;
        hashTab[h] = h + 1;
        return h;
    }
    if (keyTab[h] == key)
        return 9999;
    
    while (true) {
        h += 3;
        h %= HASH_M;
        if (!hashTab[h]) {
            keyTab[h] = key;
            hashTab[h] = h + 1;
            return h;
        }
        else if (keyTab[h] == key) {
            return 9999;
        }
        else if (h == h_org) {
            cout << "No free slot\n";
            break;
        }
    }
    return 0;
}

template <typename Elem, typename Comp>
bool checkHeap(Elem* heap, int index, int max) {
    if (2*index+2 <= max) {  
        if (Comp::gt(heap[index], heap[2*index+1]) || Comp::gt(heap[index], heap[2*index+2])){
            return false;
        }
        if (checkHeap<Elem, Comp>(heap, 2*index+1, max) && checkHeap<Elem, Comp>(heap, 2*index+2, max)) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main() {
    string key;
    static unsigned int hashTab[HASH_M];
    vector<string> keyTab(HASH_M, "\0");
    MinHeap<unsigned int, IntCompare> valueheap(NUMBER, NUMBER);
    MinHeap<unsigned int, IntCompare> allheap(0, HASH_M);

    ofstream output("Baptiste_Lines.txt");
    ofstream mycout("heapALL.dat");

    // output the 31 largest hash value lines
    int k = 1;
    while (getline(cin, key)) {
        int value = Probe(hashTab, keyTab, key);

        unsigned min;
        if (value != 9999) {
            allheap.insert(value);
        }

        if (value != 9999 && value > *valueheap.lines()) {
            valueheap.removemax(min);
            valueheap.insert(value);
        }
        if (k % 300 == 0) {
            output << "The " << k << "th line:\n";
            for (int i=0; i<NUMBER; ++i) {
                output << "hash value: " << valueheap.lines()[i] << "\t";
                output << keyTab[valueheap.lines()[i]] << endl;
            }
            output << endl;
        }
        k++;
    }
    output.close();

    // output heapALL.dat
    bool count = true;
    for (int i=0; i<=HASH_M; ++i) {
        if (allheap.lines()[i] > 0 || count) {
            if (allheap.lines()[i] == 0)
                count = false;
            mycout << "hash value: " << allheap.lines()[i] << "\t";
            mycout << keyTab[allheap.lines()[i]] << endl;
        }
    }
    mycout.close();

   return 0;
}