#pragma once
class score {
private:
	int skorPemainX;
	int skorPemainY;
public:
	void setSkorPemainX(int skorPemainX);
	int getSkorPemainX() const;
	void setSkorPemainY(int skorPemainY);
	int getSkorPemainY() const;
};

void score::setSkorPemainX(int skorPemainX) {
	this->skorPemainX = skorPemainX;
}

int score::getSkorPemainX() const {
	return skorPemainX;
}

void score::setSkorPemainY(int skorPemainY) {
	this->skorPemainY = skorPemainY;
}

int score::getSkorPemainY() const {
	return skorPemainY;
}