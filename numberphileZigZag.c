#include <stdio.h>

// Compile the program below with something like: "gcc lorenz.c" and
// execute it with:      "a.out | less" (without the quotes)

unsigned assoc[91];  // associative array to map ASCII chars to teleprinter 5-hole

// Bletchley notation for 0-31 tty codes
char *bp = "/T3O9HNM4LRGIPCVEZDBSYFXAWJ+UQK-";

char *P1 = "HELLO DAVID SEE YOU LATER";
char *P2 = "HI DAVE SEE YOU LATER";
char *P3 = "HI DAV";
char *P4 = "HI DAVE SEE YOU";
char *P5 = "HELLO DAV";
char *P6 = "HELLO DAVID";
char *P7 = "HELLO DAVID SEE";
char *P8 = "HELLO DAVID SEE YOU";

char *K = "UGKZBQLMCDBSNPFGHLMIRSZWX";

char *C1 = "W+XAEW+-TKTEDQNVER+4OIELQ";
char *C2 = "WMJOGDWOJ3OEBCRVIZNU";
char *C3 = "WMJOGDWOJ3OEBCRVIZNU/////";

char *X  = "/UP++G3U+U3/TBI/U+QS";
char *X1 = "/UP++G3U+U3/TBI/U+QSOIEL";
void  xorstrings(char *p, char *q) {
  while ((*p != 0) && (*q != 0)) {
    putchar(bp[assoc[*p] ^ assoc[*q]]);
    *p++;
    *q++;
  }
  putchar('\n');
};

int main(int *argc, char *argv[]) {
  int i, j;

  // Associative array which uses ascii representations of the 32 BP characters
  //  to index into a sparse array to deliver back the corresponding 5-bit tty codes

  assoc[32] = 4;
  assoc[43] = 27;  // used by BP for FS
  assoc[45] = 31;  // used by BP for LS
  assoc[47] = 0;   // null character slash
  assoc[48] = 13;  // zero character
  assoc[49] = 29;  // one character
  assoc[50] = 25;  // two character
  assoc[51] = 2;   // three character -- used by BP for CR
  assoc[52] = 8;   // four character -- used by BP for LF
  assoc[53] = 1;   // five character
  assoc[54] = 21;  // six character
  assoc[55] = 28;  // seven character
  assoc[56] = 12;  // eight character
  assoc[57] = 4;   // nine character -- used by BP for word space
  assoc[65] = 24;  // A character
  assoc[66] = 19;  // B character
  assoc[67] = 14;  // C character
  assoc[68] = 18;  // D character
  assoc[69] = 16;  // E character
  assoc[70] = 22;  // F character
  assoc[71] = 11;  // G character
  assoc[72] = 5;   //  H character
  assoc[73] = 12;  // I character
  assoc[74] = 26;  // J character
  assoc[75] = 30;  // K character
  assoc[76] = 9;   // L character
  assoc[77] = 7;   // M character
  assoc[78] = 6;   // N character
  assoc[79] = 3;   // O character
  assoc[80] = 13;  // P character
  assoc[81] = 29;  // Q character
  assoc[82] = 10;  // R character
  assoc[83] = 20;  // S character
  assoc[84] = 1;   // T character
  assoc[85] = 28;  // U character
  assoc[86] = 15;  // V character
  assoc[87] = 25;  // W character
  assoc[88] = 23;  // X character
  assoc[89] = 21;  // Y character
  assoc[90] = 17;  // Z character

  char *p = P1, *q = K, ciphch;
  // put out ciphertext 1
  fputs("In what follows remember that BP uses / to mean NULL and 9 to mean `word space'\n\n", stdout);
  fputs("Here is ciphertext C1: ", stdout);
  xorstrings(P1, K);
  putchar('\n');
  // put out ciphertext 2
  fputs("Here is ciphertext C2: ", stdout);
  xorstrings(P2, K);
  putchar('\n');
  fputs("Remember C1 = P1 + K where K is the key and `+' means XOR from now on\n", stdout);
  putchar('\n');
  fputs("Similarly C2 = P2 + K\n", stdout);
  putchar('\n');
  fputs("Now XOR these two equations together: C1 + C2 = P1 + P2 + K + K \n", stdout);
  putchar('\n');
  fputs("But K + K cancels out to nothing\n", stdout);
  putchar('\n');
  fputs("So we now have: C1 + C2 = P1 + P2  (*)\n", stdout);
  putchar('\n');
  // put out C1 XOR C2
  fputs("So C1 + C2 i.e. the XOR of the two ciphertexts (let's call it D) is \n D = P1 + P2 =  ", stdout);
  xorstrings(C1, C2);
  fputs("We can rearrange this to get P1 + D = P2 or P2 + D = P1\n", stdout);
  putchar('\n');
  fputs("Trying test string of `HI DAV' (XORd with D) as first guess at P2 in above equation gives \n P1 = ", stdout);
  xorstrings(P3, X);
  putchar('\n');

  fputs("Now try the guess P1 = HELLO DAV xor'd with D and we get \n P2 = ", stdout);
  xorstrings(P5, X);
  putchar('\n');

  fputs(" Now try P1 = HELLO DAVID and we get \n P2 = ", stdout);
  xorstrings(P6, X);
  putchar('\n');

  fputs(" Now try P1 = HELLO DAVID SEE and we get \n P2 = ", stdout);
  xorstrings(P7, X);
  putchar('\n');

  fputs(" This looks good! Try P1 = HELLO DAVID SEE YOU and we get \n P2 = ", stdout);
  xorstrings(P8, X);
  putchar('\n');

  fputs(" Nearly there! Try P2 = HI DAVE SEE YOU LATER and we get \n P1 = ", stdout);
  xorstrings(P2, X);
  putchar('\n');

  fputs(" Now do an XOR of P2 with corresponding C2 and we get the key (K) \n K = ", stdout);
  xorstrings(P2, C2);
  //	xorstrings(C1,C3);
  putchar('\n');

  //	xorstrings(C3,X1);
  //	putchar('\n');
}