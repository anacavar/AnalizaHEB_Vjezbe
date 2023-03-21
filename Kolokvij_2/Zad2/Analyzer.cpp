#include <Analyzer.h>

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
}

float Analyzer::Funkcija(int r, float p, int N)
{
  return TMath::Binomial(N, r) * pow(p, r) * pow(1 - p, N - r);
}

void Analyzer::Ajmo()
{
  r = 0;
  p = 0.1;
  N = 50;
  epsilon = 0.5;
  while (Funkcija(r, p, N) < epsilon && r < N)
  {
    r++;
    r0 = r;
  }

  cout << r0 << endl;
}