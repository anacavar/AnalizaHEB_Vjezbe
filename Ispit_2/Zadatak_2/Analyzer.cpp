#include <Analyzer.h>

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
}

void Analyzer::Gauss()
{
  file = new TFile("/home/public/data/Toy/Gauss.root");
  tree = (TTree *)file->Get("tree");

  tree->SetBranchAddress("x_observed", &x_observed);

  c = new TCanvas("c", "c", 900, 900);
  histogram = new TH1F("hist", "hist", 150, 70., 130.); // 150 binova u rasponu od 1 do 15?

  nentries = tree->GetEntries();
  cout << nentries << endl;

  for (i = 0; i < nentries; i++)
  {
    tree->GetEntry(i);
    histogram->Fill(x_observed);
  }

  gauss1 = new TF1("Gauss H0", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2]))", 70., 130.);
  gauss1->SetParameter(0, -8000000); // C
  gauss1->SetParameter(1, 3);        // mi
  gauss1->SetParameter(2, 1.5);      // sigma
  gauss1->SetParName(0, "C");
  gauss1->SetParName(1, "mi");
  gauss1->SetParName(2, "sigma");

  gauss2 = new TF1("Gauss H1", "[0]*exp(-0.5*((x-[1])/[2])*((x-[1])/[2]))", 70., 130.);
  gauss2->SetParameter(0, -8000000); // C
  gauss2->SetParameter(1, 7);        // mi
  gauss2->SetParameter(2, 1.5);      // sigma
  gauss2->SetParName(0, "C");
  gauss2->SetParName(1, "mi");
  gauss2->SetParName(2, "sigma");

  histogram->Fit(gauss1);
  histogram->Fit(gauss2);
  histogram->SetTitle("Gauss");
  histogram->GetXaxis()->SetTitle("x_observed");
  histogram->Draw("HIST");
  c->SaveAs("graf.pdf");
  c->SaveAs("graf.png");
  c->Destructor();
}