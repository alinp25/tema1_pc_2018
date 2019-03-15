#include "Encoder.h"

char* encode(char* inputString, char codes[26][5]) {
  int lengthOfString = strlen(inputString);
  char* encoded = (char*)malloc(301);
  strcpy(encoded, "");
  // Pastreaza codificarile literelor intr-un array de string-uri
  for (int i = 0; i < lengthOfString; i++) {
    // Verificare pentru tasta spatiu
    if (inputString[i] == ' ') {
      strcat(encoded, "0");
      continue;
    }
    // Verificare daca litera este mare, in caz afirmativ adaugam numarul
    // 1, specific, dupa care transformam litera in mica
    if (isUpperCaseLetter(inputString[i])) {
      strcat(encoded, "1");
      inputString[i] = (char)(inputString[i] + 32);
    }
    // Verificare daca 2 litere sunt formate prin apasarea unei singure taste,
    // caz in care vor fi formate din aceeasi cifra, necesara fiind separarea
    // acestora
    if (codes[inputString[i] - 'a'][0] == encoded[strlen(encoded) - 1]) {
      strcat(encoded, "#");
    }
    // Adaugarea codificarii cifrei
    strcat(encoded, codes[inputString[i] - 'a']);
  }
  return encoded;
}
