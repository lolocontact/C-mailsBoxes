/* =============================================================================*/
/* bal3_c.c                                                                     */
/*Programme Client 								*/
/*ouvre la boîte aux lettres créée par bal3_s,  				*/
/*écrit 10 fois des messages saisis. 						*/
/* =============================================================================*/
#include "lib.h"

int main(int argc, char *argv[])
{

	
	//créer boite
	int boxId= createBox(CLE);
	
	//affiche info
	infoBox(boxId);
	
	//variable de reception
	struct t_objet objet;
	
	while(1){
		
		objet = readBox( boxId );
		printf("-message : %s\n",objet.msg);
	}
	
	deleteBox(boxId);		
	return 1;
	
}
