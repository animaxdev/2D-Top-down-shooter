#include "GameObject.h"
#include <iostream>



GameObject::GameObject(float width, float height, float moveSpeed, char* textureLocation): width(width), height(height), moveSpeed(moveSpeed) {
	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
}

void GameObject::draw() {
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	sprite->draw();
	glPopMatrix();
}


float GameObject::getPositionX() {
	return x;
}
float GameObject::getPositionY() {
	return y;
}

void GameObject::setPositionX(float x) {
	this->x = x;
}

void GameObject::setPositionY(float y) {
	this->y = y;
}

void GameObject::setAngle(float angle) {
	this->angle = angle;
}

float GameObject::getAngle() {
	return angle;
}

void GameObject::moveUP(unsigned char key, int xmouse, int ymouse){
	key = 'w';
	y -= moveSpeed;
	// std::cout << y << std::endl;
}

void GameObject::moveDown(unsigned char key, int xmouse, int ymouse){
	key = 's';
	y += moveSpeed;
	// std::cout << y << std::endl;
}

void GameObject::moveLeft(unsigned char key,int xmouse, int ymouse){
	key = 'a';
	x -= moveSpeed;
	// std::cout << x << std::endl;
}

void GameObject::moveRight(unsigned char key, int xmouse, int ymouse) {
	key = 'd';
	x += moveSpeed;
	// std::cout << x << std::endl;
}
