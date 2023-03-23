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
  Analyzer();
  ~Analyzer();
  void MojaFunkcija();

private:
  TCanvas *c;
  TGraphErrors *gr;
  TF1 *fit_funciton;
  TF1 *ChiSquare_function;
  TLine *line_h, *line_v1, *line_v2, *line_v3;
};
