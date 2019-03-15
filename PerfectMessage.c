#include "PerfectMessage.h"

void perfectMessage(char *text) {
  int lengthOfString = strlen(text);
  int countWrongChars = 0;
  int sum = 0;
  // Numaram caracterele de tip '#' pentru a putea verifica daca este un numar
  // perfect
  for (int i = 0; i < lengthOfString; i++) {
    if (text[i] == '#') {
      countWrongChars++;
      continue;
    }
    // Simultan, calcuam suma elementelor
    sum += (int)(text[i] - '0');
  }
  // Suma modulo 9
  sum %= 9;
  // Daca este numar perfect
  if (((lengthOfString - countWrongChars) % sum == 0) && sum != 0) {
    // Alocam elementele necesare pentru stocarea componentelor
    int numberOfComponents = (lengthOfString - countWrongChars) / sum;
    int currentLength = 0;
    long long currentComponent = 0;
    int compIdx = 0;
    long long *components = (long long*)malloc(sizeof(long long) 
                          * numberOfComponents);
    // Parcurgem sirul element cu element
    for (int i = 0; i < lengthOfString; i++) {
      if (text[i] == '#') { // Daca intalnim un '#' nu tinem cont de el
        continue;
      }
      // Actualizam componenta curenta
      currentComponent *= 10;
      currentComponent += (long long)(text[i] - '0');
      currentLength++;
      if (currentLength == sum) { // Cand componenta curenta atinge lungimea
                                  // reprezentata de suma elementelor % 9
                                  // o adaugam in array
        components[compIdx] = currentComponent;
        currentComponent = 0;
        currentLength = 0;
        compIdx++;
      }
    }
    // Sortam componentele
    qsort(components, numberOfComponents, sizeof(long long), compareFunction); 
    // Afisam componentele
    for (int i = 0; i < numberOfComponents; i++) {
      printf("%lld ", components[i]);
    }
    free(components);
  } else { // Daca nu este numar perfect
    printf("0\n");
  }
}
// CERINTA 4
int countComponents(char *text) {
  int counterComps = 0;
  int lengthOfText = strlen(text);
  int isValidComp = 0;
  for (int i = 0; i < lengthOfText; i++) {
    if (text[i] == '#') {
      continue;
    }
    // Verificam daca pana la momentul in care gasim '0' intalnim cel putin un
    // element ce poate reprezenta o componenta (formata din 1-9)
    if (text[i] == '0' && isValidComp == 1) {
      counterComps++;
      isValidComp = 0;
      continue;
    }
    // Validam ca poate fi construita o componenta
    if (text[i] >= '0' && text[i] <= '9') { 
      isValidComp = 1;
    }
  }
  // Verificam si actualizam numarul de componente
  if (isValidComp == 1) {
    counterComps++;
  }
  return counterComps;
}

void printComponents(char *text, int numberOfComponents) {
  // printf("\n\n%d\n\n", numberOfComponents);
  long long currentComponent = 0;
  int idx = 0;
  long long maxComponent = -1;
  int maxComponentIdx = -1;
  long long *components = (long long*)malloc(sizeof(long long) 
                          * numberOfComponents);
  int lengthOfText = strlen(text);
  for (int i = 0; i < lengthOfText; i++) {
    if (text[i] == '#') {
      continue;
    }
    // Verificam daca exista vreo componenta curenta la intalnirea elementului
    // '0'
    if (text[i] == '0' && currentComponent != 0) {
      // Afisam componenta gasita
      printf("%lld ", currentComponent);
      // Actualizam componenta maxima si indexul sau
      components[idx] = currentComponent;
      if (currentComponent > maxComponent) {
        maxComponent = currentComponent;
        maxComponentIdx = idx;
      }
      idx++;
      currentComponent = 0;
    }
    // Actualizam componenta curenta
    currentComponent *= 10;
    currentComponent += (long long)(text[i] - '0');
  }
  if (currentComponent != 0) {
    printf("%lld\n", currentComponent);
    components[idx] = currentComponent;
    if (currentComponent > maxComponent) {
      maxComponent = currentComponent;
      maxComponentIdx = idx;
    }
    idx++;
  } else {
    printf("\n");
  }
  // Afisam componenta maxima si indexul acesteia
  printf("%lld %d\n", maxComponent, maxComponentIdx + 1);
  
  // printf("\n\n\n");
  int isPrime = 1;
  for (int i = 0; i < numberOfComponents && isPrime == 1; i++) {
    for (int j = i + 1; j < numberOfComponents; j++) {
      if (GreatestCommonDivisor(components[i], components[j]) != 1) {
        isPrime = 0;
        break;
      }
    }
  }
  printf("%d\n", isPrime);
  free(components);
}

