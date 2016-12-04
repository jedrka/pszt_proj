//
// Created by jedrek on 2016-12-03.
//

#include "StateSzachownica.h"

long long int StateSzachownica::getHash() {

    //normalise();

    long long h = 0;
    int c = 0;
    for (auto i : board) {
        h += i.first * i.second * i.second ;
    }

    return h;
}

int StateSzachownica::getHeuristic() {
    return getCollisions();
}

bool StateSzachownica::isEqual(State *s) {

    StateSzachownica *ss = static_cast<StateSzachownica *>(s);
    ss->normalise();
    normalise();

    return equal(board.begin(), board.end(), ss->board.begin(), ss->board.end());

//    for (auto i1 = copy.begin(), i2 = board.begin(); i2 != copy.end(); i1++, i2++) {
//        if (*i1 != *i2) return false;
//    }
    //return true;
}

StateSzachownica::StateSzachownica(int nsize, int seed) {
    n = nsize;
    initRand(seed);
}

void StateSzachownica::initRand(int seed) {
    int count = n;
    srand(seed);

    int *ar = new int[n * n];
    for (int a = 0; a < n * n; a++) {
        ar[a] = 0;
    }
    vector<pair<int, int> > list;
    while (count) {
        int x = rand() % n;
        int y = rand() % n;
        if (ar[x + n * y] == 0) {
            ar[x + n * y] = count--;
            list.push_back(make_pair(x, y));
        }
    }
    board = list;
    delete ar;
}

StateSzachownica::StateSzachownica(const StateSzachownica &c) {
    n = c.n;
    board = c.board;
}

int StateSzachownica::getCollisions() {
    int *xs = new int[n];
    int *ys = new int[n];
    int *diagsr = new int[n];// \ '
    int *diagsl = new int[n];// /

    memset(xs, 0, n);
    memset(ys, 0, n);
    memset(diagsr, 0, n);
    memset(diagsl, 0, n);

    int collisions = 0;
    for (auto i: board) {

        int collides = 0;

        if (xs[i.first]++)
            collides++;

        if (ys[i.second]++)
            collides++;

        if (i.first - i.second > 0)
            if (diagsr[i.first - i.second]++)
                collides++;

        if (n - 1 - i.first - i.second > 0)
            if (diagsl[n - 1 - i.first - i.second]++)
                collides++;

        if (collides)collisions++;
    }
    return collisions;
}

bool StateSzachownica::move(unsigned int which, unsigned int where) {
    if (which >= n)return false;
    if (where >= 8) return false;

    pair<int, int> chess = board.at(which);

    switch (where) {
        case 0: {
            chess.first--;
            chess.second--;
            break;
        }
        case 1: {

            chess.second--;
            break;
        }
        case 2: {
            chess.first++;
            chess.second--;
            break;
        }
        case 3: {
            chess.first++;
            break;
        }
        case 4: {
            chess.first++;
            chess.second++;
            break;
        }
        case 5: {
            chess.second++;
            break;
        }
        case 6: {
            chess.first--;
            chess.second++;
            break;
        }
        case 7: {
            chess.first--;
            break;
        }
    }

    if (chess.first >= 0 && chess.first < n && chess.second >= 0 && chess.second < n) {
        auto findIter = find(board.begin(), board.end(), chess);
        if (findIter == board.end()) {
            board.at(which) = chess;
            return true;
        }
    } else
        return false;
}

void StateSzachownica::normalise() {
    std::sort(board.begin(), board.end(), [](auto &left, auto &right) {
        if (left.second < right.second) {
            return true;
        } else if (left.second == right.second) {
            return left.first < right.first;
        }
        return false;
    });
}

void StateSzachownica::print() {

    int *ar = new int[n*n];
    for (int b = 0; b < n*n; b++) {
        ar[b]=0;
    }

    int count=1;
    for(auto i : board){
        ar[i.first+n*i.second]=count++;
    }

    int c = n * n;


    cout<<getHash()<<" "<<getHeuristic()<<endl;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            cout<<' '<<ar[a*n+b];
        }
        cout<<endl;
    }
}
