#pragma once

// Déclaration de la structure
struct Complex {
  float x;
  float y;
};

Complex toComplex(float a, float b);
Complex toComplexExp(float r, float theta);
Complex operator+(Complex a, Complex b);
void operator+=(Complex &a, Complex b);
Complex operator-(Complex a, Complex b);
void operator-=(Complex &a, Complex b);
Complex operator*(Complex a, Complex b);
void operator*=(Complex &a, Complex b);
Complex operator*(float lambda, Complex b);
void operator*=(Complex &b, float a);
Complex operator/(Complex b, float lambda);
void operator/=(Complex &a, float lambda);
Complex scale(Complex p, float cx, float cy, float lambda);
Complex rotate(Complex p, float cx, float cy, float thetaDeg);
Complex translate(Complex p, float dx, float dy);
