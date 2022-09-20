/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   State.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:50:15 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/20 21:56:18 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

struct State
{
		std::map<int, int>		state;
		std::map<int, int>		reverse;

		int						f;
		int						g;
		int						h;

		State					*father;
		int						movedTile;
	
};

struct HashState
{
	size_t operator() (State *state) const
	{
		return (std::hash<State*>()(state));
	}
};

struct HashStateCompare
{
	bool operator()(State *first, State *second) const
	{
		unsigned long i = 0;
		for(; i < first->state.size(); ++i)
		{
			if (first->state.at(i) != second->state.at(i))
			{
				return (false);
			}
		}
		return (true);
	}
};

struct CompareStates
{
	
	std::string		search;

	CompareStates() : search("default") {};
	CompareStates(std::string initS) : search(initS) {}
	
	bool 			operator()(State *first, State *second)
	{
		// int firstGValue = 0;
		// int secondGValue = 0;

		// int firstHValue = 0;
		// int secondHValue = 0;

		if (search == "uniform")
		{
			return (first->g > second->g);
		}
		else if (search == "greedy")
		{
			return (first->h > second->h);
		}
		else // default
		{
			if (first->g == second->g)
				return (first->h > second->h);
			else
				return (first->g > second->g);
		}

		return (false);
	}
	
};

