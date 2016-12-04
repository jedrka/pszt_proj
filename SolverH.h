//
// Created by jedrek on 2016-12-04.
//

#ifndef PSZT1_SOLVERH_H
#define PSZT1_SOLVERH_H


#include "Solver.h"
#include <list>
#include <memory>
#include <iostream>
using namespace std;

class SolverH: public Solver {
private:
    Model *model;

public:
    void setModel(Model &m);

    shared_ptr <State> solve();

    void reset();
};

#endif //PSZT1_SOLVERH_H
