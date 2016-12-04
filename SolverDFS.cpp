//
// Created by jedrek on 2016-12-03.
//

#include "SolverDFS.h"

void SolverDFS::setModel(Model &m) {
    model = &m;
}

shared_ptr<State> SolverDFS::solve() {

    shared_ptr<State> start = model->getStartState();
    list<shared_ptr<State>> A;
    A.push_front(start);
    bool finish = false;
    while (!finish) {

        //cout<<"A"<<endl;

       // A.front()->print();
        vector<pair<shared_ptr<State>, int>> r = model->getNextStates(A.front());
        A.pop_front();
        for (auto s: r) {
            cout<<"r"<<endl;
            s.first->print();
            bool present = false;

            for (auto i: A) {
                if (i->getHash() == s.first->getHash()) {
                    if (i->isEqual(s.first.get())) {
                        present = true;
                        break;
                    }
                }
            }

            if (!present) {
                A.push_front(s.first);
                if (model->isTerminalState(s.first)) {
                    finish = true;
                    s.first->print();
                    break;
                }
            }
        }
    }

    return A.back();
}

void SolverDFS::reset() {

}
