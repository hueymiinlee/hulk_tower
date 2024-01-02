#pragma once
#include "ofMain.h"

class Score {
protected:
	int score;
public:
	Score();
	void setScore(int);
	int getScore();
};
class Building: public Score
{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	void backGround();
	void displayLife();
	bool test();

	ofImage imag1;
	ofImage imag2;
	ofImage imag3;
	ofImage building1;
	ofImage building2;
	ofImage building3;
	ofImage gameend;
	ofImage word;
	ofImage replay;
	ofImage gamestart;
	ofImage life1;
	ofImage exit1;
	ofImage exit2;
	ofImage yes;
	ofImage no;
	ofImage perfect;
	ofImage title;
	ofSoundPlayer bgm;
	ofSoundPlayer se1;
	ofSoundPlayer se2;
	ofSoundPlayer click;
	ofTrueTypeFont scoredisp;
	ofTrueTypeFont scoredisp1;

	int level, stage, life, num;
	float x, x1, y, y1, x2, y2, x3, y3, moveY, fixedY, speed, testCoord;
	bool motion, hit, stop, moveScreen, gameStart, gameOver, playing, exit, sure;
};