#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

// ROOT headers
#include <TROOT.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TString.h>
#include <TGraphErrors.h>
#include <TF1.h>
#include <TLine.h>

using namespace std;

class Analyzer
{
public:
  Analyzer();  // konstruktor?
  ~Analyzer(); // destruktor?
  void MojaFunkcija();
  // void LifetimeFit();
  // void PlotIndividualLikelihood();

private:
  // TCanvas *canvas;
  // TGraphErrors *graf; // ili pointer??
  // TF1 *fit, *ChiSquare_function;
  // float m_, F_, a_, s_m, s_F, s_A;
  TCanvas *c;
  TGraphErrors *gr;
  TF1 *fit_funciton;
  TF1 *ChiSquare_function;
  TLine *line_h, *line_v1, *line_v2, *line_v3;
};
