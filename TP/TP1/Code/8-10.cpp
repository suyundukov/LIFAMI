/**
 * 8 … 10     -> Afficher le système solaire avec les images
 */
#include <Grapic.h>
#include "Complex.hpp"
#include <cstdlib>
#include <ctime>

using namespace grapic;

const short DIMW = 700;
const short STARS = 50;

// Structure de système solaire
struct SolarSys {
  Complex sun;
  Complex earth;
  Complex mars;
  Complex moon;
  Complex stars[STARS];
  Image imSun;
  Image imEarth;
  Image imMars;
  Image imMoon;
};

// Initialisation de SolarSys
void initSolarSys(SolarSys& ss) {
  srand(static_cast<unsigned int>(time(NULL)));

  ss.sun = toComplex(DIMW / 2, DIMW / 2);
  ss.earth = toComplex(150, 0) + ss.sun;
  ss.mars = toComplex(230, 0) + ss.sun;
  ss.moon = toComplex(30, 0) + ss.earth;
  ss.imSun = image("data/planets/sun.png");
  ss.imEarth = image("data/planets/earth.png");
  ss.imMars = image("data/planets/mars.png");
  ss.imMoon = image("data/planets/moon.png");

  for (int i = 0; i < STARS; ++i) {
    ss.stars[i] = toComplex(rand() % DIMW, rand() % DIMW);
  }
}

// Affichage de SolarSys
void drawSolarSys(SolarSys ss) {
  // Stars
  for (int i = 0; i < STARS; ++i) {
    color(255, 255, 255, 200);
    point(ss.stars[i].x, ss.stars[i].y);
  }
  // Le Soleil
  image_draw(ss.imSun, ss.sun.x - 100, ss.sun.y - 100, 200, 200);
  // Le 'chemin' de la Terre
  color(127, 127, 127, 200);
  circle(ss.sun.x, ss.sun.y, 150);
  // La Terre
  image_draw(ss.imEarth, ss.earth.x - 15, ss.earth.y - 15, 30, 30);
  // Le 'chemin' du Mars
  color(127, 127, 127, 200);
  circle(ss.sun.x, ss.sun.y, 230);
  // Mars
  image_draw(ss.imMars, ss.mars.x - 8, ss.mars.y - 8, 16, 16);
  // Le 'chemin' de la Lune
  color(127, 127, 127, 200);
  circle(ss.earth.x, ss.earth.y, 30);
  // La Lune
  image_draw(ss.imMoon, ss.moon.x - 5, ss.moon.y - 5, 10, 10);
}

// Mises à jour des positions
void updateSolarSys(SolarSys& ss) {
  Complex moonLocal;

  moonLocal = ss.moon - ss.earth;
  ss.mars = rotate(ss.mars, ss.sun.x, ss.sun.y, 0.001);
  ss.earth = rotate(ss.earth, ss.sun.x, ss.sun.y, 0.003);
  ss.moon = ss.earth + moonLocal;
  ss.moon = rotate(ss.moon, ss.earth.x, ss.earth.y, 0.01);
}

// Programme principal
int main(int, char**) {
  bool stop;
  SolarSys ss;

  stop = false;

  winInit("Solar System", DIMW, DIMW);
  backgroundColor(34, 34, 34);
  initSolarSys(ss);

  while(!stop) {
    winClear();

    updateSolarSys(ss);
    drawSolarSys(ss);

    stop = winDisplay();
  }
  winQuit();

  return 0;
}
