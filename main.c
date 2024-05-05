#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Structure de livre
typedef struct {
    char nom[30];
    int id;
    char titre[20];
    char auteur[20];
    char description[30];
    float prix;
    char categorie[30];
    bool disponibilite;
} livre;
//Declaration des fonctions
void ajoutlivre(char nom[]);              
void afficherlivreparid();
void afficherlivreparutilisateur(char nom[]);
void suppression();           
void afficherpartitre();
void afficherparauteur();
void modifier();
void tripartitre(char nom[]);
void triparcategorie(char nom[]);
//Declaration du fichier utilisés
 FILE *file;
 //Fonction de l'ajout d'un livre
void ajoutlivre(char nom[])
{
   livre *l=(livre*)malloc(sizeof(livre));
    int idd=0, trouve = 0;

    // Ouvrir le fichier en mode lecture
    file = fopen("library.csv", "a+");
    if (file == NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
//lire l'ID
    printf("Donner l'id : ");
    scanf("%d", &idd);
    // Au debut du fichier
while(!feof(file)) {
	//lecture des donnes du fichier
    fscanf(file,"%d %s %s %s %s %s %f %d",&l->id, l->nom, l->titre, l->auteur, l->description, l->categorie, &l->prix, &l->disponibilite);
   //Rechercher l'id pour qu'il soit unique
        if (l->id == idd)
        {
            trouve = 1;break;
          
        }
    }

    if (trouve == 1)
    {
        printf("Livre existant !!!\n");
    }
    else
    {
    	strcpy(l->nom,nom);
    	//Lecture du nouveau livre
        printf("Nom de l'utilisateur : %s \n ",nom);
        printf("Titre du livre  : \n ");
        scanf("%s", l->titre);
        printf("Auteur du livre : \n ");
        scanf("%s", l->auteur);
        printf("Description du livre : \n ");
        scanf("%s", l->description);
        printf("Catégorie du livre : \n ");
        scanf("%s", l->categorie);
        do
        {
            printf("Prix du livre : \n ");
            scanf("%f", &l->prix);
        } while (l->prix < 0);//le prix doit etre >0

        do
        {
            printf("Disponibilité du livre (0 pour Non, 1 pour Oui) : \n ");
            scanf("%d", &l->disponibilite);
        } while (l->disponibilite != 0 && l->disponibilite != 1);//la disponibilite est boolean soit 1 ou 0
//Ecrire le nouveau livre dans le fichier
        fprintf(file,"%d %s %s %s %s %s %.2f %d\n",idd,l->nom, l->titre, l->auteur, l->description, l->categorie, l->prix, l->disponibilite);
   
    }
//fermer le fichier
    fclose(file);
}
//Fonction d'affichage par Id du livre
void afficherlivreparid()
{
	livre *l=(livre*)malloc(sizeof(livre));
    int idd, trouve = 0;

    // Ouvrir le fichier en mde lecture
    file = fopen("library.csv", "r");
    if (file == NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
//lire l'étudiant
    printf("Donner l'identifiant : ");
    scanf("%d", &idd);
//Lecture de chaque livre du fichier
    while (fscanf(file, "%d %s %s %s %s %s %f %d", &l->id, l->nom, l->titre, l->auteur, l->description, l->categorie, &l->prix, &l->disponibilite) == 8)
    {
        if (l->id == idd)//retrouver l'Id du livre
        {
        	//afficher le livre
            trouve = 1;
            printf("Nom : %s\n", l->nom);
            printf("Id : %d\n", l->id);
            printf("Titre : %s\n", l->titre);
            printf("Auteur : %s\n", l->auteur);
            printf("Description : %s\n", l->description);
            printf("Catégorie : %s\n", l->categorie);
            printf("Prix : %.2f\n", l->prix);
            printf("Disponibilité : %d\n", l->disponibilite);
            printf("\n");
            break;
        }
    }

    if (trouve == 0)
        printf("Livre n'existe pas !!!\n");

    fclose(file);
}
//Affichage des livres d'un utilisateur
void afficherlivreparutilisateur(char nom[])
{
  livre *l;
  l=(livre*)malloc(sizeof(livre));
    int trouve = 0;

    // Ouvrir le fichier en mode lecture
    file = fopen("library.csv", "rt");
    if (file == NULL)
    {
        printf("Impossible d'ouvrir le fichier\n");
        exit(1);
    }
//Lecture de chaque livre du fichier
    while (fscanf(file, "%d %s %s %s %s %s %f %d", &l->id, l->nom, l->titre, l->auteur, l->description, l->categorie, &l->prix, &l->disponibilite) == 8)
    {
//    	Retrouver le nom d'utilisateur
        if (strcmp(l->nom,nom)==0) 
        {
//        	Afficher ses livres
            trouve = 1;
            printf("Nom : %s\n", l->nom);
            printf("Id : %d\n", l->id);
            printf("Titre : %s\n", l->titre);
            printf("Auteur : %s\n", l->auteur);
            printf("Description : %s\n", l->description);
            printf("Catégorie : %s\n", l->categorie);
            printf("Prix : %.2f\n", l->prix);
            printf("Disponibilité : %d\n", l->disponibilite);
            printf("\n");
          
        }
    }

    if (trouve == 0){

        printf("Utilisateur  n'existe pas !!!\n");
	}
    fclose(file);
}
//Fonction de suppression
void suppression() {
		livre *l=(livre*)malloc(sizeof(livre));
    FILE *temp; // Déclaration du pointeur de fichier temporaire
	int idd;
    int trouve = 0; // Variable pour indiquer si le livre est trouvé
    // Ouvrir le fichier en mode lecture
    file = fopen("library.csv", "rt");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }

    // Ouvrir un fichier temporaire en mode écriture
    temp = fopen("temp.csv", "at");
    if (temp == NULL) {
        printf("Impossible de créer le fichier temporaire.\n");
        fclose(file);
        return;
    }
rewind(file);//Retourner le pointeur au debut du fichier
printf("Donner l'Id");
scanf("%d",&idd);

    // Lire chaque ligne du fichier
     while(fscanf(file, "%d %s %s %s %s %s %f %d",&l->id,l->nom, l->titre, l->auteur,l->description, l->categorie, &l->prix, &l->disponibilite)==8)
          {  
            if (l->id!=idd) {
            // Si l'auteur n'est pas trouvé dans la ligne, copier cette ligne dans le fichier temporaire
           fprintf(temp, "%d %s %s %s %s %s %.2f %d\n",l->id,l->nom,l->titre, l->auteur, l->description, l->categorie,l->prix,l->disponibilite);
        }  else {
            trouve = 1;
        }
		}

    // Fermer les fichiers
    fclose(file);
    fclose(temp);

    // Si le livre est trouvé et supprimé, renommer le fichier temporaire avec le nom original
    if (trouve) {
        remove("library.csv");
        rename("temp.csv", "library.csv");
        printf("Livre(s)  supprimé(s) avec succès.\n");
    } else {
        printf("Aucun livre d'Id %d trouvé.\n", l->id);
       
         // Supprimer le fichier temporaire car aucun changement n'a été effectué
        
    }
}
//Fonction d'affichage seule utilisé dans l'affichage par titre
void affichageseule(int idd) {
		livre *l=(livre*)malloc(sizeof(livre));
//		Ouverture du fichier en mode lecture
	 file = fopen("library.csv", "rt");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }
//    Lecture de chaque ligne du fichier 
  while(fscanf(file,"%d %s %s %s %s %s %f %d",&l->id,l->nom, l->titre, l->auteur,l->description, l->categorie, &l->prix, &l->disponibilite)==8)
          {  
//          Retrouver l'Id pour afficher 
            if (l->id==idd) {
            printf("Nom d'utilisateur : %s\n", l->nom);
             printf("Id du livre: %s \n", l->id);
            printf("Titre du livre: %s \n", l->titre);
            printf("Son auteur : %s\n",  l->auteur);
            printf("Sa categorie est : %s \n",  l->categorie);
            printf("Sa description est : %s \n",  l->description);
            printf("Sa disponibilité est : %d \n", l->disponibilite);
            printf("Son prix est : %.2f\n",  l->prix);
        }
		}
		
		}
		//La fonction affichage par titre 
void afficherpartitre(){
		livre *l=(livre*)malloc(sizeof(livre));
		char titre[30];
		int trouve=0;
//		Ouvrir le fichier en mode lecture
		  file = fopen("library.csv", "rt");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }
//    Le titre a rechercher
	printf("Donner le titre du livre ");
	scanf("%s",titre);
//	Lecture de chaque ligne du fichier
     while(fscanf(file, "%d %s %s %s %s %s %f %d",&l->id,l->nom, l->titre, l->auteur,l->description, l->categorie, &l->prix, &l->disponibilite)==8)
          {  
//          Retrouver le titre du livre pour afficher
            if (strcmp(l->titre,titre)==0) {
           	affichageseule(l->id);
            printf("\n");
            trouve=1;
            }
	
}	
if(trouve){
	printf("Livre trouvée \n");
}
else {
	printf("Titre non existant");
}
fclose(file);
}
//Afficher par auteur
void afficherparauteur(){
		livre *l=(livre*)malloc(sizeof(livre));
		char auteur[30];
		int trouve=0;
//		Ouverture du fichier en mode lecture
		  file = fopen("library.csv", "rt");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }
//    Lecture de l'auteur
	printf("Donner l'auteur du livre ");
	scanf("%s",auteur);
//	Lecture de chaque ligne du fichier
     while(fscanf(file, "%d %s %s %s %s %s %f %d",&l->id,l->nom, l->titre, l->auteur,l->description, l->categorie, &l->prix, &l->disponibilite)==8)
          {  
//          Recherche de l'auteur pour l'afficher
            if (strcmp(l->auteur,auteur)==0) {
           	affichageseule(l->id);
            printf("\n");
            trouve=1;
            }
	
}	
if(trouve){
	printf("Livre trouvée \n");
}
else {
	printf("Auteur non existant");
}
fclose(file);
}
//Fonction de modification 
void modifier() {
    FILE *temp;
	int idd; 
    int trouve = 0;
    livre *l=(livre*)malloc(sizeof(livre));
    //Ouvrir du fichier en mode lecture
    file = fopen("library.csv", "rt");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return;
    }
//Ouvrir du fichier temporaire en mode écriture
    temp = fopen("temp.csv", "at");
    if (temp == NULL) {
        printf("Impossible de créer le fichier temporaire.\n");
        fclose(file);
        return;
    }
    //Lire l'Id
    printf("Donner l'Id");scanf("%d",&idd);

    int c;
    int m;
    //Demande de l'element a modifier
    printf("Donner l'element a modifier (1.description, 2.disponibilite, 3.prix) : ");
    scanf("%d", &c);
    //Retourner le pointeur au debut du fichier
rewind(file);
//Lecture de chaque ligne du fichier
     while(fscanf(file, "%d %s %s %s %s %s %f %d",&l->id,l->nom, l->titre, l->auteur,l->description, l->categorie, &l->prix, &l->disponibilite)==8)
             {   
			   if (l->id==idd) { //Recherche de l'Id
		trouve = 1;
            switch (c) {
                case 1://Lire la nvll description et l'ecrire sur le fichier temporaire
                    printf("Donner la nouvelle description : ");
                    scanf("%s", l->description);
                     fprintf(temp, "%d %s %s %s %s %s %.2f %d\n",l->id,l->nom,l->titre, l->auteur, l->description, l->categorie,l->prix,l->disponibilite);
       break;
                case 2://Lire la nvll disponibilite et l'ecrire sur le fichier temporaire
                    printf("Donner la nouvelle disponibilite : ");
                    scanf("%d",&m);
                    fprintf(temp, "%d %s %s %s %s %s %.2f %d\n",l->id,l->nom,l->titre, l->auteur, l->description, l->categorie,l->prix,m);
       break;
                case 3://Lire le nv prix et l'ecrire sur le fichier temporaire
                    printf("Donner le nouveau prix : ");
                    scanf("%f", &l->prix);
                     fprintf(temp, "%d %s %s %s %s %s %.2f %d\n",l->id,l->nom,l->titre, l->auteur, l->description, l->categorie,l->prix,l->disponibilite);
         break;
                default:
                    printf("Option invalide.\n");
            }	}
		}
          if (trouve) {
          	//Retourner au debut du fichier
        	rewind(file);
//        	Relecture de chaque ligne du fichier
        	  while(fscanf(file, "%d %s %s %s %s %s %f %d",&l->id,l->nom, l->titre, l->auteur,l->description, l->categorie, &l->prix, &l->disponibilite)==8)
          { 
          //Ecrire les autres Livres non modifie
			 if (l->id!=idd) {
            fprintf(temp, "%d %s %s %s %s %s %.2f %d\n",l->id,l->nom,l->titre, l->auteur, l->description, l->categorie,l->prix,l->disponibilite);
		 }
		 }	
		 }

//Fermer le fichier
    fclose(file);
    fclose(temp);

    if (trouve) {
        remove("library.csv");
        rename("temp.csv", "library.csv");
        printf("Changement effectue.\n");
    } else {
        printf("Cet Id %d n'existe pas.\n", idd);
        remove("temp.csv"); // Supprimer le fichier temporaire car aucun changement n'a été effectué
    }
}

//Fonction de tripar titre
   void tripartitre(char nom[]) {
    livre l[100];
    int nbrlivre = 0,trouve=0;
    livre temp;
FILE *test;
    // Ouvrir le fichier en mode lecture
    file = fopen("library.csv", "rt");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier file\n");
        exit(1);
    }
    //Ouverture du fichier temporaire en mode écriture
      test = fopen("test.csv", "wt");
    
    if (test == NULL) {
        printf("Impossible d'ouvrir le fichier test\n");
        exit(1);
    }
//    Retourner le pointeur au debut du fichier
rewind(file);
    // Lire les Livres de l'utilisateur et les stocker dans un tableau
    while (nbrlivre < 100  && fscanf(file,"%d %s %s %s %s %s %f %d",&l[nbrlivre].id,l[nbrlivre].nom, l[nbrlivre].titre, l[nbrlivre].auteur,l[nbrlivre].description, l[nbrlivre].categorie, &l[nbrlivre].prix, &l[nbrlivre].disponibilite)==8){
           if(strcmp(l->nom,nom)==0){
		   trouve=1;
		    nbrlivre++;
    	}
  if(strcmp(l->nom,nom)!=0){
  	//Ecrire les Livres de autres utilisateurs dans le temporaire sans tri
	   fprintf(test,"%d %s %s %s %s %s %.2f %d\n",l[nbrlivre].id,l[nbrlivre].nom, l[nbrlivre].titre, l[nbrlivre].auteur,l[nbrlivre].description, l[nbrlivre].categorie, l[nbrlivre].prix,l[nbrlivre].disponibilite);
  }
   }

    // Tri des produits par leur Titre en utilisant strcmp()
    for (int i = 0; i < nbrlivre - 1; i++) {
        for (int j = 0; j < nbrlivre - i - 1; j++) {
           if (strcmp(l[j].titre, l[j+1].titre) > 0){
                temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            } 
		  }
        }

    // Réécrire les livres triés par titre dans le temporaire
    for (int i = 0; i < nbrlivre; i++) {
         fprintf(test,"%d %s %s %s %s %s %.2f %d\n",l[i].id,l[i].nom,l[i].titre,l[i].auteur, l[i].description, l[i].categorie,l[i].prix,l[i].disponibilite);
      }
   //Fermeture des fichiers
   fclose(test);
   fclose(file);

  if (trouve) {
//  	Supprimer l'ancien fichier et renommer le temporaire si le tri fait
        remove("library.csv");
        rename("test.csv", "library.csv");
        printf("Produits triés par titre dans le fichier.\n");
    } else {
        printf("Cet utilisateur %s n'existe pas.\n",nom );
        remove("test.csv"); // Supprimer le fichier temporaire si aucun changement n'est effectué
        
    }   
}


//Fonction de tri par categorie
 void triparcategorie(char nom[]) {
    livre l[100];
    int nbrlivre = 0,trouve=0;
    livre temp;
FILE *test;
    // Ouvrir le fichier en mode lecture
    file = fopen("library.csv", "rt");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier file\n");
        exit(1);
    }
//    Ouvrir le fichier temporaire en mode ecriture
      test = fopen("test.csv", "wt");
    
    if (test == NULL) {
        printf("Impossible d'ouvrir le fichier test\n");
        exit(1);
    }
rewind(file);
    // Lire les livres de chaque ligne
    while (nbrlivre < 100  && fscanf(file,"%d %s %s %s %s %s %f %d",&l[nbrlivre].id,l[nbrlivre].nom, l[nbrlivre].titre, l[nbrlivre].auteur,l[nbrlivre].description, l[nbrlivre].categorie, &l[nbrlivre].prix, &l[nbrlivre].disponibilite)==8){
          //Ecrire sur le tableau les livres de l'utilisateur voulue
		   if(strcmp(l->nom,nom)==0){
		   trouve=1;
		    nbrlivre++;
    	}
    	//Ecrire les autres livres sur le temporaire  
  if(strcmp(l->nom,nom)!=0){
	   fprintf(test,"%d %s %s %s %s %s %.2f %d\n",l[nbrlivre].id,l[nbrlivre].nom, l[nbrlivre].titre, l[nbrlivre].auteur,l[nbrlivre].description, l[nbrlivre].categorie, l[nbrlivre].prix,l[nbrlivre].disponibilite);
  }
   }

    // Tri des produits par leur nom en utilisant strcmp()
    for (int i = 0; i < nbrlivre - 1; i++) {
        for (int j = 0; j < nbrlivre - i - 1; j++) {
           if (strcmp(l[j].categorie, l[j+1].categorie) > 0){
                temp = l[j];
                l[j] = l[j + 1];
                l[j + 1] = temp;
            } 
		  }
        }

    // Réécrire le fichier avec les produits triés par nom
    for (int i = 0; i < nbrlivre; i++) {
         fprintf(test,"%d %s %s %s %s %s %.2f %d\n",l[i].id,l[i].nom,l[i].titre,l[i].auteur, l[i].description, l[i].categorie,l[i].prix,l[i].disponibilite);
      }
   //Fermeture des fichiers
   fclose(test);
   fclose(file);

  if (trouve) {
//  		Supprimer l'ancien fichier et renommer le temporaire si le tri fait
        remove("library.csv");
        rename("test.csv", "library.csv");
        printf("Produits triés par catégorie dans le fichier.\n");
    } else {
        printf("Cet utilisateur %s n'existe pas.\n",nom );
        remove("test.csv"); // Supprimer le fichier temporaire si aucun changement n'est effectué
}
}
//Fonction de main 
int main() {
    char nom[30];
    int choix;
//Boucle de changement d'utilisateur 
    do {
        printf("Donner le nom d'utilisateur : ");
        scanf("%s", nom);

        do {
        	//Boucle de Menu tant que l'utilisateur choisis ses traitement
            printf("\n            MENU GESTION DE Bibliotheque     \n\n");
            printf("1-Ajouter nouvel livre \n");
            printf("2-Afficher un livre \n");
            printf("3-Afficher mes livres \n");
            printf("4-Supprimer un livre \n");
            printf("5-Recherche d'un livre par titre \n");
            printf("6-Recherche d'un livre par auteur \n");
            printf("7-Modification \n");
            printf("8-Tri \n");
            printf("0-Fin de session\n");
            printf("Votre Choix : ");
            scanf("%d", &choix);
//Fonction switch pour envoyer chaque choix vers une fonction
            switch (choix) {
                case 1:
                    ajoutlivre(nom);
                    break;
                case 2:
                   afficherlivreparid();
                    break;
                case 3:
                 afficherlivreparutilisateur(nom);
                	break;
               	case 4:
                	suppression() ;
                		break;
               	case 5:
               	afficherpartitre();
               		break;
               	case 6:
               	afficherparauteur();
               		break;
               	case 7:
               	modifier();
               		break;
               	case 8:
               	tripartitre(nom);
               			break;
               	case 9:
               	triparcategorie(nom);
               				break;
                case 0:
                    printf("Fin de votre session et changement d'utilisateur \n");
                    break;
                default:
                    printf("Choix erroné !!! Le choix doit être entre [0-6]\n\n");
            }

        } while (choix != 0);

        printf("Voulez-vous changer d'utilisateur ? (1 pour Oui, 0 pour Non) : ");
        scanf("%d", &choix);

    } while (choix == 1);

    return 0;
}
