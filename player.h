#pragma once
class player {
private:
	float hits;
public:
	enum Players {
		PemainX, PemainY
	};
	const char* setNamaPemain(Players Pemain);
	void setHits(float hits);
	float getHits();
};

const char* player::setNamaPemain(Players Pemain) {
	switch (Pemain) {
	case PemainX:
		return "Pemain X";
		break;
	case PemainY:
		return "Pemain Y";
		break;
	};
}

void player::setHits(float hits) {
	this->hits = hits;
}

float player::getHits() {
	return hits;
}