#include <iostream>
#include <fstream>
#include<cstring>

using namespace std;

struct date {
    int in;
    int out;
    char litere;
} v[100];

void
afn(int sf[100], int si, int nr_sf, int m, char sir[100], int x[100], int y[100], int z[100], int poz, int p, int nr) {
    if (sir[0] == '\0') {
        cout << "Nu";
        return;
    }
    int a = si;
    int ok = 0;
    int i = poz;
    while (i < m) {
        ok = 0;
        if (v[i].in == a && sir[p] == v[i].litere) {
            for (int j = i + 1; j < m && ok == 0; j++)
                if (v[j].in == a && sir[p] == v[j].litere) {
                    x[nr] = j;// urmatoarea pozitie din v.in pe care se afla  aceeasi stare de plecare si aceeasi litera de unire
                    ok = 1;
                    y[nr] = a;//starea la care trebuie sa se intoarca in cazul in care parcurgerea anterioara nu a ajuns la starea finala sau nu a parcurs toate literele
                    z[nr] = p;// pozitia literei la care trebuie sa se intoarca
                    nr++;
                }
            p++;
            a = v[i].out;
            i = -1;
        }
        i++;
    }
    ok = 0;
    i = 0;

    while (i < nr_sf && ok == 0) {
        if (a == sf[i] && strlen(sir) == p)
            ok = 1;
        i++;
    }
    if (ok == 1)
        cout << "da";
    else if (nr != 0)
        afn(sf, y[nr - 1], nr_sf, m, sir, x, y, z, x[nr - 1], z[nr - 1], nr - 1);
    else
        cout << "nu";
}


int main() {
    ifstream f("C:\\Users\\cosmina\\Documents\\GitHub\\LFA_AFN\\date.in");
    int n, m, alf, si, sf[100], nr_sf, x[100], y[100], z[100], nr = 0, c, d;
    char sir[100], l;
    f >> n;//nr de stari
    f >> m;//nr de relatii
    f >> alf;//nr de litere date
    f >> si;//starea initiala
    f >> nr_sf;
    for (int j = 0; j < nr_sf; j++)
        f >> sf[j];//starea finala
    f >> sir;//sirul de verificat
    int poz = 0;
    for (int j = 0; j < m; j++) {
        f >> c >> d >> l;//nr intre care exista o relatie si litera care ii uneste

        v[j].in = c;
        v[j].out = d;
        v[j].litere = l;

    }
    for (int j = 0; j < n; j++) {
        x[j] = 0;
        y[j] = 0;
        z[j] = 0;
    }

    afn(sf, si, nr_sf, m, sir, x, y, z, 0, 0, nr);


    return 0;
}