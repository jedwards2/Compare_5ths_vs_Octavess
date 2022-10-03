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
  double num_ratio{1.5};
  double den_ratio{2.0};
  
  std::vector<Ratio> ratio_array;
  
  for (int i{2}; i<55; i++){
    for (int q{2}; q<55; q++){
      Ratio current_ratio { i, q, cent_calc(pow(num_ratio, i) / pow(den_ratio, q))};
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
