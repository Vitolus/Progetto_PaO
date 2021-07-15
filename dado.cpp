#include "dado.h"

Dado::Dado(unsigned short facce){
    nFacce= facce;
    for(auto i= 0; i<nFacce; i++){
        valori.push_back(i+1);
    }
}
