#pragma once

namespace gamehacking::base_structures
{
    struct Weapon
    {
        enum class WeaponType {kUnknown, kHitscan, kLinearProjectile, kArcProjectile};
        Weapon(void* weapon_object);
        void Reset(void);
        void Setup(void* weapon_object);
        void* object_;
        WeaponType weapon_type_;
        double speed_;
    private:
        void SetupInternal(void* weapon_object);
    };
}