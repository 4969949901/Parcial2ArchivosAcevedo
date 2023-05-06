#include <iostream>
#include <filesystem>
#include <fstream>
#include <windows.h>
#include <string>


void crearArchivos(int cantidad);
void agregarTexto();
void buscarArchivo();
void agregarTexto2();
using namespace std;

int main() {
    int cantidad;
    cout<<"Cuantos archivos desea crear ingrese un numero\n";
    cin>>cantidad;
    crearArchivos(cantidad);
    int opc;
    cout<<"Seleccione una opcion si desea agregar texto:\n1.archivos pares\n2.archivos impares\n";
    cin>>opc;
    switch(opc){
        case 1:
            agregarTexto();
            break;

            case 2:
                agregarTexto2();
                break;
    }

    buscarArchivo();

    system("pause");
    return 0;
}

void crearArchivos(int cantidad) {

    for(int i=0;i<cantidad;i++) {
        ofstream archivos;
        string nombreArchivo="file";

         if(cantidad%2==0){
             archivos.open("C:/Users/helac/OneDrive/Documentos/par/"+ nombreArchivo +" "+ to_string(i) +" ."+"txt");
             if (archivos.fail()) {
                 cout << "Error al intentar abrir el archivo." << endl;

             }

             archivos.close();
             cout<<"\t--------------------------------------------------------\n";
             cout<<"\tLos archivos creados fueron un total de:"<<cantidad<<endl;
             cout<<"\t--------------------------------------------------------\n";
         }else{
             archivos.open("C:/Users/helac/OneDrive/Escritorio/impar"+ nombreArchivo +" "+ to_string(i) +" ."+"txt");
             if (archivos.fail()) {
                 cout << "Error al intentar abrir el archivo." << endl;

             }

             archivos.close();
             cout<<"\t--------------------------------------------------------\n";
             cout<<"\tLos archivos creados fueron un total de:"<<cantidad<<endl;
             cout<<"\t--------------------------------------------------------\n";

         }


         }
    }



void agregarTexto(){
    ifstream archivos;
    string texto;

    archivos.open("C:/Users/helac/OneDrive/Documentos/par/",ios::in);
    if(archivos.fail()){
        cout<<"Error al agregar texto";

    }
    cout<<"ingrese el texto que dese agregar";
    getline(archivos,texto);
    archivos>>texto;


    archivos.close();

}

void agregarTexto2(){
    ifstream archivos;
    string texto;

    archivos.open("C:/Users/helac/OneDrive/Escritorio/impar",ios::in);
    if(archivos.fail()){
        cout<<"Error al agregar texto";

    }
    cout<<"ingrese el texto que dese agregar";
    getline(archivos,texto);
    archivos>>texto;

    archivos.close();

}

void buscarArchivo(){
    std::filesystem::directory_iterator directoryIterator("C:/Users/helac/OneDrive/Documentos/par/");
    for (const auto& entry : directoryIterator) {
        if (!std::filesystem::is_directory(entry.status())) {
            std::cout << entry.path().filename() << " "
                      << file_size(entry.path()) << std::endl;
            cout<<"El archivo mas grande en la carpeta del primer ejercicio es:" ;
        }
    }
}