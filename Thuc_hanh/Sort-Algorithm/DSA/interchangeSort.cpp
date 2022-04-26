#include "interchangeSort.h"

interchangeSort::interchangeSort() {

}

interchangeSort::interchangeSort(int nn) {
    n = nn;
    arr = new int[n];
}

interchangeSort::~interchangeSort() {

}

void interchangeSort::Sorted() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) _swap(arr[i], arr[j]);
        }
    }
}