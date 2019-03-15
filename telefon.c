#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Encoder.h"
#include "Utils.h"
#include "Decoder.h"
#include "AutoCorrecter.h"
// #include "PerfectMessage.h"

int main() {
  char codes[26][5] = {"2", "22", "222", "3", "33", "333", "4", "44", "444",
    "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88",
    "888", "9", "99", "999", "9999"};
  // CERINTA 1
  char *textToEncode = (char*)malloc(101);
  //scanf("%[^\n]s", textToEncode);
  fgets(textToEncode, 101, stdin);
  char *sol1 = encode(textToEncode, codes);
  printf("%s\n", sol1);
  free(textToEncode);
  free(sol1);

  // CERINTA 2
  char *textToDecode = (char*)malloc(301);
  fgets(textToDecode, 301, stdin);
  char *sol2 = decode(textToDecode, codes);
  printf("%s\n", sol2);
  free(textToDecode);
  free(sol2);

  // CERINTA 3
  char *textToCorrect = (char*)malloc(301);
  int numberOfWordsToReplace = 0;
  fgets(textToCorrect, 301, stdin);
  if (textToCorrect[strlen(textToCorrect) - 1] == '\n') {
    textToCorrect[strlen(textToCorrect) - 1] = '\0';
  }
  scanf("%d", &numberOfWordsToReplace);
  DictEntry *dictionary = (DictEntry*)malloc(numberOfWordsToReplace); 
  for (int i = 0; i < numberOfWordsToReplace; i++) {
    scanf("%s %s", dictionary[i].wrongWord, dictionary[i].correctWord);
  }
  char *sol3Corrected = autoCorrectText(textToCorrect, dictionary, 
                                        numberOfWordsToReplace, codes);
  // char *sol3 = encode(sol3Corrected, codes);
  printf("%s\n", sol3Corrected);
  free(dictionary);
  free(textToCorrect);
  free(sol3Corrected);
  // free(sol3);

  // getchar();

  // // CERINTA 4
  // char *textToPerfect = (char*)malloc(301);
  // (void*)fgets(textToPerfect, 301, stdin);
  // char *encodedToWork = encode(textToPerfect, codes);
  // int numberOfComponents = countComponents(encodedToWork);
  // printf("%d\n", numberOfComponents);
  // printComponents(encodedToWork, numberOfComponents);
  // perfectMessage(encodedToWork);
  // free(textToPerfect);
  // free(encodedToWork);
  return 0;
}


