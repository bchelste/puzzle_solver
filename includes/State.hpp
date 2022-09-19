/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   State.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:50:15 by bchelste          #+#    #+#             */
/*   Updated: 2022/09/19 22:12:48 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

struct State
{
		std::map<int, int>		state;

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
		int firstValue = 0;
		int secondValue = 0;

		if (search == "greedy")
		{
			firstValue = first->g;
			secondValue = second->g;
		}
		else if (search == "uniform")
		{
			firstValue = first->h;
			secondValue = second->h;
		}
		else // default
		{
			firstValue = first->f;
			secondValue = second->f;
		}

		return (firstValue > secondValue);
	}
	
};

