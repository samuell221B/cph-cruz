#ifndef CIPHER_H
#define CIPHER_H

class cph {
public:
  enum mode {
    ENCRYPT,
    DECRYPT,
  };

  static void cruz(char *in, cph::mode mode = ENCRYPT);
};

#endif