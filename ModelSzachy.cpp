//
// Created by jedrek on 2016-12-03.
//

#include "ModelSzachy.h"
#include "StateSzachownica.h"

shared_ptr<State> ModelSzachy::getStartState() {
    shared_ptr<State> ss (new StateSzachownica(n, 777));
    return ss;
}

vector<pair<shared_ptr<State>, int>> ModelSzachy::getNextStates(shared_ptr<State> s) {

    StateSzachownica *ss = static_cast<StateSzachownica*>(s.get());

    vector<pair<shared_ptr<State>, int>> next;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < 8; b++) {
            shared_ptr<State> c (new StateSzachownica(*ss));
            if(static_pointer_cast<StateSzachownica>(c)->move(a,b)){
                next.push_back(make_pair(c,1));
            }
        }
    }

    return next;
}

bool ModelSzachy::isTerminalState(shared_ptr<State> s) {
    StateSzachownica *ss = static_cast<StateSzachownica *>(s.get());
    return ss->getHeuristic() == 0;
}

ModelSzachy::ModelSzachy(int setn) {
    n = setn;
}
