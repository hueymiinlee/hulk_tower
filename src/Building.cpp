#include "Building.h"

Score::Score()
{
	score = 0;
}

void Score::setScore(int s)
{
	score = s;
}

int Score::getScore()
{
	return score;
}

void Building::setup() {
	ofBackground(174, 205, 255);
	building1.load("background.png");
	building2.load("wall.png");
	building3.load("wall.png");
	imag1.load("block.png");
	imag2.load("block.png");
	imag3.load("block.png");
	gameend.load("scoreboard.png");
	word.load("word over.png");
	replay.load("replay.png");
	gamestart.load("start.png");
	life1.load("heart.png");
	bgm.load("bgm.mpeg");
	bgm.setVolume(0.5);
	bgm.play();
	bgm.setLoop(TRUE);
	se1.load("drop.mp3");
	se1.setLoop(FALSE);
	scoredisp.loadFont("Bubblegum.ttf", 50, TRUE);
	scoredisp1.loadFont("Bubblegum.ttf", 70, TRUE);
	se2.load("oh3.wma");
	se2.setLoop(FALSE);
	click.load("click.mp3");
	click.setLoop(FALSE);
	exit1.load("hulk.jpg");
	exit2.load("exit.png");
	yes.load("yes.png");
	no.load("no.png");
	perfect.load("perfect.png");
	title.load("HULK.png");

	x = 450;
	y = 0;
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	x3 = 0;
	y3 = 0;
	life = 3;
	moveY = 0;
	fixedY = 0;
	level = 0;
	stage = 0;
	speed = 1;
	score = 0;
	motion = TRUE;
	hit = FALSE;
	moveScreen = FALSE;
	gameOver = FALSE;
	gameStart = FALSE;
	playing = FALSE;
	exit = FALSE;
	sure = FALSE;
}

//--------------------------------------------------------------
void Building::update() {
	if (hit == FALSE)
	{
		if (x >= 450 && motion == TRUE)
		{
			x += (5 * speed);
			if (x >= 1100)
			{
				motion = FALSE;
				x -= (5 * speed);
			}
		}

		else if (x >= 450 && motion == FALSE)
		{
			x -= (5 * speed);
			if (x <= 450)
			{
				motion = TRUE;
				x += (5 * speed);
			}
		}
	}

	else if (hit == TRUE)
	{
		speed += 0.0025;
		if (stage == 0 && level == 0)
		{
			if (test())
			{

				if (y > ofGetHeight() - 910)
				{
					se1.play();
					x1 = x;
					y1 = y;
					hit = FALSE;
					motion = TRUE;
					playing = TRUE;
					x = 450;
					y = 0;
					level = 3;
					score += 10;
				}
				y += 20;
			}

			else
			{
				if (y <= ofGetHeight())
				{
					y += 30;
					if (y > ofGetHeight())
					{
						se2.play();
						hit = FALSE;
						motion = TRUE;
						x = 450;
						y = 0;
						life--;
						level = 0;
						score -= 10;
					}
				}
			}
		}

		if (stage > 0)
		{
			if (level == 1)
			{
				if (test())
				{
					if (y <= y1 - 200)
					{
						y += 20;
						if (y >= y1 - 200)
						{
							se1.play();
							x2 = x;
							y2 = y;
							hit = FALSE;
							motion = TRUE;
							x = 450;
							y = 0;
							level++;
							score += 10;
						}
					}
				}

				else
				{
					if (y <= ofGetHeight())
					{
						y += 30;
						if (y > ofGetHeight())
						{
							se2.play();
							hit = FALSE;
							motion = TRUE;
							x = 450;
							y = 0;
							life--;
							level = 1;
							score -= 10;
						}
					}
				}
			}

			if (level == 2)
			{
				if (test())
				{
					if (y <= y2 - 200)
					{
						y += 20;
						if (y >= y2 - 200)
						{
							se1.play();
							x3 = x;
							y3 = y;
							hit = FALSE;
							motion = TRUE;
							x = 450;
							y = 0;
							level++;
							score += 10;
						}
					}
				}
				else
				{
					if (y <= ofGetHeight())
					{
						y += 30;
						if (y > ofGetHeight())
						{
							se2.play();
							hit = FALSE;
							motion = TRUE;
							x = 450;
							y = 0;
							life--;
							level = 2;
							score -= 10;
						}
					}
				}
			}
		}
	}

	if ((level % 3) == 0 && level != 0)
	{
		moveScreen = TRUE;
		if (stage == 0)
		{
			y1 += 15;
			moveY += 15;
			if (y1 >= ofGetHeight() - 200)
			{
				level = 1;
				hit = FALSE;
				motion = TRUE;
				moveScreen = FALSE;
				x = 450;
				y = 0;
				fixedY = moveY;
				moveY = 0;
				stage++;
			}
		}
		if (stage > 0)
		{
			y1 += 15;
			y2 += 15;
			y3 += 15;
			moveY += 15;
			if (y3 >= ofGetHeight() - 200)
			{
				level = 1;
				hit = FALSE;
				motion = TRUE;
				moveScreen = FALSE;
				x = 450;
				y = 0;
				x1 = x3;
				y1 = y3;
				fixedY = moveY;
				moveY = 0;
				stage++;
			}
		}
	}
}

//--------------------------------------------------------------
void Building::draw() {
	if (gameStart == TRUE)
	{
		playing = TRUE;
		if (life > 0)
		{
			displayLife();
			if (stage == 0)
			{
				if (level == 0)
				{
					backGround();
					building1.draw(350, 0, 1000, 1050);
					imag1.draw(x, y, 200, 200);
				}

				if (moveScreen == TRUE)
				{
					backGround();
					building1.draw(350, moveY, 1000, 1050);
					imag1.draw(x1, y1, 200, 200);
				}
			}
			else if (stage == 1)
			{
				if (level == 1)
				{
					backGround();
					building1.draw(350, fixedY, 1000, 1050);
					imag1.draw(x1, y1, 200, 200);
					imag2.draw(x, y, 200, 200);
				}

				if (level == 2)
				{
					backGround();
					building1.draw(350, fixedY, 1000, 1050);
					imag1.draw(x1, y1, 200, 200);
					imag2.draw(x2, y2, 200, 200);
					imag3.draw(x, y, 200, 200);

				}

				if (moveScreen == TRUE)
				{
					backGround();
					building1.draw(350, fixedY + moveY, 1000, 1050);
					imag1.draw(x1, y1, 200, 200);
					imag2.draw(x2, y2, 200, 200);
					imag3.draw(x3, y3, 200, 200);
				}
			}

			else if (stage > 1)
			{
				if (level == 1)
				{
					backGround();
					imag1.draw(x1, y1, 200, 200);
					perfect.draw(x, y, 200, 200);
					backGround();
					imag1.draw(x1, y1, 200, 200);
					imag2.draw(x, y, 200, 200);
				}

				if (level == 2)
				{
					backGround();
					imag1.draw(x1, y1, 200, 200);
					imag2.draw(x2, y2, 200, 200);
					imag3.draw(x, y, 200, 200);
				}

				if (moveScreen == TRUE)
				{
					backGround();
					imag1.draw(x1, y1, 200, 200);
					imag2.draw(x2, y2, 200, 200);
					imag3.draw(x3, y3, 200, 200);
				}
			}
		}

		if (life == 0 || score < 0)
		{
			life = 0;
			gameOver = TRUE;
			playing = FALSE;
			backGround();
			gameend.draw(550, 50, 640, 1020);
			word.draw(600, 100, 556, 190);
			ofSetHexColor(0xC41616);
			scoredisp1.drawString("You GET", 710, 450);
			if (score < 0)
			{
				scoredisp1.drawString("0", 820, 550);
			}
			else
			{
				scoredisp1.drawString(ofToString(score), 820, 550);
			}
			ofSetHexColor(0xFFFFFF);
			replay.draw(640, 650, 459, 139);
			exit2.draw(640, 800, 459, 139);
		}
	}
	if (gameStart == FALSE)
	{
		backGround();
		title.draw(275, 200, 1100, 550);
		gamestart.draw(650, 800, 450, 141);
	}

	if (exit == TRUE && gameOver == TRUE && sure == TRUE)
	{
		exit1.draw(450, 250);
		yes.draw(610, 750, 200, 200);
		no.draw(950, 750, 200, 200);
	}
}

//--------------------------------------------------------------
void Building::mousePressed(int a, int b, int button) {
	if (button == 0 && gameOver == FALSE && playing == TRUE)
		hit = TRUE;

	if (button == 0 && playing == FALSE && a >= 640 && a <= 640 + 459 && b >= 650 && b <= 650 + 139 &&
		gameOver == TRUE && exit == FALSE)
	{
		click.play();
		x = 450;
		y = 0;
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
		x3 = 0;
		y3 = 0;
		life = 3;
		moveY = 0;
		fixedY = 0;
		level = 0;
		speed = 1;
		score = 0;
		stage = 0;
		motion = TRUE;
		hit = FALSE;
		moveScreen = FALSE;
		gameOver = FALSE;
		gameStart = TRUE;
		playing = TRUE;
		exit = FALSE;
		sure = FALSE;
	}
	if (button == 0 && playing == FALSE && a >= 650 && a <= 650 + 450 && b >= 800 && b <= 800 + 141 && gameStart == FALSE)
	{
		click.play();
		gameStart = TRUE;
		playing = TRUE;
	}
	if (button == 0 && playing == FALSE && a >= 640 && a <= 640 + 459 && b >= 800 && b <= 800 + 139 &&
		gameOver == TRUE && sure == FALSE && exit == FALSE)
	{
		click.play();
		exit = TRUE;
		sure = TRUE;
	}

	else if (button == 0 && gameOver == TRUE && exit == TRUE && sure == TRUE)
	{
		click.play();
		if (a >= 610 && a <= 610 + 200 && b >= 750 && b <= 750 + 200)
			ofExit(0);

		if (a >= 950 && a <= 950 + 200 && b >= 750 && b <= 750 + 200)
		{
			exit = FALSE;
			sure = FALSE;
		}
	}
}
void Building::backGround()
{
	if (playing == FALSE)
	{
		building2.draw(-250, 0, 600, ofGetHeight());
		building3.draw(1350, 0, 600, ofGetHeight());
	}
	if (playing == TRUE)
	{
		building2.draw(-250, 0, 600, ofGetHeight());
		building3.draw(1350, 0, 600, ofGetHeight());
		scoredisp.drawString(ofToString(score), 1360, 100);
	}
}

bool Building::test()
{
	if (stage == 0)
	{
		if (level == 0)
		{
			if ((x >= 700 && x <= 1000) || (x + 200 >= 700 && x + 200 <= 1000))
				return TRUE;
			else
				return FALSE;
		}
	}
	if (stage > 0)
	{
		if (level == 1)
		{
			if ((x >= x1 && x <= x1 + 200) || (x + 200 >= x1 && x + 200 <= x1 + 200))
				return TRUE;
			else
				return FALSE;
		}
		if (level == 2)
		{
			if ((x >= x2 && x <= x2 + 200) || (x + 200 >= x2 && x + 200 <= x2 + 200))
				return TRUE;
			else
				return FALSE;
		}
	}
}

void Building::displayLife()
{
	if (life == 3)
	{
		life1.draw(370, 10);
		life1.draw(370, 70);
		life1.draw(370, 130);
	}

	if (life == 2)
	{
		life1.draw(370, 10);
		life1.draw(370, 70);
	}

	if (life == 1)
		life1.draw(370, 10);
}