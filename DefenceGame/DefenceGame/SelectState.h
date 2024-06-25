#pragma once  
#include <fstream>
#include <Windows.h>
#include"console.h"
#include"Type.h"
#include"InGameState.h"
#include"Key.h"

void Render()
{
	int page = 0;

	while (true)
	{
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::RIGHT:
			if (page < 3)
				page++;
			break;
		case KEY::LEFT:
			if (page > 0)
				page--;
			break;
		}
	}

	if (page == 1)
	{
		gotoxy(92, 6);
		cout << "���������������" << endl;
		gotoxy(92, 7);
		cout << "��ޱü�    | ��Ÿ�: 3ĭ ��" << endl;
		gotoxy(92, 8);
		cout << "�ᰡ��: 20  | ���ݷ�: 5   ��" << endl;
		gotoxy(92, 9);
		cout << "���������������" << endl << endl;

		gotoxy(92, 11);
		cout << "���������������" << endl;
		gotoxy(92, 12);
		cout << "��޼��ú�  | ��Ÿ�: 5ĭ ��" << endl;
		gotoxy(92, 13);
		cout << "�ᰡ��: 50  | ���ݷ�: 1   ��" << endl;
		gotoxy(92, 14);
		cout << "���������������" << endl << endl;

		gotoxy(92, 16);
		cout << "���������������" << endl;
		gotoxy(92, 17);
		cout << "��޹߸���Ÿ| ��Ÿ�: 10ĭ��" << endl;
		gotoxy(92, 18);
		cout << "�ᰡ��: 1000| ���ݷ�: 200 ��" << endl;
		gotoxy(92, 19);
		cout << "���������������" << endl << endl;

		gotoxy(92, 21);
		cout << "���������������" << endl;
		gotoxy(92, 22);
		cout << "���������  | ��Ÿ�: 5ĭ ��" << endl;
		gotoxy(92, 23);
		cout << "�ᰡ�� : 100| ���ݷ�: 10  ��" << endl;
		gotoxy(92, 24);
		cout << "���������������" << endl << endl;

		gotoxy(103, 26);
		cout << "1 / 3" << endl;
	}
	else if (page == 2)
	{
		gotoxy(92, 6);
		cout << "���������������" << endl;
		gotoxy(92, 7);
		cout << "���ȭ��������|��Ÿ�: 5ĭ��" << endl;
		gotoxy(92, 8);
		cout << "�ᰡ��: 100   |���ݷ�: 10 ��" << endl;
		gotoxy(92, 9);
		cout << "���������������" << endl << endl;

		gotoxy(92, 11);
		cout << "���������������" << endl;
		gotoxy(92, 12);
		cout << "��޾���������|��Ÿ�: 5ĭ��" << endl;
		gotoxy(92, 13);
		cout << "�ᰡ��: 500   |���ݷ�: 5  ��" << endl;
		gotoxy(92, 14);
		cout << "���������������" << endl << endl;

		gotoxy(92, 16);
		cout << "���������������" << endl;
		gotoxy(92, 17);
		cout << "��޹���������|��Ÿ�: �� ��" << endl;
		gotoxy(92, 18);
		cout << "�ᰡ��: 500   |���ݷ�: 20 ��" << endl;
		gotoxy(92, 19);
		cout << "���������������" << endl << endl;

		gotoxy(103, 26);
		cout << "2 / 3" << endl;
	}
	else if (page == 3)
	{
		gotoxy(92, 6);
		cout << "���������������" << endl;
		gotoxy(92, 7);
		cout << "��ް˺�    | ��Ÿ�: 1ĭ ��" << endl;
		gotoxy(92, 8);
		cout << "�ᰡ��: 20  | ���ݷ�: 5   ��" << endl;
		gotoxy(92, 9);
		cout << "���������������" << endl << endl;

		gotoxy(92, 11);
		cout << "���������������" << endl;
		gotoxy(92, 12);
		cout << "���â��    | ��Ÿ�: 1ĭ ��" << endl;
		gotoxy(92, 13);
		cout << "�ᰡ��: 50  | ���ݷ�: 2   ��" << endl;
		gotoxy(92, 14);
		cout << "���������������" << endl << endl;

		gotoxy(92, 16);
		cout << "���������������" << endl;
		gotoxy(92, 17);
		cout << "��޽����̾� | ��Ÿ�: 1ĭ��" << endl;
		gotoxy(92, 18);
		cout << "�ᰡ��: 1000| ���ݷ�: 200 ��" << endl;
		gotoxy(92, 19);
		cout << "���������������" << endl << endl;

		gotoxy(103, 26);
		cout << "3 / 3" << endl;
	}
}

KEY KeyController()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		return KEY::LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		return KEY::RIGHT;
	}
}