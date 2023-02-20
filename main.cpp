#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;
int Time = 150;
void TextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoXY(int x, int y) { // x la ngang, y la doc
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
vector <string> input(char *s){
	ifstream cin(s);
	vector <string> kq;
	string x;
	while(1){
		if(!getline(cin, x))
			return kq;
		kq.push_back(x);
	} 
}

void heart(int x, int y, vector<string> s0, vector<string> s1, vector<string> s2){
	while(1){
		TextColor(7); 
		gotoXY(x + 4 + 13, y + 30 + 3); cout << " Mle <3 ";
		for(int i=0; i<s0.size(); i++){
			gotoXY(x, y + i);
			cout << s0[i];
		}
		gotoXY(0, 0);
		Sleep(Time);
		for(int i=20; i>=5; i--){
			for(int j=17; j<61; j++){
				gotoXY(x + j, y + i);
				if(s1[i][j] == '*'){
					TextColor(12);
				}else
					TextColor(7);
				cout << s1[i][j];
			}
			gotoXY(0, 0);
			Sleep(Time);
		}
		Sleep(Time*2);
		TextColor(12);
		for(int i=20; i>=5; i--){
			for(int j=0; j<61; j++){
				if(s2[i][j] != '@' || (j > 30 && j <47 && i <= 8))
					continue;
				gotoXY(x +j, y + i);
				cout << s2[i][j];
			}
			Sleep(Time);
		}
		gotoXY(x + 22, y + 4);	cout << "@@@@@@@@@@@";
		gotoXY(x + 44, y + 4);	cout << "@@@@@@@@@@@";
		Sleep(Time);
		gotoXY(x + 31, y + 5);	cout << "@@@@@";
		gotoXY(x + 41, y + 5);	cout << "@@@@@";
		Sleep(Time);
		gotoXY(x + 35, y + 6);	cout << "@@@";
		gotoXY(x + 39, y + 6);	cout << "@@@";
		Sleep(Time);
		gotoXY(x + 38, y + 7);	cout << "@";
		Sleep(Time);
		for(int i=0; i< 4; i++){
			for(int ii=0; ii<3; ii++){
				TextColor(12);
				gotoXY(x + 38, y + 8 + ii);
				cout << char(3);
				Sleep(Time*2);
				TextColor(7);
				gotoXY(x + 38, y + 8 + ii);
				cout << s2[8 + ii][38];
			}
			for(int j=33; j<44; j++){
				if(s2[14 - i][j] == '3'){
					TextColor(12);
					gotoXY(x + j, y + 14 - i);
					cout << char (3);
				}
			}
			Sleep(Time*2);
		}
		gotoXY(x + 4 + 13, y + 30 + 3); cout << "0   0";
		Sleep(Time*3);
	}
}
int main(){
	system("cls");
	getch(); 
	int x = 20, y = 2;
	
	char heart_0[] = "./heart0.txt";
	char heart_1[] = "./heart1.txt";
	char heart_2[] = "./heart2.txt";
	
	vector<string> s0 = input(heart_0);
	vector<string> s1 = input(heart_1);
	vector<string> s2 = input(heart_2);
	heart(x, y, s0, s1, s2);
	return 0;
}
