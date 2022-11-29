#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
#include <string.h>
#include <errno.h>

struct t_objet {
        long type;
        pid_t pid;
        char msg[256];
};

#define CHECK(sts, msg) if ((sts)==-1) {perror(msg); exit(-1);}
#define CLE "lib.h"
#define MAXMSG 100

/************************************************************************************************/
/*Fonction : createBox										*/
/* Description : Créer une boites aux lettres avec les droits RIGHTS, retourne son id		*/
/************************************************************************************************/
int createBox( char * name );

/************************************************************************************************/
/*Fonction : infoBox										*/
/* Description : Donne des informations sur une boites aux lettres via son id			*/
/************************************************************************************************/
int infoBox(int boxId);

/************************************************************************************************/
/*Fonction : writeBox										*/
/* Description : Envoie un message dans une boite aux lettres					*/
/************************************************************************************************/
void writeBox( int boxId, struct t_objet objet);

/************************************************************************************************/
/*Fonction : readBox										*/
/* Description : Lis un message dans une boite aux lettres					*/
/************************************************************************************************/
struct t_objet readBox( int boxId );

/************************************************************************************************/
/*Fonction : deleteBox										*/
/* Description : Détruit une boite aux lettres							*/
/************************************************************************************************/
void deleteBox( int boxId );
