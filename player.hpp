#include <list>
#include "weapon.hpp"
#include "../Math/math.hpp"

using gamehacking::math::Vector3D;

namespace gamehacking::base_structures
{
    struct Player
    {
        Player(void* player_object);
        bool Setup(void* player_object);
        void Reset(void);
        //static bool (*IsValid)(void*);
        //bool IsValid(void);
        void* object_;
        double health_;
        Vector3D forward_;
        Vector3D location_;
        Weapon weapon_ = Weapon(nullptr);
        bool is_valid_;
    private:
        bool SetupInternal(void* player_object);
    };

    extern Player my_player;
    extern std::list<Player> players;
}