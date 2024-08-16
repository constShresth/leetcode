#include <iostream>
using namespace std;

double calculatePower(double x, int n){
  if(n==0 || x==1) return 1;
  if(x==0) return 0;
  cout<<n/2;
  double result = calculatePower(x,n/2);
  return result;
}

int main(){
  double a = 2;
  calculatePower(2,10);

  return 0;
}