// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include <deque>


struct tElem {
    int dinero, pos;
};

inline std::ostream& operator << (std::ostream& out, tElem const& e) {
    out << e.dinero << ' ';
    return out;
}

bool resuelveCaso() {

    int n, k;
    std::cin >> n >> k;
   
    if (n == 0) return false;

    std::deque <tElem> colaDePosiblesMax;

    int dinero;

    if (k > 1) {
    
        std::cin >> dinero;
        colaDePosiblesMax.push_back({ dinero,0 });

        for (int i = 1; i < k; i++) {
            std::cin >> dinero;

            tElem elem = { dinero,i };

            while (!colaDePosiblesMax.empty() && elem.dinero > colaDePosiblesMax.back().dinero) colaDePosiblesMax.pop_back();

            colaDePosiblesMax.push_back(elem);
        }

        std::cout << colaDePosiblesMax.front();

        for (int i = k; i < n; i++) {
            std::cin >> dinero;

            tElem elem = { dinero,i };

            while (!colaDePosiblesMax.empty() && elem.dinero > colaDePosiblesMax.back().dinero) colaDePosiblesMax.pop_back(); // que aparezca un nuevo maximo
            colaDePosiblesMax.push_back(elem);

            while (colaDePosiblesMax.front().pos < i - k + 1) colaDePosiblesMax.pop_front(); // que el maximo este en intervalo

            std::cout << colaDePosiblesMax.front();
        }

    }
    else {
        for (int i = 0; i < n; i++) {
            std::cin >> dinero;
            std::cout << dinero << " ";
        }
    }

    std::cout << std::endl;
    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
