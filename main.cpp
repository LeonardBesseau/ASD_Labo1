/* ---------------------------
Laboratoire : 01
Fichier : main.cpp
Auteur(s) : Besseau Zwick Vioti
Date : 26-02-2020

But :

Remarque(s) :

Compilateur : gcc version 7.4.0

--------------------------- */


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
 * @return le nombre d'itération effectué
 */
size_t chercherPosition(const vector<int> &v, int val) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v.at(i) == val)
            return i;
    }
    return v.size();
}


/**
 * 2. Trie un vector.
 *
 * Pour la complexité, on considère le nombre de comparaisons (>)
 *
 * @param v vector à trier
 * @return le nombre de comparaison effectué
 */
int trier(vector<int> &v) {
    if (v.empty()) return 0;
    int output = 0;
    for (int a : v) {
        auto j = v.begin();
        auto k = j++;
        for (; j != v.end(); k = j++)
            if (++output, *k > *j)
                swap(*k, *j);
    }
    return output;

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
 * @return le nombre d'iteration
 */
size_t chercherSiContient(const vector<int> &v, int val) {
    auto first = v.begin();
    auto last = v.end();
    size_t output = 0;
    while (first != last) {
        auto mid = first + (last - first) / 2;
        ++output;
        if (*mid == val) {
            return output;
        } else if (*mid < val) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    return output;
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
 * @return le nombre d'addition
 */
size_t g(vector<int> &v) {
    size_t output = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = v.size() - 1; j > 0; j /= 2) {
            ++output;
            v.at(i) += v.at(j);
        }
    }
    return output;
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

/**
 * Test pour mesurer la complexité de la fonction 1 (nb d'itération) en moyenne
 * @param nbPoint nombre de point à tester
 * @return un vecteur avec les données
 */
vector<double> test1(int nbPoint) {
    std::vector<int> point;
    std::vector<double> output;
    output.resize(nbPoint);
    for (int i = 0; i < nbPoint; ++i) {
        point.push_back(i);
        size_t moyenne = 0;
        cout << "iteration " << i << endl;
        // moyenne pour vecteur de taille i
        for (int j = 0; j < point.size(); ++j) {
            moyenne += chercherPosition(point, j);
        }
        output.at(i) = moyenne / point.size();
    }
    for (double a : output) {
        cout << a << endl;
    }
    return output;
}

/** *
 * Test pour mesurer la complexité de la fonction 2 (nb de comparaison)
 * @param nbPoint nombre de point à tester
 * @return un vecteur avec les données
 */
vector<double> test2(int nbPoint) {
    std::vector<int> point;
    std::vector<double> output;
    output.resize(nbPoint);

    for (int i = 0; i < nbPoint; ++i) {
        point.push_back(i);
        cout << "iteration " << i << endl;
        output.at(i) = trier(point);

    }

    for (int j = 0; j < nbPoint; ++j) {
        cout << j << " " << output.at(j) << endl;
    }

    return output;
}

/** *
 * Test pour mesurer la complexité de la fonction 3 (nb d'itération) en moyenne
 * @param nbPoint nombre de point à tester
 * @return un vecteur avec les données
 */
vector<double> test3(int nbPoint) {
    std::vector<int> point;
    std::vector<double> output;
    output.resize(nbPoint);
    for (int i = 0; i < nbPoint; ++i) {
        point.push_back(i);
        size_t moyenne = 0;
        cout << "iteration " << i << endl;
        for (int j = 0; j < point.size(); ++j) {
            moyenne += chercherSiContient(point, j);
        }
        output.at(i) = i ? moyenne / point.size() : moyenne;
    }
    for (int k = 0; k < nbPoint; ++k) {
        cout << k << " " << output.at(k) << endl;
    }
    return output;
}

/** *
 * Test pour mesurer la complexité de la fonction 4
 * @param nbPoint nombre de point à tester
 * @return un vecteur avec les données
 */
vector<double> test4(int nbPoint) {
    std::vector<double> output;
    output.resize(nbPoint);

    for (int i = 0; i < nbPoint; ++i) {
        cout << i << endl;
        output.at(i) = f(i);

    }

    for (int j = 0; j < nbPoint; ++j) {
        cout << j << " " << output.at(j) << endl;
    }

    return output;
}

/** *
 * Test pour mesurer la complexité de la fonction 5 (nb d'addition) en moyenne
 * @param nbPoint nombre de point à tester
 * @return un vecteur avec les données
 */
vector<double> test5(int nbPoint) {
    std::vector<int> point;
    std::vector<double> output;
    output.resize(nbPoint);

    for (int i = 0; i < nbPoint; ++i) {
        point.push_back(i);
        cout << i << endl;
        output.at(i) = g(point);

    }

    for (int j = 0; j < nbPoint; ++j) {
        cout << j << " " << output.at(j) << endl;
    }

    return output;
}

/** *
 * Test pour mesurer le temps d'execution de la fonction 6
 * @param nbPoint nombre de point à tester
 * @return un vecteur avec les données
 */
vector<double> test6(int nbInst) {
    std::vector<int> point;
    std::vector<double> timer;
    timer.resize(nbInst);
    point.resize(nbInst);
    for (int i = 0; i < nbInst; ++i) {
        point.at(i) = i;
    }

    for (int a : point) {
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        random(a, 256);
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        timer.at(a) = chrono::duration_cast<chrono::nanoseconds>(
                t2 - t1).count();
        std::cout << a << " : " << timer.at(a) << endl;
    }

    return timer;
}

/** *
 * Test pour mesurer le temps d'execution de la fonction 7
 * @param nbPoint nombre de point à tester
 * @return un vecteur avec les données
 */
vector<double> test7(int nbInst) {
    std::vector<int> point;
    std::vector<double> timer;
    timer.resize(nbInst);
    point.resize(nbInst);
    for (int i = 0; i < nbInst; ++i) {
        point.at(i) = i;
    }

    for (int a : point) {
        chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
        random2(a, 256);
        chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
        timer.at(a) = chrono::duration_cast<chrono::nanoseconds>(
                t2 - t1).count();
        std::cout << a << " : " << timer.at(a) << endl;
    }

    return timer;
}

int main() {
    //initialisation du générateur aléatoire
    srand(time(NULL));
    test1(1000);


}