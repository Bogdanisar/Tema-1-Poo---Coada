#include <fstream>
#include "coada.h"

using namespace queueSpace;

int main() {
    //*
    std::ifstream in("date.in");
    std::ofstream out("date.out");

    queue<int> A,B;
    in >> A;
    in >> B;

    //*
    if (A == B) {
        out << "The two queues are equal!\n";
    }
    else {
        out << ( (A < B) ? "Queue A is smaller than queue B!\n" : "Queue B is smaller than queue A!\n" );
    }

    queue<int> sumConstructor = A + B, sumAssignment;
    sumAssignment = B + A;
    out << sumConstructor << sumAssignment;

    queue<int> difConstructor = A - B, difAssignment;
    difAssignment = B - A;
    out << difConstructor << difAssignment;
    //*/

    return 0;
}
