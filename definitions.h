#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//parameters for the different objects
#define WINDOW_W 1600
#define WINDOW_H 1000
#define BALL_DIAM 50
#define BALKEN_WIDTH 40
#define BALKEN_LENGTH_DEFAULT 300
#define FEDER_WIDTH 20
#define FEDER_HEIGHT 100
#define FOEHN_WIDTH 100
#define MASKE_WIDTH 60
#define VIRUS_DIAM 80

#define ABBRUCHZEIT 1000

//scaling between box2d world and qt scene
#define SCALING 1000.0f

//parameters for the world
#define GRAVITY -10.0f

//Box2D Prarameters for the ball
#define BALL_DENSITY 0.00000000001f
#define BALL_FRICTION 0.3f
#define BALL_RESTITUTION 0.9f

//Paramters required for steps of the box2d world
#define TIME_STEP 1.0f/60
#define VEL_ITER 10
#define POS_ITER 8

#endif // DEFINITIONS_H
