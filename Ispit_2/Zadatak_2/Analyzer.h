#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <iostream>

using namespace std;

class Analyzer
{
public:
   Analyzer();
   ~Analyzer();
   void Gauss();

private:
   TFile *file;
   TTree *tree;
   TF1 *gauss1;
   TF1 *gauss2;
   TCanvas *c;
   TH1F *histogram;
   // TH1F *histogram1;
   Float_t x_observed;
   Int_t i, nentries;
};
