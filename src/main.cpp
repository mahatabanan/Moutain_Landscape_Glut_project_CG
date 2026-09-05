#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>
#define PI 3.14159265358979323846
#define MAX_DROPS 1000

// Rain data arrays
float dropX[MAX_DROPS];
float dropY[MAX_DROPS];
int totalDrops = 0;
float rainGroundLevel = -2.0f;
bool isAnimating = true;
bool isDay = true;
bool manualDayNight = false;
float sunY = 1.8f;
float moonY = 0.45f;
float cloudX = 0.0f;
//float birdX = 0.0f;
//float birdY = 0.0f;
//float birdSpeed = 0.02f;
bool showBird = true;
bool birdMove = true;
float birdX1 = 0.0f;
//float birdX2 = 0.0f;
float birdSpeed1 = 0.05f;
//float birdSpeed2 = 0.05f;
float timeOfDay = 0.0f;
float _run3 = 0.0;
float cloudSpeed = 0.004f;
float daySpeed = 0.005f;
float rainSpeed  = 0.07f;
bool isRaining = false;
bool cloudMove = true;




void drawCircle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        glColor3ub(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x+xc,y+yc);
    }
    glEnd();
}


///SKY-obj1
void drawsky() {



if (isDay)
{
    glBegin(GL_POLYGON);
    glColor3ub(195,241,255);   //Day sky

glVertex2f(-2.0f,  2.0f);
glVertex2f( 2.0f,  2.0f);
glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);
    glEnd();
}
else
{
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);      //Night sky
glVertex2f(-2.0f,  2.0f);
glVertex2f( 2.0f,  2.0f);
glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);
    glEnd();
}

}


///CLOUD-obj2
void drawcloud()
{



if(isDay)
    {
        // Cloud 1
        drawCircle(0.12, -0.5 + _run3, 1.5, 255,255,255);
        drawCircle(0.15, -0.38 + _run3, 1.45, 255,255,255);
        drawCircle(0.12, -0.62 + _run3, 1.5, 255,255,255);
        drawCircle(0.15, -0.55 + _run3, 1.45, 255,255,255);

        // Cloud 2
        drawCircle(0.14, 0.5 + _run3, 1.5, 255,255,255);
        drawCircle(0.15, 0.38 + _run3, 1.45, 255,255,255);
        drawCircle(0.12, 0.62 + _run3, 1.5, 255,255,255);
        drawCircle(0.15, 0.55 + _run3, 1.45, 255,255,255);
    }

}

void drawsunmoon(){
    ///Sun obj3
if (isDay) {
    drawCircle(0.18f, 1.66f, sunY, 255, 230, 0); // radius, centerX, centerY, R,G,B
}


/// Moon obj4
if (!isDay) {
    drawCircle(0.18f, 1.66f, moonY, 255, 255, 255); // white moon
}
}

///GROUND1 obj5
void drawground(){

    glBegin(GL_POLYGON);
    if(isDay){
	glColor3ub(69, 173, 75);
	}
	else
        {
        glColor3ub(41, 135, 47);
	}

	glVertex2f(-0.7f,  -0.0f);
	glVertex2f(-2.0f,  -0.0f);
    glVertex2f(-2.0f,  -2.0f);
    glVertex2f(-0.7f,  -2.0f);

    glVertex2f(-0.5f,  -2.0f);
    glVertex2f(-0.28f,  -1.8f);
    glVertex2f(-0.7f,  -1.6f);
    glVertex2f(-0.7f,  -1.75f);
    glVertex2f(-0.3f,  -1.4f);
    glVertex2f(-0.3f,  -1.18f);

    glVertex2f(-0.7f,  -1.0f);


    glVertex2f(-0.7f,  -1.17f);
    glVertex2f(-0.24f,  -0.97f);
    glVertex2f(-0.7f,  -0.6f);
    glVertex2f(-0.7f,  -0.8f);
    glVertex2f(-0.38f,  -0.65f);
    glVertex2f(-0.7f,  -0.44f);

    glVertex2f(-0.7f,  -0.6f);
    glVertex2f(-0.3f,  -0.4f);
    glEnd();



   ///GROUND2
   glBegin(GL_POLYGON);
	if(isDay){
	glColor3ub(69, 173, 75);
	}
	else
        {
        glColor3ub(41, 135, 47);
	}

	glVertex2f(0.7f,  -0.0f);
	glVertex2f(2.0f,  -0.0f);
    glVertex2f(2.0f,  -2.0f);
    glVertex2f(0.7f,  -2.0f);

    glVertex2f(0.5f,  -2.0f);
    glVertex2f(0.28f,  -1.8f);
    glVertex2f(0.7f,  -1.6f);
    glVertex2f(0.7f,  -1.75f);
    glVertex2f(0.3f,  -1.4f);
    glVertex2f(0.3f,  -1.18f);

    glVertex2f(0.7f,  -1.0f);


    glVertex2f(0.7f,  -1.17f);
    glVertex2f(0.24f,  -0.97f);
    glVertex2f(0.7f,  -0.6f);
    glVertex2f(0.7f,  -0.8f);
    glVertex2f(0.38f,  -0.65f);
    glVertex2f(0.7f,  -0.44f);

    glVertex2f(0.7f,  -0.6f);
    glVertex2f(0.3f,  -0.4f);
    glEnd();

}
///mountain obj6
void drawmountain(){

///MOUNTAIN1
glBegin(GL_POLYGON);
glColor3ub(162,219,221);


glVertex2f(-2.0f, 0.20f);
glVertex2f(-1.7f, 0.35f);
glVertex2f(-1.4f, 0.50f);
glVertex2f(-1.1f, 0.65f);
glVertex2f(-0.8f, 0.80f);
glVertex2f(-0.5f, 1.3f);
glVertex2f(-0.2f, 0.85f);
glVertex2f( 0.1f, 0.75f);
glVertex2f( 0.4f, 0.85f);
glVertex2f( 0.7f, 1.00f);
glVertex2f( 1.0f, 0.85f);
glVertex2f( 1.3f, 1.370f);
glVertex2f( 1.6f, 0.55f);
glVertex2f( 1.9f, 0.40f);
glVertex2f( 2.0f, 0.35f);

glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);
glEnd();


///MOUNTAIN2
glBegin(GL_POLYGON);
glColor3ub(139,90,43);


glVertex2f(-2.0f, 0.05f);
glVertex2f(-1.6f, 0.30f);
glVertex2f(-1.2f, 0.55f);
glVertex2f(-0.8f, 0.90f);
glVertex2f(-0.4f, 1.20f);
glVertex2f( 0.0f, 0.95f);
glVertex2f( 0.4f, 0.80f);
glVertex2f( 0.8f, 1.05f);
glVertex2f( 1.2f, 1.30f);
glVertex2f( 1.6f, 0.95f);
glVertex2f( 2.0f, 0.65f);

glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);
glEnd();


///MOUNTAIN3
glBegin(GL_POLYGON);
glColor3ub(118,93,67);
glVertex2f(-2.0f, -0.10f);
glVertex2f(-1.7f,  0.20f);
glVertex2f(-1.3f,  0.45f);
glVertex2f(-0.9f,  0.75f);
glVertex2f(-0.5f,  1.05f);
glVertex2f(-0.1f,  0.80f);
glVertex2f( 0.3f,  0.60f);
glVertex2f( 0.7f,  0.85f);
glVertex2f( 1.1f,  1.10f);
glVertex2f( 1.5f,  0.80f);
glVertex2f( 1.9f,  0.50f);
glVertex2f( 2.0f,  0.40f);

glVertex2f( 2.0f, -0.2f);
glVertex2f(-2.0f, -0.2f);
glEnd();


}
void drawarchitecture(){
///wood obj 7
 glPushMatrix();
 glTranslatef(-2.1,-1.7,0);
 glScalef(0.2,0.2,0);
 glBegin(GL_POLYGON);
 glColor3ub(161, 98, 32);
 glVertex2f(2,0.5);
 glVertex2f(2.21,1.01);
 glVertex2f(2.28,1.53);
 glVertex2f(2.3,1.98);
 glVertex2f(2.84,2.49);
 glVertex2f(2.84,2.51);
 glVertex2f(2.86,1.99);
 glVertex2f(2.88,1.52);
 glVertex2f(2.94,1.01);
 glVertex2f(3.22,0.5);
 glVertex2f(1.5,0);
 glVertex2f(2.31,0);
 glVertex2f(2.68,0);
 glVertex2f(3.72,0);
 glVertex2f(3.22,0.5);
 glEnd();
 glPopMatrix();

 ///campfire obj8
if(!isRaining)
{


glColor3ub(255,140,0);

glBegin(GL_TRIANGLES);
glVertex2f(1.45,-1.95);
glVertex2f(1.50,-1.83);
glVertex2f(1.55,-1.95);

glVertex2f(1.47,-1.95);
glVertex2f(1.52,-1.85);
glVertex2f(1.57,-1.95);
glEnd();

glColor3ub(255,220,0);

glBegin(GL_POLYGON);
glVertex2f(1.48,-1.92);
glVertex2f(1.51,-1.89);
glVertex2f(1.54,-1.92);
glVertex2f(1.51,-1.95);
glEnd();


glColor3ub(120,70,20);

glBegin(GL_QUADS);
glVertex2f(1.42,-1.96);
glVertex2f(1.60,-1.96);
glVertex2f(1.60,-1.99);
glVertex2f(1.42,-1.99);
glEnd();


glBegin(GL_QUADS);
glVertex2f(1.44,-1.95);
glVertex2f(1.58,-2.01);
glVertex2f(1.60,-2.00);
glVertex2f(1.46,-1.94);
glEnd();


glBegin(GL_QUADS);
glVertex2f(1.44,-1.95);
glVertex2f(1.58,-2.01);
glVertex2f(1.60,-2.00);
glVertex2f(1.46,-1.94);
glEnd();


glColor3ub(255,200,50);

glBegin(GL_LINES);
glVertex2f(1.50,-1.83);
glVertex2f(1.50,-1.77);

glVertex2f(1.48,-1.84);
glVertex2f(1.46,-1.79);
glEnd();

}

 ///Tent obj9

 glBegin(GL_QUADS);
 glColor3ub(218,182,0);
 glVertex2f(1.7,-1.78);
 glVertex2f(1.84,-1.71);
 glVertex2f(1.73,-1.53);
 glVertex2f(1.58,-1.58);
 glEnd();

 glLineWidth(2.5);
 glBegin(GL_LINE_LOOP);
 glColor3ub(138,109,0);
 glVertex2f(1.7,-1.78);
 glVertex2f(1.84,-1.71);
 glVertex2f(1.73,-1.53);
 glVertex2f(1.58,-1.58);
 glEnd();


  glBegin(GL_QUADS);
 glColor3ub(218,182,0);
 glVertex2f(1.7,-1.78);
 glVertex2f(1.7,-1.81);
 glVertex2f(1.84,-1.74);
 glVertex2f(1.84,-1.71);
 glEnd();

  glBegin(GL_POLYGON);
 glColor3ub(218,182,0);
 glVertex2f(1.7,-1.81);
 glVertex2f(1.7,-1.78);
 glVertex2f(1.58,-1.58);
 glVertex2f(1.46,-1.76);
 glVertex2f(1.46,-1.8);
 glEnd();

  glBegin(GL_LINE_LOOP);
 glColor3ub(138,109,0);
 glVertex2f(1.7,-1.81);
 glVertex2f(1.7,-1.78);
 glVertex2f(1.58,-1.58);
 glVertex2f(1.46,-1.76);
 glVertex2f(1.46,-1.8);
 glEnd();

 glLineWidth(1.5);

 glBegin(GL_LINES);
 glColor3ub(0,0,0);
 glVertex2f(1.46,-1.76);
 glVertex2f(1.42,-1.82);
 glEnd();


  glBegin(GL_LINES);
 glColor3ub(138,109,0);
  glVertex2f(1.58,-1.58);
 glVertex2f(1.58,-1.81);
 glEnd();


  glBegin(GL_LINES);
 glColor3ub(0,0,0);
  glVertex2f(1.7,-1.78);
 glVertex2f(1.74,-1.84);
 glEnd();

   glBegin(GL_LINES);
 glColor3ub(0,0,0);
  glVertex2f(1.84,-1.71);
 glVertex2f(1.87,-1.76);
 glEnd();




 ///Wooden Bridge obj10

 glColor3f(0.55f, 0.35f, 0.15f);

    glLineWidth(18.0f);

    glBegin(GL_LINES);

        glVertex2f(-0.45f, -0.875f);
        glVertex2f(-0.15f, -0.775f);


        glVertex2f(-0.15f, -0.775f);
        glVertex2f( 0.15f, -0.775f);


        glVertex2f( 0.15f, -0.775f);
        glVertex2f( 0.45f, -0.875f);
    glEnd();

    glColor3f(0.45f, 0.25f, 0.10f);
    glLineWidth(6.0f);
    glBegin(GL_LINES);

        glVertex2f(-0.42f, -0.6f);
        glVertex2f(-0.42f, -0.82f);

        glVertex2f(-0.15f, -0.55f);
        glVertex2f(-0.15f, -0.75f);

        glVertex2f( 0.15f, -0.55f);
        glVertex2f( 0.15f, -0.75f);

        glVertex2f( 0.42f, -0.6f);
        glVertex2f( 0.42f, -0.82f);
    glEnd();

    // 3. HANDRAILS
    glColor3f(0.65f, 0.45f, 0.25f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        // Top Rail - Left Ramp
        glVertex2f(-0.42f, -0.65f);
        glVertex2f(-0.15f, -0.55f);
        // Top Rail - Middle Flat
        glVertex2f(-0.15f, -0.55f);
        glVertex2f( 0.15f, -0.55f);
        // Top Rail - Right Ramp
        glVertex2f( 0.15f, -0.55f);
        glVertex2f( 0.42f, -0.65f);

        // Mid Rail - Left Ramp
        glVertex2f(-0.42f, -0.75f);
        glVertex2f(-0.15f, -0.65f);
        // Mid Rail - Middle Flat
        glVertex2f(-0.15f, -0.65f);
        glVertex2f( 0.15f, -0.65f);
        // Mid Rail - Right Ramp
        glVertex2f( 0.15f, -0.65f);
        glVertex2f( 0.42f, -0.75f);
    glEnd();
}

///TREE 1 obj11
void drawtree(){
glBegin(GL_POLYGON);
glColor3ub(110,70,35);
glVertex2f(0.65f,-0.55f);
glVertex2f(0.68f,-0.55f);
glVertex2f(0.68f,-0.40f);
glVertex2f(0.65f,-0.40f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(40,120,60);
glVertex2f(0.55f,-0.40f);
glVertex2f(0.78f,-0.40f);
glVertex2f(0.67f,-0.15f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.58f,-0.25f);
glVertex2f(0.76f,-0.25f);
glVertex2f(0.67f, 0.00f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.61f,-0.10f);
glVertex2f(0.73f,-0.10f);
glVertex2f(0.67f, 0.15f);
glEnd();


///TREE 2
glBegin(GL_POLYGON);
glColor3ub(110,70,35);
glVertex2f(0.85f,-0.65f);
glVertex2f(0.89f,-0.65f);
glVertex2f(0.89f,-0.45f);
glVertex2f(0.85f,-0.45f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(38,118,58);
glVertex2f(0.72f,-0.45f);
glVertex2f(1.02f,-0.45f);
glVertex2f(0.87f,-0.10f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.75f,-0.25f);
glVertex2f(1.00f,-0.25f);
glVertex2f(0.87f, 0.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.78f,-0.05f);
glVertex2f(0.97f,-0.05f);
glVertex2f(0.87f, 0.25f);
glEnd();


///TREE 3
glBegin(GL_POLYGON);
glColor3ub(105,65,30);
glVertex2f(1.05f,-0.75f);
glVertex2f(1.10f,-0.75f);
glVertex2f(1.10f,-0.50f);
glVertex2f(1.05f,-0.50f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(35,115,55);
glVertex2f(0.85f,-0.50f);
glVertex2f(1.30f,-0.50f);
glVertex2f(1.08f,-0.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.90f,-0.25f);
glVertex2f(1.25f,-0.25f);
glVertex2f(1.08f, 0.20f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.95f,-0.05f);
glVertex2f(1.20f,-0.05f);
glVertex2f(1.08f, 0.45f);
glEnd();


///TREE 4
glBegin(GL_POLYGON);
glColor3ub(100,60,28);
glVertex2f(1.30f,-0.90f);
glVertex2f(1.38f,-0.90f);
glVertex2f(1.38f,-0.55f);
glVertex2f(1.30f,-0.55f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(30,110,50);
glVertex2f(1.00f,-0.55f);
glVertex2f(1.70f,-0.55f);
glVertex2f(1.34f, 0.15f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.08f,-0.20f);
glVertex2f(1.60f,-0.20f);
glVertex2f(1.34f, 0.45f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.15f, 0.05f);
glVertex2f(1.55f, 0.05f);
glVertex2f(1.34f, 0.75f);
glEnd();

///TREE 5 (smaller)
glBegin(GL_POLYGON);
glColor3ub(95,55,25);
glVertex2f(1.58f,-1.00f);
glVertex2f(1.64f,-1.00f);
glVertex2f(1.64f,-0.70f);
glVertex2f(1.58f,-0.70f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(25,105,48);
glVertex2f(1.35f,-0.70f);
glVertex2f(1.90f,-0.70f);
glVertex2f(1.61f,-0.35f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.40f,-0.50f);
glVertex2f(1.85f,-0.50f);
glVertex2f(1.61f,-0.15f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.45f,-0.30f);
glVertex2f(1.80f,-0.30f);
glVertex2f(1.61f, 0.05f);
glEnd();


///TREE 7
glBegin(GL_POLYGON);
glColor3ub(90,50,22);
glVertex2f(0.95f,-0.95f);
glVertex2f(1.00f,-0.95f);
glVertex2f(1.00f,-0.70f);
glVertex2f(0.95f,-0.70f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(18,95,40);
glVertex2f(0.80f,-0.70f);
glVertex2f(1.15f,-0.70f);
glVertex2f(0.98f,-0.40f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.85f,-0.55f);
glVertex2f(1.10f,-0.55f);
glVertex2f(0.98f,-0.20f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.90f,-0.35f);
glVertex2f(1.05f,-0.35f);
glVertex2f(0.98f, 0.00f);
glEnd();

///TREE 8
glColor3ub(85,45,20);
glVertex2f(1.15f,-0.95f);
glVertex2f(1.20f,-0.95f);
glVertex2f(1.20f,-0.70f);
glVertex2f(1.15f,-0.70f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(15,90,38);
glVertex2f(1.00f,-0.70f);
glVertex2f(1.35f,-0.70f);
glVertex2f(1.18f,-0.40f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.05f,-0.55f);
glVertex2f(1.30f,-0.55f);
glVertex2f(1.18f,-0.20f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.10f,-0.35f);
glVertex2f(1.25f,-0.35f);
glVertex2f(1.18f, 0.00f);
glEnd();


/// TREE 6
glBegin(GL_POLYGON);
glColor3ub(95,55,25);
glVertex2f(1.70f,-1.20f);
glVertex2f(1.76f,-1.20f);
glVertex2f(1.76f,-0.90f);
glVertex2f(1.70f,-0.90f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(20,100,45);
glVertex2f(1.45f,-0.90f);
glVertex2f(2.00f,-0.90f);
glVertex2f(1.73f,-0.55f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.50f,-0.75f);
glVertex2f(1.95f,-0.75f);
glVertex2f(1.73f,-0.40f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.55f,-0.60f);
glVertex2f(1.90f,-0.60f);
glVertex2f(1.73f,-0.20f);
glEnd();

/// FRONT TREE
glBegin(GL_POLYGON);
glColor3ub(95,55,25);
glVertex2f(0.85f,-1.20f);
glVertex2f(0.90f,-1.20f);
glVertex2f(0.90f,-0.95f);
glVertex2f(0.85f,-0.95f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(20,100,45);
glVertex2f(0.70f,-0.95f);
glVertex2f(1.05f,-0.95f);
glVertex2f(0.88f,-0.65f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.73f,-0.80f);
glVertex2f(1.02f,-0.80f);
glVertex2f(0.88f,-0.50f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.77f,-0.62f);
glVertex2f(0.98f,-0.62f);
glVertex2f(0.88f,-0.30f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(80,170,90);
glVertex2f(0.90f,-1.20f);
glVertex2f(0.95f,-1.20f);
glVertex2f(0.92f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.95f,-1.20f);
glVertex2f(1.00f,-1.20f);
glVertex2f(0.98f,-1.00f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.00f,-1.20f);
glVertex2f(1.05f,-1.20f);
glVertex2f(1.02f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(75,165,85);
glVertex2f(1.30f,-0.95f);
glVertex2f(1.35f,-0.95f);
glVertex2f(1.32f,-0.80f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.35f,-0.95f);
glVertex2f(1.40f,-0.95f);
glVertex2f(1.38f,-0.78f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(80,170,90);
glVertex2f(0.85f,-1.20f);
glVertex2f(0.90f,-1.20f);
glVertex2f(0.88f,-1.00f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.90f,-1.20f);
glVertex2f(0.95f,-1.20f);
glVertex2f(0.93f,-0.98f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(0.95f,-1.20f);
glVertex2f(1.00f,-1.20f);
glVertex2f(0.98f,-1.02f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(75,165,85);
glVertex2f(1.10f,-0.95f);
glVertex2f(1.15f,-0.95f);
glVertex2f(1.13f,-0.75f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.15f,-0.95f);
glVertex2f(1.20f,-0.95f);
glVertex2f(1.18f,-0.78f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.20f,-0.95f);
glVertex2f(1.25f,-0.95f);
glVertex2f(1.23f,-0.80f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(70,160,80);
glVertex2f(1.45f,-1.05f);
glVertex2f(1.50f,-1.05f);
glVertex2f(1.48f,-0.85f);
glEnd();

}
 ///flower
void drawflowergrass()
{


///FLOWRR obj12
glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.05f,-1.05f);
glVertex2f(1.05f,-0.95f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(255,220,70);
glVertex2f(1.03f,-0.95f);
glVertex2f(1.07f,-0.95f);
glVertex2f(1.05f,-0.90f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.30f,-1.00f);
glVertex2f(1.30f,-0.90f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(255,120,170);
glVertex2f(1.28f,-0.90f);
glVertex2f(1.32f,-0.90f);
glVertex2f(1.30f,-0.85f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(0.95f,-1.10f);
glVertex2f(0.95f,-1.00f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(245,245,245);
glVertex2f(0.93f,-1.00f);
glVertex2f(0.97f,-1.00f);
glVertex2f(0.95f,-0.95f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(95,185,105);
glVertex2f(1.65f,-1.30f);
glVertex2f(1.70f,-1.30f);
glVertex2f(1.68f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.70f,-1.30f);
glVertex2f(1.75f,-1.30f);
glVertex2f(1.73f,-1.00f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.75f,-1.30f);
glVertex2f(1.80f,-1.30f);
glVertex2f(1.78f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.80f,-1.30f);
glVertex2f(1.85f,-1.30f);
glVertex2f(1.83f,-1.00f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(80,170,90);
glVertex2f(1.72f,-1.30f);
glVertex2f(1.77f,-1.30f);
glVertex2f(1.75f,-0.95f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(1.82f,-1.30f);
glVertex2f(1.87f,-1.30f);
glVertex2f(1.85f,-0.92f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.74f,-1.20f);
glVertex2f(1.74f,-1.05f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255,220,70);
glVertex2f(1.72f,-1.05f);
glVertex2f(1.76f,-1.05f);
glVertex2f(1.74f,-1.00f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.90f,-1.18f);
glVertex2f(1.90f,-1.03f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(180,90,200);
glVertex2f(1.88f,-1.03f);
glVertex2f(1.92f,-1.03f);
glVertex2f(1.90f,-0.98f);
glEnd();


glBegin(GL_LINES);
glColor3ub(60,140,60);
glVertex2f(1.82f,-1.22f);
glVertex2f(1.82f,-1.07f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(255,130,170);
glVertex2f(1.80f,-1.07f);
glVertex2f(1.84f,-1.07f);
glVertex2f(1.82f,-1.02f);
glEnd();

///GRASS obj13
glColor3ub(70,160,80);

glBegin(GL_TRIANGLES);
glVertex2f(-2.00f,-0.85f);
glVertex2f(-1.95f,-0.85f);
glVertex2f(-1.97f,-0.65f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(-1.85f,-0.90f);
glVertex2f(-1.80f,-0.90f);
glVertex2f(-1.83f,-0.68f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(-1.70f,-0.88f);
glVertex2f(-1.65f,-0.88f);
glVertex2f(-1.68f,-0.65f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(-1.55f,-0.90f);
glVertex2f(-1.50f,-0.90f);
glVertex2f(-1.53f,-0.67f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(-1.40f,-0.92f);
glVertex2f(-1.35f,-0.92f);
glVertex2f(-1.38f,-0.68f);
glEnd();



/// BACK TREE
glBegin(GL_POLYGON);
glColor3ub(110,70,40);
glVertex2f(-1.65f,-1.05f);
glVertex2f(-1.58f,-1.05f);
glVertex2f(-1.58f,-0.75f);
glVertex2f(-1.65f,-0.75f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(50,150,90);

glVertex2f(-1.615f,-0.30f);
glVertex2f(-1.48f,-0.35f);
glVertex2f(-1.40f,-0.45f);
glVertex2f(-1.38f,-0.55f);
glVertex2f(-1.40f,-0.65f);
glVertex2f(-1.48f,-0.75f);
glVertex2f(-1.615f,-0.80f);
glVertex2f(-1.75f,-0.75f);
glVertex2f(-1.83f,-0.65f);
glVertex2f(-1.85f,-0.55f);
glVertex2f(-1.83f,-0.45f);
glVertex2f(-1.75f,-0.35f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(110,70,40);
glVertex2f(-1.95f,-0.95f);
glVertex2f(-1.89f,-0.95f);
glVertex2f(-1.89f,-0.75f);
glVertex2f(-1.95f,-0.75f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(50,150,90);


glVertex2f(-1.92f,-0.40f);
glVertex2f(-1.80f,-0.45f);
glVertex2f(-1.73f,-0.55f);
glVertex2f(-1.71f,-0.65f);
glVertex2f(-1.73f,-0.75f);
glVertex2f(-1.80f,-0.83f);
glVertex2f(-1.92f,-0.87f);
glVertex2f(-2.04f,-0.83f);
glVertex2f(-2.11f,-0.75f);
glVertex2f(-2.13f,-0.65f);
glVertex2f(-2.11f,-0.55f);
glVertex2f(-2.04f,-0.45f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(110,70,40);
glVertex2f(-1.20f,-1.20f);
glVertex2f(-1.10f,-1.20f);
glVertex2f(-1.10f,-0.65f);
glVertex2f(-1.20f,-0.65f);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(50,150,90);


glVertex2f(-1.15f, 0.00f);
glVertex2f(-0.95f,-0.05f);
glVertex2f(-0.80f,-0.20f);
glVertex2f(-0.75f,-0.35f);
glVertex2f(-0.80f,-0.50f);
glVertex2f(-0.95f,-0.65f);
glVertex2f(-1.15f,-0.70f);
glVertex2f(-1.35f,-0.65f);
glVertex2f(-1.50f,-0.50f);
glVertex2f(-1.55f,-0.35f);
glVertex2f(-1.50f,-0.20f);
glVertex2f(-1.35f,-0.05f);
glEnd();

///GRASS
  glBegin(GL_POLYGON);
glColor3ub(0, 102, 0);
glVertex2f(-1.89f, -1.30f);
glVertex2f(-1.86f, -1.25f);
glVertex2f(-1.84f, -0.95f);
glVertex2f(-1.87f, -1.15f);
glVertex2f(-1.89f, -1.30f);
glVertex2f(-1.92f, -1.25f);
glVertex2f(-1.94f, -0.95f);
glVertex2f(-1.91f, -1.15f);
glVertex2f(-1.89f, -1.30f);
glVertex2f(-1.88f, -1.15f);
glVertex2f(-1.89f, -0.95f);
glVertex2f(-1.90f, -1.15f);
glEnd();

glBegin(GL_POLYGON);        ///grass2
glColor3ub(0, 102, 0);
glVertex2f(-0.90f, -1.40f);
glVertex2f(-0.87f, -1.35f);
glVertex2f(-0.85f, -1.05f);
glVertex2f(-0.88f, -1.25f);
glVertex2f(-0.90f, -1.40f);
glVertex2f(-0.89f, -1.35f);
glVertex2f(-0.90f, -1.05f);
glVertex2f(-0.91f, -1.25f);
glVertex2f(-0.90f, -1.40f);
glVertex2f(-0.93f, -1.35f);
glVertex2f(-0.95f, -1.05f);
glVertex2f(-0.92f, -1.25f);
glEnd();

glBegin(GL_POLYGON);        ///grass3
glColor3ub(0, 102, 0);
glVertex2f(-0.60f, -1.30f);
glVertex2f(-0.57f, -1.25f);
glVertex2f(-0.55f, -0.95f);
glVertex2f(-0.58f, -1.15f);
glVertex2f(-0.60f, -1.30f);
glVertex2f(-0.59f, -1.25f);
glVertex2f(-0.60f, -0.95f);
glVertex2f(-0.61f, -1.15f);
glVertex2f(-0.60f, -1.30f);
glVertex2f(-0.63f, -1.25f);
glVertex2f(-0.65f, -0.95f);
glVertex2f(-0.62f, -1.15f);
glEnd();

glBegin(GL_POLYGON);        ///grass4
glColor3ub(0, 102, 0);
glVertex2f(-0.79f, -1.37f);
glVertex2f(-0.76f, -1.25f);
glVertex2f(-0.74f, -0.95f);
glVertex2f(-0.78f, -1.15f);
glVertex2f(-0.79f, -1.37f);
glVertex2f(-0.78f, -1.25f);
glVertex2f(-0.79f, -0.95f);
glVertex2f(-0.80f, -1.15f);
glVertex2f(-0.79f, -1.37f);
glVertex2f(-0.82f, -1.25f);
glVertex2f(-0.84f, -0.95f);
glVertex2f(-0.81f, -1.15f);
glEnd();

glBegin(GL_POLYGON);        ///grass5
glColor3ub(0, 102, 0);
glVertex2f(-0.69f, -1.33f);
glVertex2f(-0.66f, -1.25f);
glVertex2f(-0.64f, -0.95f);
glVertex2f(-0.68f, -1.15f);
glVertex2f(-0.69f, -1.33f);
glVertex2f(-0.68f, -1.25f);
glVertex2f(-0.69f, -0.95f);
glVertex2f(-0.70f, -1.15f);
glVertex2f(-0.69f, -1.33f);
glVertex2f(-0.72f, -1.25f);
glVertex2f(-0.74f, -0.95f);
glVertex2f(-0.71f, -1.15f);
glEnd();


}

void drawbird()
{



///BIRD1 obj14

if (isDay && showBird)
{
    glPushMatrix();
    glTranslatef(birdX1, 0.0f, 0.0f);

  glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2f(-1.8f, 1.55f);
    glVertex2f(-1.7f, 1.65f);
    glVertex2f(-1.95f,1.63f);
    glVertex2f(-1.9f, 1.53f);
    glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f(-1.78f, 1.641f);
glVertex2f(-1.88f, 1.80f);
glVertex2f(-1.85f, 1.639f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f(-1.78f, 1.641f);
glVertex2f(-1.91f, 1.75f);
glVertex2f(-1.87f, 1.639f);
glEnd();


glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.74f, 1.635f);
glEnd();


///BIRD2
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.5f,  1.35f);
glVertex2f(-1.4f,  1.45f);
glVertex2f(-1.65f, 1.43f);
glVertex2f(-1.6f,  1.33f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f(-1.48f, 1.441f);
glVertex2f(-1.58f, 1.60f);
glVertex2f(-1.55f, 1.439f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f(-1.48f, 1.441f);
glVertex2f(-1.61f, 1.55f);
glVertex2f(-1.57f, 1.439f);
glEnd();


glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.44f, 1.435f);
glEnd();

///BIRD3
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.2f,  1.50f);
glVertex2f(-1.1f,  1.60f);
glVertex2f(-1.35f, 1.58f);
glVertex2f(-1.30f, 1.48f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f(-1.18f, 1.591f);
glVertex2f(-1.28f, 1.75f);
glVertex2f(-1.25f, 1.589f);
glEnd();


glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f(-1.18f, 1.591f);
glVertex2f(-1.31f, 1.70f);
glVertex2f(-1.27f, 1.589f);
glEnd();


glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-1.14f, 1.575f);
glEnd();


glPopMatrix();
}

}
///Star obj 15



void drawstar(){
    if(!isDay){
glPointSize(2.5f);
glBegin(GL_POINTS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.7f, 1.8f);
glVertex2f(-1.2f, 1.6f);
glVertex2f(-0.8f, 1.9f);
glVertex2f(-0.2f, 1.7f);
glVertex2f(0.4f, 1.85f);
glVertex2f(0.9f, 1.65f);
glVertex2f(1.3f, 1.9f);
glVertex2f(1.9f, 1.75f);
glVertex2f(2.4f, 1.85f);
glVertex2f(-1.0f, 1.85f);
glVertex2f(-1.8f, -1.2f);
glVertex2f(-1.5f, -1.6f);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-1.1f, 1.5f);
glVertex2f(0.5f, 1.75f);
glEnd();
}


}

  ///rains obj 16
void drawRaindrops() {
    // If there are no drops, skip drawing entirely
    if (totalDrops == 0) return;

    glColor3ub(196, 211, 223); // Blue color
    glLineWidth(1.5);
    glBegin(GL_LINES);
    for (int i = 0; i < totalDrops; i++) {
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 0.05f); // 0.05f is the length of the drop
    }
    glEnd();
}


void timer(int value) ///A1
{
    if (isAnimating) {
        glutTimerFunc(50, timer, 0);
        return;
    }

    if (!manualDayNight) {
        if (isDay)
        {
            sunY -= 0.015f;
            if (sunY <0.45f) {
                isDay = false;
                moonY = 0.45f;
            }
        }
        else
        {
            moonY += 0.015f;
            if (moonY > 1.78f) {
                isDay = true;
                sunY = 1.8f;
            }
        }
    } else {

        timeOfDay += daySpeed;

        if(timeOfDay >= 1.0f)
            timeOfDay = 0.0f;

        if(timeOfDay < 0.5f)
            isDay = true;
        else
            isDay = false;
    }

    if (birdMove && isDay)
    {
        birdX1 += birdSpeed1;


        if (birdX1 > 4.0f)
            birdX1 = -4.0f;

    }
    if(cloudMove && isDay)
    {
        _run3 += 0.04f;
        if(_run3 > 2.5f) _run3 = -2.5f;
    }


    for (int i = 0; i < totalDrops; i++) {
        dropY[i] -= rainSpeed;

        if (dropY[i] <= rainGroundLevel) {

            for (int j = i; j < totalDrops - 1; j++) {
                dropX[j] = dropX[j + 1];
                dropY[j] = dropY[j + 1];
            }
            totalDrops--;
            i--;
        }
    }


    if (isRaining && isDay) {

        for (int i = 0; i < 5; i++) {
            if (totalDrops < MAX_DROPS) {

                dropX[totalDrops] = -2.0f + static_cast<float>(rand()) / (RAND_MAX / 4.0f);
                dropY[totalDrops] = 2.0f;
                totalDrops++;
            }
        }
    }


    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}

void keyboard(unsigned char key, int x, int y) ///A2
{

    if (key == ' ') {
        isAnimating = !isAnimating;
    }

    if (key == 'n' || key == 'N') {

        isDay = !isDay;

        if (isDay) {
            sunY = 1.8f;
            moonY = -0.45f;
            birdMove = true;
        }
        else {
            sunY = -0.45f;
            moonY = 1.8f;
            birdMove = true;
        }
    }

    if (key == 'r' || key == 'R') {
        isRaining = !isRaining;
    }

    if (key == 'c' || key == 'C') {
        cloudMove = !cloudMove;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) ///A3
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        birdMove = !birdMove;


    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        rainSpeed+=.02f;
    }

    glutPostRedisplay();
}
void display()
{
    glClearColor(0.094f, 0.302f, 0.447f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawsky();
    drawstar();
    drawsunmoon();
    drawmountain();
    drawcloud();
    drawbird();
    drawground();
    drawtree();
    drawflowergrass();
    drawarchitecture();
    drawRaindrops();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mountain by Anan");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc(50, timer, 0);
    glutMainLoop();

    return 0;
}
