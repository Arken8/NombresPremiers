#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <string.h>

int main()
{
	unsigned long maxNombre = 1000000;

	printf("Entrez le nombre Maximum : ");
	scanf("%ld", &maxNombre);

	if (maxNombre < 10) {
		maxNombre = 10;
		printf("nombreMax defini a %ld\n", maxNombre);
	}

	unsigned long tabTaille = floorl(maxNombre / log(maxNombre / 10));

	unsigned long *premiers = NULL;
	premiers = calloc(tabTaille, sizeof(long));

	if (premiers == NULL)
	{
		printf("Echec de l'allocation memoire !\nFin du programme.\n");
		exit(1);
	}

	unsigned long premiers_trouves = 0;
	unsigned long nombre;
	unsigned long i;
	int pasNombre = 4;
	
	premiers[premiers_trouves++] = 2;
	premiers[premiers_trouves++] = 3;

	clock_t start, end;
    start = clock ();
	
	for(nombre = 5; nombre <= maxNombre; nombre += (pasNombre = 6 - pasNombre))
	{
		unsigned long pointeurCourant = 1;
		unsigned long sqrt_nombre = floorl(sqrt(nombre));

		for(i = premiers[pointeurCourant]; (i <= sqrt_nombre) && (nombre % i); i = premiers[pointeurCourant++]);

		if(i > sqrt_nombre)
		{
			premiers[premiers_trouves++] = nombre;
		}

	}

	end = clock ();

	printf("Il y a %lu nombres premiers entre 0 et %lu.\n", premiers_trouves, maxNombre);

    end = clock ();
    double millis = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Duree de l'operation: %f Sec.\n", millis);

	char yn[3] = "n";
	printf("Afficher la liste des nombres premiers ? (o/N) : ");
	scanf("%s", yn);
	if (yn[0] == 'o' || yn[0] == 'O' || yn[0] == 'y' || yn[0] == 'Y') {
		for (i = 0; (i < premiers_trouves); i++) {
			printf("%lu ", premiers[i]);
		}
		printf("\n");
	}

	free(premiers);
    printf("Appuyez sur Entree pour fermer le programme.");
    getch();

	return 0;
}