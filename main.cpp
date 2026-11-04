#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main() {
    system("chcp 65001 > nul");

    const int max_mokiniai = 100;
    const int max_pazymiai = 10;

    string vardai[max_mokiniai];
    int pazymiai[max_mokiniai][max_pazymiai];
    int pazymiuSkaicius[max_mokiniai] = {0}; //kiek kiekvienas turi pazimiu.
    int mokiniuSkaicius = 0; // koks dabar mokiniu skaicius.

    int pasirinkimas;
    do {
        cout << endl << "Mokiniu pazymiu sistema" << endl;
        cout << "1. Įvesti mokinį ir jo pažymius" << endl;
        cout << "2. Peržiūrėti visų mokinių pažymius" << endl;
        cout << "3. Peržiūrėti konkretaus mokinio pažymius" << endl;
        cout << "4. Atnaujinti pažymį" << endl;
        cout << "5. Apskaičiuoti mokinio vidurkį" << endl;
        cout << "6. Pašalinti mokinį" << endl;
        cout << "7. Išeiti" << endl;
        cout << "Pasirinkite veiksmą (1-7): ";
        cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            // 1. Įvesti mokinį ir jo pažymius
            if (mokiniuSkaicius >= max_mokiniai) {
                cout << "Klaida. Maksimalus mokinių kiekis 100." << endl;
            } else {
                cout << "Įveskite mokinio vardą: ";
                cin >> vardai[mokiniuSkaicius];

                int kiek;
                cout << "Kiek pažymių norite įvesti šiam mokiniui (nuo 1 iki 10)? ";
                cin >> kiek;

                while (kiek < 1 || kiek > max_pazymiai) {
                    cout << "Neteisingai. Įveskite skaičių nuo 1 iki 10: ";
                    cin >> kiek;
                }

                pazymiuSkaicius[mokiniuSkaicius] = kiek;

                for (int j = 0; j < kiek; j++) {
                    int paz;
                    cout << "Įveskite " << j + 1 << "-ąjį pažymį (nuo 1 iki 10): ";
                    cin >> paz;

                    while (paz < 1 || paz > 10) {
                        cout << "Neteisingai. Įveskite skaičių nuo 1 iki 10: ";
                        cin >> paz;
                    }
                    pazymiai[mokiniuSkaicius][j] = paz;
                }

                mokiniuSkaicius++;
                cout << "Mokinys pridėtas." << endl;
            }
        }
        else if (pasirinkimas == 2) {
        // 2. Peržiūrėti visų mokinių pažymius
        if (mokiniuSkaicius == 0) {
            cout << "Nera ivestu mokiniu." << endl;
        } else {
            cout << "Visi mokiniai: " << endl;
            for (int i = 0; i < mokiniuSkaicius; i++) {
                cout << i + 1 << ". Mokinys: " << vardai[i] << "  Pažymiai: ";
                if (pazymiuSkaicius[i] == 0) {
                    cout << "Neturi pažymių";
                } else {
                    for (int j = 0; j < pazymiuSkaicius[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }
    }
            else if (pasirinkimas == 3) {
            // 3. Peržiūrėti konkretaus mokinio pažymius
            if (mokiniuSkaicius == 0) {
                cout << "Sąraše nėra mokinių." << endl;
            } else {
                int nr;
                cout << "Įveskite mokinio numerį (nuo 1 iki " << mokiniuSkaicius << "): ";
                cin >> nr;

                while (nr < 1 || nr > mokiniuSkaicius) {
                    cout << "Neteisingai. Įveskite skaičių nuo 1 iki " << mokiniuSkaicius << ": ";
                    cin >> nr;
                }

                int indeksas = nr - 1;
                cout << "Mokinys: " << vardai[indeksas] << " | Pažymiai: ";
                if (pazymiuSkaicius[indeksas] == 0) {
                    cout << "Neturi pažymių";
                } else {
                    for (int j = 0; j < pazymiuSkaicius[indeksas]; j++) {
                        cout << pazymiai[indeksas][j] << " ";
                    }
                }
                cout << endl;
            }
        }
                else if (pasirinkimas == 4) {
                // 4. Atnaujinti pažymį
                if (mokiniuSkaicius == 0) {
                    cout << "Sąraše nėra mokinių." << endl;
                } else {
                    int nr;
                    cout << "Įveskite mokinio numerį (nuo 1 iki " << mokiniuSkaicius << "): ";
                    cin >> nr;

                    while (nr < 1 || nr > mokiniuSkaicius) {
                        cout << "Neteisingai. Įveskite skaičių nuo 1 iki " << mokiniuSkaicius << ": ";
                        cin >> nr;
                    }

                    int indeksas = nr - 1;
                    if (pazymiuSkaicius[indeksas] == 0) {
                        cout << "Mokinys neturi pažymių." << endl;
                    } else {
                        int pazNr;
                        cout << "Kurį pažymį norite atnaujinti (nuo 1 iki " << pazymiuSkaicius[indeksas] << "): ";
                        cin >> pazNr;

                        while (pazNr < 1 || pazNr > pazymiuSkaicius[indeksas]) {
                            cout << "Neteisingai. Įveskite skaičių nuo 1 iki " << pazymiuSkaicius[indeksas] << ": ";
                            cin >> pazNr;
                        }

                        int naujasPaz;
                        cout << "Įveskite naują pažymį (nuo 1 iki 10): ";
                        cin >> naujasPaz;

                        while (naujasPaz < 1 || naujasPaz > 10) {
                            cout << "Neteisingai. Įveskite skaičių nuo 1 iki 10: ";
                            cin >> naujasPaz;
                        }

                        pazymiai[indeksas][pazNr - 1] = naujasPaz;
                        cout << "Pažymys atnaujintas." << endl;
                    }
                }
            }       else if (pasirinkimas == 5) {
                    // 5. Apskaičiuoti mokinio vidurkį
                    if (mokiniuSkaicius == 0) {
                        cout << "Sąraše nėra mokinių." << endl;
                    } else {
                        int nr;
                        cout << "Įveskite mokinio numerį (nuo 1 iki " << mokiniuSkaicius << "): ";
                        cin >> nr;

                        while (nr < 1 || nr > mokiniuSkaicius) {
                            cout << "Neteisingai. Įveskite skaičių nuo 1 iki " << mokiniuSkaicius << ": ";
                            cin >> nr;
                        }

                        int indeksas = nr - 1;
                        if (pazymiuSkaicius[indeksas] == 0) {
                            cout << "Mokinys neturi pažymių." << endl;
                        } else {
                            double suma = 0;
                            for (int j = 0; j < pazymiuSkaicius[indeksas]; j++) {
                                suma += pazymiai[indeksas][j];
                            }
                            double vidurkis = suma / pazymiuSkaicius[indeksas];

                            // Du skaiciai po kablelio
                            cout << fixed << setprecision(2);
                            cout << "Mokinio " << vardai[indeksas] << " pažymių vidurkis: " << vidurkis << endl;
                        }
                    }
                }   else if (pasirinkimas == 6) {
                    // 6. Pašalinti mokinį
                    if (mokiniuSkaicius == 0) {
                        cout << "Sąraše nėra mokinių." << endl;
                    } else {
                    int nr;
                    cout << "Įveskite mokinio numerį kuri norite pasalinti (nuo 1 iki " << mokiniuSkaicius << "): ";
                    cin >> nr;

                    while (nr < 1 || nr > mokiniuSkaicius) {
                        cout << "Neteisingai. Įveskite skaičių nuo 1 iki " << mokiniuSkaicius << ": ";
                        cin >> nr;
                    }

                    int indeksas = nr - 1;

                    // kad neliktu tarpu visi pasislenka i pasalinto mokinio
                    for (int i = indeksas; i < mokiniuSkaicius - 1; i++) {
                        vardai[i] = vardai[i + 1];
                        pazymiuSkaicius[i] = pazymiuSkaicius[i + 1];
                        for (int j = 0; j < max_pazymiai; j++) {
                            pazymiai[i][j] = pazymiai[i + 1][j];
                        }
                    }

                    mokiniuSkaicius--;
                    cout << "Mokinys pasalintas." << endl;
                }
            }       else if (pasirinkimas == 7) {
                    // 7. Išeiti
                    cout << "Programa baigia darbą." << endl;

                } else {
                    cout << "Neteisingas pasirinkimas. Pasirinkite skaičių nuo 1 iki 7." << endl;
                }

} while (pasirinkimas != 7);

return 0;
}