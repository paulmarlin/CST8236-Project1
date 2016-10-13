#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "TransformNode.h"
#include <iostream>

int main(int argc, char* argv) {
	sf::RenderWindow window(sf::VideoMode(900, 500), "Windmillz");
	bool keyHeld = false;
	bool oneKey = false;
	bool twoKey = false;
	bool threeKey = false;
	bool allKey = true;

	sf::Vector2i oldPosition;

	sf::Texture postTexture;
	postTexture.loadFromFile("res/eyeofsauron.png");

	sf::Texture windMillTexture;
	windMillTexture.loadFromFile("res/CryManWindMillBlade.png");

	sf::Texture broncosTexture;
	broncosTexture.loadFromFile("res/broncos-logo.png");

	sf::Texture cloudTexture;
	cloudTexture.loadFromFile("res/tiling_clouds.jpg");
	cloudTexture.setRepeated(true);

	sf::Sprite tilingCloudSprite;
	tilingCloudSprite.setTexture(cloudTexture);
	tilingCloudSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

	// create shapes for windmill 1
	sf::CircleShape windMillTop1(20.0f, 30.0f);
	sf::CircleShape windMillCenter1(10.0f, 30.0f);
	sf::RectangleShape windMillPost1(sf::Vector2<float>(40.0f, 250.0f));
	sf::RectangleShape windMillDownArm1(sf::Vector2<float>(125.0f, 15.0f));
	sf::RectangleShape windMillRightArm1(sf::Vector2<float>(125.0f, 15.0f));
	sf::RectangleShape windMillUpArm1(sf::Vector2<float>(125.0f, 15.0f));
	sf::RectangleShape windMillLeftArm1(sf::Vector2<float>(125.0f, 15.0f));

	// create shapes for windmill 2
	sf::CircleShape windMillTop2(20.0f, 30.0f);
	sf::CircleShape windMillCenter2(10.0f, 30.0f);
	sf::RectangleShape windMillPost2(sf::Vector2<float>(40.0f, 250.0f));
	sf::RectangleShape windMillDownArm2(sf::Vector2<float>(125.0f, 15.0f));
	sf::RectangleShape windMillRightArm2(sf::Vector2<float>(125.0f, 15.0f));
	sf::RectangleShape windMillUpArm2(sf::Vector2<float>(125.0f, 15.0f));
	sf::RectangleShape windMillLeftArm2(sf::Vector2<float>(125.0f, 15.0f));

	// create shapes for windmill 3
	sf::CircleShape windMillTop3(20.0f, 30.0f);
	sf::CircleShape windMillCenter3(10.0f, 30.0f);
	sf::RectangleShape windMillPost3(sf::Vector2<float>(40.0f, 250.0f));
	sf::RectangleShape windMillDownArm3(sf::Vector2<float>(125.0f, 15.0f));
	sf::RectangleShape windMillRightArm3(sf::Vector2<float>(125.0f, 15.0f));
	sf::RectangleShape windMillUpArm3(sf::Vector2<float>(125.0f, 15.0f));
	sf::RectangleShape windMillLeftArm3(sf::Vector2<float>(125.0f, 15.0f));

	// set textures
	windMillPost1.setTexture(&postTexture);
	windMillTop1.setTexture(&broncosTexture);
	windMillCenter1.setTexture(&broncosTexture);
	windMillDownArm1.setTexture(&windMillTexture);
	windMillRightArm1.setTexture(&windMillTexture);
	windMillUpArm1.setTexture(&windMillTexture);
	windMillLeftArm1.setTexture(&windMillTexture);

	windMillPost2.setTexture(&postTexture);
	windMillTop2.setTexture(&broncosTexture);
	windMillCenter2.setTexture(&broncosTexture);
	windMillDownArm2.setTexture(&windMillTexture);
	windMillRightArm2.setTexture(&windMillTexture);
	windMillUpArm2.setTexture(&windMillTexture);
	windMillLeftArm2.setTexture(&windMillTexture);

	windMillPost3.setTexture(&postTexture);
	windMillTop3.setTexture(&broncosTexture);
	windMillCenter3.setTexture(&broncosTexture);
	windMillDownArm3.setTexture(&windMillTexture);
	windMillRightArm3.setTexture(&windMillTexture);
	windMillUpArm3.setTexture(&windMillTexture);
	windMillLeftArm3.setTexture(&windMillTexture);

	// set origin and position of parent rects.
	windMillPost1.setOrigin(20.0f, 125.0f);
	windMillPost1.setPosition(150.0f, 375.0f);

	// child origins and positions
	windMillPost2.setOrigin(20.0f, 125.0f);
	windMillPost2.setPosition(450.0f, 375.0f);

	windMillPost3.setOrigin(20.0f, 125.0f);
	windMillPost3.setPosition(750.0f, 375.0f);

	// set position of windmill tops
	windMillTop1.setOrigin(10.0f, 10.0f);
	windMillTop1.setPosition(10.0f, -10.0f);
	windMillCenter1.setOrigin(5.0f, 5.0f);
	windMillCenter1.setPosition(15.0f, 15.0f);

	windMillTop2.setOrigin(10.0f, 10.0f);
	windMillTop2.setPosition(10.0f, -10.0f);
	windMillCenter2.setOrigin(5.0f, 5.0f);
	windMillCenter2.setPosition(15.0f, 15.0f);

	windMillTop3.setOrigin(10.0f, 10.0f);
	windMillTop3.setPosition(10.0f, -10.0f);
	windMillCenter3.setOrigin(5.0f, 5.0f);
	windMillCenter3.setPosition(15.0f, 15.0f);

	// set position of windmill arms
	windMillUpArm1.setRotation(270.0f);
	windMillDownArm1.setRotation(90.0f);
	windMillLeftArm1.setRotation(180.0f);
	windMillRightArm1.setOrigin(0.0f, 7.5f);
	windMillDownArm1.setOrigin(0.0f, 7.5f);
	windMillLeftArm1.setOrigin(0.0f, 7.5f);
	windMillUpArm1.setOrigin(0.0f, 7.5f);
	windMillRightArm1.setPosition(20.0f, 20.0f);
	windMillDownArm1.setPosition(20.0f, 20.0f);
	windMillLeftArm1.setPosition(20.0f, 20.0f);
	windMillUpArm1.setPosition(20.0f, 20.0f);

	windMillUpArm2.setRotation(270.0f);
	windMillDownArm2.setRotation(90.0f);
	windMillLeftArm2.setRotation(180.0f);
	windMillRightArm2.setOrigin(0.0f, 7.5f);
	windMillDownArm2.setOrigin(0.0f, 7.5f);
	windMillLeftArm2.setOrigin(0.0f, 7.5f);
	windMillUpArm2.setOrigin(0.0f, 7.5f);
	windMillRightArm2.setPosition(20.0f, 20.0f);
	windMillDownArm2.setPosition(20.0f, 20.0f);
	windMillLeftArm2.setPosition(20.0f, 20.0f);
	windMillUpArm2.setPosition(20.0f, 20.0f);

	windMillUpArm3.setRotation(270.0f);
	windMillDownArm3.setRotation(90.0f);
	windMillLeftArm3.setRotation(180.0f);
	windMillRightArm3.setOrigin(0.0f, 7.5f);
	windMillDownArm3.setOrigin(0.0f, 7.5f);
	windMillLeftArm3.setOrigin(0.0f, 7.5f);
	windMillUpArm3.setOrigin(0.0f, 7.5f);
	windMillRightArm3.setPosition(20.0f, 20.0f);
	windMillDownArm3.setPosition(20.0f, 20.0f);
	windMillLeftArm3.setPosition(20.0f, 20.0f);
	windMillUpArm3.setPosition(20.0f, 20.0f);
		
	// create nodes
	TransformNode windMillTopNode1(&windMillTop1);
	TransformNode windMillCenterNode1(&windMillCenter1);
	TransformNode windMillRightArmNode1(&windMillRightArm1);
	TransformNode windMillDownArmNode1(&windMillDownArm1);
	TransformNode windMillLeftArmNode1(&windMillLeftArm1);
	TransformNode windMillUpArmNode1(&windMillUpArm1);
	TransformNode windMillNode1(&windMillPost1);

	TransformNode windMillTopNode2(&windMillTop2);
	TransformNode windMillCenterNode2(&windMillCenter2);
	TransformNode windMillRightArmNode2(&windMillRightArm2);
	TransformNode windMillDownArmNode2(&windMillDownArm2);
	TransformNode windMillLeftArmNode2(&windMillLeftArm2);
	TransformNode windMillUpArmNode2(&windMillUpArm2);
	TransformNode windMillNode2(&windMillPost2);

	TransformNode windMillTopNode3(&windMillTop3);
	TransformNode windMillCenterNode3(&windMillCenter3);
	TransformNode windMillRightArmNode3(&windMillRightArm3);
	TransformNode windMillDownArmNode3(&windMillDownArm3);
	TransformNode windMillLeftArmNode3(&windMillLeftArm3);
	TransformNode windMillUpArmNode3(&windMillUpArm3);
	TransformNode windMillNode3(&windMillPost3);

	// add children
	windMillTopNode1.addChild(&windMillDownArmNode1);
	windMillTopNode1.addChild(&windMillUpArmNode1);
	windMillTopNode1.addChild(&windMillRightArmNode1);
	windMillTopNode1.addChild(&windMillLeftArmNode1);
	windMillTopNode1.addChild(&windMillCenterNode1);
	windMillNode1.addChild(&windMillTopNode1);

	windMillTopNode2.addChild(&windMillDownArmNode2);
	windMillTopNode2.addChild(&windMillUpArmNode2);
	windMillTopNode2.addChild(&windMillRightArmNode2);
	windMillTopNode2.addChild(&windMillLeftArmNode2);
	windMillTopNode2.addChild(&windMillCenterNode2);
	windMillNode2.addChild(&windMillTopNode2);

	windMillTopNode3.addChild(&windMillDownArmNode3);
	windMillTopNode3.addChild(&windMillUpArmNode3);
	windMillTopNode3.addChild(&windMillRightArmNode3);
	windMillTopNode3.addChild(&windMillLeftArmNode3);
	windMillTopNode3.addChild(&windMillCenterNode3);
	windMillNode3.addChild(&windMillTopNode3);

	sf::Vector2f origPos1 = windMillPost1.getPosition();
	sf::Vector2f origPos2 = windMillPost2.getPosition();
	sf::Vector2f origPos3 = windMillPost3.getPosition();

	sf::Transform origT1 = windMillPost1.getTransform();
	sf::Transform origT2 = windMillPost2.getTransform();
	sf::Transform origT3 = windMillPost3.getTransform();

	oldPosition = sf::Mouse::getPosition(window);
	sf::Transform t;
	sf::Transform t2;
	sf::Transform t3;
	sf::Clock deltaTime;
	int deltaX = 0;
	int deltaY = 0;
	float totalTime = 0.0f;

	sf::IntRect backgroundRect = tilingCloudSprite.getTextureRect();
	float movementSpeed = 150.0f; // scrolling movement speed.

	while (window.isOpen()) {
		// time elapsed since last loop
		float elapsedTime = deltaTime.restart().asSeconds();
		totalTime += elapsedTime;
		sf::Event sfEvent;
		float armMovement = 90.0f * elapsedTime;
		float centerRotationMovement = 200.0f * elapsedTime;
		// close window when x is pressed
		while (window.pollEvent(sfEvent)) {
			if (sfEvent.type == sf::Event::Closed) {
				window.close();
			}
			else if (sfEvent.type == sf::Event::KeyPressed) {
				keyHeld = true;
				if (sfEvent.key.code == sf::Keyboard::Num1) {
					oneKey = true;
					twoKey = false;
					threeKey = false;
					allKey = false;
				}
				else if (sfEvent.key.code == sf::Keyboard::Num2) {
					twoKey = true;
					oneKey = false;
					threeKey = false;
					allKey = false;
				}
				else if (sfEvent.key.code == sf::Keyboard::Num3) {
					threeKey = true;
					oneKey = false;
					twoKey = false;
					allKey = false;
				}
				else if (sfEvent.key.code == sf::Keyboard::Num4 || sfEvent.key.code == sf::Keyboard::A) {
					allKey = true;
					oneKey = false;
					twoKey = false;
					threeKey = false;

					printf("rotat1 -> %f \n", windMillPost1.getRotation());
					printf("rotat2 -> %f \n", windMillPost2.getRotation());
					printf("rotat3 -> %f \n", windMillPost3.getRotation());

					// reset rotations
					windMillPost1.setRotation(0.0f);					
					windMillPost2.setRotation(0.0f);
					windMillPost3.setRotation(0.0f);

					// reset transforms
					t = sf::Transform::Identity; 
					t2 = sf::Transform::Identity;
					t3 = sf::Transform::Identity;					
				}
			}
			else if (sfEvent.type == sf::Event::KeyReleased) {
				keyHeld = false;
			}
			else if (sfEvent.type == sf::Event::MouseMoved) {
				// get current mouse position
				sf::Vector2i localPosition = sf::Mouse::getPosition(window);

				// determine differences in movement
				deltaX = localPosition.x - oldPosition.x;
				deltaY = localPosition.y - oldPosition.y;

				// ensure number is positive
				deltaX = deltaX < 0 ? deltaX * -1 : deltaX;
				deltaY = deltaY < 0 ? deltaY * -1 : deltaY;

				// mouse moved up or down
				if (deltaX > 2) {
					printf("xxxx\n");
					if (oneKey)
						windMillPost1.rotate(centerRotationMovement);
					else if (twoKey)
						windMillPost2.rotate(centerRotationMovement);
					else if (threeKey)
						windMillPost3.rotate(centerRotationMovement);
					else if (allKey) {						
						/*windMillPost1.rotate(centerRotationMovement);
						windMillPost2.rotate(centerRotationMovement);
						windMillPost3.rotate(centerRotationMovement);*/
					}
				}

				// mouse moved left or right 
				if (deltaY > 2) {
					printf("yyyy\n"); 
					if (oneKey)
						t.rotate(1.0f, { 100.0f, 300.0f });
					else if (twoKey)
						t2.rotate(1.0f, { windMillPost1.getLocalBounds().width / 2.0f, windMillPost1.getLocalBounds().height / 2.0f });
					else if (threeKey)
						t3.rotate(1.0f, { windMillPost2.getLocalBounds().width / 2.0f, windMillPost2.getLocalBounds().height / 2.0f });
					else if (allKey) {
						// rotate around corner of screen
						t.rotate(1.0f, { 100.0f, 300.0f });
						// rotate around left windmill
						t2.rotate(1.0f, { windMillPost1.getLocalBounds().width / 2.0f, windMillPost1.getLocalBounds().height / 2.0f });
						t3.rotate(1.0f, { windMillPost2.getLocalBounds().width / 2.0f, windMillPost2.getLocalBounds().height / 2.0f });
						
					}
				}
				oldPosition = localPosition;
			}
		}

		sf::IntRect deltaRect = backgroundRect;
		deltaRect.left = backgroundRect.left + (int)(movementSpeed * totalTime);
		tilingCloudSprite.setTextureRect(deltaRect);

		// Check if more than a second has elapsed, as that's all we're checking.
		if (totalTime > 1.0f)
		{
			/* Remove a second from timer (we can't set it to 0 because there's a chance that a small
			* fraction of a second has elapsed, and we don't want to lose that). eg. 1.001f */
			totalTime -= 1.0f;
			backgroundRect.left += (int)movementSpeed; // Add on the appropriate offset.

			/* We don't want our offset to get too big, so what we do is check to see if it's larger than our
			* texture. If it is, we can safely subtract the size of our texture from the rectangle's offset and
			* see the exact same point on the texture. (if width = 100, then we don't want the offset to be 1300
			* when 1300 looks exactly like 100 because of the repeating texture; this makes our numbers much easier
			* to work with. */
			if (backgroundRect.left >= (float)cloudTexture.getSize().x) {
				backgroundRect.left -= cloudTexture.getSize().x;
			}
		}

		windMillRightArm1.rotate(armMovement);
		windMillDownArm1.rotate(armMovement);
		windMillLeftArm1.rotate(armMovement);
		windMillUpArm1.rotate(armMovement);

		windMillRightArm2.rotate(armMovement);
		windMillDownArm2.rotate(armMovement);
		windMillLeftArm2.rotate(armMovement);
		windMillUpArm2.rotate(armMovement);

		windMillRightArm3.rotate(armMovement);
		windMillDownArm3.rotate(armMovement);
		windMillLeftArm3.rotate(armMovement);
		windMillUpArm3.rotate(armMovement);

		window.clear(); // clear display
		window.draw(tilingCloudSprite);
		windMillNode1.draw(&window, t); // draw all shapes
		windMillNode2.draw(&window, t2);
		windMillNode3.draw(&window, t3);
		window.display(); // display!
	}
	return 0;
}