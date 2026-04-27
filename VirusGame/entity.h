#pragma once
class Entity {
public:
	int _x = 0, _y = 0;
	char _symbol = ' ';
	virtual void Update() {}
};