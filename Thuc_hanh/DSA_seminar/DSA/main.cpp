#include "Train.h"
#include <string>

int howManyWagons(Train train) {
    bool first = train.isLightOnInCurrentWagon();
    for (int i = 1;; i++) {
        train.goToNextWagon();
        if (train.isLightOnInCurrentWagon() == first) {
            train.switchLight();
            for (int j = 0; j < i; j++) train.goToPreviousWagon();
            if (train.isLightOnInCurrentWagon() != first) {
                train.switchLight();
                return i;
            }
            for (int j = 0; j < i; j++) train.goToNextWagon();
            train.switchLight();
        }
    }
}

string gen_random_test() {
    int len = 1+rand() % 22;
    string test;
    for (int i = 0; i < len; i++) {
        test += to_string(rand() % 2);
        test += ":";
    }
    test.pop_back();
    return test;
}

int main() {
    int num_test = 100000;
    string* test = new string[num_test];
    for (int i = 0; i < num_test; i++) {
        test[i] = gen_random_test();
        cout << test[i] << endl;
        Train t(test[i]);
        cout << howManyWagons(t);
        cout << "\n\n";
    }
	return 0;
}