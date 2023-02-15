#include <Analyzer.h>
#include <TCanvas.h>

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
  // if (!fChain)
  //   return;
  // delete fChain->GetCurrentFile();
}

void Analyzer::PlotHistogram(TString input_file_name)
{
  c = new TCanvas("c", "c", 900, 900);

  // file = new TFile("/home/public/data/Lifetime/Lifetime.root");
  file = new TFile(input_file_name);

  // tree = (TTree *)file->Get("Tree");
  // tree = (TTree *)file->Get("tree");

  // tree->SetBranchAddress("t", &t);
  // tree.SetBranchAddress("t", &t);

  // gStyle->SetOptStat(0);
  // HistoLifetime = new TH1F("Lifetime", "Lifetime", 24, 0.0, 10.0);
  Histogram = new TH1F("Histogram", "Histogram", 24, 0.0, 10.0);

  // exp = new TF1("exp", "[0]/[1]*exp(-x/[1])", 0.0, 10.0);
  // exp->SetParameter(0, 100.);
  // exp->SetParameter(1, 1.);
  // sum = 0;
  nentries = tree->GetEntries();
  for (i = 0; i < nentries; i++)
  {
    tree->GetEntry(i);
    Histogram->Fill(t);
    sum += t;
  }

  // HistoLifetime->Fit(exp, "L");

  // canvas1 = new TCanvas("canvas1", "canvas1", 600, 400);
  // HistoLifetime->GetXaxis()->SetTitle("t/s");
  // HistoLifetime->GetYaxis()->SetTitle("N");
  // HistoLifetime->Draw();
  Histogram->Draw();
  // canvas1->SaveAs("LifetimeFit.png");
  c->SaveAs("YES.png");

  // std::cout << "Koristeci root: tau = " << exp->GetParameter(1) << "±" << exp->GetParError(1) << endl;

  // mean = sum / nentries;
  // error = mean / sqrt(nentries);
  // C = exp->GetParameter(0);

  // std::cout << "Analiticki: tau = " << mean << "±" << error << endl;

  // delete exp;

  // Likelihood = new TF1("Likelihood", "([0]/x)*exp(-1.0/x)", 0.1, 10);
  // Likelihood->SetParameter(0, C);
  // canvas2 = new TCanvas("canvas2", "canvas2", 600, 400);
  // Likelihood->GetXaxis()->SetTitle("#tau");
  // Likelihood->GetYaxis()->SetTitle("L(#tau)");
  // Likelihood->SetTitle("Likelihood function for t=1s");
  // Likelihood->Draw();
  // canvas2->SaveAs("Likelihood.pdf");

  // delete Likelihood;

  // LogLikelihood = new TF1("LogLikelihood", "-2*([0]*log(1./x)-[1]/x)", 0.1, 5); // mogu uzet C=1, rezultat ostaje isti
  // LogLikelihood->SetParameter(0, nentries);
  // LogLikelihood->SetParameter(1, sum);
  // canvas3 = new TCanvas("canvas1", "canvas1", 600, 400);
  // LogLikelihood->GetXaxis()->SetTitle("#tau");
  // LogLikelihood->GetYaxis()->SetTitle("-2lnL(#tau)");
  // LogLikelihood->SetTitle("Log Likelihood function");
  // LogLikelihood->Draw();
  // canvas3->SaveAs("LogLikelihood.pdf");

  // tau_graph = LogLikelihood->GetMinimumX();
  // Float_t err_dn = tau_graph - LogLikelihood->GetX(LogLikelihood->GetMinimum(0.1, 5) + 1, 0.1, tau_graph); //-2lnL=lnL_min+1
  // Float_t err_up = LogLikelihood->GetX(LogLikelihood->GetMinimum(0.1, 5) + 1, tau_graph, 5) - tau_graph;   //-2lnL=lnL_min+1

  // std::cout << "Graficki: tau = " << tau_graph << "+" << err_up << "-" << err_dn << endl;

  // delete LogLikelihood;

  // delete HistoLifetime, file, tree;
  delete Histogram, file, tree;

  c->Destructor();
  // canvas1->Destructor();
  // canvas2->Destructor();
  // canvas3->Destructor();
}