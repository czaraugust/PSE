#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>


double slowmedia = 0;
double fastmedia =0;
int samplesFastMean =0;

long int slowfunction()
{
	clock_t start, end;
	start = clock();
	int x;
	slowmedia =0;

	for(int i = 0 ; i < 1000 ; i++)	{

		x = i>>4;
		// 3X³+5x²+8 x +5 POLINÔMIO
		double y= (3*x*x*x) + (5*x*x) + (8*x) +5;
		//SENO
		int  z= sin (y) ;
		//DIVISÃO POR CONSTANTE
		double w = z/10;
		//MEDIA
		slowmedia = (slowmedia +w) /(i+1);
	}

	end = clock();

	return end-start;
}

long int fastfunction(){
	clock_t start, end;
	start = clock();
	int x;
	fastmedia =0;
	for(int i = 0 ; i < 1000 ; i++)	{
		x = i>>4;
		// 3X³+5x²+8 x +5 POLINÔMIO
		double y = ((((3*x) + 5)*x+8) *x)+5;
		//SENO EM SÉRIES DE TAYLOR DE 4ª ORDEM
		int  z = y - (y*y*y / 6.0)  + (y*y*y*y*y / 120.0) - (y*y*y*y*y*y*y / 5040.0);
		//DIVISÃO POR CONSTANTE
		double w = (z *171)>>10;
		//MEDIA RAPIDA
		fastmedia = (fastmedia+ w);
		samplesFastMean ++;





	}
	fastmedia = fastmedia /samplesFastMean;


	end = clock();
	//printf("Tempo total = %lf", v[1]);
	return end-start;
}



int main()
{
    double  x = slowfunction();
		double y = fastfunction();

	 printf("SLOW-> CLOCKS: %f \n",x );
	 printf("FAST-> CLOCKS: %f \n",y );
	 long double perc = (y/x)*100;
	 printf("PORCENTAGEM-> %Lf\n ", perc);


   return 0;
}
