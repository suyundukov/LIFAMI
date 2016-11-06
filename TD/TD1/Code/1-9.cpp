/**
 * 1 ... 8 -> Les consignes sont sur la fiche de TD1
 * 9.      -> Afficher le système solaire simplifié
 */
#include <Grapic.h>
#include "Complex.hpp"

using namespace grapic;

const short DIMW = 700;

// Structure de système solaire
struct SolarSys {
  Complex sun;
  Complex earth;
  Complex mars;
  Complex moon;
};

// Initialisation de SolarSys
void initSolarSys(SolarSys &ss)
{
  ss.sun = toComplex(DIMW / 2, DIMW / 2);
  ss.earth = toComplex(150, 0) + ss.sun;
  ss.mars = toComplex(230, 0) + ss.sun;
  ss.moon = toComplex(30, 0) + ss.earth;
}

// Affichage de SolarSys
void drawSolarSys(SolarSys ss)
{
  // Le bord du Soleil
  color(255, 245, 34, 50);
  circleFill(ss.sun.x, ss.sun.y, DIMW / 11 + 10);
  // Le Soleil
  color(255, 245, 34);
  circleFill(ss.sun.x, ss.sun.y, DIMW / 11);

  // Le 'chemin' de la Terre
  color(127, 127, 127, 200);
  circle(ss.sun.x, ss.sun.y, 150);
  // La Terre
  color(2, 122, 244);
  circleFill(ss.earth.x, ss.earth.y, 15);

  // Le 'chemin' du Mars
  color(127, 127, 127, 200);
  circle(ss.sun.x, ss.sun.y, 230);
  // Mars
  color(255, 0, 0);
  circleFill(ss.mars.x, ss.mars.y, 8);

  // Le 'chemin' de la Lune
  color(127, 127, 127, 200);
  circle(ss.earth.x, ss.earth.y, 30);
  // La Lune
  color(127, 127, 127);
  circleFill(ss.moon.x, ss.moon.y, 5);
}

// Mises à jour des positions
void updateSolarSys(SolarSys &ss)
{
  Complex moonLocal;
  
  moonLocal = ss.moon - ss.earth;
  ss.mars = rotate(ss.mars, ss.sun.x, ss.sun.y, 0.001);
  ss.earth = rotate(ss.earth, ss.sun.x, ss.sun.y, 0.003);
  ss.moon = ss.earth + moonLocal;
  ss.moon = rotate(ss.moon, ss.earth.x, ss.earth.y, 0.01);
}

// Programme principal
int main()
{
  SolarSys ss;
  bool stop;
  
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
