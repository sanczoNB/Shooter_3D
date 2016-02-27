#pragma once
public ref class Difficulty_and_level
{
private:
protected: int difficulty;
protected: int level;
protected: int ships_shoted_counter;
protected: int enemy_ships_moving_ability; //NIE MNIEJ NI¯ 9!!! im wartoœæ bli¿sza 9, tym szybciej statki bêd¹ siê poruszaæ w p³aszczyŸnie ekranu
protected: float enemy_ships_moving_speed; //Im wiêksza wartoœæ, tym szybciej statki wroga bêd¹ zbli¿a³y siê do statku gracza
protected: float other_shapes_moving_speed;
protected: float player_shots_speed; //Ustawienie prêdkoœci strza³ów gracza
protected: float enemy_ships_shots_speed = enemy_ships_moving_speed; //Ustawienie prêdkoœci strza³ów statków wroga
protected: int maximal_number_of_enemy_ships; // maksymalna liczba statków wroga
protected: int when_random_generate_enemy_ships; //liczba statków wroga, powy¿ej której nastêpuje losowe generowanie kolejnych statków - innymi s³owy minimalna liczba statków wroga na ekranie
protected: int probability_of_adding_enemy_ship; //NIE MNIEJ NI¯ 2!!! Odwrotnoœæ prawdopodobieñstwa generowania statków wroga - im liczba mniejsza, tym szybciej bêd¹ generowane kolejne statki
protected: int probability_of_generating_enemy_shot; //NIE MNIEJ NI¯ 2!!! Odwrotnoœæ prawdopodobieñstwa generowania strza³ów ze statków wroga - im liczba mniejsza, tym czêœciej generowane s¹ strza³y
protected: int maximal_number_of_enemy_shots; //Najwiêksza mo¿liwa liczba strza³ów wroga obecnych na ekranie jednoczeœnie
protected: float minimal_time_beetwen_player_shots; // Odstêp czasowy pomiêdzy kolejnymi strza³ami gracza dla "ci¹g³ego" trybu strzelania - wciœniêta spacja
protected: int shoted_ships_for_level_up;

public:
	Difficulty_and_level();
	Difficulty_and_level(const int& diff);
	~Difficulty_and_level();

public:
	int GetShipsShotedCounter();
	void ResetShipsShotedCounter();
	void AddShipsShotedCounter();
	int GetEnemyShipsMovingAbility();
//	void SetEnemyShipsMovingAbility(const int& level);
	float GetEnemyShipsMovingSpeed();
//	void SetEnemyShipsMovingSpeed(const int& level);
	float GetOtherShapesMovingSpeed();
//	void SetOtherShapesMovingSpeed();
	float GetPlayerShotsSpeed();
//	void SetPlayerShotsSpeed();
	float GetEnemyShipsShotsSpeed();
//	void SetEnemyShipsShotsSpeed();
	int GetMaximalNumberOfEnemyShips(); 
//	void SetMaximalNumberOfEnemyShips();
	int GetWhenRandomGenerateEnemyShips();
//	void SetWhenRandomGenerateEnemyShips();
	int GetProbabilityOfAddingEnemyShip();
//	void SetProbabilityOfAddingEnemyShip();
	int GetProbabilityOfGeneratingEnemyShot();
//	void SetProbabilityOfGeneratingEnemyShot();
	int GetMaximalNumberOfEnemyShots(); 
//	void SetMaximalNumberOfEnemyShots();
	float GetMinimalTimeBeetwenPlayerShots();
//	void SetMinimalTimeBeetwenPlayerShots();
	
	bool UpdateLevel();
	int GetLevel();
	void SetLevel(const int& lvl);
	void SetDifficulty(const int& diff);
	int GetDifficulty();
	void UpdateOnGameOver();

protected: void ConstructorFunction();

};

