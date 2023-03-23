#include <TROOT.h>
// #include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TBranch.h>
#include <TTree.h>
#include <TGraphErrors.h>
#include <iostream>

using namespace std;

class Analyzer
{
public:
   Analyzer();
   ~Analyzer();
   void PlotHistogram();

private:
   TFile *file;
   TTree *tree;
   TF1 *exp;
   TCanvas *c;
   TGraphErrors *graf;
   // Float_t x, y, error_x, error_y;
   Int_t i, nentries;
};
