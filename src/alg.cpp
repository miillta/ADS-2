#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  uint16_t count = 0;
  double num = 1;
  
  if (n == 0) {
    return 1;
  } 
  else {
    while (count < n) {
      num *= value;
      count++;
    }
    return num;
  }
}

uint64_t fact(uint16_t n) {
  uint16_t result = 1;
  for (uint16_t i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double e = 0;
  for (uint16_t i = 0; i < count; i++) {
    e += calcItem(x, i);
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double dsin = 0;
  
  for (uint16_t i = 1; i < count; i++) {
    dsin += pown(-1, i) * calcItem(x, (i * 2) - 1);
  }
  return dsin;
}

double cosn(double x, uint16_t count) {
  double dcos = 0;
  for (uint16_t i = 1; i < count; i++) {
    dcos += pown(-1, i) * calcItem(x, (i * 2) - 2);
  }
  return dcos;
}
