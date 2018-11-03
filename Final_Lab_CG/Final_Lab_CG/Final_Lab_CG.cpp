//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha

CTexture tree;

CFiguras sky;
CFiguras edificio;
CFiguras mueble1;
CFiguras mueble2;
CFiguras television3;
CFiguras mueble4;
CFiguras cajas5;
CFiguras sillon6;
CFiguras sillon7;

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();


	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();


	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				sky.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
				glColor3f(1.0,1.0,1.0);
			glPopMatrix();

			////Creación del mueble 1
			//glPushMatrix();
			//	mueble1.prisma(0.45, 0.05, 0.9, NULL);
			//	mueble1.prisma(0.45, 0.9, 0.05, NULL);
			//	glPushMatrix();
			//		glTranslatef(0.0, 0.25, 0.0);
			//		mueble1.prisma(0.05, 0.9, 0.9, NULL);
			//	glPopMatrix();
			//glPopMatrix();

			////Creación del mueble 2
			//glPushMatrix();
			//	mueble2.prisma(0.1, 1.2, 0.4, NULL);
			//	glPushMatrix();
			//		glTranslatef(-0.45, 0.275, 0.0);
			//		mueble2.prisma(0.45, 0.3, 0.4, NULL);
			//	glPopMatrix();
			//	glPushMatrix();
			//		glTranslatef(0.45, 0.275, 0.0);
			//		mueble2.prisma(0.45, 0.3, 0.4, NULL);
			//	glPopMatrix();
			//	glPushMatrix();
			//		glTranslatef(0.0, 0.51, 0.0);
			//		mueble2.prisma(0.02, 1.2, 0.4, NULL);
			//		glPushMatrix();
			//			glTranslatef(-0.45, 0.235, -0.05);
			//			mueble2.prisma(0.45, 0.3, 0.3, NULL);
			//		glPopMatrix();
			//		glPushMatrix();
			//			glTranslatef(0.45, 0.235, -0.05);
			//			mueble2.prisma(0.45, 0.3, 0.3, NULL);
			//		glPopMatrix();
			//		glTranslatef(0.0, 0.47, 0.0);
			//		mueble2.prisma(0.02, 1.2, 0.4, NULL);
			//	glPopMatrix();
			//	glTranslatef(0.0, 0.47, -0.21);
			//	mueble2.prisma(1.04, 1.2, 0.02, NULL);
			//glPopMatrix();

			////Creación de la television 3
			//glPushMatrix();
			//	glTranslatef(0.0, 0.4, 0.0);
			//	television3.prisma(0.75, 1.25, 0.1, NULL);
			//	glPushMatrix();
			//		glTranslatef(-0.5, -0.4, 0.0);
			//		glRotatef(-22.5, 0, 1, 0);
			//		television3.prisma(0.05, 0.05, 0.3, NULL);
			//	glPopMatrix();
			//	glPushMatrix();
			//		glTranslatef(0.5, -0.4, 0.0);
			//		glRotatef(22.5, 0, 1, 0);
			//		television3.prisma(0.05, 0.05, 0.3, NULL);
			//	glPopMatrix();
			//glPopMatrix();

			////Creación del mueble 4
			//glPushMatrix();
			//	mueble4.prisma(0.65, 0.8, 0.35, NULL);
			//	glTranslatef(0.0, 0.85, 0.0);
			//	mueble4.prisma(1.05, 0.6, 0.35, NULL);
			//glPopMatrix();

			////Creación de las cajas 5
			//glPushMatrix();
			//	cajas5.prisma(0.3, 0.7, 0.4, NULL);
			//	glTranslatef(0.0, 0.175, 0.0);
			//	cajas5.prisma(0.05, 0.75, 0.5, NULL);
			//	glTranslatef(0.0, 0.175, 0.0);
			//	cajas5.prisma(0.3, 0.7, 0.4, NULL);
			//	glTranslatef(0.0, 0.175, 0.0);
			//	cajas5.prisma(0.05, 0.75, 0.5, NULL);
			//	glTranslatef(0.0, 0.175, 0.0);
			//	cajas5.prisma(0.3, 0.6, 0.4, NULL);
			//glPopMatrix();

			////Creación del sillon 6
			//glPushMatrix();
			//	sillon6.prisma(0.4, 2.4, 0.8, NULL); //Asiento
			//	glPushMatrix();
			//		glTranslatef(1.1, 0.3, 0.0);
			//		sillon6.prisma(0.2, 0.2, 0.8, NULL); //Recargadera brazo izquierdo
			//		glTranslatef(0.0, 0.1, -0.4);
			//		glRotatef(90.0, 1, 0, 0);
			//		sillon6.cilindro(0.1, 0.8, 20, NULL); //Cilindro de recargadera
			//	glPopMatrix();
			//	glPushMatrix();
			//		glTranslatef(-1.1, 0.3, 0.0);
			//		sillon6.prisma(0.2, 0.2, 0.8, NULL); //Recargadera brazo derecho
			//		glTranslatef(0.0, 0.1, -0.4);
			//		glRotatef(90.0, 1, 0, 0);
			//		sillon6.cilindro(0.1, 0.8, 20, NULL); //Cilindro recargadera
			//	glPopMatrix();
			//	glPushMatrix();
			//		glTranslatef(0.0, 0.175, -0.525);
			//		sillon6.prisma(0.75, 2.4, 0.25, NULL); //Recargadera espalda
			//		glTranslatef(1.2, 0.375, 0.0);
			//		glRotatef(90.0, 0, 0, 1);
			//		sillon6.cilindro(0.125, 2.4, 20, NULL); //Cilindro recargadera
			//	glPopMatrix();
			//glPopMatrix();

			////Creación del sillon 7
			//glPushMatrix();
			//	sillon7.prisma(0.4, 0.8, 0.8, NULL); //Asiento
			//	glPushMatrix();
			//		glTranslatef(0.3, 0.3, 0.0);
			//		sillon7.prisma(0.2, 0.2, 0.8, NULL); //Recargadera brazo izquierdo
			//		glTranslatef(0.0, 0.1, -0.4);
			//		glRotatef(90.0, 1, 0, 0);
			//		sillon7.cilindro(0.1, 0.8, 20, NULL); //Cilindro de recargadera
			//	glPopMatrix();
			//	glPushMatrix();
			//		glTranslatef(-0.3, 0.3, 0.0);
			//		sillon7.prisma(0.2, 0.2, 0.8, NULL); //Recargadera brazo derecho
			//		glTranslatef(0.0, 0.1, -0.4);
			//		glRotatef(90.0, 1, 0, 0);
			//		sillon7.cilindro(0.1, 0.8, 20, NULL); //Cilindro recargadera
			//	glPopMatrix();
			//	glPushMatrix();
			//		glTranslatef(0.0, 0.175, -0.525);
			//		sillon7.prisma(0.75, 0.8, 0.25, NULL); //Recargadera espalda
			//		glTranslatef(0.4, 0.375, 0.0);
			//		glRotatef(90.0, 0, 0, 1);
			//		sillon7.cilindro(0.125, 0.8, 20, NULL); //Cilindro recargadera
			//	glPopMatrix();
			//glPopMatrix();

		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Jerarquia"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
