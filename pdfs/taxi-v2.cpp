//---------------------------------------------------------
// Fichier        : LaboTaxi.cpp
// Auteur(s)      :
//                  v1 -> Philibert Alexandre, Villegas Castrillon Adrian
//                  v2 -> Valentin Ricard, Ewan Mariaux
// Date           : 2021-10-02
// But            : Un programme qui calcule le prix d'une course en € en taxi
// Modifications  :
// Remarque(s)    : Le programme ne gère pas les saisies
//---------------------------------------------------------

#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>  // cin et cout
#include <iomanip>   // setprecision
#include <limits>    // numeric_limits<streamsize>
#include <cmath>     // ceil(...) et max()

/// Affiche une date, en forcant la taille à 2, et en rajoutant des 0 si nécessaire.
#define FORMAT_DATE setw(2) << setfill('0')

/// Définir le format de nombres pour l'affichage, en forcant la taille à 6
#define FORMAT_NOMBRE setw(6) << setfill(' ')

/// Vider le buffer (on recoit un retour à la ligne)
#define VIDER_BUF cin.ignore(numeric_limits<streamsize>::max(), '\n')

/// Affiche et attend l'interaction de l'utilisateur pour arrêter le programme.
#define FINIR cout << "presser ENTREE pour quitter"; VIDER_BUF; return EXIT_SUCCESS

using namespace std;

// rajout des f pour préciser que ce sont des float car manquant sur le programme initial.
const float PRISE_EN_CHARGE = 5.00f;
const float SUPPLEMENT_PAR_BAGAGE = 2.50f;
const float TARIF_MINUTE_JOUR = 1.0f;
const float TARIF_MINUTE_NUIT = 1.6f;

const int HEURE_DEBUT_JOUR = 8;
const int MINUTE_DEBUT_JOUR = 0;
const int DEBUT_JOUR_EN_MINUTES = HEURE_DEBUT_JOUR * 60 + MINUTE_DEBUT_JOUR;

const int HEURE_FIN_JOUR = 20;
const int MINUTE_FIN_JOUR = 0;
const int FIN_JOUR_EN_MINUTES = HEURE_FIN_JOUR * 60 + MINUTE_FIN_JOUR;

int main() {

    float distanceKm,
            vitesseKmH,
            supplementBagages,
            prixCourseJournee,  // prix des heures durant le jour
            prixCourseNuit,     // prix des heures durant la nuit.
            prixTotal;

    int heureDepart,
            minutesDepart,
            tempsCourse,
            nombreBagages; // Il n'est pas possible d'avoir 1/2 bagage, ils sont représentés par un entier


    // On initialise cette variable, car la course peut ne pas passer par les chemins candides.
    int tempsCourseMatin = 0,
            tempsCourseTarifJournee,
            tempsCourseSoir = 0,
            tempsCourseTarifNuit,
            departEnMinutes,
            ecartArriveeSoir,
            ecartDepartMatin;



    // définit la précision d'affichage des nombres à virgules (exemple: 2.50)
    cout << fixed << setprecision(2);

    cout << "bonjour, ce programme calcule le prix d'une course en € en taxi"
         << "voici les conditions" << endl
         << "===============================================================" << endl
         << " - prise en charge     : " << FORMAT_NOMBRE << PRISE_EN_CHARGE << endl
         << " - supp par bagage     : " << FORMAT_NOMBRE << SUPPLEMENT_PAR_BAGAGE << endl
         // Modification des constantes pour refléter le changement dans les besoins
         << " - tarif/minute (jour) : " << FORMAT_NOMBRE << TARIF_MINUTE_JOUR << endl
         << " - tarif/minute (nuit) : " << FORMAT_NOMBRE << TARIF_MINUTE_NUIT << endl
         << " - tarif jour          : "
         << HEURE_DEBUT_JOUR << "h" << FORMAT_DATE << MINUTE_DEBUT_JOUR
         << "-"
         << HEURE_FIN_JOUR << "h" << FORMAT_DATE << MINUTE_FIN_JOUR
         << endl;

    cout << "votre commande" << endl
         << "==============" << endl;

    cout << " - nbre de bagage    [0-4]: ";

    cin >> nombreBagages;
    // Changement du vider de buffer explicite à la macro pour faciliter la maintenance
    VIDER_BUF;
    // Rajout d'une vérification
    if (nombreBagages < 0 || nombreBagages > 4) {
        cout << "Le nombre de bagages n'est pas valide." << endl;
        FINIR;
    }

    cout << " - distance [km]   [0-500]: ";
    cin >> distanceKm;
    VIDER_BUF;
    if (distanceKm < 0 || distanceKm > 500) {
        cout << "La distance n'est pas valide." << endl;
        FINIR;
    }

    cout << " - vitesse [km/h] [30-120]: ";

    cin >> vitesseKmH;
    VIDER_BUF;
    if (vitesseKmH < 30 || vitesseKmH > 120) {
        cout << "La vitesse n'est pas valide." << endl;
        FINIR;
    }

    cout << " - depart          [hh:mm]: ";
    cin >> heureDepart;
    cin.ignore(numeric_limits<streamsize>::max(), ':');
    cin >> minutesDepart;

    if (heureDepart < 0 || heureDepart > 23
        || minutesDepart < 0 || minutesDepart > 60) {
        cout << "L'heure de départ n'est pas valide." << endl;
        FINIR;
    }

    VIDER_BUF;

    // Calculs
    departEnMinutes = heureDepart * 60 + minutesDepart;
    // Séparation du temps de course avec le prix de la course pour les opérations suivantes
    tempsCourse = (int) ceil(distanceKm / vitesseKmH * 60);


    ecartDepartMatin = DEBUT_JOUR_EN_MINUTES - departEnMinutes;
    if (ecartDepartMatin > 0) {
        // On utilise max pour ne pas dépasser le temps de course
        tempsCourseMatin = min(tempsCourse, ecartDepartMatin);
    }

    ecartArriveeSoir = (departEnMinutes + tempsCourse) - FIN_JOUR_EN_MINUTES;
    if (ecartArriveeSoir > 0) {
        tempsCourseSoir = min(tempsCourse - tempsCourseMatin, ecartArriveeSoir);
    }

    tempsCourseTarifNuit = tempsCourseMatin + tempsCourseSoir;
    tempsCourseTarifJournee = tempsCourse - tempsCourseTarifNuit;


    prixCourseJournee = (float) tempsCourseTarifJournee * TARIF_MINUTE_JOUR;
    prixCourseNuit = (float) tempsCourseTarifNuit * TARIF_MINUTE_NUIT;

    // Modification du supplément bagage pou enlever un warning de compilation
    supplementBagages = SUPPLEMENT_PAR_BAGAGE * (float) nombreBagages;

    prixTotal = PRISE_EN_CHARGE + supplementBagages + prixCourseJournee + prixCourseNuit;

    cout << endl
         << "votre ticket" << endl
         << "============" << endl
         << " - prise en charge   : " << FORMAT_NOMBRE << PRISE_EN_CHARGE << endl
         << " - supp bagages      : " << FORMAT_NOMBRE << supplementBagages << endl
         << " - temps course" << endl

         << FORMAT_NOMBRE << tempsCourseTarifJournee << "' @ 1.00    : " << FORMAT_NOMBRE << prixCourseJournee << endl
         << FORMAT_NOMBRE << tempsCourseTarifNuit << "' @ 1.60    : " << FORMAT_NOMBRE << prixCourseNuit << endl

         << "--------------------------------------" << endl
         << "TOTAL : " << prixTotal << endl;

    FINIR;
}