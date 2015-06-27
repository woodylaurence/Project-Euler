#include <iostream>
#include <ctime>

#include "ProjectEulerProblemSolver.h"

#include "Prob32.hpp"

using namespace std;

int main(void)
{
//    Prob32 problem;
//    ProjectEulerProblemSolver::solveProblem(problem);
    ProjectEulerProblemSolver::solveProblem();
    return 0;
}

//void ProjectEulerProblemSolver::solveProblem(IProblem problem)
//{
//    cout << "Solving " << problem.getProblemName() << " ..." << endl;
//    
//    clock_t timeBegin = clock();
//    problem.solve();
//    clock_t timeEnd = clock();
//    
//    double timeDiffInMilliSeconds = (double)(timeEnd - timeBegin) / (double)CLOCKS_PER_SEC;
//    
//    cout << "Took " << timeDiffInMilliSeconds << " ms to solve problem" << endl;
//    
//}

void ProjectEulerProblemSolver::solveProblem()
{
    Prob32 problem;
    cout << "Solving " << problem.getProblemName() << " ..." << endl;
    
    clock_t timeBegin = clock();
    problem.solve();
    clock_t timeEnd = clock();
    
    double timeDiffInMilliSeconds = (double)(timeEnd - timeBegin) / (double)CLOCKS_PER_SEC;
    
    cout << "Took " << timeDiffInMilliSeconds << " ms to solve problem" << endl;
}