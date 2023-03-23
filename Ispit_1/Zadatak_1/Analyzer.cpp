#include <Analyzer.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TH1F.h>
#include <TBranch.h>

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

  Float_t x, y, error;

  Float_t xx[11], yy[11], yerrors[11];

  tree->SetBranchAddress("x", &x);
  tree->SetBranchAddress("y", &y);
  tree->SetBranchAddress("error", &error);

  int entries = tree->GetEntries();

  cout << entries << endl;

  for (i = 0; i < entries; i++)
  {
    tree->GetEntry(i);
    xx[i] = x;
    yy[i] = y;
    yerrors[i] = error;
    cout << x << " " << y << endl;
  }

  graf = new TGraphErrors(entries, xx, yy, 0, yerrors);

  graf->Draw("AP");

  c->SaveAs("graf.png");
  c->Destructor();
}