#include <iostream>
#include "ox.h"
using namespace std;
int main()
{
	OX ox; //インスタンス生成
	int tesu = 0; //手数
	int te; //入力用

	while (tesu < 9) { //9手目までくり返す

		ox.disp(); //マップを画面に表示する
		do {
			cout << "「" << ox.c[1] << "」の番です(0-8)：";
			cin >> te; //手を入力
		} while (te < 0 || te > 8 || ox.getM(te) != 0); //手の繰り返し

		ox.setM(te, 1); //マップ[te]に手を代入
		tesu++;
		if (ox.win() != 0)break;//勝利確認


		te = ox.npc();//相手の手の取得
		ox.setM(te, 2); //マップ[te]に手を代入
		cout << te;
		tesu++; //手数をカウントアップ
		if (ox.win() != 0)break;//勝利確認
	}
	ox.disp(); //マップを画面に表示する

	if (ox.win() == 0)
		cout << "引き分けです";
	else
		cout << ox.c[ox.win()] << "の勝利です";
}
