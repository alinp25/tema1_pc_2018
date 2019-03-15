#include <stdlib.h>
#include <string.h>

#include "Encoder.h"

typedef struct {
  char wrongWord[301];
  char correctWord[301];
} DictEntry;

char *autoCorrectText(char *str, DictEntry *dictionary, int numberOfWords,
                      char codes[26][5]);
