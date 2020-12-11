#include "esphome.h"

class MyTeleinfo : public Component, public UARTDevice {
 public:
  MyTeleinfo(UARTComponent *parent) : UARTDevice(parent) {}

  void setup() override {
    // nothing to do here
  }

  // Lecture de la trame
  // On attend de voir passer un caractère ETX (\x03) suivi d'un STX (\x02)
  // On récupère tout jusqu'au prochain ETX (\x03)

  // Decodage de la trame
  // En entrée nous avons une trame qui sera découpée en groupe d'informations
  // La découpe se fera via le caractère CR (\x15)
  // Pour chaque groupe d'informations, on valide le groupe
    // Si le groupe d'informations est valide, on retourne le libellé et la valeur

  // Validation du groupe d'informations
    // On calcul le checksum du groupe d'information
    // Si le checksum est valide
      // On découpe le groupe d'informations vie le caractère SP (\x20)
      // on retourne le libellé (1er champ) et la valeur (2ème champ)
    // Sinon, on retourne une erreur

  // Calcul du checkSum
    // En entrée nous avons le groupe d'informations brut
    // Pour chaque caractère de la chaine, on récupère la valeur décimale de ce caractère
      // On incrémente une somme
    // Cette somme est tronquée sur 6 bits (cette opération est faite à l’aide d’un ET logique avec 63)
    // On additionne au résultat précédent 32
    // On récupère le caractère ASCII ayant cette valeur décimale
    // On compare ce caractère avec le checksum (dernier caractère du groupe d'informations)
      // Si les 2 caractères sont égaux
        // On retourne vrai
      // Sinon, on retourne faux

/* commentaires de bernard :
sur Arduino, on peut faire du C++ (cf. String) ou du C. Pour des raisons de mémoire linitée, il vaut mieux faire le maximum de choses en C.
Le problème est pour les chaînes de caractères : en C ce sont juste des tableaux de char, et il vaut mieux souvent définir une taille max.
Donc la première chose à faire c'est de décider quelle sera la taille max de la trame (1024 caractères ? 4096 ? plus ?). Pareil pour
les différents composants de la trame : définir des tailles max en nb de caractères pour avoir un tableau de cette taille et le réutiliser
(on peut être plus rusé et traiter directement des sous-chaînes de caractères dans le tableau, mais c'est moins propre car il faut alors mettre
des terminateurs de chaine de caractère '\0' dans le tableau.
En effet, en C, les chaines de caractère sont juste définies par l'adresse du début, et elles continues jusqu' au caractère '\0'.

L'origine des données de la trame n'est pas très claire : readString() ? le read() dans la boucle ?
*/
Ce n'est pas très clair d'où
  void loop() override {
    // Use Arduino API to read data, for example
    String line = readString();
    int i = parseInt();
    while (available()) {
      char c = read();
    }
    // etc
  }
};
