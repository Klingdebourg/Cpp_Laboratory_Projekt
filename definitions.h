#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define WINDOW_W 1600
#define WINDOW_H 1000
#define BALL_DIAM 70
#define BALKEN_WIDTH 40
#define FEDER_WIDTH 20
#define FEDER_HEIGHT 100
#define FOEHN_BREITE 100
#define MASKE_BREITE 60
#define VIRUS_RADIUS 80
#define Abbruchzeit 1000

//scaling between box2d world and qt scene
#define SCALING 1000.0f

//Box2D Prarameters for the ball
#define BALL_DENSITY 100
#define BALL_FRICTION 0.3f
#define BALL_RESTITUTION 0.9f

//Paramters required for steps of the box2d world
#define TIME_STEP 1.0f/60
#define VEL_ITER 10
#define POS_ITER 8

#endif // DEFINITIONS_H
