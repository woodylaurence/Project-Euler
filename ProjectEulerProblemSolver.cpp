#include <iostream>
#include <ctime>

#include "ProjectEulerProblemSolver.h"

using namespace std;

void ProjectEulerProblemSolver::solveProblem(IProblem& problem)
{
    cout << "Solving " << problem.getProblemName() << " ..." << endl;
    
    clock_t timeBegin = clock();
    problem.solve();
    clock_t timeEnd = clock();
    
    double timeDiffInMilliSeconds = (double)(timeEnd - timeBegin) / (double)CLOCKS_PER_SEC;
    
    cout << "Took " << timeDiffInMilliSeconds << " ms to solve problem" << endl;
    
}