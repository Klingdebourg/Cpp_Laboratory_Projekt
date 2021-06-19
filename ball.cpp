#include "ball.h"

Ball::Ball(int x, int y, int radius, QGraphicsItem* parent) :
  QGraphicsEllipseItem(parent)
{
    setRect(x,y,radius,radius);

/*

    bodyDefBall.type = b2_dynamicBody;
    bodyDefBall.position.Set(x, y*(-1));

    circle.m_p.Set(x, y);
    circle.m_radius = radius;

    fixtureDefBall.shape = &circle;
    fixtureDefBall.density = 100.0f;
    fixtureDefBall.friction = 0.3f;
*/

}
