#include <Analyzer.h>

int main()
{
  Analyzer *analyzer = new Analyzer();
  analyzer->FitToy();
  analyzer->~Analyzer();
  return 0;
}