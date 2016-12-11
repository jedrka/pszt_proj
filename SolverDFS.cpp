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
    list<shared_ptr<State>> visited;
    A.push_front(start);
    bool finish = false;

    // Maybe we've got lucky?
    if (model->isTerminalState(A.front())) {
      A.front()->print();
      return A.front();
    }

    while (!finish) {
        vector<pair<shared_ptr<State>, int>> r = model->getNextStates(A.front());
        A.pop_front();

        for (auto s : r) {
            bool present = false;

            // Checks if next states hasn't been already visited
            for (auto i : visited) {
                if (i->getHash() == s.first->getHash() && i->isEqual(s.first.get())) {
                    present = true;
                    break;
                }
            }

            if (!present) {
                A.push_front(s.first);
                s.first->print();
                visited.push_back(s.first);
                if (model->isTerminalState(s.first)) {
                    finish = true;
                    break;
                }
            }
        }
    }

    return A.back();
}

void SolverDFS::reset() {
}
