#include "ball.h"

Ball::Ball(int x, int y, int radius)
{
    setRect(x,y,radius,radius);



    b2BodyDef bodyDefBall;
    bodyDefBall.type = b2_dynamicBody;
    bodyDefBall.position.Set(x, y*(-1));
    b2CircleShape circle;
    circle.m_p.Set(x, y);
    circle.m_radius = radius;

    b2FixtureDef fixtureDefBall;
    fixtureDefBall.shape = &circle;
    fixtureDefBall.density = 100.0f;
    fixtureDefBall.friction = 0.3f;


}
