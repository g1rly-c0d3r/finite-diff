#include<cstdio>
#include<cmath>

#define X_VALS 20
#define T_VALS 20


double f_init(double x, double t){
  return std::sin(2*M_PI*x); 
}

void print_arr(double v[][T_VALS]){
  for(int k=0; k<T_VALS; k++){
    for(int j=0; j<X_VALS; j++){
      printf("%f ", v[j][k]);
    }
    printf("\n");
  }
}

void init_array(double v[X_VALS][T_VALS]){
/* takes an array of size X_VALS x T_VALS and sets every element to 0.0 */
// preformance hit since all of these values will get reassigned 
// needed for debugging
  for(int j=0; j<X_VALS; j++){
    for(int k=0; k<T_VALS; k++){
      v[j][k] = 0.0;
    }
  }
}

int main(void){
  // m is x bound, n is t bound
  unsigned short j=0, k=0; // mutable indicies of x and t
  double delta_x = 1.0/static_cast<double>(X_VALS), delta_t = 1.0 / static_cast<double>(T_VALS); 
  

  // array of values
  double v[X_VALS+T_VALS][T_VALS];
  init_array(v);

  // first "time step" using the init cond
  for(j=0; j < X_VALS+T_VALS; j++){
    v[j][0] = f_init(j * delta_x, k * delta_t);
  }

  // for this example, shorthand
  double s = 1.0 - delta_t/delta_x - delta_t; 
  double d = delta_t/delta_x;
  
  //next time steps
  for(k=0; k<T_VALS-1; k++){
    for(j=0; j<X_VALS+T_VALS-k; j++){
      v[j][k+1] = s * v[j][k] + d*v[j+1][k];
    }
  }

  print_arr(v);
  return 0;
}


