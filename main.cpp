
#include <iostream>
#include "SolverDFS.h"
#include "ModelSzachy.h"
#include "StateSzachownica.h"

using namespace std;
int main() {


    std::cout << "Hello, World!" << std::endl;



    ModelSzachy ms(5);
    SolverDFS dfs;

    dfs.setModel(ms);
    shared_ptr<State> s = dfs.solve();


    static_pointer_cast<StateSzachownica>(s)->print();


    std::cout << "BYE!" << std::endl;

    return 0;
}



