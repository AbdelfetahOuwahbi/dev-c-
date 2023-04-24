//GAME DEVELOPPED BY ABDELFETAH OUWAHBI - SAADINE ELHIMEUR

//the comments is in french language

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int T[5],Y[5],F[5],i,j,o,n,essai,a,e,m=0,f=7,p;
char nom1[20],nom2[20];
FILE *fnamescore ;

//*********************************
int Welcome();
void DEBUT();
void joker();
void YouLost();
void EVERYTHING();
void ACCEUIL();
void GRAPHE();
void BIENPLACEE_MALSPLACEE();
void LEVEL2();
void FICHIER();
//*********************************

//La fonction du niveau 2
void LEVEL2(){
   printf("     **YOU'RE NOW AT THE LEVEL TWO **\n");
   printf("\n");
   printf("     -PLAYER 1 TYPE YOUR NAME : ");
   scanf("%s",nom1);
   printf("\n");
   printf("     * %s , ENTER THE SECRET CODE TO START THE GAME .  \n",nom1);
   printf("\n");

   for(i=0;i<5;i++){
   printf("     **NUMBER %d :",i+1);
   scanf("%d",&T[i]);}

   system("cls");
   GRAPHE();
   printf("     **YOU'RE NOW AT THE LEVEL TWO **\n");
   printf("\n");
   printf("     -PLAYER 2 TYPE YOUR NAME :");
   scanf("%s",nom2);
   printf("\n");
   printf("     * %s , GAME STARTED .\n",nom2);
   printf("     -----TRY TO FIND THE CODE");
   printf("\n");
    f=9; //Anything but 0 to block le joker
    essai=20; //initialisation
	while(essai>0){
	//sauter une ligne
   	printf("\n");
   	//scan des valeurs du 2eme joueurs
   for(j=0;j<5;j++){
   	    printf("     **NUMBER %d :",j+1);
   	    scanf("%d",&Y[j]);
		   }
   	BIENPLACEE_MALSPLACEE();

	//sauter une ligne
	printf("\n");

	//affichege des chiffres bien placees et les mals placees
    printf("     *WELL PLACED   :%d\n",o);
    printf("     *BADLY PLACED : %d\n",n);

    //sauter une ligne
    printf("\n");

    //compteur des essais

    essai=essai-1;

    //la condition pour continuer les tentatives
    if(o!=5&&essai!=0){
    printf("     --NUMBER OF TRIALS YOU HAVE LEFT :  %d\n",essai);}
    //Si le joueur 2 gangne
    YouLost();

    ///Les instructions si le joueur 2 gagne
          if(o==5){
	printf("           YOU WIN !!\n");
	printf("           ----YOUR SCORE : %d\n",essai);
	printf("\n");
	printf("           END OF THE GAME .\n");

	essai=0;
	printf("\n");
	//Si le joueur veut rejouer ou quiter apres terminer le jeu
	printf("     1 : TO EXIT\n");
	printf("     0 : TO REPLAY\n");
	printf("\n");
	printf("     *CHOOSE : ");
	FICHIER();
	scanf("%d",&m);
	system("cls");
	if (m==1){
		exit(1);
	}if (m==0){
	GRAPHE();
	Welcome();}}
		joker(); }
}
//La fonction qui calcule les biens placees et les mals placees
void BIENPLACEE_MALSPLACEE(){
   		   for(i=0;i<5;i++){
			F[i]=T[i];
		}
   	//la boucles des biens placees
   	  o=0;
   	  for(i=0;i<5;i++){
   	  	if(F[i]==Y[i]){o=o+1;
			 Y[i]=981;
			 F[i]=971;}
   	  		}
	//la boucle des mals placees
		   n=0;
		  for(i=0;i<5;i++){
		  	p=1;
		  	 for(j=0;j<5;j++){
		  		if(F[i]==Y[j]&&j!=i&&p!=0){
		  			Y[j]=981;
		  			n=n+1;
					p=0;}
					  }}
}
//la fonction du schema master mind , pour un peu de design
void GRAPHE(){
   printf("          %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",30,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,31);
   printf("          %c                                     %c   \n",30,31);
   printf("          %c     M  A  S  T  E  R    M I N D     %c  \n",30,31);
   printf("          %c     M  A  S  T  E  R    M I N D     %c  \n",30,31);
   printf("          %c     M  A  S  T  E  R    M I N D     %c   \n",30,31);
   printf("          %c                                     %c     \n",30,31);
   printf("          %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c \n",30,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,31);
   printf("\n");
}
//la fonction du menu
int Welcome(){
    printf("     =======THE MAIN MENU=======\n");
    printf("\n");
    //une valeur dehors 0 ,1,2 et 3 , pour ne pas fair tromper le scan
	m=5;
	p=5;
    //Main menu
    printf("      1 : TO PLAY\n");
    printf("      2 : TO SEE THE MENU\n");
    printf("      0 : TO CLOSE\n");
    printf("\n");
    printf("      *CHOOSE : ");
    scanf("%d",&m);
    system("cls");
    if(m==1){
    	EVERYTHING();
	}
    if(m==2){
       //les regles du jeu , une introduction
		GRAPHE();
		printf("-MASTERMIND is a code-breaking game for two players. The first one propose \n");
		printf(" a code of 5 numbers , and the second one should find it , with little  ,  \n");
		printf(" help which is marking The numbers well placed and the badly placed  , \n");
		printf(" with 20 chances of playing.\n");
		printf("\n");
		printf("There's two levels in this game :\n");
        printf("\n");
		printf("---The first , the easy  one based on that the 5 code proposed by  the  first   \n");
		printf("should be distinct , which is easy for the second player to play.This level\n");
		printf("is recommended for the kids to have fun playing , not getting mad .   \n");
        printf("\n");
		printf("---The second one is the opposite of the last one ,which is allow to the      \n");
		printf("players to tap a code nondistinct ,nondistinct means the numbers can repeat \n");
		printf("or not ,it makes the game much harder .\n");
        printf("\n");
		printf("-There's is something last to add , if you're having any trouble finding the  \n");
		printf(" code, the game propose for you an option called 'JOKER' , it's unlocked\n");
		printf(" after the 10th chances in back you lose 3 chances of playing , it help    \n");
		printf(" you to see one code of the secret code , but once you use you can't \n");
		printf(" reuse it , so be carefull using it . \n");
		printf("\n");
		printf("   HAVE FUN PALYING .   \n");
		printf("\n");
		//Menu pour le retour
	    printf("    1 : TO GO BACK \n");
	    printf("    0 : TO CLOSE\n");
	    printf("\n");
        printf("    *CHOOSE : ");
        scanf("%d",&p);
	    system("cls");
	       if(p==1){
	       	GRAPHE();
	  	    Welcome();
	       }
	      if(p==0){
	  	   exit(1);
	       }}
	if(m==0)	{
		exit(1);
	}}
	//La fonction du execution du jeu
void EVERYTHING()
	{
		GRAPHE();
           //Menu pour choisir les niveaux
		    printf("      1  : FOR LEVEL ONE \n");
		    printf("      2  : FOR LEVEL TWO \n");
		    printf("      0  : TO GO BACK\n");
		    printf("\n");
            printf("      *CHOOSE : ");
		    scanf("	%d",&m);
		    system("cls");
		    GRAPHE();
		    if(m==0){

		    	Welcome();
			}
		    if(m==1){
    system ("cls");



	DEBUT();
       f=9;//pour reinitialiser le blockeur du joker .
	    essai=20;
	while(essai>0){


	//sauter une ligne
   	printf("\n");

   	//scan des chiffres du 2eme joueurs
    for(j=0;j<5;j++){
   	    printf("     **NUMBER %d :",j+1);

   	    scanf("%d",&Y[j]);
		   }

     //si l'utilisateur a entrer un chiffre bcp de fois , le programme lui donne pour repeter .
           a=0;
		   for(i=0;i<5;i++){
		  	for (j=0;j<5;j++){
		  		if(Y[i]==Y[j]&&j!=i){
		  			a=a+1;
					  }}}
		 if ( a>=1){
        printf("\n");
		 printf("     !! YOU ENTRED A NUMBER MANY TIMES !! \n");
		 printf("     --REPLAY.\n");
		 printf("     --NUMBER OF TRIALS YOU HAVE LEFT : %d\n",essai);

		 i=2;
		 }

	else{


   	BIENPLACEE_MALSPLACEE();

	//sauter une ligne
	printf("\n");

	//affichege des chiffres bien placees et les mals placees
    printf("     *WELL PLACED  :%d\n",o);
    printf("     *BADLY PLACED : %d\n",n);


    //sauter une ligne
    printf("\n");


    //compteur des essais
    essai=essai-1;

    //si tous est rigolo ,et le joueur 2 na ni gagner ni perder
    if(o!=5&&essai!=0){
    printf("     --NUMBER OF TRIALS YOU HAVE LEFT :  %d\n",essai);
}

   //si le joueur 2 perdu
    YouLost();

    //Les instructions si le joueur 2 gagne
          if(o==5){
	printf("           YOU WIN !!\n");
	printf("           ----YOURE SCORE : %d\n",essai);
	printf("\n");
	printf("           END OF THE GAME .\n");
	essai=0;
	printf("\n");
	printf("     1 : TO REPLAY\n");
	printf("     0 : TO EXIT\n");
	printf("\n");
    printf("     *CHOOSE : ");
    FICHIER();
	scanf("%d",&m);
	system("cls");
	if (m==0){
		exit(1);

	}if (m==1){
	GRAPHE();
	Welcome();
	}
	 }
		}joker(); }}
		if(m==2){
			LEVEL2();
		}
		}

//La fonction du input pout le niveau 1
void DEBUT(){
	GRAPHE();
	printf("     **YOU'RE NOW AT THE LEVEL 1**\n");
	printf("\n");

   printf("     -PLAYER 1 TYPE YOUR NAME : ");

   scanf("%s",nom1);
   printf("\n");
   printf("     * %s , ENTER THE SECRET CODE TO START THE GAME .  \n",nom1);
   printf("\n");
   a=1;
   while(a!=0){
   for(i=0;i<5;i++){
   	   printf("     **NUMBER %d :",i+1);
   	   scanf("%d",&T[i]);}
      a=0;
		   for(i=0;i<5;i++){
		  	for (j=0;j<5;j++){
		  		if(T[i]==T[j]&&j!=i){
		  			a=a+1;}}}
		 if ( a!=0){
         printf("\n");
		 printf("     !! YOU ENTERED A NUMBER MANY TIMES !! \n");
		 printf("     --REENTER THE CODE .\n");
		 printf("\n");
              }
	     else{
   system("cls");
   GRAPHE();
   printf("     **YOU'RE NOW AT THE LEVEL 1**\n");
   printf("\n");
   printf("     -PLAYER 2 TYPE YOUR NAME :");

   scanf("%s",nom2);
   printf("\n");
   printf("     * %s , GAME STARTED .\n",nom2);

   printf("     -----TRY TO FIND THE CODE");

   printf("\n");}}
   }

//La fonction du perdu
void YouLost(){
	if(essai==0&&n>=0&&o!=5)
	{
	printf("           YOU LOST !!\n");
	printf("           ----YOURE SCORE : 0\n");
	printf("\n");
	printf("           --THE CODE ENTERED BY %s : \n ",nom1);


	printf("\n");
	for(i=0;i<5;i++){
	printf("                       **NUMBER %d : %d\n",i+1,T[i]);
}
     printf("\n");
	printf("                       --END OF THE GAME .\n");

	printf("\n");
	printf("     1 : TO EXIT\n");
	printf("     0 : TO REPLAY\n");
	printf("\n");
    printf("          *CHOOSE : ");
    FICHIER();

	scanf("%d",&m);
	system("cls");
	if (m==1){
		exit(1);

	}if (m==0){
	GRAPHE();
	Welcome();
	}}
}
//La fonction du joker
void joker(){

	if(essai==10&&i!=2){
    printf("\n");
	printf("     ------||YOU NOW UNLOCKED THE OPTION JOKER .||------\n ");
	}

 	  if(f==0&&essai!=0||essai<=3&&essai!=0){
 	  	printf("\n");                                               //le block du joker
 	  	printf("     !!YOU CAN'T USE THE OPTION JOKER NOW .\n");
	   }

 if(essai<=10&&essai>3&&f!=0&&i!=2){
     printf("\n");
     printf("     **TYPE '1' IF YOU WANT TO USE THE OPTION JOKER .**\n");
     printf("\n");
     printf("     **TYPE ANY OTHER NUMBER IF YOU DONT WANT TO .**\n");
     printf("\n");
     printf("       *CHOOSE : ");
     scanf("%d",&m);
   	     if(m==1){
   	     	f=0;
   	     	if(essai>=4){
                 printf("\n");
                 printf("     YOU'RE USING THE OPTION JOKER .\n");
	             printf("\n");                                             //Si le joueur a decider d'utiliser l'option joker .
	             printf("     TYPE THE NUMBER YOU WANT TO SEE : \n");
	             printf("\n");
                 printf("       *CHOOSE : ");
                 scanf("%d",&e);
                 printf("\n");
	              if(e<6&&e!=0){
	                  printf("     THE NUMBER YOU CHOOSE : [%d] \n",e);
                      printf("\n");
                      printf("     IT VALUE IS : '%d'\n",T[e-1]);
	                  essai=essai-3;}
    }else
	{printf("    YOU JUST ENTERED A NUMBER BIGGER THAN 5 .");}
	}else {
    printf("\n");
	printf("     YOU DIDNT CHOOSE THE OPTION JOKER .");
	printf("\n");
	printf("     --FINISH YOUR GAME .");
	printf("\n");}
}}
//le fonction pour stocker les noms et le scores des joueurs
void FICHIER()
{
 //stockage du nom et du score dans un fichier dans votre ordinateur//
    fnamescore = fopen("history_mastermind.txt","w");

    fprintf(fnamescore,"\n LE JOUEUR %s BIEN JOUER \nVotre score EST : %d\n",nom2,essai);

    fclose(fnamescore);}

 main(){
    system("color 0d");

	GRAPHE();
	Welcome();     //Appel des fonction dans la fonction principale main .
    EVERYTHING();



    getch();
}// THANKS FOR READING THE CODE//
