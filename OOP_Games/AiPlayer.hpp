#ifndef AIPLAYER
#define AIPLAYER
#include "BoardGame_Classes.hpp"
#include "Position.hpp"
#include <utility>
#include <algorithm>
struct Result
{
public:
	int score;
	unsigned int depth;
};
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
			result = r1.depth > r2.depth ? 1 : -1;
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
		Result result;
		result.score = maximise ? INT_MIN + 1 : INT_MAX;
		result.depth = max_depth;
		for (auto move : moves)
		{
			Result s = evaluate(move, !maximise, depth - 1,alpha,beta, comp);
			result = compare_result(s, result, maximise) > 0 ? s : result;
			if (maximise)
			{
				alpha = compare_result(result, alpha, maximise) > 0 ? result : alpha;
			}
			else
			{
				beta = compare_result(result, beta, maximise) > 0 ? result : beta;
			}
			if (beta.score <= alpha.score)
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
	AiPlayer(char symbol, T* board,unsigned int max_depth) : Player(symbol), max_depth(max_depth), board(board)
	{
		name = "AI Player: ";
		name += symbol;
	}
	// Generate a random move
	void get_move(int& x, int& y)
	{
		vector<pair<T, Position>> moves;
		board->generate_moves(moves);
		Result result;
		result.score = is_maximiser() ? INT_MIN + 1 : INT_MAX;
		result.depth = max_depth;
		int comp = 0;
		Result alpha = { INT_MIN + 1,0 };
		Result beta = { INT_MAX,0 };
		for (int i = 0; i < moves.size(); i++)
		{
			Result r = evaluate(moves[i].first, is_maximiser(), max_depth, alpha, beta, comp);
			if (compare_result(r, result, is_maximiser()) > 0)
			{
				result = r;
				x = moves[i].second.x;
				y = moves[i].second.y;
			}
			if (is_maximiser())
			{
				alpha = compare_result(result, alpha, is_maximiser()) > 0 ? result : alpha;
			}
			else
			{
				beta = compare_result(result, beta, is_maximiser()) > 0 ? result : beta;
			}
			if (beta.score <= alpha.score)
			{
				break;
			}
		}
		cout << "positions calculated: " << comp << endl;
		if (is_maximiser() && result.score >= board->MIN_WIN)
		{
			cout << name << " will win after " << (max_depth - result.depth) << " moves.\n";
		}
		else if (!is_maximiser() && result.score <= -board->MIN_WIN)
		{
			cout << name << " will win after " << (max_depth - result.depth) << " moves.\n";
		}

	}
};
#endif // !AIPLAYER
