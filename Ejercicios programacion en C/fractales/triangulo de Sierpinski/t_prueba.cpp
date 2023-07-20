/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>


/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);
/***************************
*Librerias a usar para realizar diferentes tipos de 
*operaciones
***************************/
	#include<stdlib.h>
	#include<stdio.h>
	#include<math.h>
	
	#define O_X 0.0
	#define O_Y 0.0
	#define ESC_X 1
	#define ESC_Y 1
	typedef struct vectores
	{
		double i,j;	
	}V;
	typedef struct triangulo
	{
		V p,q,s;
	}T;
	V mitad_S(V a,V b);
	T crea_T(void);
	T P_medios_T(T a);
	T crea_T2(V a,V b,V c);
	void dibuja_T(T A);
	void dibuja_T2(T A);
	void T_sier(int n,T a);

/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "GLSample";
    RegisterClass (&wc);
    T A;	
	int n=3;	
	A=crea_T();
    /* create main window */
    hWnd = CreateWindow (
      "GLSample", "OpenGL Sample", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 3*256, 2*256,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            dibuja_T(A);
            T_sier(n,A);
            SwapBuffers (hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}
V mitad_S(V a,V b)
{
	V r;
	r.i=(a.i+b.i)/2;
	r.j=(a.j+b.j)/2;
	return r;
}
T crea_T(void)
{
	T r;
	double l=2.0;
	r.p.i=(l/2);
	r.p.j=0;
	r.q.i=0;
	r.q.j=-l*sin(60.0);
	r.s.i=-(l/2);
	r.s.j=0;
	return r;
}
T crea_T2(V a,V b,V c)
{
	T r;
	r.p=a;
	r.q=b;
	r.s=c;
	return r;
}
T P_medios_T(T a)
	{
		T r;
		r.p=mitad_S(a.p,a.q);
		r.q=mitad_S(a.q,a.s);
		r.s=mitad_S(a.s,a.p);
		return r;
	}

/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}
void dibuja_T(T A)
{
	glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
    glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix ();
	glBegin (GL_TRIANGLES);
	glColor3f (1.0f, 1.0f, 1.0f);
	glVertex2d(O_X+ESC_X*A.p.i,O_Y+ESC_Y*A.p.j);
	glVertex2d(O_X+ESC_X*A.q.i,O_Y+ESC_Y*A.q.j);
	glVertex2d(O_X+ESC_X*A.s.i,O_Y+ESC_Y*A.s.j);
	glEnd ();
    glPopMatrix ();
}
void dibuja_T2(T A)
{
	glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
    glClear (GL_ACCUM_BUFFER_BIT);
	glBegin (GL_TRIANGLES);
	glColor3f (0.5f, 0.5f, 0.5f);
	glVertex2d(O_X+ESC_X*A.p.i,O_Y+ESC_Y*A.p.j);
	glVertex2d(O_X+ESC_X*A.q.i,O_Y+ESC_Y*A.q.j);
	glVertex2d(O_X+ESC_X*A.s.i,O_Y+ESC_Y*A.s.j);
	glEnd ();
    glPopMatrix ();
}
void T_sier(int n,T a)
{
	T r,aux;
	int i;
	r=P_medios_T(a);
	dibuja_T2(r);
	aux=crea_T2(a.s,r.q,r.s);
	for(i=0;i<n;i++)
	{
       r=P_medios_T(aux);
       dibuja_T2(r);
       aux=crea_T2(a.s,r.p,r.q);
    }
    r=P_medios_T(a);
    aux=crea_T2(r.s,r.p,a.p);
    dibuja_T2(aux);
}
