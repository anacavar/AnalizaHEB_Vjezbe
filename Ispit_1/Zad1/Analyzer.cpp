#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analyzer::Loop()
{
   //   In a ROOT session, you can do:
   //      root> .L Analyzer.C
   //      root> Analyzer t
   //      root> t.GetEntry(12); // Fill t data members with entry number 12
   //      root> t.Show();       // Show values of entry 12
   //      root> t.Show(16);     // Read and show values of entry 16
   //      root> t.Loop();       // Loop on all entries
   //

   //     This is the loop skeleton where:
   //    jentry is the global entry number in the chain
   //    ientry is the entry number in the current Tree
   //  Note that the argument to GetEntry must be:
   //    jentry for TChain::GetEntry
   //    ientry for TTree::GetEntry and TBranch::GetEntry
   //
   //       To read only selected branches, Insert statements like:
   // METHOD1:
   //    fChain->SetBranchStatus("*",0);  // disable all branches
   //    fChain->SetBranchStatus("branchname",1);  // activate branchname
   // METHOD2: replace line
   //    fChain->GetEntry(jentry);       //read all branches
   // by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0)
      return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry = 0; jentry < nentries; jentry++)
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0)
         break;
      nb = fChain->GetEntry(jentry);
      nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}

void Analyzer::ChiSquareFit()
{
   TCanvas *c = new TCanvas("c", "c", 1200, 800);
   gStyle->SetOptFit();

   float x_array[11];
   float y_array[11];
   float sigma_y[11];
   float sigma_x[11];

   fit_function = new TF1("fit_function", "[0]*TMath::Exp(-[1]*x)*TMath::Sin([2]*x)", 0.1, 10.);
   fit_function->SetParName(0, "A");
   fit_function->SetParName(1, "alpha");
   fit_function->SetParName(2, "beta");

   fit_function->SetParameter(0, 0.2);
   fit_function->SetParameter(1, 0.2);
   fit_function->SetParameter(2, 2.);

   if (fChain == 0)
      return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   int i = 0;
   for (Long64_t jentry = 0; jentry < nentries; jentry++)
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0)
         break;
      nb = fChain->GetEntry(jentry);
      nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      x_array[i] = x;
      y_array[i] = y;
      sigma_y[i] = error;
      sigma_x[i] = 0;
      i++;
   }
   gr = new TGraphErrors(11, x_array, y_array, sigma_x, sigma_y);
   gr->Fit(fit_function);

   gr->SetTitle("Chi-Square function fit");
   gr->SetMarkerColor(kBlack);
   gr->SetMarkerStyle(21);
   gr->SetMaximum(0.9);
   gr->SetMinimum(-0.7);
   gr->GetXaxis()->SetTitle("x");
   gr->GetYaxis()->SetTitle("y");
   gr->Draw("AP");

   c->SaveAs("histo.pdf");

   cout << "alpha = " << fit_function->GetParameter(1) << " +- " << fit_function->GetParError(1) << "\n";
   cout << "beta = " << fit_function->GetParameter(2) << " +- " << fit_function->GetParError(2) << "\n";
}
