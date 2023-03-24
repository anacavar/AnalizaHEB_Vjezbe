// #include <TROOT.h>
// #include <TFile.h>
// #include <TH1F.h>
// #include <TF1.h>
// #include <TCanvas.h>
// #include <TBranch.h>
// #include <TTree.h>
// #include <TGraphErrors.h>
#include <TMath.h>
#include <iostream>

using namespace std;

class Analyzer
{
public:
   Analyzer();
   ~Analyzer();
   float Poisson(int, float);
   void Funkcija();

private:
   // TFile *file;
   // TTree *tree;
   // TF1 *fit;
   // TCanvas *c;
   // TGraphErrors *graf;
   // Float_t x, y, error;
   Int_t i;
};
