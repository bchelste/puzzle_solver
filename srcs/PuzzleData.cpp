/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PuzzleData.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:04:39 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/15 00:41:32 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PuzzleData.hpp"

PuzzleData::PuzzleData(int &size, std::string &newHeuristic, std::vector<int> &newTiles) : puzzleSize(size), heuristic(newHeuristic), tiles(newTiles)
{

}