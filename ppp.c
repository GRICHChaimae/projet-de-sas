#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n , n_c = 0 ;
int n_affichage;
char tab_prenom[100][20],tab_nom[100][20],tab_CIN[100][20];
float montant_DH[100];
char recherche_CIN[25];

void f_un_des_compte(int n_c){

   int i;

   for(i=0; i<n_c ; i++){

    if(n_c != 1)
      printf("Pour creer le compte numero %d veuillez remplire ces informations : \n",i+1);

    printf("Veulliez entrer votre prenom : \n");
    scanf("%s",tab_prenom[i]);
    printf("Veulliez entrer votre nom : \n");
    scanf("%s",tab_nom[i]);
    printf("Veulliez entrer votre CIN : \n");
    scanf("%s",tab_CIN[i]);
    printf("Veulliez entrer votre montant en DH : \n");
    scanf("%f",&montant_DH[i]);
   }

}

void f_chercher_CIN(){

    int i,j;

    printf("Veuillez entrer votre CIN : \n");
    scanf("%s",recherche_CIN);

    j=0;
    for(i=0;i<n_c;i++){
            if( strcmp(tab_CIN[i],recherche_CIN)== 0 ){
             printf("Le prenom : %s \n",tab_prenom[i]);
             printf("Le nom : %s \n",tab_nom[i]);
             printf("Le montant : %.2f \n",montant_DH[i]);
             j++;
         }
   }
   if(j==0)
      printf("ce compte n'existe pas \n");

}

void depot(){
   float c_depot;
   int i,j;

    printf("Ou quelle compte voulez vous verser l'argent (entrer CIN) :");
    scanf("%s",recherche_CIN);

    j=0;
   for(i=0;i<n_c;i++){
    if( strcmp(tab_CIN[i],recherche_CIN ) == 0 ){
        printf("combien d'argent voulez vous depot :");
        scanf("%f",&c_depot);
        montant_DH[i] = montant_DH[i] + c_depot ;
        printf("votre nouveau montant est : %.2f \n",montant_DH[i]);
        j++;
    }
}
  if(j == 0)
    printf("Ce compte n'existe pas \n");
}

void retrait(){

      float c_retrait;
      int i,j;

    printf("De quelle compte voulez vous retrait l'argent (entrer CIN) :");
   scanf("%s",recherche_CIN);

      j=0;
      for(i=0;i<n_c;i++){
      if(strcmp(tab_CIN[i],recherche_CIN ) == 0 )
            j++;
      }

      if(j==0)
        printf("ce compte n'existe pas \n");
      if(j != 0){
        printf("combien d'argent voulez vous retrait :");
        scanf("%f",&c_retrait);
        for(i=0;i<n_c;i++){
        if(strcmp(tab_CIN[i],recherche_CIN ) == 0){
          if(c_retrait > montant_DH[i])
          printf("ce retrait est plus de votre montant \n");
          else{  montant_DH[i] = montant_DH[i] - c_retrait ;
          printf("votre nouveau montant est : %.2f \n",montant_DH[i]);
    }
    } }
      }

}

void f_Ascendant(){
   int i,j;
   float c;

   for(j=0;j<n_c-1;j++){
    for(i=0;i<n_c-1;i++){
     if(montant_DH[i]>montant_DH[i+1]){
       c = montant_DH[i];
       montant_DH[i] = montant_DH[i+1];
       montant_DH[i+1] = c;
    }
   }}

   printf("Les montants trie : \n");
    for( i=0 ; i<n_c ; i++){
       printf(" %f \n",montant_DH[i]);
    }
}

void f_Descendant(){
   int i,j;
   float c;

   for(j=0;j<n_c -1;j++){
    for(i=0;i<n_c - 1;i++){
     if(montant_DH[i]<montant_DH[i+1]){
       c = montant_DH[i];
       montant_DH[i] = montant_DH[i+1];
       montant_DH[i+1] = c;
    }}
   }

   printf("Les montants trie : \n");
    for( i=0 ; i<n_c ; i++){
       printf(" %f \n",montant_DH[i]);
    }

}

void f_C_Ascendant(){

   int i,j;
   float c;
   float montant_introduit;

   printf("Veillez entrer un montant :");
   scanf("%f",&montant_introduit);

     for(j=0;j<n_c -1;j++){
      for(i=0;i<n_c - 1;i++){
       if(montant_DH[i]>montant_DH[i+1]){
         c = montant_DH[i];
         montant_DH[i] = montant_DH[i+1];
         montant_DH[i+1] = c;
    }}
   }

    if(montant_introduit>montant_DH[n_c-1])
      printf("Il n\'existe pas un montant superieur a le chiffre que vous avez introduit \n");
    else{
      printf("Les montants qui sont supérieur à le chiffre que vous avez introduit par Ordre ascendant: \n");
       for( i=0 ; i<n_c ; i++){
       if(montant_DH[i]>montant_introduit)
       printf(" %f \n",montant_DH[i]);
    }
   }
}

void f_C_Descendant(){

   int i,j;
   float c;
   float montant_introduit;

   printf("Veillez entrer un montant :");
   scanf("%f",&montant_introduit);

     for(j=0;j<n_c -1;j++){
      for(i=0;i<n_c - 1;i++){
       if(montant_DH[i]<montant_DH[i+1]){
         c = montant_DH[i];
         montant_DH[i] = montant_DH[i+1];
         montant_DH[i+1] = c;
    } }
   }

    if(montant_introduit>montant_DH[0])
      printf("Il n\'existe pas un montant superieur a le chiffre que vous avez introduit");
   else{
      printf("Les montants qui sont supérieur a le chiffre que vous avez introduit par Ordre descendant: \n");
      for( i=0 ; i<n_c ; i++){
      if(montant_DH[i]>montant_introduit)
      printf(" %f \n",montant_DH[i]);
    }
   }
}

void f_affichge(){

 do{
    printf("Veuillez choisir un type d'affichage d'appre entrer son numero : \n");
    printf("Affichage Par Ordre : \n ");
    printf("\t 1:Ascendant \t 2:Descendant \n");
    printf("Affichage Par Ordre : (de les comptes bancaire ayant un montant supérieur à un chiffre introduit) \n ");
    printf("\t 3:Ascendant \t 4:Descendant");
    printf("\n Je choisi : ");
    scanf("%d",&n_affichage);
    }while(n_affichage != 1 && n_affichage != 2 && n_affichage != 3 && n_affichage != 4);

    switch(n_affichage){
        case 1: f_Ascendant();
                break;
        case 2: f_Descendant();
                break;
        case 3: f_C_Ascendant();
                break;
        case 4: f_C_Descendant();
                break;

    }
}

void f_Fidelisation(){
   int i,j;
   float c;

   for(j=0;j<n_c -1;j++){
    for(i=0;i<n_c - 1;i++){
     if(montant_DH[i]<montant_DH[i+1]){
       c = montant_DH[i];
       montant_DH[i] = montant_DH[i+1];
       montant_DH[i+1] = c;
    }}
   }

   printf(" les 3 premiers montants supérieurs : \n");

   for(i=0;i<3;i++){

     montant_DH[i] = montant_DH[i] + montant_DH[i] * 0.13 ;
     printf("%2.f \n",montant_DH[i]);
   }
}

int main(){

    start:

    do{
        printf("Veiullez choisir l'operation que vous voulez faire par entrer son numero : \n");
        printf("\t 1:creer un compte. \t 2:creer des plusieures comptes. \n \t 3:Depot \t 4:Retrait \n  \t 5:Une liste d'affichage \t 6:chercher par CIN \n \t 7:Fidelisation \t 8:Quitter l\'application");
        printf("\n Je choisi :");
        scanf("%d",&n);

        switch(n){
            case 1 : printf("Pour creer un compte veuillez remplire ces informations : \n");
                     n_c = 1;
                     f_un_des_compte(n_c);
                     goto start ;
                        break;
            case 2 : printf("Combien de comptes voulez vous creer : \n");
                        scanf("%d",&n_c);
                        f_un_des_compte(n_c);
                        goto start ;
                        break;
            case 3 : if(n_c == 0){
                        printf("Cree un ou plusieurs compte pour acceder a cette operation.\n");
                        system("pause");
                        goto start ;
                    }
                     depot();
                     goto start ;
                     break;
            case 4 : if(n_c == 0){
                        printf("Cree un ou plusieurs compte pour acceder a cette operation.\n");
                        system("pause");
                        goto start ;
                    }
                     retrait();
                     goto start ;
                     break;
            case 5 :if(n_c == 0){
                        printf("Cree un ou plusieurs compte pour acceder a cette operation.\n");
                        system("pause");
                        goto start ;
                    }
                    f_affichge();
                     goto start ;
                     break;
            case 6 :if(n_c == 0){
                        printf("Cree un ou plusieurs compte pour acceder a cette operation.\n");
                        system("pause");
                        goto start ;
                    }
                    f_chercher_CIN();
                    goto start ;
                    break;
            case 7 :if(n_c == 0){
                        printf("Cree un ou plusieurs compte pour acceder a cette operation.\n");
                        system("pause");
                        goto start ;
                    }
                    f_Fidelisation();
                    goto start ;
                    break;
            case 8 :printf("Pour quitter l'application veuillez qliquer sur entrer.");
                    break;
        }
    }while(n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6 && n != 7 && n != 8);

    return 0;
}
