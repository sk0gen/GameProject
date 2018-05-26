//
// Created by gawin on 17/05/2018.
//

#include "Bullet.h"
#include "Units/Units.h"

Bullet::Bullet(const sf::Texture &texture, int r, float x, float y,
               b2World *World,
               b2BodyType bodyType) {
    this->Texture = texture;
    this->r = r;
    this->x = x;
    this->y = y;

    b2BodyDef bodyDef;
    bodyDef.position = b2Vec2(
            Units::PixelsToMeters(x), Units::PixelsToMeters(y));
    bodyDef.type = bodyType;
   bodyDef.bullet = true;
    this->World = World;
    body = this->World->CreateBody(&bodyDef);
    b2CircleShape circle;
    circle.m_radius = Units::PixelsToMeters(r);
    circle.m_p.Set((Units::PixelsToMeters(r)) / 2.f, Units::PixelsToMeters(r) / 2.f);

    b2FixtureDef fixtureDef;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.60f;
    fixtureDef.shape = &circle;
    body->CreateFixture(&fixtureDef);
}

void Bullet::Rendering(Game *game) {
    sf::Sprite Sprite;
    Texture.setSmooth(true);
    Sprite.setTexture(Texture);
    Sprite.setOrigin(r/2.f, r/2.f);
    x = Units::MetersToPixels(body->GetPosition().x);
    y = Units::MetersToPixels(body->GetPosition().y);
    Sprite.setPosition(x, y);
    Sprite.setRotation(180 / b2_pi * body->GetAngle());
    game->window.draw(Sprite);

}

void Bullet::Kill() {
    body->GetWorld()->DestroyBody(body);
}

