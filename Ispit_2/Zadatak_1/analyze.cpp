#include <iostream>
#include <fstream>
#include <Analyzer.h>

using namespace std;

int main()
{
  float a, b, c;
  cout << "Unesite poluosi elipsoida a, b i c:" << endl;
  cin >> a >> b >> c;
  Analyzer *analyzer;
  analyzer = new Analyzer();
  analyzer->Ellipsoid(a, b, c);
  analyzer->~Analyzer();
  return 0;
}