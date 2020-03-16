#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
LogicalVector oddeven(NumericVector x) {
  int n = x.size();
  LogicalVector out(n);
  IntegerVector y(n);
  y = x/2;
  Function sum("sum");
  CharacterVector r(n);
  for (int i = 0; i < n; ++i){out[i] = y[i]*2==x[i];}
  for (int i = 0; i < n; ++i){r[i] = x[i];}
  out.names() = r;
  out.attr("even") = sum(out);
  out.attr("odd") = n-as<int>(sum(is_na(x)))-as<int>(sum(out));
  out.attr("class") = "oddeven";
  return out;}
