#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void desplegarPreguntas(vector<string> &vecPreguntas, vector<string> &vecRespuestas){
    int exit = 0;
    int numPreg = 0;
    string pregunta = "";
    string respuesta = "";
    while(exit != 1) {
        cout << "Ingresa la pregunta " << numPreg+1 << endl;
        getline(cin, pregunta);
        vecPreguntas.push_back(pregunta);
        cout << "Ingresa la respuesta " << numPreg+1 << endl;
        getline(cin, respuesta);
        vecRespuestas.push_back(respuesta);
        cout << "Deseas salir? '1 para si' " << endl;
        cin >> exit;
        numPreg++;
        cin.ignore();
    }
}

int borrarPosVector(vector<string> &vecPreguntas, vector<string> &vecRespuestas, int &numPreguntas, int numAleatorio){

    for(int i=0;i<numPreguntas;i++){
        if(i==numAleatorio){
            while(i<numPreguntas-1){
                vecPreguntas[i]=vecPreguntas[i+1];
                vecRespuestas[i]=vecRespuestas[i+1];
                i++;
            }
            break;
        }
    }
    numPreguntas=numPreguntas-1;
    vecPreguntas.pop_back();
    return 0;

}

void responderPreguntas(vector<string> &vecPreguntas, vector<string> &vecRespuestas, int &numPreguntas, int comodin){
    srand(time(NULL));
    string respUsuario = "";
    int numAleatorio = 0;
    float score = 0;
    float calif;
    int numPregBorradas = 0;
    for(int i = 0; i < numPreguntas+numPregBorradas; i++){
        cin.ignore();
        numAleatorio = rand() % (numPreguntas-0);
        cout << i+1 << " - " << vecPreguntas[numAleatorio] << endl;
        cout << "Respuesta\n";
        getline(cin, respUsuario);
        if(respUsuario == "comodin" && comodin > 0){
            respUsuario = vecRespuestas[numAleatorio];
            comodin = comodin-1;
            cout << "Comodines restantes: " << comodin << endl;
        }
        if(respUsuario == "comodin" && comodin <= 0){
            cout << "Ya no tienes comodines "<< endl;
            cout << i+1 << " - " << vecPreguntas[numAleatorio] << endl;
            cout << "Responde de nuevo, por favor\n";
            getline(cin, respUsuario);
        }
        if(respUsuario == vecRespuestas[numAleatorio]){
            cout << "Respuesta correcta\n";
            score++;
        }
        else{
            cout << "Respuesta incorrecta\n";
        }
        borrarPosVector(vecPreguntas, vecRespuestas, numPreguntas, numAleatorio);
        numPregBorradas++;
    }
    cout << "\n";
    calif = score/(numPreguntas+numPregBorradas)*100;
    cout << "Calificacion: " << calif << endl;
}

int main() {
    vector<string> vecPreguntas(0);
    vector<string> vecRespuestas(0);
    int numPreguntas = 0;
    int iniciarJuego = 0;
    int comodin = 1;
    desplegarPreguntas(vecPreguntas, vecRespuestas);
    numPreguntas = vecPreguntas.size();
    cout << "Deseas iniciar el juego? '1 para si '" << endl;
    cin >> iniciarJuego;
    cout << "Recuerda que puedes usar un comodin para saltar una pregunta\n solo escribe 'comodin'! " << endl;
    if(iniciarJuego == 1){
        responderPreguntas(vecPreguntas, vecRespuestas, numPreguntas, comodin);
        cout << "FIN" << endl;
    }
}