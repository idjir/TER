#include <gmp.h>
#include <time.h>
#include "../head/fonctionnalites/cryptosystemes/RPNG.h"
#include "../head/fonctionnalites/cryptosystemes/RSA.h"
#include "../head/fonctionnalites/tests_primalite/testOptimal.h"
#include "../head/fonctionnalites/tests_primalite/testNaif.h"
#include "../head/fonctionnalites/tests_primalite/testWilson.h"
#include "../head/fonctionnalites/tests_primalite/testFermat.h"
#include "../head/fonctionnalites/tests_primalite/testMillerRabin.h"

int main(int argc, char *argv[]) 
{
	srand(time(NULL));
    
	//Génération nombre premier avec différents tests
	mpz_t premier;
	mpz_init(premier);
	RPNG_prob(testMillerRabin, 1024, premier);	//test Naif et Wilson galèrent à partir d'un nombre de plus 28 bits, à voir
	gmp_printf("Fermat dit sur %Zd : %d\n", premier, testFermat(premier, K));
	mpz_clear(premier);
	
	/*
	//Test chiffrement et déchiffrement RSA (module RSA mis à 32 bits pour accélérer nos tests)
	mpz_t n, e, d, m, c;
	mpz_inits(n, e, d, m, c, NULL);
	//generationClesRSA_det (testNaif, n, e, d);
	generationClesRSA_gen (n, e, d);
	mpz_set_ui(m, 12345);
	printf("\n######################### RSA ######################\n");
	//risque de probleme chiffrement et déchiffrement RSA si deux des clés générées sont égales (à cause du seed de l'aléatoire)
	chiffrementRSA(m, n, e, c);
	gmp_printf("Chiffrement de %Zd : %Zd\n", m, c);
	dechiffrementRSA(c, n, d, m);
	gmp_printf("Déchiffrement de %Zd : %Zd\n", c, m);
    */
    
    return EXIT_SUCCESS;
}
