#include <Analyzer.h>

int main()
{
  // Declare Analyzer
  Analyzer *analyzer;

  analyzer = new Analyzer();

  analyzer->ReadTxtFile("../Vjezbe_3/Analysis.txt");
  analyzer->ConvertTxtToRootFile("../Vjezbe_3/Analysis.txt", "Analysis.root");

  analyzer->~Analyzer();

  return 0;
}