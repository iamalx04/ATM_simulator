#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <iomanip>


using namespace std;


int main()
{
    system("Color 70");
    ifstream in("date.in");
    ofstream in2("date_copy.in");

    char s[200], copy[200], v[6], pi[5], sum[10], *p;
    int op=0,ok=0,cash, var=2, ok1=0;
    cout<<"BANCA TRANSILVANIA"<<endl<<endl<<endl;
    cout << endl<<endl<< setw (110)<< "Bine ati venit la Banca Transilvania! Daca doresti sa devii client al bancii noastre, introdu cifra 0. ";
    cout << endl<<endl<< setw (190)<< "Introdu codul de client: ";
    cin.getline(v,6);
    if(atoi(v)==0)
    {
        ofstream out2("copy.txt");
        string line;
        while(in.getline(s,200) && !in.eof())
        {
            out2<<s<<endl;
            p=strtok(s," ");

        }
        int t=atoi(p+3)+1;
        int pin;
        in.close();
        out2.close();

        ifstream in7("copy.txt");
        ofstream out5("date.in");
        while(in7.getline(s,200)) out5<<s<<endl;

        cout<<endl<<endl;
        cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl<<endl;
        cout<<"Va multumim ca ati ales sa fiti client la Banca Transilvania! Codul dumneavoastra de client este: "<<"000"<<t<<endl;
        out5<<"000"<<t<<" ";
        cout<<endl<<endl<<"Sa trecem la inregistrarea datelor dumneavoastra in sistemul bancii!"<<endl<<endl<<endl<<"In primul rand, va rugam sa introduceti numele si prenumele dumneavoastra!"<<endl<<endl;
        char nume[100];

        cin.getline(nume, 100);
        out5<<nume<<" ";
        system("cls");
        cout<<"Foarte bine! Acum va rugam sa alegeti un cod PIN prin care sa va accesati contul!"<<endl;
        cin>>pin;   out5<<pin<<" "<<"0";
        system("cls");
        cout<<"Totul este in regula! A fost atat de usor sa deveniti client al Bancii Transilvania!"<<endl<<"Din acest moment, va puteti bucura de benficiile unui cont deschis la banca noastra!"<<endl;
        return 0;
    }
    else{
   system("cls");

    while(in.getline(s,200) && ok==0) //se cauta codul de client in baza de date
    {
        strcpy(copy, s);
    p=strtok(s, " ");

    if(strcmp(p,v)==0) {ok=1; break;}
    else in2<<copy<<endl;

    }

    if(ok==0) cout << endl<<endl<< setw (210)<<"Codul de client introdus nu se afla in baza noastra de date!";
    else
    {
       cout << endl<<endl<< setw (175)<<"Bine ai venit, ";
      in2<<p<<" ";
      p=strtok(NULL, " "); cout<<p<<" ";
      in2<<p<<" ";

      p=strtok(NULL, " "); cout<<p<<"!"<<endl;
      in2<<p<<" ";

      p=strtok(NULL, " ");
      in2<<p<<" ";

      cout << endl<<endl<< setw (190)<<"Introdu codul PIN: ";
    cin.getline(pi,5);

    while((strcmp(pi,p)!=0) && (var>0))
      { cout << endl<<endl<< setw (75)<<"Codul pin a fost introdus gresit! Mai ai "<<var<<" incercari"<<endl;
      cout << endl<<endl<< setw (190)<<"Introdu codul PIN: ";
          cin.getline(pi,5);
          var--;
      }

          if(var==0) {cout << endl<<endl<< setw (190)<<"Ai atins limita de incercari!"; return 0;}
          else
            {    system("cls");
            while(op>3 || op<1){
            cout << endl<<endl<< setw (198)<<"Alege ce operatiune vrei sa executi:"<<endl;

         cout<< setw (190)<<"1. Retragere numerar;"<<endl;
         cout<< setw (189)<<"2. Depunere numerar;"<<endl;
         cout<< setw (188)<<"3. Verificare sold;"<<endl;
         cin>>op;

         p=strtok(NULL, " ");

         system("cls");

        int x,y,j;
        j=atoi(p);

         if(op==1){

            cout << endl<<endl<< setw (200)<<"Introdu suma pe care vrei sa o retragi: ";
            cin.ignore();
            cin.getline(sum,9);

           x=atoi(sum);


           if(x>j) {cout << endl<<endl<< setw (190)<<"Fonduri insuficiente!"; in2<<p<<endl;}
           else {y=j-x;

    cout << endl<<endl<< setw (193)<<"Soldul actual din cont este: "<<y;
            in2<<y<<endl;
           }



                    }
         else
         if(op==2){cout << endl<<endl<< setw (200)<<"Introdu suma pe care vrei sa o depui: ";
                    cin.ignore();
                    cin.getline(sum,9);
                    x=atoi(sum);
                    if(x<=0) {cout << endl<<endl<< setw (205)<<"Nu se poate depune o suma mai mica sau egala cu 0"; in2<<p<<endl;}
                    else{
                    y=x+j;


    cout << endl<<endl<< setw (193)<<"Soldul actual din cont este: "<<y;}
            in2<<y<<endl;



                    }
        else
         if(op==3){cout << endl<<endl<< setw (193)<<"Suma disponibila in cont: "<<p; in2<<p<<endl;
         }

         else {cout << endl<<endl<< setw (194)<<"Ai introdus o valoare gresita!"<<endl; in2<<p<<endl;}

            }
            }

    }


    while(in.getline(s,200))
   {
       in2<<s<<endl;
   }

   in.close();
   in2.close();

   ifstream in3("date_copy.in");
   ofstream in4("date.in");

   char mut[200];
   while(in3.getline(mut, 200))
   {
       in4<<mut<<endl;
   }

 cout << endl<<endl<< setw (205)<<"Multumim pentru utilizarea bancomatelor noastre!"<<endl;
 cout << endl<<endl<< setw (200)<<"Va asteptam cu drag si data viitoare!"<<endl;
    return 0;}
}
