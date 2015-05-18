#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const int N=4;
const int NPS = 1<<16; //This is 2^16

void InitS(int S[N][N])
{
    int ix;
    int iy;

    for(ix=0; ix<N; ix++)
        for(iy=0; iy<N; iy++)
            S[ix][iy] = 1;
}

void PrintS(int S[N][N])
{
    int ix;
    int iy;

    for(ix=0; ix<N; ix++)
    {
        for(iy=0; iy<N; iy++)
        {
            if(S[ix][iy] == 1)
                cout << " + ";
            else
                cout << "   ";
        }

        cout << endl;
    }

    cout << endl;
}

int EnergyS(int S[N][N])
{
    int ix, iy;
    int sum = 0;
    int rix, riy;
    int dix, diy;

    for(ix=0; ix<N; ix++)
    {
        for(iy=0; iy<N; iy++)
        {
            rix = ix+1;
            riy = iy;

            if(rix == N)
                rix = 0;

            dix = ix;
            diy = iy +1;

            if(diy == N)
                diy = 0;

            sum += S[ix][iy]*(S[rix][riy]+S[dix][diy]);

        }
    }

    return -sum;
}

int Delta(int S[N][N], int tix, int tiy)
{
    int rix, riy, dix, diy;
    int lix, liy, uix, uiy;

    rix = tix + 1;
    riy = tiy;

    if(rix == N)
        rix = 0;

    dix = tix;
    diy = tiy + 1;

    if(diy == N)
        diy = 0;

    lix = tix - 1;
    liy = tiy;

    if(lix == N)
        lix = N-1;

    uix = tix;
    uiy = tiy - 1;

    if(uiy == -1)
        uiy = N-1;
}

int main()
{
    //algorithm exact enumeration ising
    int S[N][N];
    int E;
    int k0, k1, k2, k3, k4, k5, k6, k7;
    int k8, k9, k10, k11, k12, k13, k14, k15;
    int ix, iy;

    double kT, PUN, Z, AveE;

    Z = 0;
    kT = 200;
    AveE = 0.0;

    InitS(S);
    PrintS(S);
    E = EnergyS(S);
    cout << E << endl << endl;

        for( k0=-1; k0<2; k0+=2){
            ix=0; iy=0;
            S[ix][iy]=k0;

        for( k1=-1; k1<2; k1+=2){
            ix=1; iy=0;
            S[ix][iy]=k1;

        for( k2=-1; k2<2; k2+=2){
            ix=2; iy=0;
            S[ix][iy]=k2;

        for( k3=-1; k3<2; k3+=2){
            ix=3; iy=0;
            S[ix][iy]=k3;

        for( k4=-1; k4<2; k4+=2){
            ix=0; iy=1;
            S[ix][iy]=k4;

        for( k5=-1; k5<2; k5+=2){
            ix=1; iy=1;
            S[ix][iy]=k5;

        for( k6=-1; k6<2; k6+=2){
            ix=2; iy=1;
            S[ix][iy]=k6;

        for( k7=-1; k7<2; k7+=2){
            ix=3; iy=1;
            S[ix][iy]=k7;

        for( k8=-1; k8<2; k8+=2){
            ix=0; iy=2;
            S[ix][iy]=k8;

        for( k9=-1; k9<2; k9+=2){
            ix=1; iy=2;
            S[ix][iy]=k9;

        for(k10=-1;k10<2;k10+=2){
            ix=2; iy=2;
            S[ix][iy]=k10;

        for(k11=-1;k11<2;k11+=2){
            ix=3; iy=2;
            S[ix][iy]=k11;

        for(k12=-1;k12<2;k12+=2){
            ix=0; iy=3;
            S[ix][iy]=k12;

        for(k13=-1;k13<2;k13+=2){
            ix=1; iy=3;
            S[ix][iy]=k13;

        for(k14=-1;k14<2;k14+=2){
            ix=2; iy=3;
            S[ix][iy]=k14;

        for(k15=-1;k15<2;k15+=2){
            ix=3; iy=3;
            S[ix][iy]=k15;

                E=EnergyS(S);
                PUN=exp(-E/kT);
                Z+=PUN;
                AveE+=PUN*E;

  } } } } } } } } } } } } } } } }

    AveE=AveE/Z;

   cout << setw(12) <<kT
        << setw(12) <<log(Z)
        << setw(12) <<AveE/(N*N)
        << endl;

}
