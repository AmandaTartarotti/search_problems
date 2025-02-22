//####################################################
//BOAT TRIPS (returns 1 uppon sucess and 0 otherwise)
//####################################################

//>>>>> Two missionaries in the boat <<<<< 
int two_missionaries_boat(int cur_shore_missionaries, int cur_shore_cannibals, int oposite_shore_missionaries, int oposite_shore_cannibals){

    if( (cur_shore_missionaries >= 2) && 
        ( ((cur_shore_missionaries - 2) == 0) || ( (cur_shore_missionaries - 2) >= cur_shore_cannibals) ) &&
        ( (oposite_shore_missionaries + 2) >= oposite_shore_cannibals) ) //otherwise as soon as they arrive at the oposite shore missionaries will be eaten
    {
        //cout << "two_missionaries_boat" << endl;
        return 1; // operation possible :)
    }

    return 0;
}

//>>>>> Two cannibals in the boat <<<<<
int two_cannibals_boat(int cur_shore_missionaries, int cur_shore_cannibals, int oposite_shore_missionaries, int oposite_shore_cannibals){
    if( (cur_shore_cannibals >= 2) && 
        ( (oposite_shore_missionaries == 0) ||  (oposite_shore_missionaries >= (oposite_shore_cannibals + 2)) ) )
        {
            //cout << "two_cannibals_boat" << endl;
            return 1;
        }

    return 0;
}

//>>>>> One missionarie and one cannibal in the boat <<<<<
int missionarie_cannibal_boat(int cur_shore_missionaries, int cur_shore_cannibals, int oposite_shore_missionaries, int oposite_shore_cannibals){
    if( cur_shore_missionaries && cur_shore_cannibals &&
        ( (oposite_shore_missionaries + 1) >= (oposite_shore_cannibals + 1)) )
        {
            //cout << "missionarie_cannibal_boat" << endl;
            return 1;
        }

    return 0;
}

//>>>>> Just one missionarie in the boat <<<<<
int missionarie_boat(int cur_shore_missionaries, int cur_shore_cannibals, int oposite_shore_missionaries, int oposite_shore_cannibals){

    if( cur_shore_missionaries && 
        ( ((cur_shore_missionaries-1) == 0 ) || ( (cur_shore_missionaries-1) >= cur_shore_cannibals) ))
        {
            //cout << "missionarie_boat" << endl;
            return 1;
        }

    return 0;
}

//>>>>> Just one cannibal in the boat <<<<<
int cannibal_boat(int cur_shore_missionaries, int cur_shore_cannibals, int oposite_shore_missionaries, int oposite_shore_cannibals){
    if( cur_shore_cannibals && 
        ( (oposite_shore_missionaries == 0) || ( oposite_shore_missionaries >= (oposite_shore_cannibals+1) ) ) )
        {
            //cout << "cannibal_boat" << endl;
            return 1;
        }

    return 0;
}

//####################################################