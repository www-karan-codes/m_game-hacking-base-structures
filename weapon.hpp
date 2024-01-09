#pragma once

//#include "player.hpp"
#include "../Math/math.hpp"

namespace gamehacking::base_structures
{
    //struct Player;
    struct Weapon
    {
        enum class WeaponType {kUnknown, kHitscan, kLinearProjectile, kArcProjectile};
        Weapon(void* weapon_object);
        void Reset(void);
        void Setup(void* weapon_object);
        void* object_;
        WeaponType weapon_type_;
        double bullet_speed_;
        double inheritence_; // 0.0 - 1.0
        gamehacking::math::Vector3D offset_;
    private:
        void SetupInternal(void);
    };
}