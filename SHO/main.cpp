//--------------------------------------------------------------
// Solution of Simple Harmonic Oscillator using the Euler Method
// note: to emphasize that the solution of the ODEs are functions
//   we store their discrete approximation as arrays x[n], v[v]
//   this is very very wasteful and later on we need to use codes
//   that only keep the last few term needed to iterate the procedure
//   e.g.  xold, xnew
//         vold, vnew
//         told, tnew
//--------------------------------------------------------------

using namespace std;
#include <iostream>
#include <iomanip>

double ft(double,double,double);        //prototype
double Et(double,double);               //prototype

int main(){
  const int n=1000;int i;
  double xold, xnew, vold, vnew,E,told, tnew,dt;

  dt=0.05;  //time step
  xnew = 1.0; vnew = 0.0; tnew = 0.0;

  E=Et(xnew, vnew);

    cout << setw(16) << tnew << setw(16) << xnew << setw(16) << E << endl;

  for(i=0;i<n-1;i++)
    {
    told = tnew;
    xold = xnew;
    vold = vnew;
    tnew = told + dt;
    xnew = xold + vold*dt;
    vnew = vold + ft(xold, vold, told)*dt;
    E=Et(xnew, vnew);
    tnew = told + dt;

    cout << setw(16) << tnew << setw(16) << xnew << setw(16) << E << endl;

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

