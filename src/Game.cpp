// Including the sfml and iostream libraires
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

// Using Namespace
using namespace sf;
using namespace std;

Game::Game()
{
	// Using all the functions once the object is created to save time
	setMainMenuText();
	setMainMenuMusic();
	setMainMenuButton();

	setBackground();
	setScoreboard();
	setOutlinePiles();
	setMenu();
	setMenuText();

	setFont();
	setTimer();
	setEndMenu();
}

void Game::setBackground()
{
	// The function sets the background texture and set the sprite
	// with that texture
	background_texture.loadFromFile("Assets/Background.jpg");
	background.setTexture(background_texture);
}

void Game::setScoreboard()
{
	// The function sets the scoreboard's size and it's fill
	// color
	score_board.setSize(Vector2f(1600, 80));
	score_board.setFillColor(Color(169, 169, 169, 128));
}

void Game::setMenu()
{
	// The function sets the menu box and it's content (resume button &
	// new game button & quit button)
	menu_box.setSize(Vector2f(400, 550));
	menu_box.setPosition(600, 250);
	menu_box.setFillColor(Color(69, 163, 113, 245));
	menu_box.setOutlineColor(Color::Black);
	menu_box.setOutlineThickness(1);

	resume.setSize(Vector2f(300, 100));
	resume.setPosition(650, 400);
	resume.setFillColor(Color(218, 247, 166));
	resume.setOutlineColor(Color::Black);
	resume.setOutlineThickness(1);

	new_game.setSize(Vector2f(300, 100));
	new_game.setPosition(650, 530);
	new_game.setFillColor(Color(218, 247, 166));
	new_game.setOutlineColor(Color::Black);
	new_game.setOutlineThickness(1);

	quit.setSize(Vector2f(300, 100));
	quit.setPosition(650, 660);
	quit.setFillColor(Color(218, 247, 166));
	quit.setOutlineColor(Color::Black);
	quit.setOutlineThickness(1);
}

void Game::setMenuText()
{
	// The function sets the text that're inside
	// the menu window
	menu_text.setFont(font);
	menu_text.setString("Menu");
	menu_text.setCharacterSize(40);
	menu_text.setPosition(740, 300);
	menu_text.setFillColor(Color::Black);

	resume_text.setFont(font);
	resume_text.setString("Resume");
	resume_text.setCharacterSize(40);
	resume_text.setPosition(710, 425);
	resume_text.setFillColor(Color::Black);

	new_game_text.setFont(font);
	new_game_text.setString("New Game");
	new_game_text.setCharacterSize(40);
	new_game_text.setPosition(685, 555);
	new_game_text.setFillColor(Color::Black);

	quit_text.setFont(font);
	quit_text.setString("Quit");
	quit_text.setCharacterSize(40);
	quit_text.setPosition(740, 685);
	quit_text.setFillColor(Color::Black);
}

void Game::setFont()
{
	// The function sets the font for the game
	font.loadFromFile("Assets/Martian_Mono/MartianMono-VariableFont_wdth,wght.ttf");
}

void Game::setTimer()
{
	// The function sets the timer for the game
	timer.setFont(font);
	timer.setCharacterSize(20);
	timer.setPosition(715, 30);
}

Text Game::drawTimer()
{
	time_elapsed2 = clock.getElapsedTime() - time_elapsed1;
	int timer_minutes = int(time_elapsed2.asSeconds()) / 60;
	int timer_seconds = int(time_elapsed2.asSeconds()) % 60;
	if (timer_minutes < 10 && timer_seconds >= 10)
		timer.setString("Timer: 0" + to_string(timer_minutes) + ":" + to_string(timer_seconds));
	else if (timer_seconds < 10 && timer_minutes >= 10)
		timer.setString("Timer: " + to_string(timer_minutes) + ":0" + to_string(timer_seconds));
	else if (timer_minutes < 10 && timer_seconds < 10)
		timer.setString("Timer: 0" + to_string(timer_minutes) + ":0" + to_string(timer_seconds));
	else
		timer.setString("Timer: " + to_string(timer_minutes) + ":" + to_string(timer_seconds));
	return timer;
}

void Game::setMainMenuMusic()
{
	// The function sets the main menu music
	window_start_buffer.loadFromFile("Assets/Sounds/Start Sound.wav");
	window_start.setBuffer(window_start_buffer);
	music_start_buffer.loadFromFile("Assets/Sounds/Start Music.wav");
	music_start.setBuffer(music_start_buffer);

	sound_On_texture.loadFromFile("Assets/Sound on.png");
	sound_on.setTexture(sound_On_texture);
	sound_on.setPosition(Vector2f(100, 750));

	mute_texture.loadFromFile("Assets/Mute.png");
	mute.setTexture(mute_texture);
	mute.setPosition(Vector2f(100, 750));
}


void Game::setMainMenuText()
{
	// The function sets the main menu text which includes the "Made By Tryerz" text and image of the team
	made_by.setFont(font);
	made_by.setString("Made  By\n TRYERZ");
	made_by.setCharacterSize(20);
	made_by.setPosition(1300, 680);
	tryerz_texture.loadFromFile("Assets/Tryerz.jpg");
	tryerz_image.setTexture(tryerz_texture);
	tryerz_image.setPosition(1290, 740);
	tryerz_image.setScale(0.23, 0.23);

	// The "Start Game" blue button is set with the "Welcome to the Tryerz Solitare" text
	start.setFont(font);
	start.setString("Start Game");
	start.setCharacterSize(25);
	start.setPosition(700, 435);
	start_message.setFont(font);
	start_message.setString("Welcome to the Tryerz Solitaire!!\n\n\n\n\n\n\n");
	start_message.setCharacterSize(25);
	start_message.setPosition(490, 300);
}

void Game::setMainMenuButton()
{
	// The function sets the start button's (Size, Position & Color)
	start_button.setSize(Vector2f(250, 70));
	start_button.setPosition(Vector2f(675, 415));
	start_button.setFillColor(Color(0, 181, 212));
	start_button.setOutlineColor(Color::Black);
	start_button.setOutlineThickness(1);
}

void Game::setOutlinePiles()
{
	// The function sets all 12 outline piles so we can draw them
	// through out the game
	outline_piles = new OutlinePile[12];
	outline_piles[0] = OutlinePile(290, 120);
	outline_piles[1] = OutlinePile(740, 120);
	outline_piles[2] = OutlinePile(890, 120);
	outline_piles[3] = OutlinePile(1040, 120);
	outline_piles[4] = OutlinePile(1190, 120);
	outline_piles[5] = OutlinePile(290, 370);
	outline_piles[6] = OutlinePile(440, 370);
	outline_piles[7] = OutlinePile(590, 370);
	outline_piles[8] = OutlinePile(740, 370);
	outline_piles[9] = OutlinePile(890, 370);
	outline_piles[10] = OutlinePile(1040, 370);
	outline_piles[11] = OutlinePile(1190, 370);
}

void Game::drawOutlinePiles(RenderWindow& window)
{
	for (int i = 0; i < 12; i++)
		window.draw(outline_piles[i].pileOutline);
}

void Game::setEndMenu()
{
	// The function sets the background blurred image and 
	// the "You Won!" text
	blurred_page.setSize(Vector2f(1600, 900));
	blurred_page.setFillColor(Color(255, 255, 255, 10));

	you_won.setFont(font);
	you_won.setString("You Won!!");
	you_won.setCharacterSize(50);
	you_won.setPosition(Vector2f(635, 300));
	you_won.setFillColor(Color::Black);

	winning_theme_buffer.loadFromFile("Assets/Sounds/Winning Theme.wav");
	winning_theme_music.setBuffer(winning_theme_buffer);
}

void Game::setEndMenuButton()
{
	// The function updates the menu buttons as to be able to be used 
	// when the player wins again saving up space and not creating
	// new ones
	timer.setFillColor(Color::Black);

	new_game.setPosition(470, 530);
	new_game_text.setPosition(Vector2f(500, 555));

	quit.setPosition(830, 530);
	quit_text.setPosition(Vector2f(920, 555));
}
