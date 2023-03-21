// #include <iostream>
// #include <fstream>
#include <Analyzer.h>

// using namespace std;

int main()
{
  Analyzer *analyzer = new Analyzer();
  // analyzer->PlotHistogram("/home/public/data/Toy/ToyTree.root");
  analyzer->FitToy();
  analyzer->~Analyzer();
  return 0;
}