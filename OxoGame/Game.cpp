#include "pch.h"
#include "Game.h"
#include <iostream>

#pragma region gameFunctions											
void Start()
{
	BgInit();
	PlayerInit();
	GridInit();
}

void Draw()
{
	ClearBackground();
	DrawBg();
	DrawPlayers();
	DrawGrid();
}

void Update(float elapsedSec)
{
	UpdateGrid();
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
		case SDL_BUTTON_LEFT:
		{
			//std::cout << "Left mouse button released\n";

			Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
			if (g_GameOver == false)
			{
				g_MousePosition = mousePos;
				SetMove();
			}
			break;
		}
	}
}
#pragma endregion inputHandling

void BgInit() {
	TextureFromFile("recources/OXO.png", g_BackGroundTexture);
}
void DrawBg() {
	DrawTexture(g_BackGroundTexture, g_BackGroundRectDest);
}
void PlayerInit() {
	for (size_t i = 0; i < playersArr.size(); ++i)
	{
		TextureFromFile("recources/FreeCell.png", playersArr[i].playerTexture);
		playersArr[i].destRect.bottom = g_WindowHeight * .2f;
	}
	playersArr[0].destRect.left = g_WindowWidth * .1f;
	playersArr[1].destRect.left = g_WindowWidth * .8f;
	TextureFromFile("recources/GreenX.png", playersArr[0].playerTexture);
}


void DrawPlayers() {

	for (Player& player : playersArr) {
		DrawTexture(player.playerTexture, player.destRect);
	}

}

void GridInit() {
	Point2f currentCellPosition{ g_WindowWidth * .3f,g_WindowHeight * .2f };//starting pos of the cell
	grid.gridMainPos = GRID_STARTING_POS;
	int currentCell{ 0 };

	///loading all the possible textures in the cell
	for (playableCell& cell : grid.cells) {
		TextureFromFile("recources/FreeCell.png", cell.cellTexture);
		cell.state = cell.empty;
	}

	///drawing the grid
	for (size_t i = 0; i < AMOUNT_OF_ROWS; ++i)
	{
		for (size_t i = 0; i < AMOUNT_OF_COLUMNS; ++i)
		{
			grid.cells[currentCell].destRect.left = currentCellPosition.x;
			grid.cells[currentCell].destRect.bottom = currentCellPosition.y;
			currentCellPosition.x += MARGIN_BETWEEN_CELLS + CELLWIDTH;
			++currentCell;
		}
		currentCellPosition.x = g_WindowWidth * .3f;
		currentCellPosition.y += MARGIN_BETWEEN_CELLS + CELLHEIGHT;
	}
}

///
//		|    |	   
//	6	|  7 |	8  
//	----|----|-----
//	3	|  4 |	5  
//	----|----|-----
//	0	|  1 |	2   
//		|    |	   

void UpdateGrid() {
	if (g_GameOver == false)
	{
		for (playableCell& cell : grid.cells) {//voor elke cel checken of de state o is;
			//checking from idx 0
			if (grid.cells[0].state == cell.o)
			{
				if (grid.cells[1].state == cell.x)
				{
					if (grid.cells[2].state == cell.o)
					{
						TextureFromFile("recources/GreenO.png", grid.cells[0].cellTexture);
						TextureFromFile("recources/GreenX.png", grid.cells[1].cellTexture);
						TextureFromFile("recources/GreenO.png", grid.cells[2].cellTexture);
						if (g_MovePlayerOne == true)
						{
							TextureFromFile("recources/Win.png", playersArr[0].playerTexture);
							g_GameOver = true;
						}
						else {
							TextureFromFile("recources/Win.png", playersArr[1].playerTexture);
							g_GameOver = true;
						}
					}
				}
				if (grid.cells[4].state == cell.x)
				{
					if (grid.cells[8].state == cell.o)
					{
						TextureFromFile("recources/GreenO.png", grid.cells[0].cellTexture);
						TextureFromFile("recources/GreenX.png", grid.cells[4].cellTexture);
						TextureFromFile("recources/GreenO.png", grid.cells[8].cellTexture);
						if (g_MovePlayerOne == true)
						{
							TextureFromFile("recources/Win.png", playersArr[0].playerTexture);
							g_GameOver = true;
						}
						else {
							TextureFromFile("recources/Win.png", playersArr[1].playerTexture);
							g_GameOver = true;
						}
					}
				}
				if (grid.cells[3].state == cell.x)
				{
					if (grid.cells[6].state == cell.o)
					{
						TextureFromFile("recources/GreenO.png", grid.cells[0].cellTexture);
						TextureFromFile("recources/GreenX.png", grid.cells[3].cellTexture);
						TextureFromFile("recources/GreenO.png", grid.cells[6].cellTexture);
						if (g_MovePlayerOne == true)
						{
							TextureFromFile("recources/Win.png", playersArr[0].playerTexture);
							g_GameOver = true;
						}
						else {
							TextureFromFile("recources/Win.png", playersArr[1].playerTexture);
							g_GameOver = true;
						}
					}
				}
			}

			//checking from idx 3
			if (grid.cells[3].state == cell.o)
			{
				if (grid.cells[4].state == cell.x)
				{
					if (grid.cells[5].state == cell.o)
					{
						TextureFromFile("recources/GreenO.png", grid.cells[3].cellTexture);
						TextureFromFile("recources/GreenX.png", grid.cells[4].cellTexture);
						TextureFromFile("recources/GreenO.png", grid.cells[5].cellTexture);
						if (g_MovePlayerOne == true)
						{
							TextureFromFile("recources/Win.png", playersArr[0].playerTexture);
							g_GameOver = true;
						}
						else {
							TextureFromFile("recources/Win.png", playersArr[1].playerTexture);
							g_GameOver = true;
						}
					}
				}
			}

			//checking from idx 6
			if (grid.cells[6].state == cell.o)
			{
				if (grid.cells[7].state == cell.x)
				{
					if (grid.cells[8].state == cell.o)
					{
						TextureFromFile("recources/GreenO.png", grid.cells[6].cellTexture);
						TextureFromFile("recources/GreenX.png", grid.cells[7].cellTexture);
						TextureFromFile("recources/GreenO.png", grid.cells[8].cellTexture);
						if (g_MovePlayerOne == true)
						{
							TextureFromFile("recources/Win.png", playersArr[0].playerTexture);
							g_GameOver = true;
						}
						else {
							TextureFromFile("recources/Win.png", playersArr[1].playerTexture);
							g_GameOver = true;
						}
					}
				}
				if (grid.cells[4].state == cell.x)
				{
					if (grid.cells[2].state == cell.o)
					{
						TextureFromFile("recources/GreenO.png", grid.cells[6].cellTexture);
						TextureFromFile("recources/GreenX.png", grid.cells[4].cellTexture);
						TextureFromFile("recources/GreenO.png", grid.cells[2].cellTexture);
						if (g_MovePlayerOne == true)
						{
							TextureFromFile("recources/Win.png", playersArr[0].playerTexture);
							g_GameOver = true;

						}
						else {
							TextureFromFile("recources/Win.png", playersArr[1].playerTexture);
							g_GameOver = true;

						}
					}
				}
				if (grid.cells[3].state == cell.x)
				{
					if (grid.cells[0].state == cell.o)
					{
						TextureFromFile("recources/GreenO.png", grid.cells[0].cellTexture);
						TextureFromFile("recources/GreenX.png", grid.cells[3].cellTexture);
						TextureFromFile("recources/GreenO.png", grid.cells[6].cellTexture);
						if (g_MovePlayerOne == true)
						{
							TextureFromFile("recources/Win.png", playersArr[0].playerTexture);
							g_GameOver = true;
						}
						else {
							TextureFromFile("recources/Win.png", playersArr[1].playerTexture);
							g_GameOver = true;

						}
					}
				}
			}


			//checking from idx 7
			if (grid.cells[7].state == cell.o)
			{
				if (grid.cells[4].state == cell.x)
				{
					if (grid.cells[1].state == cell.o)
					{
						TextureFromFile("recources/GreenO.png", grid.cells[7].cellTexture);
						TextureFromFile("recources/GreenX.png", grid.cells[4].cellTexture);
						TextureFromFile("recources/GreenO.png", grid.cells[1].cellTexture);
						if (g_MovePlayerOne == true)
						{
							TextureFromFile("recources/Win.png", playersArr[0].playerTexture);
						}
						else {
							TextureFromFile("recources/Win.png", playersArr[1].playerTexture);
						}
					}
				}
			}

			//checking from idx 8
			if (grid.cells[8].state == cell.o)
			{
				if (grid.cells[5].state == cell.x)
				{
					if (grid.cells[2].state == cell.o)
					{
						TextureFromFile("recources/GreenO.png", grid.cells[8].cellTexture);
						TextureFromFile("recources/GreenX.png", grid.cells[5].cellTexture);
						TextureFromFile("recources/GreenO.png", grid.cells[2].cellTexture);
						g_GameOver = true;
						if (g_MovePlayerOne == true)
						{
							TextureFromFile("recources/Win.png", playersArr[0].playerTexture);
						}
						else {
							TextureFromFile("recources/Win.png", playersArr[1].playerTexture);
						}
					}
				}
			}
		}
	}

}



void DrawGrid() {
	for (playableCell& cell : grid.cells)
	{
		DrawTexture(cell.cellTexture, cell.destRect);

	}
}
void SetMove() {
	for (playableCell& cell : grid.cells) {
		if (g_MousePosition.x > cell.destRect.left and g_MousePosition.x < cell.destRect.left + CELLWIDTH and
			g_MousePosition.y > cell.destRect.bottom and g_MousePosition.y < cell.destRect.bottom + CELLHEIGHT and cell.state == cell.empty)
		{
			if (g_MovePlayerOne == true)
			{
				TextureFromFile("recources/WhiteX.png", cell.cellTexture);
				cell.state = cell.x;
				g_MovePlayerOne = false;
				g_MovePlayerTwo = true;
				UpdatePlayer();
				return;
			}
			if (g_MovePlayerTwo == true)
			{
				TextureFromFile("recources/WhiteO.png", cell.cellTexture);
				cell.state = cell.o;
				g_MovePlayerTwo = false;
				g_MovePlayerOne = true;
				UpdatePlayer();
				return;
			}
		}
	}
}
void UpdatePlayer() {
	if (g_MovePlayerOne == true)
	{
		TextureFromFile("recources/FreeCell.png", playersArr[1].playerTexture);
		TextureFromFile("recources/GreenX.png", playersArr[0].playerTexture);
	}
	else {
		TextureFromFile("recources/FreeCell.png", playersArr[0].playerTexture);
		TextureFromFile("recources/GreenO.png", playersArr[1].playerTexture);

	}
}