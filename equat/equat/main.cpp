#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

//  Calcul de y(x) = m  <==>  m^m = x
//  xmin = (1/e)^(1/e) = 0.69220062755534636
//  ymin = y(xmin) = 1/e = 0.36787944117144232 = amin
//  bmax = 143.0 <==> xmax = bmax^bmax voisin de : 1.633e+308
double y(double x) {
    if(x < 0.69220062755534636) return 0.0;
    double a = 0.36787944117144232;
    double b = 143.0;
    double m, mm, n=0.0;
    do {
        m = (a+b)/2.0;
        if(m == n) break;
        mm = pow(m,m);
        if(mm > x) b = m; 
        if(mm < x) a = m; 
        n = m;
    }while((abs(mm-x) > 0.0) && (b-a > 0.0));
    return m;
}

//  Calcul de y'(x) = 1/(x(1+ln(y(x)))  
//  ou : y'(m^m) = 1/((m^m)(1+ln(m)))
double yp(double x) {
    if(x < 0.69220062755534636) return 0.0;
    double a = 0.36787944117144232;
    double b = 143.0;
    double m, mm, n=0.0;
    do {
        m = (a+b)/2.0;
        if(m == n) break;
        mm = pow(m,m);
        if(mm > x) b = m; 
        if(mm < x) a = m; 
        n = m;
    }while((abs(mm-x) > 0.0) && (b-a > 0.0));
    return 1.0/(mm*(1.0+log(m)));
}

int main(int argc, char ** argv) {
    std::cout << "Pour trouver une solution de : z^x = x" << std::endl << std::endl;
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
    std::cout << z << "^" << std::setprecision(10) << x << " = " << pow(z,x) << std::endl;
    return 0;
}