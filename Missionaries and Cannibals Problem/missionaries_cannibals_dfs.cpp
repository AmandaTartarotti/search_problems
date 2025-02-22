#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int missionaries_cannibals_dfs(int missionaries, int cannibals, int deep, int &acc_node){

    int total_people = missionaries + cannibals;

    //estrututras auxiliares
    stack<vector<int>> dfs;
    bool visited[5][5][5][5][1] = {false};
    
    int boat = 0; //the boat can have 1 to 2 people

    //estado inicial: 
    dfs.push({missionaries,cannibals,0,0,0,0}); 
    visited[3][3][0][0][0] = true; //left shore amount of people vs right side

    while(!dfs.empty()){

        auto cur_state = dfs.top();

        int right_shore_missionaries = cur_state[0];
        int right_shore_cannibals = cur_state[1];

        int left_shore_missionaries = cur_state[2];
        int left_shore_cannibals = cur_state[3];

        int boat_pos = cur_state[4]; //0 -> right & 1->left
        int steps = cur_state[5];

        acc_node++;

        //verficar se a solução foi encontrada -- todos do lado esquerdo
        if( (left_shore_missionaries + left_shore_cannibals) == total_people) return steps;

        //check ending condition
        if(steps == deep) return -2;

        dfs.pop();

        // ########################################################
        // Tentar TODAS operações possíveis 
        // ########################################################

        //>>>>>>>>>>> If the boat is at the right shore <<<<<<<<<<<<<

        if (boat_pos == 0){

            if(!visited[right_shore_missionaries-2][right_shore_cannibals][left_shore_missionaries+2][left_shore_cannibals][1])
            {
                if(two_missionaries_boat(right_shore_missionaries, right_shore_cannibals, left_shore_missionaries, left_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries-2, right_shore_cannibals, left_shore_missionaries+2, left_shore_cannibals, 1, steps+1});
                    visited[right_shore_missionaries-2][right_shore_cannibals][left_shore_missionaries+2][left_shore_cannibals][1] = true;
                }
            } 
                

            if(!visited[right_shore_missionaries][right_shore_cannibals-2][left_shore_missionaries][left_shore_cannibals+2][1]){

                if(two_cannibals_boat(right_shore_missionaries, right_shore_cannibals, left_shore_missionaries, left_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries, right_shore_cannibals-2, left_shore_missionaries, left_shore_cannibals+2, 1, steps+1});
                    visited[right_shore_missionaries][right_shore_cannibals-2][left_shore_missionaries][left_shore_cannibals+2][1] = true;
                }
            }
                

            if(!visited[right_shore_missionaries-1][right_shore_cannibals-1][left_shore_missionaries+1][left_shore_cannibals+1][1])
            {
                if(missionarie_cannibal_boat(right_shore_missionaries, right_shore_cannibals,left_shore_missionaries, left_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries-1, right_shore_cannibals-1, left_shore_missionaries+1, left_shore_cannibals+1, 1, steps+1});
                    visited[right_shore_missionaries-1][right_shore_cannibals-1][left_shore_missionaries+1][left_shore_cannibals+1][1] = true;
                }
            } 

            if(!visited[right_shore_missionaries-1][right_shore_cannibals][left_shore_missionaries+1][left_shore_cannibals][1])
            {
                if(missionarie_boat(right_shore_missionaries, right_shore_cannibals, left_shore_missionaries, left_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries-1, right_shore_cannibals, left_shore_missionaries+1, left_shore_cannibals, 1, steps+1});
                    visited[right_shore_missionaries-1][right_shore_cannibals][left_shore_missionaries+1][left_shore_cannibals][1] = true;
                }
            }

            if(!visited[right_shore_missionaries][right_shore_cannibals-1][left_shore_missionaries][left_shore_cannibals+1][1])
            {
                if(cannibal_boat(right_shore_missionaries, right_shore_cannibals, left_shore_missionaries, left_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries, right_shore_cannibals-1, left_shore_missionaries, left_shore_cannibals+1, 1, steps+1});
                    visited[right_shore_missionaries][right_shore_cannibals-1][left_shore_missionaries][left_shore_cannibals+1][1] = true;
                }
            }

        } 
        
        //>>>>>>>>>>> Else, the boat is at the left shore <<<<<<<<<<<<<

        else { 

            if(!visited[right_shore_missionaries+2][right_shore_cannibals][left_shore_missionaries-2][left_shore_cannibals][0]){

                if(two_missionaries_boat(left_shore_missionaries, left_shore_cannibals, right_shore_missionaries, right_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries+2, right_shore_cannibals, left_shore_missionaries-2, left_shore_cannibals, 0, steps+1});
                    visited[right_shore_missionaries+2][right_shore_cannibals][left_shore_missionaries-2][left_shore_cannibals][0] = true;
                }
            }

            if(!visited[right_shore_missionaries][right_shore_cannibals+2][left_shore_missionaries][left_shore_cannibals-2][0]){
                if(two_cannibals_boat(left_shore_missionaries, left_shore_cannibals, right_shore_missionaries, right_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries, right_shore_cannibals+2, left_shore_missionaries, left_shore_cannibals-2, 0, steps+1});
                    visited[right_shore_missionaries][right_shore_cannibals+2][left_shore_missionaries][left_shore_cannibals-2][0] = true;
                }
            }

            if(!visited[right_shore_missionaries+1][right_shore_cannibals+1][left_shore_missionaries-1][left_shore_cannibals-1][0]){
                if(missionarie_cannibal_boat(left_shore_missionaries, left_shore_cannibals, right_shore_missionaries, right_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries+1, right_shore_cannibals+1, left_shore_missionaries-1, left_shore_cannibals-1, 0, steps+1});
                    visited[right_shore_missionaries+1][right_shore_cannibals+1][left_shore_missionaries-1][left_shore_cannibals-1][0] = true;
                }
            }

            if(!visited[right_shore_missionaries+1][right_shore_cannibals][left_shore_missionaries-1][left_shore_cannibals][0])
            {
                if(missionarie_boat(left_shore_missionaries, left_shore_cannibals,right_shore_missionaries, right_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries+1, right_shore_cannibals, left_shore_missionaries-1, left_shore_cannibals, 0, steps+1});
                    visited[right_shore_missionaries+1][right_shore_cannibals][left_shore_missionaries-1][left_shore_cannibals][0] = true;
                }
            }

            if(!visited[right_shore_missionaries][right_shore_cannibals+1][left_shore_missionaries][left_shore_cannibals-1][0])
            {
                if(cannibal_boat(left_shore_missionaries, left_shore_cannibals,right_shore_missionaries, right_shore_cannibals))
                {
                    dfs.push({right_shore_missionaries, right_shore_cannibals+1, left_shore_missionaries, left_shore_cannibals-1, 0, steps+1});
                    visited[right_shore_missionaries][right_shore_cannibals+1][left_shore_missionaries][left_shore_cannibals-1][0] = true;
                }
            }

        }
    }

    return -1;
}