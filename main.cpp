#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string vardai[100];
int pazymiai[100][10];
int pazymiuKiekis[100];
int mokiniuKiekis = 0;

int ivestiPazymi()
{
    int p;

    do
    {
        cout << "Iveskite pazymi nuo 1 iki 10: ";
        cin >> p;

        if (p < 1 || p > 10)
        {
            cout << "Neteisingas pazymys. Bandykite dar karta." << endl;
        }
    }
    while (p < 1 || p > 10);
    return p;
}

int pasirinktiMokini()
{
    if (mokiniuKiekis == 0)
    {
        cout << "Mokiniu sarasas tuscias." << endl;
        return -1;
    }

    cout << "Mokiniai:" << endl;

    for (int i = 0; i < mokiniuKiekis; i++)
    {
        cout << i + 1 << ". " << vardai[i] << endl;
    }

    int n;
    cout << "Pasirinkite mokinio numeri: ";
    cin >> n;

    if (n < 1 || n > mokiniuKiekis)
    {
        cout << "Neteisingas numeris. Galima rinktis nuo 1 iki "
             << mokiniuKiekis << "." << endl;
        return -1;
    }

    return n - 1;
}

int main()
{
    int pasirinkimas;

    do
    {
        cout << endl;
        cout << "Mokiniu pazymiu sistema" << endl;
        cout << "1. Ivesti mokini ir jo pazymius" << endl;
        cout << "2. Perziureti visu mokiniu pazymius" << endl;
        cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti pazymi" << endl;
        cout << "5. Apskaiciuoti mokinio vidurki" << endl;
        cout << "6. Pasalinti mokini" << endl;
        cout << "7. Iseiti" << endl;
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 1)
        {
            if (mokiniuKiekis >= 100)
            {
                cout << "Mokiniu sarasas pilnas." << endl;
            }
                else
            {
                cout << "Iveskite mokinio varda: ";
                cin >> vardai[mokiniuKiekis];

                do
                {
                    cout << "Kiek pazymiu norite ivesti (0-10)? ";
                    cin >> pazymiuKiekis[mokiniuKiekis];

                    if (pazymiuKiekis[mokiniuKiekis] < 0 ||
                        pazymiuKiekis[mokiniuKiekis] > 10)
                    {
                        cout << "Galima ivesti nuo 0 iki 10 pazymiu." << endl;
                    }
                }
                    while (pazymiuKiekis[mokiniuKiekis] < 0 ||
                         pazymiuKiekis[mokiniuKiekis] > 10);

                for (int j = 0; j < pazymiuKiekis[mokiniuKiekis]; j++)
                {
                    pazymiai[mokiniuKiekis][j] = ivestiPazymi();
                }

                mokiniuKiekis++;
                cout << "Mokinys pridetas." << endl;
            }
        }
        else if (pasirinkimas == 2)
        {
            if (mokiniuKiekis == 0)
            {
                cout << "Mokiniu sarasas tuscias." << endl;
            }
                else
            {
                for (int i = 0; i < mokiniuKiekis; i++)
                {
                    cout << i + 1 << ". " << vardai[i] << endl;
                    cout << "Pazymiai: ";

                    if (pazymiuKiekis[i] == 0)
                    {
                        cout << "Mokinys neturi pazymiu.";
                    }
                        else
                    {
                        for (int j = 0; j < pazymiuKiekis[i]; j++)
                        {
                            cout << pazymiai[i][j] << " ";
                        }
                    }

                    cout << endl;
                }
            }
        }
        else if (pasirinkimas == 3)
        {
            int i = pasirinktiMokini();

            if (i != -1)
            {
                cout << "Mokinio vardas: " << vardai[i] << endl;

                if (pazymiuKiekis[i] == 0)
                {
                    cout << "Mokinys neturi pazymiu." << endl;
                }
                    else
                {
                    cout << "Pazymiai: ";

                    for (int j = 0; j < pazymiuKiekis[i]; j++)
                    {
                        cout << pazymiai[i][j] << " ";
                    }

                    cout << endl;
                }
            }
        }
            else if (pasirinkimas == 4)
            {
            int i = pasirinktiMokini();

            if (i != -1)
            {
                if (pazymiuKiekis[i] == 0)
                {
                    cout << "Mokinys neturi pazymiu." << endl;
                } else
                {
                    cout << "Pazymiai:" << endl;

                    for (int j = 0; j < pazymiuKiekis[i]; j++)
                    {
                        cout << j + 1 << ". " << pazymiai[i][j] << endl;
                    }

                    int nr;
                    cout << "Kurio pazymio numeri norite pakeisti? ";
                    cin >> nr;

                    if (nr < 1 || nr > pazymiuKiekis[i])
                    {
                        cout << "Neteisingas numeris. Galima rinktis nuo 1 iki "
                             << pazymiuKiekis[i] << "." << endl;
                    }
                        else
                    {
                        pazymiai[i][nr - 1] = ivestiPazymi();
                        cout << "Pazymys pakeistas." << endl;
                    }
                }
            }
        }
            else if (pasirinkimas == 5)
            {
            if (mokiniuKiekis == 0)
            {
                cout << "Mokiniu sarasas tuscias." << endl;
            }
                else
                {
                for (int i = 0; i < mokiniuKiekis; i++)
                {
                    if (pazymiuKiekis[i] == 0)
                    {
                        cout << vardai[i] << " pazymiu vidurkio nera."
                             << endl;
                    }
                        else
                    {
                        int suma = 0;

                        for (int j = 0; j < pazymiuKiekis[i]; j++)
                        {
                            suma += pazymiai[i][j];
                        }

                        double vidurkis =
                            (double)suma / pazymiuKiekis[i];

                        cout << fixed << setprecision(2);
                        cout << vardai[i] << " vidurkis: "
                             << vidurkis << endl;
                    }
                }
            }
        }
            else if (pasirinkimas == 6)
            {
            int i = pasirinktiMokini();

            if (i != -1)
            {
                for (int j = i; j < mokiniuKiekis - 1; j++)
                {
                    vardai[j] = vardai[j + 1];
                    pazymiuKiekis[j] = pazymiuKiekis[j + 1];

                    for (int k = 0; k < 10; k++)
                    {
                        pazymiai[j][k] = pazymiai[j + 1][k];
                    }
                }

                mokiniuKiekis--;
                cout << "Mokinys pasalintas." << endl;
            }
        }
            else if (pasirinkimas == 7)
            {
            cout << "Programa baigiama." << endl;
            }
             else
             {
            cout << "Neteisingas pasirinkimas. Rinkites nuo 1 iki 7."
                 << endl;
            }

    }
    while (pasirinkimas != 7);

    return 0;
}