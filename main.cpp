//
//  Labo1.cpp
//
//	@author Besseau Zwick Viotti
//

#include <stdlib.h>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <iostream>


using namespace std;

/**
 * 1. Recherche la position d'une valeur dans un vector.
 *
 * Pour la complexité, on considère le nombre d'itérations.
 * Tester pour diverses valeurs de val, présentes ou non dans le vector.
 *
 * @param v vector dans lequel on cherche
 * @param val valeur à chercher
 * @return la position de la valeur dans le vector si trouvé, -1 sinon
 */
size_t chercherPosition(const vector<int> &v, int val) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v.at(i) == val)
            return i;
    }
    return -1;
}


/**
 * 2. Trie un vector.
 *
 * Pour la complexité, on considère le nombre de comparaisons (>)
 *
 * @param v vector à trier
 */
void trier(vector<int> &v) {
    if (v.empty()) return;

    for (int a : v) {
        auto j = v.begin();
        auto k = j++;
        for (; j != v.end(); k = j++)
            if (*k > *j)
                swap(*k, *j);
    }
}

/**
 * 3. Retourne true si la valeur est contenue dans le vector.
 *
 * Pour la complexité, on considère le nombre d'itérations.
 * v doit être trié en entrée !
 * Tester pour diverses valeurs de val, présentes ou non dans le vecteur.
 *
 * @param v vector trié dans lequel on cherche
 * @param val valeur à chercher
 * Retourne true si la valeur est contenue dans le vector, false sinon.
 */
bool chercherSiContient(const vector<int> &v, int val) {
    auto first = v.begin();
    auto last = v.end();

    while (first != last) {
        auto mid = first + (last - first) / 2;
        if (*mid == val) {
            return true;
        } else if (*mid < val) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    return false;
}

/**
 * 4. Pour la complexité, on considère le nombre d'additions
 *
 * @param n
 * @return
 */
unsigned long long f(unsigned n) {

    if (n == 0) return 1;

    return f(n - 1) + f(n - 1) + f(n - 1);
}

/**
 * 5. Pour la complexité, on considère le nombre d'additions (+=)
 *
 * @param v
 */
void g(vector<int> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = v.size() - 1; j > 0; j /= 2) {
            v.at(i) += v.at(j);
        }
    }
}

/**
 * 6. Pour la complexité, on considère les opérations push_back()
 *
 * Evaluer le temps d'exécution
 *
 * @param N nombre de données à générer
 * @param maxVal valeur maximale des données
 * @return vector rempli de N valeurs aléatoires.
 */
vector<int> random(size_t N, int maxVal) {

    vector<int> v;
    for (size_t i = 0; i < N; ++i) {
        v.push_back(1 + rand() % maxVal);
    }

    return v;
}

/**
 * 7. Pour la complexité, on considère les opérations insert()
 *
 * Evaluer le temps d'exécution
 *
 * @param N nombre de données à générer
 * @param maxVal valeur maximale des données
 * @return vector rempli de N valeurs aléatoires.
 */
vector<int> random2(size_t N, int maxVal) {

    vector<int> v;
    for (size_t i = 0; i < N; ++i) {
        v.insert(v.begin(), 1 + rand() % maxVal);
    }

    return v;
}

void test4(){
    std::vector<int> point;
    std::vector<double> timer;
    const int nbInst = 20;
    timer.resize(nbInst);
    point.resize(nbInst);
    for (int i = 0; i < 20; ++i) {
        point.at(i) = i;
    }

    for (int a : point) {
        cout << "Point " << a << endl;
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        f(a);
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        timer.at(a) = chrono::duration_cast<chrono::nanoseconds>(
                t2 - t1).count();
    }
    for (int a : point) {
        std::cout << a << " : " << timer.at(a) << endl;
    }
}

void test5(){
    std::vector<int> point;
    std::vector<vector<int>> list;
    std::vector<double> timer;
    const int nbInst = 200;
    timer.resize(nbInst);
    point.resize(nbInst);
    list.resize(nbInst);
    for (int i = 0; i < nbInst; ++i) {
        point.at(i) = i;
        list.at(i).resize(i);
        for (int j = 0; j < i; ++j) {
            list.at(i).at(j)= j;
        }
    }

    for (int a : point) {
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        g(list.at(a));
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        timer.at(a) = chrono::duration_cast<chrono::nanoseconds>(
                t2 - t1).count();
    }
    for (int a : point) {
        std::cout << a << " : " << timer.at(a) << endl;
    }
}


void test6(){
    std::vector<int> point;
    std::vector<double> timer;
    const int nbInst = 200;
    timer.resize(nbInst);
    point.resize(nbInst);
    for (int i = 0; i < nbInst; ++i) {
        point.at(i) = i;
    }

    for (int a : point) {
        cout << "Point " << a << endl;
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        random(a, 256);
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        timer.at(a) = chrono::duration_cast<chrono::nanoseconds>(
                t2 - t1).count();
    }
    for (int a : point) {
        std::cout << a << " : " << timer.at(a) << endl;
    }
}

int main() {
    //initialisation du générateur aléatoire
    srand(time(NULL));



}