/**
 *    -> Suivre les indications de l'exercise
 */
#include <cmath>
#include <Grapic.h>
#include "Complex.hpp"

using namespace grapic;

const short DIMW = 500;
const int MAXITE = 200;

float norm(Complex c) {
  return sqrt(c.x * c.x + c.y * c.y);
}

int suiteJulia(float borne, int maxIte, Complex Z0, Complex C) {
  Complex Zn;
  int i;

  i = 0;
  Zn = Z0;

  do {
    Zn = Zn * Zn + C;
    i += 1;
  } while ((norm(Zn) < borne) && (i < maxIte));

  return i;
}

void colorJulia(int n, unsigned char& r, unsigned char& g, unsigned char& b) {
  float c = (float(n)) / MAXITE;
  r = c * 255;
  g = 128 + c * 128;
  b = 64  + c * (127 + 64);
}

void draw() {
  float x;
  float y;
  int n;
  unsigned char r;
  unsigned char g;
  unsigned char b;
  Complex C;

  C = toComplex(0.32, 0.043);

  for(int i = 0; i < DIMW; ++i)
    for(int j = 0; j < DIMW; ++j) {
      x = ((float(i)) / DIMW) * 3 - 1.5;
      y = ((float(j)) / DIMW) * 3 - 1.5;
      n = suiteJulia(2, MAXITE, toComplex(x, y), C);
      colorJulia(n, r, g, b);
      put_pixel(i, j, r, g, b);
    }
}

/* Programme principal */

int main(int , char**) {
  bool stop;

  stop = false;

  winInit("Julia", DIMW, DIMW);

  backgroundColor(34, 34, 34);
  while (!stop) {
    setKeyRepeatMode(true);
    winClear();

    draw();

    stop = winDisplay();
  }
  winQuit();

  return 0;
}
