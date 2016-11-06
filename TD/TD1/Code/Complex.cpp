#include "Complex.hpp"
#include <cmath>

Complex toComplex(float a, float b)
{
  Complex c;
  
  c.x = a;
  c.y = b;
  
  return c;
}

Complex toComplexExp(float r, float theta)
{
  Complex c;
  
  c.x = r * cos(theta);
  c.y = r * sin(theta);
  
  return c;
}

Complex operator+(Complex a, Complex b)
{
  Complex c;
  
  c.x = a.x + b.x;
  c.y = a.y + b.y;
  
  return c;
}

void operator+=(Complex &a, Complex b)
{
  a.x += b.x;
  a.y += b.y;
}

Complex operator-(Complex a, Complex b)
{
  Complex c;
  
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  
  return c;
}

void operator-=(Complex &a, Complex b)
{
  a.x -= b.x;
  a.y -= b.y;
}

Complex operator*(Complex a, Complex b)
{
  Complex c;
  
  c.x = a.x * b.x - b.y * a.y;
  c.y = a.x * b.y + a.y * b.x;
  
  return c;
}

Complex operator*(float lambda, Complex b)
{
  Complex c;
  
  c.x = b.x * lambda;
  c.y = b.y * lambda;
  
  return c;
}

void operator*=(Complex &a, float lambda)
{
  a.x *= lambda;
  a.y *= lambda;
}

void operator*=(Complex &a, Complex b)
{
  float temp;
  
  temp = a.x;
  
  a.x = a.x * b.x - b.y * a.y;
  a.y = a.y * b.x + temp * b.y;
}

Complex operator/(Complex b, float lambda)
{
  Complex c;
  
  c.x = b.x / lambda;
  c.y = b.y / lambda;
  
  return c;
}

void operator/=(Complex &a, float lambda)
{
  a.x /= lambda;
  a.y /= lambda;
}

Complex scale(Complex p, float cx, float cy, float lambda)
{
  Complex tr;
  Complex scp;
  
  tr = toComplex(cx, cy);
  scp = (lambda * (p - tr)) + tr;
  
  return scp;
}

Complex rotate(Complex p, float cx, float cy, float thetaDeg)
{
  Complex c;
  Complex tr;
  Complex rot;
  
  tr = toComplex(cx, cy);
  rot = toComplexExp(1, thetaDeg);
  c = ((p - tr) * rot) + tr;
  
  return c;
}

Complex translate(Complex p, float dx, float dy)
{
  Complex c;
  
  c = p + toComplex(dx, dy);
  
  return c;
}
