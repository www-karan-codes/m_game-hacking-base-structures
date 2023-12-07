namespace gamehacking::base_structures
{
    struct Weapon
    {
        enum class WeaponType {kUnknown, kHitscan, kLinearProjectile, kArcProjectile};
        void* object_;
    };
}