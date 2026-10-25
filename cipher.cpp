enum mode {
  ENCRYPT,
  DECRYPT,
};

void cruz(char *in, mode mode) {

  int m[] = {5, 15, 9, 23, 17, 19, 1, 11, 25, 7, 21, 3};
  int n[] = {21, 7, 3, 17, 23, 11, 1, 19, 25, 15, 5, 9};

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

    break;

  case DECRYPT:

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