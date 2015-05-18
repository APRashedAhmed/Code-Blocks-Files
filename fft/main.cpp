using namespace std;
#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <complex>
#include <fftw3.h>


//compiled with g++ -lfftw3 fft4.c


typedef complex<double> doublecomplex;

const int n=4;
const double pi=acos(-1.0);

int main(){
  doublecomplex z, w, wn[n], fx[n], Fq[n], FFTFq[n];
  int l,q,k;

  //init xn
  w = doublecomplex(cos(2.0*pi/n),sin(2.0*pi/n));
  wn[0] = 1;
  for(l=1;l<n;l++){ wn[l]=wn[l-1]*w; }

  //init fx
  for(l=0;l<n;l++){ fx[l]=doublecomplex(1.0,0.0); }

  //FT
  for(k=0;k<n;k++){
    Fq[k]=doublecomplex(0.0,0.0);
    for(l=0;l<n;l++){
      q=(l*k)%n;
      Fq[k]+=wn[q]*fx[l];
    }
  }

  //print fx and Fq
  cout << setw(20) << " fx(l) " << setw(20) << " Fq(q) " << endl;
  for(l=0;l<n;l++){
    z=Fq[l]/double(n);
    cout << setw(20) << fx[l] << " ##### " << setw(20) << z << endl;
  }

  fftw_plan p;
  p=fftw_plan_dft_1d(n,reinterpret_cast<fftw_complex*>(&fx[0]), reinterpret_cast<fftw_complex*>(&FFTFq[0]), FFTW_FORWARD, FFTW_ESTIMATE);
  fftw_execute(p);

  //print fx and Fq
  cout << setw(20) << " fx(l) " << setw(20) << " FFTFq(q) " << endl;
  for(l=0;l<n;l++){
    z=FFTFq[l]/double(n);
    cout << setw(20) << fx[l] << " ##### " << setw(20) << z << endl;
  }
  return 0;

}
