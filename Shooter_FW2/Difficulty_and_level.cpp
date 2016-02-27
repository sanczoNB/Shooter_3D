#include "Difficulty_and_level.h"


Difficulty_and_level::Difficulty_and_level(){
	difficulty = 0;
	level = 1;
	shoted_ships_for_level_up = 10;
	ConstructorFunction();
}

Difficulty_and_level::Difficulty_and_level(const int& diff) : difficulty(diff) {
	level = 1;
	shoted_ships_for_level_up = 10;
	ConstructorFunction();
}

Difficulty_and_level::~Difficulty_and_level()
{
}


int Difficulty_and_level::GetShipsShotedCounter(){
	return ships_shoted_counter;
}

void Difficulty_and_level::AddShipsShotedCounter(){
	ships_shoted_counter++;
}

void Difficulty_and_level::ResetShipsShotedCounter(){
	ships_shoted_counter=0;
}

int Difficulty_and_level::GetEnemyShipsMovingAbility(){
	return enemy_ships_moving_ability;
}

float Difficulty_and_level::GetEnemyShipsMovingSpeed(){
	return enemy_ships_moving_speed;
}

float Difficulty_and_level::GetOtherShapesMovingSpeed(){
	return other_shapes_moving_speed;
}

float Difficulty_and_level::GetPlayerShotsSpeed(){
	return player_shots_speed;
}

float Difficulty_and_level::GetEnemyShipsShotsSpeed(){
	return enemy_ships_shots_speed;
}

int Difficulty_and_level::GetMaximalNumberOfEnemyShips(){
	return maximal_number_of_enemy_ships;
}

int Difficulty_and_level::GetWhenRandomGenerateEnemyShips(){
	return when_random_generate_enemy_ships;
}

int Difficulty_and_level::GetProbabilityOfAddingEnemyShip(){
	return probability_of_adding_enemy_ship;
}

int Difficulty_and_level::GetProbabilityOfGeneratingEnemyShot(){
	return probability_of_generating_enemy_shot;
}

int Difficulty_and_level::GetMaximalNumberOfEnemyShots(){
	return maximal_number_of_enemy_shots;
}

float Difficulty_and_level::GetMinimalTimeBeetwenPlayerShots(){
	return minimal_time_beetwen_player_shots;
}

bool Difficulty_and_level::UpdateLevel(){
	if (ships_shoted_counter >= shoted_ships_for_level_up){
		shoted_ships_for_level_up += (level+1)*5;

		level++;

		int multiplayer = difficulty+1;

		enemy_ships_moving_ability -= (int)(level/2);
		if (enemy_ships_moving_ability < 9)
			enemy_ships_moving_ability = 9;

		
		enemy_ships_moving_speed += 0.002f*multiplayer;
		other_shapes_moving_speed += 0.002f*multiplayer;
		player_shots_speed -= 0.004f*multiplayer;
		enemy_ships_shots_speed = enemy_ships_moving_speed + 0.065f + 0.002f*multiplayer;
		maximal_number_of_enemy_ships += level*multiplayer;
		when_random_generate_enemy_ships = maximal_number_of_enemy_ships/3;

		probability_of_adding_enemy_ship -= multiplayer;
		if (probability_of_adding_enemy_ship < 2)
			probability_of_adding_enemy_ship = 2;

		probability_of_generating_enemy_shot -= multiplayer;
		if (probability_of_generating_enemy_shot < 2)
			probability_of_generating_enemy_shot = 2;

		maximal_number_of_enemy_shots = 3 * maximal_number_of_enemy_ships;
		minimal_time_beetwen_player_shots += 0.002f*multiplayer;
		return true;
	}
	return false;
}

int Difficulty_and_level::GetLevel(){
	return level;
}

void Difficulty_and_level::SetDifficulty(const int& diff){
	difficulty = diff;
	if (difficulty > 2)
		difficulty = 0;
	else if (difficulty < 0)
		difficulty = 2;

	ConstructorFunction();
}

int Difficulty_and_level::GetDifficulty(){
	return difficulty;
}


void Difficulty_and_level::ConstructorFunction(){
	if (difficulty > 2)
		difficulty = 2;

	switch (difficulty){
		case 0: {
			ships_shoted_counter = 0;
			enemy_ships_moving_ability = 20;
			enemy_ships_moving_speed = 0.04f;
			other_shapes_moving_speed = 0.03f;
			player_shots_speed = 0.35f;
			enemy_ships_shots_speed = enemy_ships_moving_speed + 0.065f;
			maximal_number_of_enemy_ships = 6;
			when_random_generate_enemy_ships = 2;
			probability_of_adding_enemy_ship = 20;
			probability_of_generating_enemy_shot = 16;
			maximal_number_of_enemy_shots = 3*maximal_number_of_enemy_ships;
			minimal_time_beetwen_player_shots = 0.055f;
		}break;
		case 1: {
			ships_shoted_counter = 0;
			enemy_ships_moving_ability = 14;
			enemy_ships_moving_speed = 0.06f;
			other_shapes_moving_speed = 0.04f;
			player_shots_speed = 0.31f;
			enemy_ships_shots_speed = enemy_ships_moving_speed + 0.085f;
			maximal_number_of_enemy_ships = 10;
			when_random_generate_enemy_ships = 5;
			probability_of_adding_enemy_ship = 15;
			probability_of_generating_enemy_shot = 12;
			maximal_number_of_enemy_shots = 4 * maximal_number_of_enemy_ships;
			minimal_time_beetwen_player_shots = 0.065f;
		}break;
		case 2: {
			ships_shoted_counter = 0;
			enemy_ships_moving_ability = 9;
			enemy_ships_moving_speed = 0.08f;
			other_shapes_moving_speed = 0.05f;
			player_shots_speed = 0.27f;
			enemy_ships_shots_speed = enemy_ships_moving_speed + 0.10f;
			maximal_number_of_enemy_ships = 15;
			when_random_generate_enemy_ships = 7;
			probability_of_adding_enemy_ship = 7;
			probability_of_generating_enemy_shot = 8;
			maximal_number_of_enemy_shots = 5 * maximal_number_of_enemy_ships;
			minimal_time_beetwen_player_shots = 0.075f;
		}break;
	}
}

void Difficulty_and_level::UpdateOnGameOver(){
	ships_shoted_counter = shoted_ships_for_level_up - (level) * 5;
}

void Difficulty_and_level::SetLevel(const int& lvl){
	level = lvl;
}