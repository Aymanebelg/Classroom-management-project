



#include <iostream>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>


using namespace std;


class etudiant
{
public:
    string nom,prenom,cne,r;
    float notetp,notecc,notecu,notef;
    int num;

public:
    void afficher(string nomfichier);
    void modifier(string nomfichier,string CNE);
    void ajouteretudiant(string nomfichier,etudiant *e,int m);
    void supprimer(string nomfichier,etudiant *e,string CNE);
    void exist(etudiant *e,string CNE);
    void majorant(string nomfichier);
    void save(string nomfichier,etudiant *e);
    etudiant* load(string nomfichier);
    void moyenneclasse(string nomfichier);
};


void etudiant::afficher(string nomfichier)            //fonction d'affichage
{
    etudiant *e=e->load(nomfichier);
    int n=num;
    int i;
    cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
    cout<<left<<setw(20)<<"| nom";
    cout<<left<<setw(20)<<"| prenom";
    cout<<left<<setw(15)<<"| cne";
    cout<<left<<setw(10)<<"| notetp";
    cout<<left<<setw(10)<<"| notecc";
    cout<<left<<setw(10)<<"| notecu";
    cout<<left<<setw(10)<<"| notef";
    cout<<left<<setw(10)<<"| resultat"<<"|"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"| "<<left<<setw(18)<<e[i].nom;
        cout<<"| "<<left<<setw(18)<<e[i].prenom;
        cout<<"| "<<left<<setw(13)<<e[i].cne;
        cout<<"| "<<left<<setw(8)<<e[i].notetp;
        cout<<"| "<<left<<setw(8)<<e[i].notecc;
        cout<<"| "<<left<<setw(8)<<e[i].notecu;
        cout<<"| "<<left<<setw(8)<<e[i].notef;
        cout<<"| "<<left<<setw(8)<<e[i].r<<"|"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
    }
    cout<<endl<<endl<<endl;
}

void etudiant::modifier(string nomfichier,string CNE)        //fonction pour modifier un etudiant
{
    etudiant* e=load(nomfichier);
    int z=num;
    int j,b;
    bool ex=false;
    int k=0;
    do
    {

        for(j=0; j<z; j++)
        {
            if(CNE==e[j].cne)
            {

                cout<<"                      ________________________MENU DE MODIFICATION_________________________"<<endl;
                cout<<"                     |                                                                     |"<<endl;
                cout<<"                     |                     Choisir l'operation desiree :                   |"<<endl;
                cout<<"                     |_____________________________________________________________________|"<<endl;
                cout<<"                     |0) Revenir au menu principal                                         |"<<endl;
                cout<<"                     |1) Modifier le nom                                                   |"<<endl;
                cout<<"                     |2) Modifier le prenom                                                |"<<endl;
                cout<<"                     |3) Modifier le cne                                                   |"<<endl;
                cout<<"                     |4) Modifier la note tp                                               |"<<endl;
                cout<<"                     |5) Modifier la note cc                                               |"<<endl;
                cout<<"                     |6) Modifier la note cu                                               |"<<endl;
                cout<<"                     |_____________________________________________________________________|"<<endl;
                cout<<endl;
                cout<<"Entrez votre choix : ";
                cin>>b;
                cout<<endl<<endl<<endl;

                k++;

                switch (b)
                {

                case 1:
                    cout<<"entrer le nouveau nom : ";
                    cin>>e[j].nom;
                    break;
                case 2:
                    cout<<"entrer le nouveau prenom : ";
                    cin>>e[j].prenom;
                    break;
                case 3:
                    cout<<"entrer le nouveau cne : ";
                    cin>>e[j].cne;
                    break;
                case 4:


                    do
                    {
                        cout<<"entrer la note de tp  : ";
                        cin>>e[j].notetp;
                        if(e[j].notetp>20 || e[j].notetp<0)                         //verifier que l'utilisateur à entrer une note entre  et 20
                            cout<<"*la note doit etre entre 0 et 20*"<<endl;
                    }
                    while(e[j].notetp>20 || e[j].notetp<0);


                    e[j].notef=0.35*e[j].notetp+0.15*e[j].notecc+0.5*e[j].notecu;
                    if(e[j].notef>12)
                        e[j].r='V';
                    else
                        e[j].r='R';

                    break;
                case 5:

                    do
                    {
                        cout<<"entrer la note de cc : ";
                        cin>>e[j].notecc;
                        if(e[j].notecc>20 || e[j].notecc<0)
                            cout<<"*la note doit etre entre 0 et 20*"<<endl;
                    }
                    while(e[j].notecc>20 || e[j].notecc<0);
                    e[j].notef=0.35*e[j].notetp+0.15*e[j].notecc+0.5*e[j].notecu;

                    if(e[j].notef>12)
                        e[j].r='V';
                    else
                        e[j].r='R';
                    break;
                case 6:
                    do
                    {
                        cout<<"entrer la note de cu : ";
                        cin>>e[j].notecu;
                        if(e[j].notecu>20 || e[j].notecu<0)
                            cout<<"*la note doit etre entre 0 et 20*"<<endl;
                    }
                    while(e[j].notecu>20 || e[j].notecu<0);


                    e[j].notef=0.35*e[j].notetp+0.15*e[j].notecc+0.5*e[j].notecu;


                    if(e[j].notef>12)
                        e[j].r='V';
                    else
                        e[j].r='R';
                    break;
                }
            }

        }


        if(k==0)
        {

            cout<<"Ce CNE n'existe pas"<<endl<<endl<<endl;
            b=0;

        }

    }
    while(b!=0 && b!=3);

    e->save(nomfichier,e);
}

void etudiant::ajouteretudiant(string nomfichier,etudiant *e,int m)   //fonction pour ajouter des etudiants
{
    int k,b;
    ofstream f;
    f.open(nomfichier.c_str(),ios::app);
    int a=num;
    for(k=a; k<a+m; k++)
    {
        cout<<"_________________________________"<<k+1<<"____________________________________"<<endl;
        cout<<"entrer le nouveau nom : ";
        cin>>e[k].nom;
        f<<e[k].nom<<"\t";


        cout<<"entrer le nouveau prenom : ";
        cin>>e[k].prenom;
        f<<e[k].prenom<<"\t";
        do{
               b=0;
        cout<<"entrer le nouveau cne : ";
        cin>>e[k].cne;


        for(int i=0;i<num;i++){
        if(e[k].cne==e[i].cne)
            b++;
        }
        if(b!=0)
        cout<<"cet etudiant deja existe"<<endl;


        }while(b!=0);
        f<<e[k].cne<<"\t";

        do
        {
            cout<<"entrer la note de tp  : ";
            cin>>e[k].notetp;
            if(e[k].notetp>20 || e[k].notetp<0)
                cout<<"*La note doit etre entre 0 et 20*"<<endl;
        }
        while(e[k].notetp>20 || e[k].notetp<0);
        f<<e[k].notetp<<"\t";
        do
        {
            cout<<"entrer la note de cc : ";
            cin>>e[k].notecc;
            if(e[k].notecc>20 || e[k].notecc<0)
                cout<<"*la note doit etre entre 0 et 20*"<<endl;
        }
        while(e[k].notecc>20 || e[k].notecc<0);
        f<<e[k].notecc<<"\t";


        do
        {
            cout<<"entrer la note de cu : ";
            cin>>e[k].notecu;
            if(e[k].notecu>20 || e[k].notecu<0)
                cout<<"*la note doit etre entre 0 et 20*"<<endl;
        }
        while(e[k].notecu>20 || e[k].notecu<0);
        f<<e[k].notecu<<"\t";



        e[k].notef=0.35*e[k].notetp+0.15*e[k].notecc+0.5*e[k].notecu;
        f<<e[k].notef<<"\t";

        if(e[k].notef>12)
        {
            e[k].r='V';
            f<<e[k].r<<endl;
        }

        else
        {
            e[k].r='R';
            f<<e[k].r<<endl;
        }

    }
    f.close();
    num=num+m;
}

void etudiant::supprimer(string nomfichier,etudiant *e,string CNE)          //fonction pour supprimer un etudiant
{

    bool ex=false;
    int i;
    for(i=0; i<num; i++)
    {
        if(CNE==e[i].cne)
        {
            ex=true;
            break;
        }

    }

    if(ex)
    {
        for(int j=i; j<num-1; j++)
        {
            e[j].nom=e[j+1].nom;                           //on remplace l'etudiant suivant par l'etudiant qu'on veut supprimer et on reduit la taille
            e[j].prenom=e[j+1].prenom;
            e[j].cne=e[j+1].cne;
            e[j].notetp=e[j+1].notetp;
            e[j].notecc=e[j+1].notecc;
            e[j].notecu=e[j+1].notecu;
            e[j].notef=e[j+1].notef;
            e[j].r=e[j+1].r;

        }
        e->num=e->num-1;
        e->save(nomfichier,e);

    }
    else
    {
        cout<<"Ce CNE n'existe pas"<<endl;
    }

}

void etudiant::exist(etudiant *e,string CNE)             //fonction pour chercher un etudiant
{
    int t=0,i;
    for( i=0; i<num; i++)
    {
        if(CNE==e[i].cne)
        {
            t++;

            break;
        }
    }
    if(t==0)
    {
        cout<<"cet etudiant n'existe pas"<<endl;
    }

    else
    {
        cout<<"----------------------------------------------------------------------------------------------------------"<<endl;

        cout<<left<<setw(20)<<"| nom";
        cout<<left<<setw(20)<<"| prenom";
        cout<<left<<setw(15)<<"| cne";
        cout<<left<<setw(10)<<"| notetp";
        cout<<left<<setw(10)<<"| notecc";
        cout<<left<<setw(10)<<"| notecu";
        cout<<left<<setw(10)<<"| notef";
        cout<<left<<setw(10)<<"| resultat"<<"|"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------"<<endl;

        cout<<"| "<<left<<setw(18)<<e[i].nom;
        cout<<"| "<<left<<setw(18)<<e[i].prenom;
        cout<<"| "<<left<<setw(13)<<e[i].cne;
        cout<<"| "<<left<<setw(8)<<e[i].notetp;
        cout<<"| "<<left<<setw(8)<<e[i].notecc;
        cout<<"| "<<left<<setw(8)<<e[i].notecu;
        cout<<"| "<<left<<setw(8)<<e[i].notef;
        cout<<"| "<<left<<setw(8)<<e[i].r<<"|"<<endl;
        cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
        cout<<endl<<endl;
    }
}

void etudiant::majorant(string nomfichier)          //fonction qui affiche le majorant
{    etudiant* e=load(nomfichier);
    int k;
    for(int i=0; i<num; i++)
    {
        if(e[i].notef<e[i+1].notef)
            k=i+1;


    }
    cout<<"le majorant est :"<<e[k].nom<<endl;
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------"<<endl;

    cout<<left<<setw(20)<<"| nom";
    cout<<left<<setw(20)<<"| prenom";
    cout<<left<<setw(10)<<"| cne";
    cout<<left<<setw(10)<<"| notetp";
    cout<<left<<setw(10)<<"| notecc";
    cout<<left<<setw(10)<<"| notecu";
    cout<<left<<setw(10)<<"| notef";
    cout<<left<<setw(10)<<"| resultat"<<"|"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------"<<endl;

    cout<<"| "<<left<<setw(18)<<e[k].nom;
    cout<<"| "<<left<<setw(18)<<e[k].prenom;
    cout<<"| "<<left<<setw(8)<<e[k].cne;
    cout<<"| "<<left<<setw(8)<<e[k].notetp;
    cout<<"| "<<left<<setw(8)<<e[k].notecc;
    cout<<"| "<<left<<setw(8)<<e[k].notecu;
    cout<<"| "<<left<<setw(8)<<e[k].notef;
    cout<<"| "<<left<<setw(8)<<e[k].r<<"|"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl<<endl;

}

void etudiant::save(string nomfichier,etudiant* e)    //fonction pour enregistrer les informations dans le fichier
{
    int i,n=num;
    ofstream f;

    f.open(nomfichier.c_str());
    f.close();
    f.open(nomfichier.c_str(),ios::app);
    f<<"Nom\t";
    f<<"Prenom\t";
    f<<"CNE\t";
    f<<"Note TP\t";
    f<<"Note CC\t";
    f<<"Note CU\t";
    f<<"Note F\t";
    f<<"Resultat"<<endl;
    for(i=0; i<n; i++)
    {
        f<<e[i].nom<<"\t";
        f<<e[i].prenom<<"\t";
        f<<e[i].cne<<"\t";
        f<<e[i].notetp<<"\t";
        f<<e[i].notecc<<"\t";
        f<<e[i].notecu<<"\t";
        f<<e[i].notef<<"\t";
        f<<e[i].r<<"\t"<<endl;


    }
    f.close();
}


etudiant *etudiant::load(string nomfichier)    //Charger les données des étudiants du fichier vers la console
{
    int z=0;
    ifstream g;
    ofstream f;
    string h;
    f.open(nomfichier.c_str(),ios::app);
    etudiant *e=new etudiant[100];
    g.open(nomfichier.c_str());
    int i=0;

    while(getline(g,h))       //cette fonction prend ligne par ligne et divise chaque donnée par le delimiteur "\t" et les stock dans la variable pch
    {
        if(z>0)
        {
            int n = h.length();
            char char_array[n + 1];
            strcpy(char_array, h.c_str());
            char* pch = strtok(char_array,"\t");

            int w=0;
            while (pch != NULL && w<8)
            {
                switch(w)
                {

                case 0:
                    e[i].nom=pch;
                    break;

                case 1:
                    e[i].prenom=pch;
                    break;

                case 2:
                    e[i].cne=pch;
                    break;
                case 3:
                    e[i].notetp=atof(pch);
                    break;
                case 4:
                    e[i].notecc=atof(pch);
                    break;
                case 5:
                    e[i].notecu=atof(pch);
                    break;
                case 6:
                    e[i].notef=atof(pch);
                    break;
                case 7:
                    e[i].r=pch;
                    break;
                default:
                    break;
                }
                pch = strtok (NULL, "\t");

                w++;

            }
            i++;
        }
        z++;
    }
    if(z==0)
    {
        f<<"Nom\t";
        f<<"Prenom\t";
        f<<"CNE\t";
        f<<"Note TP\t";
        f<<"Note CC\t";
        f<<"Note CU\t";
        f<<"Note F\t";
        f<<"Resultat"<<endl;
        z++;
    }

    f.close();
    g.close();
    e->num=z-1;
    return e;
}



void etudiant::moyenneclasse(string nomfichier){     ////fonction pour calculer la moyenne de la classe
    etudiant *e=e->load(nomfichier);
    float s=0,moy;
    int i;
for(i=0;i<num;i++){
    s=s+e[i].notef;
}
moy=s/num;
cout<<"La moyenne de la classe est : "<<moy<<endl;


}

int main()
{
    cout<<" {-----------------------------------------------------------------------------------------------------------------}"<<endl;
    cout<<" {                                                 BIENVENUE !                                                     }"<<endl;
    cout<<" {-----------------------------------------------------------------------------------------------------------------}"<<endl;
    ofstream f;
    string nomfichier,ext=".xls";
    cout<<"                                                                                     Premier mini-projet"<<endl;
    cout<<"                                                                                     Encadre par: Mr.Hicham Ghennioui"<<endl;

    int n,j,c,m;
    string CNE;
    cout<<endl<<endl;
    cout<<"Entrez le nom du fichier : ";
    cin>>nomfichier;
    nomfichier=nomfichier+ext;
    etudiant *e=e->load(nomfichier);
    cout<<endl<<endl;

    do
    {
        cout<<"                      _________________________________MENU_________________________________"<<endl;
        cout<<"                     |                                                                     |"<<endl;
        cout<<"                     |                     Choisir l'operation desiree :                   |"<<endl;
        cout<<"                     |_____________________________________________________________________|"<<endl;
        cout<<"                     |1) Ajouter des etudiants                                             |"<<endl;
        cout<<"                     |2) Modifier les infos d'un etudiant                                  |"<<endl;
        cout<<"                     |3) Supprimer un etudiant                                             |"<<endl;
        cout<<"                     |4) Afficher la liste des etudiants                                   |"<<endl;
        cout<<"                     |5) Chercher un etudiant                                              |"<<endl;
        cout<<"                     |6) Afficher le majorant de la classe                                 |"<<endl;
        cout<<"                     |7) Afficher la moyenne de la classe                                  |"<<endl;
        cout<<"                     |                                                                     |"<<endl;
        cout<<"                     |0) Quitter                                                           |"<<endl;
        cout<<"                     |_____________________________________________________________________|"<<endl;
        cout<<endl;
        cout<<"Entrez votre choix : ";
        cin>>c;
        cout<<endl<<endl<<endl;
        switch (c)
        {

        case 0:
            cout<<" {-----------------------------------------------------------------------------------------------------------------}"<<endl;
            cout<<" {                                                  A LA PROCHAINE !                                               }"<<endl;
            cout<<" {-----------------------------------------------------------------------------------------------------------------}"<<endl;

            break;
        case 2:


            cout<<"entrer le cne a modifier : ";
            cin>>CNE;
            cout<<endl<<endl;

            e->modifier(nomfichier,CNE);

            break;
        case 4:


            e->afficher(nomfichier);
            break;
        case 1:
            cout<<"combien d'etudiant voulez vous ajouter : ";
            cin>>m;
            cout<<endl<<endl;
            e->ajouteretudiant(nomfichier,e,m);
            break;

        case 3:
            cout<<"entrer le cne a supprimer : ";
            cin>>CNE;
            cout<<endl<<endl;
            e->supprimer(nomfichier,e,CNE);
            break;

        case 5:
            cout<<"entrer le cne a chercher : ";
            cin>>CNE;
            cout<<endl<<endl;
            e->exist(e,CNE);
            break;

        case 6:
            e->majorant(nomfichier);
            break;
        case 7:
            e->moyenneclasse(nomfichier);
            break;
        }
    }
    while(c!=0);
}

