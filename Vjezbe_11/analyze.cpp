#include <Analyzer.h>

int main()
{
  Analyzer *analyzer = new Analyzer();
  analyzer->BinomialProb(5, 0.5, 10);
  cout << analyzer->BinomialProb(6, 0.99, 6) << endl;
  cout << analyzer->CPinterval(0.6827, 5, 3).first << endl;
  cout << analyzer->CPinterval(0.6827, 5, 3).second << endl;
  analyzer->CPbelt(10, 0.6827);
  // analyzer->Game();
  analyzer->~Analyzer();
  return 0;
}