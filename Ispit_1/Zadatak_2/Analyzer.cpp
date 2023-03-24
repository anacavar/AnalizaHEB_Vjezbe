#include <Analyzer.h>

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
}

// Napišite skriptu koja za dani level pouzdanosti (CL, "confidence level")
// i broj uočenih događaja računa centralni interval pouzdanosti
// (za parametar 0<lambda<50). Pri numeričkom određivanju intervala
// pouzdanosti koristite korak od 0.001 pri iteriranju preko parametra lambda.

void Analyzer::Funkcija(float C, int r)
{
  // C je zadani confidence level
  // r je broj uočenih događaja
  // lambda je šta ono? ๏ λ events expected to occur in average during some time interval

  float lambda = 1;

  while (lambda < 50)
  {
    lambda = lambda + 0.001;
  }

  float lol = TMath::Poisson(3, 0.5);

  cout << lol << endl;
}