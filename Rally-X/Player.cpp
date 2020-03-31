#include "Player.h"

Player::Player(): Car()
{
	fuelLevel = 100.0;
	lives = 3;
	score = 0;
	direction = animationState = stateTick = 0;
	specialActive = false;
	flagCount = 0;
}

Player::~Player()
{
}


enum States {
	Dead = -2, Stoped, Inactive,
	Up, Down, Left, Right, 
	UpRight, UpLeft, UpDown,
	DownRight, DownLeft, DownUp,
	LeftUp, LeftDown, LeftRight,
	RightUp, RightDown,  RightLeft,
};


enum Update {
	WallUp =1, WallRight, WallDown, WallLeft, EnemyC,
	UpUpdate, RightUpdate, DownUpdate, LeftUpdate, oHund, twoHund,
	threeHund, fourHund, fiveHund, sixHund, sevenHund, eightHund, nineHund, oneK
};

/*
Direction
	1
4	.	2
	3

States:



Dead = -2
Stoped =  -1
Inactive  = 0;


Default
	going up: 1
	going down: 2
	going left: 3
	going right: 4

Turning going UP
	turning right: 5
	turning left: 6
	going down: 7
Turning going DOWN:
	turning right: 8
	turning left: 9
	going up: 10
Turning going LEFT
	going up: 11
	going down: 12
	going right: 13
Turning going RIGHT:
	going up: 14
	going Down: 15
	going left: 16

*/


void Player::update(int type)
{
	this->state = Up;
	//Update input
	switch (type)
	{
	case 0:
		break;

	//Walls
		//Collision with wall up
	case WallUp:
		//Not head on
		if (direction != Up)
			direction = direction;
		//Handle side collision
		else
			direction = direction;
			//random turn
		break;


		//Collision with wall down
	case WallDown:
		//Not head on
		if (direction != Down)
			direction = direction;
		//Handle side collision
		else
			direction = direction;
		break;


		//Collision with wall left
	case WallLeft:
		//Not head on
		if (direction != Left)
			direction = direction;
		//Handle side collision
		else
			direction = direction;
		break;


		//Collision with wall right
	case WallRight:
		//Not head on
		if (direction != Right)
			direction = direction;
		//Handle side collision
		else
			direction = direction;
		break;

//Game Objects
		//Collision with Enemy
	case EnemyC:
		state = Dead;
		break;

//Update Input
		//Input up
	case UpUpdate:
		switch (direction)
		{
			//Going Right
		case Right:
			state = RightUp;
			break;
			//Going Left
		case Left:
			state = LeftUp;
			break;
			//Going Down
		case Down:
			state = DownUp;
			break;
		default:
			break;
		}
		if (direction != Up)
			stateTick = 7;
		break;

		//Input Down
	case DownUpdate:
		switch (direction)
		{
			//Going Right
		case Right:
			state = RightDown;
			break;
			//Going Left
		case Left:
			state = LeftDown;
			break;
			//Going Up
		case Up:
			state =UpDown;
			break;
		default:
			break;
		}
		if (direction != Down)
			stateTick = 7;
		break;

		//Input Left
	case LeftUpdate:
		switch (direction)
		{
			//Going up
		case Up:
			state = UpLeft;
			break;
			//Going Down
		case Down:
			state = DownLeft;
			break;
			//Going Right
		case Right:
			state = RightLeft;
			break;
		default:
			break;
		}
		if (direction != Left)
			stateTick = 7;
		break;

		//Input Right
	case RightUpdate:
		switch (direction)
		{
			//Going Down
		case Down:
			state = DownRight;
			break;
			//Going Up
		case Up:
			state = UpRight;
			break;
			//Going Left
		case Left:
			state = LeftRight;
			break;
		default:
			break;
		}
		if (direction != Right)
			stateTick = 7;
		break;

	//scoring
	case oneK:
		score += 100;
	case nineHund:
		score += 100;
	case eightHund:
		score += 100;
	case sevenHund:
		score += 100;
	case sixHund:
		score += 100;
	case fiveHund:
		score += 100;
	case fourHund:
		score += 100;
	case threeHund:
		score += 100;
	case twoHund:
		score += 100;
	case oHund:
		score += 100;
		break;

	default:
		break;
	}


	//Animation
	switch (state)
	{
	case Dead:
		//Explosion
		break;
	case Stoped:
		//Stop
		break;

	case UpRight:
		//Facing up Turning Right (right)
		if (stateTick == 0)
			state = Right;
		else 
		{
			if (5 <= stateTick <= 7)
			{
				animationState = 0;
			}
			else if (3 <= stateTick <= 4)
			{
				animationState = 1;
			}
			else if (1 <= stateTick <= 2)
			{
				animationState = 2;
			}
			stateTick--;
		}
		break;


	case UpLeft:
		//Facing up Turning Left (left)
		if (stateTick == 0)
			state = Left;
		else
		{
			if (5 <= stateTick <= 7)
			{
				animationState = 0;
			}
			else if (3 <= stateTick <= 4)
			{
				animationState = 11;
			}
			else if (1 <= stateTick <= 2)
			{
				animationState = 10;
			}
			stateTick--;
		}
		break;


	case UpDown:
//Turning Around
		//Facing up Turning Around (down)
		if (stateTick == 0)
			state = Down;
		else
		{
			if (13 <= stateTick <= 15)
			{
				animationState = 0;
			}
			else if (11 <= stateTick <= 12)
			{
				animationState = 11;
			}
			else if (9 <= stateTick <= 10)
			{
				animationState = 10;
			}
			if (6 <= stateTick <= 7)
			{
				animationState = 0;
			}
			else if (3 <= stateTick <= 4)
			{
				animationState = 11;
			}
			else if (1 <= stateTick <= 2)
			{
				animationState = 10;
			}
			stateTick--;
		}
		break;
	case DownLeft:
		//Facing Down Turning Right (left)
		if (stateTick == 0)
			state = 3;
		else
		{
			if (5 <= stateTick <= 7)
			{
				animationState = 6;
			}
			else if (3 <= stateTick <= 4)
			{
				animationState = 7;
			}
			else if (1 <= stateTick <= 2)
			{
				animationState = 8;
			}
			stateTick--;
		}
		break;
	case DownRight:
		//Facing Down Turning Left (right)
		if (stateTick == 0)
			state = 4;
		else
		{
			if (5 <= stateTick <= 7)
			{
				animationState = 6;
			}
			else if (3 <= stateTick <= 4)
			{
				animationState = 5;
			}
			else if (1 <= stateTick <= 2)
			{
				animationState = 4;
			}
			stateTick--;
		}
		break;
	case DownUp:
//Turn Around
		//Facing Down Turning Around (up)
		if (stateTick == 0)
			state = 1;
		else
		{

		}
		break;
	case LeftUp:
		//Facing Left Turning right (up)
		if (stateTick == 0)
			state = 1;
		else
		{
			if (5 <= stateTick <= 7)
			{
				animationState = 10;
			}
			else if (3 <= stateTick <= 4)
			{
				animationState = 11;
			}
			else if (1 <= stateTick <= 2)
			{
				animationState = 12;
			}
			stateTick--;
		}
		break;
	case LeftDown:
		//Facing Left Turning left (down)
		if (stateTick == 0)
			state = 2;
		else
		{

		}
		break;
	case LeftRight:
		//Facing Left Turning Around (right)
		if (stateTick == 0)
			state = 4;
		else
		{

		}
		break;
	case RightDown:
		//Facing Right Turning right (down)
		if (stateTick == 0)
			state = 2;
		else
		{

		}
		break;
	case RightUp:
		//Facing Right Turning left (up)
		if (stateTick == 0)
			state = 1;
		else
		{

		}
		break;
	case RightLeft:
		//Facing Right Turning Around (left)
		if (stateTick == 0)
			state = 3;
		else
		{

		}
		break;
	default:
		break;
	}
}

double Player::getFuel()
{
	return fuelLevel;
}

int Player::getScore()
{
	return score;
}

int Player::getLives()
{
	return lives;
}
