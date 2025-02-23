#pragma once
#include<bits/stdc++.h>

namespace eos {
  double forward_difference(std::function<double(double, double)> u, double x, double t, double h){
    double u_x;

    u_x = ( u(x+h, t)-u(x,t) ) / h;

    return u_x;
  }
  double centered_difference(std::function<double(double, double)> u, double x, double t, double h){
    double u_x;

    u_x = ( u(x+h, t)-u(x-h,t) ) / (2*h);

    return u_x;
  }
  double backward_difference(std::function<double(double, double)> u, double x, double t, double h){
    double u_x;

    u_x = ( u(x, t)-u(x-h,t) ) / h;

    return u_x;
  }
}
