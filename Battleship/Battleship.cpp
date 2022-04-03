// Battleship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <vector>
#include <string>


//Eden Szopa
//Columbia College Chicago - C++ Programming 1 SP22
//03/30/2022

//Credits: 
//Reference DisplayPhil and DisplayPlayer to print out the board for the game:
//https://www.quora.com/How-do-you-print-an-array-but-every-3-values-add-a-line-break-C-arrays-string-loops-development
//Commenter - Praveen Shankar




int main()
{

    std::string playerName;
    std::string computerName = "Phil";
    int k = 0;
    int totalShips = 7;
    int totalShipsOnBoard = 0;
    int x;
    int y;
    int coordinateInput;
    int totalShipsPhil = 0;
    int totalShipsInGame = totalShipsOnBoard + totalShipsPhil;
    //String Array containg the information that will be displayer for the players and the computers board. 
    //I wasnt sure how to create a board where I could change the vallue and I thought an array would be best because i can reassign the string at the 
    //location that the player selects
    //Add method that reasigns the location of the array with a coordinate
    //Changed the string array to a Vector class 

    std::vector<std::string> playerBoard
    { 
        "--"  "0", "1", "2", "3", "4", "5", "6", "7",
        "0", "0", "0", "0", "0", "0", "0", "0", "0",
        "1", "0", "0", "0", "0", "0", "0", "0", "0",
        "2", "0", "0", "0", "0", "0", "0", "0", "0",
        "3", "0", "0", "0", "0", "0", "0", "0", "0",
        "4", "0", "0", "0", "0", "0", "0", "0", "0",
        "5", "0", "0", "0", "0", "0", "0", "0", "0",
        "6", "0", "0", "0", "0", "0", "0", "0", "0",
        "7", "0", "0", "0", "0", "0", "0", "0", "0",
    };

    std::vector < std::string > philBoard
    {
        "--"  "0", "1", "2", "3", "4", "5", "6", "7",
         "0", "0", "0", "0", "0", "0", "0", "0", "0",
         "1", "0", "0", "0", "0", "0", "0", "0", "0",
         "2", "0", "0", "0", "0", "0", "0", "0", "0",
         "3", "0", "0", "0", "0", "0", "0", "0", "0",
         "4", "0", "0", "0", "0", "0", "0", "0", "0",
         "5", "0", "0", "0", "0", "0", "0", "0", "0",
         "6", "0", "0", "0", "0", "0", "0", "0", "0",
         "7", "0", "0", "0", "0", "0", "0", "0", "0",
    };

    std::vector < std::string > computerBoard
    {
        "--"  "0", "1", "2", "3", "4", "5", "6", "7",
         "0", "0", "0", "0", "0", "0", "0", "0", "0",
         "1", "0", "0", "0", "0", "0", "0", "0", "0",
         "2", "0", "0", "0", "0", "0", "0", "0", "0",
         "3", "0", "0", "0", "0", "0", "0", "0", "0",
         "4", "0", "0", "0", "0", "0", "0", "0", "0",
         "5", "0", "0", "0", "0", "0", "0", "0", "0",
         "6", "0", "0", "0", "0", "0", "0", "0", "0",
         "7", "0", "0", "0", "0", "0", "0", "0", "0",
    };

    std::vector < std::string > endValue
    {
        "HIT", "MISS", "NEAR MISS"
    };


    //Start game, explain the game rules
    std::cout << "Welcome to Battleship!\n";
    std::cout << "RULES:\n";
    std::cout << "1. You have to destroy your opponent's war ships before he destroys yours.\n";
    std::cout << "2. The board is 8x8 grid size in which you are able to place your ships.\n";
    std::cout << "3. You have a fleet of 7 ships, each is 1x1 grid size.\n";
    std::cout << "4. After placing your ships, you can attack the enemy. To attack an area, enter the x and y coordinates\n(make sure to add a space in between them)\n";
    std::cout << "5. Attack hit to the enemy ship is marked by an H.\n";
    std::cout << "6. A miss is marked with an M and your turn ends\n";
    std::cout << "7. * is used to represent the ships on your board.\n";
    std::cout << "8. If the miss is a near miss a message will display letting you know that it was a near miss and your turn will end.\n";

    //Ask for players name, this will be used to indicate which board represents the player and which represents the computer
    std::cout << "Please enter your name:";
    std::cin >> playerName;
    //The computers name is Phil, thought it would get boring to just refer to the computer as computer the entire game
    std::cout << "Hello, " << playerName << " you will be playing against Phil the computer\n\n";

    //Randomize ship placement for Phil
    while (totalShipsPhil < 7)
    {
        //Ask the player to input the x and y coordinates, reassign these the x and y integers to these numbers

        int xCoordinate = rand() % (7 - 0 + 1) + 0;
        int yCoordinate = rand() % (7 - 0 + 1) + 0;

        //Used this to check if x and y coordinates were being saved and added to the board for Phil == they are
        //std::cout << xCoordinate << ", " << yCoordinate;

        //Take each possible coordinate, then check if the space is a 0 on the array at the array element that the coordinate is assigned to
        //If it is available replace the 0 to a * and update board and message letting player know how many ships are on the board.
        //There's a more efficient way to do this, but my brain is fried and I just wanted it to work. So I apologize for the massive amount of code that is about to happen.

        //0,0
        if (xCoordinate == 0 && yCoordinate == 0)
        {
            if (philBoard[9] == "0")
            {
                philBoard[9] = "*";
                totalShipsPhil++;
            }
        }

        //0, 1
        if (xCoordinate == 0 && yCoordinate == 1)
        {
            if (philBoard[18] == "0")
            {
                philBoard[18] = "*";
                totalShipsPhil++;
            }
        }

        //0, 2
        if (xCoordinate == 0 && yCoordinate == 2)
        {
            if (philBoard[27] == "0")
            {
                philBoard[27] = "*";
                totalShipsPhil++;
            }
        }

        //0, 3
        if (xCoordinate == 0 && yCoordinate == 3)
        {
            if (philBoard[36] == "0")
            {
                philBoard[36] = "*";
                totalShipsPhil++;
            }
        }

        //0, 4
        if (xCoordinate == 0 && yCoordinate == 4)
        {
            if (philBoard[45] == "0")
            {
                philBoard[45] = "*";
                totalShipsPhil++;
            }
        }

        //0, 5
        if (xCoordinate == 0 && yCoordinate == 5)
        {
            if (philBoard[54] == "0")
            {
                philBoard[54] = "*";
                totalShipsPhil++;
            }
        }

        //0, 6
        if (xCoordinate == 0 && yCoordinate == 6)
        {
            if (philBoard[63] == "0")
            {
                philBoard[63] = "*";
                totalShipsPhil++;
            }
        }

        //0, 7
        if (xCoordinate == 0 && yCoordinate == 7)
        {
            if (philBoard[72] == "0")
            {
                philBoard[72] = "*";
                totalShipsPhil++;
            }
        }

        //1, 0
        if (xCoordinate == 1 && yCoordinate == 0)
        {
            if (philBoard[10] == "0")
            {
                philBoard[10] = "*";
                totalShipsPhil++;
            }
        }

        //1, 1
        if (xCoordinate == 1 && yCoordinate == 1)
        {
            if (philBoard[19] == "0")
            {
                philBoard[19] = "*";
                totalShipsPhil++;
            }
        }

        //1, 2
        if (xCoordinate == 1 && yCoordinate == 2)
        {
            if (philBoard[28] == "0")
            {
                philBoard[28] = "*";
                totalShipsPhil++;
            }
        }

        //1, 3
        if (xCoordinate == 1 && yCoordinate == 3)
        {
            if (philBoard[37] == "0")
            {
                philBoard[37] = "*";
                totalShipsPhil++;
            }
        }

        //1, 4
        if (xCoordinate == 1 && yCoordinate == 4)
        {
            if (philBoard[46] == "0")
            {
                philBoard[46] = "*";
                totalShipsPhil++;
            }
        }

        //1, 5
        if (xCoordinate == 1 && yCoordinate == 5)
        {
            if (philBoard[55] == "0")
            {
                philBoard[55] = "*";
                totalShipsPhil++;
            }
        }

        //1, 7
        if (xCoordinate == 1 && yCoordinate == 7)
        {
            if (philBoard[73] == "0")
            {
                philBoard[73] = "*";
                totalShipsPhil++;
            }
        }

        //2, 0
        if (xCoordinate == 2 && yCoordinate == 0)
        {
            if (philBoard[11] == "0")
            {
                philBoard[11] = "*";
                totalShipsPhil++;
            }
        }

        //2, 1
        if (xCoordinate == 2 && yCoordinate == 1)
        {
            if (philBoard[20] == "0")
            {
                philBoard[20] = "*";
                totalShipsPhil++;
            }
        }

        //2, 2
        if (xCoordinate == 2 && yCoordinate == 2)
        {
            if (philBoard[29] == "0")
            {
                philBoard[29] = "*";
                totalShipsPhil++;
            }
        }

        //2, 3
        if (xCoordinate == 2 && yCoordinate == 3)
        {
            if (philBoard[38] == "0")
            {
                philBoard[38] = "*";
                totalShipsPhil++;
            }
        }

        //2, 4
        if (xCoordinate == 2 && yCoordinate == 4)
        {
            if (philBoard[47] == "0")
            {
                philBoard[47] = "*";
                totalShipsPhil++;
            }
        }

        //2, 5
        if (xCoordinate == 2 && yCoordinate == 5)
        {
            if (philBoard[56] == "0")
            {
                philBoard[56] = "*";
                totalShipsPhil++;
            }
        }

        //2, 6
        if (xCoordinate == 2 && yCoordinate == 6)
        {
            if (philBoard[65] == "0")
            {
                philBoard[65] = "*";
                totalShipsPhil++;
            }
        }

        //2, 7
        if (xCoordinate == 2 && yCoordinate == 7)
        {
            if (philBoard[74] == "0")
            {
                philBoard[74] = "*";
                totalShipsPhil++;
            }
        }

        //3, 0
        if (xCoordinate == 3 && yCoordinate == 0)
        {
            if (philBoard[12] == "0")
            {
                philBoard[12] = "*";
                totalShipsPhil++;
            }
        }

        //3, 1
        if (xCoordinate == 3 && yCoordinate == 1)
        {
            if (philBoard[21] == "0")
            {
                philBoard[21] = "*";
                totalShipsPhil++;
            }
        }

        //3, 2
        if (xCoordinate == 3 && yCoordinate == 2)
        {
            if (philBoard[30] == "0")
            {
                philBoard[30] = "*";
                totalShipsPhil++;
            }
        }

        //3, 3
        if (xCoordinate == 3 && yCoordinate == 3)
        {
            if (philBoard[39] == "0")
            {
                philBoard[39] = "*";
                totalShipsPhil++;
            }
        }

        //3, 4
        if (xCoordinate == 3 && yCoordinate == 4)
        {
            if (philBoard[48] == "0")
            {
                philBoard[48] = "*";
                totalShipsPhil++;
            }
        }

        //3, 5
        if (xCoordinate == 3 && yCoordinate == 5)
        {
            if (philBoard[57] == "0")
            {
                philBoard[57] = "*";
                totalShipsPhil++;
            }
        }

        //3, 6
        if (xCoordinate == 3 && yCoordinate == 6)
        {
            if (philBoard[66] == "0")
            {
                philBoard[66] = "*";
                totalShipsPhil++;
            }
        }

        //3, 7 
        if (xCoordinate == 3 && yCoordinate == 7)
        {
            if (philBoard[75] == "0")
            {
                philBoard[75] = "*";
                totalShipsPhil++;
            }
        }

        //4, 0
        if (xCoordinate == 4 && yCoordinate == 0)
        {
            if (philBoard[13] == "0")
            {
                philBoard[13] = "*";
                totalShipsPhil++;
            }
        }

        //4, 1
        if (xCoordinate == 4 && yCoordinate == 1)
        {
            if (philBoard[22] == "0")
            {
                philBoard[22] = "*";
                totalShipsPhil++;
            }
        }

        //4, 2
        if (xCoordinate == 4 && yCoordinate == 2)
        {
            if (philBoard[31] == "0")
            {
                philBoard[31] = "*";
                totalShipsPhil++;
            }
        }

        //4, 3
        if (xCoordinate == 4 && yCoordinate == 3)
        {
            if (philBoard[40] == "0")
            {
                philBoard[40] = "*";
                totalShipsPhil++;
            }
        }

        //4, 4
        if (xCoordinate == 4 && yCoordinate == 4)
        {
            if (philBoard[49] == "0")
            {
                philBoard[49] = "*";
                totalShipsPhil++;
            }
        }

        //4, 5
        if (xCoordinate == 4 && yCoordinate == 5)
        {
            if (philBoard[58] == "0")
            {
                philBoard[58] = "*";
                totalShipsPhil++;
            }
        }

        //4, 6
        if (xCoordinate == 4 && yCoordinate == 6)
        {
            if (philBoard[67] == "0")
            {
                philBoard[67] = "*";
                totalShipsPhil++;
            }
        }

        //4, 7
        if (xCoordinate == 4 && yCoordinate == 7)
        {
            if (philBoard[76] == "0")
            {
                philBoard[76] = "*";
                totalShipsPhil++;
            }
        }

        //5, 0
        if (xCoordinate == 5 && yCoordinate == 0)
        {
            if (philBoard[14] == "0")
            {
                philBoard[14] = "*";
                totalShipsPhil++;
            }
        }

        //5, 1
        if (xCoordinate == 5 && yCoordinate == 1)
        {
            if (philBoard[23] == "0")
            {
                philBoard[23] = "*";
                totalShipsPhil++;
            }
        }

        //5, 2
        if (xCoordinate == 5 && yCoordinate == 2)
        {
            if (philBoard[32] == "0")
            {
                philBoard[32] = "*";
                totalShipsPhil++;
            }
        }

        //5, 3
        if (xCoordinate == 5 && yCoordinate == 3)
        {
            if (philBoard[41] == "0")
            {
                philBoard[41] = "*";
                totalShipsPhil++;
            }
        }

        //5, 4
        if (xCoordinate == 5 && yCoordinate == 4)
        {
            if (philBoard[50] == "0")
            {
                philBoard[50] = "*";
                totalShipsPhil++;
            }
        }

        //5, 5
        if (xCoordinate == 5 && yCoordinate == 5)
        {
            if (philBoard[59] == "0")
            {
                philBoard[59] = "*";
                totalShipsPhil++;
            }
        }

        //5, 6
        if (xCoordinate == 5 && yCoordinate == 6)
        {
            if (philBoard[68] == "0")
            {
                philBoard[68] = "*";
                totalShipsPhil++;
            }
        }

        //5, 7
        if (xCoordinate == 5 && yCoordinate == 7)
        {
            if (philBoard[77] == "0")
            {
                philBoard[77] = "*";
                totalShipsPhil++;
            }
        }

        //6, 0
        if (xCoordinate == 6 && yCoordinate == 0)
        {
            if (philBoard[15] == "0")
            {
                philBoard[15] = "*";
                totalShipsPhil++;
            }
        }

        //6, 1
        if (xCoordinate == 6 && yCoordinate == 1)
        {
            if (philBoard[24] == "0")
            {
                philBoard[24] = "*";
                totalShipsPhil++;
            }
        }

        //6, 2
        if (xCoordinate == 6 && yCoordinate == 2)
        {
            if (philBoard[33] == "0")
            {
                philBoard[33] = "*";
                totalShipsPhil++;
            }
        }

        //6, 3
        if (xCoordinate == 6 && yCoordinate == 3)
        {
            if (philBoard[42] == "0")
            {
                philBoard[42] = "*";
                totalShipsPhil++;
            }
        }

        //6, 4
        if (xCoordinate == 6 && yCoordinate == 4)
        {
            if (philBoard[51] == "0")
            {
                philBoard[51] = "*";
                totalShipsPhil++;
            }
        }

        //6, 5
        if (xCoordinate == 6 && yCoordinate == 5)
        {
            if (philBoard[60] == "0")
            {
                philBoard[60] = "*";
                totalShipsPhil++;
            }
        }

        //6, 6
        if (xCoordinate == 6 && yCoordinate == 6)
        {
            if (philBoard[69] == "0")
            {
                philBoard[69] = "*";
                totalShipsPhil++;
            }
        }

        //6, 7
        if (xCoordinate == 6 && yCoordinate == 7)
        {
            if (philBoard[78] == "0")
            {
                philBoard[78] = "*";
                totalShipsPhil++;
            }
        }

        //7, 0
        if (xCoordinate == 7 && yCoordinate == 0)
        {
            if (philBoard[16] == "0")
            {
                philBoard[16] = "*";
                totalShipsPhil++;
            }
        }

        //7, 1
        if (xCoordinate == 7 && yCoordinate == 1)
        {
            if (philBoard[25] == "0")
            {
                philBoard[25] = "*";
                totalShipsPhil++;
            }
        }

        //7, 2
        if (xCoordinate == 7 && yCoordinate == 2)
        {
            if (philBoard[34] == "0")
            {
                philBoard[34] = "*";
                totalShipsPhil++;
            }
        }

        //7, 3
        if (xCoordinate == 7 && yCoordinate == 3)
        {
            if (philBoard[43] == "0")
            {
                philBoard[43] = "*";
                totalShipsPhil++;
            }
        }

        //7, 4
        if (xCoordinate == 7 && yCoordinate == 4)
        {
            if (philBoard[52] == "0")
            {
                philBoard[52] = "*";
                totalShipsPhil++;
            }
        }

        //7, 5
        if (xCoordinate == 7 && yCoordinate == 5)
        {
            if (philBoard[61] == "0")
            {
                philBoard[61] = "*";
                totalShipsPhil++;
            }
        }

        //7, 6
        if (xCoordinate == 7 && yCoordinate == 6)
        {
            if (philBoard[70] == "0")
            {
                philBoard[70] = "*";
                totalShipsPhil++;
            }
        }

        //7, 7
        if (xCoordinate == 7 && yCoordinate == 7)
        {
            if (philBoard[79] == "0")
            {
                philBoard[79] = "*";
                totalShipsPhil++;
            }
        }


        //Used to check to see if the total ships for Phil on the board was being updated, it is.
        //std::cout << "Phil had: " << totalShipsPhil;
    }

    //Display Phil's Board
    std::cout << "Phil's Board:\n";

    for (int i = 0; i < philBoard.size(); i++)
    {
        std::cout << philBoard[i] << " ";

        if ((i + 2) % 9 == 0)
        {
            std::cout << std::endl;
        }
    }

    //Display Players Board
    std::cout << "\n\n" << playerName << " Board:\n";  
    for (int i = 0; i < playerBoard.size(); i++)
    {
        std::cout << playerBoard[i] << " ";

        if ((i + 2) % 9 == 0)
        {
            std::cout << std::endl;
        }
    }

    

    //Instruction player to choose x and y coordinates to place ships on board
    std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";

    //Loop through this until the player has placed 7 ships on their board, this places a ship on the board and checks if coordinate is available
    while (totalShipsOnBoard < 7)
    {
        //Ask the player to input the x and y coordinates, reassign these the x and y integers to these numbers
        std::cout << "X coordinate: \n";

        std::cin >> x;

        std::cout << "Y coordinate: \n";

        std::cin >> y;

        //Check to see if this is within the coordinate range for x
        if (0 >= x <= 7) 
        {
            //Check to see if this is within the coordinate range for y
            if (0 >= y <= 7)
            {
                //Take each possible coordinate, then check if the space is a 0 on the array at the array element that the coordinate is assigned to
                //If it is available replace the 0 to a * and update board and message letting player know how many ships are on the board.
                //There's a more efficient way to do this, but my brain is fried and I just wanted it to work. So I apologize for the massive amount of code that is about to happen.

                //0,0
                if (x == 0 && y == 0)
                {
                    if (playerBoard[9] == "0")
                    {
                        playerBoard[9] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //0, 1
                if (x == 0 && y == 1)
                {
                    if (playerBoard[18] == "0")
                    {
                        playerBoard[18] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //0, 2
                if (x == 0 && y == 2)
                {
                    if (playerBoard[27] == "0")
                    {
                        playerBoard[27] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //0, 3
                if (x == 0 && y == 3)
                {
                    if (playerBoard[36] == "0")
                    {
                        playerBoard[36] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //0, 4
                if (x == 0 && y == 4)
                {
                    if (playerBoard[45] == "0")
                    {
                        playerBoard[45] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //0, 5
                if (x == 0 && y == 5)
                {
                    if (playerBoard[54] == "0")
                    {
                        playerBoard[54] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //0, 6
                if (x == 0 && y == 6)
                {
                    if (playerBoard[63] == "0")
                    {
                        playerBoard[63] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //0, 7
                if (x == 0 && y == 7)
                {
                    if (playerBoard[72] == "0")
                    {
                        playerBoard[72] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }
                

                //1, 0
                if (x == 1 && y == 0)
                {
                    if (playerBoard[10] == "0")
                    {
                        playerBoard[10] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //1, 1
                if (x == 1 && y == 1)
                {
                    if (playerBoard[19] == "0")
                    {
                        playerBoard[19] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //1, 2
                if (x == 1 && y == 2)
                {
                    if (playerBoard[28] == "0")
                    {
                        playerBoard[28] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //1, 3 
                if (x == 1 && y == 3)
                {
                    if (playerBoard[37] == "0")
                    {
                        playerBoard[37] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //1, 4
                if (x == 1 && y == 4)
                {
                    if (playerBoard[46] == "0")
                    {
                        playerBoard[46] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //1, 5
                if (x == 1 && y == 5)
                {
                    if (playerBoard[55] == "0")
                    {
                        playerBoard[55] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //1, 6
                if (x == 1 && y == 6)
                {
                    if (playerBoard[64] == "0")
                    {
                        playerBoard[64] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //1, 7
                if (x == 1 && y == 7)
                {
                    if (playerBoard[73] == "0")
                    {
                        playerBoard[73] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //2, 0
                if (x == 2 && y == 0)
                {
                    if (playerBoard[11] == "0")
                    {
                        playerBoard[11] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //2, 1
                if (x == 2 && y == 1)
                {
                    if (playerBoard[20] == "0")
                    {
                        playerBoard[20] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //2, 2
                if (x == 2 && y == 2)
                {
                    if (playerBoard[29] == "0")
                    {
                        playerBoard[29] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //2, 3
                if (x == 2 && y == 3)
                {
                    if (playerBoard[38] == "0")
                    {
                        playerBoard[38] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //2, 4
                if (x == 2 && y == 4)
                {
                    if (playerBoard[47] == "0")
                    {
                        playerBoard[47] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //2, 5
                if (x == 2 && y == 5)
                {
                    if (playerBoard[56] == "0")
                    {
                        playerBoard[56] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //2, 6
                if (x == 2 && y == 6)
                {
                    if (playerBoard[65] == "0")
                    {
                        playerBoard[65] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //2, 7
                if (x == 2 && y == 7)
                {
                    if (playerBoard[74] == "0")
                    {
                        playerBoard[74] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }


                //3, 0
                if (x == 3 && y == 0)
                {
                    if (playerBoard[12] == "0")
                    {
                        playerBoard[12] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //3, 1
                if (x == 3 && y == 1)
                {
                    if (playerBoard[21] == "0")
                    {
                        playerBoard[21] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //3, 2
                if (x == 3 && y == 2)
                {
                    if (playerBoard[30] == "0")
                    {
                        playerBoard[30] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //3, 3
                if (x == 3 && y == 3)
                {
                    if (playerBoard[39] == "0")
                    {
                        playerBoard[39] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //3, 4
                if (x == 3 && y == 4)
                {
                    if (playerBoard[48] == "0")
                    {
                        playerBoard[48] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //3, 5
                if (x == 3 && y == 5)
                {
                    if (playerBoard[57] == "0")
                    {
                        playerBoard[57] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //3, 6
                if (x == 3 && y == 6)
                {
                    if (playerBoard[66] == "0")
                    {
                        playerBoard[66] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //3, 7
                if (x == 3 && y == 7)
                {
                    if (playerBoard[75] == "0")
                    {
                        playerBoard[75] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //4, 0
                if (x == 4 && y == 0)
                {
                    if (playerBoard[13] == "0")
                    {
                        playerBoard[13] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //4, 1
                if (x == 4 && y == 1)
                {
                    if (playerBoard[22] == "0")
                    {
                        playerBoard[22] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //4, 2
                if (x == 4 && y == 2)
                {
                    if (playerBoard[31] == "0")
                    {
                        playerBoard[31] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //4, 3
                if (x == 4 && y == 3)
                {
                    if (playerBoard[40] == "0")
                    {
                        playerBoard[40] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //4, 4
                if (x == 4 && y == 4)
                {
                    if (playerBoard[49] == "0")
                    {
                        playerBoard[49] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //4, 5
                if (x == 4 && y == 5)
                {
                    if (playerBoard[58] == "0")
                    {
                        playerBoard[58] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //4, 6
                if (x == 4 && y == 6)
                {
                    if (playerBoard[67] == "0")
                    {
                        playerBoard[67] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //4, 7
                if (x == 4 && y == 7)
                {
                    if (playerBoard[76] == "0")
                    {
                        playerBoard[76] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //5, 0
                if (x == 5 && y == 0)
                {
                    if (playerBoard[14] == "0")
                    {
                        playerBoard[14] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //5, 1
                if (x == 5 && y == 1)
                {
                    if (playerBoard[23] == "0")
                    {
                        playerBoard[23] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //5, 2
                if (x == 5 && y == 2)
                {
                    if (playerBoard[32] == "0")
                    {
                        playerBoard[32] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //5, 3
                if (x == 5 && y == 3)
                {
                    if (playerBoard[41] == "0")
                    {
                        playerBoard[41] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //5, 4
                if (x == 5 && y == 4)
                {
                    if (playerBoard[50] == "0")
                    {
                        playerBoard[50] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //5, 5
                if (x == 5 && y == 5)
                {
                    if (playerBoard[59] == "0")
                    {
                        playerBoard[59] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //5, 6
                if (x == 5 && y == 6)
                {
                    if (playerBoard[68] == "0")
                    {
                        playerBoard[68] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //5, 7
                if (x == 5 && y == 7)
                {
                    if (playerBoard[77] == "0")
                    {
                        playerBoard[77] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //6, 0
                if (x == 6 && y == 0)
                {
                    if (playerBoard[15] == "0")
                    {
                        playerBoard[15] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //6, 1
                if (x == 6 && y == 1)
                {
                    if (playerBoard[24] == "0")
                    {
                        playerBoard[24] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //6, 2
                if (x == 6 && y == 2)
                {
                    if (playerBoard[33] == "0")
                    {
                        playerBoard[33] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //6, 3
                if (x == 6 && y == 3)
                {
                    if (playerBoard[42] == "0")
                    {
                        playerBoard[42] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //6, 4
                if (x == 6 && y == 4)
                {
                    if (playerBoard[51] == "0")
                    {
                        playerBoard[51] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //6, 5
                if (x == 6 && y == 5)
                {
                    if (playerBoard[60] == "0")
                    {
                        playerBoard[60] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //6,6
                if (x == 6 && y == 6)
                {
                    if (playerBoard[69] == "0")
                    {
                        playerBoard[69] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //6, 7
                if (x == 6 && y == 7)
                {
                    if (playerBoard[78] == "0")
                    {
                        playerBoard[78] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //7, 0
                if (x == 7 && y == 0)
                {
                    if (playerBoard[16] == "0")
                    {
                        playerBoard[16] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //7, 1
                if (x == 7 && y == 1)
                {
                    if (playerBoard[25] == "0")
                    {
                        playerBoard[25] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //7, 2
                if (x == 7 && y == 2)
                {
                    if (playerBoard[34] == "0")
                    {
                        playerBoard[34] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //7, 3
                if (x == 7 && y == 3)
                {
                    if (playerBoard[43] == "0")
                    {
                        playerBoard[43] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //7, 4
                if (x == 7 && y == 4)
                {
                    if (playerBoard[52] == "0")
                    {
                        playerBoard[52] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //7, 5
                if (x == 7 && y == 5)
                {
                    if (playerBoard[61] == "0")
                    {
                        playerBoard[61] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //7, 6
                if (x == 7 && y == 6)
                {
                    if (playerBoard[70] == "0")
                    {
                        playerBoard[70] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }

                //7, 7
                if (x == 7 && y == 7)
                {
                    if (playerBoard[79] == "0")
                    {
                        playerBoard[79] = "*";
                        totalShipsOnBoard++;

                        std::cout << "\n\n" << playerName << " Board:\n";
                        for (int i = 0; i < playerBoard.size(); i++)
                        {
                            std::cout << playerBoard[i] << " ";

                            if ((i + 2) % 9 == 0)
                            {
                                std::cout << std::endl;
                            }
                        }

                        std::cout << "\n\n" << playerName << " you currently have " << totalShipsOnBoard << " out of " << totalShips << " ships on your board.\n";
                    }
                    else
                    {
                        std::cout << "Sorry it seems like this position is already taken, try again.\n";
                    }

                }


            }

        }

    }




    //Have turns repeat until there are no more ships on either Phil's or the Players board
    while (totalShipsOnBoard  > 0 || totalShipsPhil > 0)
    {
        //for (int i = 0; i < totalShips; i++)
        //{
             
        //}

        //Phil goes first
        //random guess of the coordinates 
        int xCoordinate = rand() % (7 - 0 + 1) + 0;
        int yCoordinate = rand() % (7 - 0 + 1) + 0;

        std::cout << "Phil guessed: " << xCoordinate << ", " << yCoordinate << "\n";

        //0,0
        if (xCoordinate == 0 && yCoordinate == 0)
        {
            if (playerBoard[9] == "H" || "M")
            {
                std::cout << endValue[1] << "\n" ;
            }
            
            if (playerBoard[9] == "0")
            {
                if (playerBoard[10] == "*" || playerBoard[18] == "*")
                {
                    playerBoard[9] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }

            if (playerBoard[9] == "*")
            {
                playerBoard[9] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }
            
        }

        //0, 1
        if (xCoordinate == 0 && yCoordinate == 1)
        {
            if (playerBoard[18] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[18] == "0")
            {
                if (playerBoard[9] == "*" || playerBoard[19] == "*" || playerBoard[27] == "*")
                {
                    playerBoard[18] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[18] == "*")
            {
                playerBoard[18] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 2
        if (xCoordinate == 0 && yCoordinate == 2)
        {
            if (playerBoard[27] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[27] == "0")
            {
                if (playerBoard[18] == "*" || playerBoard[28] == "*" || playerBoard[26] == "*")
                {
                    playerBoard[27] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[27] == "*")
            {
                playerBoard[27] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 3
        if (xCoordinate == 0 && yCoordinate == 3)
        {
            if (playerBoard[36] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[36] == "0")
            {
                if (playerBoard[27] == "*" || playerBoard[37] == "*" || playerBoard[45] == "*")
                {
                    playerBoard[36] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[36] == "*")
            {
                playerBoard[36] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 4
        if (xCoordinate == 0 && yCoordinate == 4)
        {
            if (playerBoard[45] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[45] == "0")
            {
                if (playerBoard[36] == "*" || playerBoard[46] == "*" || playerBoard[54] == "*")
                {
                    playerBoard[45] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[45] == "*")
            {
                playerBoard[45] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 5
        if (xCoordinate == 0 && yCoordinate == 5)
        {
            if (playerBoard[54] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[54] == "0")
            {
                if (playerBoard[45] == "*" || playerBoard[55] == "*" || playerBoard[63] == "*")
                {
                    playerBoard[54] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[54] == "*")
            {
                playerBoard[54] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 6
        if (xCoordinate == 0 && yCoordinate == 6)
        {
            if (playerBoard[63] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[63] == "0")
            {
                if (playerBoard[54] == "*" || playerBoard[64] == "*" || playerBoard[72] == "*")
                {
                    playerBoard[63] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[63] == "*")
            {
                playerBoard[63] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 7
        if (xCoordinate == 0 && yCoordinate == 7)
        {
            if (playerBoard[72] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[72] == "0")
            {
                if (playerBoard[63] == "*" || playerBoard[73] == "*")
                {
                    playerBoard[72] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[72] == "*")
            {
                playerBoard[72] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 0
        if (xCoordinate == 1 && yCoordinate == 0)
        {
            if (playerBoard[10] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[10] == "0")
            {
                if (playerBoard[9] == "*" || playerBoard[11] == "*" || playerBoard[19] == "*")
                {
                    playerBoard[10] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[10] == "*")
            {
                playerBoard[10] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 1
        if (xCoordinate == 1 && yCoordinate == 1)
        {
            if (playerBoard[19] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[19] == "0")
            {
                if (playerBoard[10] == "*" || playerBoard[18] == "*" || playerBoard[20] == "*" || playerBoard[28] == "*")
                {
                    playerBoard[19] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[19] == "*")
            {
                playerBoard[19] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 2
        if (xCoordinate == 1 && yCoordinate == 2)
        {
            if (playerBoard[28] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[28] == "0")
            {
                if (playerBoard[19] == "*" || playerBoard[27] == "*" || playerBoard[29] == "*" || playerBoard[37] == "*")
                {
                    playerBoard[28] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[28] == "*")
            {
                playerBoard[28] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 3
        if (xCoordinate == 1 && yCoordinate == 3)
        {
            if (playerBoard[37] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[37] == "0")
            {
                if (playerBoard[28] == "*" || playerBoard[36] == "*" || playerBoard[38] == "*" || playerBoard[46] == "*")
                {
                    playerBoard[37] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[37] == "*")
            {
                playerBoard[37] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 4
        if (xCoordinate == 1 && yCoordinate == 4)
        {
            if (playerBoard[46] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[46] == "0")
            {
                if (playerBoard[37] == "*" || playerBoard[45] == "*" || playerBoard[47] == "*" || playerBoard[55] == "*")
                {
                    playerBoard[46] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[46] == "*")
            {
                playerBoard[46] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 5
        if (xCoordinate == 1 && yCoordinate == 5)
        {
            if (playerBoard[55] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[55] == "0")
            {
                if (playerBoard[46] == "*" || playerBoard[54] == "*" || playerBoard[55] == "*" || playerBoard[64] == "*")
                {
                    playerBoard[55] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[55] == "*")
            {
                playerBoard[55] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 6
        if (xCoordinate == 1 && yCoordinate == 6)
        {
            if (playerBoard[64] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[64] == "0")
            {
                if (playerBoard[55] == "*" || playerBoard[63] == "*" || playerBoard[65] == "*" || playerBoard[73] == "*")
                {
                    playerBoard[64] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[64] == "*")
            {
                playerBoard[64] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 7
        if (xCoordinate == 1 && yCoordinate == 7)
        {
            if (playerBoard[73] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[73] == "0")
            {
                if (playerBoard[64] == "*" || playerBoard[72] == "*" || playerBoard[74] == "*")
                {
                    playerBoard[73] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[73] == "*")
            {
                playerBoard[73] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 0
        if (xCoordinate == 2 && yCoordinate == 0)
        {

            if (playerBoard[11] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[11] == "0")
            {
                if (playerBoard[10] == "*" || playerBoard[20] == "*" || playerBoard[12] == "*")
                {
                    playerBoard[11] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[11] == "*")
            {
                playerBoard[11] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 1
        if (xCoordinate == 2 && yCoordinate == 1)
        {
            if (playerBoard[20] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[20] == "0")
            {
                if (playerBoard[11] == "*" || playerBoard[19] == "*" || playerBoard[21] == "*" || playerBoard[29] == "*")
                {
                    playerBoard[20] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[20] == "*")
            {
                playerBoard[20] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 2
        if (xCoordinate == 2 && yCoordinate == 2)
        {
            if (playerBoard[29] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[29] == "0")
            {
                if (playerBoard[20] == "*" || playerBoard[28] == "*" || playerBoard[30] == "*" || playerBoard[38] == "*")
                {
                    playerBoard[29] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[29] == "*")
            {
                playerBoard[29] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 3
        if (xCoordinate == 2 && yCoordinate == 3)
        {
            if (playerBoard[38] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[38] == "0")
            {
                if (playerBoard[29] == "*" || playerBoard[37] == "*" || playerBoard[39] == "*" || playerBoard[47] == "*")
                {
                    playerBoard[38] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[38] == "*")
            {
                playerBoard[38] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 4
        if (xCoordinate == 2 && yCoordinate == 4)
        {
            if (playerBoard[47] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[47] == "0")
            {
                if (playerBoard[38] == "*" || playerBoard[46] == "*" || playerBoard[48] == "*" || playerBoard[56] == "*")
                {
                    playerBoard[47] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[47] == "*")
            {
                playerBoard[47] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 5
        if (xCoordinate == 2 && yCoordinate == 5)
        {
            if (playerBoard[56] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[56] == "0")
            {
                if (playerBoard[47] == "*" || playerBoard[55] == "*" || playerBoard[57] == "*" || playerBoard[65] == "*")
                {
                    playerBoard[56] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[56] == "*")
            {
                playerBoard[56] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 6
        if (xCoordinate == 2 && yCoordinate == 6)
        {
            if (playerBoard[65] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[65] == "0")
            {
                if (playerBoard[56] == "*" || playerBoard[64] == "*" || playerBoard[66] == "*" || playerBoard[74] == "*")
                {
                    playerBoard[65] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[65] == "*")
            {
                playerBoard[65] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }
        
        //2, 7
        if (xCoordinate == 2 && yCoordinate == 7)
        {
            if (playerBoard[74] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[74] == "0")
            {
                if (playerBoard[65] == "*" || playerBoard[73] == "*" || playerBoard[75] == "*")
                {
                    playerBoard[74] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[74] == "*")
            {
                playerBoard[74] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 0
        if (xCoordinate == 3 && yCoordinate == 0)
        {
            if (playerBoard[12] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[12] == "0")
            {
                if (playerBoard[11] == "*" || playerBoard[21] == "*" || playerBoard[13] == "*")
                {
                    playerBoard[12] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[12] == "*")
            {
                playerBoard[12] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 1
        if (xCoordinate == 3 && yCoordinate == 1)
        {
            if (playerBoard[21] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[21] == "0")
            {
                if (playerBoard[12] == "*" || playerBoard[20] == "*" || playerBoard[22] == "*" || playerBoard[30] == "*")
                {
                    playerBoard[21] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[21] == "*")
            {
                playerBoard[21] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 2
        if (xCoordinate == 3 && yCoordinate == 2)
        {
            if (playerBoard[30] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[30] == "0")
            {
                if (playerBoard[21] == "*" || playerBoard[29] == "*" || playerBoard[31] == "*" || playerBoard[39] == "*")
                {
                    playerBoard[30] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[30] == "*")
            {
                playerBoard[30] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 3
        if (xCoordinate == 3 && yCoordinate == 3)
        {
            if (playerBoard[39] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[39] == "0")
            {
                if (playerBoard[30] == "*" || playerBoard[38] == "*" || playerBoard[40] == "*" || playerBoard[48] == "*")
                {
                    playerBoard[39] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[39] == "*")
            {
                playerBoard[39] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 4
        if (xCoordinate == 3 && yCoordinate == 4)
        {
            if (playerBoard[48] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[48] == "0")
            {
                if (playerBoard[39] == "*" || playerBoard[47] == "*" || playerBoard[49] == "*" || playerBoard[57] == "*")
                {
                    playerBoard[48] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[48] == "*")
            {
                playerBoard[48] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 5
        if(xCoordinate == 3 && yCoordinate == 5)
        {
            if (playerBoard[57] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[57] == "0")
            {
                if (playerBoard[48] == "*" || playerBoard[56] == "*" || playerBoard[58] == "*" || playerBoard[66] == "*")
                {
                    playerBoard[57] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[57] == "*")
            {
                playerBoard[57] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 6
        if (xCoordinate == 3 && yCoordinate == 6)
        {
            if (playerBoard[66] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[66] == "0")
            {
                if (playerBoard[57] == "*" || playerBoard[65] == "*" || playerBoard[67] == "*" || playerBoard[75] == "*")
                {
                    playerBoard[66] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[66] == "*")
            {
                playerBoard[66] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 7 
        if (xCoordinate == 3 && yCoordinate == 7)
        {
            if (playerBoard[75] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[75] == "0")
            {
                if (playerBoard[66] == "*" || playerBoard[74] == "*" || playerBoard[76] == "*")
                {
                    playerBoard[75] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[75] == "*")
            {
                playerBoard[75] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 0
        if (xCoordinate == 4 && yCoordinate == 0)
        {
            if (playerBoard[13] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[13] == "0")
            {
                if (playerBoard[12] == "*" || playerBoard[22] == "*" || playerBoard[14] == "*")
                {
                    playerBoard[13] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[13] == "*")
            {
                playerBoard[13] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 1
        if (xCoordinate == 4 && yCoordinate == 1)
        {
            if (playerBoard[22] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[22] == "0")
            {
                if (playerBoard[13] == "*" || playerBoard[21] == "*" || playerBoard[23] == "*" || playerBoard[31] == "*")
                {
                    playerBoard[22] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[22] == "*")
            {
                playerBoard[22] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 2
        if (xCoordinate == 4 && yCoordinate == 2)
        {
            if (playerBoard[31] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[31] == "0")
            {
                if (playerBoard[22] == "*" || playerBoard[30] == "*" || playerBoard[32] == "*" || playerBoard[40] == "*")
                {
                    playerBoard[31] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[31] == "*")
            {
                playerBoard[31] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 3
        if (xCoordinate == 4 && yCoordinate == 3)
        {
            if (playerBoard[40] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[40] == "0")
            {
                if (playerBoard[31] == "*" || playerBoard[39] == "*" || playerBoard[41] == "*" || playerBoard[49] == "*")
                {
                    playerBoard[40] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[40] == "*")
            {
                playerBoard[40] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 4
        if (xCoordinate == 4 && yCoordinate == 4)
        {
            if (playerBoard[49] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[49] == "0")
            {
                if (playerBoard[40] == "*" || playerBoard[48] == "*" || playerBoard[50] == "*" || playerBoard[58] == "*")
                {
                    playerBoard[49] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[49] == "*")
            {
                playerBoard[49] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 5
        if (xCoordinate == 4 && yCoordinate == 5)
        {
            if (playerBoard[58] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[58] == "0")
            {
                if (playerBoard[49] == "*" || playerBoard[57] == "*" || playerBoard[59] == "*" || playerBoard[67] == "*")
                {
                    playerBoard[58] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[58] == "*")
            {
                playerBoard[58] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 6
        if (xCoordinate == 4 && yCoordinate == 6)
        {
            if (playerBoard[67] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[67] == "0")
            {
                if (playerBoard[58] == "*" || playerBoard[66] == "*" || playerBoard[68] == "*" || playerBoard[76] == "*")
                {
                    playerBoard[67] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[67] == "*")
            {
                playerBoard[67] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 7
        if (xCoordinate == 4 && yCoordinate == 7)
        {
            if (playerBoard[76] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[76] == "0")
            {
                if (playerBoard[67] == "*" || playerBoard[75] == "*" || playerBoard[77] == "*")
                {
                    playerBoard[76] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[76] == "*")
            {
                playerBoard[76] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 0
        if (xCoordinate == 5 && yCoordinate == 0)
        {
            if (playerBoard[14] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[14] == "0")
            {
                if (playerBoard[13] == "*" || playerBoard[23] == "*" || playerBoard[15] == "*")
                {
                    playerBoard[14] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[14] == "*")
            {
                playerBoard[14] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 1
        if (xCoordinate == 5 && yCoordinate == 1)
        {
            if (playerBoard[23] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[23] == "0")
            {
                if (playerBoard[14] == "*" || playerBoard[22] == "*" || playerBoard[24] == "*" || playerBoard[32] == "*")
                {
                    playerBoard[23] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[23] == "*")
            {
                playerBoard[23] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 2
        if (xCoordinate == 5 && yCoordinate == 2)
        {
            if (playerBoard[32] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[32] == "0")
            {
                if (playerBoard[23] == "*" || playerBoard[31] == "*" || playerBoard[33] == "*" || playerBoard[41] == "*")
                {
                    playerBoard[32] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[32] == "*")
            {
                playerBoard[32] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 3
        if (xCoordinate == 5 && yCoordinate == 3)
        {
            if (playerBoard[41] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[41] == "0")
            {
                if (playerBoard[32] == "*" || playerBoard[40] == "*" || playerBoard[42] == "*" || playerBoard[50] == "*")
                {
                    playerBoard[41] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[41] == "*")
            {
                playerBoard[41] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 4
        if (xCoordinate == 5 && yCoordinate == 4)
        {
            if (playerBoard[50] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[50] == "0")
            {
                if (playerBoard[41] == "*" || playerBoard[49] == "*" || playerBoard[51] == "*" || playerBoard[59] == "*")
                {
                    playerBoard[50] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[50] == "*")
            {
                playerBoard[50] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 5
        if (xCoordinate == 5 && yCoordinate == 5)
        {
            if (playerBoard[59] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[59] == "0")
            {
                if (playerBoard[50] == "*" || playerBoard[58] == "*" || playerBoard[60] == "*" || playerBoard[68] == "*")
                {
                    playerBoard[59] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[59] == "*")
            {
                playerBoard[59] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 6
        if (xCoordinate == 5 && yCoordinate == 6)
        {
            if (playerBoard[68] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[68] == "0")
            {
                if (playerBoard[59] == "*" || playerBoard[67] == "*" || playerBoard[69] == "*" || playerBoard[77] == "*")
                {
                    playerBoard[68] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[68] == "*")
            {
                playerBoard[68] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 7
        if (xCoordinate == 5 && yCoordinate == 7)
        {
            if (playerBoard[77] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[77] == "0")
            {
                if (playerBoard[68] == "*" || playerBoard[76] == "*" || playerBoard[78] == "*")
                {
                    playerBoard[77] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[77] == "*")
            {
                playerBoard[77] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 0
        if (xCoordinate == 6 && yCoordinate == 0)
        {
            if (playerBoard[15] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[15] == "0")
            {
                if (playerBoard[14] == "*" || playerBoard[24] == "*" || playerBoard[16] == "*")
                {
                    playerBoard[15] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[15] == "*")
            {
                playerBoard[15] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 1
        if (xCoordinate == 6 && yCoordinate == 1)
        {
            if (playerBoard[24] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[24] == "0")
            {
                if (playerBoard[15] == "*" || playerBoard[23] == "*"|| playerBoard[25] == "*" || playerBoard[33] == "*")
                {
                    playerBoard[24] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[24] == "*")
            {
                playerBoard[24] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 2
        if (xCoordinate == 6 && yCoordinate == 2)
        {
            if (playerBoard[33] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[33] == "0")
            {
                if (playerBoard[24] == "*" || playerBoard[32] == "*" || playerBoard[34] == "*" || playerBoard[42] == "*")
                {
                    playerBoard[33] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[33] == "*")
            {
                playerBoard[33] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 3
        if (xCoordinate == 6 && yCoordinate == 3)
        {
            if (playerBoard[42] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[42] == "0")
            {
                if (playerBoard[33] == "*" || playerBoard[41] == "*" || playerBoard[43] == "*" || playerBoard[51] == "*")
                {
                    playerBoard[42] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[42] == "*")
            {
                playerBoard[42] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 4
        if (xCoordinate == 6 && yCoordinate == 4)
        {
            if (playerBoard[51] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[51] == "0")
            {
                if (playerBoard[42] == "*" || playerBoard[50] == "*" || playerBoard[52] == "*" || playerBoard[60] == "*")
                {
                    playerBoard[51] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[51] == "*")
            {
                playerBoard[51] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 5
        if (xCoordinate == 6 && yCoordinate == 5)
        {
            if (playerBoard[60] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[60] == "0")
            {
                if (playerBoard[51] == "*" || playerBoard[59] == "*" || playerBoard[61] == "*" || playerBoard[69] == "*")
                {
                    playerBoard[60] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[60] == "*")
            {
                playerBoard[60] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 6
        if (xCoordinate == 6 && yCoordinate == 6)
        {
            if (playerBoard[69] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[69] == "0")
            {
                if (playerBoard[60] == "*" || playerBoard[68] == "*" || playerBoard[70] == "*" || playerBoard[78] == "*")
                {
                    playerBoard[69] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[69] == "*")
            {
                playerBoard[69] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 7
        if (xCoordinate == 6 && yCoordinate == 7)
        {
            if (playerBoard[78] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[78] == "0")
            {
                if (playerBoard[69] == "*" || playerBoard[77] == "*" || playerBoard[79] == "*")
                {
                    playerBoard[78] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[78] == "*")
            {
                playerBoard[78] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 0
        if (xCoordinate == 7 && yCoordinate == 0)
        {
            if (playerBoard[16] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[16] == "0")
            {
                if (playerBoard[15] == "*" || playerBoard[25] == "*")
                {
                    playerBoard[16] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[16] == "*")
            {
                playerBoard[16] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 1
        if (xCoordinate == 7 && yCoordinate == 1)
        {
            if (playerBoard[25] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[25] == "0")
            {
                if (playerBoard[16] == "*" || playerBoard[24] == "*" || playerBoard[34] == "*")
                {
                    playerBoard[25] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[25] == "*")
            {
                playerBoard[25] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 2
        if (xCoordinate == 7 && yCoordinate == 2)
        {
            if (playerBoard[34] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[34] == "0")
            {
                if (playerBoard[25] == "*" || playerBoard[33] == "*" || playerBoard[43] == "*")
                {
                    playerBoard[34] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[34] == "*")
            {
                playerBoard[34] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 3
        if (xCoordinate == 7 && yCoordinate == 3)
        {
            if (playerBoard[43] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[43] == "0")
            {
                if (playerBoard[34] == "*" || playerBoard[42] == "*" || playerBoard[52] == "*")
                {
                    playerBoard[43] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[43] == "*")
            {
                playerBoard[43] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 4
        if (xCoordinate == 7 && yCoordinate == 4)
        {
            if (playerBoard[52] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[52] == "0")
            {
                if (playerBoard[43] == "*" || playerBoard[51] == "*" || playerBoard[61] == "*")
                {
                    playerBoard[52] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[52] == "*")
            {
                playerBoard[52] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 5
        if (xCoordinate == 7 && yCoordinate == 5)
        {
            if (playerBoard[61] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[61] == "0")
            {
                if (playerBoard[52] == "*" || playerBoard[60] == "*" || playerBoard[70] == "*")
                {
                    playerBoard[61] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[61] == "*")
            {
                playerBoard[61] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 6
        if (xCoordinate == 7 && yCoordinate == 6)
        {
            if (playerBoard[70] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[70] == "0")
            {
                if (playerBoard[61] == "*" || playerBoard[69] == "*" || playerBoard[79] == "*")
                {
                    playerBoard[70] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[70] == "*")
            {
                playerBoard[70] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 7
        if (xCoordinate == 7 && yCoordinate == 7)
        {
            if (playerBoard[79] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[79] == "0")
            {
                if (playerBoard[70] == "*" || playerBoard[78] == "*")
                {
                    playerBoard[79] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
             if (playerBoard[79] == "*")
            {
                playerBoard[79] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }


        //Display Players Board
        std::cout << "\n\n" << playerName << " Board:\n";
        for (int i = 0; i < playerBoard.size(); i++)
        {
            std::cout << playerBoard[i] << " ";

            if ((i + 2) % 9 == 0)
            {
                std::cout << std::endl;
            }
        }

        std::cout << "it is now your turn to guess: \n";

        std::cout << "X coordinate: \n";

        std::cin >> x;

        std::cout << "Y coordinate: \n";

        std::cin >> y;

        std::cout << playerName << " guessed " << x << ", " << y << "\n";

        //0, 0
        if (x == 0 && y == 0)
        {
            if (philBoard[9] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[9] == "0")
            {
                if (philBoard[10] == "*" || philBoard[18] == "*")
                {
                    philBoard[9] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[9] == "*")
            {
                philBoard[9] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 1
        if (x == 0 && y == 1)
        {
            if (philBoard[18] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[18] == "0")
            {
                if (philBoard[9] == "*" || philBoard[19] == "*" || philBoard[27] == "*")
                {
                    philBoard[18] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[18] == "*")
            {
                philBoard[18] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 2
        if (x == 0 && y == 2)
        {
            if (philBoard[27] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[27] == "0")
            {
                if (philBoard[18] == "*" || philBoard[28] == "*" || philBoard[26] == "*")
                {
                    philBoard[27] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[27] == "*")
            {
                philBoard[27] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 3
        if (x == 0 && y == 3)
        {
            if (philBoard[36] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[36] == "0")
            {
                if (philBoard[27] == "*" || philBoard[37] == "*" || philBoard[45] == "*")
                {
                    philBoard[36] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[36] == "*")
            {
                philBoard[36] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 4
        if (x == 0 && y == 4)
        {
            if (philBoard[45] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[45] == "0")
            {
                if (philBoard[36] == "*" || philBoard[46] == "*" || philBoard[54] == "*")
                {
                    philBoard[45] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[45] == "*")
            {
                philBoard[45] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 5
        if (x == 0 && y == 5)
        {
            if (philBoard[54] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[54] == "0")
            {
                if (philBoard[45] == "*" || philBoard[55] == "*" || philBoard[63] == "*")
                {
                    philBoard[54] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[54] == "*")
            {
                philBoard[54] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 6
        if (x == 0 && y == 6)
        {
            if (philBoard[63] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[63] == "0")
            {
                if (philBoard[54] == "*" || philBoard[64] == "*" || philBoard[72] == "*")
                {
                    philBoard[63] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[63] == "*")
            {
                philBoard[63] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //0, 7
        if (x == 0 && y == 7)
        {
            if (philBoard[72] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[72] == "0")
            {
                if (philBoard[63] == "*" || philBoard[73] == "*")
                {
                    philBoard[72] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[72] == "*")
            {
                philBoard[72] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 0
        if (x == 1 && y == 0)
        {
            if (philBoard[10] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[10] == "0")
            {
                if (philBoard[9] == "*" || philBoard[11] == "*" || philBoard[19] == "*")
                {
                    philBoard[10] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[10] == "*")
            {
                philBoard[10] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 1
        if (x == 1 && y == 1)
        {
            if (philBoard[19] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[19] == "0")
            {
                if (philBoard[10] == "*" || philBoard[18] == "*" || philBoard[20] == "*" || philBoard[28] == "*")
                {
                    philBoard[19] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[19] == "*")
            {
                philBoard[19] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 2
        if (x == 1 && y == 2)
        {
            if (philBoard[28] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[28] == "0")
            {
                if (philBoard[19] == "*" || philBoard[27] == "*" || philBoard[29] == "*" || philBoard[37] == "*")
                {
                    philBoard[28] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[28] == "*")
            {
                philBoard[28] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 3
        if (x == 1 && y == 3)
        {
            if (philBoard[37] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[37] == "0")
            {
                if (philBoard[28] == "*" || philBoard[36] == "*" || philBoard[38] == "*" || philBoard[46] == "*")
                {
                    philBoard[37] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[37] == "*")
            {
                philBoard[37] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 4
        if (x == 1 && y == 4)
        {
            if (philBoard[46] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[46] == "0")
            {
                if (philBoard[37] == "*" || philBoard[45] == "*" || philBoard[47] == "*" || philBoard[55] == "*")
                {
                    philBoard[46] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[46] == "*")
            {
                philBoard[46] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 5
        if (x == 1 && y == 5)
        {
            if (philBoard[55] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[55] == "0")
            {
                if (philBoard[46] == "*" || philBoard[54] == "*" || philBoard[55] == "*" || philBoard[64] == "*")
                {
                    philBoard[55] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[55] == "*")
            {
                philBoard[55] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 6
        if (x == 1 && y == 6)
        {
            if (philBoard[64] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[64] == "0")
            {
                if (philBoard[55] == "*" || philBoard[63] == "*" || philBoard[65] == "*" || philBoard[73] == "*")
                {
                    philBoard[64] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[64] == "*")
            {
                philBoard[64] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //1, 7
        if (x == 1 && y == 7)
        {
            if (philBoard[73] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[73] == "0")
            {
                if (philBoard[64] == "*" || philBoard[72] == "*" || philBoard[74] == "*")
                {
                    philBoard[73] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[73] == "*")
            {
                philBoard[73] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 0
        if (x == 2 && y == 0)
        {
            if (philBoard[11] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[11] == "0")
            {
                if (philBoard[10] == "*" || philBoard[20] == "*" || philBoard[12] == "*")
                {
                    philBoard[11] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[11] == "*")
            {
                philBoard[11] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 1
        if (x == 2 && y == 1)
        {
            if (philBoard[20] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[20] == "0")
            {
                if (philBoard[11] == "*" || philBoard[19] == "*" || philBoard[21] == "*" || philBoard[29] == "*")
                {
                    philBoard[20] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[20] == "*")
            {
                philBoard[20] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 2
        if (x == 2 && y == 2)
        {
            if (philBoard[29] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[29] == "0")
            {
                if (philBoard[20] == "*" || philBoard[28] == "*" || philBoard[30] == "*" || philBoard[38] == "*")
                {
                    philBoard[29] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[29] == "*")
            {
                philBoard[29] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 3
        if (x == 2 && y == 3)
        {
            if (philBoard[38] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[38] == "0")
            {
                if (philBoard[29] == "*" || philBoard[37] == "*" || philBoard[39] == "*" || philBoard[47] == "*")
                {
                    philBoard[38] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[38] == "*")
            {
                philBoard[38] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 4
        if (x == 2 && y == 4)
        {
            if (philBoard[47] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[47] == "0")
            {
                if (philBoard[38] == "*" || philBoard[46] == "*" || philBoard[48] == "*" || philBoard[56] == "*")
                {
                    philBoard[47] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[47] == "*")
            {
                philBoard[47] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 5
        if (x == 2 && y == 5)
        {
            if (philBoard[56] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[56] == "0")
            {
                if (philBoard[47] == "*" || philBoard[55] == "*" || philBoard[57] == "*" || philBoard[65] == "*")
                {
                    philBoard[56] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[56] == "*")
            {
                philBoard[56] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 6
        if (x == 2 && y == 6)
        {
            if (philBoard[65] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[65] == "0")
            {
                if (philBoard[56] == "*" || philBoard[64] == "*" || philBoard[66] == "*" || philBoard[74] == "*")
                {
                    philBoard[65] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[65] == "*")
            {
                philBoard[65] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //2, 7
        if (x == 2 && y == 7)
        {
            if (philBoard[74] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[74] == "0")
            {
                if (philBoard[65] == "*" || philBoard[73] == "*" || philBoard[75] == "*")
                {
                    philBoard[74] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[74] == "*")
            {
                philBoard[74] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 0
        if (x == 3 && y == 0)
        {
            if (philBoard[12] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[12] == "0")
            {
                if (philBoard[11] == "*" || philBoard[21] == "*" || philBoard[13] == "*")
                {
                    philBoard[12] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[12] == "*")
            {
                philBoard[12] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 1
        if (x == 3 && y == 1)
        {
            if (philBoard[21] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[21] == "0")
            {
                if (philBoard[12] == "*" || philBoard[20] == "*" || philBoard[22] == "*" || philBoard[30] == "*")
                {
                    philBoard[21] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[21] == "*")
            {
                philBoard[21] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 2
        if (x == 3 && y == 2)
        {
            if (philBoard[30] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[30] == "0")
            {
                if (philBoard[21] == "*" || philBoard[29] == "*" || philBoard[31] == "*" || philBoard[39] == "*")
                {
                    philBoard[30] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[30] == "*")
            {
                philBoard[30] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 3
        if (x == 3 && y == 3)
        {
            if (philBoard[39] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[39] == "0")
            {
                if (philBoard[30] == "*" || philBoard[38] == "*" || philBoard[40] == "*" || philBoard[48] == "*")
                {
                    philBoard[39] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[39] == "*")
            {
                philBoard[39] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 4
        if (x == 3 && y == 4)
        {
            if (philBoard[48] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[48] == "0")
            {
                if (philBoard[39] == "*" || philBoard[47] == "*" || philBoard[49] == "*" || philBoard[57] == "*")
                {
                    philBoard[48] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[48] == "*")
            {
                philBoard[48] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 5
        if (x == 3 && y == 5)
        {
            if (philBoard[57] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[57] == "0")
            {
                if (philBoard[48] == "*" || philBoard[56] == "*" || philBoard[58] == "*" || philBoard[66] == "*")
                {
                    philBoard[57] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[57] == "*")
            {
                philBoard[57] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 6
        if (x == 3 && y == 6)
        {
            if (philBoard[66] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[66] == "0")
            {
                if (philBoard[57] == "*" || philBoard[65] == "*" || philBoard[67] == "*" || philBoard[75] == "*")
                {
                    philBoard[66] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[66] == "*")
            {
                philBoard[66] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //3, 7 
        if (x == 3 && y == 7)
        {
            if (philBoard[75] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[75] == "0")
            {
                if (philBoard[66] == "*" || philBoard[74] == "*" || philBoard[76] == "*")
                {
                    philBoard[75] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[75] == "*")
            {
                philBoard[75] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 0
        if (x == 4 && y == 0)
        {
            if (philBoard[13] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[13] == "0")
            {
                if (philBoard[12] == "*" || philBoard[22] == "*" || philBoard[14] == "*")
                {
                    philBoard[13] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[13] == "*")
            {
                philBoard[13] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 1
        if (x == 4 && y == 1)
        {
            if (philBoard[22] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[22] == "0")
            {
                if (philBoard[13] == "*" || philBoard[21] == "*" || philBoard[23] == "*" || philBoard[31] == "*")
                {
                    philBoard[22] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[22] == "*")
            {
                philBoard[22] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 2
        if (x == 4 && y == 2)
        {
            if (philBoard[31] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[31] == "0")
            {
                if (philBoard[22] == "*" || philBoard[30] == "*" || philBoard[32] == "*" || philBoard[40] == "*")
                {
                    philBoard[31] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[31] == "*")
            {
                philBoard[31] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 3
        if (x == 4 && y == 3)
        {
            if (philBoard[40] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[40] == "0")
            {
                if (philBoard[31] == "*" || philBoard[39] == "*" || philBoard[41] == "*" || philBoard[49] == "*")
                {
                    philBoard[40] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[40] == "*")
            {
                philBoard[40] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 4
        if (x == 4 && y == 4)
        {
            if (philBoard[49] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[49] == "0")
            {
                if (philBoard[40] == "*" || philBoard[48] == "*" || philBoard[50] == "*" || philBoard[58] == "*")
                {
                    philBoard[49] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[49] == "*")
            {
                philBoard[49] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 5
        if (x == 4 && y == 5)
        {
            if (philBoard[58] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[58] == "0")
            {
                if (philBoard[49] == "*" || philBoard[57] == "*" || philBoard[59] == "*" || philBoard[67] == "*")
                {
                    philBoard[58] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[58] == "*")
            {
                philBoard[58] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 6
        if (x == 4 && y == 6)
        {
            if (philBoard[67] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[67] == "0")
            {
                if (philBoard[58] == "*" || philBoard[66] == "*" || philBoard[68] == "*" || philBoard[76] == "*")
                {
                    philBoard[67] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[67] == "*")
            {
                philBoard[67] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //4, 7
        if (x == 4 && y == 7)
        {
            if (playerBoard[76] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[76] == "0")
            {
                if (philBoard[67] == "*" || philBoard[75] == "*" || philBoard[77] == "*")
                {
                    philBoard[76] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[76] == "*")
            {
                philBoard[76] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 0
        if (x == 5 && y == 0)
        {
            if (philBoard[14] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[14] == "0")
            {
                if (philBoard[13] == "*" || philBoard[23] == "*" || philBoard[15] == "*")
                {
                    philBoard[14] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[14] == "*")
            {
                philBoard[14] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 1
        if (x == 5 && y == 1)
        {
            if (philBoard[23] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[23] == "0")
            {
                if (philBoard[14] == "*" || philBoard[22] == "*" || philBoard[24] == "*" || philBoard[32] == "*")
                {
                    philBoard[23] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[23] == "*")
            {
                philBoard[23] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 2
        if (x == 5 && y == 2)
        {
            if (philBoard[32] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[32] == "0")
            {
                if (philBoard[23] == "*" || philBoard[31] == "*" || philBoard[33] == "*" || philBoard[41] == "*")
                {
                    philBoard[32] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[32] == "*")
            {
                philBoard[32] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 3
        if (x == 5 && y == 3)
        {
            if (philBoard[41] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[41] == "0")
            {
                if (philBoard[32] == "*" || philBoard[40] == "*" || philBoard[42] == "*" || philBoard[50] == "*")
                {
                    philBoard[41] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[41] == "*")
            {
                philBoard[41] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 4
        if (x == 5 && y == 4)
        {
            if (philBoard[50] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[50] == "0")
            {
                if (philBoard[41] == "*" || philBoard[49] == "*" || philBoard[51] == "*" || philBoard[59] == "*")
                {
                    philBoard[50] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[50] == "*")
            {
                philBoard[50] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 5
        if (x == 5 && y == 5)
        {
            if (philBoard[59] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[59] == "0")
            {
                if (philBoard[50] == "*" || philBoard[58] == "*" || philBoard[60] == "*" || philBoard[68] == "*")
                {
                    philBoard[59] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[59] == "*")
            {
                philBoard[59] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 6
        if (x == 5 && y == 6)
        {
            if (philBoard[68] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[68] == "0")
            {
                if (philBoard[59] == "*" || philBoard[67] == "*" || philBoard[69] == "*" || philBoard[77] == "*")
                {
                    philBoard[68] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[68] == "*")
            {
                philBoard[68] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //5, 7
        if (x == 5 && y == 7)
        {
            if (playerBoard[77] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (playerBoard[77] == "0")
            {
                if (playerBoard[68] == "*" || playerBoard[76] == "*" || playerBoard[78] == "*")
                {
                    playerBoard[77] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (playerBoard[77] == "*")
            {
                playerBoard[77] = "H";
                totalShipsOnBoard--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 0
        if (x == 6 && y == 0)
        {
            if (philBoard[15] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[15] == "0")
            {
                if (philBoard[14] == "*" || philBoard[24] == "*" || philBoard[16] == "*")
                {
                    philBoard[15] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[15] == "*")
            {
                philBoard[15] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 1
        if (x == 6 && y == 1)
        {
            if (philBoard[24] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[24] == "0")
            {
                if (philBoard[15] == "*" || philBoard[23] == "*" || philBoard[25] == "*" || philBoard[33] == "*")
                {
                    philBoard[24] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[24] == "*")
            {
                philBoard[24] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 2
        if (x == 6 && y == 2)
        {
            if (philBoard[33] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[33] == "0")
            {
                if (philBoard[24] == "*" || philBoard[32] == "*" || philBoard[34] == "*" || philBoard[42] == "*")
                {
                    philBoard[33] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[33] == "*")
            {
                philBoard[33] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 3
        if (x == 6 && y == 3)
        {
            if (philBoard[42] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[42] == "0")
            {
                if (philBoard[33] == "*" || philBoard[41] == "*" || philBoard[43] == "*" || philBoard[51] == "*")
                {
                    philBoard[42] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[42] == "*")
            {
                philBoard[42] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 4
        if (x == 6 && y == 4)
        {
            if (philBoard[51] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[51] == "0")
            {
                if (philBoard[42] == "*" || philBoard[50] == "*" || philBoard[52] == "*" || philBoard[60] == "*")
                {
                    philBoard[51] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[51] == "*")
            {
                philBoard[51] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 5
        if (x == 6 && y == 5)  
        {
            if (philBoard[60] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[60] == "0")
            {
                if (philBoard[51] == "*" || philBoard[59] == "*" || philBoard[61] == "*" || philBoard[69] == "*")
                {
                    philBoard[60] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[60] == "*")
            {
                philBoard[60] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 6
        if (x == 6 && y == 6)
        {
            if (philBoard[69] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[69] == "0")
            {
                if (philBoard[60] == "*" || philBoard[68] == "*" || philBoard[70] == "*" || philBoard[78] == "*")
                {
                    philBoard[69] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[69] == "*")
            {
                philBoard[69] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //6, 7
        if (x == 6 && y == 7)
        {
            if (philBoard[78] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[78] == "0")
            {
                if (philBoard[69] == "*" || philBoard[77] == "*" || philBoard[79] == "*")
                {
                    philBoard[78] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[78] == "*")
            {
                philBoard[78] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 0
        if (x == 7 && y == 0)
        {
            if (philBoard[16] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[16] == "0")
            {
                if (philBoard[15] == "*" || philBoard[25] == "*")
                {
                    philBoard[16] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[16] == "*")
            {
                philBoard[16] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 1
        if (x == 7 && y == 1)
        {
            if (philBoard[25] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[25] == "0")
            {
                if (philBoard[16] == "*" || philBoard[24] == "*" || philBoard[34] == "*")
                {
                    philBoard[25] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[25] == "*")
            {
                philBoard[25] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 2
        if (x == 7 && y == 2)
        {
            if (philBoard[34] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[34] == "0")
            {
                if (philBoard[25] == "*" || philBoard[33] == "*" || philBoard[43] == "*")
                {
                    philBoard[34] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[34] == "*")
            {
                philBoard[34] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 3
        if (x == 7 && y == 3)
        {
            if (philBoard[43] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[43] == "0")
            {
                if (philBoard[34] == "*" || philBoard[42] == "*" || philBoard[52] == "*")
                {
                    philBoard[43] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[43] == "*")
            {
                philBoard[43] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 4
        if (x == 7 && y == 4)
        {
            if (philBoard[52] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[52] == "0")
            {
                if (philBoard[43] == "*" || philBoard[51] == "*" || philBoard[61] == "*")
                {
                    philBoard[52] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[52] == "*")
            {
                philBoard[52] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 5
        if (x == 7 && y == 5)
        {
            if (philBoard[61] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[61] == "0")
            {
                if (philBoard[52] == "*" || philBoard[60] == "*" || philBoard[70] == "*")
                {
                    philBoard[61] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[61] == "*")
            {
                philBoard[61] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 6
        if (x == 7 && y == 6)
        {
            if (philBoard[70] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[70] == "0")
            {
                if (philBoard[61] == "*" || philBoard[69] == "*" || philBoard[79] == "*")
                {
                    philBoard[70] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[70] == "*")
            {
                philBoard[70] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }

        //7, 7
        if (x == 7 && y == 7)
        {
            if (philBoard[79] == "H" || "M")
            {
                std::cout << endValue[1] << "\n";
            }
            if (philBoard[79] == "0")
            {
                if (philBoard[70] == "*" || philBoard[78] == "*")
                {
                    philBoard[79] = "N";
                    std::cout << endValue[2] << "\n";
                }
            }
            if (philBoard[79] == "*")
            {
                philBoard[79] = "H";
                totalShipsPhil--;
                std::cout << endValue[0] << "\n";
            }

        }



    //Display Phil's Board
        std::cout << "Phil's Board:\n";

        for (int i = 0; i < philBoard.size(); i++)
        {
            std::cout << philBoard[i] << " ";

            if ((i + 2) % 9 == 0)
            {
                std::cout << std::endl;
            }
        }

        //Check to see if one of the players has reached 0, win message at end
        if (totalShipsOnBoard > 0 || totalShipsPhil > 0)
        {
            std::cout << "End of game/\n";

            if (totalShipsOnBoard == 0)
            {
                std::cout << "Phil Wins!";
                
            }
            else if (totalShipsPhil == 0)
            {
                std::cout << playerName << " Wins!";
            }
        }
    }



    return 0; 
    
}






