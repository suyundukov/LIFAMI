/**
 * 9 ... 17 -> Écrire les fonctions demandés
 */
#include <Grapic.h>
#include "Complex.hpp"

using namespace grapic;

const short DIMW = 500;
const short MAX = 15;

// Structure de polygon
struct Polygon {
  short content;
  Complex tab[MAX];
};

// Ajout d'un sommet à polygone p
void addToPolygon(Polygon &p, float px, float py)
{
  p.tab[p.content] = toComplex(px, py);
  p.content += 1;
}

// Affichage du polygone
void drawPolygon(Polygon p)
{
  for (int i = 0; i < p.content; ++i)
    if (i == p.content - 1)
      line(p.tab[i].x, p.tab[i].y, p.tab[0].x, p.tab[0].y);
    else
      line(p.tab[i].x, p.tab[i].y, p.tab[i + 1].x, p.tab[i + 1].y);
}

// Calcule du centre de gravité d'un polynome
Complex calcCenter(Polygon p)
{
  Complex o;
  
  o = {0, 0};

  for (int i = 0; i < p.content; ++i)
    o += p.tab[i];
  
  o /= p.content;
  
  return o;
}

// Déplacement d'un polynome
void movePolygon(Polygon &p, float dx, float dy)
{
  for (int i = 0; i < p.content; ++i)
    p.tab[i] += toComplex(dx, dy);
}

// Déplacement d'un polynome 1
void translatePolygon(Polygon &p, float dx, float dy)
{
  for (int i = 0; i < p.content; ++i)
    p.tab[i] = translate(p.tab[i], dx, dy);
}

// Homothétie d'un polygone
void scalePolygon(Polygon &p, float cx, float cy, float lambda)
{
  for (int i = 0; i < p.content; ++i)
    p.tab[i] = scale(p.tab[i], cx, cy, lambda);
}

// Rotation d'un polygone
void rotatePolygon(Polygon &p, float cx, float cy, float lambda)
{
  for (int i = 0; i < p.content; ++i)
    p.tab[i] = rotate(p.tab[i], cx, cy, lambda);
}

// Symétrique par rapport à OX
void symmetryX(Polygon &p)
{
  for (int i = 0; i < p.content; ++i)
    p.tab[i].y *= -1;

  movePolygon(p, DIMW / 2, DIMW / 2);
}

// Symétrique par rappoer à OY
void symmetryY(Polygon &p)
{
  for (int i = 0; i < p.content; ++i)
    p.tab[i].x *= -1;

  movePolygon(p, DIMW / 2, DIMW / 2);
}

// Programme principal
int main()
{
  Polygon p;
  Complex c;
  bool stop;
  
  p.content = 3;
  p.tab[0] = {2, 2};
  p.tab[1] = {1, -1};
  p.tab[2] = {.75, 1};
  stop = false;
  
  addToPolygon(p, -1, 1);  // Debug
  
  c = calcCenter(p);
  std::cout << c.x << " " << c.y << std::endl;  // Debug
  
  scalePolygon(p, 0, 0, 80);  // Debug
  
  //movePolygon(p, 250, 250);  // Debug
  //translatePolygon(p, 250, 250);  // Debug

  //rotatePolygon(p, 250, 250, 3.14);  // Debug

  symmetryX(p);  // Debug
  symmetryY(p);  // Debug
  
  winInit("Polygon", DIMW, DIMW);
  backgroundColor(34, 34, 34);
  while(!stop) {
    winClear();
    
    color(255, 0, 0);
    drawPolygon(p);
    
    stop = winDisplay();
  }
  winQuit();
  
  return 0;
}
