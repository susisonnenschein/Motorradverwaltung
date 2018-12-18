#include <iostream>
#include <fstream>
#include <list>

using namespace std;

//Klasse der Kunden
class Kunde
{

private:
    //Deklaration der Attribute
    string name, vorname, strasse, hausnummer, ort;
    int plz, geburtsjahr, telefonnr, reservierung;
    bool fuehrerschein;

public:

    //Konstruktor
    Kunde(): name(""), vorname(""), strasse(""), hausnummer(""), plz(0), ort(""), geburtsjahr(0), telefonnr(0), fuehrerschein(0), reservierung(0)
    {cout << "Neues Kundenprofil wurde erstellt." << endl;}

    //Funktionen, um auf Daten zugreifen zu können
    string get_name()
    {
        return name;
    }
    string get_vorname()
    {
        return vorname;
    }
    bool get_fuehrerschein()
    {
        return fuehrerschein;
    }
    int get_reservierung()
    {
        return reservierung;
    }

    //Funktion, um Reservierung ändern zu können
    void reservieren(int x)
    {
        reservierung = x;
    }

    //Operatorüberladung
    friend istream& operator>>(istream &is, Kunde &k);
    friend ostream& operator<<(ostream &os, Kunde &k);
};

//Liste für Kundendaten
list <Kunde> liste;

//Eingabe eines Kunden
istream& operator>>(istream &is, Kunde &k)
{
    cout << "Name:" << endl;
    is >> k.name;
    cout << "Vorname: " << endl;
    is >> k.vorname;
    cout << "Strasse:" << endl;
    is >> k.strasse;
    cout << "Hausnummer;" << endl;
    is >> k.hausnummer;
    cout << "PLZ:" << endl;
    is >> k.plz;
    cout << "Ort:" << endl;
    is >> k.ort;
    cout << "Geburtsjahr:" << endl;
    is >> k.geburtsjahr;
    cout << "Telefonnummer:" << endl;
    is >> k.telefonnr;
    cout << "Fuehrerschein Klasse A:" << endl;
    cout << "1 ja" << endl;
    cout << "0 nein" << endl;
    is >> k.fuehrerschein;
    return is;
}

//Ausgabe eines Kunden
ostream& operator<<(ostream &os, Kunde &k)
{
    os << k.name << endl;
    os << k.vorname << endl;
    os << k.strasse << endl;
    os << k.hausnummer << endl;
    os << k.plz << endl;
    os << k.ort << endl;
    os << k.geburtsjahr << endl;
    os << k.telefonnr << endl;
    os << k.fuehrerschein << endl << endl;
    return os;
}

//Funktionen deklarieren
void Kundeneingabe();
void Kundenausgabe();
void Reservierung();
void Motorradausgabe();
void Programmende();

int main()
{
    //lokale Variable definieren
    int m = 0;

    cout << "Herzlich Willkommen" << endl << endl;

    //Menü
    do
    {
    cout << "Waehlen Sie einen Menuepunkt (1-5)" << endl;
    cout << "1 Neuen Kunden erfassen" << endl;
    cout << "2 Alle Kundendaten ausgeben" << endl;
    cout << "3 Reservierung vornehmen" << endl;
    cout << "4 Motorrad herausgeben" << endl;
    cout << "5 Programm beenden" << endl;
    cin >> m;

    if (m == 1)
        {Kundeneingabe();}
    else if (m == 2)
        {Kundenausgabe();}
    else if (m == 3)
        {Reservierung();}
    else if (m == 4)
        {Motorradausgabe();}
    else if (m == 5)
        {Programmende();}
    else
        {cout << "Ungueltige Eingabe." << endl;}
    }while(m!=5);

    return 0;
}

//Funktionen definieren

//Erstellung eines neuen Kunden
void Kundeneingabe()
{
    Kunde *k = new Kunde();
    cin >> *k;
    liste.push_back(*k);
    delete k;
}

//Gibt alle Kundendaten aus
void Kundenausgabe()
{
   int zaehler = 1;
   list<Kunde>::iterator i;

   for(i = liste.begin(); i != liste.end(); ++i)
   {
        cout << "Kunde " << zaehler << endl;
        cout << "-------------------------" << endl;
        cout << *i << endl;
        zaehler++;
   }
}

//Nimmt eine Reservierung auf und schreibt diese in die Datei "reservierungen.txt"
void Reservierung()
{
    string name, vorname;
    int fuehrerschein = 2; //um Personen zu erkennen, die noch keine Kunden sind
    int reserviert = 0;
    int x = 0;
    string m = " ";

    cout << "Name:" << endl;
    cin >> name;
    cout << "Vorname: " << endl;
    cin >> vorname;

    list<Kunde>::iterator i;

    for(i = liste.begin(); i != liste.end(); ++i)
    {
        if (i->get_name() == name && i->get_vorname() == vorname)
        {
            fuehrerschein = i->get_fuehrerschein();
                if (fuehrerschein == 1)
                {
                    if (i->get_reservierung() != 0)
                    {
                        cout << "Der Kunde hat bereits ein Motorrad reserviert." << endl << endl;
                    }
                    else
                    {
                        cout << "Welches Motorrad moechten Sie reservieren? (1-4)" << endl;
                        cout << "1 Suzuki Bandit" << endl;
                        cout << "2 Honda TransAlp" << endl;
                        cout << "3 BMW F 650 GS" << endl;
                        cout << "4 Kawasaki ZZR1400" << endl << endl;
                        cin >> x;

                        if (x <= 4)
                        {
                            list<Kunde>::iterator j;

                            for(j = liste.begin(); j != liste.end(); ++j)
                            {
                                if (j->get_reservierung() == x)
                                {
                                    cout << "Das Motorrad ist bereits reserviert." << endl << endl;
                                    reserviert = 1;
                                    break;
                                }
                            }

                            if (reserviert == 0)
                            {
                                i->reservieren(x);

                                if (x == 1)
                                {m = "Suzuki Bandit";}
                                if (x == 2)
                                {m = "Honda TransAlp";}
                                if (x == 3)
                                {m = "BMW F 650 GS";}
                                if (x == 4)
                                {m = "Kawasaki ZZR1400";}

                                fstream f;
                                f.open("reservierungen.txt",ios::app);
                                f << m << ": " << vorname << " " << name << endl;
                                f.close();
                                cout << "Die Reservierung wurde verbucht." << endl << endl;
                            }
                        }
                        else
                        {
                            cout << "Geben Sie eine Zahl zwischen 1 und 4 ein." << endl << endl;
                        }
                    }
                }
                else if (fuehrerschein == 0)
                {
                    cout << "Der Kunde besitzt keinen Fuehrerschein der Klasse A, daher kann keine Reservierung vorgenommen werden." << endl << endl;
                }
            break;
        }
    }

    if (fuehrerschein == 2)
    {
        cout << "Diese Person ist nicht im System. Bitte Erfassen Sie den Kunden zunaechst in Menuepunkt 1." << endl << endl;
    }
}


//Storniert die Reservierung
void Motorradausgabe()
{
    string name, vorname;
    int fremder = 1; //um Personen zu erkennen, die noch keine Kunden sind

    cout << "Name:" << endl;
    cin >> name;
    cout << "Vorname: " << endl;
    cin >> vorname;

    list<Kunde>::iterator i;

    for(i = liste.begin(); i != liste.end(); ++i)
    {
        if (i->get_name() == name && i->get_vorname() == vorname && i->get_reservierung() == 1)
        {
            i->reservieren(0);
            fremder = 0;
            cout << "Reservierung von " << vorname << " " << name << " fuer die Suzuki Bandit wurde storniert." << endl << endl;
            break;
        }
        if (i->get_name() == name && i->get_vorname() == vorname && i->get_reservierung() == 2)
        {
            i->reservieren(0);
            fremder = 0;
            cout << "Reservierung von " << vorname << " " << name << " fuer die Honda TransAlp wurde storniert." << endl << endl;
            break;
        }
        if (i->get_name() == name && i->get_vorname() == vorname && i->get_reservierung() == 3)
        {
            i->reservieren(0);
            fremder = 0;
            cout << "Reservierung von " << vorname << " " << name << " fuer die BMW F 650 GS wurde storniert." << endl << endl;
            break;
        }
        if (i->get_name() == name && i->get_vorname() == vorname && i->get_reservierung() == 4)
        {
            i->reservieren(0);
            fremder = 0;
            cout << "Reservierung von " << vorname << " " << name << " fuer die Kawasaki ZZR1400 wurde storniert." << endl << endl;
            break;
        }
        else if (i->get_name() == name && i->get_vorname() == vorname && i->get_reservierung() == 0)
        {
            cout << "Es liegt keine Reservierung fuer " << vorname << " " << name << " vor." << endl << endl;
            fremder = 0;
            break;
        }
    }
    if (fremder == 1)
    {
        cout << "Diese Person ist nicht im System. Bitte Erfassen Sie den Kunden zunaechst in Menuepunkt 1." << endl << endl;
    }
}

//Beendet das Programm
void Programmende()
{
    cout << "Auf Wiedersehen" << endl;
}
