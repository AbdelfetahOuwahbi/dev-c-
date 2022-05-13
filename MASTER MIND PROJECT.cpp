#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
   int tentatives,T[5],Y[5];
   int i,j,malPlaces,bienPlaces,optionJocker,blocDeCode,o,a,loading,LIST1,LIST2;
   char nom[20],nom1[20];
    
void Loading(){
	int count=1;
	loop:
		system("cls");
		printf("LOADING.");
		for(loading=1; loading<=2; loading++){
			sleep(1);
			printf(".");
		}
		sleep(1);
		count++;
		if(count==3)
		goto endloop;
		else
		goto loop;
	endloop:
	printf("\n\n LET'S GET STARTED ..\n\n");
	sleep(2);
	system("cls");
	printf("PRESS ANY KEY");
	getch();	
}    
    
void jocker(){
	if(tentatives <= 18 && tentatives > 3 ){
		printf("\n");
		printf("TOO MUCH ATTEMPTS \n");
	    printf("\n");
			printf("TYPE 1 TO USE THE OPTION JOCKER \n");
			printf("\n");
			printf("OR \n");
			printf("\n");
			printf("TYPE ANY OTHER NUMBER TO KEEP PLAYING \n");
		scanf("%d",&optionJocker);
		if(optionJocker == 1 ){
		
			printf("TYPE THE BLOC OF THE NUMBER YOU WANT TO SEE : \n");
			scanf("%d",&blocDeCode);
			if( blocDeCode<6 && blocDeCode>2 && blocDeCode<5 ){printf("THE NUMBER PLACED IN THE %drd BLOC IS :%d \n",blocDeCode,T[blocDeCode-1]);}
				
			if( blocDeCode<6 && blocDeCode==1 ){printf("THE NUMBER PLACED IN THE %dst BLOC IS :%d \n",blocDeCode,T[blocDeCode-1]);}
			
				                                                      //all of those (if) conditions are to put the phrases correctely//
				                                                      
			if(blocDeCode<6 && blocDeCode==2){printf("THE NUMBER PLACED IN THE %dnd BLOC IS :%d \n",blocDeCode,T[blocDeCode-1]);}
			
			if(blocDeCode<6 && blocDeCode==5){printf("THE NUMBER PLACED IN THE %dth BLOC IS :%d \n",blocDeCode,T[blocDeCode-1]);}
				
			if(blocDeCode>=6){printf("YOU HAVE ENTERED A NUMBER HIGHER THAN 5 \n");}
			tentatives=tentatives-3;	
		}else{
			printf("FINISH YOUR GAME,THINK CAREFULY NEXT TIME .. \n");
			printf("\n\n\n");
			printf("YOU CAN DO IT .... \n");
				printf("\n");
		}
		
	}
}

void Nmbr_destinct_p1(){
	a=1;
	while(a!=0){
	a=0;
	for(i=0;i<5;i++){
   	for(o=0;o<5;o++){
   		if(T[i]==T[o] && o!=i){
   			a=a+1;
		   }
		   }
	   }
	   if(a>=1){
	   	printf("YOU HAVE ENTERED A NUMBER MANY TIMES \n");
	   	printf("\n");
	 for(i=0;i<5;i++){
   	   printf("Le chiffre %d :",i+1);
   	   scanf("%d",&T[i]);
   	   }
}
}
}
void Nmbr_destinct_p2(){
	a=1;
	while(a!=0){
	a=0;
	for(j=0;j<5;j++){
   	for(o=0;o<5;o++){
   		if(Y[j]==Y[o]&&o!=j){
   			a=a+1;
		   }
		   }
	   }
	   if(a>=1){
	   	printf("YOU HAVE ENTERED A NUMBER MANY TIMES \n");
	   	printf("\n");
	   	for(j=0;j<5;j++){
   	   printf("Le chiffre %d :",j+1);
   	   scanf("%d",&Y[j]);
   	   }
	   	}
	   	}
}

void Maincode(){
	//affichage de nom et de code de joueur 1//
   printf(" VOUS ETES LE JOUEUR 1, DONNER VOTER NOM :");
   scanf("%s",nom);
   printf("\n");
   printf("%s BIENVENUE AU MASTER MIND, DONNER UN CODE (5 CHIFFRES) \n",nom);
   printf("\n");
   
   for(i=0;i<5;i++){
   	   printf("Le chiffre %d :",i+1);
   	   
   	   scanf("%d",&T[i]); 
   	} 
	
   	   
   Nmbr_destinct_p1();
   getch();
   system("cls");
    
   //affichage de nom et de code de joueur 2..//
   
   printf(" VOUS ETES LE JOUEUR 2, DONNER VOTER NOM :");
   scanf("%s",nom1);
   printf("\n");
   printf("%s BIENVENUE AU MASTER MIND, ESSAYER DE TROUVER LE CODE (5 CHIFFRES) \n",nom1);
   printf("\n");
   //..et declaration de nombre de tentative//
    tentatives=20;
   while(tentatives>0){
	tentatives=tentatives-1;
			for(j=0;j<5;j++){
   	   printf("Le chiffre %d :",j+1);
   	   scanf("%d",&Y[j]);
   	   
   	  //les nombres bien places// 
   	} Nmbr_destinct_p2();
bienPlaces=0;j=0;
   for(i=0;i<5;i++){
   	if(T[i]==Y[j]){
   		bienPlaces=bienPlaces+1;
   } j=j+1;
   if(bienPlaces==5){                                                        //ANONCE DE GAGNER !!//
		  	printf("WELL PLAYED, YOU HAVE FOUND THE RIGHT CODE \n");
		  	
		  	goto fin;
   }
   }printf("LE NOMBRE DES CHIFFRES BIEN PLACES EST :%d \n",bienPlaces);
   
   //les nombres mal places//
   malPlaces=0;
   for(i=0;i<5;i++){
   	for(j=0;j<5;j++){
   		if(T[i]==Y[j]&&j!=i){
   			malPlaces=malPlaces+1;
		   }
	   }
   }printf("LE NOMBRE DES CHIFFRES MAL PLACEES EST :%d \n",malPlaces);
   
   jocker();  
   
   printf("LE NOMBRE DE TENTATIVES RESTANT EST :%d \n",tentatives);
  
		  } 
	if(tentatives==20&&bienPlaces!=5){                                       //ANONCE DU PERT !!//
		printf("WRONG CODE, INFORTUNATELY YOU LOST !!! \n");
		printf("YOUR SCORE IS : 0 ");
	}
	
	fin : printf("YOU WIN %s !! \n",nom1);	                          //ANONCE DU GAGNER (2)!!//
	printf("YOUR SCORE IS :%d \n",tentatives+1);
  
  
   }

void lists(){
	printf("CLICK 1 TO PLAY \n\n");
	printf("CLICK 2 TO READ THE GAME'S PRINCIPE \n\n");
	printf("CLICK 3 TO EXIT \n\n");
	scanf("%d",&LIST1);
	system("cls");
	if(LIST1==1){
		Loading();
		Maincode();
	} 
	if(LIST1==2){
	printf("THE GAME'S NAME IS MASTER MIND \n\n");
	printf("FIRST OF ALL YOU CHOOSE THE LEVEL (1 OR 2) YOU WANT TO PLAY IN \n\n");
	printf("THE PRINCIPE OF LEVEL 1 IS : \n\n");
	printf("THE PLAYERS CANNOT ENTER REPEATED NUMBERS \n\n");
	printf("THE PRINCIPE OF LEVEL 2 IS : \n\n");
	printf("THE PLAYERS CAN ENTER REPEATED NUMBERS \n\n");
	printf("THE 1ST PLAYER ENTERS A CODE (5 DIGITS) \n\n");
	printf("THEN THE 2ND PLAYER TRIES TO GUESS THE CODE (5 DIGITS) \n\n\n");
	printf("CLICK 1 TO GO BACK \n");
	printf("CLICK 2 TO EXIT \n\n");
	scanf("%d",&LIST2);
	if(LIST2==1){
		system("cls");
		lists();
	}
	if(LIST2==2){
		exit(1);
	}
	}
	if(LIST1==3){
		exit(1);
	}
}

main(){
	system("color 5b");
   lists();
   Maincode();
	 
 }
   
   
   

