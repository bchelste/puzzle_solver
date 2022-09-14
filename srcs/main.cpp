/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:29:03 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/15 00:43:05 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include <PuzzleData.hpp>
// #include <Puzzle.hpp>

std::vector<int> genRandomPuzzle(int &size)
{
	std::cout << size << std::endl;
	std::vector<int> result = std::vector<int>();
	return (result);
}

std::vector<int> readPuzzleFromFile(std::string &filename)
{
	std::cout << filename << std::endl;
	std::vector<int> result = std::vector<int>();
	return (result);
}

PuzzleData *setPuzzleData(std::string &filename, std::string &heuristic, int &size)
{
	std::string currentHeuristic;
	std::vector<int> currentPuzzle;
	
	if ((filename.empty()) && (size > 0))
	{
		currentPuzzle = genRandomPuzzle(size);
	}
	else if (!(filename.empty()) && (size = 0))
	{
		currentPuzzle = readPuzzleFromFile(filename);
	}
	else
	{
		throw std::invalid_argument("something WRONG with creating tiles!");
	}
	
	if (!(heuristic.empty()))
		currentHeuristic = heuristic;
	currentHeuristic = "manhtn";

	PuzzleData *result = new PuzzleData(size, currentHeuristic, currentPuzzle);

	return (result);
	
}

bool checkConversion(char *src)
{
	for (int i = 0; src[i] != '\0'; ++i)
	{
		if (!isdigit(src[i]))
			return (false);
	}
	return (true);
}

PuzzleData *cmdParser(int argc, char **argv)
{
	if (argc < 2)
		throw std::invalid_argument("very few options were given!");
	std::string filename = "";
	std::string heuristic = "";
	int puzzleSize = 0;

	for (int i = 1; i < argc; ++i)
	{
		std::string tmp = std::string(argv[i]);
		if (tmp == "-h")
		{
			i += 1;
			if (i < argc)
			{
				if (!(heuristic.empty()))
				{
					throw std::invalid_argument("only  ONE HEURISTIC type should be given!");
				}
				std::string res = std::string(argv[i]);
				if ((res == "manhtn") || (res == "euclid") || (res == "hamm"))
				{
					heuristic = res;
				}
				else
				{
					throw std::invalid_argument("the WRONG HEURISTIC type was given!");
				}
				
			}
		}
		else if (tmp == "-n")
		{
			if (puzzleSize != 0)
			{
				throw std::invalid_argument("something WRONG  with the puzzle size param!");
			}
			i += 1;
			if (i < argc)
			{
				if (!checkConversion(argv[i]))
				{
					throw std::invalid_argument("puzzle size should be a DIGIT !");
				}
				puzzleSize = std::stoi(std::string(argv[i]));
				if (puzzleSize <= 0)
				{
					throw std::invalid_argument("puzzle size should be the positive number!");
				}
			}
		}
		else 
		{
			if (filename.empty())
			{
				filename = tmp;
			}
			else
			{
				throw std::invalid_argument("only ONE PUZZLE file should be given!");
			}
		}
	}

	std::cout << "---" << std::endl;
	std::cout << filename << std::endl;
	std::cout << heuristic << std::endl;
	std::cout << puzzleSize << std::endl;

	return (setPuzzleData(filename, heuristic, puzzleSize));
	
}

int main(int argc, char **argv)
{
	PuzzleData *puzzle;
	try
	{
		puzzle = cmdParser(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}

	// std::cout << puzzle << std::endl;
	
}