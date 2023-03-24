#include <Analyzer.h>

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
}

void Analyzer::PlotHistogram()
{
  file = new TFile("/home/public/data/Toy/ChiSquareTree.root");
  c = new TCanvas("c", "c", 900, 900);
  tree = (TTree *)file->Get("tree");

  entries = tree->GetEntries();
  Float_t xx[entries], yy[entries], yerrors[entries];

  tree->SetBranchAddress("x", &x);
  tree->SetBranchAddress("y", &y);
  tree->SetBranchAddress("error", &error);

  cout << entries << endl;

  for (i = 0; i < entries; i++)
  {
    tree->GetEntry(i);
    xx[i] = x;
    yy[i] = y;
    yerrors[i] = error;
    // cout << x << " " << y << endl;
  }

  graf = new TGraphErrors(entries, xx, yy, 0, yerrors);

  fit = new TF1("fit", "exp(-[0]*x)*sin([1]*x)", 0., 10.);
  fit->SetParameter(0, 0.2);
  fit->SetParameter(1, 2);
  fit->SetParName(0, "alpha");
  fit->SetParName(1, "beta");

  graf->Fit(fit);
  graf->SetMinimum(-0.8);
  graf->SetMaximum(1.0);
  graf->Draw("AP");

  c->SaveAs("graf.pdf");
  c->Destructor();
}