#include "player.hpp"
#include "../Aimbot/aimbot.hpp"
#include <vector>

using gamehacking::base_structures::Player;

Player gamehacking::base_structures::my_player(nullptr);
std::list<Player> gamehacking::base_structures::players;

Player::Player(void* player_object) : object_(player_object)
{
	is_valid_ = false;

	if (player_object == nullptr)
	{
		return;
	}

	is_valid_ = Setup(player_object);
}

bool Player::Setup(void* player_object)
{
	object_ = player_object;
	is_valid_ = false;

	if (player_object != nullptr)
	{
		return is_valid_ = SetupInternal();
	}
	return false;
}

void Player::Reset(void)
{
	is_valid_ = false;
	//weapon_.Reset();
}

bool Player::PredictAim(const gamehacking::base_structures::Player& target_object, gamehacking::math::Vector3D& output_vector)
{
    auto weapon_type = weapon_.weapon_type_;

    if (weapon_type == gamehacking::base_structures::Weapon::WeaponType::kUnknown)
    {
        return false;
    }

    if (weapon_type == gamehacking::base_structures::Weapon::WeaponType::kHitscan) {
        output_vector = target_object.location_;
        return true;
    }

    if (weapon_type == gamehacking::base_structures::Weapon::WeaponType::kArcProjectile) {
        return false;
    }

    /*
    if (weapon_type_ == WeaponType::kProjectileArching) {
                    return PredictAimAtTarget_DicksuckingLord(target_object, output_vector, offset);
    }
    */

    auto owner_location = location_ + weapon_.offset_;
    auto owner_velocity = velocity_;

    //owner_location = owner_location - owner_velocity * (weapon_parameters_.self_compensation_ping_ / 1000.0);

    auto target_location = target_object.location_;
    auto target_velocity = target_object.velocity_;
    //Vector target_acceleration = target_object->GetAcceleration();

    float ping_time = ping_ / 1000.0;

    auto target_ping_prediction = target_location + (target_velocity * ping_time * 1);
    auto prediction = target_ping_prediction;
    auto ping_prediction = target_ping_prediction;

    static std::vector<double> D(gamehacking::aimbot::settings::maximum_iterations, 0);
    static std::vector<double> dt(gamehacking::aimbot::settings::maximum_iterations, 0);

    int i = 0;
    do {
        D[i] = (owner_location - prediction).Magnitude();
        dt[i] = D[i] / weapon_.bullet_speed_;
        if (i > 0 && abs(dt[i] - dt[i - 1]) < gamehacking::aimbot::settings::epsilon) {
            break;
        }

        prediction = (target_ping_prediction + (target_velocity * dt[i] * 1) - (owner_velocity * (weapon_.inheritence_ * dt[i])));
        i++;
    } while (i < gamehacking::aimbot::settings::maximum_iterations);

    if (i == gamehacking::aimbot::settings::maximum_iterations) {
        return false;
    }

    ping_prediction = prediction = (target_ping_prediction + (target_velocity * dt[i] * 1) - (owner_velocity * (weapon_.inheritence_ * dt[i])));

    output_vector = ping_prediction;

    return true;
}