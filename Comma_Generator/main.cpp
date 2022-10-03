#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

struct Ratio {
  int num_exp;
  int den_exp;
  double cent;
};

double cent_calc(double ratio);
bool compare (Ratio a, Ratio b);

int main(int argc, const char * argv[]) {
  const double NUM_RATIO{1.5};
  const double DEN_RATIO{2.0};
  const int EXPONENT_LIMIT{100};
  
  std::vector<Ratio> ratio_array;
  
  for (int i{2}; i<EXPONENT_LIMIT; i++){
    for (int q{2}; q<EXPONENT_LIMIT; q++){
      Ratio current_ratio { i, q, cent_calc(pow(NUM_RATIO, i) / pow(DEN_RATIO, q))};
      ratio_array.push_back(current_ratio);
    }
  }
  
  sort(ratio_array.begin(), ratio_array.end(), compare);
  
  for(Ratio ratio : ratio_array)
    std::cout << "Numerator: " << ratio.num_exp << " Denominator: " << ratio.den_exp << " Cents Off: "<< ratio.cent << std::endl;
  
  return 0;
}

bool compare (Ratio a, Ratio b){
  if (a.cent < b.cent){
    return 1;
  } else {
    return 0;
  }
}

double cent_calc(double ratio){
  return 1200 * (log10(ratio)/log10(2));
}
