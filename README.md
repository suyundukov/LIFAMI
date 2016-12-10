<p align="center">
  <img src="https://i1.sumaxi.me/i/lifami.svg" width="100%" height="300">
</p>

Table of Contents
-----------------

- [CM](#cm)
- [TD](#td)
- [TP](#tp)
- [Links](#links)

Courses
-------

### CM

- [CM1 : Nombres complexes / Interpolation et monde discret](CM/CM1.pdf)
- [CM2a : Culture générale de programmation](CM/CM2a.pdf)
- [CM2b : Dérivées et mécanique du point / Système de particules](CM/CM2b.pdf)

### TD

- [TD1 : Nombres complexes et transformations du plan](TD/TD1/)
  - [Sujet](TD/TD1/TD1.pdf)
  - [Corrigé](TD/TD1/TD1-cor.pdf)
  - [Source Code](TD/TD1/Code/)
- [TD2 : Interpolation](TD/TD2/)
  - [Sujet](TD/TD2/TD2.pdf)
  - Corrigé[](TD/TD2/TD2-cor.pdf)
  - Source Code[](TD/TD2/Code/)
- [TD3 : Système de particules / Mécanique du point](TD/TD3/)
  - [Sujet](TD/TD3/TD3.pdf)
  - Corrigé[](TD/TD3/TD3-cor.pdf)
  - Source Code[](TD/TD3/Code/)
- [TD4 : Collision et système Masses-Ressorts](TD/TD4/)
  - [Sujet](TD/TD4/TD4.pdf)
  - Corrigé[](TD/TD4/TD4-cor.pdf)
  - Source Code[](TD/TD4/Code/)
- [TD5 : Dérivée et intégrale de fonctions discrètes](TD/TD5/)
  - [Sujet](TD/TD5/TD5.pdf)
  - Corrigé[](TD/TD5/TD5-cor.pdf)
  - Source Code[](TD/TD5/Code/)
- [TD6 : Dynamique des populations](TD-TP/TD6-TP4/)
  - [Sujet](TD-TP/TD6-TP4/TD6-TP4.pdf)
  - Corrigé[](TD-TP/TD6-TP4/TD6-TP4-cor.pdf)
  - Source Code[](TD-TP/TD6-TP4/Code/)
- [TD7 : Evolution de la couleur des insectes cherchant à se camoufler](TD-TP/TD7-TP5/)
  - [Sujet](TD-TP/TD7-TP5/TD7-TP5.pdf)
  - Corrigé[](TD-TP/TD7-TP5/TD7-TP5-cor.pdf)
  - Source Code[](TD-TP/TD7-TP5/Code/)
- [TD8 : Dérivée, intégrale et applications à l’économie](TD/TD8/)
  - [Sujet](TD/TD8/TD8.pdf)
  - Corrigé[](TD/TD8/TD8-cor.pdf)
  - Source Code[](TD/TD8/Code/)

### TP

- [TP1 : Nombres complexes et transformations du plan](TP/TP1/)
  - [Sujet](TP/TP1/TP1.pdf)
  - [Corrigé](TP/TP1/TP1-cor.pdf)
  - [Source Code](TP/TP1/Code/)
- [TP2 : Interpolation](TP/TP2/)
  - [Sujet](TP/TP2/TP2.pdf)
  - Corrigé[](TP/TP2/TP2-cor.pdf)
  - Source Code[](TP/TP2/Code/)
- [TP3 : Système de particules](TP/TP3/)
  - [Sujet](TP/TP3/TP3.pdf)
  - Corrigé[](TP/TP3/TP3-cor.pdf)
  - Source Code[](TP/TP3/Code/)
- [TP4 : Dynamique des populations](TD-TP/TD6-TP4/)
  - [Sujet](TD-TP/TD6-TP4/TD6-TP4.pdf)
  - Corrigé[](TD-TP/TD6-TP4/TD6-TP4-cor.pdf)
  - Source Code[](TD-TP/TD6-TP4/Code/)
- [TP5 : Evolution de la couleur des insectes cherchant à se camoufler](TD-TP/TD7-TP5/)
  - [Sujet](TD-TP/TD7-TP5/TD7-TP5.pdf)
  - Corrigé[](TD-TP/TD7-TP5/TD7-TP5-cor.pdf)
  - Source Code[](TD-TP/TD7-TP5/Code/)
- [TP6 : Simulation économique des marchands de glaces](TP/TP6/)
  - [Sujet](TP/TP6/TP6.pdf)
  - Corrigé[](TP/TP6/TP6-cor.pdf)
  - Source Code[](TP/TP6/Code/)

## Links

- [Support files](TD-TP/All.pdf)
- [GrAPiC][grapic]
- [sunlib.hpp][sunlib]

  > Defines some useful functions

  ```cpp
int fact(int n);  // Factorial Function
int combin(int n, int p);  // Combination Function
  ```

- [Complex.hpp][complex]

  > Contains some functions to use with complex numbers

  ```cpp
Complex toComplex(float a, float b);  // Create (make) complex number (Algebraic form)
Complex toComplexExp(float r, float theta);  // Create (make) complex number (Exponential form)
Complex operator+(Complex a, Complex b);  // Let's us add two complex numbers
Complex operator-(Complex a, Complex b);  // Let's us subtract second complex numbers from the first
Complex operator*(Complex a, Complex b);  // Let's us muliplie both complex numbers
Complex operator*(float lambda, Complex b);  // Let's us multiplie complex number and floating point number
Complex operator/(float lambda, Complex b);  // Let's us divide complex number by floating point number
Complex scale(Complex p, float cx, float cy, float lambda);  // Scaling an object
Complex rotate(Complex p, float cx, float cy, float thetaDeg);  // rotating an object
Complex translate(Complex p, float dx, float dy);  // Translating an object
  ```

## License

<p align="center">
  <a href="./LICENSE"><img src="https://i1.sumaxi.me/i/logo.svg" width="100%" height="128"></a>
  <a href="./LICENSE"><strong>MIT</strong></a>
</p>



[grapic]: http://liris.cnrs.fr/alexandre.meyer/grapic/html/index.html
[sunlib]: https://git.io/vXZXX
[complex]: https://git.io/vXlKK
