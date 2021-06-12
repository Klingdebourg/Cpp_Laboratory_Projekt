#include "ball.h"


Ball::Ball() {
    //creates an ellipse with given size at origin in scene coordinates
    setRect(0, 0, BALL_DIAM, BALL_DIAM);
    //moves the transformation point to the middle of the circle
    setTransformOriginPoint(QPointF(BALL_DIAM/2, BALL_DIAM/2));


}
