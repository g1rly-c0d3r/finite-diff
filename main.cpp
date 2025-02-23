#include<cstdio>
#include"finite_diff.hpp"

double f(double x, double t){
  return 3 + 2*x - 7*x*x;
}

int main(void){
  printf("1) u'(2) = %f using forward difference\n", eos::forward_difference(f, 2.0, 0.0, 0.1));
  printf("1) u'(2) = %f using centered difference\n", eos::centered_difference(f, 2.0, 0.0, 0.1));
  printf("1) u'(2) = %f using backward difference\n", eos::backward_difference(f, 2.0, 0.0, 0.1));
  return 0;
}


