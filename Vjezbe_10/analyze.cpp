#include <Analyzer.h>

int main()
{
  Analyzer *analyzer = new Analyzer();
  analyzer->MojaFunkcija();
  analyzer->~Analyzer();
  return 0;
}