#pragma once
class Rainbow{
private:
	double R = 0;
	double G = 0;
	double B = 0;
	double SPEED;
	bool RGB[3] = { false,false,false };
public:
	Rainbow(int red, int green, int blue, double speed);
	void Change();
	int getColor(char Color);
};

