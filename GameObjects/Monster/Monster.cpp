
#include "Monster.h"


#include "Units/Units.h"

Monster::Monster(const sf::Texture &texture, int width,
                     int height, float x, float y,
                     b2World *World,
                     b2BodyType bodyType) {
    this->Texture = texture;
    this->width = width;
    this->height=height;
    this->x = x;
    this->y = y;
    b2BodyDef bodyDef;
    bodyDef.position = b2Vec2(
            Units::PixelsToMeters(x), Units::PixelsToMeters(y));
    bodyDef.type =bodyType;
    this->World = World;
    body = this->World->CreateBody(&bodyDef);
    std::string * kappa = new std::string("monster");
    body->SetUserData(kappa);
    b2PolygonShape Shape;
    Shape.SetAsBox((Units::PixelsToMeters(width-1)/2.f),
                   (Units::PixelsToMeters(height-1)/2.f));
    b2FixtureDef fixtureDef;
    fixtureDef.density = 1.f;
    fixtureDef.friction =0.60f;
    fixtureDef.shape =&Shape;
    body->CreateFixture(&fixtureDef);
    body->SetGravityScale(0);
}

void Monster::Rendering(Game *game) {
    sf::Sprite Sprite;
    Texture.setSmooth(true);
    Sprite.setTexture(Texture);
    Sprite.setOrigin(width/2.f,height/2.f);
    x=Units::MetersToPixels(body->GetPosition().x);
    y=Units::MetersToPixels(body->GetPosition().y);
    Sprite.setPosition(x,y);
    Sprite.setRotation(180/b2_pi *body->GetAngle());
    game->window.draw(Sprite);

}

void Monster::Kill() {
    body->GetWorld()->DestroyBody(body);
}
