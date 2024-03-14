#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

//returns number of votes
int vote_count(ElectionResult& electionResult){
    return electionResult.votes;
}

//adds additional votes to total votes
void increment_vote_count(ElectionResult& electionResult, int additionalVotes){
    electionResult.votes += additionalVotes;
}

//returns a reference to the winner and adds the "President "-prefix to the winner
ElectionResult& determine_result(std::vector<ElectionResult>& allResults){
    int leadPosition = 0;

    for(int i=0; i<allResults.size(); i++){
        if(allResults[i].votes > allResults[leadPosition].votes)
            leadPosition = i;
    }

    allResults[leadPosition].name = "President " + allResults[leadPosition].name;
    
    return allResults[leadPosition];
}

}  // namespace election