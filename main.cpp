#include"score.h"
#include"player.h"
#include<iostream>
#include<future>
#include<chrono>
using namespace std;

player getHits(player* Pemain) {
	int* temp = new int;
	srand((int)temp);
	delete temp;
	float result = rand() % 100 + 1;
	Pemain->setHits(result);
	return *Pemain;
}

int main() {
	//Instance Score
	score skor;
	skor.setSkorPemainX(0);
	skor.setSkorPemainY(0);

	//Instance Player
	player pemainX = player();
	const char* namaPemainX = pemainX.setNamaPemain(pemainX.PemainX);
	//Copy Player
	player pemainY = pemainX;
	const char* namaPemainY = pemainY.setNamaPemain(pemainY.PemainY);

	int skorPemainX = 0, skorPemainY = 0;
	float hitsPemainX, hitsPemainY;

	while (1) {
		float first = rand() % 1;
	back:
		if (first == 0) {
			auto future_pemainX = async(getHits, &pemainX);
			hitsPemainX = future_pemainX.get().getHits();
			auto future_pemainY = async(getHits, &pemainY);
			hitsPemainY = future_pemainY.get().getHits();
		}
		else if (first == 1) {
			auto future_pemainY = async(getHits, &pemainY);
			hitsPemainY = future_pemainY.get().getHits();
			auto future_pemainX = async(getHits, &pemainX);
			hitsPemainX = future_pemainX.get().getHits();
		}

		if (hitsPemainX > 50 && hitsPemainY > 50) {
			cout << "kembali" << endl;
			cout << "Hit Pemain X: " << hitsPemainX << endl;
			cout << "Hit Pemain Y: " << hitsPemainY << endl;
			goto back;
		}
		else if (hitsPemainX <= 50 && hitsPemainY <= 50) {
			cout << "kembali" << endl;
			cout << "Hit Pemain X: " << hitsPemainX << endl;
			cout << "Hit Pemain Y: " << hitsPemainY << endl;
			goto back;
		}
		else {
			if (hitsPemainX <= 50) {
				skorPemainY++;
			}
			else {
				skorPemainX++;
			}
		}

		cout << "Hit Pemain X: " << hitsPemainX << endl;
		cout << "Hit Pemain Y: " << hitsPemainY << endl;
		cout << "Skor Pemain X: " << skorPemainX << endl;
		cout << "Skor Pemain Y: " << skorPemainY << endl;

		std::this_thread::sleep_for(std::chrono::seconds(5));
		system("cls");

		if (skorPemainX == 10 || skorPemainY == 10) {
			score.setSkorPemainX(skorPemainX);
			score.setSkorPemainY(skorPemainY);
			break;
		}
	}
	if (score.getSkorPemainX() == 10) {
		cout << "Pemain X menang" << endl;
		cout << "Skor Pemain X: " << score.getSkorPemainX << endl;
		cout << "Skor Pemain Y: " << score.getSkorPemainY << endl;
	}
	else if (score.getSkorPemainY() == 10) {
		cout << "Pemain Y menang" << endl;
		cout << "Skor Pemain X: " << score.getSkorPemainX << endl;
		cout << "Skor Pemain Y: " << score.getSkorPemainY << endl;
	}

	system("pause");
	return 0;
}