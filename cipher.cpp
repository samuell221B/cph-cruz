#include "cipher.h"

void cph::cruz(char *in, cph::mode mode) {

  int m[] = {5, 15, 9, 23, 17, 19, 1, 11, 25, 7, 21, 3};
  int n[] = {21, 7, 3, 17, 23, 11, 1, 19, 25, 15, 5, 9};

  char buffer[9];
  int map[9] = {8, 6, 7, 0, 1, 2, 3, 5, 4};
  int rmap[9] = {3, 4, 5, 6, 8, 7, 1, 2, 0};

  int p;

  bool upp;

  switch (mode) {
  case ENCRYPT:

    for (int i = 0; in[i] != '\0'; i++) {
      upp = (in[i] >= 'A' && in[i] <= 'Z');
      in[i] += (upp ? 32 : 0);
      if (in[i] > 'a' && in[i] < 'z') {
        p = m[i % 12];
        in[i] = (((in[i] - 97) * p) % 26) + 97;
        in[i] -= (upp ? 32 : 0);
      }
    }

    for (int i = 0; in[i] != '\0'; i++) {
      buffer[map[i % 9]] = in[i];
      if ((i % 9) == 8) {
        for (int x = 0; x < 9; x++) {
          in[i - 8 + x] = buffer[x];
        }
      }
    }

    break;

  case DECRYPT:

    for (int i = 0; in[i] != '\0'; i++) {
      buffer[rmap[i % 9]] = in[i];
      if ((i % 9) == 8) {
        for (int x = 0; x < 9; x++) {
          in[i - 8 + x] = buffer[x];
        }
      }
    }

    for (int i = 0; in[i] != '\0'; i++) {
      upp = (in[i] >= 'A' && in[i] <= 'Z');
      in[i] += (upp ? 32 : 0);
      if (in[i] >= 'a' && in[i] <= 'z') {
        p = n[i % 12];
        in[i] = (((in[i] - 97) * p) % 26) + 97;
        in[i] -= (upp ? 32 : 0);
      }
    }

    break;
  }
};