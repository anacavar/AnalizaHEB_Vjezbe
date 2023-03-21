#include <Analyzer.h>
#include <TCanvas.h>

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
}

// Napravite histogram varijable var iz ROOT datoteke "/home/public/data/Toy/ToyTree.root" koja se nalazi
// unutar stabla tree. Fitajte histogram na funckiju:
// funkcija = A*(e**(-x/alfa)+e**(-(x-mi)**2/(2*sigma**2)))
// koristeći Likelihood metodu (opcija "L" u root metodi za fitanje histograma). Na istom platnu nacrtajte
// histogram i fitanu funkciju. Ispišite vrjednosti svih parametara i njihove greške. Hint: prije fitanja postavite
// inicijalne vrjednosti parametara α, µ i σ na 4, 3 i 0.3.

void Analyzer::FitToy()
{
  file = new TFile("/home/public/data/Toy/ToyTree.root");
  tree = (TTree *)file->Get("tree");

  tree->SetBranchAddress("var", &var); // ČEMU OVO SLUŽI

  Long64_t nentries = tree->GetEntriesFast();
  cout << nentries << endl;

  canvas = new TCanvas();
  canvas->SetCanvasSize(700, 700);
  hist = new TH1F("hist", "hist", 100, 0., 10.); // 1-D histogram with a float per channel

  for (int i = 0; i < nentries; i++)
  {
    tree->GetEntry(i);
    hist->Fill(var);
  }
  gStyle->SetOptStat(0); // iz TStyle

  f = new TF1("fit funkcija", "[0] * (TMath::Exp(-x / [1]) + TMath::Exp(-(x - [2]) * (x - [2]) / 2. / [3] / [3]))", 0, 10);
  f->SetParameter(0, 224.); // A = ?
  f->SetParameter(1, 4.);   // alfa = 4
  f->SetParameter(2, 3.);   // mi = 3
  f->SetParameter(3, 0.3);  // sigma = 0.3

  hist->Fit(f, "L", "", 0, 10);

  hist->SetTitle("Fit to Toy");
  hist->GetXaxis()->SetTitle("var");

  hist->Draw("HIST");
  f->Draw("SAME");
  canvas->Print("FitToy.pdf");
  canvas->Print("FitToy.png");

  cout << "A =" << f->GetParameter(0) << "±" << f->GetParError(0) << endl;
  cout << "alfa = " << f->GetParameter(1) << "±" << f->GetParError(1) << endl;
  cout << "mu = " << f->GetParameter(2) << "±" << f->GetParError(2) << endl;
  cout << "sigma = " << f->GetParameter(3) << "±" << f->GetParError(3) << endl;
}