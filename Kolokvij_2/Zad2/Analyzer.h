#include <TROOT.h>
#include <TFile.h>
#include <TMath.h>
#include <iostream>

using namespace std;

class Analyzer
{

public:
  Analyzer();
  ~Analyzer();
  float Funkcija(int, float, int);
  void Ajmo();

private:
  int r;
  int r0;
  int N;
  float p;
  float epsilon;
};