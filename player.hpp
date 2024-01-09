#pragma once

#include <list>
#include "weapon.hpp"
#include "../Math/math.hpp"

//using gamehacking::math::Vector3D;

namespace gamehacking::base_structures
{
    struct Player
    {
        Player(void* player_object);
        bool Setup(void* player_object);
        void Reset(void);
        //static bool (*IsValid)(void*);
        static bool IsValid(void* player_object);
        static void SetupPlayers(void* players_object);
        void* object_;
        double health_;
        int team_;
        double ping_;
        gamehacking::math::Vector3D forward_;
        gamehacking::math::Vector3D direction_;
        gamehacking::math::Vector3D camera_;
        gamehacking::math::Rotation rotation_;
        gamehacking::math::Vector3D location_;
        gamehacking::math::Vector3D velocity_;
        double collision_height_;
        double collision_width_;

        Weapon weapon_ = Weapon(nullptr);
        bool is_valid_;

        bool PredictAim(const gamehacking::base_structures::Player& target_object, gamehacking::math::Vector3D& output_vector);
    private:
        bool SetupInternal(void);
    };

    extern Player my_player;
    extern std::list<Player> players;
}