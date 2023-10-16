#pragma once
using namespace utils;
#include <array>
#pragma region gameInformation
std::string g_WindowTitle{ "OxoGame - Terentyev, Alexander" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
const int AMOUNT_OF_PLAYERS{ 2 };
const int AMOUNT_OF_ROWS{ 3 };
const int AMOUNT_OF_COLUMNS{ 3 };
const int TOTAL_CELLS{ AMOUNT_OF_COLUMNS * AMOUNT_OF_ROWS };
const Point2f GRID_STARTING_POS{ g_WindowWidth * .4f,g_WindowHeight * .4f };
const int MARGIN_BETWEEN_CELLS{ 10 };
const int CELLWIDTH{ 60 }, CELLHEIGHT{ 60 };
Point2f g_MousePosition{};

bool g_MovePlayerOne{ true };
bool g_MovePlayerTwo{ false };
bool g_GameOver{ false };

Texture g_BackGroundTexture{};
Rectf g_BackGroundRectDest{0,0,g_WindowWidth,g_WindowHeight};

struct Player {
	Rectf destRect{};
	Texture playerTexture{  };
};

std::array<Player, AMOUNT_OF_PLAYERS> playersArr;

struct playableCell
{
	Point2f cellPosition{};
	Texture cellTexture{};


	Rectf destRect{ cellPosition.x,cellPosition.y,CELLWIDTH,CELLHEIGHT };

	enum cellState {
		empty,
		x,
		o
	};
	cellState state{ empty };
};

struct Grid
{
	Point2f gridMainPos{GRID_STARTING_POS};
	std::array<playableCell, TOTAL_CELLS> cells;
};


Texture g_PlayerTexture{};

Grid grid{};

void BgInit();
void DrawBg();
void PlayerInit();
void UpdatePlayer();
void DrawPlayers();
void GridInit();
void DrawGrid();
void UpdateGrid();

void SetMove();


#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
