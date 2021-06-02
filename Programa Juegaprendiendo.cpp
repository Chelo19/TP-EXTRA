#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ESC 27

using namespace std;

char key;

void JuegoPreguntas()
{
	system("cls");
	cout << "Este programa consta de ingresar la cantidad de preguntas que desee con sus respectivas respuestas.\n";
	cout << "Esas preguntas eventualmente se desplegarán en orden aleatorio para ser respondidas.\n";
	cout << "Presione cualquier tecla para comenzar...\n";
	getch();
	vector<string> vecPreguntas(0);
    vector<string> vecRespuestas(0);
    int numPreguntas , num , comodin , _comodin;
    string pregunta , respuesta;
    cout << "\nCuantas preguntas desea ingresar? ";
    cin >> numPreguntas;
    cout << "\nCuantos comodines desea permitir por sesion? ";
    cin >> comodin;
    system("cls");
    cin.ignore();
    for(int i = 0 ; i < numPreguntas ; i++)
	{
        cout << "\nIngrese la pregunta #" << i + 1 << ": ";
        getline(cin , pregunta);
        vecPreguntas.push_back(pregunta);
        cout << "\nIngrese la respuesta: ";
        getline(cin , respuesta);
        vecRespuestas.push_back(respuesta);
    }
    cout << "\nPresione cualquier tecla para empezar la sesion de preguntas...";
	getch();
    do
	{
		int score = 0 , calif;
		_comodin = comodin;
    	int prevUsedNumbers[numPreguntas];
    	system("cls");
        cout << "Recuerde que puede usar un comodin para saltar una pregunta\nsolo escriba 'comodin'!\n\n";
	    string respUsuario;
    	for(int i = 0 ; i < numPreguntas ; i++)
		{
    		int j = 0;
        	while(j <= i)
        	{
        		if(num == prevUsedNumbers[j - 1]) j = 0;
        		if(j == 0) num = rand() % numPreguntas;
        		j++;
			}
			prevUsedNumbers[i] = num;
			Sleep(1000);
        	cout << i + 1 << ". " << vecPreguntas[num] << endl;
        	cout << "Respuesta: ";
			getline(cin , respUsuario);
        	while(respUsuario == "comodin" && _comodin == 0)
        	{
        		cout << "\nYa no tiene comodines. Responda de nuevo: ";
            	getline(cin , respUsuario);
			}
        	if(respUsuario == "comodin")
			{
            	_comodin--;
            	cout << "\nUsted ha usado un comodin. Comodines restantes: " << _comodin << "\n\n";
        	}
        	if(respUsuario == vecRespuestas[num])
			{
            	cout << "\nRespuesta correcta\n\n";
            	score++;
       		}
        	else
			{
				cout << "\nRespuesta incorrecta\n\n";
			}
    	}
    	Sleep(1000);
    	calif = score * 100 / numPreguntas;
    	cout << "Fin de la sesion. Calificacion: " << calif;
    	Sleep(1000);
        cout << "\n\nDesea volver a jugar? (1 = Si , 0 = No)\n";
        do
        {
        	key = getch();
		} while(key != '1' && key != '0');
    }
    while(key == '1');
}

void JuegoOperaciones()
{
	int num1 , num2 , rango , operador , respuestaUsuario , respuesta , repeticion = 0 , score = 0;
	float calificacion;
	system("cls");
	cout << "En este juego deberá resolver las operaciones indicadas de suma, resta o multiplicacion.\n\n";
	Sleep(1000);
    cout << "Ingrese la dificultad ( Facil=1 | Medio=2 | Dificil=3 | Extremo=4 )\n";
    do
    {
    	key = getch();
	} while(key != '1' && key != '2' && key != '3' && key != '4');
    switch(key)
	{
		case '1': rango = 10; break;
        case '2': rango = 100; break;
        case '3': rango = 250; break;
        case '4': rango = 500; break;
    }
    system("cls");
    do
	{
        repeticion++;
        num1 = rand() % rango;
        num2 = rand() % rango;
        operador = rand() % 3;
        cout << num1;
        switch(operador)
		{
            case 0: cout << " * "; respuesta = num1 * num2; break;
            case 1: cout << " + "; respuesta = num1 + num2; break;
            case 2: cout << " - "; respuesta = num1 - num2; break;
        }
        cout << num2 << " = ";
        cin >> respuestaUsuario;
        if(respuestaUsuario == respuesta)
		{
            cout << "\nCorrecto!\n";
        	score++;
        }
        else
		{
            cout << "\nIncorrecto. La respuesta correcta es: " << respuesta << endl;
        }
        Sleep(1000);
        cout << "\nSeguir jugando? (1 = Si , 0 = No)\n\n";
        do
        {
        	key = getch();
		} while(key != '1' && key != '0');
    } while(key == '1');
    calificacion = score * 100 / repeticion;
    system("cls");
    cout << "Operaciones respondidas: " << repeticion << endl;
    Sleep(1000);
    cout << "Contestadas correctamente: " << score << endl;
    Sleep(1000);
    cout << "Calificacion: " << calificacion << endl;
    Sleep(1000);
    cout << "Presione cualquier tecla para continuar...";
    getch();
}

void JuegoDerivadas()
{
	int tipo , num , exponente;
	system("cls");
    cout << "Este juego trata de acertar la derivada de la expresion aleatoriamente propuesta." << endl;
    getch();
    do
	{
		system("cls");
        tipo = 1 + rand() % 3;
        num = 1 + rand() % 9;
    	exponente = 1 + rand() % 9;
    	int numUsuario , exponenteUsuario;
        switch(tipo)
		{
            case 1:
                cout << "\nDerivada de tipo u^n" << endl;
                cout << "\nEl problema propuesto es : \n" << "Dx(" << num << "x^" << exponente << ")\n\n";
    			cout << "El problema se responde de manera (ax^b)" << "\n\n";
    			num = num * exponente;
    			exponente--;
    			do
				{
        			cout << "\ta = ";
			        cin >> numUsuario;
        			cout << "\tb = ";
        			cin >> exponenteUsuario;
        			cout << "\nSu respuesta final es:\n" << numUsuario << "x^" << exponenteUsuario << "\n\n";
        			cout << "Volver a escribir respuesta? (1 = Si , 0 = No)\n\n";
        			do
	        		{
        				key = getch();
					} while(key != '1' && key != '0');
    			} while(key == '1');
    			if(numUsuario == num && exponenteUsuario == exponente) cout << "\nLa respuesta es correcta!\n";
    			else cout << "\nIncorrecto. La respuesta correcta es: " << num << "x^" << exponente << endl;
                break;
            case 2:
            	int a , b , c , d , aCor , bCor , cCor , dCor , z , zCor;
                cout << "\nDerivada de tipo e^n" << endl;
                cout << "\nEl problema propuesto es : \n" << "e^(x^" << exponente << "+" << num << "x" << ")\n\n";
    			cout << "El problema se soluciona con un parentesis que multiplica a la \"e\", asi que se contestara de la siguiente forma:" << endl;
    			cout << "(ax^b+c)e^(x^d+zx)\n\n";
    			aCor = exponente;
    			bCor = exponente - 1;
    			cCor = num;
    			dCor = exponente;
    			zCor = num;
    			do
				{
        			cout << "\ta = ";
        			cin >> a;
        			cout << "\tb = ";
        			cin >> b;
        			cout << "\tc = ";
        			cin >> c;
        			cout << "\td = ";
        			cin >> d;
        			cout << "\tz = ";
        			cin >> z;
        			cout << "\nSu respuesta final es:\n" << "(" << a << "x^" << b << "+" << c << ")e^(x^" << d << "+" << z << "x)\n\n";
        			cout << "Volver a escribir respuesta? (1 = Si , 0 = No)\n\n";
        			do
        			{
        				key = getch();
					} while(key != '1' && key != '0');
    			} while(key == '1');
    			if(aCor == a && bCor == b && cCor == c && dCor == d && zCor == z)
				{
        			cout << "\nLa respuesta es correcta!\n";
    			}
    			else
				{
        			cout << "\nIncorrecto. La respuesta correcta es: ";
        			cout << "(" << aCor << "x^" << bCor << "+" << cCor << ")e^(x^" << dCor << "+" << zCor << "x)\n";
    			}
                break;
            case 3:
                cout << "\nDerivada de tipo lnu" << endl;
                cout << "\nEl problema propuesto es : \n" << "Ln" << num << "x^" << exponente << "\n\n";
    			cout << "La respuesta es de tipo a/x\n\n";
    			do
				{
        			cout << "\ta = ";
        			cin >> numUsuario;
        			cout << "\nSu respuesta final es:\n" << numUsuario << "/x\n\n";
        			cout << "Volver a escribir respuesta? (1 = Si , 0 = No)\n\n";
        			do
        			{
        				key = getch();
					} while(key != '1' && key != '0');
    			} while(key == '1');
    			if(numUsuario == exponente) cout << "\nLa respuesta es correcta!\n";
    			else cout<< "\nIncorrecto. La respuesta correcta es: " << num << "/x\n";
                break;
        }
        Sleep(1000);
        cout << "\nSeguir jugando? (1 = Si , 0 = No)" << endl;
        do
        {
        	key = getch();
		} while(key != '1' && key != '0');
    } while(key == '1');
}

void JuegoIntegrales()
{
	int tipo , num , numUsuario , exponente , exponente2 , a , b , f , g , h , i , j , k , l , m;
	system("cls");
    cout << "Este juego trata de acertar la integral de la expresion aleatoriamente propuesta." << endl;
    getch();
    do
	{
		system("cls");
        tipo = 1 + rand() % 3;
        switch(tipo)
		{
            case 1:
                cout << "\nIntegral de tipo Sdx" << endl;
    			num = 1 + rand() % 30;
    			cout << "\nEl problema propuesto es : \n" << "S" << num << "dx\n" << endl;
    			cout << "El problema se responde de manera (ax+C) y NO se simplifica.\n\n";
    			do
				{
        			cout << "\ta = ";
        			cin >> numUsuario;
        			cout << "Tu respuesta final es:\n" << numUsuario << "x+C\n\n";
        			cout << "Volver a escribir respuesta? (1 = Si , 0 = No)\n\n";
        			do
        			{
        				key = getch();
					} while(key != '1' && key != '0');
    			} while(key == '1');
    			if(numUsuario == num)
				{
        			cout << "\nLa respuesta es correcta!\n";
    			}
    			else
				{
        			cout << "\nIncorrecto. La respuesta correcta es: ";
        			cout << num << "x+C\n";
    			}
                break;
            case 2:
                cout << "\nIntegral de tipo Sx^ndx" << endl;
    			num = 1 + rand() % 9;
    			exponente = 1 + rand() % 9;
    			cout << "\nEl problema propuesto es : \nS" << num << "x^" << exponente << "dx\n" << endl;
    			cout << "La respuesta es de tipo (ax^b)/f+C y NO se simplifica" << endl;
    			exponente++;
    			do
				{
        			cout << "\ta = ";
        			cin >> a;
        			cout << "\tb = ";
        			cin >> b;
        			cout << "\tf = ";
        			cin >> f;
        			cout << "\nTu respuesta final es:\n(" << a << "x^" << b << ")/" << f << "+C\n\n";
        			cout << "Volver a escribir respuesta? (1 = Si , 0 = No)\n\n";
        			do
        			{
        				key = getch();
					} while(key != '1' && key != '0');
    			} while(key == '1');
    			if(a == num && b == exponente && f == exponente)
				{
        			cout << "\nLa respuesta es correcta!\n";
    			}
    			else
				{
        			cout << "\nIncorrecto. La respuesta correcta es: ";
        			cout << "(" << num << "x^" << exponente << ")/" << exponente << "+C\n";
    			}
                break;
            case 3:
                cout << "\nIntegral de tipo S[f(x)+-g(x)]dx" << endl;
    			f = 1 + rand() % 9;
    			g = 1 + rand() % 9;
    			exponente = 1 + rand() % 9;
    			exponente2 = 1 + rand() % 9;
    			cout << "\nEl problema propuesto es : \nS(" << f << "x^" << exponente << "+" << g << "x^" << exponente2 << ")dx\n" << endl;
    			cout << "La respuesta es de tipo (hx^i)/j+(kx^l)/m+C" << endl;
    			exponente++;
    			exponente2++;
    			do
				{
        			cout << "\th = ";
        			cin >> h;
        			cout << "\ti = ";
        			cin >> i;
        			cout << "\tj = ";
        			cin >> j;
        			cout << "\tk = ";
        			cin >> k;
        			cout << "\tl = ";
        			cin >> l;
        			cout << "\tm = ";
        			cin >> m;
        			cout << "\nTu respuesta final es:\n(" << h << "x^" << i << ")/" << j << "+(" << k << "x^" << l << ")/" << m << "+C\n\n";
        			cout << "Volver a escribir respuesta? (1 = Si , 0 = No)\n\n";
        			do
        			{
        				key = getch();
					} while(key != '1' && key != '0');
    			} while(key == '1');
    			if(h == f && i == exponente && j == exponente && k == g && l == exponente2 && m == exponente2)
				{
        			cout << "\nLa respuesta es correcta!\n";
    			}
    			else
				{
        			cout << "\nIncorrecto. La respuesta correcta es: ";
        			cout << "(" << f << "x^" << exponente << ")/" << exponente << "+(" << g << "x^" << exponente2 << ")/" << exponente2 << "+C\n";
    			}
                break;
        }
        Sleep(1000);
        cout << "\nSeguir jugando? (1 = Si , 0 = No)" << endl;
        do
        {
        	key = getch();
		} while(key != '1' && key != '0');
    } while(key == '1');
}

int main()
{
	cout << "-- Bienvenido(a) al programa Juegaprendiendo --\n\n";
	cout << "Este proyecto abarca varios 'minijuegos' hechos para poner aprueba su conocimiento.\n";
	cout << "Y asimismo, pretende ser una herramienta util para aprender.\n\n";
	cout << "Presione una tecla para ver los minijuegos disponibles...";
	getch();
	while(key != ESC)
	{
		system("cls");
		srand(time(NULL));
		cout << "-> Minijuegos <-\n\n";
		cout << "\t1. Sesion de preguntas\n\t2. Operaciones matematicas\n\t3. Derivadas\n\t4. Integrales\n\n(Para salir presione ESC)";
		do
		{
			key = getch();
		} while(key != '1' && key != '2' && key != '3' && key != '4' && key != ESC);
		switch(key)
		{
			case '1': JuegoPreguntas(); break;
			case '2': JuegoOperaciones(); break;
			case '3': JuegoDerivadas(); break;
			case '4': JuegoIntegrales(); break;
		}
	}
}
