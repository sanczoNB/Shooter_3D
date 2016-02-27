#pragma once
public ref class Difficulty_and_level
{
private:
protected: int difficulty;
protected: int level;
protected: int ships_shoted_counter;
protected: int enemy_ships_moving_ability; //NIE MNIEJ NI� 9!!! im warto�� bli�sza 9, tym szybciej statki b�d� si� porusza� w p�aszczy�nie ekranu
protected: float enemy_ships_moving_speed; //Im wi�ksza warto��, tym szybciej statki wroga b�d� zbli�a�y si� do statku gracza
protected: float other_shapes_moving_speed;
protected: float player_shots_speed; //Ustawienie pr�dko�ci strza��w gracza
protected: float enemy_ships_shots_speed = enemy_ships_moving_speed; //Ustawienie pr�dko�ci strza��w statk�w wroga
protected: int maximal_number_of_enemy_ships; // maksymalna liczba statk�w wroga
protected: int when_random_generate_enemy_ships; //liczba statk�w wroga, powy�ej kt�rej nast�puje losowe generowanie kolejnych statk�w - innymi s�owy minimalna liczba statk�w wroga na ekranie
protected: int probability_of_adding_enemy_ship; //NIE MNIEJ NI� 2!!! Odwrotno�� prawdopodobie�stwa generowania statk�w wroga - im liczba mniejsza, tym szybciej b�d� generowane kolejne statki
protected: int probability_of_generating_enemy_shot; //NIE MNIEJ NI� 2!!! Odwrotno�� prawdopodobie�stwa generowania strza��w ze statk�w wroga - im liczba mniejsza, tym cz�ciej generowane s� strza�y
protected: int maximal_number_of_enemy_shots; //Najwi�ksza mo�liwa liczba strza��w wroga obecnych na ekranie jednocze�nie
protected: float minimal_time_beetwen_player_shots; // Odst�p czasowy pomi�dzy kolejnymi strza�ami gracza dla "ci�g�ego" trybu strzelania - wci�ni�ta spacja
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

