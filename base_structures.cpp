#include "base_structures.hpp"

namespace gamehacking::base_structures
{
	void Reset(void)
	{
		my_player.Reset();
		//my_player.weapon_.Reset();
		players.clear();
	}

	void Tick(void* player_list)
	{
		Reset();
		Player::SetupPlayers(player_list);
	}
}