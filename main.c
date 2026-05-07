#include <stdio.h>
#include <string.h>
#include "incs/libasm.h"

int main() {
	char *coucou = "Coucou les gens!";
	printf("%s\n", coucou);
	printf("resultat: %d\n", ft_strlen(coucou));
	printf("pointer de fin: %s\n", coucou + strlen(coucou));
	printf("dernier lettre (doit etre egale a F) : %c\n", *(coucou + strlen(coucou)) + 70);
	printf("expected resultat: %lu\n", strlen(coucou));
	return (0);
}

// 4342633716
// 4342633789

// 4329137398
// 4329137398
