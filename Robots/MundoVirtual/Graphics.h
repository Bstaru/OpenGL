#ifndef _GRR
#define _GRR

#include <windows.h>
#include <windowsx.h>
#include <gl\GLU.h>
#include <gl\GL.h>
#include "glext.h"

class Camara{
public:
	GLfloat poscx,poscy,poscz,dircx,dircy,dircz;

	Camara(){
	}	

	void CamaraUpdate()
	{
		gluLookAt(poscx, poscy, poscz,
			dircx, dircy, dircz, 
			0, 1, 0);
	}
};

class Graph: public Camara
{
public:	

	GLfloat angulo, paso, paso2;
	GLfloat x, y, z, cRed, cGreen, cBlue;
	GLint estado;

	Graph(HWND hWnd)
	{
		poscx = 0;
		poscy = 10;
		poscz = 210;

		dircx = 0;
		dircy = 0;
		dircz = 0;
		angulo = 0;

		estado = 1;
		angulo = 0.0f;
		paso = 0;
		paso2 = 0;

		x = 0; y= 0; z=0; cRed=0; cGreen=0; cBlue=0;

		glShadeModel(GL_SMOOTH);

		//habilitamos el control de profundidad en el render
		glEnable(GL_DEPTH_TEST);

		//habilitamos la iluminacion
		glEnable(GL_LIGHTING);

		// habilitamos la luz 0 o primer luz
		glEnable(GL_LIGHT0);

		//habilitamos la forma de reflejar la luz
		glEnable(GL_COLOR_MATERIAL);		
	}

//Rainbow lel--------------------------------------------------------------------	
	void PisosColores(){
		//pisos colores

		glColor3f(30,0,0); //rojo
		glBegin(GL_QUADS);
		glVertex3f(-100.0f,-9.8f,-100.0f);
			glVertex3f(-80.0f,-9.8f,-100.0f);
			glVertex3f(-80.0f,-9.8f,-80.0f);
			glVertex3f(-100.0f,-9.8f,-80.0f);
		glEnd();

		glColor3f(255, 1, 0); //naranja
		glBegin(GL_QUADS);
		glVertex3f(-80.0f,-9.8f,-100.0f);
			glVertex3f(-60.0f,-9.8f,-100.0f);
			glVertex3f(-60.0f,-9.8f,-80.0f);
			glVertex3f(-80.0f,-9.8f,-80.0f);
		glEnd();

		glColor3f(5,5,0);//amarillo
		glBegin(GL_QUADS);
		glVertex3f(-60.0f,-9.8f,-100.0f);
			glVertex3f(-40.0f,-9.8f,-100.0f);
			glVertex3f(-40.0f,-9.8f,-80.0f);
			glVertex3f(-60.0f,-9.8f,-80.0f);
		glEnd();

		glColor3f(0,40,0.4f);//verde
		glBegin(GL_QUADS);
		glVertex3f(-40.0f,-9.8f,-100.0f);
			glVertex3f(-20.0f,-9.8f,-100.0f);
			glVertex3f(-20.0f,-9.8f,-80.0f);
			glVertex3f(-40.0f,-9.8f,-80.0f);
		glEnd();

		glColor3f(0,48,50);//Azul fuerte
		glBegin(GL_QUADS);
		glVertex3f(-20.0f,-9.8f,-100.0f);
			glVertex3f(0.0f,-9.8f,-100.0f);
			glVertex3f(0.0f,-9.8f,-80.0f);
			glVertex3f(-20.0f,-9.8f,-80.0f);
		glEnd();

		glColor3f(255,0,0);//...
		glBegin(GL_QUADS);
		glVertex3f(100.0f,-9.8f,-100.0f);
			glVertex3f(80.0f,-9.8f,-100.0f);
			glVertex3f(80.0f,-9.8f,-80.0f);
			glVertex3f(100.0f,-9.8f,-80.0f);
		glEnd();

		glColor3f( 255, 0, 255);//rosa
		glBegin(GL_QUADS);
		glVertex3f(80.0f,-9.8f,-100.0f);
			glVertex3f(60.0f,-9.8f,-100.0f);
			glVertex3f(60.0f,-9.8f,-80.0f);
			glVertex3f(80.0f,-9.8f,-80.0f);
		glEnd();

		glColor3f(2,0,255);//morado 
		glBegin(GL_QUADS);
		glVertex3f(60.0f,-9.8f,-100.0f);
			glVertex3f(40.0f,-9.8f,-100.0f);
			glVertex3f(40.0f,-9.8f,-80.0f);
			glVertex3f(60.0f,-9.8f,-80.0f);
		glEnd();

		glColor3f(0.5,0,1);//agua
		glBegin(GL_QUADS);
		glVertex3f(40.0f,-9.8f,-100.0f);
			glVertex3f(20.0f,-9.8f,-100.0f);
			glVertex3f(20.0f,-9.8f,-80.0f);
			glVertex3f(40.0f,-9.8f,-80.0f);
		glEnd();

		glColor3f(0,0,6);//Azul
		glBegin(GL_QUADS);
		glVertex3f(20.0f,-9.8f,-100.0f);
			glVertex3f(0.0f,-9.8f,-100.0f);
			glVertex3f(0.0f,-9.8f,-80.0f);
			glVertex3f(20.0f,-9.8f,-80.0f);
		glEnd();

}
//Nyan Cat------------------------------------------------------------------------
	void cuerpoG(float xPos, float yPos, float zPos){
	
	glPushMatrix();

		glTranslatef(xPos, yPos, zPos);
		glScalef(3.3f, 2.0f, 1.0f);	
		glColor3f(20, 2.5f, 0);
		glutSolidCube(10);
		glPopMatrix();}
	void cuerpoG2(float xPos, float yPos, float zPos){
	
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(2.7f, 1.5f, 0.3f);	
		glColor3f(5, 1, 40);
		glutSolidCube(10);
		glPopMatrix();
	}
	void puntos(float xPos, float yPos, float zPos){
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(1, 1.0f, 0.3f);	
		glColor3f(5, 0, 3);
		glutSolidCube(1.5f);
	glPopMatrix();
	}
	void cabeza(float xPos, float yPos, float zPos){
	
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(0.9f, 0.5f, 0.4f);	
		glColor3f(0.7f,0.7f,0.7f);
		glutSolidCube(20);
	glPopMatrix();
	}
	void pies(float xPos, float yPos, float zPos){
	
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(1.0f, 1.0f, 1.0f);	
		glColor3f(0.7f,0.7f,0.7f);
		glutSolidCube(5);
	glPopMatrix();

	}
	void orejas(float xPos, float yPos, float zPos){
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glRotatef(-90,1,0,0);
		glColor3f(0.4f,0.4f,0.4f);
		glutSolidCone(3.0f,3.5f,32,32);
	glPopMatrix();
	
	}
	void cola(float xPos, float yPos, float zPos){
	
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(0.2f, 0.2f, 0.2f);	
		glColor3f(0.3f,0.3f,0.3f);
		glutSolidCube(20);
	glPopMatrix();

	}
	void ojos1(float xPos, float yPos, float zPos){
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(2.2f, 2.2f, 2.2f);	
		glColor3f(0,0,0);
		glutSolidCube(1);
		glPopMatrix();}
	void ojos2(float xPos, float yPos, float zPos){

	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glColor3f(20,20,20);
		glutSolidCube(1);
	glPopMatrix();
	}
	void boca1(float xPos, float yPos, float zPos){
	

	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
		glScalef(9, 1.0f, 2.2f);	
		glColor3f(0,0,0);
		glutSolidCube(1);
		glPopMatrix();}
	void boca2(float xPos, float yPos, float zPos){
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(1, 1, 2.2f);	
		glColor3f(0,0,0);
		glutSolidCube(1);
		glPopMatrix();}
	void nariz(float xPos, float yPos, float zPos){
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(1, 1, 2.2f);	
		glColor3f(0,0,0);
		glutSolidCube(1);
		glPopMatrix();}
	void chapas(float xPos, float yPos, float zPos){
	glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(1, 1, 2.2f);	
		glColor3f(5,1,2);
		glutSolidCube(2.8f);
		glPopMatrix();}

	void AIR(float xPos, float yPos, float zPos){

		glColor3f(255,0,0); 
		glBegin(GL_QUADS);
			
			glVertex3f(-80.0f,13.0f,-3.0f);
			glVertex3f(-80.0f,10.0f,-3.0f);
			glVertex3f(-30.0f,10.0f,-3.0f);
			glVertex3f(-30.0f,13.0f,-3.0f);
			
		glEnd();
	}
	void AIN(float xPos, float yPos, float zPos){

		glColor3f(255, 1, 0);
		glBegin(GL_QUADS);
			
			glVertex3f(-80.0f,10.0f,-3.0f);
			glVertex3f(-80.0f,7.0f,-3.0f);
			glVertex3f(-30.0f,7.0f,-3.0f);
			glVertex3f(-30.0f,10.0f,-3.0f);
			
		glEnd();
	}
	void AIA(float xPos, float yPos, float zPos){

		glColor3f(5,5,0);
		glBegin(GL_QUADS);
			
		glVertex3f(-80.0f,7.0f,-3.0f);	
		glVertex3f(-80.0f,4.0f,-3.0f);
			
			glVertex3f(-30.0f,4.0f,-3.0f);
			glVertex3f(-30.0f,7.0f,-3.0f);
			
		glEnd();
	}
	void AIV(float xPos, float yPos, float zPos){

		glColor3f(0,40,0.4f);
		glBegin(GL_QUADS);
			
			
			glVertex3f(-80.0f,4.0f,-3.0f);
			glVertex3f(-80.0f,1.0f,-3.0f);
			glVertex3f(-30.0f,1.0f,-3.0f);
			glVertex3f(-30.0f,4.0f,-3.0f);
			
		glEnd();
	}
	void AIAz(float xPos, float yPos, float zPos){

	glColor3f(0,48,50);
		glBegin(GL_QUADS);
			
			
			glVertex3f(-80.0f,1.0f,-3.0f);
			glVertex3f(-80.0f,-2.0f,-3.0f);
			glVertex3f(-30.0f,-2.0f,-3.0f);
			glVertex3f(-30.0f,1.0f,-3.0f);
			
		glEnd();
	}
	void AIAzF(float xPos, float yPos, float zPos){

	glColor3f(0,0,6);
		glBegin(GL_QUADS);
			
			
			glVertex3f(-80.0f,-2.0f,-3.0f);
			glVertex3f(-80.0f,-5.0f,-3.0f);
			glVertex3f(-30.0f,-5.0f,-3.0f);
			glVertex3f(-30.0f,-2.0f,-3.0f);
			
		glEnd();
	}

//Estrellas blancas del fondo------------------------------------------------
	void lal(float xPos, float yPos, float zPos){
		glTranslatef(xPos, yPos, zPos);
		glColor3f(10,10,10);
		glutSolidSphere(3,32,32);
	}
	void estreshas(float xPos, float yPos, float zPos){
	
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
		lal(-80.0f, 30.0f, -200.0f);
		lal(-30.0f, 50.0f, -200.0f);
		lal(-60.0f, 40.0f, -200.0f);
		lal(80.0f, 20.0f, -200.0f);
		glPopMatrix();
	
	}
	void stars(){
		glPushMatrix();
		glTranslatef(50,50,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(100,-5,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-60,-100,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(150,-5,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-50,53,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(10,60,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-4,-10,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(150,30,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-150,30,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(250,30,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(350,50,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(450,50,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-450,60,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(400,20,20);
		estreshas(10.0f, 10.0f, 0.0f);
		glPopMatrix();
	}

//Hongos de mario jaja--------------------------------------------------------
	void Hongo(float xPos, float yPos, float zPos){

		glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(2.7f,2,1);
		glColor3f(10,0,0);
		glutSolidSphere(10,32,32);
		glPopMatrix();
	}
	void hongomanchas(float xPos, float yPos, float zPos){
		glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(2.4f,2,1);
		glColor3f(10,10,10);
		glutSolidSphere(3.5f,32,32);
		glPopMatrix();}
	void hongolel(float xPos, float yPos, float zPos){
		glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(1.7f,1.3f,1);
		glColor3f(1,1,0.3f);
		glutSolidSphere(10.0f,32,32);
		glPopMatrix();}
	void hongoojos(float xPos, float yPos, float zPos){
		glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
		glScalef(1.0f,3.0f,1);
		glColor3f(0,0,0);
		glutSolidSphere(2.0f,32,32);
		glPopMatrix();}
//Estrellas de mario :3------------------------------------------------------
	void Estreshita(){
		glPushMatrix();	
		glScalef(3.0f,3.0f,3.0f);
			glColor3f(5,5,0);
			
			glBegin(GL_POLYGON);
			
			glVertex3f(-2,-1,0);
			glVertex3f(-5,1,0);
			glVertex3f(-1.5,1,0);
			glVertex3f(0,5,0);
			glVertex3f(1.5,1,0);
			glVertex3f(5,1,0);
			glVertex3f(2,-1,0);
			glVertex3f(4,-5,0);
			glVertex3f(0,-2.5f,0);
			glVertex3f(-4,-5,0);

			glEnd();
		glPopMatrix();
	}
	void ojoRIGHT()
	{
		//ojo derecho
		glPushMatrix();
			glScalef(1,2,1);
			glTranslatef(-3,-0.5,0);
			glColor3f(0,0,0);
			glBegin(GL_QUADS);
			glVertex3f(1,1.5,1);
			glVertex3f(-1,1.5,1);
			glVertex3f(-1,-1.5,1);
			glVertex3f(1,-1.5,1);
			glEnd();
		glPopMatrix();
	}
	void ojoLEFT()
	{
		//ojo derecho
		glPushMatrix();
			glScalef(1,2,1);
			glColor3f(0,0,0);
			glTranslatef(3,-0.5,0);
			glBegin(GL_QUADS);
			glVertex3f(1,1.5,1);
			glVertex3f(-1,1.5,1);
			glVertex3f(-1,-1.5,1);
			glVertex3f(1,-1.5,1);
			glEnd();
		glPopMatrix();
	}
	void StarMario()	{
		glPushMatrix();
		glTranslatef(paso*2,0,0);
		glRotatef(paso*10,0,0,1);
		glScalef(1.5f,1.5f,1.5f);
		Estreshita();
		ojoRIGHT();
		ojoLEFT();
		glPopMatrix();
	}
//Paisaje :'D-----------------------------------------------------------------
	void Montania(float xPos, float yPos, float zPos){
	
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glScalef(6,6,6);
	glRotatef(-90,1,0,0);
	glColor3f(cRed*1.0f,cGreen*0.8f,cBlue*0.2f);
	glutSolidCone(10,20,32,32);
	glPopMatrix();
	
	}
	void Edificio(float xPos, float yPos, float zPos){
		glPushMatrix();
		glTranslatef(xPos, yPos, zPos);
			Ven();
			glTranslatef(40,-90,20);
			glScalef(1,3,1);
			glColor3f(cRed*2, 0, cBlue*2);
			//glColor3f(1,1,1);
			glutSolidCube(20);
		glPopMatrix();
	
	}
	void Ventanas(){
	
	glColor3f(10,10,10);
		glBegin(GL_QUADS); //v1
			glVertex3f(-9,2,0);
			glVertex3f(-6,2,0);
			glVertex3f(-6,-2,0);
			glVertex3f(-9,-2,0);
		glEnd();

		glBegin(GL_QUADS); //v2
			glVertex3f(-4,2,0);
			glVertex3f(-1,2,0);
			glVertex3f(-1,-2,0);
			glVertex3f(-4,-2,0);
		glEnd();

		glBegin(GL_QUADS); //v3
			glVertex3f(1,2,0);
			glVertex3f(4,2,0);
			glVertex3f(4,-2,0);
			glVertex3f(1,-2,0);
		glEnd();

		glBegin(GL_QUADS); //v4
			glVertex3f(6,2,0);
			glVertex3f(9,2,0);
			glVertex3f(9,-2,0);
			glVertex3f(6,-2,0);
		glEnd();
	
	
	}
	void Ven(){
	glPushMatrix();
			glTranslatef(40,-65,31);
			Ventanas();
			glPopMatrix();

				glPushMatrix();
			glTranslatef(40,-71,31);
			Ventanas();
			glPopMatrix();

				glPushMatrix();
			glTranslatef(40,-77,31);
			Ventanas();
			glPopMatrix();

				glPushMatrix();
			glTranslatef(40,-83,31);
			Ventanas();
			glPopMatrix();

				glPushMatrix();
			glTranslatef(40,-89,31);
			Ventanas();
			glPopMatrix();

				glPushMatrix();
			glTranslatef(40,-95,31);
			Ventanas();
			glPopMatrix();}
//Intento de EXO--------------------------------------------------------------
	void rombo(){
	glPushMatrix();	
		glScalef(4.0f,4.0f,4.0f);
			glColor3f(cRed*2,cGreen*2,cBlue*2);
			
			glBegin(GL_POLYGON);
			
			glVertex3f(1.5,2.5,0);
			glVertex3f(2.5,0,0);
			glVertex3f(1.5,-2.5,0);
			glVertex3f(0.5,0,0);
			
		glEnd();
		glPopMatrix();
	
	}
	void triangulo(){
	glPushMatrix();	
		glScalef(4.0f,4.0f,4.0f);
			glColor3f(cRed*2,cGreen*2,cBlue*2);
			
			glBegin(GL_POLYGON);
			
			glVertex3f(0,0.3f,0);
			glVertex3f(1,3,0);
			glVertex3f(-1,3,0);
			
		glEnd();
		glPopMatrix();
	
	}
	void triangulo2(){
	glPushMatrix();	
		glScalef(4.0f,4.0f,4.0f);
			glColor3f(cRed*2,cGreen*2,cBlue*2);

			glBegin(GL_POLYGON);
			
			glVertex3f(-1.5,2.5,0);
			glVertex3f(-2.5,0.3f,0);

			glVertex3f(-0.7f,0.3f,0);
			glVertex3f(-1.3f,0,0);
			glVertex3f(-0.5f,0,0);

			glVertex3f(-0.5f,0.3f,0); 
			
			
		glEnd();
		glPopMatrix();
	
	}
	void triangulo3(){
	glPushMatrix();	
		glScalef(4.0f,4.0f,4.0f);
			glColor3f(cRed*2,cGreen*2,cBlue*2);
			
			glBegin(GL_POLYGON);
			
			glVertex3f(0,-0.3f,0);
			glVertex3f(1,-3,0);
			glVertex3f(-1,-3,0);
			
		glEnd();
		glPopMatrix();
	}
	void triangulo4(){
	glPushMatrix();	
		glScalef(4.0f,4.0f,4.0f);
			glColor3f(cRed*2,cGreen*2,cBlue*2);
			
			glBegin(GL_POLYGON);
			
			glVertex3f(-1.5,-2.5f,0);
			glVertex3f(-2.5,-0.3f,0);

			glVertex3f(-0.7f,-0.3f,0);
			glVertex3f(-1.3f,0,0);
			glVertex3f(-0.5f,0,0);

			glVertex3f(-0.5f,-0.3f,0); 
			
		glEnd();
		glPopMatrix();
	
	}

//Funciones donde se junta las cosas jaja -------------------------------------
	void NyanCat(){

		glPushMatrix();

		ojos2(-400,1.7f, 6); //--
		ojos2(-4,1.7f, 6); //--
		ojos2(4.3f,1.7f, 6);//--
		boca1(0.5f,-3, 5);//--
		boca2(0.5f,-2, 5);//--
		boca2(4.5f,-2, 5);//--
		boca2(-3.5f,-2, 5);//--
		nariz(2.5f,0, 5);//--
		ojos1(-3.5f,1, 5);
		ojos1(4.7f,1, 5);
		cuerpoG(-14.0f,3.5f,-5.5f);
		cuerpoG2(-13,3,1);
		puntos(-13,3,5);
		puntos(-10,2,5);
		puntos(-20,2,5);
		puntos(-20,6,5);
		puntos(-18,-2,5);
		puntos(-10,5,5);
		cabeza(0, 0, 2);
		pies(-5,-5,1);
		pies(5,-5,1);
		pies(-20,-5,0);
		pies(-30,-5,0);
		orejas(-5.9f,4.8f,5);
		orejas(5.9f,4.8f,5);
		cola(-31, 2, 0);
		cola(-33, 5, 0);
		cola(-35, 8, 0);
		chapas(7.5f,-2, 5);
		chapas(-7.5f,-2, 5);
		AIR(0,0,0);
		AIN(0,0,0);
		AIA(0,0,0);
		AIV(0,0,0);
		AIAz(0,0,0);
		AIAzF(0,0,0);

		glPopMatrix();
	
	}
	void NyanBig(){
		glPushMatrix();
		glTranslatef(-150,1,50);
		glTranslatef(20 + (4 * paso), -1, 15);
		NyanCat();
		glPopMatrix();}

	void Honguis(){
	glPushMatrix();
		
	glTranslatef(0.0f, 0.0f, 0.0f);
		Hongo(40,30,-5);
		hongomanchas(43,42,3);
		hongomanchas(24,25,3);
		hongomanchas(58,25,3);
		hongolel(40,10,-5);
		hongoojos(35,10,5);
		hongoojos(50,10,5);

	glPopMatrix();
	}
	void Hongues(){
		glPushMatrix();
		glScalef(1,1,1);
		glTranslatef(-50,30,-200);
		glTranslatef(20 + (1 * paso), -1, 15);
		glRotatef(paso*15,0,0,5);
		Honguis();
		glPopMatrix();
		
		glPushMatrix();
		glScalef(1,1,1);
		glTranslatef(-250,50,-100);
		Honguis();
		glPopMatrix();

		glPushMatrix();
		glRotatef(-25,0,1,0);
		glScalef(0.5,0.5,0.5);
		glTranslatef(220,-60+(angulo*2),-150);
		Honguis();
		glPopMatrix();
	}
	void StarMario2(){
	
		glPushMatrix();
		glTranslatef(paso*2,0,0);
		glRotatef(paso*10,0,0,1);
		glScalef(1.5f,1.5f,1.5f);
		Estreshita();
		ojoRIGHT();
		ojoLEFT();
		glPopMatrix();

		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glTranslatef(-50.0f,-130.0f,-10.0f);
		StarMario();
		glPopMatrix();

		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glTranslatef(20.0f,220.0, 50.0f);
		StarMario();
		glPopMatrix();
		
		glPushMatrix();
		glScalef(0.3,0.3,0.3);
		glTranslatef(-300.0f,250.0f,70.0f);
		StarMario();
		glPopMatrix();
	}

	void MasEdificios(){
	glPushMatrix();
		Edificio(40,-9,20);
		Edificio(20,-10,0);
		Edificio(-40,-5,0);
		Edificio(0,5,0);
		Edificio(-20,0,0);
		Edificio(0,-20,20);
		Edificio(-20,-25,20);
	glPopMatrix;
	}
	void Paisaje(){
	glPushMatrix();
		glPushMatrix();
		Montania(-90,-150,0);
		Montania(-20,-150,-2);
		Montania(90,-150,-2);
		Montania(-60,-170,-10);
		glPopMatrix();
		
		glPushMatrix();
		MasEdificios();
		glPopMatrix;
	glPopMatrix;
	}

	void EXO(){
	glPushMatrix();
		glScalef(2.5f,1.8,1);
		glTranslatef(50,20,10);
		rombo();
		triangulo();
		triangulo2();
		triangulo3();
		triangulo4();
	glPopMatrix();
	
	}
	
	void Render(HDC hDC)
	{

		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		glClearColor(0.0f, 0.0f,0.5f, 20.5f); // color de fondo

		GLfloat LightAmb2[] = { 0.0, 0.0,0.1, 0.0 };
		GLfloat LightPos[] = { 20.0, 60.0, 20.0, 0.0 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb2);	  
		glLightfv(GL_LIGHT0, GL_POSITION, LightPos);

		glLoadIdentity();

		CamaraUpdate();
		
		
		glPushMatrix();
			glTranslatef(paso2,paso2+1,paso2-100);
			glColor3f(cRed, 0, 0);
			glutSolidTeapot(0.01f);
		glPopMatrix();

		//Nyan cat grande---------------------------------------------------------
		glPushMatrix();
		NyanBig();
		glPopMatrix();
		//Piso--------------------------------------------------------------------
		glPushMatrix();
		glTranslatef(0,0,-100);
		PisosColores();
		glPopMatrix;
		
		for(int i=0;i<10;i++){
		glPushMatrix();
		glTranslatef(-1, -1, -2+ (1 * paso));
		PisosColores();
		glPopMatrix;
		}
		
		//nyan cats pequeños-----------------------------------------------------
		glPushMatrix();
		glScalef(1,1,2);
		glTranslatef(-310,50,-200);
		glTranslatef(20 + (5 * paso), -1, 15);
		glTranslatef(paso2,paso2+5,paso2-1);
		NyanCat();
		glPopMatrix();
		
		glPushMatrix();
		glScalef(1,1,2);
		glTranslatef(-400,100,-200);
		glTranslatef(20 + (5 * paso), -1, 15);
		glTranslatef(paso2,paso2+5,paso2-1);
		NyanCat();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-300,90,-300);
		glTranslatef(20 + (2 * paso), -1, 15);
		glTranslatef(paso2,paso2+5,paso2-1);
		NyanCat();
		glPopMatrix();

		glPushMatrix();
		glScalef(1,1,2);
		glTranslatef(0,140,-200);
		glTranslatef(20 + (5 * paso), -1, 15);
		glTranslatef(paso2,paso2+5,paso2-1);
		NyanCat();
		glPopMatrix();

		glPushMatrix();
		//Paisaje----------------------------------------------------------------
		Paisaje();
		//Estrellas--------------------------------------------------------------
		stars();
		//Hongo------------------------------------------------------------------
		Hongues();
		//Estrela Mario----------------------------------------------------------
		StarMario2();

		EXO();
		glPopMatrix();
		//----------------------------------------------------------------------//
		SwapBuffers(hDC);
	}

};

#endif 
