enum mode {
  ENCRYPT,
  DECRYPT,
};

void cruz(char *in, int num, mode mode = ENCRYPT) {

  for (int i = 0; in[i] != '\0'; i++) {
    if ((in[i] >= 'A' && in[i] <= 'Z') || (in[i] >= 'a' && in[i] <= 'z')) {
      in[i] += (mode == ENCRYPT ? num : num * (-1));
    }
  }
};