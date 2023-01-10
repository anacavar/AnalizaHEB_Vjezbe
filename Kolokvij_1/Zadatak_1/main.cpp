#include <iostream>
#include <Generator.h>

int main() {
  Generator Gen(-3, 9);
  std::cout << Gen.generatePDF() << std::endl;
  return 0;
}