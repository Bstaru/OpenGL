#include <windows.h>
#include <windowsx.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>


#include "Graphics.h"
#define Timer1 100

#pragma comment(lib, "glu32.lib")



#define boton1 1
HWND bot1;

LRESULT CALLBACK WindowProc(HWND hWnd, 	UINT message, WPARAM wParam, LPARAM lParam);
void SetUpPixelFormat(HDC hDC);

//variable global
HDC gHDC;

//puntero del objeto 
Graph *OGLobj;

bool renderiza=false;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,  LPSTR lpCmdLine, int nCmdShow)
{  	   
	HWND hWnd;  
				
	PlaySound(L"NyanCatRemix.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	
	WNDCLASSEX wc;    
	
	ZeroMemory(&wc, sizeof(WNDCLASSEX));    
	wc.cbSize = sizeof(WNDCLASSEX);  
	wc.style = CS_HREDRAW | CS_VREDRAW; 	
	wc.lpfnWndProc = WindowProc; 	
	wc.hInstance = hInstance;   	
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 	
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;	
	wc.lpszClassName = L"EjemploLMAD"; 	
	RegisterClassEx(&wc);     
	RECT wr = {0, 0, 800, 600};    
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);    

	hWnd = CreateWindowEx(NULL,  
		L"EjemploLMAD",                       
		L"NYAN CAT CAGUAI",             
		WS_OVERLAPPEDWINDOW,                            
		100,                     
		100,                     
		wr.right - wr.left,                        
		wr.bottom - wr.top,                   
		NULL,                     
		NULL,                
		hInstance,                        
		NULL);   	
	   
	ShowWindow(hWnd, nCmdShow);  

	//Creamos al objeto y se lo pasamos al puntero
	OGLobj = new Graph(hWnd);

	// inicializamos el objeto Timer a la cantidad de milisegundos deseada
	SetTimer(hWnd,Timer1,10,NULL);

	MSG msg = {0};      
	while(TRUE)   
	{      		
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))       
		{			    
			TranslateMessage(&msg); 		   
			DispatchMessage(&msg);           
			     
			if(msg.message == WM_QUIT)              
				break;        
		}        
		else       
		{   	
			//en este lazo estara ejecutandose el render
			//"renderiza" controla si se hace el render o no a través del timer Timer1
			if (renderiza)
			{
				OGLobj->Render(gHDC);   
				renderiza=false;
			}
		}    
	}    
	
	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
	static HGLRC hRC;
	static HDC hDC;
	int ancho, alto;

	switch(wParam){
	
	case VK_RIGHT:
		//if(OGLobj->poscx<200)
			OGLobj->poscx += 5;
			break;

	case VK_LEFT:
		//if(OGLobj->poscx<200)
			OGLobj->poscx += -5;
			break;

	case VK_DOWN: 
			OGLobj->poscy -= 5;
			break;

	case VK_UP: 
			OGLobj->poscy += 5;
			break;

	case VK_SPACE: 
			OGLobj->poscz -= 5;
			break;

	case VK_DELETE: 
			OGLobj->poscz += 5;
			break;

	case VK_ESCAPE:
		DestroyWindow(hWnd);
	
	}
	 
	switch(message)    
	{    
		
	case WM_CREATE:
		hDC=GetDC(hWnd);
		gHDC=hDC;
		SetUpPixelFormat(hDC);
		hRC=wglCreateContext(hDC);
		wglMakeCurrent(hDC,hRC);
		break;
	
	case WM_TIMER:
		//OGLobj->angulo+=1.5;

		if (OGLobj->estado == 1)
			OGLobj->angulo -= 0.5f;
		else
			OGLobj->angulo += 0.5f;

		if (OGLobj->angulo >= 15.0f)
			OGLobj->estado = 1;
		else if (OGLobj->angulo <= -15.0f)
			OGLobj->estado = 0;
		
		if (OGLobj->paso<=100)
			OGLobj->paso += 0.5;
		else 
			OGLobj->paso = 0.5;

		//Color mov:

		if (OGLobj->cRed<=1)
			OGLobj->cRed += 0.01;
		else
			OGLobj->cRed = 0;

		if (OGLobj->cBlue<=1)
			OGLobj->cBlue += 0.01;
		else
			OGLobj->cBlue = 0;

		if (OGLobj->cGreen<=1)
			OGLobj->cGreen += 0.01;
		else
			OGLobj->cGreen = 0;


		// para el movimiento de la tetera
		if (OGLobj->paso2<20)
			OGLobj->paso2 += 0.1;
		else
			OGLobj->paso2 = 0.1;

		// para el movimiento de la cámara
		if (OGLobj->x<20)
			OGLobj->x += 0.01;
		else
			OGLobj->x = -20;

		if (OGLobj->y<20)
			OGLobj->y += 0.03;
		else
			OGLobj->y = -20;

		if (OGLobj->z<20)
			OGLobj->z += 0.05;
		else
			OGLobj->z = -20;

		renderiza=true;
		break;

	case WM_DESTROY:           
		{  
			KillTimer(hWnd,Timer1);
			//en caso de salir desocupar los recursos del opengl
			wglMakeCurrent(hDC,NULL);
			wglDeleteContext(hRC);
			PostQuitMessage(0);  
			return 0;            
		} break;   

	case WM_SIZE:
		{
			//esta opcion del switch se ejecuta una sola vez al arrancar y si se
			//afecta el tamaño de la misma se dispara de nuevo
			alto = HIWORD(lParam);
			ancho= LOWORD(lParam);
			if (alto==0)
				alto=1;
			glViewport(0,0,ancho,alto);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45.0f, (GLfloat)ancho/(GLfloat)alto,1.0f,1000.0f);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}
		break;
	} 

	return DefWindowProc (hWnd, message, wParam, lParam);
}

void SetUpPixelFormat(HDC hDC)
{
	int PixForm;

	static PIXELFORMATDESCRIPTOR pixfordes = {
		sizeof(PIXELFORMATDESCRIPTOR), //tamaño de la estructura
		1, //numero de version
		PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER, //soporta la ventana, el opengl y manejara doble buffer
		PFD_TYPE_RGBA, //formato de 32 bits rgba
		32, //tamaño del color en 32 bits
		0,0,0,0,0,0, //bits de color, no se usan
		0, //no hay buffer para el alfa
		0, //ignore el bit de corrimiento
		0, //no hay buffer de acumulacion
		0,0,0,0, //no hay bits de acumulacion
		16, //tamaño del flotante para el buffer z
		0, //no hay buffers de stencil
		0, //no hay buffers auxiliares
		PFD_MAIN_PLANE, //plano principal para dibujo
		0, //reservado
		0,0,0 //mascaras de capas ignoradas
	};

	PixForm=ChoosePixelFormat(hDC, &pixfordes);
	SetPixelFormat(hDC, PixForm, &pixfordes);
}



