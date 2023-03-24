// #include <TROOT.h>
// #include <TFile.h>
// #include <TH1F.h>
// #include <TF1.h>
// #include <TCanvas.h>
// #include <TBranch.h>
// #include <TTree.h>
// #include <TGraphErrors.h>
#include <iostream>

using namespace std;

class Analyzer
{
public:
   Analyzer();
   ~Analyzer();
   void Ellipsoid(float, float, float);

private:
   int N_unutar, N_ukupno;
   float V_ellipsoid;
   float x_random, y_random, z_random;
   float elipsoida;
   int i;
};
