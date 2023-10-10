
#include<stdio.h>
#include<math.h>
double f(double x)
{
    return x-tan(x);
}
double df (double x)
{
    return -tan(x)*tan(x);
}
int main()

 {
    FILE* miarchivo= NULL;
    char* nombrearchivo = "Data.txt";

    miarchivo= fopen(nombrearchivo, "w");
    if (miarchivo == NULL)return-1;

    int itr, maxmitr;
    double h, x0, x1, tol, er;

    printf("\nPrograma fet per Gemma Domenech, Oscar Garrido, Nil Ponsa\n");
    printf("\nIntrodueix el valor inicial x0, la tolerancia i el numero maxim de iteracions, en aquest ordre\n");

    scanf("%lf %lf %d", &x0, &tol, &maxmitr);
    if (fabs( f(x0) ) < tol)
	{
		printf("No val la pena fer cap iteracio perque el x0 que has introduit ja te una imatge per f el valor de la qual es menor que la tolerancia que has donat, en aquest cas, ens dona que la imatge de x0 = %f val %f \n", x0, f(x0));
    	fprintf(miarchivo, "No val la pena fer cap iteracio perque el x0 que has introduit ja te una imatge per f el valor de la qual es menor que la tolerancia que has donat, en aquest cas, ens dona que la imatge de x0 = %10f val %10f \n", x0, f(x0));

    	fclose(miarchivo);
        return 0;
	}
    //Si no es compleix aquest ''if'' (la condició especificada), aleshores s'acabarà el pregrama.

    //fprintf(miarchivo, "Posant com a valor inicial x0 = %f, amb una tolerancia de %f, i posant un numero maxim de %d iteracions, el Metode de Newton dona els seguents resultats:\n", x0, tol, maxmitr);

    for (itr=1; itr<=maxmitr; itr++)
    {

		h=f(x0)/df(x0);
        x1=x0-h;
        er=fabs(x1-x0)/(fabs(x1)+tol);

        printf(" En la iteracio numero %d, x = %.9f , el error val %f    f(x1)=%10f   f(x0)=%10f\n", itr, x1, er,fabs(f(x1)),fabs(f(x0)));
        fprintf(miarchivo, "%.9f %f\n", x1, er);
		if (fabs(f(x0))<fabs(f(x1))){
		printf("\n\n \t No es un bon punt!!!");
		printf(" El metode no convergeix per al valor inicial x0 donat ,o be, cal fer mes iteracions\n");
        fprintf(miarchivo, " El metode no convergeix per al valor inicial x0 donat ,o be, cal fer mes iteracions\n");
			 break;}


        if (fabs(x1-x0) < tol) //Aquest if et dira el valor de l'arrel si es compleix que la diferència entre x1 i x0 és més petita que la tol.








        {

            printf("Despres de %d iteracions, la arrel val aproximadament %.9f\n", itr, x1);
            //fprintf(miarchivo, "Despres de %d iteracions atura per tolerancia, la arrel val aproximadament %.9f\n", itr, x1);
            break;
        }
        x0=x1;
    }
	if (itr==maxmitr){
		printf(" El metode no convergeix per al valor inicial x0 donat ,o be, cal fer mes iteracions\n");
    	fprintf(miarchivo, " El metode no convergeix per al valor inicial x0 donat ,o be, cal fer mes iteracions\n");}


    fclose(miarchivo);
    return 1;
}
