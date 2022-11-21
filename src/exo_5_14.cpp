//
// Created by ValentinRicard on 08.11.2022.
//

#include <cstdlib>
#include <iostream>

using namespace std;

bool contient(const int tableau[], size_t longueur, int valeur) {
  for (size_t i = 0; i < longueur; ++i) {
    if (tableau[i] == valeur) {
      return true;
    }
  }
  return false;
}

bool contientTout(const int tableau1[], size_t longueur1, const int tableau2[],
                  size_t longueur2) {
  for (size_t i = 0; i < longueur1; ++i) {
    if (!contient(tableau2, longueur2, tableau1[i])) {
      return false;
    }
  }
  return true;
}

bool tableauxEgaux(const int tableau1[], size_t longueur1, const int tableau2[],
                   size_t longueur2) {
  return contientTout(tableau1, longueur1, tableau2, longueur2) &&
         contientTout(tableau2, longueur2, tableau1, longueur1);
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
  int t1[] = {0, 9, 2, 5, 5, 5, 6, 6, 8, 9};
  size_t t1_length = sizeof(t1) / sizeof(t1[0]);

  int t2[] = {0, 9, 3, 5, 5, 5, 6, 6, 8};
  size_t t2_length = sizeof(t2) / sizeof(t2[0]);

  int t3[] = {0, 9, 2, 5, 6, 8};
  size_t t3_length = sizeof(t3) / sizeof(t3[0]);

  cout << boolalpha << tableauxEgaux(t1, t1_length, t2, t2_length) << endl
       << tableauxEgaux(t1, t1_length, t3, t3_length);
}