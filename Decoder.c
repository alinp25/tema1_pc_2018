#include "Decoder.h"

char* decode(char *inputString, char codes[26][5]) {
  int lengthOfString = strlen(inputString);
  char *decoded = (char*)malloc(301);
  char charToString[2];
  int isUpperCase = 0;
  char currentCode[5];

  charToString[1] = '\0';
  strcpy(decoded, "");
  strcpy(currentCode, "");

  // Parcurgerea sirului
  for (int i = 0; i < lengthOfString; i++) {   
    // Verificam daca la indexul curent, caracterul difera fata de ce era 
    // inaintea sa, in caz afirmativ adaugam cifra respectiva codului 
    // curent in sirul decodat
    if (inputString[i] != currentCode[strlen(currentCode) - 1] 
        && strlen(currentCode) > 0) {
      for (int j = 0; j < 26; j++) {
        if (strcmp(currentCode, codes[j]) == 0) {
          charToString[0] = (char)('a' + j);
          if (isUpperCase) {
            charToString[0] -= 32;
            isUpperCase = 0;
          }
          strcat(decoded, charToString);
          strcpy(currentCode, "");
        }
      }  
    }
    // Daca cifra este '0' adaugam spatiu
    if (inputString[i] == '0') {
      charToString[0] = ' ';
      strcat(decoded, charToString);
      continue;
    }
    // Daca cifra este 1 actualizam optiunea pentru urmatorul set
    if (inputString[i] == '1') {
      isUpperCase = 1;
      strcpy(currentCode, "");
      continue;
    }
    // Daca intalnim '#' resetam codul curent
    if (inputString[i] == '#') {
      strcpy(currentCode, "");
      continue;
    }
    // Daca niciuna din cele 3 conditii de mai sus nu e indeplinita,
    // Adaugam caracterul la codul curent
    charToString[0] = inputString[i];
    strcat(currentCode, charToString);
  }
  return decoded;
}