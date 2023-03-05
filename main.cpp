#include <iostream>
#include <cstring>

using namespace std;

#define dim_max 101

//declarare variabile
int matrice_adiacenta[dim_max][dim_max];
int n; //numar de noduri/varfuri
int m; //numar de muchii
bool graf = false; //daca graful este construit, graf = true


void Ecran1()
{
    cout << "Bazele Grafurilor neorientate" << endl;

    cout << "Apasa orice tasta pentru a continua" << endl;
    char c;
    cin >> c;
}

void ConstruireGraf()
{
    if (graf == true){
        cout << endl;
        cout << "Variante disponibile: " << endl;
        cout << "1. Adauga muchie: " << endl;
        cout << "2. Sterge Muchie: " << endl;
        cout << "3. Iesire" << endl;
        cout << "Introdu Comanda: " << endl;

        int comanda;
        cin >> comanda;
        if (comanda == 1){
            if (m == n*(n-1)/2){
                cout << "Nu mai pot fi adaugate muchii in graf!" << endl;
                ConstruireGraf();
                return;
            }

            cout << endl;
            cout << "Introdu muchia pe care doresti sa o adaugi: " << endl;

            int x, y;
            cin >> x >> y;

            if (x == y or x > n or y > n or x < 1 or y < 1) cout << "Muchie Invalida!" << endl;
            else if (matrice_adiacenta[x][y] == 1){
                cout << "Muchia exista deja!" << endl;
            }
            else{
                matrice_adiacenta[x][y] = matrice_adiacenta[y][x] = 1;
                m++;
                cout << "Muchia a fost adaugata cu succes!" << endl;
            }
        }
        else if (comanda == 2){
            if (m == 0){
                cout << "Graful nu are muchii care pot fi sterse!" << endl;
                ConstruireGraf();
                return;
            }

            cout << endl;
            cout << "Introdu muchia pe care doresti sa o stergi: " << endl;

            int x, y;
            cin >> x >> y;
            if (x == y or x > n or y > n or x < 1 or y < 1) cout << "Muchie Invalida!" << endl;
            else if (matrice_adiacenta[x][y] == 0){
                cout << "Muchia nu exista!" << endl;
            }
            else{
                matrice_adiacenta[x][y] = matrice_adiacenta[y][x] = 0;
                cout << "Muchia a fost stearsa cu succes!" << endl;
                m--;
            }
        }
        else if (comanda == 3) return;
        else cout << "Comanda gresita" << endl;

        ConstruireGraf();
    }
    else{
        cout << endl;
        cout << "Introdu numarul de noduri / varfuri: " << endl;
        cin >> n;
        if (n > dim_max) {
            cout << "Numarul maxim de noduri admisibile este " << dim_max << endl;
            ConstruireGraf();
            return;
        }
        else if (n < 1) {
            cout << "Graful trebuie sa aibe cel putin un nod" << endl;
            ConstruireGraf();
            return;
        }

        cout << "Introdu numarul de muchii: " << endl;
        cin >> m;
        if (m > n*(n-1)/2){
            cout << "Graful nu poate avea atat de multe muchii, reia procesul de construire a grafului" << endl;
            ConstruireGraf();
            return;
        }
        if (m  < 0){
            cout << "Graful nu poate avea numar negativ de muchii, reia procesul de construire a grafului" << endl;
            ConstruireGraf();
            return;
        }

        cout << "Introdu muchiile grafului" << endl;
        for (int i = 1; i <= m; i++){
            int x, y;
            cin >> x >> y;

            if (x == y or x > n or y > n or x < 1 or y < 1) cout << "Muchie Invalida!" << endl, i--;
            else if (matrice_adiacenta[x][y] == 1) cout << "Muchia exista deja!" << endl, i--;
            else matrice_adiacenta[x][y] = matrice_adiacenta[y][x] = 1;
        }

        cout << "Graful a fost creat cu succes!" << endl;
        graf = true;
        return;
    }
}


void Definitii()
{
    //////////!!!!!!!!!TREBUIE SCOS DIACRITICE!!!!!!!!!!////////////////

    cout << endl;
    //Definitie graf neorientat, varfuri, muchii
    cout << "Definitie: Se numeste graf neorientat o pereche ordonata de multimi G=(X,U), unde: " << endl;
    cout << "     - X este o multime finita si nevida de elemente numite varfuri sau noduri;" << endl;
    cout << "     - U este o multime finita de submultimi cu doua elemente din X, numite muchii." << endl << endl;

    //Lant
    cout << "Se numeste lant o succesiune de varfuri L=[x1,x2, ..., xk]\n"
            " cu proprietatea ca oricare doua varfuri consecutive sunt adiacente.:" << endl << endl;

    //Ciclu
    cout << "Se numeste ciclu un lant simplu in care primul varf este identic cu ultimul. \n"
            " Daca toate varfurile sunt distincte, mai putin primul si ultimul, se numeste ciclu elementar." << endl << endl;

    //Graf partial
    cout << "Fie G=(X, U) un graf neorientat. Se numeşte graf partial al grafului G, graful neorientat G1=(X, U1), unde U1 ⊆ U." << endl << endl;

    //Subgraf
    cout << "Fie G=(X, U) un graf orientat. Se numeşte subgraf al grafului G graful neorientat G1=(X1,U1), \n"
            " unde X1 ⊆ X iar U1 contine toate arcele din U care au extremitatile in X1." << endl << endl;


    //Graf complet
    cout << " Fie G=(X, U) un graf neorientat. Graful G se numeste graf complet daca oricare doua varfuri\n"
            "distincte ale sale sunt adiacente. Un graf complet cu n varfuri se noteaza Kn." << endl << endl;

    //Graf Bipartit
    cout << "Un graf G=(X, U) se numeste graf bipartit daca exista doua mulţimi nevide A si B astfel incat X=A reunit B, A intersectat B = multimea vida şi \n"
            " orice muchie u a lui G are o extremitate in A iar cealalta in B. \n"
            "Mulţimile A şi B formeaza o partiţie a lui X." << endl << endl;

    //Graf Bipartit Complet
    cout << "Un graf bipartit G=(X,U) se numeste bipartit complet daca pentru oricare doua varfuri x apartine A"
            " si y apartine B\n"
            ", exista in graf muchia [x,y]; adica [x,y] apartine U\n" << endl;
}


void GradVarf()
{
    cout << endl;
    cout << "Variante disponibile: " << endl;
    cout << "1. Definitii" << endl;
    cout << "2. Varf izolat" << endl;
    cout << "3. Varf terminal" << endl;
    cout << "4. Iesire" << endl;
    cout << "Introdu Comanda:" << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1){
        cout << endl;
        //////de scos diacritice///////
        //gradele unui varf
        cout << "intr-un graf neorientat se numeste grad al unui varf numarul de varful adiacente cu acesta (sau numarul de muchii incidente cu acesta). \n "
                "Gradul unui varf x se noteaza d(x) (degree)." << endl << endl;
        //nod izolat
        cout << "un varf cu gradul 0 se numeste izolat" << endl << endl;
        //nod terminal
        cout << "un varf cu gradul 1 se numeste terminal" << endl << endl;
    }
    else if (comanda == 2){
        if (graf == false){
            cout << endl;
            cout << "Graful nu a fost inca creat" << endl;
        }
        else{
            int nr = 0;
            for (int i = 1; i <= n; i++){
                int vecini = 0;
                for (int j = 1; j <= n; j++){
                    if (matrice_adiacenta[i][j] == 1) vecini = 1;
                }

                if (vecini == 0) nr++;
            }

            cout << endl;
            if (nr > 0) cout << "Graful are " << nr << " varf(uri) izolate" << endl;
            else cout << "Graful nu are varfuri izolate" << endl;
        }

    }
    else if (comanda == 3){
        if (graf == false){
            cout << endl;
            cout << "Graful nu a fost inca creat" << endl;
        }
        else{
            int nr = 0;
            for (int i = 1; i <= n; i++){
                int vecini = 0;
                for (int j = 1; j <= n; j++){
                    if (matrice_adiacenta[i][j] == 1) vecini++;
                }

                if (vecini == 1) nr++;
            }

            cout << endl;
            if (nr > 0) cout << "Graful are " << nr << " varf(uri) terminale" << endl;
            else cout << "Graful nu are varfuri terminale" << endl;
        }
    }
    else if (comanda == 4) return;
    else cout << "Comanda gresita" << endl;

    GradVarf();
}



bool Test1And0(int nn, int mm, int matrice[dim_max][dim_max])
{
    for (int i = 1; i <= nn; i++){
        for (int j = 1; j <= mm; j++){
            if (matrice[i][j] != 0 and matrice[i][j] != 1){
                return false;
            }
        }
    }

    return true;
}


bool TestDiagPrinc(int nn, int mm, int matrice[dim_max][dim_max])
{
    for (int i = 1; i <= nn; i++){
        if (matrice[i][i] != 0) return false;
    }
    return true;
}

bool TestSimetrie(int nn, int mm, int matrice[dim_max][dim_max])
{
    for (int i = 1; i <= nn; i++){
        for (int j = i+1; j <= mm; j++){ //verific doar elementele de deasupra diagonalei principale
            if (matrice[i][j] != matrice[j][i]) return false;
        }
    }

    return true;
}


void MatriceAdiacenta()
{
    cout << endl;
    cout << "Variante disponibile" << endl;
    cout << "1. Caracteristici + definitie" << endl;
    cout << "2. Aplicatie" << endl;
    cout << "3. Iesire" << endl;

    int comanda;
    cin >> comanda;

    if (comanda == 1){
        cout << "Pentru un graf neorientat G=(X,U) cu n varfuri, \n"
                "matricea de adiacenta este o matrice cu n linii si n coloane si elemente din {0,1}, cu: \n"
                "  -a[i][j] = 1, daca [i,j] aparinte U \n"
                "  -a[i][j] = 0, daca [i,j] nu aparinte U" << endl << endl;
        cout << "Caracteristici: " << endl;
        cout << "   -matricea de adiacenta este simetrica fata de diagonala principala" << endl;
        cout << "   -elementele de pe diagonala principala sun 0" << endl;
        cout << "   -gradul unui varf x este egal cu numarul de elemente 1 de pe linia (sau coloana) x" << endl;
        cout << "   -suma tuturor elementelor din matricea de adiacenta a unui graf neorientat este egala cu dublul numarului de muchii din graf." << endl << endl;
    }
    else if (comanda == 2){
        int matrix[dim_max][dim_max];
        int n1, m1;

        cout << "Introdu dimensiunile matricei: " << endl;
        cin >> n1 >> m1;

        cout << "Introdu elementele matricei:" << endl;
        for (int i = 1; i <= n1; i++){
            for (int j = 1; j <= m1; j++){
                cin >> matrix[i][j];
            }
        }

        if (n1 != m1){
            cout << "Matricea introdusa nu este valida. Matricea trebuie sa fie patratica" << endl;
        }
        else if (!Test1And0(n1, m1, matrix)){
            cout << "Matricea introudusa nu este valida. Matricea trebuie sa aibe numai elemente de 0 sau 1" << endl;
        }
        else if (!TestDiagPrinc(n1, m1, matrix)){
            cout << "Matricea introdusa nu este valida. Matricea trebuie sa aibe elementele de pe diagonala principala egale cu 0" << endl;
        }
        else if (!TestSimetrie(n1, m1, matrix)){
            cout << "Matricea introdusa nu este valida. Matricea trebuie sa fie simetrica fata de diagonala principala" << endl;
        }
        else {
            cout << "Matricea introdusa poate fi valida. Depinde de numarul de muchii pe care il are graful" << endl << endl;
        }
    }
    else if (comanda == 3) return;
    else cout << "Comanda gresita" << endl;

    MatriceAdiacenta();
}

void Repr()
{
    cout << endl;
    cout << "Variante disponibile: " << endl;
    cout << "1. Liste de adiacente" << endl;
    cout << "2. Vectorul muchiilor" << endl;
    cout << "3. Matricea de adiacenta" << endl;
    cout << "4. Iesire" << endl;

    int comanda;
    cin >> comanda;

    if (comanda == 1){
        cout << "Pentru un graf neorientat cu G=(X,U) se va memora numarul de varfuri n si apoi, \n "
                "pentru fiecare varf x, lista varfurilor adiacente cu x, \n"
                " adica a varfurilor y cu proprietatea ca exista muchia [x,y]." << endl << endl;
        cout << "Listele de adiacenta pentru graful curent sunt: " << endl;
        for (int i = 1; i <= n; i++){
            cout << i << ": ";
            for (int j = 1; j <= n; j++){
                if (matrice_adiacenta[i][j]) cout << j << ' ';
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    else if (comanda == 2){
        cout << "Lista de muchii a unui graf neorientat reprezinta o multime ce contine toate muchiile din graf." << endl << endl;

        //vector de muchii
        cout << "Lista de muchii pentru graful curent este: " << endl;
        cout << "{";
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if (matrice_adiacenta[i][j]){
                    cout << "[" << i << ", " << j << "] ";
                }
            }
        }
        cout << "}";
        cout << endl << endl;

        int m_lista_muchii;
        struct lista_muchii{
            int e1, e2;
        }lista[dim_max];

        cout << "Introdu numarul de muchii pentru a face o citire folosind lista de muchii" << endl;
        cin >> m_lista_muchii;

        cout << "Introdu muchiile" << endl;
        int el = 0;
        for (int i = 1; i <= m_lista_muchii; i++){
            el++;
            cin >> lista[el].e1;
            cin >> lista[el].e2;
        }
        cout << "Lista citita cu succes, lista este urmatoarea: " << endl;
        cout << "{";
        for (int i = 1; i <= m_lista_muchii; i++){
            if (i != m_lista_muchii) cout << "[" << lista[i].e1 << "," << lista[i].e2 << "], ";
            else cout << "[" << lista[i].e1 << "," << lista[i].e2 << "]";
        }
        cout << "}" << endl << endl;



    }
    else if (comanda == 3){
        MatriceAdiacenta();
    }
    else if (comanda == 4) return;
    else cout << "Comanda gresita" << endl;

    Repr();
}



void BFS(int d)
{
    int vizit[dim_max] = {0}; //vectorul de vizitat, initializat cu 0
    int noduri[dim_max] = {0}; int primul, ultimul; //coada pentru bfs, initializat cu 0
    int solutie[dim_max] = {0}; int i_solutie = 0; //vector in care imi pun in ordine nodurile parcurse, initializat cu 0
    vizit[d] = 1; //nodul de start il marcam ca vizitat
    primul = ultimul = 1; noduri[ultimul] = d; //adaugam nodul de start in coada pentru bfs
    i_solutie++; solutie[i_solutie] = d; //adaugam nodul de start in vectorul de solutie

    while (primul <= ultimul){ //cat timp coada este nevida
        int curent = noduri[primul];
        for (int i = 1; i <= n; i++){
            if (matrice_adiacenta[curent][i] and !vizit[i]){
                ultimul++; noduri[ultimul] = i;
                vizit[i] = 1;
                i_solutie++; solutie[i_solutie] = i;
            }
        }
        primul++; //scot primul element din coada;
    }


    cout << endl;
    cout << "Parcurgerea in latime a grafului este: " << endl;
    for (int i = 1; i <= i_solutie; i++){
        cout << solutie[i] << " ";
    } //afisez parcurgerea din vectorul solutie
}


void DFS(int d, int vizit[], int solutie[], int &i_sol)
{
    vizit[d] = 1; //marchez nodul curent ca fiind vizitat
    i_sol++; solutie[i_sol] = d;
    for (int i = 1; i <= n; i++){
        if (matrice_adiacenta[d][i] and !vizit[i]){
            DFS(i, vizit, solutie, i_sol);
        }
    }
}

void Parcurgere()
{
    cout << endl;
    cout << "Variante disponibile: " << endl;
    cout << "1. In latime" << endl;
    cout << "2. In adancime" << endl;
    cout << "3. Iesire" << endl;
    cout << "Introdu comanda" << endl;

    int comanda;
    cin >> comanda;

    if (comanda == 1){
        if (graf == false) {
            cout << "Graful nu a fost creat inca" << endl;
        }
        else{
            cout << "Introdu nodul de start:" << endl;
            int nod;
            cin >> nod;
            if (nod < 1 or nod > n){
                cout << "Nod invalid!" << endl;
                Parcurgere();
                return;
            }
            BFS(nod);
        }
    }
    else if (comanda == 2){
        if (graf == false){
            cout << "graful nu a fost creat inca" << endl;
        }
        else{
            cout << "Introdu nodul de start:" << endl;
            int nod;
            if (nod < 0 or nod > n){
                cout << "Nod invalid" << endl;
                return;
            }
            cin >> nod;

            int vizit[dim_max] = {0}; //vectorul de vizitat
            int solutie[dim_max] = {0}; int i_solutie = 0; //vectorul in care retin parcurgerea
            DFS(nod, vizit, solutie, i_solutie);

            cout << "Parcurgerea in adancime este urmatoarea:" << endl;
            for (int i = 1; i <= i_solutie; i++){
                cout << solutie[i] << " ";
            }
            cout << endl;

        }
    }
    else if (comanda == 3) return;
    else cout << "Comanda gresita" << endl;


    Parcurgere();
}



bool TestConex()
{
    int vizit[dim_max] = {0}; //vectorul de vizitat, initializat cu 0
    int noduri[dim_max] = {0}; int primul, ultimul; //coada pentru bfs, initializat cu 0
    vizit[1] = 1; //nodul de start il marcam ca vizitat
    primul = ultimul = 1; noduri[ultimul] = 1; //adaugam nodul de start in coada pentru bfs

    while (primul <= ultimul){ //cat timp coada este nevida
        int curent = noduri[primul];
        for (int i = 1; i <= n; i++){
            if (matrice_adiacenta[curent][i] and !vizit[i]){
                ultimul++; noduri[ultimul] = i;
                vizit[i] = 1;
            }
        }
        primul++; //scot primul element din coada;
    }

    for (int i = 1; i <= n; i++){
        if (vizit[i] == 0) return false;
    }
    return true;
}

void GetCompConexe()
{
    int vizit[dim_max] = {0}; //vectorul de vizitat, initializat cu 0
    int noduri[dim_max] = {0}; int primul, ultimul; //coada pentru bfs, initializat cu 0
    vizit[1] = 1; //nodul de start il marcam ca vizitat
    primul = ultimul = 1; noduri[ultimul] = 1; //adaugam nodul de start in coada pentru bfs
    int ok = 1, nr = 1; //numar componete conexe

    while (ok == 1){
        while (primul <= ultimul){ //cat timp coada este nevida
            int curent = noduri[primul];
            for (int i = 1; i <= n; i++){
                if (matrice_adiacenta[curent][i] and !vizit[i]){
                    ultimul++; noduri[ultimul] = i;
                    vizit[i] = 1;
                }
            }
            primul++; //scot primul element din coada;
        }


        ok = 0;
        int i;
        for (i = 1; i <= n; i++){
            if (vizit[i] == 0){
                ok = 1;
                break;
            }
        }

        if (ok == 1){
            nr++;
            ultimul++;
            noduri[ultimul] = i;
            vizit[i] = 1;
        }
    }



    cout << "Graful are " << nr << " componente conexe" << endl;
}

void Conexitate()
{
    cout << endl;
    cout << "Variante disponibile: " << endl;
    cout << "1. Definite graf conex, componenta conexa" << endl;
    cout << "2. Verificare graf conex" << endl;
    cout << "3. Iesire" << endl;
    cout << "Introdu comanda" << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1){
        cout << endl;
        cout << " Un graf neorientat se numeste graf conex daca pentru oricare doua varfuri x si y diferite ale sale, \n "
                "exista cel putin un lant care le leaga, adica x este extremitatea initiala si y este extremitatea finala." << endl << endl;
        cout << "Se numeste componenta conexa a unui graf G=(X,U) un subgraf H=(Y, V), conex, al lui G\n"
                "care are proprietatea ca nu exista nici un lant in G care sa lege un varf din Y cu un varf din X – Y." << endl << endl;

    }
    else if (comanda == 2){
        if (graf == false) cout << "Graful nu a fost creat inca" << endl;
        else{
            if (TestConex() == true) cout << "Graful este conex" << endl;
            else{
                cout << "Graful nu este conex. ";
                GetCompConexe();
            }

        }

    }
    else if (comanda == 3) return;
    else cout << "Comanda gresita" << endl;

    Conexitate();
}


void Hamiltonian()
{
    cout << endl;
    cout << "Variante disponibile:" << endl;
    cout << "1. Teorie" << endl;
    cout << "2. Verificare" << endl;
    cout << "3. Iesire" << endl;
    cout << "Introdu comanda" << endl;

    int comanda;
    cin >> comanda;

    if (comanda == 1){
        cout << " Se numeste graf hamiltonian un graf care contine un ciclu hamiltonian. \n "
                "Se numeste ciclu hamiltonian un ciclu elementar care contine toate varfurile grafului." << endl << endl;
        cout << "Teorema: Un G un graf neorientat. Daca are n≥3 varfuri şi gradul oricarui varf verifica inegalitatea d(x)≥n/2 atunci G este hamiltonian." << endl << endl;
    }
    else if (comanda == 2){
        if (graf == false) cout << "Graful nu a fost creat inca" << endl;
        else{
            if (n <= 2) cout << "Graful nu este Hamiltonian" << endl;
            else{
                //verificam toate nodurile sa respecte egalitatea d(x) >= n/2
                int ok = 1;
                for (int i = 1; i <= n; i++){
                    int grad = 0;
                    for (int j = 1; j <= n; j++){
                        if(matrice_adiacenta[i][j] == 1) grad ++;
                    }
                    if (grad < n / 2){
                        ok = 0;
                        break;
                    }
                    cout << endl;
                }
                if (ok == 1) cout << "Graful este Hamiltonian" << endl;
                else cout << "Graful nu este Hamiltonian" << endl;
            }
        }

    }
    else if (comanda == 3) return;
    else cout << "Comanda gresita" << endl;

    Hamiltonian();
}

bool CheckVfIzolate()
{
    int ok = 1;
    for (int i = 1; i <= n; i++){
        int grad = 0;
        for (int j = 1; j <= n; j++){
            if (matrice_adiacenta[i][j]) grad++;
        }
        if (grad == 0){
            ok = 0;
            break;
        }

    }
    return ok;
}

bool TestGradPar()
{
    int ok = 1;

    for (int i = 1; i <= n; i++){
        int grad = 0;
        for (int j = 1; j <= n; j++){
            if (matrice_adiacenta[i][j]) grad++;
        }
        if (grad % 2 != 0){
            ok = 0;
            break;
        }

    }
    return ok;
}

void Eulerian()
{
    cout << endl;
    cout << "Variante disponibile:" << endl;
    cout << "1. Teorie" << endl;
    cout << "2. Verificare" << endl;
    cout << "3. Iesire" << endl;
    cout << "Introdu comanda" << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1){
        cout << "Se numeste graf eulerian un graf care contine un ciclu eulerian. \n"
                " Se numeste ciclu eulerian un ciclu care contine toate muchiile grafului." << endl << endl;
        cout << "Teorema: Un graf G = (X,U), fara varfuri izolate, este eulerian daca şi numai daca este conex şi\n"
                "gradele tuturor varfurilor sale sunt numere pare." << endl << endl;
    }
    else if (comanda == 2){
        if (graf == false){
            cout << "Graful nu a fost creat inca" << endl;
        }
        else{
            if (!CheckVfIzolate()){
                cout << "Graful nu este Eulerian" << endl;
            }
            else{
                if (TestConex() and TestGradPar()) cout << "Graful este Eulerian" << endl;
                else cout << "Graful nu este Eulerian" << endl;
            }
        }
    }
    else if (comanda == 3) return;
    else cout << "Comanda gresita" << endl;

    Eulerian();
}


void Arbori()
{
    cout << endl;
    cout << "Variante disponibile:" << endl;
    cout << "1. Teorie" << endl;
    cout << "2. Arbori oarecare" << endl;
    cout << "3. Arbori binari" << endl;
    cout << "4. Iesire" << endl;
    cout << "Introdu comanda" << endl;

    int comanda;
    cin >> comanda;

    if (comanda == 1){
        cout << "Se numeste arbore un graf conex si aciclic." << endl << endl;
        cout << "Terminologie: \n"
                "    -Nodurile sunt organiazte pe nivele, primul nivel fiind ocupat de \n"
                "un nod special numit radacina; \n"
                "    -Nodurile de pe ultimul nivel sunt noduri terminale sau frunze \n"
                "    -Orice nod este legat printr-o muchie de un nod de pe nivelul superior(nod parinte, predecesor sau ascendent) \n"
                "    -Orice nod neterminal este legat printr-o muchie de un nod de pe un nivel inferior(nod fiu, succesor sau descendent direct) \n"
                "    -Succesorii aceluiasi nod sunt frati" << endl << endl;
        cout << "Teoreme:\n"
                "    -Un arbore cu n varfuri are n-1 muchii.\n"
                "    -Un arbore este un graf conex si minimal cu aceasta proprietate; \n"
                "daca s-ar mai elimina o muchie, graful nu ar mai fi conex.\n"
                "    -Un arbore este un graf aciclic si maximal cu aceasta proprietate; \n"
                "daca s-ar mai adauga o muchie, s-ar obtine un ciclu." << endl << endl;
    }
    else if (comanda == 2){
        cout << "Vectorul de tati" << endl << endl;
        cout << "Vectorul tatilor (parintilor) va avea un numar de elemente egal cu \n"
                "numarul de noduri din arbore. Elementul i al vectorului va contine parintele nodului i" << endl << endl;
        cout << "Analizand vectorul tatilor, observam, foarte usor ca nodurile frunza nu se regasesc in vector. \n"
                "asemenea, nodul radacina poate fi aflat foarte usor: este pozitia elementului egal cu 0" << endl << endl;
    }
    else if (comanda == 3){
        cout << "Un arbore oarecare cu propietatea ca fiecare nod in afara de frunze are cel mult \n"
                "doi descendenti directi se numeste arbore binar" << endl << endl;
        cout << "Pe langa vectorul de tati, arborii binari se mai pot reprezenta prin vectorul descendentilor \n"
                "la stanga si la dreapta" << endl << endl;
        cout << "Vectorii ST si DR (avand acelasi numar de elemente ca si numarul de noduri) se completeaza \n"
                "cu descendentul stanga/dreapta pentru fiecare nod sau 0, pentru frunze" << endl << endl;
    }
    else if (comanda == 4) return;
    else cout << "Comanda gresita" << endl;

    Arbori();
}


void AfisALL()
{
    ///matricea
    cout << "Matricea de adiacenta a grafului curent este: " << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << matrice_adiacenta[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    //liste
    cout << "Listele de adiacenta pentru graful curent sunt: " << endl;
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        for (int j = 1; j <= n; j++){
            if (matrice_adiacenta[i][j]) cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl << endl;

    //vector de muchii
    cout << "Lista de muchii pentru graful curent este: " << endl;
    cout << "{";
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (matrice_adiacenta[i][j]){
                cout << "[" << i << ", " << j << "] ";
            }
        }
    }
    cout << "}";
    cout << endl << endl;

}


void Aplicatii()
{
    cout << endl;
    cout << "Variante disponibile:" << endl;
    cout << "1. Afisare matrice de adiacenta, liste de adiacenta, liste de muchii pentru graful curent" << endl;
    cout << "2. Se da un vector de tati pentru un arbore. Se va afisa nivelul fiearui nod din arbore" << endl;
    cout << "3. Se da un vector de tati pentru un arbore. Se va afisa radacina, frunzele si descendentii directi ai fiecarui nod" << endl;
    cout << "4. Iesire" << endl;
    cout << "Introdu comanda" << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 1){
        if (graf == false) cout << "Graful nu a fost creat inca" << endl;
        else AfisALL();
    }
    else if (comanda == 2){
        int nr_noduri, tata[dim_max] = {0};
        cout << "Introdu numarul de noduri din arbore" << endl;
        cin >> nr_noduri;

        cout << "Introdu vectorul de tati" << endl;
        for (int i = 1; i <= nr_noduri; i++) cin >> tata[i];

        cout << "Nivelurile nodurilor sunt: " << endl;
        for (int i = 1; i <= nr_noduri; i++){
            int c = 0, nod_curent = i;
            while (tata[nod_curent]){
                nod_curent = tata[nod_curent];
                c++;
            }
            cout << "Nodul " << i << ": Nivelul " << c << endl;
        }
    }
    else if (comanda == 3){
        int nr_noduri, tata[dim_max] = {0}, radacina, noduri[dim_max] = {0};
        cout << "Introdu numarul de noduri din arbore" << endl;
        cin >> nr_noduri;

        cout << "Introdu vectorul de tati" << endl;
        for (int i = 1; i <= nr_noduri; i++){
            cin >> tata[i];
            if (tata[i] == 0) radacina = i;
            noduri[tata[i]]++;
        }

        cout << endl << "Radacina este nodul " << radacina << endl << endl;

        cout << "Frunzele sunt: ";
        for (int i = 1; i <= nr_noduri; i++){
            if (noduri[i] == 0) cout << i << " ";
        }
        cout << endl << endl;

        cout << "Descendentii directi ai fiecarui nod: " << endl;
        for (int i = 1; i <= nr_noduri; i++){
            cout << "Descendentii directi ai lui " << i << " sunt nodurile: ";
            int ok = 0;
            for (int j = 1; j <= nr_noduri; j++){
                if (tata[j] == i) cout << j << " ", ok = 1;
            }
            if (ok == 0) cout << "Este frunza, nu are descendenti directi";
            cout << endl;
        }
        cout << endl;


    }
    else if (comanda == 4) return;
    else cout << "Comanda gresita" << endl;

    Aplicatii();
}



void Intrebare1(int &punctaj)
{
    char raspuns;
    cout << endl << "1. Adevarat sau Fals: " << endl;

    cout << endl;
    cout << "Intr-un graf neorientat exista muchie de la un varf la el insusi." << endl;
    cout << "Raspunsul tau (A sau F): ";
    cin >> raspuns;
    if (raspuns == 'F') punctaj += 10;
    cout << "Raspuns corect: F" << endl;
}

void Intrebare2(int &punctaj)
{
    char raspuns;
    cout << endl << "2. Alege varianta corecta (una singura): " << endl;
    cout << endl;
    cout << "Cum se numeste un varf care are gradul 0?" << endl;
    cout << "a) izolat   b) terminal   c) complet   d) conex" << endl;
    cout << "Raspunsul tau (a sau b sau c sau d): ";
    cin >> raspuns;
    if (raspuns == 'a') punctaj += 10;
    cout << "Raspuns corect: a)" << endl;
}

void Intrebare3(int &punctaj)
{
    char raspuns[15];
    cout << endl << "3. Alege varianta corecta (una sau mai multe): " << endl;
    cout << endl;
    cout << "Care sunt metode posibile de a reprezenta un graf neorientat din lista de mai jos?" << endl;
    cout << "a) vector de tati   b) matrice de adiacenta   c) sir de caractere   d) stiva    e) liste de adiacenta" << endl;
    cout << "Raspunsul tau: ";
    cin.get(); cin.getline(raspuns, 15);
    for (int i = 0; i < strlen(raspuns); i++){
        if (raspuns[i] == 'b' or raspuns[i] == 'e') punctaj += 5;
    }
    cout << "Raspuns corect: b si e" << endl;
}

void Intrebare4(int &punctaj)
{
    char raspuns[15];
    cout << endl << "4. Alege varianta corecta (una sau mai multe): " << endl;
    cout << endl;
    cout << "Care sunt metode posibile de a reprezenta un arbore(binar sau oarecare) din lista de mai jos?" << endl;
    cout << "a) vector de tati   b) matrice de adiacenta   c) vectorii descendentilor stanga si dreapta   d) stiva    e) liste de adiacenta" << endl;
    cout << "Raspunsul tau: ";
    cin.getline(raspuns, 15);
    for (int i = 0; i < strlen(raspuns); i++){
        if (raspuns[i] == 'a' or raspuns[i] == 'c') punctaj += 5;
    }
    cout << "Raspuns corect: a si c" << endl;
}

void Intrebare5(int &punctaj)
{
    char raspuns;
    cout << endl << "5. Alege varianta corecta (una singura): " << endl;
    cout << endl;
    cout << "Cum se numeste un varf care are gradul 1?" << endl;
    cout << "a) izolat   b) terminal   c) complet   d) conex" << endl;
    cout << "Raspunsul tau (a sau b sau c sau d): ";
    cin >> raspuns;
    if (raspuns == 'b') punctaj += 10;
    cout << "Raspuns corect: b)" << endl;
}

void Intrebare6(int &punctaj)
{
    char raspuns;
    cout << endl <<  "6. Adevarat sau Fals: " << endl;

    cout << endl;
    cout << "Urmatorul vector de tati al unui arbore de 7 noduri este valid/corect: 4 1 7 0 7 7 1  " << endl;
    cout << "Raspunsul tau (A sau F): ";
    cin >> raspuns;
    if (raspuns == 'A') punctaj += 10;
    cout << "Raspuns corect: A" << endl;
}

void Intrebare7(int &punctaj)
{
    char raspuns;
    cout << endl << "7. Alege varianta corecta (una singura): " << endl;
    cout << endl;
    cout << "Cate muchii are un graf complet cu n noduri?" << endl;
    cout << "a) n+1   b) (2^n)-1   c) n(n-1)/2   d) 10" << endl;
    cout << "Raspunsul tau (a sau b sau c sau d): ";
    cin >> raspuns;
    if (raspuns == 'c') punctaj += 10;
    cout << "Raspuns corect: c)" << endl;
}

void Intrebare8(int &punctaj)
{
    char raspuns;
    cout << endl <<  "8. Adevarat sau Fals: " << endl;

    cout << endl;
    cout << "Intre doua varfuri distincte exista cel putin o muchie." << endl;
    cout << "Raspunsul tau (A sau F): ";
    cin >> raspuns;
    if (raspuns == 'F') punctaj += 10;
    cout << "Raspuns corect: F" << endl;

}

void Intrebare9(int &punctaj)
{
    char raspuns;
    cout << endl << "9. Alege varianta corecta (una singura): " << endl;
    cout << endl;
    cout << "Care este o propietate a matricei de adiacenta?" << endl;
    cout << "a) este simetrica fata de diagonala principala   b) este patratica   c) elementele de pe diagonala principala sunt egale cu 0   d) toate variantele sunt corecte" << endl;
    cout << "Raspunsul tau (a sau b sau c sau d): ";
    cin >> raspuns;
    if (raspuns == 'd') punctaj += 10;
    cout << "Raspuns corect: d)" << endl;
}

void Intrebare10(int &punctaj)
{
    char raspuns[15];
    cout << endl << "10. Alege varianta corecta (una sau mai multe): " << endl;
    cout << endl;
    cout << "Fie G un graf neorientat cu n varfuri si m muchii, atunci graful admite" << endl;
    cout << "a) un unic graf partial   b) 2^m grafuri complementare   c) 2^m grafuri partiale   d) 2^n - 1 subgrafuri    e) niciuna din variante" << endl;
    cout << "Raspunsul tau: ";
    cin.get(); cin.getline(raspuns, 15);
    for (int i = 0; i < strlen(raspuns); i++){
        if (raspuns[i] == 'c' or raspuns[i] == 'd') punctaj += 5;
    }
    cout << "Raspuns corect: d si c" << endl;
}


void Test()
{
    int punctaj = 0;

    Intrebare1(punctaj);
    Intrebare2(punctaj);
    Intrebare3(punctaj);
    Intrebare4(punctaj);
    Intrebare5(punctaj);
    Intrebare6(punctaj);
    Intrebare7(punctaj);
    Intrebare8(punctaj);
    Intrebare9(punctaj);
    Intrebare10(punctaj);

    if (punctaj >= 50) cout << "Felicitari! Ai trecut testul cu " << punctaj << " puncte." << endl;
    else cout << "Din pacate, ai picat testul cu " << punctaj << " puncte" << endl;
}


void MeniuPrincipal()
{
    cout << endl;
    cout << "Variante disponibile: " << endl;
    cout << "0. Construire / Modificare Graf" << endl;
    cout << "1. Definitii" << endl;
    cout << "2. Gradul unui varf" << endl;
    cout << "3. Metode de reprezentare" << endl;
    cout << "4. Parcurgere" << endl;
    cout << "5. Conexitate" << endl;
    cout << "6. Graf hamiltonian" << endl;
    cout << "7. Graf eulerian" << endl;
    cout << "8. Arbori" << endl;
    cout << "9. Aplicatii" << endl;
    cout << "10. Test" << endl;
    cout << "11. Iesire" << endl;
    cout << "Introdu Comanda" << endl;

    int comanda;
    cin >> comanda;
    if (comanda == 0) ConstruireGraf();
    else if (comanda == 1) Definitii();
    else if (comanda == 2) GradVarf();
    else if (comanda == 3) Repr();
    else if (comanda == 4) Parcurgere();
    else if (comanda == 5) Conexitate();
    else if (comanda == 6) Hamiltonian();
    else if (comanda == 7) Eulerian();
    else if (comanda == 8) Arbori();
    else if (comanda == 9) Aplicatii();
    else if (comanda == 10) Test();
    else if (comanda == 11) return;
    else cout << "Comanda gresita" << endl;

    MeniuPrincipal(); //se apeleaza recursiv
}

int main() {
    Ecran1();
    MeniuPrincipal();
    return 0;
}
