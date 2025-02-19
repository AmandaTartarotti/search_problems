#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int bucket_problem_dfs(int cap1, int cap2, int goal, int deep, int &acc_node){

    //verficar se é possível
    if(goal > max(cap1,cap2)) return -1;

    //estrututras auxiliares
    stack<vector<int>> dfs;
    vector<vector<bool>> visited(cap1 + 1, vector<bool>(cap2 + 1, false));

    //estado inicial: baldes vazios
    dfs.push({0,0,0});
    visited[0][0] = true;

    while(!dfs.empty()){

        auto cur_state = dfs.top();

        int bucket1 = cur_state[0];
        int bucket2 = cur_state[1];
        int steps = cur_state[2];

        acc_node++;

        //verficar se a solução foi encontrada
        if(goal == bucket1 || goal == bucket2) return steps;

        if(steps == deep) return -2;

        dfs.pop();

        // ########################################################
        // Tentar TODAS operações possíveis -> fill, empyt, pour
        // ########################################################

        //>>>>>>>>>>> Fill (completely) a bucket <<<<<<<<<<<<<
        //fill bucket1
        if(!visited[cap1][bucket2]){
            dfs.push({cap1, bucket2, (steps+1) });
            visited[cap1][bucket2] = true;
        }

        //fill bucket2
        if(!visited[bucket1][cap2]){
            dfs.push({bucket1, cap2, (steps+1) });
            visited[bucket1][cap2] = true;
        }

        
        //>>>>>>>>> Empty a bucket <<<<<<<<<<<<<

        //empyt bucket1
        if(!visited[0][bucket2]){
            dfs.push({0, bucket2, (steps+1) });
            visited[0][bucket2] = true;
        }

        //empyt bucket2
        if(!visited[bucket1][0]){
            dfs.push({bucket1, 0, (steps+1) });
            visited[bucket1][0] = true;
        }

                //>>>>>>>>>> Pour one bucket into the other <<<<<<<<<<

        //pour bucket1 into bucket2
        if((bucket2 < cap2) && (bucket1 > 0)){
            
            int transfer = min(bucket1, cap2 - bucket2); //tudo oq tem no bucket1 ou oq que falta no bucket2
            int b2 = bucket2 + transfer;
            int b1 = bucket1 - transfer;

            if(!visited[b1][b2]){
                dfs.push({b1, b2, (steps+1) });
                visited[b1][b2] = true;

            }

        }

        //pour bucket2 into bucket1
        if((bucket1 < cap1) && (bucket2 > 0)){

            int transfer = min(bucket2, (cap1 - bucket1));
            int b1 = bucket1 + transfer;
            int b2 = bucket2 - transfer;

            if(!visited[b1][b2]){
                dfs.push({b1, b2, (steps+1) });
                visited[b1][b2] = true;
            }
        }

    }

    return -1;
}