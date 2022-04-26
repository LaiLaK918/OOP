#include "BubbleSort.h"

BubbleSort::BubbleSort() {

}

BubbleSort::BubbleSort(int nn) {
    n = nn;
    arr = new int[n];
}

BubbleSort::~BubbleSort() {

}

void BubbleSort::Sorted() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) _swap(arr[j], arr[j - 1]);
        }
    }
}