#include <Analyzer.h>

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
}

void Analyzer::Ellipsoid(float a, float b, float c)
{
  N_unutar = 0;
  N_ukupno = 10000;

  for (i = 0; i < N_ukupno; i++)
  {
    x_random = ((float)rand() / (RAND_MAX)) * (2 * a) - a; // generiraj x između -a do a
    y_random = ((float)rand() / (RAND_MAX)) * (2 * b) - b; // generiraj y između -b do b
    z_random = ((float)rand() / (RAND_MAX)) * (2 * c) - c; // generiraj z između -c do c
    elipsoida = (x_random / a) * (x_random / a) + (y_random / b) * (y_random / b) + (z_random / c) * (z_random / c);

    if (elipsoida <= 1)
    {
      N_unutar++;
    }
  }

  V_ellipsoid = (a * 2) * (b * 2) * (c * 2) * ((float)N_unutar / (float)N_ukupno);

  cout << "Volumen elipsoida je: " << V_ellipsoid << endl;
}