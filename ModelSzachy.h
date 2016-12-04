//
// Created by jedrek on 2016-12-03.
//

#ifndef PSZT1_MODELSZACHY_H
#define PSZT1_MODELSZACHY_H

#include "Model.h"

class ModelSzachy: public Model {
    int n;
public:

    ModelSzachy(int setn);

    shared_ptr<State> getStartState() override;

    vector<pair<shared_ptr<State>, int>> getNextStates(shared_ptr<State> s) override;

    bool isTerminalState(shared_ptr<State> s) override;
};


#endif //PSZT1_MODELSZACHY_H
