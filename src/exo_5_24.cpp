//
// Created by ValentinRicard on 08.11.2022.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &tableau) {
    for (const T &value: tableau) {
        cout << value << " ";
    }
    return os;
}

vector<int> concat(vector<int> vec1, vector<int> vec2) {
    vector<int> result = {};
    result.resize(vec1.size() + vec2.size());
    auto end_first = copy(vec1.begin(), vec1.end(), result.begin());
    copy(vec2.begin(), vec2.end(), end_first);
    return result;
}


int main() {
    vector<int> tableau1 = {1, 3, 5, 7, 11};
    vector<int> tableau2 = {1, 3, 5, 7, 12};

    cout << boolalpha << "t1: " << tableau1 << ", t2: " << tableau2 << endl;
    cout << "result: " << concat(tableau1, tableau2);
}