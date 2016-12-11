#include <iostream>
#include "SolverDFS.h"
#include "ModelSzachy.h"
#include "StateSzachownica.h"

using namespace std;

int main() {
    ModelSzachy ms(5);
    SolverDFS dfs;

    dfs.setModel(ms);
    shared_ptr<State> s = dfs.solve();

    return 0;
}
