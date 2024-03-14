#include <string>

namespace targets {
    class Alien {
    //variables
    public:
        int x_coordinate, y_coordinate;
    private:
        int health = 3;
    //functions
    public:
        Alien(int x, int y){
            x_coordinate = x;
            y_coordinate = y;
        }
        int get_health() {
            return health;
        }
        bool hit(){
            if(health>0)
                health-=1;
            return true;
        }
        bool is_alive(){
            return health != 0;
        }
        bool teleport(int x_new, int y_new){
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }
        bool collision_detection(Alien otherAlien){
            return x_coordinate == otherAlien.x_coordinate && y_coordinate == otherAlien.y_coordinate;
        }
    };
}  // namespace targets