/* ###########################################

 STRATEGY: Breadth-first search
 DESCRIPTION: it begins with a node, then first traverses all its adjacent nodes.

########################################## */

/* ###########################################

 STRATEGY: Depth Limited Search
 DESCRIPTION: modified version of DFS that imposes a limit on the depth of the search

########################################## */

/* ###########################################

 STRATEGY: Iterative deepening strategy
 DESCRIPTION: repeatedly runs Depth-Limited Search, increasing the depth limit (L) step by step until the goal is found.

########################################## */

#include <iostream>
#include "two_buckets_bfs.cpp"
#include "two_buckets_dfs.cpp"

using namespace std;

int main(){

    int goal, strategy, deep, steps, acc_node = 0; 
    int iteractions = 1;

    cout << "Qual a quantidade de litros que você quer no balde? (Obs. capacidade max é 4L)" << endl;
    cin >> goal;

    cout << "Qual algoritmo você gostaria de usar?" << endl;
    cout << "[1] Breadth-first search" << endl;
    cout << "[2] Depth-first search strategy (limited depth)" << endl;
    cout << "[3] Iterative deepening strategy. " << endl;
    cin >> strategy;

    switch(strategy){
        case 1:
            steps = bucket_problem_bfs(4,3,goal,acc_node);
            break;
        case 2:
            cout << "Qual a profundidade máxima da pesquisa?" << endl;
            cin >> deep;

            steps = bucket_problem_dfs(4,3,goal,deep,acc_node);
            break;
        case 3:
            steps = -2;

            while (steps < -1){
                acc_node = 0;
                steps = bucket_problem_dfs(4,3,goal,iteractions,acc_node);
                iteractions++;
            }
            break;
        default:
            break;
    }

    if(steps > -1) cout << "São necessários " << steps << " iterações para atingir o objetivo." << endl <<
    "A árvore final tem " << acc_node << " nós." << endl;
    else if (steps == -1) cout << "Oh, que pena! Não há soluções possíveis :(" << endl;
    else cout << "O limite de profundidade foi alcançado e nenhuma solução foi encontrada.. " << endl;

    return 0;
}