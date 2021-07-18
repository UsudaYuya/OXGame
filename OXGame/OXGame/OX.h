#ifndef ___Class_OX
#define ___Class_OX
#include <string>
#include <iostream>
class OX {
	int m[9] = { 0,0,0,0,0,0,0,0,0 }; //マップ(0:空,1:o,2:x)
public:
	const std::string c[3] = { " ", "o", "x" }; // 共通で使う文字列配列
	void setM(int n, int v) { m[n] = v; } //マップ[n]に値vを格納
	int getM(int n) { return m[n]; } //マップ[n]の値を返す
	void disp() { //マップを表示
		std::cout << "+-+-+-+\n";
		std::cout << "\|" << c[m[0]] << "\|" << c[m[1]] << "\|" << c[m[2]] << "\| 0,1,2\n";
		std::cout << "+-+-+-+\n";
		std::cout << "\|" << c[m[3]] << "\|" << c[m[4]] << "\|" << c[m[5]] << "\| 3,4,5\n";
		std::cout << "+-+-+-+\n";
		std::cout << "\|" << c[m[6]] << "\|" << c[m[7]] << "\|" << c[m[8]] << "\| 6,7,8\n";
		std::cout << "+-+-+-+\n";
	}

	int win(){//勝利状態を返す
		for (int i = 0; i < 3; i++)
		{
			int n = 3 * i;
			if (m[n + 0] != 0 && m[n + 0] == m[n + 1] && m[n + 0] == m[n + 2])
				return m[n + 0];
			if (m[i + (3 * 0)] != 0 && m[i + (3 * 0)] == m[i + (3 * 1)] && m[i + (3 * 0)] == m[i + (3 * 2)])
				return m[i + (3 * 0)];
		}
		//斜め
		if ((m[0] != 0 && m[0] == m[4] && m[0] == m[8]) || (m[2] != 0 && m[2] == m[4] && m[2] == m[6]))
			return m[4];

		return 0;
	}

	int npc()
	{
		std::cout << m[0];
		int r = 0;//返す関数

		//✖が三つ並べる場所が存在していたらそこに決定する
		for (int i = 0; i < 3; i++)
		{
			int c = 0;
			for (int i = 0; i < 3; i++)
			{
				//横
				int c = 0;
				for (int n = 0; n < 3; n++)
					if (m[3 * i + n] == 2) c++; else r = 3 * i + n;

				if (c == 2 && m[r] == 0)
					return r;

				c = 0;
				//縦
				for (int n = 0; n < 3; n++)
					if (m[i + 3 * n] == 2)c++; else r = i + 3 * n;

				if (c == 2 && m[r] == 0)
					return r;
			}

			int n = 0;
			if (m[0] == 2)n++; else r = 0;
			if (m[4] == 2)n++; else r = 4;
			if (m[8] == 2)n++; else r = 8;
			if (r == 2 && m[r] == 0)return r;

			if (m[2] == 2)n++; else r = 2;
			if (m[4] == 2)n++; else r = 4;
			if (m[6] == 2)n++; else r = 6;
			if (r == 2 && m[r] == 0)return r;
		}

		//✖が三つ並べる場所が存在していたらそこに決定する
		for (int i = 0; i < 3; i++)
		{
			//横
			int c = 0;
			for (int n = 0; n < 3; n++)
				if (m[3 * i + n] == 2) c++; else r = 3 * i + n;

			if (c == 2 && m[r] == 0)
				return r;

			c = 0;
			//縦
			for (int n = 0; n < 3; n++)
				if (m[i + 3 * n] == 2)c++; else r = i + 3 * n;

			if (c == 2 && m[r] == 0)
				return r;
		}

		int n = 0;
		if (m[0] == 2)n++; else r = 0;
		if (m[4] == 2)n++; else r = 4;
		if (m[8] == 2)n++; else r = 8;
		if (r == 2 && m[r] == 0)return r;

		if (m[2] == 2)n++; else r = 2;
		if (m[4] == 2)n++; else r = 4;
		if (m[6] == 2)n++; else r = 6;
		if (r == 2 && m[r] == 0)return r;

		//〇が三つ並ぶ可能性のある場所を取得してそこを止める
		for (int i = 0; i < 3; i++)
		{
			//横
			int c = 0;
			for (int n = 0; n < 3; n++)
				if (m[3 * i + n] == 1) c++; else r = 3 * i + n;

			if (c == 2 && m[r] == 0)
				return r;

			c = 0;
			//縦
			for (int n = 0; n < 3; n++)
				if (m[i + 3 * n] == 1)c++; else r = i + 3 * n;

			if (c == 2 && m[r] == 0)
				return r;
		}

		n = 0;
		if (m[0] == 1)n++; else r = 0;
		if (m[4] == 1)n++; else r = 4;
		if (m[8] == 1)n++; else r = 8;
		if (n == 2 && m[r] == 0)return r;

		n = 0;
		if (m[2] == 1)n++; else r = 2;
		if (m[4] == 1)n++; else r = 4;
		if (m[6] == 1)n++; else r = 6;
		if (n == 2 && m[r] == 0)return r;

		//真ん中に置く[
		if (m[4] == 0)
			return 4;

		//端に置く　0,2,6,8
		if (m[0] == 0)return 0;
		if (m[2] == 0)return 2;
		if (m[6] == 0)return 6;
		if (m[8] == 0)return 8;

		//上下左右に置く　1357
		if (m[1] == 0)return 1;
		if (m[3] == 0)return 3;
		if (m[5] == 0)return 5;
		if (m[7] == 0)return 7;

	}
};
#endif
