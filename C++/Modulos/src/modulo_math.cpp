/*
 * modulo_math.cpp
 *
 *  Created on: 5 de set de 2019
 *      Author: otluix
 */

int fatorial(int n){

	int result;
	if (n == 0) result = 1;
	else result = n * fatorial(n - 1);
	return result;
}

int fibonacci(int n, int atual, int prox){
	int result;
		if (n == 0) result = atual;
		else result = fibonacci(n-1, prox, prox + atual);

	return result; // fibonacci(n, 0, 1);
	}

void fibonacci(int n){
	fibonacci(n, 0, 1);
}
