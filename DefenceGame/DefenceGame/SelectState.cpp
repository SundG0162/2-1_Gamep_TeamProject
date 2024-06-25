#include "SelectState.h"
#include"Player.h"
#include<conio.h>

SelectState::SelectState(InGameScene* inGameScene)
{
	_inGameScene = inGameScene;
}
void SelectState::update()
{
	KEY Key = keyController();
	switch (Key)
	{
	case KEY::RIGHT:
	{
		if (_currentPage < 3)
			_currentPage++;
		break;
	}
	case KEY::LEFT:
	{
		if (_currentPage > 1)
			_currentPage--;
		break;
	}
	case KEY::UP:
	{
		if (_currentSelectIndex > 1)
			_currentSelectIndex--;
		break;
	}
	case KEY::DOWN:
	{
		if (_currentSelectIndex < 4)
			_currentSelectIndex++;
		break;
	}
	case KEY::ENTER:
	{
		GET_SINGLETON(Player)->
			setAlly(GET_SINGLETON(EntityManager)->
			spawnEntity((ALLY_TYPE)(_currentPage * _currentSelectIndex), Vector2(28,19)));
		_inGameScene->changeState(INGAMESCENE_STATE::PLACE);
		break;
	}
	case KEY::SPACE:
	{
		GET_SINGLETON(Player)->
			setAlly(GET_SINGLETON(EntityManager)->
			spawnEntity((ALLY_TYPE)(_currentPage * _currentSelectIndex), Vector2(28, 19)));
		_inGameScene->changeState(INGAMESCENE_STATE::PLACE);
		break;
	}
	case KEY::ESC:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
		break;
	}
	}
}

void SelectState::render()
{
	if (_currentPage == 1)
	{
		gotoxy(92, 6);
		cout << "���������������" << endl;
		gotoxy(92, 7);
		cout << "��  �ü�    | ��Ÿ�: 3ĭ ��" << endl;
		gotoxy(92, 8);
		cout << "�ᰡ��: 20  | ���ݷ�: 5   ��" << endl;
		gotoxy(92, 9);
		cout << "���������������" << endl << endl;

		gotoxy(92, 11);
		cout << "���������������" << endl;
		gotoxy(92, 12);
		cout << "��  ���ú�  | ��Ÿ�: 5ĭ ��" << endl;
		gotoxy(92, 13);
		cout << "�ᰡ��: 50  | ���ݷ�: 1   ��" << endl;
		gotoxy(92, 14);
		cout << "���������������" << endl << endl;

		gotoxy(92, 16);
		cout << "���������������" << endl;
		gotoxy(92, 17);
		cout << "��  �߸���Ÿ| ��Ÿ�: 10ĭ��" << endl;
		gotoxy(92, 18);
		cout << "�ᰡ��: 1000| ���ݷ�: 200 ��" << endl;
		gotoxy(92, 19);
		cout << "���������������" << endl << endl;

		gotoxy(92, 21);
		cout << "���������������" << endl;
		gotoxy(92, 22);
		cout << "��  ������  | ��Ÿ�: 5ĭ ��" << endl;
		gotoxy(92, 23);
		cout << "�ᰡ�� : 100| ���ݷ�: 10  ��" << endl;
		gotoxy(92, 24);
		cout << "���������������" << endl << endl;
	}
	else if (_currentPage == 2)
	{
		gotoxy(92, 6);
		cout << "���������������" << endl;
		gotoxy(92, 7);
		cout << "��  ȭ��������|��Ÿ�: 5ĭ��" << endl;
		gotoxy(92, 8);
		cout << "�ᰡ��: 100   |���ݷ�: 10 ��" << endl;
		gotoxy(92, 9);
		cout << "���������������" << endl << endl;

		gotoxy(92, 11);
		cout << "���������������" << endl;
		gotoxy(92, 12);
		cout << "��  ����������|��Ÿ�: 5ĭ��" << endl;
		gotoxy(92, 13);
		cout << "�ᰡ��: 500   |���ݷ�: 5  ��" << endl;
		gotoxy(92, 14);
		cout << "���������������" << endl << endl;

		gotoxy(92, 16);
		cout << "���������������" << endl;
		gotoxy(92, 17);
		cout << "��  ����������|��Ÿ�: �� ��" << endl;
		gotoxy(92, 18);
		cout << "�ᰡ��: 500   |���ݷ�: 20 ��" << endl;
		gotoxy(92, 19);
		cout << "���������������" << endl << endl;

		gotoxy(92, 21);
		cout << "���������������" << endl;
		gotoxy(92, 22);
		cout << "��  ��ũ�θǼ�|��Ÿ�: ?ĭ��" << endl;
		gotoxy(92, 23);
		cout << "�ᰡ�� : 500| ���ݷ�: ??  ��" << endl;
		gotoxy(92, 24);
		cout << "���������������" << endl << endl;
	}
	else if (_currentPage == 3)
	{
		gotoxy(92, 6);
		cout << "���������������" << endl;
		gotoxy(92, 7);
		cout << "��  �˺�    | ��Ÿ�: 1ĭ ��" << endl;
		gotoxy(92, 8);
		cout << "�ᰡ��: 20  | ���ݷ�: 5   ��" << endl;
		gotoxy(92, 9);
		cout << "���������������" << endl << endl;

		gotoxy(92, 11);
		cout << "���������������" << endl;
		gotoxy(92, 12);
		cout << "��  â��    | ��Ÿ�: 2ĭ ��" << endl;
		gotoxy(92, 13);
		cout << "�ᰡ��: 50  | ���ݷ�: 2   ��" << endl;
		gotoxy(92, 14);
		cout << "���������������" << endl << endl;

		gotoxy(92, 16);
		cout << "���������������" << endl;
		gotoxy(92, 17);
		cout << "��  �����̾� | ��Ÿ�: 1ĭ��" << endl;
		gotoxy(92, 18);
		cout << "�ᰡ��: 1000| ���ݷ�: 200 ��" << endl;
		gotoxy(92, 19);
		cout << "���������������" << endl << endl;

		gotoxy(92, 21);
		cout << "���������������" << endl;
		gotoxy(92, 22);
		cout << "��  ��˺�  | ��Ÿ�: 2ĭ ��" << endl;
		gotoxy(92, 23);
		cout << "�ᰡ�� : 800| ���ݷ�: 300 ��" << endl;
		gotoxy(92, 24);
		cout << "���������������" << endl << endl;
	}

	gotoxy(103, 26);
	cout << _currentPage << " / 3" << endl;

	int selectMarkY = 7 + 5 * (_currentSelectIndex - 1);
	gotoxy(93, selectMarkY);
	cout << "��";

	gotoxy(48, 27);
	cout << "Enter �Ǵ� SpaceŰ�� ����";
}