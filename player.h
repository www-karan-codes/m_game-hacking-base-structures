#include <list>
#include "weapon.h"

namespace gamehacking::base_structures
{
    struct Player
    {
        Player(void* player_object);
        static bool (*IsValid)(void*);
        bool IsValid(void);
        void* object_;
        double health_;
    };

    extern std::list<Player> players;
}