#include "BadAppleScene.h"
#include<opencv2/opencv.hpp>
#include "Define.h"
#include "console.h"
#include "SceneManager.h"
#include<conio.h>
#include "mci.h"
#include<iostream>

BadAppleScene::BadAppleScene()
{
}

BadAppleScene::~BadAppleScene()
{
}

void BadAppleScene::init()
{
	cout.tie(0);
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	_cap = cv::VideoCapture("Video\\bad_apple.mp4");
	COORD resolution = getConsoleResolution();
	_width = resolution.X;
	_height = resolution.Y - 1;
	PlayBgm(TEXT("Sounds\\bad_apple.mp3"), 100);
}

void BadAppleScene::update()
{
	_curFrame++;
	_framePerSecond += 0.00025f;
	KEY key = keyController();

	if (key == KEY::ESC)
	{
		GET_SINGLETON(SceneManager)->setTransition("TitleScene");
		GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
	}
}

void BadAppleScene::render()
{
	if (_curFrame % 2 == 0) return;
	if (_cap.read(_frame))
	{
		cv::cvtColor(_frame, _grayFrame, cv::COLOR_BGR2GRAY);
		cv::resize(_grayFrame, _resizedFrame, cv::Size(_width, _height));
		gotoxy(0, 0);
		string buffer;
		buffer.reserve(_width * _height * 2);
		int index = 0;
		for (int y = 0; y < _height; y++) {
			for (int x = 0; x < _width; x++) {
				int pixelValue = _resizedFrame.at<uchar>(y, x);
				buffer += (pixelValue > 128) ? "8" : " ";
			}
			buffer += "\n";
		}
		cout << buffer;
		Sleep(1000/_framePerSecond);
	}
	else
	{
		GET_SINGLETON(SceneManager)->loadScene("TitleScene");
	}
}

KEY BadAppleScene::keyController()
{
	if (_kbhit())
	{
		int key = _getch();
		if (key == 0 || key == 224)
		{
			key = _getch();
			return (KEY)key;
		}
		return (KEY)key;
	}
	return KEY::FAIL;
}
