#include<iostream>

using namespace std;

class Generator
{
   public:
   Generator();
   float generatePDF(int _xmin, int _xmax);
   int xmin;
   int xmax;
};