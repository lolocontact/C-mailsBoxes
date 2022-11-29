/* =============================================================================*/
/* bal3_c.c                                                                     */
/*Programme Client 								*/
/*ouvre la boîte aux lettres créée par bal3_s,  				*/
/*écrit 10 fois des messages saisis. 						*/
/* =============================================================================*/
#include "lib.h"

int main(int argc, char *argv[])
{
	// Récupération du numéro de la boîte aux lettres
	if (argc != 2) {
		printf("Veuillez utiliser ces parametres : %s <msqid>\n", argv[0]);
		exit(1);
	}
	
	int msqid = atoi(argv[1]);
	char input[MAXMSG];
	
	//envoie 10 messages de suite
	for (int i = 0; i < 10; i++) {
		// Saisie
		printf("(%d/%d) Saisissez un message : ", i + 1, 10);
		fgets(input, MAXMSG, stdin);
		
		//si on veut arrêter :
		if(strcmp(input, "FIN") == 0) {
			return 1;
        	}
		
		//objet qui sera envoyé
		struct t_objet objet;
		objet.type = 1;
		objet.pid = getpid();
		strcpy(objet.msg, input);
		writeBox(msqid, objet);
		//CHECK(msgsnd(msqid, &objet, sizeof(objet.msg), 0), "msgsnd");
    	}
	return 1;
	
}
