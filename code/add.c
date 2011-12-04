/*
 * Note tail recursion, z = y
 * #Also note that compiler optimization can help!
 * #Which is easier to prove?
 * #Hard to prove with compiler optimizatino flag
 *
 * #ALSO assumed x is natrual number for all examples
 */

/*
 * Resources: http://en.wikipedia.org/wiki/Compiler_correctness
 * 			  Formal Methods Oct-25 Lecture Notes
 * 			  Book by zohar mathmatical theory of computation 
 * 			  http://www.cut-the-knot.org/arithmetic/
 *				http://plato.stanford.edu/entries/recursive-functions/
 				http://mathworld.wolfram.com/PrimitiveRecursiveFunction.html
 */

/*# Notes: Building blocks for multp, div, exp...
 * #Since its a buildinb block, we choose wizly 
 */
/*
	#primitive recursion using gcd 
 	
	*#also talk about list and give proof using computational induction (stepwise and complete)
 */
/*
 * #We keep the extra z argument so we can use Kleene's axioms in proving 
 */

/*
 * #All examples are using simple/weak induction 
*/

/* #fix point induction examples
 */
/*
	look at conclusion 
	http://www4.informatik.tu-muenchen.de/~krauss/papers/recursion.pdf
*/

 /*#fixed point combinator talk a bit more about it (fixpoint induction p406)
 */ 

 /*
  * #Structural induction 
  *
  */
#include <assert.h>
#include <stdio.h>
#include <time.h>

//Ackermann function 
int rec_McCarthy_91(int n){
	if(n > 100)
		return n - 10;
	else
		return rec_McCarthy_91( rec_McCarthy_91 (n+11));
}

//Zohar manna itr version
//easier to prove
int itr_McCarthy_91(int n){
    int c;
    for (c = 1; c != 0; ) {
        if (n > 100) {
            n = n - 10;
            c--;
        } else {
            n = n + 11;
            c++;
        }
    }
    return n;
}

int add_rec(int x, int y, int z){
	if (x == 0)
		return z;
	else
		return add_rec(x-1, y, z+1);
}

int add_slow(int x, int y, int z){
	if(x == 0){
		if(y == 0)
			return z;
		else
			return add_slow(x,y-1,z+1);
	}else
		return add_slow(x-1, y, z+1);
}

/* Other forms of loops like for loop
 */
int add_itr(int x, int y, int z){
	while( x != 0 ) {
		z = z + 1; 
		x = x - 1; 
	}
	return z;
}

int add_itr2(int x, int y, int z){
	for(; x != 0; z++, x--);
	return z;
}

int main(){
	
	int x =  92847;
	int y =  63820;
	int n = -18760;
	int z;
	clock_t t0, t1;

	t0 = clock();
	z = add_rec(x,y,y);
	t1 = clock();
	printf("Recursive Addition\n\t %d + %d = %d\n\tTime: %gms\n\n",x,y,z,
			1000 * (double) (t1-t0)/(((double) CLOCKS_PER_SEC)));	
       
	t0 = clock();
	z = add_itr(x,y,y);
	t1 = clock();
	printf("While-loop Addition\n\t %d + %d = %d\n\tTime: %gms\n\n",x,y,z,
			1000 * (double) (t1-t0)/(((double) CLOCKS_PER_SEC)));	
	
	t0 = clock();
	z = add_slow(x,y,0);
	t1 = clock();
	printf("Double Induction Addition\n\t %d + %d = %d\n\tTime: %gms\n\n",x,y,z,
			1000 * (double) (t1-t0)/(((double) CLOCKS_PER_SEC)));	
	
	t0 = clock();
	z = add_itr2(x,y,y);
	t1 = clock();
	printf("For-loop Addition \n\t %d + %d = %d\n\tTime: %gms\n\n",x,y,z, 
						1000 * (double) (t1-t0)/(((double) CLOCKS_PER_SEC)));	
	
	t0 = clock();
	z = rec_McCarthy_91(n);
	t1 = clock();
	printf("Recursive McCarthy 91 (n = %d)\n\tTime: %gms\n\n",n,
			1000 * (double) (t1-t0)/(((double) CLOCKS_PER_SEC)));	
	
	t0 = clock();
	z = itr_McCarthy_91(n);
	t1 = clock();
	printf("Iterative McCarthy 91 (n = %d)\n\tTime: %gms\n\n",n,
			1000 * (double) (t1-t0)/(((double) CLOCKS_PER_SEC)));	

	t0 = clock();
	z = x + y;
	t1 = clock();
	printf("Predefined addition in C\n\t %d + %d = %d\n\tTime: %gms\n\n",x,y,z,
			1000 * (double) (t1-t0)/(((double) CLOCKS_PER_SEC)));	
	
	return 0;
}
