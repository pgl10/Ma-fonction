#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

double y(double x) {
    if(x < 0.6922006276) return 0.0;
    double a = 0.3678794412;
    double b = 1000000000.0;
    double m, mm, n=0.0;
    do {
        m = (a+b)/2.0;
        if(m == n) break;
        mm = pow(m,m);
        if(mm > x) b = m; 
        else a = m;
        n = m;
    }while(abs(mm-x) > x/1000000000.0 );
    return m;
}

int main(int argc, char ** argv) {
    std::cout << "Pour trouver la solution de : z^x = x" << std::endl << std::endl;
    if(argc == 1 || argc > 2) {
        std::cout << "Faire : equat z" << std::endl << std::endl
                  << "avec : 0 < z < e^(1/e) = 1.44466786" << std::endl;
        return 0;
    }
    std::string st;
    std::istringstream iss;
    iss.str(argv[1]);
    double z;
    iss >> z;
        if(!((0 < z) && (z < 1.44466786))) {
        std::cout << "z = " << z << " : erreur !" << std::endl;
        return 0;
    }
    double x = 1.0/y(1.0/z);
    std::cout << z << "^" << x << " = " << pow(z,x) << std::endl;
    return 0;
}