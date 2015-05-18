//--------------------------------------------------------------
// Solution of Simple Harmonic Oscillator using the Euler Method
//--------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

double ft(double,double,double);        //prototype
double Et(double,double);               //prototype

int main(){
  const int n=1000;int i;
  double x[n],v[n],E[n],t[n],dt;

  x[0]=1.0; v[0]=0.0; t[0]=0.0;         //initial conditions

  E[0]=Et(x[0],v[0]);

  dt=0.05;                              //time step

  for(i=0;i<n-1;i++){
    x[i+1]=x[i]+v[i]*dt;
    v[i+1]=v[i]+ft(x[i],v[i],t[i])*dt;
    E[i+1]=Et(x[i+1],v[i+1]);
    t[i+1]=t[i]+dt;
}

 for(i=0;i<n;i++){
   cout << setw(16) << t[i] << setw(16) << x[i] << setw(16) << E[i] << endl;
 }
}

//--------------------------------------------------------------
// Model dependent part
//--------------------------------------------------------------

double ft(double x, double v, double t){const double w0=1.0;
  return -w0*w0*x;
}
double Et(double x, double v){          const double w0=1.0;
  return 0.5* (v*v + w0*w0*x*x);
}

