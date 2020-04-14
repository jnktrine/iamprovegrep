#include <iostream>     //biblioteka standardowych procedur wejscia/wyjscia
#include <fstream>      //biblioteka do obsługi plików
#include <string>       //biblioteka obsługi łańcuchów znaków
#include <stdio.h>      //biblioteka do clrscr
#include <algorithm>    //biblioteka do sortowania
#include <stdlib.h>     //losowość

using namespace std;

///////////////////////////////////////////////////////////
//                                                       //
//  STRUKTURA PLIKU                                      //
//  1. Deklaracje zmiennych, procedur i funkcji          //
//  2. Funkcja główna                                    //
//  3. Definicje procedur i funkcji                      //
//                                                       //
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
//                                                       //
//  1.1. Deklaracje zmiennych, procedur i funkcji        //
//                                                       //
///////////////////////////////////////////////////////////

// ZMIENNE GŁÓWNE

int A = 0; //wartość animals
int E = 0; //wartość environment
int S = 0; //wartość social justice
int H = 0; //wartość health
int T = 0; //wartość taste

fstream wyniki; //plik, w którym zapisywane są wyniki testów
fstream oceny;  //plik, w którym zapisywane są oceny testu
fstream opinie; //plik, w którym zapisywane są i

int numer = 0;      //licznik pytań
int numer2 = 0;      //licznik pytań pomocniczych
int archetyp = 0;   //określenie archetypu

// archetyp jest zapisany jako liczba dwucyfrowa
// liczba dziesiątek oznacza piwerszy dominujący archetyp
// liczba jedności oznacza drugi dominujący archetyp
// np. 50 - to archetyp z dominującą wartością animals, 54 - archetyp z dominującymi wartościami animals i environment. Liczba 60 oznacza dodatkowy archetyp, bez dominujących pro

// ZMIENNIE POMOCNICZE

int wyjscie = 0; //warunek wyjścia z pętli
int wybor; //zmienna wybierana

///////////////////////////////////////////////////////////
//  1.2 deklaracje procedur pomocnicznych                //
///////////////////////////////////////////////////////////

void intro(); // rysuje logo advalue
void myflush ( FILE *in ); //czyści bufor znaków
void mypause ( void ); //czeka na enter, żeby kontynuować

///////////////////////////////////////////////////////////
//  1.3 deklaracje procedur i funkcji zasadniczych       //
///////////////////////////////////////////////////////////

void pytanie(string pyt1, string pyt2, string aa, string be, string ce, int *a, int *b, int *c);
//wyświetla pytanie i pobiera odpowiedź, zmienia wartość A,E,S,H,T

void pytanie2(int *a, int *b, int *c);
//symuluje losową odpowiedź na pytanie, zmienia wartość A,E,S,H,T

void algorytm();
//przypisuje wartość do zmiennej archetyp na podstawie odpowiedzi

//przypisuje wartość do zmiennej archetyp na podstawie odpowiedzi
void rezultat(string nazwa, string opis1, string opis2, string dominacja);
//wyświetla przyporządkowany archetyp

void ocena(string pyt, string aa, string be, string ce, string de, string ee, int *zmienna);
//wyświetla pytanie do oceny testu

///////////////////////////////////////////////////////////
//                                                       //
//  2. FUNKCJA GŁÓWNA                                    //
//                                                       //
///////////////////////////////////////////////////////////

int main()
{

    srand( time( NULL ) );
    intro();

    while (wyjscie==0)
    {
      A = 0; //wyzerowanie zmiennych
      E = 0;
      S = 0;
      H = 0;
      T = 0;
      numer = 0;
      numer2 = 0;

      cout << "╭─────────────────────────────────────────────────────────╮" << endl;
      cout << "│ Who would you be                                        │" << endl;
      cout << "│ in 2040?               ╭───╮                            │" << endl;
      cout << "│            ▒    ╭───╮  │ oo│     ▒            ╭───╮     │" << endl;
      cout << "│    ▒ ▒     ║    │ooo│  │ oo╰╮ ▒ ╭╨─────╮    ▒ │o o│ ▒ ▒ │" << endl;
      cout << "│ ▒░ ║ ║░ ▒ ░║░▒  │ooo│ ╭╯ Ooo│ ║ │oo╭╮oo│ ▒ ░║ │o o│ ║░║░│" << endl;
      cout << "├─╨╨─╨─╨╨─╨─╨╨╨╨──┴───┴─┴─────┴─╨─┴──┴┴──┴─╨─╨╨─┴───┴─╨╨╨╨┤" << endl;
      cout << "╰──────────────────────────────────────────────────proveg─╯" << endl;
      cout << endl;

      cout << "1. ROZPOCZNIJ TEST          - naciśnij 1 i potwierdź Enter" << endl;
      cout << "2. LOSOWY WYNIK             - naciśnij 2 i potwierdź Enter" << endl;
      cout << "3. SYMULACJA 10 000 TESTÓW  - naciśnij 3 i potwierdź Enter" << endl;
      cout << "4. WYJDŹ Z PROGRAMU         - naciśnij 4 i potwierdź Enter" << endl << endl;
      cout << "Twój wybór: ";
      cin >> wybor;

      if (wybor == 4) //WYJDZ Z PROGRAMU
                {
                  wyjscie = 1;
                  //break;
                } // KONIEC WYJSCIA Z PROGRAMU

      else if (wybor == 1) //ROZPOCZNIJ TEST ///////////////////////////////////
                {
                //Rozpocznij test: pytania
                printf("\033[H\033[2J");
                cout << "'Jest poranek, sobota, 14 lipca 2040 roku. Powietrze przejrzyste," << endl;
                cout << "nasłonecznienie wysokie' - budzi Cię informacja domowej SI." << endl << endl;

                pytanie ("Dzień zaczynasz od...", " ",
                           "zmiksowania ulubionego smoothie ze świeżych owoców",
                           "uzupełnienia poidełka dla ptaków na tarasie",
                           "sprawdzenia parametrów swojego snu",
                           &T, &A, &H);
                pytanie ("W czasie śniadania przegląsza newsy. Twoją uwagę przykuwa informacja:", " ",
                           "o sukcesie programu zwiększenia populacji misiów Koala",
                           "o zahamowaniu wzrostu zachorowań na cukrzycę",
                           "o trzykrotnym zmniejszeniu skali marnowania żywności na świecie",
                           &A, &H, &S);
                pytanie ("Wychodzisz z kawą na taras, z którego rozpościera się widok na:", " ",
                           "hyde park wolnej wymiany myśli i idei ",
                           "rezerwat dający schronienie dzikim zwierzętom",
                           "zautomatyzowaną plantację soczystych awokado",
                           &S, &E, &T);
                pytanie ("Twój taras również tonie w zieleni. Można wśród niej znaleźć:", " ",
                           "szafran, imbir i kolendrę",
                           "grządkę odzywczego jarmużu",
                           "budkę lęgową dla ptaków",
                           &T, &H, &E);
                pytanie ("Do tarasu dokuje dron kurierski. Odbierasz zakupy ze sklepu:", " ",
                           "kooperatywy spożywczej zrzeszającej rolników",
                           "z żywnością funkcjonalną",
                           "z delikatesami z całego świata",
                           &S, &H, &T);
                pytanie ("Ubierasz się do wyjścia. W Twojej garderobie:", " ",
                           "dominują ubrania uszyte z bawełny fair-trade",
                           "są głównie rzeczy z second-handów i freeshopów",
                           "nie ma przedmiotów ze skóry i futra",
                           &S, &E, &A);
                pytanie ("Po wyjściu z domu", " ",
                           "idziesz na przystanek bezemisyjnej kolejki podmiejskiej",
                           "wsiadasz na rower i włączasz licznik spalonych kalorii",
                           "wsiadasz do taksówki z lokalnej kooperatywy przewozowej",
                           &E, &H, &S);
                pytanie ("Jesteś już w centrum. W infrastrukturze miasta przyszłości" , "najbardziej cieszą Cię:",
                           "społeczne jadłodajnie serwujące bezpłatne posiłki dla potrzebujących",
                           "ściany budynków porośnięte roślinami oczyszczającymi powietrze",
                           "ogólnodostępne parki fitness z obniżoną grawitacją",
                           &S, &E, &H);
                pytanie ("Mijasz remontowany budynek starej fabryki. Na dotykowej tablicy", "możesz zagłosować co powinno w nim powstać:",
                           "inkubator biznesów i inicjatyw prospołecznych",
                           "azyl dla miejskich zwierząt",
                           "śródmiejski targ śniadaniowy",
                           &S, &A, &T);
                pytanie ("Udajesz się do nowo otwartego Centrum Nauki. Spośród atrakcji wybierasz:", " ",
                           "ogród akademii odtwarzającej wymarłe gatunki zwierząt",
                           "strefę VR, w której można poczuć smak dowolnej potrawy na świecie",
                           "interaktywą grę, której celem jest stworzenie ekosystemu leśnego",
                           &T, &A, &E);
                pytanie ("Przy wyjściu z Centrum Nauki automat proponuje Ci wsparcie", "wybranej inicjatywy. Przekazujesz datek na:",
                           "zasadzenie drzewa",
                           "posiłek dla głodnego dziecka",
                           "lecznicę zwierząt",
                           &E, &S, &A);
                pytanie ("Zapach z mijanych lokali gastronomicznych przypomina Ci, że czas na obiad.", "Udajesz się do restauracji:",
                           "z najwyższą oceną na Trendy Foods",
                           "która takie samo danie jak Twoje przekaże także potrzebującemu",
                           "serwującej dania na bazie superfoods",
                           &T, &S, &H);
                pytanie ("Przeglądasz menu, w którym możesz poczuć zapach dań. Przy zamówieniu:", " ",
                           "kierujesz się bogactwem składników i apetycznym wyglądem",
                           "zwracasz uwagę, żeby potrawa była w pełni roślinna",
                           "wybierasz dania z certyfikatem lokalnego pochodzenia",
                           &T, &A, &E);
                pytanie ("Było pyszne! Po obiedzie idziesz się na spacer przez park.", "Wybierasz ścieżkę:",
                           "biegnącą wzdłuż siedlisk zwierząt",
                           "z wirtualnym przewodnikiem po otaczającej Cię roślinności ",
                           "z powietrzem o wyższym stężeniu jodu",
                           &A, &E, &H);
                pytanie ("Masz w planie spotkanie z przyjaciółmi. Proponujesz im:", " ",
                           "spotkanie z Noblistą w dziedzinie zaangażowania społecznego",
                           "turniej kulinarny najlepszych kucharzy świata",
                           "symulator nurkowania wśród wodnych zwierząt",
                           &S, &T, &A);
                pytanie ("Ciesząc się z udanego dnia, wsiadasz do kolejki,", "która zawiezie Cię do domu:",
                           "na osiedlu neutralnym klimatycznie",
                           "do dzielnicy leśnej pełnej dzikich zwierząt",
                           "w strefie odtwarzającej czyste górskie powietrze",
                           &E, &A, &H);
                pytanie ("W Twoim domu najważniejszym miejscem jest", " ",
                           "kuchnia z holograficznym kucharzem ",
                           "zielony taras z mikroogrodem",
                           "łaźnia do odnowy biologicznej",
                           &T, &E, &H);
                pytanie ("Po kolacji oglądasz hologramowy odcinek:", " ",
                           "Battle of Amazonia - o utworzeniu Ekologicznych Sił Szybkiego Reagowania",
                           "Social Avengers - o przekształcaniu terenów pustynnych w obszary uprawne",
                           "Odysei Kulinarnej - o gotowaniu w stanie nieważkości",
                           &E, &S, &T);
                pytanie ("Planujesz co będziesz robić kolejnego dnia. Decydujesz się na:", " ",
                            "opiekę nad zwierzętami w podmiejskim azylu",
                            "ściankę wspinaczkową w rozszerzonej rzeczywistości",
                            "pomoc w gotowaniu w kuchni społecznej",
                            &A, &H, &S);
                pytanie ("Przed snem:", " ",
                           "zlecasz inteligentnej kuchni zamówienie na pyszne śniadanie",
                           "włączasz automatyczną segregowarkę śmieci",
                           "oddajesz się regeneracji w wannie z hydromasażem",
                           &T, &A, &H);

                //Rozpocznij test: obliczenie i wyświetlenie wyniku

                algorytm(); //zwraca wartość archetyp

                //zapisanie wyniku do pliku
                wyniki.open("wyniki.txt", ios::app);
                if (wyniki.good() == true)
                  {
                  wyniki << archetyp;
                  wyniki.close();
                  }

                  if ((archetyp == 10) or (archetyp == 1))
                      {rezultat("FLAVOUR ARCHITECT",
                               "Tworzysz innowacyjne, wykraczające poza granice naszej wyobraźni smaki",
                               "(...)",
                               "TASTE");
                      }
                  else if ((archetyp == 20) or (archetyp == 2))
                      {rezultat("CHIEF HEALTH OFFICER",
                               "dbasz o zdrowie współpracowników w firmie lub organizacji",
                               "(...)",
                               "HEALTH");
                      }
                  else if ((archetyp == 30) or (archetyp == 3))
                      {rezultat("INTEGRITY ENGINEER",
                               "opracowujesz programy wyrównujące szanse krajów rozwijających się",
                               "(...)",
                               "SOCIAL JUSTICE");
                      }
                  else if ((archetyp == 40) or (archetyp == 4))
                      {rezultat("REFORESTER",
                               "odtwarzasz naturalne ekosystemy leśne na spustynniałych terenach",
                               "(...)",
                               "ENVIRONMENT");
                      }
                  else if ((archetyp == 50) or (archetyp == 5))
                      {rezultat("ANIMAL LINGUISTIC EXPERT",
                               "studiujesz języki zwierząt społecznych i opracowujesz metody",
                               "komunikacji z nimi (...)",
                               "ANIMALS");
                      }
                  else if ((archetyp == 54) or (archetyp == 45))
                      {rezultat("REKONSTRUKTOR GATUNKÓW",
                               "przywracasz przyrodzie gatunki, które przez człowieka straciły",
                               "swoje naturalne siedliska (...)",
                               "ANIMALS + ENVIRONMENT");
                      }
                  else if ((archetyp == 53) or (archetyp == 35))
                      {rezultat("EQUALITY ARCHITECT",
                               "modyfikujesz i projektujesz infrastrukturę tak,",
                               "żeby była użyteczna dla ludzi i przyjazna dla zwierząt (...)",
                               "ANIMALS + SOCIAL JUSTICE");
                      }
                  else if ((archetyp == 52) or (archetyp == 25))
                      {rezultat("ZOOTERAPIST",
                               "Leczysz ludzi korzystając z pomocy zwierząt",
                               "(...)",
                               "ANIMALS + HEALTH");
                      }
                  else if ((archetyp == 51) or (archetyp == 15))
                      {rezultat("MAESTRO SMAKÓW",
                               "na bazie roślin wyczarowujesz smaki",
                               "tradycyjnych potraw (...)",
                               "ANIMALS + TASTE");
                      }
                  else if ((archetyp == 43) or (archetyp == 34))
                      {rezultat("SUSTAINIBILITY GUIDER",
                               "pomagasz firmom wdrażać rozwiązania odpowiedzialne",
                               "środowiskowo i społecznie (...)",
                               "ENVIRONMENT + SOCIAL JUSTICE");
                      }
                  else if ((archetyp == 42) or (archetyp == 24))
                      {rezultat("EARTH DOCTOR",
                               "oczyszczasz glebę i odtwarzasz naturalny bilans mineralny",
                               "(...)",
                               "ENVIRONMENT + HEALTH");
                      }
                  else if ((archetyp == 41) or (archetyp == 14))
                      {rezultat("DIETARY PRO EDUCATOR",
                               "uczysz dzieci w szkołachzdrowego i odpowiedzialnego żywienia ",
                               "(...)",
                               "ENVIRONMENT + TASTE");
                      }
                  else if ((archetyp == 32) or (archetyp == 23))
                      {rezultat("FOOD SECURITY COUNCILOR",
                               "Dzięki Tobie każdy człowiek ma zapewnione minimalne wyżywienie",
                               "w postaci zbilansowanego pakietu żywności huel (...)",
                               "SOCIAL JUSTICE + HEALTH");
                      }
                  else if ((archetyp == 31) or (archetyp == 13))
                      {rezultat("FOOD EXPLOIT LOGISTIC",
                               "minimalizujesz skalę marnowania żywności opracowując",
                               "logistyczne i prawne rozwiązania jej redystrybucji (...)",
                               "SOCIAL JUSTICE + TASTE");
                      }
                  else if ((archetyp == 21) or (archetyp == 12))
                      {rezultat("HEALTHCARE AI GUIDER",
                               "rozwijasz bazujący na sztucznej inteligencjii projekt",
                               "personalnego dietetyka w smartfonie (...)",
                               "HEALTH + TASTE");
                      }
                  else if (archetyp == 60)
                      {rezultat("MARS COLONIST CANDIDAT",
                               "Masz zrównoważone podejście do świata i możesz być wzorem dla innych!",
                               "Wytypowano Cię na kandydata do pierwszej międzynarodowej kolonii na Marsie.",
                               "BRAK");
                      }



                    cout << "Naciśnij Enter, żeby kontynuować";
                    myflush(stdin);
                    mypause();

                    //Rozpocznij test: zebranie ocen i opinii

                    int ocenaczasu = 0;
                    int ocenatresci = 0;
                    string opinia;

                    ocena("Jak oceniasz czas trwania testu?",
                      "Mógłby być dłuższy",
                      "W sam raz",
                      "Trochę długi, ale ciekawy",
                      "Trochę za długi",
                      "Zdecydowanie za długi", &ocenaczasu);

                    ocena("Czy test (pytania) był dla Ciebie ciekawy?",
                      "Bardzo ciekawy",
                      "Ciekawy",
                      "Nie mam zdania",
                      "Nieciekawy",
                      "Zdecydowanie nieciekawy", &ocenatresci);

                    cout << "Jeżeli chcesz podzielić się swoją opinią na temat testu, wpisz ją teraz!" << endl;
                    cout << "Użyj klawisza Enter, kiedy skończysz wpisywać." << endl << endl;
                    cout << "Twoja opinia: ";
                    myflush(stdin);
                    getline(cin, opinia);
                    cout << endl << endl;
                    cout << "Dzięki za pomoc, Twoje oceny i opinia będą wzięte" << endl;
                    cout << "pod uwagę przy doskonaleniu testu!" << endl << endl;

                    cout << "Naciśnij Enter, żeby wrócić do menu głównego...";
                    //myflush(stdin);
                    mypause();

                    oceny.open("oceny.txt", ios::app);
                    if (oceny.good() == true) {
                    oceny << ocenaczasu;
                    oceny << ocenatresci;
                    oceny.close();
                    }

                    opinie.open("opinie.txt", ios::app);
                    if (opinie.good() == true) {
                    opinie << opinia;
                    opinie.close();
                    }

                    printf("\033[H\033[2J");
                    cout << "  ЯНЭК IamProVeg QuizTester v0.02 ©advalue 2020" << endl << endl;
          } // koniec rozpocznij test

          else if (wybor == 2) //losowy wynik
          {
                pytanie2 (&T, &A, &H);
                pytanie2 (&A, &H, &S);
                pytanie2 (&S, &E, &T);
                pytanie2 (&T, &H, &E);
                pytanie2 (&S, &H, &T);
                pytanie2 (&S, &E, &A);
                pytanie2 (&E, &H, &S);
                pytanie2 (&S, &E, &H);
                pytanie2 (&S, &A, &T);
                pytanie2 (&T, &A, &E);
                pytanie2 (&E, &S, &A);
                pytanie2 (&T, &S, &H);
                pytanie2 (&T, &A, &E);
                pytanie2 (&E, &S, &T);
                pytanie2 (&A, &E, &H);
                pytanie2 (&S, &T, &A);
                pytanie2 (&A, &H, &S);
                pytanie2 (&E, &A, &H);
                pytanie2 (&T, &E, &H);
                pytanie2 (&T, &A, &H);

                algorytm();

                if ((archetyp == 10) or (archetyp == 1))
                    {rezultat("FLAVOUR ARCHITECT",
                             "Tworzysz innowacyjne, wykraczające poza granice naszej wyobraźni smaki",
                             "(...)",
                             "TASTE");
                    }
                else if ((archetyp == 20) or (archetyp == 2))
                    {rezultat("CHIEF HEALTH OFFICER",
                             "dbasz o zdrowie współpracowników w firmie lub organizacji",
                             "(...)",
                             "HEALTH");
                    }
                else if ((archetyp == 30) or (archetyp == 3))
                    {rezultat("INTEGRITY ENGINEER",
                             "opracowujesz programy wyrównujące szanse krajów rozwijających się",
                             "(...)",
                             "SOCIAL JUSTICE");
                    }
                else if ((archetyp == 40) or (archetyp == 4))
                    {rezultat("REFORESTER",
                             "odtwarzasz naturalne ekosystemy leśne na spustynniałych terenach",
                             "(...)",
                             "ENVIRONMENT");
                    }
                else if ((archetyp == 50) or (archetyp == 5))
                    {rezultat("ANIMAL LINGUISTIC EXPERT",
                             "studiujesz języki zwierząt społecznych i opracowujesz metody",
                             "komunikacji z nimi (...)",
                             "ANIMALS");
                    }
                else if ((archetyp == 54) or (archetyp == 45))
                    {rezultat("REKONSTRUKTOR GATUNKÓW",
                             "przywracasz przyrodzie gatunki, które przez człowieka straciły",
                             "swoje naturalne siedliska (...)",
                             "ANIMALS + ENVIRONMENT");
                    }
                else if ((archetyp == 53) or (archetyp == 35))
                    {rezultat("EQUALITY ARCHITECT",
                             "modyfikujesz i projektujesz infrastrukturę tak,",
                             "żeby była użyteczna dla ludzi i przyjazna dla zwierząt (...)",
                             "ANIMALS + SOCIAL JUSTICE");
                    }
                else if ((archetyp == 52) or (archetyp == 25))
                    {rezultat("ZOOTERAPIST",
                             "Leczysz ludzi korzystając z pomocy zwierząt",
                             "(...)",
                             "ANIMALS + HEALTH");
                    }
                else if ((archetyp == 51) or (archetyp == 15))
                    {rezultat("MAESTRO SMAKÓW",
                             "na bazie roślin wyczarowujesz smaki",
                             "tradycyjnych potraw (...)",
                             "ANIMALS + TASTE");
                    }
                else if ((archetyp == 43) or (archetyp == 34))
                    {rezultat("SUSTAINIBILITY GUIDER",
                             "pomagasz firmom wdrażać rozwiązania odpowiedzialne",
                             "środowiskowo i społecznie (...)",
                             "ENVIRONMENT + SOCIAL JUSTICE");
                    }
                else if ((archetyp == 42) or (archetyp == 24))
                    {rezultat("EARTH DOCTOR",
                             "oczyszczasz glebę i odtwarzasz naturalny bilans mineralny",
                             "(...)",
                             "ENVIRONMENT + HEALTH");
                    }
                else if ((archetyp == 41) or (archetyp == 14))
                    {rezultat("DIETARY PRO EDUCATOR",
                             "uczysz dzieci w szkołachzdrowego i odpowiedzialnego żywienia ",
                             "(...)",
                             "ENVIRONMENT + TASTE");
                    }
                else if ((archetyp == 32) or (archetyp == 23))
                    {rezultat("FOOD SECURITY COUNCILOR",
                             "Dzięki Tobie każdy człowiek ma zapewnione minimalne wyżywienie",
                             "w postaci zbilansowanego pakietu żywności huel (...)",
                             "SOCIAL JUSTICE + HEALTH");
                    }
                else if ((archetyp == 31) or (archetyp == 13))
                    {rezultat("FOOD EXPLOIT LOGISTIC",
                             "minimalizujesz skalę marnowania żywności opracowując",
                             "logistyczne i prawne rozwiązania jej redystrybucji (...)",
                             "SOCIAL JUSTICE + TASTE");
                    }
                else if ((archetyp == 21) or (archetyp == 12))
                    {rezultat("HEALTHCARE AI GUIDER",
                             "rozwijasz bazujący na sztucznej inteligencjii projekt",
                             "personalnego dietetyka w smartfonie (...)",
                             "HEALTH + TASTE");
                    }
                else if (archetyp == 60)
                    {rezultat("MARS COLONIST CANDIDAT",
                             "Masz zrównoważone podejście do świata i możesz być wzorem dla innych!",
                             "Wytypowano Cię na kandydata do pierwszej międzynarodowej kolonii na Marsie.",
                             "BRAK");
                    }

            cout << "Naciśnij Enter, żeby wrócić do menu głównego...";
                  myflush(stdin);
                  mypause();

                  printf("\033[H\033[2J");
                  cout << "  ЯНЭК IamProVeg QuizTester v0.02 ©advalue 2020" << endl << endl;

            //break;
          } // koniec losowego wyniku

            else if (wybor == 3)
            {
                printf("\033[H\033[2J");
                cout << endl << endl;
                cout << "Trwa symulacja. Może to chwilę potrwać..." << endl;

                int AA = 0;
                int AE = 0;
                int AS = 0;
                int AH = 0;
                int AT = 0;
                int ES = 0;
                int EH = 0;
                int ET = 0;
                int SH = 0;
                int ST = 0;
                int HT = 0;
                int EE = 0;
                int SS = 0;
                int HH = 0;
                int TT = 0;
                int BB = 0;

                for(int k=0; k<10000; k++)
                {
                  A=0;
                  E=0;
                  S=0;
                  H=0;
                  T=0;
                  numer=0;

                  pytanie2 (&T, &A, &H);
                  pytanie2 (&A, &H, &S);
                  pytanie2 (&S, &E, &T);
                  pytanie2 (&T, &H, &E);
                  pytanie2 (&S, &H, &T);
                  pytanie2 (&S, &E, &A);
                  pytanie2 (&E, &H, &S);
                  pytanie2 (&S, &E, &H);
                  pytanie2 (&S, &A, &T);
                  pytanie2 (&T, &A, &E);
                  pytanie2 (&E, &S, &A);
                  pytanie2 (&T, &S, &H);
                  pytanie2 (&T, &A, &E);
                  pytanie2 (&E, &S, &T);
                  pytanie2 (&A, &E, &H);
                  pytanie2 (&S, &T, &A);
                  pytanie2 (&A, &H, &S);
                  pytanie2 (&E, &A, &H);
                  pytanie2 (&T, &E, &H);
                  pytanie2 (&T, &A, &H);

                  algorytm();

                    if ((archetyp == 10) or (archetyp == 2)) AA++;
                    else if ((archetyp == 20) or (archetyp == 2)) EE++;
                    else if ((archetyp == 30) or (archetyp == 3)) SS++;
                    else if ((archetyp == 40) or (archetyp == 4)) HH++;
                    else if ((archetyp == 50) or (archetyp == 5)) TT++;
                    else if ((archetyp == 54) or (archetyp == 45)) AE++;
                    else if ((archetyp == 53) or (archetyp == 35)) AS++;
                    else if ((archetyp == 52) or (archetyp == 25)) AH++;
                    else if ((archetyp == 51) or (archetyp == 15)) AT++;
                    else if ((archetyp == 43) or (archetyp == 34)) ES++;
                    else if ((archetyp == 42) or (archetyp == 24)) EH++;
                    else if ((archetyp == 41) or (archetyp == 14)) ET++;
                    else if ((archetyp == 32) or (archetyp == 23)) SH++;
                    else if ((archetyp == 31) or (archetyp == 13)) ST++;
                    else if ((archetyp == 21) or (archetyp == 12)) HT++;
                    else if (archetyp == 60) BB++;


                  } //koniec pętli

            cout << "Już! Oto rozkład archetypów dla 10 000 losowo wypełnionych testów:" << endl << endl;
            cout << "ANIMAL:........................." << AA << endl;
            cout << "ENVIRONMENT....................." << EE << endl;
            cout << "SOCIAL JUSTICE:................." << SS << endl;
            cout << "HEALTH:........................." << HH << endl;
            cout << "TASTE:.........................." << TT << endl;
            cout << "ANIMAL + ENVIRONMENT:..........." << AE << endl;
            cout << "ANIMAL + SOCIAL JUSTICE:........" << AS << endl;
            cout << "ANIMALS + HEALTH:..............." << AH << endl;
            cout << "ANIMALS + TASTE:................" << AT << endl;
            cout << "ENIVRONMENT + SOCIAL JUSTICE:..." << ES << endl;
            cout << "ENIVRONMENT + HEALTH:..........." << EH << endl;
            cout << "ENIVRONMENT + TASTE:............" << ET << endl;
            cout << "SOCIAL JUSTICE + HEALTH:........" << SH << endl;
            cout << "SOCIAL JUSTICE + TASTE:........." << ST << endl;
            cout << "HEALTH + TASTE:................." << HT << endl;
            cout << "ALL Z GRUBSZA EQUAL:........... " << BB << endl << endl;


            cout << "Naciśnij Enter, żeby wrócić do menu głównego...";
            myflush(stdin);
            mypause();

            printf("\033[H\033[2J");
            cout << "  ЯНЭК IamProVeg QuizTester v0.02 ©advalue 2020" << endl << endl;

          } //Koniec symulacji

    else {
      cout << endl << "Nierozpoznany wybór. Wybierz 1, 2, 3 lub 4" << endl << endl;
      //break;
      }

  }; //koniec menu głównego

    printf("\033[H\033[2J");
    cout << "  ЯНЭК IamProVeg QuizTester v0.02 ©advalue 2020" << endl << endl;
    cout << "    █   █  █  █▀▀▀  █     █ ▄▀  █  █▀▀▀ " << endl;
    cout << "    ▀▄■▄▀  █  █▀▀▀  █     █▀▄   █  █▀▀▀ " << endl;
    cout << "     ▀ ▀   ▀  ▀▀▀▀  ▀▀▀▀  ▀  ▀  ▀  ▀▀▀▀  "<< endl;
    cout << "    █▀▀▀▄ ▀▀▀█  █  █▀▀▀  █ ▄▀  █  █" << endl;
    cout << "    █   █  ▄▀   █  █▀▀▀  █▀▄   █  ▀" << endl;
    cout << "    ▀▀▀▀  ▀▀▀▀  ▀  ▀▀▀█  ▀  ▀  ▀  ▀ " << endl;
    cout << "za pomoc w rozwijaniu i testowaniu projektu!" << endl;
    cout << endl << endl;

    cout << "Naciśnij Enter, żeby zakończyć.";
          myflush(stdin);
          mypause();

    return 0;
}


///////////////////////////////////////////////////////////
//                                                       //
//  3. DEFINICJE FUNKCJI I PROCEDUR                      //
//                                                       //
///////////////////////////////////////////////////////////


void algorytm()
        {
        int roboczy = 0;
        int p[] = {A*16+5,E*16+4,S*16+3,H*16+2,T*16+1};
                    sort(p, p+5);

                    if (p[4]/16 == 4) roboczy = 60;
                    else if ((p[4]/16 > 5) && (p[4]/16 - p[3]/16) > (p[3]/16 - p[2]/16))
                        {if (p[3]/16 > 4) roboczy = ((p[4]%16)*10) + p[3]%16;
                         else roboczy = (p[4]%16)*10;}
                    else if ((p[4]/16 > p[3]/16) && (p[3]/16 == p[2]/16)) roboczy = (p[4]%16)*10;
                    else if ((p[4]/16 + p[3]/16) > 10) roboczy = ((p[4]%16)*10) + p[3]%16;
                    else if ((p[4]/16 > 5) && (p[4]/16 == p[3]/16)) roboczy = ((p[4]%16)*10) + p[3]%16;
                    else if ((p[4]/16 == 5) && (p[3]/16 == 5) && (p[2]/16 != 5)) roboczy = ((p[4]%16)*10) + p[3]%16;
                    else roboczy = 60;

        archetyp = roboczy;
        }


///////////////////////////////////////////////////////////

void pytanie(string pyt1, string pyt2, string aa, string be, string ce, int *a, int *b, int *c)
    {
    int odp=0;
    int check=0;

    numer++;

    cout << " ╭─ PYTANIE " << numer << "/20 ─────────────────────────────────" << endl;
    cout << " │ " << endl;
    cout << " │ " << pyt1 << endl;
    cout << " │ " << pyt2 << endl;
    cout << " │ " << endl;
    cout << " │ 1. " << aa << endl;
    cout << " │ 2. " << be << endl;
    cout << " │ 3. " << ce << endl;
    cout << " │ " << endl;
    cout << " │ Wybierz odpowiedź (1,2 lub 3) i zatwierdź Enter: ";

    while (check==0)
        {
        cin >> odp;
        if (odp==1)  {*a = *a+1;
                      cout << " │ " << endl;
                      cout << " ╰───────────────────────╴╴╴╴╴╴╴ ╴╴ ╴ ╴ ╴  ╴   ╴    ╴";
                      check=1;} else
            if (odp==2) {*b = *b+1;
                      cout << " │ " << endl;
                      cout << " ╰───────────────────────╴╴╴╴╴╴╴ ╴╴ ╴ ╴ ╴  ╴   ╴    ╴";
                      check=1;} else
                if (odp==3) {*c = *c+1;
                      cout << " │ " << endl;
                      cout << " ╰───────────────────────╴╴╴╴╴╴╴ ╴╴ ╴ ╴ ╴  ╴   ╴    ╴";
                      check=1;} else
                    cout << " │ " << endl << " │ Nieprawidłowy wybór. Wpisz 1, 2 lub 3 i zatwierdź klawiszem Enter: ";
        }
      cout << endl << endl << endl;
    printf("\033[H\033[2J");
    }

///////////////////////////////////////////////////////////

void pytanie2(int *a, int *b, int *c)
    {
    int odp=0;
    int check=0;
    numer++;

    while (check==0)
        {
        odp = rand()%3 + 1;
        if (odp==1)  {*a = *a+1; check=1;} else
            if (odp==2) {*b = *b+1; check=1;} else
                if (odp==3) {*c = *c+1; check=1;};
    }


  }

///////////////////////////////////////////////////////////

void rezultat(string nazwa, string opis1, string opis2, string dominacja)
    {
    printf("\033[H\033[2J");
    cout << " ╔═ w przyszłości twoim zawodem mógłby być... ══════════════════════" << endl;
    cout << " ║ " << endl;
    cout << " ║  " << nazwa << endl;
    cout << " ║  " << opis1 << endl;
    cout << " ║  " << opis2 << endl;
    cout << " ║ " << endl;
    cout << " ║  ANI: "; for(int i=0; i<A; i++) {cout << "■";}; cout << endl;
    cout << " ║  ENV: "; for(int i=0; i<E; i++) {cout << "■";}; cout << endl;
    cout << " ║  SOC: "; for(int i=0; i<S; i++) {cout << "■";}; cout << endl;
    cout << " ║  HEA: "; for(int i=0; i<H; i++) {cout << "■";}; cout << endl;
    cout << " ║  TAS: "; for(int i=0; i<T; i++) {cout << "■";}; cout << endl;
    cout << " ║ " << endl;
    cout << " ║  dominujące PRO: " << dominacja << endl;
    cout << " ║ " << endl;
    cout << " ╚══════════════════════════════════════════════════════════════════" << endl;
    }

///////////////////////////////////////////////////////////

void ocena(string pyt, string aa, string be, string ce, string de, string ee, int *zmienna)
    {
    int odp=0;
    int check=0;
    numer2++;

    printf("\033[H\033[2J");

    cout << " ╭─ Pytanie pomocnicze " << numer2 << "/2 ─────────────────────────────────" << endl;
    cout << " │ " << pyt << endl;
    cout << " │ " << endl;
    cout << " │ 1. " << aa << endl;
    cout << " │ 2. " << be << endl;
    cout << " │ 3. " << ce << endl;
    cout << " │ 4. " << de << endl;
    cout << " │ 5. " << ee << endl;
    cout << " │ " << endl;
    cout << " │ Wybierz odpowiedź (1,2, 3, 4, 5) i zatwierdź Enter: ";

    while (check==0)
        {
        cin >> odp;
        if (odp==1)  {//*zmienna = 1;
                      cout << " │ " << endl;
                      cout << " ╰───────────────────────╴╴╴╴╴╴╴ ╴╴ ╴ ╴ ╴  ╴   ╴    ╴";
                      check=1;} else
            if (odp==2) {//*zmienna = 2;
                      cout << " │ " << endl;
                      cout << " ╰───────────────────────╴╴╴╴╴╴╴ ╴╴ ╴ ╴ ╴  ╴   ╴    ╴";
                      check=1;} else
                if (odp==3) {//*zmienna = 3;
                      cout << " │ " << endl;
                      cout << " ╰───────────────────────╴╴╴╴╴╴╴ ╴╴ ╴ ╴ ╴  ╴   ╴    ╴";
                      check=1;} else
                if (odp==4) {//*zmienna = 4;
                            cout << " │ " << endl;
                            cout << " ╰───────────────────────╴╴╴╴╴╴╴ ╴╴ ╴ ╴ ╴  ╴   ╴    ╴";
                            check=1;} else
                if (odp==5) {//zmienna = 5;
                                  cout << " │ " << endl;
                                  cout << " ╰───────────────────────╴╴╴╴╴╴╴ ╴╴ ╴ ╴ ╴  ╴   ╴    ╴";
                                  check=1;} else
                    cout << " │ " << endl << " │ Nieprawidłowy wybór. Wpisz cyfrę 1-5 i zatwierdź klawiszem Enter: ";

        }
      *zmienna = odp;
      cout << endl << endl;
    }

////////////////////////////////////////////////////////////////////////////////

void intro()
    {
    cout << "   ▀▀▀▄      █  █   █   ▀▀▀▄  █  █   █  ▄███▄    " << endl;
    cout << "  ▄████  ▄████  ▀▄ ▄▀  ▄████  █  █   █  █████    " << endl;
    cout << "  ▀████  ▀████   ▀█▀   ▀████  █  ▀▄▄▄▀  ▀▄▄▄▄ SM" << endl;
    cout << "  s o m e t h i n g   g o o d   t o   c o d e " << endl;
    cout << endl;
    cout << "  ЯНЭК IamProVeg QuizTester v0.02 ©advalue 2020" << endl << endl;
    cout << "Witaj! Zapraszamy do testowania i rozwijania projektu I'am ProVeg!"<< endl;
    cout << "Używaj klawiatury. Jeżeli literki są za małe, naciśnij kombinację" << endl;
    cout << "klawiszy Ctrl i +, żeby powiększyć tekst w przeglądarce. Enjoy!" << endl << endl;
    }

//////////////////////////////////////////////////////////


void myflush ( FILE *in )
{
  int ch;

  do
    ch = fgetc ( in );
  while ( ch != EOF && ch != '\n' );

  clearerr ( in );
}

///////////////////////////////////////////////////////////

void mypause ( void )
{
  fflush ( stdout );
  getchar();
}
