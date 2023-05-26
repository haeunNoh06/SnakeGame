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


private:
	int dir_;
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
	window.setFramerateLimit(15);

	RectangleShape snake;
	int snake_x = 1, snake_y = 2;	// �� �� �׸��� ��ǥ
	int snake_dir = DIR_DOWN;		// ���� ó�� �̵��ϴ� ����
	snake.setFillColor(Color::White);
	snake.setPosition(snake_x * BLOCK_SIZE, snake_y * BLOCK_SIZE);
	snake.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	RectangleShape apple;
	int apple_x = rand() % G_WIDTH, apple_y = rand() % G_HEIGHT;
	apple.setFillColor(Color::Red);
	// 640�� 50�� �� ������ ������� ȭ�� �ۿ� 
	apple.setPosition(apple_x * BLOCK_SIZE, apple_y * BLOCK_SIZE);
	apple.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			// window�� x�� ������ �� â�� �ݾ������� 
			if (e.type == Event::Closed)
				window.close();
		}

		// ����Ű�� ���ÿ� �������� �ʵ��� else ó��
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake_dir = DIR_RIGHT;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake_dir = DIR_LEFT;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			snake_dir = DIR_UP;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake_dir = DIR_DOWN;

		}

		// update
		if (snake_dir == DIR_UP) {
			snake_y--;
		}
		else if (snake_dir == DIR_DOWN) {
			snake_y++;
		}
		else if (snake_dir == DIR_RIGHT) {
			snake_x++;
		}
		else if (snake_dir == DIR_LEFT ) {
			snake_x--;
		}
		snake.setPosition(snake_x * BLOCK_SIZE, snake_y * BLOCK_SIZE);

		// ���� ����� �Ծ��� �� : �� ��ǥ�� ��ġ��
		if ( snake_x == apple_x && snake_y == apple_y ) {
			apple_x = rand() % G_WIDTH, apple_y = rand() % G_HEIGHT;
			apple.setPosition( apple_x * BLOCK_SIZE, apple_y*BLOCK_SIZE);
		}

		// update render
		window.clear();

		window.draw(apple);
		window.draw(snake);	// draw�� �ʰ� �Ҽ��� �� ���� �ִ�

		window.display();
	}

	return 0;
}