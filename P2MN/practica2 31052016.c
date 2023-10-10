
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846


double F (double x, double mu);

void romberg(double f(double, double), double a, double b, int n, double **R);

double trapezis(double f(double, double), double a, double b, int n);



double F (double x, double mu)
{
  return (1.0/ (sqrt(1.0 - mu*sin(x)*sin(x))));
}



double trapezis(double f(double, double), double a, double b, int n)
{
       int i;
       double s=0,y=0,h,fi0=0,mu=0;

       printf("Introdueix el valor del angle inicial\n");
       scanf("%lf", &fi0);

       mu=sin(fi0/2.0)*sin(fi0/2.0);

       h=(b-a)/n;

      for(i=1;i<=n-1;i++)
      {
       s=s+f(a+i*h,mu);
      }

      y=(f(a,mu)+f(b,mu)+2*s)*h/2;

      return y;

       }




 void romberg(double f(double, double), double a, double b, int n, double **R)
{
  int i, j, k;
  double h, sum, fi0=0, mu=0;

       printf("Introdueix el valor del angle inicial\n");
       scanf("%lf", &fi0);

       mu=sin(fi0/2.0)*sin(fi0/2.0);


  h = b - a;
  R[0][0] = 0.5 * h * (f(a,mu) + f(b,mu));
  printf(" R[0][0] = %f\n", R[0][0]);

  for (i = 1; i <= n; i++)
  {
     h *= 0.5;
     sum = 0;
     for (k = 1; k <= pow(2,i)-1; k+=2)
     {
       sum += f(a + k * h,mu);
     }
     R[i][0] = 0.5 * R[i-1][0] + sum * h;
     printf(" R[%d][0] = %f\n", i, R[i][0]);
     for (j = 1; j <= i; j++)
     {
       R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4,j)-1);
       printf(" R[%d][%d] = %f\n", i,j, R[i][j]);
     }
   }
}





int main()
{

  int n = 10;
  int i;
  double **R;
  double F(double, double);
  double g,L,fi0,mu,w0,temp=0,Ttrap,Trom;

  R = calloc((n+1), sizeof(double *));
  for (i = 0; i <= n; i++)
    R[i] = calloc((n+1), sizeof(double));

    printf("Aquest programa ha estat fet per G.Domenech, O.Garrido i N.Ponsa\n");

    printf("Introdueix la gravetat (positiva) i la llargada del pendol. En aquest ordre:\n");
    scanf("%lf %lf", &g, &L);


    w0=sqrt(g/L);

    temp=trapezis(F,0.0,PI/2.0,4);
    printf("El metode del trapezi ens dona que el valor de la integral es:\n");
    printf("%lf\n", temp);

    printf("I per tant el valor del periode buscat si usem trapezis es:\n");
    Ttrap=(4.0*temp)/w0;
    printf("%lf\n", Ttrap);




    printf("El metode de Romberg ens dona els resultats seguents:\n");
    romberg(F, 0.0, PI/2 ,3, R);

    printf("I per tant el valor del periode buscat si usem Romberg es:\n");
    temp=R[3][3];
    Trom=(4.0*temp)/w0;
    printf("%lf\n", Trom);


  system("pause");

}




