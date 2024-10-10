#include "ex2.h"

int main(){
    
    Complex2D a = Complex2D(1.0,1.0);
    Complex2D b = Complex2D(a+1.0);
    Complex2D c = Complex2D(a+b);

    Complex2D d = Complex2D((a-1.0));
    Complex2D e = Complex2D(a-b);

    Complex2D f = Complex2D(a);
    Complex2D g = Complex2D(a*b);

    Complex2D h = Complex2D(a/2);
    Complex2D i = Complex2D(a/b);

    double j = module(a);
    Complex2D k = inv(a);


    std::cout << "Le nombre complexe est : " << a << std::endl;
    std::cout << "Le nombre complexe est : " << b << std::endl;
    std::cout << "Le nombre complexe est : " << c << std::endl;
    std::cout << "Le nombre complexe est : " << d << std::endl;
    std::cout << "Le nombre complexe est : " << e << std::endl;
    std::cout << "Le nombre complexe est : " << f << std::endl;   
    std::cout << "Le nombre complexe est : " << g << std::endl;
    std::cout << "Le nombre complexe est : " << h << std::endl;
    std::cout << "Le nombre complexe est : " << i << std::endl;
    std::cout << "Le nombre complexe est : " << j << std::endl;
    std::cout << "Le nombre complexe est : " << k << std::endl;
    if(a<b){
        std::cout << "a<b" <<std::endl;
    }else{
        std::cout << "a>b" <<std::endl;
    }
        if(a>b){
        std::cout << "a>b" <<std::endl;
    }else{
        std::cout << "a<b" <<std::endl;
    }
    return 0;
}