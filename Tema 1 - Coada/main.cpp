#include <bits/stdc++.h>
#include "coada.cpp"

using namespace queueSpace;

int main()
{
    std::ifstream in("date.in");
    std::ofstream out("date.out");

    int N,M;
    in >> N >> M;

    queue<int> A,B;
    for (int i = 1;i <= N;++i) {
        in >> A;
    }
    for (int i = 1;i <= M;++i) {
        in >> B;
    }

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

    return 0;
}
