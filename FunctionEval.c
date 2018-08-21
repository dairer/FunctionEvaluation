#include <math.h>
#include <stdio.h>

double f(double x);
double g(double b);
double f1(double x,double alpha);
double f_prime(double x);
int main(void) {

	double alpha;


	/*
	 * Read in alpha
	 */

	printf("Please enter alpha: ");
	if (scanf("%lf", &alpha) != 1) {
		printf("Sorry, couldn’t read steps.\n");
		return 1;
	}
	if (alpha <= 0 || alpha >=1) {
		printf("must have 0<alpha<1\n");
	return 1;
	}

	printf("The value of alpha you entered:%g\n",alpha);




	double x, old_x;
	x  = 1.0;
	do {
		old_x = x;
		x = old_x - f1(old_x,alpha)/f_prime(old_x);
		printf("New value: f(%f) = %f\n", x, f1(x,alpha));
	} while (fabs(old_x - x) > 0.000000000001);

	printf("The value of b such that the equation holds: %f \n", x);




	double ans=g(1.162306);

	/*
	 * Print out the answers.
	 */
	printf("trap=%g\n", ans);
	return 0;
}

double f1(double x,double alpha) {


return g(x)-alpha*(sqrt(3.14)/2);

}
double f_prime(double x) {
return exp(-x*x);
}

double g(double b){
	int i;
	int steps=100000;
	double a, h, x;
	double box, trap, simp;

	/*
	 * Going to integrate sqrt(1−x*x) from 0 to 1.
	 */
	a = 0.0;

	h = (b - a)/steps;

	/*
	 * Now try trapazoid method.
	 */
	trap = f(a)/2.0;
	x = a + h;

	for (i = 1; i < steps; i++) {
		trap += f(x);
		x += h;
	}

	trap += f(b)/2.0;
	trap *= h;

	return trap;

}

double f(double x) {

	return exp(-x*x);
}
