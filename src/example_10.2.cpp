// I am more comfortable with C-style printing
#include<cstdio>
#include<cmath>

// the number of x and t points to consider on the rectangle [0,1]x[0,1]
#define X_VALS 20
#define T_VALS 20


double f_init(double x, double t){
// initial condition for the diffeq
  return std::sin(2*M_PI*x); 
}

void print_arr(double v[][T_VALS]){
//takes the array of size Xvals x Tvals and prints it to the screen
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
  unsigned short j=0, k=0; // mutable indicies of x and t
  double delta_x = 1.0/static_cast<double>(X_VALS), delta_t = 1.0 / static_cast<double>(T_VALS); // step size for x and t
  

  // array of values
  double v[X_VALS+T_VALS][T_VALS];
  init_array(v);

  // first "time step" using the init cond
  for(j=0; j < X_VALS+T_VALS; j++){
    v[j][0] = f_init(j * delta_x, k * delta_t);
  }

  // these are constants we got from solving the difference eq
  double s = 1.0 - delta_t/delta_x - delta_t; 
  double d = delta_t/delta_x;
  
  //next time steps
  // this is the "meat" of the code, we go through all the rest of the time steps here
  for(k=0; k<T_VALS-1; k++){
    for(j=0; j<X_VALS+T_VALS-k; j++){
      v[j][k+1] = s * v[j][k] + d*v[j+1][k];
    }
  }

  // print it to the screen
  // could print to a file, but I did that on the CL with the shell
  print_arr(v);
  return 0;
}


