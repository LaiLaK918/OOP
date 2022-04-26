#include "MergeSort.h"

MergeSort::MergeSort() {

}

MergeSort::MergeSort(int nn) {
    n = nn;
    arr = new int[n];
}

MergeSort::~MergeSort() {

}

void MergeSort::Merge(int left, int mid, int right) {
    int subArrOne = mid - left + 1, subArrTwo = right - mid;
    int* leftArr = new int[subArrOne], * rightArr = new int[subArrTwo];
    for (int i = 0; i < subArrOne; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < subArrTwo; i++) rightArr[i] = arr[mid + 1 + i];
    int indexOfLeftArr = 0, indexOfRightArr = 0, indexOfMergedArr = left;
    while (indexOfLeftArr < subArrOne || indexOfRightArr < subArrTwo) {
        if ((indexOfLeftArr < subArrOne && indexOfRightArr < subArrTwo && leftArr[indexOfLeftArr] < rightArr[indexOfRightArr]) ||
            indexOfRightArr >= subArrTwo) arr[indexOfMergedArr++] = leftArr[indexOfLeftArr++];
        else arr[indexOfMergedArr++] = rightArr[indexOfRightArr++];

    }
    delete[] leftArr;
    delete[] rightArr;
}

void MergeSort::mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        Merge(left, mid, right);
    }
}

void MergeSort::Sorted() {
    mergeSort(0, n - 1);
}