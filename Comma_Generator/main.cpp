#include <iostream>
#include <math.h>

double cent_calc(double ratio);

int main(int argc, const char * argv[]) {
  double num_ratio{1.5};
  double den_ratio{2.0};
  
  for (int i{2}; i<55; i++){
    for (int q{2}; q<55; q++){
      std::cout << "Num Exp: " << i << " Den Exp: " << q << " Ratio " << cent_calc(pow(num_ratio, i) / pow(den_ratio, q)) << std::endl;
    }
  }
  
  return 0;
}


double cent_calc(double ratio){
  return 1200 * (log10(ratio)/log10(2));
}
