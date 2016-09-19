
#include <iostream>
#include<cstdlib>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdio.h>

using namespace std;
bool miecz=false, zbroja=false;
bool lew=true;
bool zaklecie=false;
int HP=100,liczba,liczba2, sila=10,zrecznosc=10,szczescie=0,wrogS,wrogZ,wrogHP;
string imie, odp, akcja;
char *tr(char *str)
  {
   static char buff[256];
   char cp[]="\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215ąćęłńóśżźĄĆĘŁŃÓŚŻŹ";
   if(strlen(str)>=sizeof(buff)) return str;
   char *bf=buff;
   while(*str)
     {
      char *pos=strchr(cp+18,*str);
      *(bf++)=pos?*(pos-18):*str;
      ++str;
     }
   *bf=0;
   return buff;
  }
void LvlUp (int &sila, int &zrecznosc ,int &szczescie)
{
    cout<<endl<<"Awans!"<<endl<<tr("Masz 4 punkty doświadczenia do rozdysponowania")<<endl;
    for (int i=0; i<4; i++)
    {
        string wybor;
        cout<<"Co rozwijasz?"<<endl;
        cin>>wybor;
        if (wybor == ("siła"))
        {
            sila++;
            cout<<tr("siła zwiększona")<<endl<<endl;
        }
        if (wybor == "zręczność")
        {
            zrecznosc++;
            cout<<tr("zręczność zwiększona")<<endl<<endl;
        }
        if (wybor == "szczęście")
        {
            szczescie++;
            cout<<tr("szczęscie zwiększone")<<endl<<endl;
        }
    }
    cout<<tr("twoje obecne statystyki wyglądają następująco:")<<endl;
    cout<<tr("siła-")<<sila<<endl;
    cout<<tr("zręczność-")<<zrecznosc<<endl;
    cout<<tr("szczęscie-")<<szczescie<<endl;


}
void walka (int & hp ,int &sila, int&zrecznosc,int&szczescie,int&wrogS,int &wrogZ,int &wrogHP)
{

    int bron,atak;
    if (miecz) bron=10;
    cout<<tr("Ty:             Wróg:")<<endl;
    cout<<"   "<<HP<<"              "<<wrogHP<<endl;
    cout<<"   "<<sila<<"            "<<wrogS<<endl;
    cout<<"   "<<zrecznosc<<"       "<<wrogZ<<endl;
    cout<<"   "<<szczescie<<"        Luck not involved"<<endl;

    while(HP>0 && wrogHP>0)
    {

        srand(time(NULL));
        liczba=rand()%10+1;


        liczba2=rand()%10+1;

        if( (zrecznosc*liczba)>(wrogZ*liczba2) )
        {


            if(szczescie > ((liczba+liczba2)/2))
            {
                cout<<"TRAFIENIE KRYTYCZNE!!!!!!       "<<liczba<<"     "<<liczba2<<endl;
                atak =((sila*bron)-((wrogS*liczba2)/2));
                wrogHP=wrogHP-atak;
                cout<<"atak- "<<atak<<endl;
                cout<<tr("Życie wroga- ")<<wrogHP<<endl;
                cout<<"Twoje HP- "<<HP<<endl<<endl<<endl;
                Sleep(10000);

            }

            else
            {
                atak=(sila*bron)-((wrogS*liczba2));
                wrogHP=wrogHP-atak;
                cout<<"TRAFIENIE"<<"            "<<liczba<<"     "<<liczba2<<endl;
                cout<<"atak- "<<atak<<endl;
                cout<<tr("życie wroga- ")<<wrogHP<<endl;
                cout<<"Twoje HP- "<<HP<<endl<<endl<<endl;
                Sleep(10000);
            }
        }
        else
        {
            atak =((wrogS*liczba2))-(sila*liczba);
            HP = HP-atak;
            cout<<tr("ZOSTALEŚ TRAFIONY")<<"            "<<liczba<<"     "<<liczba2<<endl;
            cout<<"atak- "<<atak<<endl;
            cout<<tr("Życie wroga- ")<<wrogHP<<endl;
            cout<<"Twoje HP- "<<HP<<endl<<endl<<endl;
            Sleep(10000);
        }
    }
}


void ruch (int & x, int & y, int t[][3])//czemu tu jest puste?
{
    string move;
    cout<<"twoja pozycja "<<x<<" "<<y<<" a numer pokoju to: "<<t[x-1][y-1]<<endl;
    cin>>move;
    if(move=="north"||move=="n") y--;
    if(move=="south"||move=="s") y++;
    if(move=="west"||move=="w") x--;
    if(move=="east"||move=="e") x++;
    if(x==4 && y==3)
    {
        cout<<"wygrana...";
        exit(0);
    }
}

void powitanie (string imie)
{
    cout<<"Podaj swoje imie:";
    cin>>imie;
    cout<<"Witaj w mojej grze!"<<endl<<"Na poczatek kilka zasad:"<<endl<<endl<<endl<<"1. Postepuj zgodnie z instrukcjami"<<endl<<"2.Nie wpisuj w wiersz polecen niepotrzebnych"<<endl<<endl<<endl<<"Sterowanie:"<<endl<<endl<<"jak w otchlani xd"<<endl<<"To chyba wszystko, mam nadzieje ze gra ci sie spodoba\nPs.Postaraj sie nie zginac\n\n\n";
//Sleep(12000);
    cout<<imie<<"!\a\n";
//Sleep(5000);
    cout<<imie<<"!\a\n";
//Sleep(6000);
    cout<<imie<<"!\a\n";
//Sleep(7000);
    cout<<tr("Budzisz się w ciemnym pomiesczeniu, masz wrażenie że ktoś cię wołał...\n Wstajesz, otrzepujesz się i wiesz że masz 100hp i znaleźć pomieszczenie z meta\n\n\n");
}
int niepowodzenie(int a)
{
    if(zbroja==true)
    {
        a=a-10;
        cout<<tr("Dzięki zbroi dostajesz tylko połowę obrażeń, hp zmniejszone o 10\n")<<endl;
    }
    else
    {
        a=a-20;
        cout<<tr("Dostajesz obrażenia, hp zmniejszone o 20\n");
    }
    return a;
}


bool funkcja2()
{
    if(miecz==false)
    {


        cout<<tr("Spotykasz sfinksa, aby przejść dalej musisz odpowiedzieć na jego zagadkę\n");
        cout<<tr("Noc jej nie czuje i nie widzą oczy\n");
        cout<<tr("ucho nie słyszy, gdy bez ciała kroczy\n");
        cout<<tr("w dziurach zalega i ponad gwiazdami\n");
        cout<<tr("w wodnych glębinach i hen pod wzgórzami\n");
        cout<<tr("pierwsza przychodzi i ostatnia mija\n");
        cout<<tr("kres niesie życiu i radość zabija\n");
        cout<<tr("znasz odpowiedź?\n");
        cin>>odp;
        if(odp=="ciemnosc")
        {
            cout<<"masz miecz!"<<endl;
            miecz=true;
            LvlUp(sila,zrecznosc, szczescie);

        }
        else
        {
            cout<<"bledna odpowiedz";
            HP=niepowodzenie(HP);
            cout<<"zostalo Ci "<<HP<<endl;

        }
    }
    else cout<<"Sfinks zastygł po rozwiazaniu zagadki";

}




int lecznie (int hp)
{
    hp=hp+40;
    return hp;
}


void smierc()
{
    cout<<" sorry umierasz - game over"<<endl;
    exit(0);
}

void funkcja3(bool & zbroja, bool & lew)
{
    if(lew==true)
    {

        cout<<"Przed wejsciem do pokoju slyszysz wibrujacy gleboki dzwiek wchodzisz masz lwa, skradasz sie czy go ciupasz? bez miecza bedzie to klopotliwe\n"<<endl;
        cout<<"\n-----------------------------------------------"<<endl<<"1.zabij\n2.sproboj sie przekrasc\n-----------------------------------------------\n";
        cin>>odp;
        srand(time(NULL));
        liczba=rand()%100+1;
        cout<<liczba;
        if(odp=="1")
        {
            if((liczba>=50) &&(miecz==true))
            {

                cout<<"Zabiles lwa ktory mial zbroje dostajesz ja\n"<<endl;
                zbroja=true;
                lew=false;
                LvlUp(sila,zrecznosc, szczescie);
            }
            else if (miecz==true)
            {
                cout<<"lew siê obudzi³ i zanim zdazyles mu powiedziec ze masz miecz i zeby sie odpieprzyl zranil cie\n";
                niepowodzenie(HP);

            }
            if (miecz==false)
            {
                cout<<"Jestes skonczonym idiota jesli chciales zabic lwa golymi renkami, lew sie zbudzil i zanim zdazyles\npowiedziec sory rozerwal cie na strzempy\n";
                smierc();
                cout<<HP<<endl;

            }
        }
        if (odp!="1")
        {
            if(liczba<=75)
            {
                cout<<"udalo ci sie przejsc niepostrzezenie\n";

            }
            else
            {
                cout<<"lew sie zbudzil i zanim zadazyles uciec zdazyl cie zranic\n";
                niepowodzenie(HP);

            }
        }
    }
    else cout<<"Pokonales juz lwa\n";
}
bool funkcja4()
{
    if(zbroja==true)
    {
        string wymiana;
        cout<<"Spotykasz tajemniczego mistyka który w zamian za zbroje chce cie uleczyc, czy chcesz mu ja oddac\n?";
        cout<<"\n-----------------------------------------------"<<endl<<"1.tak\n2.nie\n-----------------------------------------------\n";
        cin>>wymiana;
        if (wymiana=="1")
        {
            zbroja=false;
            HP=lecznie(HP);
            cout<<"Oddajac zbroje mistykowi czujesz jak wypelnia cie tajemnicza sila   uleczono 40hp\n"<<HP;
            cout<<"Mistyk nauczyl ciebie paru nowych sztuczek";
            LvlUp(sila,zrecznosc, szczescie);
            return zbroja;

        }
        else cout<<"odchodzisz od mistyka z poczuciem odrzuconej szansy";

    }
    else
    {
        cout<<"Spotykasz tajemniczego mistyka ktory nie ma nic do zaoferowania";
        return zbroja;
    }
}
void funkcja5(int & x, int & y)
{
    if(miecz==false)
    {
        cout<<"zdobadz mnecz aby wejsc\n";
        x=1;
        y=1;
    }
    else
    {
        cout<<"Nic tu nie ma ";
    }
}
void funkcja6(bool & zaklecie)
{
    cout<<"Sala do ktorej wszedles wyglada na zagraconą pracownie pelna ksiazek, slojow i innych przedmiotow niewiadomego pochodzenia.\nPokoj przypomina troche labolatorium szalonego maga...\n";
    cout<<"Po dluzszym przeszukiwaniu tajemniczego miejsca zauwazasz w kacie jakas przygarbiona postac,\n mozesz zaburzyc spokoj czlowieka skrytego w mroku,\n lub odejsc majac nadzieje ze mieszkaniec tej komnaty sie toba nie zainteresuje.\nCo robisz?";
    cout<<"\n-----------------------------------------------"<<endl<<"1.zbadaj\n2.odejdz\n-----------------------------------------------\n";
    cin>>akcja;

    if(akcja=="1")
    {
        cout<<"Po krotkim zastanowieniu postanowiles zmacic odpoczynek tajemniczej postaci, na szczescie dla ciebie po wypowidzeniu slow\n''hallo prosze pana, czy slyszy mnie pan?'' czlowiek nie odpowiedzial\nbo nie zyl.\nTo co wydawalo sie przygarbionym starcem okazalo sie przygarbionym szkieletem\n";
        Sleep(12000);
        cout<<"Zazwyczaj szkielety nie wzbudzaja  twojego zainteresownia, zazwczyczaj tez nie sciskaja pieczolowicie zamknietej skrzyneczki ,a na szyji nie ma ja klucza akurat do nie jej pasujacego\n";
        Sleep(12000);
        cout<<"w skrzynce znajdowal sie kawalek pergaminu na ktorym bylo napisane ''Endaem wend di som'' cokolwiek to znaczy...";
        zaklecie=true;

    }

}
void funkcja7()
{

}



int main ()
{

    powitanie(imie);

//tworzenie planszy
    int numer=1;
    int lochy [4][3];
    for (int j=0; j<=2; j++)
        for(int i=0; i<=3; i++)
        {
            lochy[i][j]=numer;
            numer++;
        }

    int x=1, y=1;

    for (int i=0; i<30; i++) //Po co jeest ten fragment?1
    {
        ruch(x,y, lochy);

        if(lochy[x-1][y-1]==2) funkcja2();
        if(lochy[x-1][y-1]==3) funkcja3(zbroja,lew);
        if(lochy[x-1][y-1]==4) funkcja4();
        if(lochy[x-1][y-1]==5) funkcja5(x,y);
        if(lochy[x-1][y-1]==6) funkcja6(zaklecie);
        if(lochy[x-1][y-1]==7) funkcja7();
        /*if(lochy[x-1][y-1]==8) funkcja8();
        if(lochy[x-1][y-1]==9) funkcja9();
        if(lochy[x-1][y-1]==10) funkcja10();
        if(lochy[x-1][y-1]==11) funkcja11();
        if(lochy[x-1][y-1]==12) funkcja12();

        */
    }
    return 0;
}
