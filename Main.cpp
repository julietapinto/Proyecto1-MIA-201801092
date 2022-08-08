#include <iostream>
#include "MBR_y_Partition.cpp"
#include "comandRMDISK.cpp"
#include "Fdisk.cpp"

#include <fstream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <filesystem>
#include <cstdlib>

#include <cstdio>




using namespace std;
string primer;
int poscont;
int posrmkd;
int posfdisk;
int valu;
long result;
int contparti;
void leer();
void crearchivobin();
void guardamkdisk(string,string );
void eliminarmkdisk();
void guardafdisk(string,string );
void funcionMBR();
const string horafechaactual() ;


struct mkdisk{
    string nombre;
    int tamano;
    string ajuste;
    string unidad;
    string path;

};
mkdisk *disco = new mkdisk[20];


 
int main(){
   
    leer();
    

    return 0;
}

void leer(){
    string texto;
    ifstream archivo;
    string sep = " ";
    string datos[100];
    string dat[100];
    
    int contador = 0; 
    int posi;


    archivo.open("prueba.txt",ios::in);
    while ( getline(archivo,texto)){
        cout<<texto<<endl;
        while ((posi = texto.find(sep)) != std::string::npos) {
        datos[contador] = texto.substr(0, posi);
        // cout<<datos[contador]<<endl;
        
            texto.erase(0, posi + sep.length());
            //cout<<contador<<endl;
            if (contador ==0){
                primer= datos[contador];
            }

            contador++;
            valu = contador;
        }
        contador =0;
        //crearchivobin mkdisk
        int cc =0;
        
            if (primer.compare("mkdisk")==0){
                cout<<"MKDISKKK -------"<<endl;
                disco[poscont].nombre= primer;		    
                //cout<<valu<<endl;
             
                
  
              
                for (size_t i = 0; i < valu; i++)
                {
                    
                   // cout<<"-valores "+datos[i]<<endl;
                        string a = datos[cc];
                        guardamkdisk(a,datos[i]);

                }
                
                string t = texto.erase(0, texto.find_first_not_of(" "));
               

                         string a = datos[cc];
                        guardamkdisk(a,t);
                            
            poscont++;
            crearchivobin();
            funcionMBR();

            }else if (primer.compare("rmdisk")==0){
                cout<<"<<<<<<<<<<<<<<<<< entra en eliminar////////////// "<<endl;
                int vi = 0;
                int pp;
                
                string dd = "->";
                string tt = texto.erase(0, texto.find_first_not_of(" "));
                //cout<<posrmkd<<endl;    
                arrrmkd[posrmkd].nombre = "rmdisk";
                //cout<<tt;
                  //  cout<<"----------"<<endl;
                    while ((pp = tt.find(dd)) != std::string::npos) {
                    datos[vi] = tt.substr(0, pp);
                    tt.erase(0, pp + dd.length()); 

                        }
                         if ((datos[vi].compare("-path"))==0){
                                string hj = tt.erase(0, tt.find_first_not_of(" "));  
                             //  cout<<"port a"<<endl;
                              // cout<<hj<<endl;
                                std::string chh = "\"";
                            
                                for (char g: chh) {
                                    hj.erase(std::remove(hj.begin(), hj.end(), g), hj.end());
                                }
                            
                               // std::cout << hj;
                                
                                arrrmkd[posrmkd].path = hj;
                                
                            }
                     
            posrmkd++;
            eliminarmkdisk();
            cout<<"antes "<<endl;
            cout<<primer<<endl;
            }else if(primer.compare("fdisk")==0){
              
                
                cout<<"777777777777777"<<endl;
                for (size_t i = 0; i < valu; i++)
                {
                    
            

                        string a = datos[cc];
                        guardafdisk(a,datos[i]);

                }
                string t = texto.erase(0, texto.find_first_not_of(" "));
                string a = datos[cc];
                guardafdisk(a,t);

               posfdisk++; 
                
            }

        }
    archivo.close();
    //termina el proceso de leer 

  /*  for (size_t i = 0; i < posrmkd; i++)
    {
        cout<<"nomb"<<endl;
        cout<<arrrmkd[i].nombre<<endl;
        cout<<"path"<<endl;
        cout<<arrrmkd[i].path<<endl;
    }
 

  */


    
}
void guardamkdisk(string a,string tt){
    int pp;
    int f=0;
    int u=0;
  
    string ajus[3]= {"BF", "FF", "WF"};
    string deli = "->";
    
    while ((pp = tt.find(deli)) != std::string::npos) {
        
            a = tt.substr(0, pp);   
            tt.erase(0, pp + deli.length());
            }
  //  cout<<a.length()<<endl;
    string b = tt.erase(0, tt.find_first_not_of(" "));
        if ((a.compare("-s"))==0){
            cout<<"entra"<<endl;
            
            cout<<"----------"<<endl;
            
            cout<<b<<endl;
            int as = atoi( b.c_str() );
            disco[poscont].tamano = as;

        }else if ((a.compare("-f"))==0){
            
            if ((ajus[0].compare(b))==0){
                cout<<"bbbff "<<endl;
                 cout<<b<<endl;
                disco[poscont].ajuste = b;
                
            }else if((ajus[1].compare(b))==0){
                cout<<b<<endl;
                disco[poscont].ajuste = b;
                
            }else if((ajus[2].compare(b))==0){
                cout<<b<<endl;
                disco[poscont].ajuste = b;
                
            }else{
                string e ="error";
                disco[poscont].ajuste = e;
                cout<<"mkdisk -f->Ajuste No valido!"<<endl;
            }
            
           
            
        }else if ((a.compare("-u"))==0){
            
            if((b.compare("k"))==0){
                cout<<b<<endl;
                disco[poscont].unidad = b;
                

            }else if ((b.compare("M"))==0){
                cout<<b<<endl;
                disco[poscont].unidad = b;
                

            }else{
                string e ="error";
                disco[poscont].ajuste = e;
                cout<<"mkdisk -u->Valor no valido!"<<endl;
            }
            
           
        }else if ((a.compare("-path"))==0){
            cout<<"entra en pat"<<endl;
            cout<<b<<endl;
            std::string chars = "\"";
                            
            for (char c: chars) {
                b.erase(std::remove(b.begin(), b.end(), c), b.end());
            }
            
            cout<<b<<endl;
            disco[poscont].path = b;
        }
        

}

void crearchivobin()
{
    cout<<"-----------/////////////--"<<endl;
    for (size_t i = 0; i < poscont; i++)
    {
         
        fflush(stdin);
        cout<<" -nob "+disco[i].nombre;
        fflush(stdin);
       // cout<<" -s";
       // cout<<disco[i].tamano<<endl;
        cout<<disco[i].ajuste;
        cout<<disco[i].unidad;
        result =0;
        fflush(stdin);
        FILE *arch;
        const char * c = disco[i].path.c_str();
        //crea un archivo en la pat que le mando 
        arch=fopen(c, "wb");
        
        if (arch==NULL)
            exit(1);
            if ((disco[i].unidad.compare("k"))==0){
                // de k a byte 
                cout<<"en k"<<endl;
                result = disco[i].tamano * 1024;
                
                for (size_t i = 0; i < result; i++)
                {
                    //una variable char pesa 1 byte 
                    //en sizeof mandamos cuanto va a pesar el archivo en bytes 
                    char valor1=0;
                    fwrite(&valor1, sizeof(char), 1, arch);
        
                }
                
                
            }else if((disco[i].unidad.compare("M"))==0){
                //de me a k 
                cout<<"NAAAAA DAAA  AA"<<endl;
                int m = 1024*1024;
                result = disco[i].tamano * m;
                for (size_t i = 0; i < result; i++)
                {
                    //una variable char pesa 1 byte 
                    //en sizeof mandamos cuanto va a pesar el archivo en bytes 
                    char valor1=0;
                    fwrite(&valor1, sizeof(char), 1, arch);
        
                }
                

            }else if ((disco[i].unidad.compare("error"))==0){
                cout<<"error"<<endl;
                result = 0;
            }else{
                cout<<"en ********else"<<endl;
                int m = 1024*1024;
                disco[i].tamano = m;
                result = m;
                for (size_t i = 0; i < m; i++)
                {
                    //una variable char pesa 1 byte 
                    //en sizeof mandamos cuanto va a pesar el archivo en bytes 
                    char valor1=0;
                    fwrite(&valor1, sizeof(char), 1, arch);
        
                }
                }
        
            cout<<"resulll "<<endl;
                cout<<result;

        
            fclose(arch);
    cout<<"------------"<<endl;
      //  cout<<" -pat"+disco[i].path; 

    }
    

}

void eliminarmkdisk(){
        cout<< "###############"<<endl;
        string arc;
    for (size_t i = 0; i < (posrmkd-1); i++)
    {
        cout<<"nomb";
        cout<<arrrmkd[i].nombre;
        cout<<"path";
        cout<<arrrmkd[i].path;
        arc = arrrmkd[i].path;
        char arr[arrrmkd[i].path.length() + 1]; 

        strcpy(arr, arrrmkd[i].path.c_str()); 
   
        if(remove(arr) != 0 )
        perror("Error al borrar archivo!.");
    else
        puts("El archivo se borro con exito!");
    
  
    }
        for (size_t i = 0; i < poscont; i++)
    {
        if ((arc.compare(disco[i].path)==0)){
                     cout<<arc<<endl;
            fflush(stdin);
            disco[i].nombre="0";
            disco[i].tamano=0;
            disco[i].ajuste="0";
            disco[i].unidad="0";
            disco[i].path="0";

        }

    }
}

void guardafdisk(string a, string ty){
    int pp;
    string deli = "->";

        
        while ((pp = ty.find(deli)) != std::string::npos) {
            a = ty.substr(0, pp);
            ty.erase(0, pp + deli.length());
        }
    string b = ty.erase(0, ty.find_first_not_of(" ")); 
    if ((a.compare("-s"))==0){
        cout<<b<<endl;
        int as = atoi( b.c_str() );
        fdisc[posfdisk].tamano = as;

    }else if ((a.compare("-u"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].letra = b;
    }else if ((a.compare("-path"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].path = b;
    }else if ((a.compare("-t"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].tipoparti = b;
    }else if ((a.compare("-f"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].ajuste=b;
    }else if ((a.compare("-delete"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].elimina = b;
    }else if ((a.compare("-name"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].nombre = b;
    }else if ((a.compare("-add"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].add = b;
}
}

void funcionMBR(){
    cout<<"///////////// MBRRRR"<<endl;
    for (size_t i = 0; i < poscont; i++)
    {
        cout<<disco[i].nombre<<endl;
        cout<<disco[i].tamano<<endl;
        cout<<disco[i].unidad<<endl;
        cout<<disco[i].ajuste<<endl;
        cout<<disco[i].path<<endl;
        if ((disco[i].unidad.compare("k"))==0){
                // de k a byte 
                cout<<"en k"<<endl;
                result = disco[i].tamano * 1024;
                
                arrparticion[contparti].mbr_tamano = result;
                
                
            }else if((disco[i].unidad.compare("M"))==0){
                //de me a k 
                cout<<"NAAAAA DAAA  AA"<<endl;
                int m = 1024*1024;
                result = disco[i].tamano * m;
                arrparticion[contparti].mbr_tamano = result;
      
                

        }

        
    }
    horafechaactual(); 
    
}
const string horafechaactual() { 
    time_t now = time(0); 
    struct tm tstruct; 
    char buf[80]; 
    tstruct = *localtime(&now); 
  
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); 
    return buf; 
    } 