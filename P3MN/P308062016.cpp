

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void euler (float x0,float y0,float z0,float sigma,float b,float r,float Tmax,float h)
{

       float x,y,z,temps;

       FILE * archivo;

       archivo=fopen("fitxerE.txt","w");
       fprintf(archivo,"#Fent servir el metode de Euler amb x0=%f , y0=%f, z0=%f, sigma=%f, b=%f, r=%f, Tmax=%f, h=%f ,obtenim els resultats: \n",x0,y0,z0,sigma,b,r,Tmax,h);

       fprintf(archivo,"#Temps \t\t\t X \t\t\t Y \t\t\t Z \t\t\t X^2 \n");

       for(temps=0; temps<Tmax; temps=temps+h)
       {
	      x=x0+(sigma*(y0-x0))*h;
	      y=y0+(x0*(r-z0)-y0)*h;
	      z=z0+(x0*y0-b*z0)*h;

	      fprintf(archivo,"%f \t\t %f \t\t %f \t\t %f \t\t %f\n",temps,x,y,z,pow(x,2));

	      x0=x;
	      y0=y;
	      z0=z;
	}

	fclose(archivo);
}



 void kutta (float a0,float b0,float c0,float sigma,float b,float r,float Tmax,float h)
{
   float a,B,c,i,a1,b1,c1,a2,b2,c2,a3,b3,c3,a4,b4,c4,k1a,k1b,k1c,k2a,k2b,k2c,k3a,k3b,k3c,k4a,k4b,k4c;

   FILE * archivo;
   archivo=fopen("fitxerK.txt","w");

   fprintf(archivo,"#Fent servir el metode de Runge Kutta amb x0=%f , y0=%f, z0=%f, sigma=%f, b=%f, r=%f, Tmax=%f, h=%f ,obtenim els resultats: \n",a0,b0,c0,sigma,b,r,Tmax,h);
   fprintf(archivo,"#Temps \t\t\t X \t\t\t Y \t\t\t Z \t\t\t X^2 \n");


   for(i=0; i<Tmax; i=i+h){

		a1=a0;
		b1=b0;
		c1=c0;
		k1a=sigma*(b1-a1);
		k1b=a1*(r-c1)-b1;
		k1c=a1*b1-b*c1;


		a2=a0+(h/2)*k1a;
		b2=b0+(h/2)*k1b;
		c2=c0+(h/2)*k1c;
		k2a=sigma*(b2-a2);
		k2b=a2*(r-c2)-b2;
		k2c=a2*b2-b*c2;

		a3=a0+(h/2)*k2a;
		b3=b0+(h/2)*k2b;
		c3=c0+(h/2)*k2c;
		k3a=sigma*(b3-a3);
		k3b=a3*(r-c3)-b3;
		k3c=a3*b3-b*c3;

		a4=a0+h*k3a;
		b4=b0+h*k3b;
		c4=c0+h*k3c;
		k4a=sigma*(b4-a4);
		k4b=a4*(r-c4)-b4;
		k4c=a4*b4-b*c4;

		a=a0+(h/6)*(k1a+2*k2a+2*k3a+k4a);
		B=b0+(h/6)*(k1b+2*k2b+2*k3b+k4b);
		c=c0+(h/6)*(k1c+2*k2c+2*k3c+k4c);

		fprintf(archivo,"%f \t\t %f \t\t %f \t\t %f \t\t %f\n",i,a,B,c,pow(a,2));

		a0=a;
		b0=B;
		c0=c;
	}

	fclose(archivo);

}





int main()
{
    float x0,y0,z0,sigma,b,r,Tmax,h;

    printf("Introdueix els valors de: x0, y0, z0, sigma, b, r, Tmax, h en aquest ordre\n");
    scanf("%f %f %f %f %f %f %f %f",&x0,&y0,&z0,&sigma,&b,&r,&Tmax,&h);

    euler (x0,y0,z0,sigma,b,r,Tmax,h);
	kutta (x0,y0,z0,sigma,b,r,Tmax,h);

  system("pause");
}

