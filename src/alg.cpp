// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  uint16_t count = 0;
  double num = 1;
  if (n == 0) {
    return 1;
  } else {
    while (count < n) {
      num *= value;
      count++;
    }
    return num;
  }
}

uint64_t fact(uint16_t n) {
  if (n == 0) {
    return 1;
  }
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double e = 0;
  for (uint16_t i = 0; i <= count; i++) {
    e += calcItem(x, i);
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double s = 0;
  double an = x;
  uint16_t n = 1;
  while (n < count) {
    s += an;
    n++;
    an *= -x * x / (2. * n - 1.0) / (2.0 * n - 2.0);
  }
  return s;
}

double cosn(double x, uint16_t count) {
  double dcos = 0;
  for (uint16_t i = 0; i < count; i++) {
    dcos += (pown(-1, i) * calcItem(x, i * 2));
  }
  return dcos;
}
