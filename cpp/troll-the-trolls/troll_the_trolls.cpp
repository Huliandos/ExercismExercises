#include <map>
#include <set>

namespace hellmath {

// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

// permission types: `read`, `write`, and `remove`.
enum class Action {
    read,
    write,
    remove
};


// Returns if viewer can view posters Post
bool display_post(AccountStatus poster, AccountStatus viewer){
    if(poster == AccountStatus::troll){
        if(viewer == AccountStatus::troll)
            return true;
        return false;
    }
    return true;
}

std::map<AccountStatus, std::set<Action>> accountRights {
    {AccountStatus::guest, std::set<Action>{Action::read}},
    {AccountStatus::user, std::set<Action>{Action::read, Action::write}},
    {AccountStatus::troll, std::set<Action>{Action::read, Action::write}},
    {AccountStatus::mod, std::set<Action>{Action::read, Action::write, Action::remove}}
};

// returns if user is allowed to do action
bool permission_check(Action action, AccountStatus user){
    auto thisUsersRights = accountRights.find(user);
    if(thisUsersRights == accountRights.end())
        return false;
    if(thisUsersRights->second.find(action) == thisUsersRights->second.end())
        return false;
    return true;
}

// returns if two players can join the same game
bool valid_player_combination(AccountStatus account1, AccountStatus account2){
    //guests can't join
    if(account1 == AccountStatus::guest || account2 == AccountStatus::guest)
        return false;
    
    //anyone can join if both accounts have the same status
    if(account1 == account2)
        return true;
    
    //trolls can't join other players if they aren't trolls
    if(account1 == AccountStatus::troll || account2 == AccountStatus::troll)
        return false;

    //everyone but else can freely join others
    return true;
}
    
// returns if first account has priority over second accound
bool has_priority(AccountStatus accountToCheck, AccountStatus accountToCheckAgainst){
    return static_cast<int>(accountToCheck) > static_cast<int>(accountToCheckAgainst);
}

}  // namespace hellmath