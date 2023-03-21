// #include <iostream>
// #include <fstream>
#include <Analyzer.h>

// using namespace std;

int main()
{
  Analyzer *analyzer = new Analyzer();
  analyzer->Ajmo();
  analyzer->~Analyzer();
  return 0;
}