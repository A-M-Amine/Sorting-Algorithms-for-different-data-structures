#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Element      // structure de la liste
{
    char info[50];
    struct Element *svt;
} Element, *List;



// * * * * * * * * * fcts supplementaires * * * * * *

List creation_Fifo(int n)
{
    List L= NULL, p = NULL;
    int i;
    L = (List)malloc(sizeof(Element));
    printf("Donner le mot N[1] : ");
    gets(L->info);
    p = L;
    for(i=2; i<=n; i++)
    {
        p->svt = (List)malloc(sizeof(Element));
        p = p->svt;
        printf("Donner le mot N[%d] : ",i);
        gets(p->info);
    }
    p->svt = NULL;
    return L;
}


void affiche_List(List L)           // fct d'affichage d'une liste des mots
{
    List p = L;
    while(p!=NULL)
    {
        puts(p->info);
        p = p->svt;
    }
}



void swap_chaine(char str1[], char str2[],int m)    // fct pour permuter entre 2 mots
{

    char temp[m];

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);

}


void print_Mat_c(char **str, int len)       // fct pour l'affichage d'une matrice des mots
{
    int i = 0;
    while (i < len)
    {
        printf("%s\n", str[i]);
        i++;
    }
}


void ViderBuffer()
{
    int c;
    while(c!= '\n' && c!= EOF)
    {
        c= getchar();
    }
}



void terminate()        // fct qui controle la fermeture de prog
{
    system("cls");
    printf("Goodbye");
    system("color 3f");
    exit(EXIT_SUCCESS);
}




// - - - - - - - - - - - - - - - - - - - - Partie 1 - - - - - - - - - - - - - - - - - - - - - -

// tri par selection ordre croissant

void Tri_selection_Vect_c(int* V,int n,int type)
{
    int i,Posm,x,j,T[n];
    int nbprm=0,nbcmp=0;    // les compteurs de nombre des comparisons et permutation effectués
    int ce=1; // compteur des etapes
    for(i=0; i<n; i++)
    {
        T[i]=V[i];
    }
    for(i=0; i<(n-1); i++)
    {
        Posm=i;
        for(j=i+1; j<n; j++)
        {
            nbcmp++;
            if(T[j]<T[Posm])
            {
                Posm=j;

            }
        }
        if(i!=Posm)
        {
            x=T[i];
            T[i]=T[Posm];
            T[Posm]=x;
            nbprm++;
            printf("Etape [%d] :",ce);
            for(int k=0; k<n; k++)      //  boucle d'affichage des etapes
            {
                printf(" %d ",T[k]);
            }
            ce++;
            printf("\n");
        }
    }
    printf("Vecteur Final apres le Tri d'ordre croissant par Selection : \n[");
    for(i=0; i<n; i++)
    {
        printf(" %d ",T[i]);
    }
    printf("]\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
    if(type==1)   // pour controler la modification des vecteurs de matrice dans les fcts de Tri de matrice
    {
        for(i=0; i<n; i++)
        {
            V[i]=T[i];
        }
    }

}

// tri par selection ordre decroissant

void Tri_selection_Vect_d(int* V,int n,int type)
{
    int i,Posm,x,j,T[n];
    int ce=1;
    int nbprm=0,nbcmp=0;    // les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n; i++)
    {
        T[i]=V[i];
    }
    for(i=0; i<(n-1); i++)
    {
        Posm=i;
        for(j=i+1; j<n; j++)
        {
            nbcmp++;
            if(T[j]>T[Posm])
            {
                Posm=j;

            }
        }
        if(i!=Posm)
        {
            x=T[i];
            T[i]=T[Posm];
            T[Posm]=x;
            nbprm++;
            printf("Etape [%d] :",ce);
            for(int k=0; k<n; k++)
            {
                printf(" %d ",T[k]);
            }
            ce++;
            printf("\n");
        }
    }
    printf("Vecteur Final apres le Tri d'ordre decroissant par Selection : \n[");
    for(i=0; i<n; i++)
    {
        printf(" %d ",T[i]);
    }
    printf("]\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
    if(type==1)   // pour controler la modification des vecteurs de matrice dans les fcts de Tri de matrice
    {
        for(i=0; i<n; i++)
        {
            V[i]=T[i];
        }
    }

}

// tri par bulle ordre croissant

void Tri_bulle_vect_c(int *V,int n,int type)
{
    int x,T[n],i,j;
    int ce;
    int nbcmp=0,nbprm=0;    // les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n; i++)
    {
        T[i]=V[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            nbcmp++;
            if(T[j]>T[j+1])
            {
                x=T[j];
                T[j]=T[j+1];
                T[j+1]=x;
                nbprm++;
                printf("Etape [%d] :",ce);
                for(int k=0; k<n; k++)
                {
                    printf(" %d ",T[k]);
                }
                ce++;
                printf("\n");
            }
        }
    }
    printf("Vecteur Final apres le Tri d'ordre croissant par bulle : \n[");
    for(i=0; i<n; i++)
    {
        printf(" %d ",T[i]);
    }
    printf("]\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
    if(type==1)   // pour controler la modification des vecteurs de matrice dans les fcts de Tri de matrice
    {
        for(i=0; i<n; i++)
        {
            V[i]=T[i];
        }
    }
}


// Tri par bulle ordre decroissant

void Tri_bulle_vect_d(int *V,int n,int type)
{
    int x,T[n],i,j;
    int ce=1;
    int nbcmp=0,nbprm=0;    // les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n; i++)
    {
        T[i]=V[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            nbcmp++;
            if(T[j]<T[j+1])
            {
                x=T[j];
                T[j]=T[j+1];
                T[j+1]=x;
                nbprm++;
                printf("Etape [%d] :",ce);
                for(int k=0; k<n; k++)
                {
                    printf(" %d ",T[k]);
                }
                ce++;
                printf("\n");
            }
        }
    }
    printf("Vecteur Final apres le Tri d'ordre decroissant par bulle : \n[");
    for(i=0; i<n; i++)
    {
        printf(" %d ",T[i]);
    }
    printf("]\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");

    if(type==1)   // pour controler la modification des vecteurs de matrice dans les fcts de Tri de matrice
    {
        for(i=0; i<n; i++)
        {
            V[i]=T[i];
        }
    }
}

// tri par insertion ordre croissant

void Tri_insertion_vect_c(int *V,int n,int type)
{

    int x,T[n],i,j;
    int ce=1;
    int nbcmp=0,nbprm=0;    // les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n; i++)
    {
        T[i]=V[i];
    }
    for(i=1; i<n; i++)
    {
        j=i;
        x=T[i];
        while( j>0 && T[j-1]>x )
        {

            T[j]=T[j-1];
            j--;
            nbprm++;
            nbcmp++;
        }
        if(T[j-1]>x)
            nbcmp++;
        T[j]=x;
        printf("Etape [%d] :",ce);
        for(int k=0; k<n; k++)
        {
            printf(" %d ",T[k]);
        }
        ce++;
        printf("\n");

    }
    printf("Vecteur Final apres le Tri d'ordre croissant par insertion : \n[");
    for(i=0; i<n; i++)
    {
        printf(" %d ",T[i]);
    }
    printf("]\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");

    if(type==1)   // pour controler la modification des vecteurs de matrice dans les fcts de Tri de matrice
    {
        for(i=0; i<n; i++)
        {
            V[i]=T[i];
        }
    }
}


// tri par insertion ordre decroissant


void Tri_insertion_vect_d(int *V,int n,int type)
{

    int x,T[n],i,j;
    int nbcmp=0,nbprm=0;    // les compteurs de nombre des comparisons et permutation effectués
    int ce=1;
    for(i=0; i<n; i++)
    {
        T[i]=V[i];
    }
    for(i=1; i<n; i++)
    {
        j=i;
        x=T[i];
        while( j>0 && T[j-1]<x )
        {

            T[j]=T[j-1];
            j--;
            nbprm++;
            nbcmp++;
        }
        if(T[j-1]>x)
            nbcmp++;
        T[j]=x;
        printf("Etape [%d] :",ce);
        for(int k=0; k<n; k++)
        {
            printf(" %d ",T[k]);
        }
        ce++;
        printf("\n");

    }
    printf("Vecteur Final apres le Tri d'ordre decroissant par insertion : \n[");
    for(i=0; i<n; i++)
    {
        printf(" %d ",T[i]);
    }
    printf("]\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");

    if(type==1)   // pour controler la modification des vecteurs de matrice dans les fcts de Tri de matrice
    {
        for(i=0; i<n; i++)
        {
            V[i]=T[i];
        }
    }
}

// tri par permutation ordre croissant

void Tri_permutation_vect_c(int *V,int n,int type)
{
    int x,T[n],i,j;
    int ce=1;
    int nbcmp=0,nbprm=0;    // les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n; i++)
    {
        T[i]=V[i];
    }
    for(i=1; i<n; i++)
    {
        nbcmp++;
        if(T[i]<T[i-1])
        {
            j = 0;
            while(T[j]<T[i])
            {
                nbcmp++;
                j++;
            }
            x = T[i];
            for(int z=i-1; z>=j; z--)
            {
                T[z+1] = T[z];
            }
            T[j] = x;
            nbprm++;
        }
        printf("Etape [%d] :",ce);
        for(int k=0; k<n; k++)
        {
            printf(" %d ",T[k]);
        }
        ce++;
        printf("\n");
    }
    printf("Vecteur Final apres le Tri d'ordre croissant par permutation : \n[");
    for(i=0; i<n; i++)
    {
        printf(" %d ",T[i]);
    }
    printf("]\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");

    if(type==1)   // pour controler la modification des vecteurs de matrice dans les fcts de Tri de matrice
    {
        for(i=0; i<n; i++)
        {
            V[i]=T[i];
        }
    }
}

// tri par permutation ordre decroissant

void Tri_permutation_vect_d(int *V,int n,int type)
{
    int x,T[n],i,j;
    int ce=1;
    int nbcmp=0,nbprm=0;    // les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n; i++)
    {
        T[i]=V[i];
    }
    for(i=1; i<n; i++)
    {
        nbcmp++;
        if(T[i]>T[i-1])
        {
            j = 0;
            while(T[j]>T[i])
            {
                nbcmp++;
                j++;
            }
            x = T[i];
            for(int z=i-1; z>=j; z--)
            {
                T[z+1] = T[z];
            }
            T[j] = x;
            nbprm++;
        }
        printf("Etape [%d] :",ce);
        for(int k=0; k<n; k++)
        {
            printf(" %d ",T[k]);
        }
        ce++;
        printf("\n");
    }
    printf("Vecteur Final apres le Tri d'ordre decroissant par permutation : \n[");
    for(i=0; i<n; i++)
    {
        printf(" %d ",T[i]);
    }
    printf("]\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");

    if(type==1)   // pour controler la modification des vecteurs de matrice dans les fcts de Tri de matrice
    {
        for(i=0; i<n; i++)
        {
            V[i]=T[i];
        }
    }
}


// - - - - - - - - - - - - - - - - - - - - Partie 2 - - - - - - - - - - - - - - - - - - - - - -

// - - - - - qst 2

// Tri de matrice ligne par ligne par selection d'ordre croissant

void Tri_selection_Mat_LPL_c(int **Mat,int n,int m)
{
    int type=1;
    int i,j,A[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        Tri_selection_Vect_c(A[i],m,type);
    }
    printf("La matrice finale apres le Tri par selection croissant ligne par ligne : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("]");
        printf("\n");
    }
}


// Tri de matrice ligne par ligne par selection d'ordre decroissant

void Tri_selection_Mat_LPL_d(int **Mat,int n,int m)
{
    int type=1;
    int i,j,A[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        Tri_selection_Vect_d(A[i],m,type);
    }
    printf("La matrice finale apres le Tri par selection decroissant ligne par ligne : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("]");
        printf("\n");
    }
}

// Tri de matrice ligne par ligne par bulle d'ordre croissant


void Tri_bulle_Mat_LPL_c(int **Mat,int n,int m)
{
    int type=1;
    int i,j,A[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        Tri_bulle_vect_c(A[i],m,type);
    }
    printf("La matrice finale apres le Tri par bulle croissant ligne par ligne : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("]");
        printf("\n");
    }
}

// Tri de matrice ligne par ligne par bulle d'ordre decroissant

void Tri_bulle_Mat_LPL_d(int **Mat,int n,int m)
{
    int type=1;
    int i,j,A[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        Tri_bulle_vect_d(A[i],m,type);
    }
    printf("La matrice finale apres le Tri par bulle decroissant ligne par ligne : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("]");
        printf("\n");
    }
}

// Tri de matrice ligne par ligne par insertion d'ordre croissant


void Tri_insertion_Mat_LPL_c(int **Mat,int n,int m)
{
    int type=1;
    int i,j,A[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        Tri_insertion_vect_c(A[i],m,type);
    }
    printf("La matrice finale apres le Tri par insertion croissant ligne par ligne : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("]");
        printf("\n");
    }
}

// Tri de matrice ligne par ligne par insertion d'ordre decroissant

void Tri_insertion_Mat_LPL_d(int **Mat,int n,int m)
{
    int type=1;
    int i,j,A[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        Tri_insertion_vect_d(A[i],m,type);
    }
    printf("La matrice finale apres le Tri par insertion decroissant ligne par ligne : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("]");
        printf("\n");
    }
}

// Tri de matrice ligne par ligne par permutation d'ordre croissant

void Tri_permutation_Mat_LPL_c(int **Mat,int n,int m)
{
    int type=1;
    int i,j,A[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        Tri_permutation_vect_c(A[i],m,type);
    }
    printf("La matrice finale apres le Tri par permutation croissant ligne par ligne : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("]");
        printf("\n");
    }
}

// Tri de matrice ligne par ligne par permutation d'ordre decroissant

void Tri_permutation_Mat_LPL_d(int **Mat,int n,int m)
{
    int type=1;
    int i,j,A[n][m];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        Tri_permutation_vect_d(A[i],m,type);
    }
    printf("La matrice finale apres le Tri par permutation decroissant ligne par ligne : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A[i][j]);
        }
        printf("]");
        printf("\n");
    }
}

// * * * * * qst 2

// Tri par selection croissant d'une matrice

void Tri_selection_Mat_c(int **Mat,int n,int m)
{
    int i,j,c,d,x,A[n][m],Pi,Pj;
    int nbprm=0,nbcmp=0;    // les compteurs de nombre des comparisons et permutation effectués
    int k,o,ce=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            Pi=i;
            Pj=j;
            d=j;
            for(c=i; c<n; c++)
            {
                while(d<m)
                {
                    if(A[c][d]<A[Pi][Pj])
                    {
                        Pi=c;
                        Pj=d;
                    }
                    nbcmp++;
                    d++;
                }
                d=0;
            }
            if(Pi!=i || Pj!=j)
            {
                x=A[i][j];
                A[i][j]=A[Pi][Pj];
                A[Pi][Pj]=x;
                nbprm++;
            }
            printf("Etape [%d] :\n",ce);
            for(k=0; k<n; k++)
            {
                printf("[");
                for(o=0; o<m; o++)
                {
                    printf(" %d ",A[k][o]);
                }
                printf("]");
                printf("\n");
            }
            ce++;
        }
    }
    printf("Matrice Final apres le Tri d'ordre croissant par Selection : \n");
    for(k=0; k<n; k++)
    {
        printf("[");
        for(o=0; o<m; o++)
        {
            printf(" %d ",A[k][o]);
        }
        printf("]");
        printf("\n");
    }
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}


// Tri par selection decroissant d'une matrice


void Tri_selection_Mat_d(int **Mat,int n,int m)
{
    int i,j,c,d,x,A[n][m],Pi,Pj;
    int nbprm=0,nbcmp=0;    // les compteurs de nombre des comparisons et permutation effectués
    int k,o,ce=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[i][j]=Mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            Pi=i;
            Pj=j;
            d=j;
            for(c=i; c<n; c++)
            {
                while(d<m)
                {
                    if(A[c][d]>A[Pi][Pj])
                    {
                        Pi=c;
                        Pj=d;
                    }
                    nbcmp++;
                    d++;
                }
                d=0;
            }
            if(Pi!=i || Pj!=j)
            {
                x=A[i][j];
                A[i][j]=A[Pi][Pj];
                A[Pi][Pj]=x;
                nbprm++;
            }
            printf("Etape [%d] :\n",ce);
            for(k=0; k<n; k++)
            {
                printf("[");
                for(o=0; o<m; o++)
                {
                    printf(" %d ",A[k][o]);
                }
                printf("]");
                printf("\n");
            }
            ce++;
        }
    }
    printf("Matrice Final apres le Tri d'ordre decroissant par Selection : \n");
    for(k=0; k<n; k++)
    {
        printf("[");
        for(o=0; o<m; o++)
        {
            printf(" %d ",A[k][o]);
        }
        printf("]");
        printf("\n");
    }
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}


// Tri par bulle croissant d'une matrice

void Tri_bulle_Mat_c(int **Mat,int n,int m)
{
    int i,j,d=0,A[n*m],A2[n][m];
    int type=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[d]=Mat[i][j];
            d++;
        }
    }
    Tri_bulle_vect_c(A,(n*m),type);
    d=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A2[i][j]=A[d];
            d++;
        }
    }
    printf("Matrice Final apres le Tri d'ordre croissant par Bulle : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A2[i][j]);
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}


// Tri par bulle decroissant d'une matrice

void Tri_bulle_Mat_d(int **Mat,int n,int m)
{
    int i,j,d=0,A[n*m],A2[n][m];
    int type=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[d]=Mat[i][j];
            d++;
        }
    }
    Tri_bulle_vect_d(A,(n*m),type);
    d=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A2[i][j]=A[d];
            d++;
        }
    }
    printf("Matrice Final apres le Tri d'ordre decroissant par Bulle : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A2[i][j]);
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}


// Tri par insertion croissant d'une matrice

void Tri_insertion_Mat_c(int **Mat,int n,int m)
{
    int i,j,d=0,A[n*m],A2[n][m];
    int type=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[d]=Mat[i][j];
            d++;
        }
    }
    Tri_insertion_vect_c(A,(n*m),type);
    d=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A2[i][j]=A[d];
            d++;
        }
    }
    printf("Matrice Final apres le Tri d'ordre croissant par insertion : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A2[i][j]);
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}


// Tri par insertion decroissant d'une matrice

void Tri_insertion_Mat_d(int **Mat,int n,int m)
{
    int i,j,d=0,A[n*m],A2[n][m];
    int type=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[d]=Mat[i][j];
            d++;
        }
    }
    Tri_insertion_vect_d(A,(n*m),type);
    d=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A2[i][j]=A[d];
            d++;
        }
    }
    printf("Matrice Final apres le Tri d'ordre decroissant par insertion : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A2[i][j]);
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}

// Tri par permutation croissant d'une matrice

void Tri_permutation_Mat_c(int **Mat,int n,int m)
{
    int i,j,d=0,A[n*m],A2[n][m];
    int type=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[d]=Mat[i][j];
            d++;
        }
    }
    Tri_permutation_vect_c(A,(n*m),type);
    d=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A2[i][j]=A[d];
            d++;
        }
    }
    printf("Matrice Final apres le Tri d'ordre croissant par permutation : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A2[i][j]);
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}

// Tri par permutation decroissant d'une matrice

void Tri_permutation_Mat_d(int **Mat,int n,int m)
{
    int i,j,d=0,A[n*m],A2[n][m];
    int type=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A[d]=Mat[i][j];
            d++;
        }
    }
    Tri_permutation_vect_d(A,(n*m),type);
    d=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            A2[i][j]=A[d];
            d++;
        }
    }
    printf("Matrice Final apres le Tri d'ordre decroissant par permutation : \n");
    for(i=0; i<n; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf(" %d ",A2[i][j]);
        }
        printf("]");
        printf("\n");
    }
    printf("\n");
}



// * * * * * qst 3

// Tri chaine selection croissant

void Chaine_Mat_Tri_Selection_c(char **A,int n,int m)
{
    int i,j,Posm,ce=1;
    int nbprm=0,nbcmp=0;    // les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n-1; i++)
    {
        Posm=i;
        for(j=i+1; j<n; j++)
        {
            nbcmp++;
            if(strcmp(A[Posm],A[j])>0)
            {
                Posm=j;
            }
        }
        if(i!=Posm)
        {
            swap_chaine(A[i],A[Posm],m);
            nbprm++;
            printf("etape [%d] : \n",ce);
            print_Mat_c(A,n);
            ce++;
        }
    }
    printf("La matrice apres le tri par selection croissant : \n");
    print_Mat_c(A,n);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}

// Tri chaine selection decroissant

void Chaine_Mat_Tri_Selection_d(char **A,int n,int m)
{
    int i,j,Posm,ce=1;
    int nbprm=0,nbcmp=0;    // les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n-1; i++)
    {
        Posm=i;
        for(j=i+1; j<n; j++)
        {
            nbcmp++;
            if(strcmp(A[Posm],A[j])<0)
            {
                Posm=j;
            }
        }
        if(i!=Posm)
        {
            swap_chaine(A[i],A[Posm],m);
            nbprm++;
            printf("etape [%d] : \n",ce);
            print_Mat_c(A,n);
            ce++;
        }
    }
    printf("La matrice apres le tri par selection decroissant : \n");
    print_Mat_c(A,n);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}


// Tri chaine bulle croissant

void Chaine_Mat_Tri_Bulle_c(char **str,int n,int m)
{
    int i,j,nbcmp=0,nbprm=0,ce=1;   // (nbcmp,nbprm) les compteurs de nombre des comparisons et permutation effectués
    char temp[m];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            nbcmp++;
            if(strcmp(str[i],str[j])>0)
            {
                swap_chaine(str[i],str[j],m);
                nbprm++;
                printf("etape [%d] : \n",ce);
                print_Mat_c(str,n);
                ce++;
            }
        }
    }
    printf("La matrice apres le tri par bulle croissant : \n");
    print_Mat_c(str,n);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}

// Tri chaine bulle decroissant

void Chaine_Mat_Tri_Bulle_d(char **str,int n,int m)
{
    int i,j,nbcmp=0,nbprm=0,ce=1;   // (nbcmp,nbprm) les compteurs de nombre des comparisons et permutation effectués
    char temp[m];
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            nbcmp++;
            if(strcmp(str[i],str[j])<0)
            {
                swap_chaine(str[i],str[j],m);
                nbprm++;
                printf("etape [%d] : \n",ce);
                print_Mat_c(str,n);
                ce++;
            }
        }
    }
    printf("La matrice apres le tri par bulle decroissant : \n");
    print_Mat_c(str,n);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}

// Tri chaine insertion croissant

void Chaine_Mat_Tri_Insertion_c(char **A,int n,int m)
{
    int i,j;
    int nbcmp=0,nbprm=0,ce=1;   // (nbcmp,nbprm) les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n; i++)
    {
        j=i;
        while( j>=1 && (strcmp(A[j],A[j-1]))<0)
        {
            swap_chaine(A[j],A[j-1],m);
            printf("etape [%d] : \n",ce);
            print_Mat_c(A,n);
            ce++;
            nbcmp++;
            nbprm++;
            j--;
        }
    }
    printf("La matrice apres le tri par insertion croissant : \n");
    print_Mat_c(A,n);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}


// Tri chaine insertion decroissant

void Chaine_Mat_Tri_Insertion_d(char **A,int n,int m)
{
    int i,j;
    int nbcmp=0,nbprm=0,ce=1;   // (nbcmp,nbprm) les compteurs de nombre des comparisons et permutation effectués
    for(i=0; i<n; i++)
    {
        j=i;
        while( j>=1 && (strcmp(A[j],A[j-1]))>0)
        {
            swap_chaine(A[j],A[j-1],m);
            printf("etape [%d] : \n",ce);
            print_Mat_c(A,n);
            ce++;
            nbcmp++;
            nbprm++;
            j--;
        }
    }
    printf("La matrice apres le tri par insertion decroissant : \n");
    print_Mat_c(A,n);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}

// Tri chaine permutation croissant

void Chaine_Mat_Tri_Permutation_c(char **str,int n,int m)
{
    int i,j,nbcmp=0,nbprm=0,ce=1;   // (nbcmp,nbprm) les compteurs de nombre des comparisons et permutation effectués
    char temp[m];
    for(i=1; i<n; i++)
    {
        nbcmp++;
        if(strcmp(str[i],str[i-1])<0)
        {
            j = 0;
            while(strcmp(str[i],str[j])>0)
            {
                nbcmp++;
                j++;
            }
            strcpy(temp,str[i]);
            for(int z=i-1; z>=j; z--)
            {
                strcpy(str[z+1],str[z]);
            }
            strcpy(str[j],temp);
            nbprm++;
        }
        printf("etape [%d] : \n",ce);
        print_Mat_c(str,n);
        ce++;
        printf("\n");
    }
    printf("La matrice apres le tri par permutation croissant : \n");
    print_Mat_c(str,n);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}

// Tri chaine permutation decroissant

void Chaine_Mat_Tri_Permutation_d(char **str,int n,int m)
{
    int i,j,nbcmp=0,nbprm=0,ce=1;   // (nbcmp,nbprm) les compteurs de nombre des comparisons et permutation effectués
    char temp[m];
    for(i=1; i<n; i++)
    {
        nbcmp++;
        if(strcmp(str[i],str[i-1])>0)
        {
            j = 0;
            while(strcmp(str[i],str[j])<0)
            {
                nbcmp++;
                j++;
            }
            strcpy(temp,str[i]);
            for(int z=i-1; z>=j; z--)
            {
                strcpy(str[z+1],str[z]);
            }
            strcpy(str[j],temp);
            nbprm++;
        }
        printf("etape [%d] : \n",ce);
        print_Mat_c(str,n);
        ce++;
        printf("\n");
    }
    printf("La matrice apres le tri par permutation decroissant : \n");
    print_Mat_c(str,n);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}

// - - - - - - - - - - - - - - - - - - - - Partie 4 - - - - - - - - - - - - - - - - - - - - - -

// Tri list par bulle croissant

void Tri_List_Bulle_c(List L)
{
    List p = L, q;
    int m=50,ce=1,nbcmp=0,nbprm=0;  // (nbcmp,nbprm) les compteurs de nombre des comparisons et permutation effectués
    while(p->svt != NULL)
    {
        q = p->svt;
        while(q != NULL)
        {
            nbcmp++;
            if(strcmp(p->info,q->info)>0)
            {
                swap_chaine(p->info,q->info,m);
                nbprm++;
                printf("etape [%d] : \n",ce);
                affiche_List(L);
                ce++;
            }
            q = q->svt;
        }
        p = p->svt;
    }
    printf("La liste apres le tri par bulle croissant : \n");
    affiche_List(L);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}

// Tri list par bulle decroissant

void Tri_List_Bulle_d(List L)
{
    List p = L, q;
    int m=50,ce=1,nbcmp=0,nbprm=0;
    while(p->svt != NULL)
    {
        q = p->svt;
        while(q != NULL)
        {
            nbcmp++;
            if(strcmp(p->info,q->info)<0)
            {
                swap_chaine(p->info,q->info,m);
                nbprm++;
                printf("etape [%d] : \n",ce);
                affiche_List(L);
                ce++;
            }
            q = q->svt;
        }
        p = p->svt;
    }
    printf("La liste apres le tri par bulle decroissant : \n");
    affiche_List(L);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}

// Tri list par selection croissant

void Tri_List_selection_c(List L)
{
    List p = L,adr,q;
    int ce=1,nbprm=0,nbcmp=0,m=50;

    while(p->svt != NULL)
    {
        adr = p;
        q = p->svt;
        while(q != NULL)
        {
            nbcmp++;
            if(strcmp(adr->info,q->info)>0)
            {
                adr = q;
            }
            q = q->svt;
        }
        if(adr != p)
        {
            swap_chaine(p->info,adr->info,m);
            nbprm++;
            printf("etape [%d] : \n",ce);
            affiche_List(L);
            ce++;
        }
        p = p->svt;
    }
    printf("La liste apres le tri par selection croissant : \n");
    affiche_List(L);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}

// Tri list par selection decroissant

void Tri_List_selection_d(List L)
{
    List p = L,adr,q;
    int ce=1,nbprm=0,nbcmp=0,m=50;

    while(p->svt != NULL)
    {
        adr = p;
        q = p->svt;
        while(q != NULL)
        {
            nbcmp++;
            if(strcmp(adr->info,q->info)<0)
            {
                adr = q;
            }
            q = q->svt;
        }
        if(adr != p)
        {
            swap_chaine(p->info,adr->info,m);
            nbprm++;
            printf("etape [%d] : \n",ce);
            affiche_List(L);
            ce++;
        }
        p = p->svt;
    }
    printf("La liste apres le tri par selection decroissant : \n");
    affiche_List(L);
    printf("\nLe nombre de permutations effectuees : %d",nbprm);
    printf("\nLe nombre de comparaisons effectuees : %d",nbcmp);
    printf("\n");
}


// algorithme principal

int main()
{
    int type=0;
    int m,i,j,n,a,b,c,d,h,lpl;
    system("color e0");
entr:
    do
    {
        printf("Bienvenu(e) dans notre algorithme de tri: \n");
        printf("1- Pour trier un vecteur\n");
        printf("2- Pour trier une matrice\n");
        printf("3- Pour un tri de liste.\n");
        printf("4- Exit\n");
        printf("           Votre choix : ");
        scanf("%d",&a);
    }
    while((a > 4)||(a < 1));

    switch (a)
    {

    case 1:     //  cas de tri de vecteur
    {
        printf("Donner une taille au vecteur : ");
        scanf("%d",&n);

        int* V=(int*)malloc(n*sizeof(int));

        for(i=0; i<n; i++)
        {
            printf("Saisir la valeur [%d] :",i+1);
            scanf("%d",&V[i]);
        }
vect_tri:
        printf("Veuillez maintenant choisir la methode de tri \n");
        printf("1- tri par insertion \n");
        printf("2- tri par bulle \n");
        printf("3- tri par selection \n");
        printf("4- tri par permutation \n");
        printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
        printf("           Votre choix : ");
        scanf("%d",&b);

        //deb switch b
        switch (b)
        {

        case 1:     // tri par insertion
        {
            printf("Choisir l'ordre de Tri\n");
            printf("1- Pour un tri croissant\n");
            printf("2- Pour un tri decroissant\n");
            printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
            printf("           Votre choix : ");
            scanf("%d",&c);

            switch (c)
            {

            case 1:     // croissant
            {
                Tri_insertion_vect_c(V,n,type);
                printf("\n\n");
                goto vect_tri;

            }
            break;

            case 2:     // decroissant
            {
                Tri_insertion_vect_d(V,n,type);
                printf("\n\n");
                goto vect_tri;

            }
            break;

            default:
                goto vect_tri;
            }

        }
        break;

        case 2:         // tri par bulle
        {

            printf("Choisir l'ordre de Tri\n");
            printf("1- Pour un tri croissant\n");
            printf("2- Pour un tri decroissant\n");
            printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
            printf("           Votre choix : ");
            scanf("%d",&c);

            switch (c)
            {
            case 1:     // croissant
            {
                Tri_bulle_vect_c(V,n,type);
                printf("\n\n");
                goto vect_tri;

            }
            break;



            case 2:     // decroissant
            {
                Tri_bulle_vect_d(V,n,type);
                printf("\n\n");
                goto vect_tri;

            }
            break;

            default:
                goto vect_tri;
            }
        }
        break;

        case 3:         //tri par selection
        {
            printf("Choisir l'ordre de Tri\n");
            printf("1- Pour un tri croissant\n");
            printf("2- Pour un tri decroissant\n");
            printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
            printf("           Votre choix : ");
            scanf("%d",&c);
            switch (c)
            {

            case 1:     // croissant
            {
                Tri_selection_Vect_c(V,n,type);
                printf("\n\n");
                goto vect_tri;
            }
            break;

            case 2:     // decroissant
            {
                Tri_selection_Vect_d(V,n,type);
                printf("\n\n");
                goto vect_tri;

            }
            break;

            default:
                goto vect_tri;
            }
        }
        break;
        case 4:   // tri par permutation
        {
            printf("Choisir l'ordre de Tri\n");
            printf("1- Pour un tri croissant\n");
            printf("2- Pour un tri decroissant\n");
            printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
            printf("           Votre choix : ");
            scanf("%d",&c);
            switch (c)
            {

            case 1:     // croissant
            {
                Tri_permutation_vect_c(V,n,type);

                printf("\n\n");
                goto vect_tri;
            }
            break;

            case 2:     // decroissant
            {
                Tri_permutation_vect_d(V,n,type);

                printf("\n\n");
                goto vect_tri;
            }
            break;

            default:
                goto vect_tri;
            }
        }
        break;
        default:
            goto entr;
        }

    }
    break;

    //fin tri vecteur
    case 2:
    {
tmat:
        printf("Choisir le type de matrice \n");
        printf("1- matrice d entiers\n");
        printf("2- matrice de caracteres\n");
        printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
        printf("           Votre choix : ");
        scanf("%d",&h);
        switch(h)
        {
        case 1:
        {
            printf("Donner la taille des lignes de matrice : ");
            scanf("%d",&n);
            printf("Donner la taille des colonnes de matrice : ");
            scanf("%d",&m);

            int** mat = (int**)malloc(n*sizeof(int*));

            for(i=0; i<n; i++)
            {
                mat[i] = (int*)malloc(m*sizeof(int));
            }

            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    printf("Donner la valeur [%d][%d] : ",i+1,j+1);
                    scanf("%d",&mat[i][j]);
                }
            }
mat_tri:
            printf("Veuillez maintenant faire un choix de tri \n");
            printf("1- Tri par insertion \n");
            printf("2- Tri par bulle \n");
            printf("3- Tri par selection\n");
            printf("4- Tri par permutation\n");
            printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
            printf("           Votre choix : ");
            scanf("%d",&b);
            // deb switch b
            switch (b)
            {

            case 1:  // tri par insertion
            {
tmatrix1:
                printf("Choisir le type de tri:\n");
                printf("1- Ligne par Ligne\n");
                printf("2- Tri de tous les elements de matrice\n");
                printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                printf("           Votre choix : ");
                scanf("%d",&lpl);
                switch(lpl)
                {
                case 1:
                {

                    printf("Choisir l'ordre de Tri\n");
                    printf("1- Pour un tri croissant\n");
                    printf("2- Pour un tri decroissant\n");
                    printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                    printf("           Votre choix : ");
                    scanf("%d",&c);

                    switch (c)
                    {

                    case 1:         // croissant
                    {
                        Tri_insertion_Mat_LPL_c(mat, n, m);

                        printf("\n\n");
                        goto tmatrix1;

                    }
                    break;

                    case 2:         // decroissant
                    {
                        Tri_insertion_Mat_LPL_d(mat,n, m);

                        printf("\n\n");
                        goto tmatrix1;

                    }
                    break;
                    default:
                        goto tmatrix1;

                    }
                }
                break;
                case 2:
                {

                    printf("Choisir l'ordre de Tri\n");
                    printf("1- Pour un tri croissant\n");
                    printf("2- Pour un tri decroissant\n");
                    printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                    printf("           Votre choix : ");
                    scanf("%d",&c);

                    switch (c)
                    {

                    case 1:      // croissant
                    {
                        Tri_insertion_Mat_c(mat,n, m);

                        printf("\n\n");
                        goto tmatrix1;
                    }
                    break;



                    case 2:// decroissant manquant
                    {
                        Tri_insertion_Mat_d(mat,n, m);

                        printf("\n\n");
                        goto tmatrix1;

                    }
                    break;
                    default:
                        goto tmatrix1;

                    }
                }
                break;
                default:
                    goto mat_tri;

                }
            }
            break;

            case 2:      // tri par bulle
            {
tmarix2:
                printf("Choisir le type de tri:\n");
                printf("1- Ligne par Ligne\n");
                printf("2- Tri de tous les elements de matrice\n");
                printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                printf("           Votre choix : ");
                scanf("%d",&lpl);

                switch(lpl)
                {
                case 1:
                {

                    printf("Choisir l'ordre de Tri\n");
                    printf("1- Pour un tri croissant\n");
                    printf("2- Pour un tri decroissant\n");
                    printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                    printf("           Votre choix : ");
                    scanf("%d",&c);

                    switch (c)
                    {
                    case 1:      // croissant
                    {
                        Tri_bulle_Mat_LPL_c(mat, n, m);

                        printf("\n\n");
                        goto tmarix2;
                    }
                    break;

                    case 2:      // decroissant
                    {
                        Tri_bulle_Mat_LPL_d(mat,n,m);

                        printf("\n\n");
                        goto tmarix2;
                    }
                    break;
                    default:
                        goto tmarix2;

                    }

                }
                break;
                case 2:
                {
                    printf("Choisir l'ordre de Tri\n");
                    printf("1- Pour un tri croissant\n");
                    printf("2- Pour un tri decroissant\n");
                    printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                    printf("           Votre choix : ");
                    scanf("%d",&c);

                    switch (c)
                    {
                    case 1:      // croissant
                    {
                        Tri_bulle_Mat_c(mat,n, m);

                        printf("\n\n");
                        goto tmarix2;
                    }
                    break;
                    case 2:      // decroissant
                    {
                        Tri_bulle_Mat_d(mat,n, m);

                        printf("\n\n");
                        goto tmarix2;

                    }
                    break;
                    default:
                        goto tmarix2;

                    }
                }
                break;
                default :
                    goto mat_tri;

                }
            }
            break;

            case 3:          //tri par selection
            {
tmatrix3:
                printf("Choisir le type de tri:\n");
                printf("1- Ligne par Ligne\n");
                printf("2- Tri de tous les elements de matrice\n");
                printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                printf("           Votre choix : ");
                scanf("%d",&lpl);

                switch(lpl)
                {
                case 1:
                {
                    printf("Choisir l'ordre de Tri\n");
                    printf("1- Pour un tri croissant\n");
                    printf("2- Pour un tri decroissant\n");
                    printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                    printf("           Votre choix : ");
                    scanf("%d",&c);

                    switch (c)
                    {
                    case 1:      // croissant
                    {
                        Tri_selection_Mat_LPL_c(mat,n, m);

                        printf("\n\n");
                        goto tmatrix3;

                    }
                    break;

                    case 2:        // decroissant
                    {
                        Tri_selection_Mat_LPL_d(mat, n, m);

                        printf("\n\n");
                        goto tmatrix3;

                    }
                    break;

                    default:
                        goto tmatrix3;

                    }
                }
                break;
                case 2:
                {
                    printf("Choisir l'ordre de Tri\n");
                    printf("1- Pour un tri croissant\n");
                    printf("2- Pour un tri decroissant\n");
                    printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                    printf("           Votre choix : ");
                    scanf("%d",&c);

                    switch (c)
                    {
                    case 1:      // croissant
                    {
                        Tri_selection_Mat_c(mat,n, m);

                        printf("\n\n");
                        goto tmatrix3;
                    }
                    break;

                    case 2:        // decroissant
                    {
                        Tri_selection_Mat_d(mat,n,m);

                        printf("\n\n");
                        goto tmatrix3;
                    }
                    break;

                    default:
                        goto tmatrix3;

                    }
                }
                break;
                default:
                    goto mat_tri;

                }
            }
            break;
            case 4:  // tri par permutation
            {
tmatrix4:
                printf("Choisir le type de tri:\n");
                printf("1- Ligne par Ligne\n");
                printf("2- Tri de tous les elements de matrice\n");
                printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                printf("           Votre choix : ");
                scanf("%d",&lpl);

                switch(lpl)
                {
                case 1:
                {
                    printf("Choisir l'ordre de Tri\n");
                    printf("1- Pour un tri croissant\n");
                    printf("2- Pour un tri decroissant\n");
                    printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                    printf("           Votre choix : ");
                    scanf("%d",&c);

                    switch (c)
                    {
                    case 1:      // croissant
                    {
                        Tri_permutation_Mat_LPL_c(mat,n, m);

                        printf("\n\n");
                        goto tmatrix4;

                    }
                    break;

                    case 2:        // decroissant
                    {
                        Tri_permutation_Mat_LPL_d(mat,n, m);

                        printf("\n\n");
                        goto tmatrix4;

                    }
                    break;

                    default:
                        goto tmatrix4;

                    }
                }
                break;
                case 2:
                {
                    printf("Choisir l'ordre de Tri\n");
                    printf("1- Pour un tri croissant\n");
                    printf("2- Pour un tri decroissant\n");
                    printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                    printf("           Votre choix : ");
                    scanf("%d",&c);

                    switch (c)
                    {
                    case 1:      // croissant
                    {
                        Tri_permutation_Mat_c(mat,n, m);

                        printf("\n\n");
                        goto tmatrix4;
                    }
                    break;

                    case 2:        // decroissant
                    {
                        Tri_permutation_Mat_d(mat,n, m);

                        printf("\n\n");
                        goto tmatrix4;
                    }
                    break;

                    default:
                        goto tmatrix4;

                    }
                }
                break;
                default:
                    goto mat_tri;

                }

            }
            default:
                goto tmat;
            }


        }
        break;
        case 2:
        {
            m=50;
            printf("Donner le nombre des lignes de matrice : ");
            scanf("%d",&n);
            ViderBuffer();
            char **A =(char **)malloc(n*sizeof(char *));
            for(i=0; i<n; i++)
            {
                A[i] = (char *)malloc(m*sizeof(char));
            }
            for(i=0; i<n; i++)
            {
                printf("donner le mot [%d] : ",i+1);
                gets(A[i]);
            }
Chaine_tri:
            printf("Veuillez maintenant faire un choix de tri \n");
            printf("1- Tri par insertion \n");
            printf("2- Tri par bulle \n");
            printf("3- Tri par selection\n");
            printf("4- Tri par permutation\n");
            printf("*- Appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
            printf("   ***Une nouvelle execution est necessaire pour qu'une autre methode de tri sera fonctionelle\n");
            printf("           Votre choix : ");
            scanf("%d",&b);
            switch (b)
            {
            case 1:     // tri par insertion
            {
                printf("Choisir l'ordre de Tri\n");
                printf("1- Pour un tri croissant\n");
                printf("2- Pour un tri decroissant\n");
                printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                printf("           Votre choix : ");
                scanf("%d",&c);

                switch (c)
                {

                case 1:     // croissant
                {
                    Chaine_Mat_Tri_Insertion_c(A,n,m);

                    printf("\n\n");
                    goto Chaine_tri;

                }
                break;

                case 2:     // decroissant
                {
                    Chaine_Mat_Tri_Insertion_d(A,n,m);

                    printf("\n\n");
                    goto Chaine_tri;

                }
                break;

                default:
                    goto Chaine_tri;
                }

            }
            break;

            case 2:         // tri par bulle
            {

                printf("Choisir l'ordre de Tri\n");
                printf("1- Pour un tri croissant\n");
                printf("2- Pour un tri decroissant\n");
                printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                printf("           Votre choix : ");
                scanf("%d",&c);

                switch (c)
                {
                case 1:     // croissant
                {
                    Chaine_Mat_Tri_Bulle_c(A,n,m);

                    printf("\n\n");
                    goto Chaine_tri;

                }
                break;

                case 2:     // decroissant
                {
                    Chaine_Mat_Tri_Bulle_d(A,n,m);

                    printf("\n\n");
                    goto Chaine_tri;

                }
                break;

                default:
                    goto Chaine_tri;
                }
            }
            break;

            case 3:         //tri par selection
            {
                printf("Choisir l'ordre de Tri\n");
                printf("1- Pour un tri croissant\n");
                printf("2- Pour un tri decroissant\n");
                printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                printf("           Votre choix : ");
                scanf("%d",&c);
                switch (c)
                {

                case 1:     // croissant
                {
                    Chaine_Mat_Tri_Selection_c(A,n,m);

                    printf("\n\n");
                    goto Chaine_tri;
                }
                break;

                case 2:     // decroissant
                {
                    Chaine_Mat_Tri_Selection_d(A,n,m);

                    printf("\n\n");
                    goto Chaine_tri;

                }
                break;

                default:
                    goto Chaine_tri;
                }
            }
            break;
            case 4:   // tri par permutation
            {
                printf("Choisir l'ordre de Tri\n");
                printf("1- Pour un tri croissant\n");
                printf("2- Pour un tri decroissant\n");
                printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
                printf("           Votre choix : ");
                scanf("%d",&c);
                switch (c)
                {

                case 1:     // croissant
                {
                    Chaine_Mat_Tri_Permutation_c(A,n,m);

                    printf("\n\n");
                    goto Chaine_tri;
                }
                break;

                case 2:     // decroissant
                {
                    Chaine_Mat_Tri_Permutation_d(A,n,m);

                    printf("\n\n");
                    goto Chaine_tri;
                }
                break;

                default:
                    goto Chaine_tri;
                }



                default:
                    goto tmat;
                }

            }
            break;

            default:
                goto entr;
            }
        }
        break;
        //fin de tri des matrices
    }
    break;
    case 3:     //tri de liste de car
    {
        List L;
        m=50;
        printf("Donner le nombre de mots de liste : ");
        scanf("%d",&n);
        ViderBuffer();
        L = creation_Fifo(n);
List_tri:
        printf("Veuillez maintenant choisir la methode de tri \n");
        printf("1- tri par bulle \n");
        printf("2- tri par selection \n");
        printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
        printf("           Votre choix : ");
        scanf("%d",&b);
        switch (b)
        {
        case 1: // tri par bulle
        {
            printf("Choisir l'ordre de Tri\n");
            printf("1- Pour un tri croissant\n");
            printf("2- Pour un tri decroissant\n");
            printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
            printf("           Votre choix : ");
            scanf("%d",&c);
            switch (c)
            {

            case 1:     // croissant
            {
                Tri_List_Bulle_c(L);


            }
            break;

            case 2:     // decroissant
            {
                Tri_List_Bulle_d(L);

            }
            break;

            default:
                goto List_tri;
            }
        }
        break;
        case 2: // tri par selection
        {
            printf("Choisir l'ordre de Tri\n");
            printf("1- Pour un tri croissant\n");
            printf("2- Pour un tri decroissant\n");
            printf("*- appuyez sur un nombre diffrent pour retourner vers le Menu precedent\n");
            printf("           Votre choix : ");
            scanf("%d",&c);
            switch (c)
            {

            case 1:     // croissant
            {
                Tri_List_selection_c(L);


            }
            break;

            case 2:     // decroissant
            {
                Tri_List_selection_d(L);

            }
            break;

            default:
                goto List_tri;
            }
        }
        break;

        default:
            goto entr;

        }
    }
    break;
    default:
        terminate();
    }

    return 0;
}


