#include<ElementaryParticle.h>

ElementaryParticle::ElementaryParticle() {}
float ElementaryParticle::generatePDF(int xmin, int xmax)
{
  // sample x from [xmin - xmax]
  float x = rand()%(xmax-xmin + 1) + xmin;

  // generate U from [0, f(x)max]
                                    

  // if yes -> accept x :)
  return x;
}