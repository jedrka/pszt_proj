//
// Created by jedrek on 2016-12-03.
//

#ifndef PSZT1_STATESZACHOWNICA_H
#define PSZT1_STATESZACHOWNICA_H

#include "State.h"
#include <cstdlib>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
#include  <iostream>

using namespace std;

class StateSzachownica : public State {
public:
    StateSzachownica();

    long long int getHash() override;

    int getHeuristic() override;

    bool isEqual(State * s) override;

    StateSzachownica(int nsize, int seed);

    StateSzachownica(const StateSzachownica &c);
    bool move(unsigned int which, unsigned int where);
    void print();


private:
    int n;

    void initRand(int seed);

    vector<pair<int, int> > board;

    int getCollisions();


    void normalise();

};


#endif //PSZT1_STATESZACHOWNICA_H
