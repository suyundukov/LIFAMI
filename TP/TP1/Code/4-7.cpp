/**
 *    -> Suivre les indications de l'exercise
 */
#include <cmath>
#include <Grapic.h>
#include "Complex.hpp"

using namespace grapic;

const short DIMW = 500;

// Définition de la structure
struct Bird {
  float angle;
  Complex c;
};

// Initialisation
void initBird(Bird& b) {
  b.angle = 15;
  b.c = toComplex(DIMW / 2, DIMW / 2);
}

// Affichage
void draw(Bird& b) {
  Complex right;
  Complex left;

  right = b.c + toComplex(20, 0);
  left = b.c + toComplex(-20, 0);
  right = rotate(right, b.c.x, b.c.y, b.angle);
  left = rotate(left, b.c.x, b.c.y, -b.angle);

  circleFill(b.c.x, b.c.y, 2);
  line(b.c.x, b.c.y, left.x, left.y);
  line(b.c.x, b.c.y, right.x, right.y);
}

// Mises à jours
void update(Bird& b) {
  float d;
  float t;

  d = .1f;

  if (b.c.y > 3)
    b.c.y -= d;

  if (isKeyPressed(SDLK_LEFT))
    if (b.c.x > 0)
      b.c.x -= d;
  if (isKeyPressed(SDLK_RIGHT))
    if (b.c.x < DIMW)
      b.c.x += d;
  if (isKeyPressed(SDLK_UP)) {
    b.c.y += 2.f * d;
    t = elapsedTime();
    b.angle = 20.f * cos(50.f * t);
  } else {
    b.angle = 15.f;
  }
}

/* Programme principal */

int main(int, char**) {
  bool stop;
  Bird b;

  stop = false;

  winInit("Complex", DIMW, DIMW);

  initBird(b);

  backgroundColor(34, 34, 34);
  while (!stop) {
    setKeyRepeatMode(true);
    winClear();

    color(255, 0, 0);

    draw(b);
    update(b);

    stop = winDisplay();
  }
  winQuit();

  return 0;
}
