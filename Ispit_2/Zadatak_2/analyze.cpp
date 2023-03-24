#include <iostream>
#include <fstream>
#include <Analyzer.h>

using namespace std;

int main()
{
  Analyzer *analyzer;
  analyzer = new Analyzer();
  analyzer->Gauss();
  analyzer->~Analyzer();
  return 0;
}