//---------------------------------------------------------
// Demo           : example
// Classe         : PRG1_E
// Fichier        : repas.cpp
// Auteur(s)      : ValentinRicard & TiagoDeOliveiraJorge
// But            : Commande de repas dans un restaurant
// Modifications  :
// Remarque(s)    : NILL
//---------------------------------------------------------

#include <iostream>  // cout & cin
#include <cstdlib>   // EXIT_SUCCESS
#include <limits>    // numeric_limits<streamsize>
#include <iomanip>   // setw(...) et setprecision(...)

#define FMT_NUMBER setw(7)
#define CLEAR_BUF cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define END cout << "presser ENTREE pour quitter"; CLEAR_BUF; return EXIT_SUCCESS

using namespace std; // Removes the need to use std:: before every call

// Constant variables declaration
const float ENTRY_PRICE = 4.30f;
const float MAIN_DISH_PRICE = 12.50f;
const float BEVERAGE_PRICE = 3.00f;
const float DESERT_PRICE = 6.00f;
const float COFFEE_PRICE = 2.80f;


int main() {
    //==================//
    //      GREET       //
    //==================//
    cout << "bonjour, ce programme..." << endl
         << "voici le prix des éléments" << endl
         << "==========================" << endl;


    //======================//
    //  DISPLAY CONDITIONS  //
    //======================//
    // Note: We set the display to limit the precision to 2 decimal places
    cout << fixed << setprecision(2)
         << " - entree  : " << FMT_NUMBER << ENTRY_PRICE << endl
         << " - plat    : " << FMT_NUMBER << MAIN_DISH_PRICE << endl
         << " - boisson : " << FMT_NUMBER << BEVERAGE_PRICE << endl
         << " - dessert : " << FMT_NUMBER << DESERT_PRICE << endl
         << " - cafe    : " << FMT_NUMBER << COFFEE_PRICE << endl
         << "NB: limite de saisie [0-10]";

    //==================//
    //      INPUT       //
    //==================//
    cout << endl << endl
         << "votre commande" << endl
         << "==============" << endl;

    int entryCount;
    cout << " - nbre de entree :";
    cin >> entryCount;
    CLEAR_BUF;
    // Validate the entry count
    if (entryCount < 0 || entryCount > 10) {
        cout << "Entrée invalide ! Merci de relancer le programme." << endl;
        END;
    }


    int mainDishCount;
    cout << " - nbre de plat    :";
    cin >> mainDishCount;
    CLEAR_BUF;
    // Validate the main dish count
    if (mainDishCount < 0 || mainDishCount > 10) {
        cout << "Entrée invalide ! Merci de relancer le programme." << endl;
        END;
    }


    int beverageCount;
    cout << " - nbre de boisson :";
    cin >> beverageCount;
    CLEAR_BUF;
    // Validate the beverage count
    if (beverageCount < 0 || beverageCount > 10) {
        cout << "Entrée invalide ! Merci de relancer le programme." << endl;
        END;
    }


    int desertCount;
    cout << " - nbre de dessert :";
    cin >> desertCount;
    CLEAR_BUF;
    // Validate the desert count
    if (desertCount < 0 || desertCount > 10) {
        cout << "Entrée invalide ! Merci de relancer le programme." << endl;
        END;
    }

    int coffeeCount;
    cout << " - nbre de cafe    :";
    cin >> coffeeCount;
    CLEAR_BUF;

    if (coffeeCount < 0 || coffeeCount > 10) {
        cout << "Entrée invalide ! Merci de relancer le programme." << endl;
        END;
    }

    //==================//
    //     PROCESS      //
    //==================//
    float entryTotalPrice = (float) entryCount * ENTRY_PRICE;
    float mainDishTotalPrice = (float) mainDishCount * MAIN_DISH_PRICE;
    float beverageTotalPrice = (float) beverageCount * BEVERAGE_PRICE;
    float desertTotalPrice = (float) desertCount * DESERT_PRICE;
    float coffeeTotalPrice = (float) coffeeCount * COFFEE_PRICE;

    float total = entryTotalPrice
                  + mainDishTotalPrice
                  + beverageTotalPrice
                  + desertTotalPrice
                  + coffeeTotalPrice;

    //==================//
    //      OUTPUT      //
    //==================//

    cout << "votre ticket" << endl << "============" << endl
         << "- " << entryCount << " entrees  :" << FMT_NUMBER << entryTotalPrice << endl
         << "- " << mainDishCount << " plats    :" << FMT_NUMBER << mainDishTotalPrice << endl
         << "- " << beverageCount << " boissons :" << FMT_NUMBER << beverageTotalPrice << endl
         << "- " << desertCount << " desserts :" << FMT_NUMBER << desertTotalPrice << endl
         << "- " << coffeeCount << " cafes    :" << FMT_NUMBER << coffeeTotalPrice << endl
         << "-      total :" << FMT_NUMBER << total << endl
         << "merci de votre visite" << endl << endl;


    END;
}