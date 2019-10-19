#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <iomanip>
#include <vector>

//Grupo:
//Conjunto de al menos tres fichas del mismo valor(numero)
//Pueden tener diferente color
//Numero	Caracteres
//  3                   r,y
//  8                   b
//  1                   b,r,g
//  2                   r,b

//Carrera:
//Conjunto de al menos tres fichas del mismo color y
//Forman una secuencia,(valores consecutivos)

//Carácter	Números
//  R               	1,2,4,3
//  Y                   	4
//  B               	1,4,3,5,6
//  G                   	2,3

using namespace std;
typedef pair<int,char> num;
std::vector<std::string>
split_iterator(const std::string& str);
int main()
{


    map<int,char>Rummi;
    int v=1,o=0;
    size_t i=0;
    char c;
    string z;
    cout<<"Inserte las fichas que posee"<<endl;
    while (v>0) {
        cout<<"ingrese el valor y el color Valores[1-2-3...8acostao] , "<<
        "  color[b,g,r,w] blue,green,red,white, con una sola letra"<<endl;
        cout<<"Ingrese '0' para salir";

        while (o==0) {
        cout<<"ingrese el valor de la ficha"<<i+1<<endl;
        cin>>v;
        if(v>13||v<1)
        {o=0;}else {
           o=1;}
                }

        while (o==0)
        {
        cout<<"Ingrese el color de la ficha (n,r,a,y)[Negro,Rojo,Azul,Amarillo]"<<i+1<<endl;
        cin>>c;

            if(c!='n'&&c!='r'&&c!='a'&&c!='y')
            {o=1;}else {
              cout<<"color incorrecto"<<endl;  o=0;}
        }
        pair<int,char> a(v,c) ;
        Rummi.insert(a);
    }
    cout<< setw(10)<<"Valor"<<setw(12)<<"Color"<<endl;
            map<int, char>::iterator p = Rummi.begin();
             while (p != Rummi.end() )
             {
                 // Para resolverlo, planteo que si la ficha contigua es igual en alguno de los 2 aspectos, se genere un contador y
                 // Al generar una igualdad con el iterador a 3 significa o que el color ha sido repetido 3 veces, o que hay numeros consecutivos en
                 // la lista de fichas y por lo tanto se puede hacer una carrera

                 // ahora planteado lo anterior procedere a realizar una lista de objetos pair que indiquen lo que
                 //necesitamos para el caso de las carreras, como se ve, debemos guardar la cantidad de colores presentes en las fichas


    //             106 fichas: 104 numeradas y dos comodines

    //                             Las fichas están numeradas del uno al trece [1-13]
    //                          y en cuatro  colores diferentes (negro, rojo, azul y amarillo).
    //               Hay dos unidades idénticas de cada ficha, de modo que:
    //                                                         13 fichas/color x 4 colores x 2 unidades/ficha = 104 fichas.

                map<int, char>::iterator q= p++;
                int fr=p->first,sc=q->first;
                char st=p->second,nd=q->second;
                int Mind; // Esta variable cambiara el tipo de aumento, dependiendo si estamos sumando para  ver
                 //si se forman grupos o si contamos pa lo de carreras

                if(fr==sc)  // En caso de que el valor de la ficha actual y la siguiente sean el mismo, guardar esta shit
                {    Mind=2;
                   // en los peores casos, casi todas las fichas solo repiten 2 veces su valor, y debemos almacenarlas, para saber si
                    //en algun punto se ingresan las suficientes para un grupo
                }
               cout << setw(10) << p->first << setw(12) << p->second << endl;
               p ++;
             }

             cout << "........................\n";

             return 0;

        }

std::vector<std::string>
split_iterator(const std::string& str)
{
  std::vector<std::string> resultado;

  std::string::const_iterator itBegin = str.begin();
  std::string::const_iterator itEnd   = str.end();

  int numItems = 1;
  for( std::string::const_iterator it = itBegin; it!=itEnd; ++it )
    numItems += *it==' ';

  resultado.reserve(numItems);

  for( std::string::const_iterator it = itBegin; it!=itEnd; ++it )
  {
    if( *it == ' ' )
    {
      resultado.push_back(std::string(itBegin,it));
      itBegin = it+1;
    }
  }

  if( itBegin != itEnd )
    resultado.push_back(std::string(itBegin,itEnd));

  return resultado;
}
