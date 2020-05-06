#include <iostream>
#include <string>
using namespace std;

#define GRID_SIZE 3

class Game
	{
		public:
			int counter = 0;
			bool game_over = false;
			int round = 0;
			char grid[GRID_SIZE][GRID_SIZE];
			void ask_move()
				{
					char move;

					if (round%2 == 0)
						{
							cout << "player-1 (x): ";
							cin >> move; set_move(move, 'x');
							round++;counter++;

						}
					else
						{
							cout << "player-2 (o): ";
							cin >> move; set_move(move, 'o');
							round++;counter++;
						}
				}


			void create_map()
				{
					int number = 1;
					for (int x=0; x < GRID_SIZE; x++)
						for (int y=0; y < GRID_SIZE; y++)
							{
								grid[x][y] = to_string(number).c_str()[0];
								number += 1;
							}
				}

			void show_map()
				{
					cout << "-----------" << endl;
					for (int x=0; x < GRID_SIZE; x++)
						{
							for (int y=0; y < GRID_SIZE; y++){cout << grid[x][y] << " | ";}
							cout << endl << "-----------" << endl;
						}
				}

			void set_move(char num, char new_move)
				{
					for (int x=0; x < GRID_SIZE; x++)
						{
							for (int y=0; y < GRID_SIZE; y++)
								{
									if (grid[x][y] == num && grid[x][y] != 'x' && grid[x][y] != 'o')
										{
											grid[x][y] = new_move;
										}
								}
						}
				}

			void check_winner()
				{
					for (int cn=0; cn < 3; cn++)
						{
							if (grid[cn][0] == grid[cn][1] && grid[cn][1] == grid[cn][2])
								{
									if (grid[cn][0] == 'x')
										{
											cout << "player-1 (x) is winner !"<< endl;
											exit(1);
										}
									else
										{
											cout << "player-2 (o) is the winner !" << endl;
											exit(1);
										}
								}

							else if(grid[0][cn] == grid[1][cn] && grid[1][cn] == grid[2][cn])
								{
									if (grid[cn][0] == 'x')
										{
											cout << "player-1 (x) is winner !"<< endl;
											exit(1);
										}
									else if (grid[cn][0] == 'o')
										{
											cout << "player-2 (o) is the winner !" << endl;
											exit(1);
										}
								}
						}
					if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
						{
							if (grid[0][0] == 'x')
								{
									cout << "player-1 (x) is winner !"<< endl;
									exit(1);
								}
							else if (grid[0][0] == 'o')
								{
									cout << "player-2 (o) is the winner !" << endl;
									exit(1);
								}
						}
					else if(grid[0][2] == grid[2][0] && grid[2][0] == grid[1][1])
						{
							if (grid[1][1] == 'x')
								{
									cout << "player-1 (x) is winner !"<< endl;
									exit(1);
								}
							else if (grid[1][1] == 'o')
								{
									cout << "player-2 (o) is the winner !" << endl;
									exit(1);
								}
						}
				}

			Game()
				{
					create_map(); system("clear");
					show_map(); ask_move(); system("clear"); check_winner();
					for (int counterB=0; counterB < 9; counterB++)
						{
							show_map(); ask_move(); system("clear"); check_winner();
						}
				}
	};


int main()
	{
		Game game;
	}

