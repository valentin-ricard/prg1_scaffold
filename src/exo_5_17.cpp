//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

vector<int> merge(const vector<int> &vec1, const vector<int> &vec2) {
    vector<int> result;
    result.reserve(vec1.size() + vec2.size());
    vector<int>::const_iterator vec1Iter = vec1.cbegin();
    vector<int>::const_iterator vec2Iter = vec2.cbegin();

    int count = 0;
    while (vec1Iter != vec1.cend() && vec2Iter != vec2.cend()) {
        // USe the count to know which one to use
        if (count % 2 == 0) {
            result.push_back(*vec1Iter);
            ++vec1Iter;
        } else {
            result.push_back(*vec2Iter);
            ++vec2Iter;
        }
        ++count;
    }

    if (vec1Iter == vec1.cend()) {
        // Add the rest of the vector 2 and end
        result.insert(result.end(), vec2Iter, vec2.cend());
    } else {
        result.insert(result.end(), vec1Iter, vec1.cend());
    }

    return result;
}

ostream& operator<< (ostream& os, const vector<int>& v) {
    os << "[";
    for (size_t i=0; i<v.size(); ++i) {
        if (i)
            os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

void afficherTableau(const int tableau[], size_t longueur) {
    cout << "[";
    for (size_t i = 0; i < longueur; ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << tableau[i];
    }
    cout << "]" << endl;
}

int main() {
    vector<int> vec1 = {1,1,1,1,1};
    vector<int> vec2 = {2,2,2,2,2,2,2,2};
    vector<int> result = merge(vec1, vec2);
    cout << "t1: " << result;
}