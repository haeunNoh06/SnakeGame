#include <SFML/Graphics.hpp>
#include <stdlib.h>		// srand(), rand()
#include <time.h>		// time()
#include <stdio.h>

#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_RIGHT 2
#define DIR_LEFT 3

using namespace sf;

class Snake {
public:
	int dir_;
	int x_;
	int y_;
	RectangleShape sprite_;
};

class Apple {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};


int main(void) {
	printf("%d\n", DIR_RIGHT);
	const int WIDTH = 1000;						// �ȼ� �ʺ�
	const int HEIGHT = 800;						// �ȼ� ����
	const int BLOCK_SIZE = 50;					// �� ĭ�� ������ �ִ� �ȼ�
	const int G_WIDTH = WIDTH / BLOCK_SIZE;		// �׸����� �ʺ�
	const int G_HEIGHT = HEIGHT / BLOCK_SIZE;	// �׸����� ����

	srand(time(NULL));
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");
	// ��ǻ�Ͱ� 1�� ���� ó���ϴ� Ƚ���� 30���� �����Ѵ�. => �ݺ����� 1�ʵ��� 30�� ���� ��
	window.setFramerateLimit(20);

	Snake snake;
	snake.x_ = 1, snake.y_ = 2;	// �� �� �׸��� ��ǥ
	snake.dir_ = DIR_DOWN;		// ���� ó�� �̵��ϴ� ����
	snake.sprite_.setFillColor(Color::White);
	snake.sprite_.setPosition(snake.x_ * BLOCK_SIZE, snake.y_ * BLOCK_SIZE);
	snake.sprite_.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	Apple apple;
	apple.x_ = rand() % G_WIDTH, apple.y_ = rand() % G_HEIGHT;
	apple.sprite_.setFillColor(Color::Red);
	// 640�� 50�� �� ������ ������� ȭ�� �ۿ� 
	apple.sprite_.setPosition(apple.x_ * BLOCK_SIZE, apple.y_ * BLOCK_SIZE);
	apple.sprite_.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			// window�� x�� ������ �� â�� �ݾ������� 
			if (e.type == Event::Closed)
				window.close();
		}

		// ����Ű�� ���ÿ� �������� �ʵ��� else ó��
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake.dir_ = DIR_RIGHT;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake.dir_ = DIR_LEFT;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			snake.dir_ = DIR_UP;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake.dir_ = DIR_DOWN;

		}

		// update
		if (snake.dir_ == DIR_UP) {
			snake.y_--;
		}
		else if (snake.dir_ == DIR_DOWN) {
			snake.y_++;
		}
		else if (snake.dir_ == DIR_RIGHT) {
			snake.x_++;
		}
		else if (snake.dir_ == DIR_LEFT ) {
			snake.x_--;
		}
		snake.sprite_.setPosition(snake.x_ * BLOCK_SIZE, snake.y_ * BLOCK_SIZE);

		// ���� ����� �Ծ��� �� : �� ��ǥ�� ��ġ��
		if ( snake.x_ == apple.x_ && snake.y_ == apple.y_ ) {
			apple.x_ = rand() % G_WIDTH, apple.y_ = rand() % G_HEIGHT;
			apple.sprite_.setPosition( apple.x_ * BLOCK_SIZE, apple.y_*BLOCK_SIZE);
		}

		// update render
		window.clear();

		window.draw(apple.sprite_);
		window.draw(snake.sprite_);	// draw�� �ʰ� �Ҽ��� �� ���� �ִ�

		window.display();
	}

	return 0;
}