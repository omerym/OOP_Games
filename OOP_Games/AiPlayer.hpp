#ifndef AIPLAYER
#define AIPLAYER
#include "BoardGame_Classes.hpp"
#include "Position.hpp"
#include <utility>
#include <iostream>
#include <vector>
template <typename T>
class AiPlayer : public Player
{
	unsigned int max_depth;
	T* board;
	int compare_result(Result r1, Result r2, bool maximise)
	{
		int result = 0;
		if (r1.score != r2.score)
		{
			result = r1.score > r2.score ? 1 : -1;
		}
		// if two moves have similar score
		else if (r1.depth != r2.depth)
		{
			// if score is positive(winning) least depth is better
			// if score is negative(losing) most depth is better
			result = r1.depth < r2.depth ? 1 : -1;
			result = r1.score > 0 ? result : -result;
		}
		// if minimising invert result
		return maximise ? result : -result;
	}
	Result evaluate(T board, bool maximise, unsigned int depth, Result alpha, Result beta, int& comp)
	{
		if (depth <= 0 || board.game_is_over())
		{
			return { board.evaluate(), depth };
		}
		comp++;
		vector<T> moves;
		board.generate_moves(moves);
		int result;
		result = maximise ? -INT_MAX : INT_MAX;
		for (auto move : moves)
		{
			int s = evaluate(move, !maximise, depth - 1, alpha, beta, comp);
			if (maximise)
			{
				result = s > result ? s : result;
				alpha = result > alpha ? result : alpha;
			}
			else
			{
				result = s < result ? s : result;
				beta = s < beta ? result : beta;
			}
			if (beta <= alpha)
			{
				break;
			}
		}
		return result;
	}
public:
	bool is_maximiser()
	{
		return symbol == 'x';
	}
	// Take a symbol and pass it to parent
	AiPlayer(char symbol, T* board, unsigned int max_depth) : Player(symbol), max_depth(max_depth), board(board)
	{
		name = "AI Player: ";
		name += symbol;
	}

	void get_move(int& x, int& y)
	{
		vector<pair<T, Position>> moves;
		board->generate_moves(moves);
		int result;
		result = is_maximiser() ? -INT_MAX : INT_MAX;
		int comp = 0;
		int alpha = -INT_MAX;
		int beta = INT_MAX;
		for (int i = 0; i < moves.size(); i++)
		{
			int r = evaluate(moves[i].first, is_maximiser(), max_depth, alpha, beta, comp);
			if (is_maximiser())
			{
				if (r > result)
				{
					result = r;
					alpha = result > alpha ? result : alpha;
					x = moves[i].second.x;
					y = moves[i].second.y;
				}
			}
			else
			{
				if (r < result)
				{
					result = r;
					beta = result < beta ? result : beta;
					x = moves[i].second.x;
					y = moves[i].second.y;
				}
			}
			if (beta <= alpha)
			{
				break;
			}
					}
		cout << "positions calculated: " << comp << endl;

	}
};
#endif // !AIPLAYER
