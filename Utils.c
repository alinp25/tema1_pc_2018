#include "Utils.h"

// Algoritm cel mai mare divizor comun a doua numere
// construit prin ajutorul operatiilor pe biti
long long GreatestCommonDivisor(long long a, long long b) {
  if (a == b) {
    return a;
  }
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }
  if (~a & 1) {
    if (b & 1) { 
      return GreatestCommonDivisor(a >> 1, b);
    } else {
      return GreatestCommonDivisor(a >> 1, b >> 1) << 1;
    }
  }
  if (~b & 1) {
    return GreatestCommonDivisor(a, b >> 1);
  }
  if (a > b) {
    return GreatestCommonDivisor((a - b) >> 1, b);
  }
  return GreatestCommonDivisor((b - a) >> 1, a);
}

// Functia pentru sortarea in ordine descrescatoare a elementelor
int compareFunction (const void *a, const void *b) {
  return ( *(long long*)b - *(long long*)a);
}

// Verificare daca este majuscula
int isUpperCaseLetter(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}