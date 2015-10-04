#define N 8
#define fs 8000
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <complex>
using namespace std;
int main() {

    ofstream saida("DFTPolar.txt");
    double xn=0,ts=(double)1/fs, xmi[N], xmr[N];
    const float ToDeg=180/M_PI; // converte radiano para deg

//------------------------------------------------------------------------
    for (int m=0; m<N/2+1 ;m++){
            xmr[m]=0;
            xmi[m]=0;
        for (int n=0;n<N;n++) {
            xn=sin(2*M_PI*1000*n*ts)+0.5*sin(2*M_PI*2000*n*ts+3*M_PI/4);
            xmr[m]+=(xn*cos(2*M_PI*n*m/N));
            xmi[m]+=-(xn*sin(2*M_PI*n*m/N));
    }
//------------------------------------------------------------------------
            xmr[m]*=10000;
            xmr[m]= (int) xmr[m];
            xmr[m]/=10000;
            xmi[m]*=10000;
            xmi[m]=(int) xmi[m];
            xmi[m]/=10000;
    }
//-------------------Simetria acontece aqui-------------------------------
            for (int j=N-1; j>=(N/2)+1 ;j--){
                        xmr[j]=xmr[N-j];
                        xmi[j]=-xmi[N-j];
    }
//------------------------------------------------------------------------

            for (int x=0; x<N; x++){
                complex <double> resp(xmr[x],xmi[x]);
                //saida <<"x("<<x<<")= "<< setiosflags (ios::fixed) << setprecision (0) <<"("<<abs(resp)<<",<"<<arg(resp)*ToDeg<<")"<< endl;
                cout <<"Polar x("<<x<<")= "<< setiosflags (ios::fixed) << setprecision (0) <<"("<<abs(resp)<<",<"<<arg(resp)*ToDeg<<")\n"<< endl;
        }

}
