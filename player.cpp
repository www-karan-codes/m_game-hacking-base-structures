#include "player.hpp"

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
		return SetupInternal(player_object);
	}
	return false;
}

void Player::Reset(void)
{
	is_valid_ = false;
	weapon_.Reset();
}