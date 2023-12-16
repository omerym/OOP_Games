#ifndef AIPLAYER
#define AIPLAYER
#include "BoardGame_Classes.hpp"
#include "Position.hpp"
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
		else if(r1.depth != r2.depth)
		{
			// if score is positive(winning) least depth is better
			// if score is negative(losing) most depth is better
			result = r1.depth < r2.depth ? 1 : -1;
			result = r1.score > 0 ? result : -result;
		}
		// if minimising invert result
		return maximise ? result : -result;
	}
	Result evaluate(T board,bool maximise, int index, unsigned int depth = 0)
	{
		//cout << "depth: " << depth << " index " << index << endl;
		if (depth >= max_depth || board.game_is_over())
		{
			return { board.evaluate(), depth };
		}
		vector<T> moves;
		board.generate_moves(moves);
		Result result;
		result.score = maximise ? INT_MIN + 1 : INT_MAX;
		result.depth = max_depth;
		int i = 0;
		for (auto move : moves)
		{
			Result s = evaluate(move,!maximise, index,depth + 1);
			if (compare_result(s,result,maximise) > 0)
			{
				result = s;
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
	AiPlayer(char symbol, unsigned int max_depth, T* board) : Player(symbol), max_depth(max_depth), board(board)
	{
		name = "AI Player: " + symbol;
	}
	// Generate a random move
	void get_move(int& x, int& y)
	{
		vector<T> moves;
		vector<Position> positions;
		board->generate_moves(moves, positions);
		Result result;
		result.score = is_maximiser() ? INT_MIN + 1 : INT_MAX;
		result.depth = max_depth;
		for (int i = 0; i < moves.size(); i++)
		{
			Result r = evaluate(moves[i], is_maximiser(),i);
			if (compare_result(r,result,is_maximiser()))
			{
				result = r;
				x = positions[i].x;
				y = positions[i].y;
			}
		}
		
	}

};
#endif // !AIPLAYER
