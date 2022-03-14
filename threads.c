#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *med (void *vArr);
void *min (void *vArr);
void *max (void *vArr);

float tot;
int tam;
int menor = 0;
int maior = 0;

int main(void) {
	
	int TAM_ARR, num, c=0;
	char pChar;
        
	scanf("%d", &TAM_ARR);
	
	int ARR[TAM_ARR];

	while (scanf("%d%c", &num, &pChar) == 2) {
		ARR[c] = num;
		c++;
		if (pChar == '\n') {break;}
	
	}

	tam = TAM_ARR;

	pthread_t th1;
	pthread_t th2;
	pthread_t th3;

	pthread_create (&th1, NULL, med, (void *)ARR);
	pthread_join (th1, NULL);
	
	pthread_create (&th2, NULL, min, (void *)ARR);
	pthread_join (th2, NULL);
	
	pthread_create (&th3, NULL, max, (void *)ARR);
	pthread_join (th3, NULL);

	printf("\n");
	
	printf("The average value is %.2f\n", tot);
	printf("The minimum value is %d\n", menor);
	printf("The maximum value is %d\n", maior);

	return 0;
}

void *med (void *vArr) {
	
	int *arr = (int *) vArr;

	int sum = 0, c;

	for (c=0; c<tam; c++) {
		sum += arr[c];
	}

	tot = sum/tam;
	pthread_exit(0);

}

void *min (void *vArr) {

	int c;
	int *arr = (int *) vArr;

	for (c=0; c<tam; c++) {
		
		if (c==0) {menor = arr[c];}
		
		else {
			
			if (arr[c] < menor) {menor = arr[c];}

		}

	}

	pthread_exit(0);

}

void *max (void *vArr) {

	int c;
	int *arr = (int *) vArr;

        for (c=0; c<tam; c++) {

                if (c==0) {maior = arr[c];}

                else {

                        if (arr[c] > maior) {maior = arr[c];}

                }

        }

        pthread_exit(0);

}
