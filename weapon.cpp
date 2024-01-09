#include "weapon.hpp"
#include "player.hpp"

using gamehacking::base_structures::Weapon;

Weapon::Weapon(void* weapon_object) : object_(weapon_object)
{
	weapon_type_ = WeaponType::kUnknown;

	if (weapon_object == nullptr)
	{
		return;
	}

	Setup(weapon_object);
}

void Weapon::Reset(void)
{
	weapon_type_ = WeaponType::kUnknown;
}

void Weapon::Setup(void* weapon_object)
{
	object_ = weapon_object;
	weapon_type_ = WeaponType::kUnknown;

	if (weapon_object != nullptr)
	{
		SetupInternal();
	}
}