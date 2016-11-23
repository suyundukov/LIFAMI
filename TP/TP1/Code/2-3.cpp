/**
 *    -> Suivre les indications de l'exercise
 */
#include <Grapic.h>
#include "Complex.hpp"

using namespace grapic;

const short DIMW = 500;

/* Exercise 2 */

void drawSampling() {
  float a;
  float b;
  short max;
  Complex c;
  Complex center;

  center = toComplex(DIMW / 2, DIMW / 2);
  max = 10;

  for (int i = 0; i < max; ++i) {
    a = float(DIMW) * i / max;
    for (int j = 0; j < max; ++j) {
      b = float(DIMW) * j / max;
      c = toComplex(a, b);
      circleFill(c.x, c.y, 2);
    }
  }
}

/* Exercise 3 */

void drawSamplingExp() {
  float r;
  float theta;
  short max;
  Complex c;
  Complex center;

  center = toComplex(DIMW / 2, DIMW / 2);
  max = 20;

  for (int i = 0; i < max; ++i) {
    r = .5f * DIMW * i / max;
    for (int j = 0; j < max; ++j) {
      theta = 2.f * M_PI * j / max;
      c = center + toComplexExp(r, theta);
      circleFill(c.x, c.y, 1);
    }
  }
}

/* Programme principal */

int main(int, char**) {
  bool stop;
  Menu menu;

  stop = false;

  winInit("Complex", DIMW, DIMW);

  menu_add(menu, "Sampling reg");
  menu_add(menu, "Sampling exp");

  backgroundColor(34, 34, 34);
  while(!stop) {
    winClear();

    color(255, 0, 0);

    switch (menu_select(menu)) {
      case 0:
        drawSampling();
        break;
      case 1:
        drawSamplingExp();
        break;
    }

    menu_draw(menu);

    stop = winDisplay();
  }
  winQuit();

  return 0;
}
