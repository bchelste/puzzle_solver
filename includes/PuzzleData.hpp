/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleData.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:04:35 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/17 19:14:32 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>
#include <iostream>

class PuzzleData 
{
	public:
		
		PuzzleData();
		PuzzleData(int &newSize,  std::vector<int> &newTiles);
		virtual ~PuzzleData();

		// std::pair<int, int>		findTile(int &tile);
		// void					swapTiles(std::pair<int, int> &p1, std::pair<int, int> &p2);

		int						getPuzzleSize() const;
		std::vector<int>		getTiles() const;

	private:
	
		int						puzzleSize;
		std::vector<int>		tiles;

};

std::ostream& operator<<(std::ostream &stream, const PuzzleData &puzzle);