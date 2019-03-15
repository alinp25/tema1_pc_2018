#include "AutoCorrecter.h"

char *autoCorrectText(char *str, DictEntry *dictionary, int numberOfWords,
                      char codes[26][5]) {
  char *p, *finalString;
  // Aloca memorie pentru sirul de caractere dupa corectare
  finalString = (char*)malloc(701);
  strcpy(finalString, "");
  int replaced = 0;
  // Parcurge fiecare cuvant din text
  p = strtok(str, " ");
  while (p != NULL) {
    replaced = 0;
    // La intalnirea acestui cuvant in dictionar, printre cuvintele gresite
    // adauga la sirul final acel cuvant corect ce ii corespunde, urmat de 
    // spatiu; in caz contrar adauga la sirul final cuvantul respectiv. 
    for (int i = 0; i < numberOfWords; i++) {
      if (strcmp(dictionary[i].wrongWord, p) == 0) {
        strcat(finalString, dictionary[i].correctWord);
        strcat(finalString, " ");
        replaced = 1;
        break;
      }
    }
    if (replaced == 0) {
      strcat(finalString, p);
      strcat(finalString, " ");
    }
    p = strtok(NULL, " ");
  }
  // Elimina spatiul adaugat in urma adaugarii ultimului cuvant in sir
  finalString[strlen(finalString) - 1] = '\0';
  // Returneaza sirul final
  return encode(finalString, codes);
}
