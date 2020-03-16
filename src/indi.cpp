#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int indi(double x, double l, double u) {
  if(l<=x){if(x<=u){return 1;} else {return 0;}} else {return 0;}
}
