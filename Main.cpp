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

#include <cstring>
#include <stdlib.h>


#include <cstdio>




using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;

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
void generaarchivobin(string, int);
void funcionMBR();
const string horafechaactual() ;
void MBRcomando();
void particionn(int);
void inicioparti();
void espacio (int result);



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

                for (size_t i = 0; i < valu; i++)
                {
                    
                   // cout<<"-valores "+datos[posfdisk]<<endl;
                        string a = datos[cc];
                        guardamkdisk(a,datos[i]);


                }
                string t = texto.erase(0, texto.find_first_not_of(" "));
                string a = datos[cc];
                guardamkdisk(a,t);
                crearchivobin();
                
                            
            poscont++;
            
            //funcionMBR();

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
           
            //cout<<"antes "<<endl;
            //cout<<primer<<endl;
            }else if(primer.compare("fdisk")==0){
                for (size_t i = 0; i < valu; i++)
                {

                        string a = datos[cc];
                        guardafdisk(a,datos[i]);

                }
                string t = texto.erase(0, texto.find_first_not_of(" "));
                string a = datos[cc];
                guardafdisk(a,t);
                
                MBRcomando();
                
                

               posfdisk++; 
                
            }

        }
    archivo.close();
    

    eliminarmkdisk();
    cout<<"sale"<<endl;

   
    //termina el proceso de leer 


    
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
   // cout<<b<<endl;
        if ((a.compare("-s"))==0){
      
            int as = atoi( b.c_str() );
            if (as>0){
                cout<<b<<endl;
                disco[poscont].tamano = as;
            }else{
                cout<<"mkdisk -s->Valor no valido"<<endl;
                disco[poscont].tamano = 0;
            }
            

        }else if ((a.compare("-f"))==0){
            
            if ((ajus[0].compare(b))==0){
                //cout<<"bbbff "<<endl;
                 cout<<b<<endl;
                disco[poscont].ajuste = b;
                
            }else if((ajus[1].compare(b))==0){
                cout<<b<<endl;
                disco[poscont].ajuste = b;
                
            }else if((ajus[2].compare(b))==0){
                cout<<b<<endl;
                disco[poscont].ajuste = b;
                
            }else{
                string e ="Error";
                disco[poscont].ajuste = e;
                cout<<"mkdisk -f->Ajuste No valido!"<<endl;
            }
            
           
            
        }else if ((a.compare("-u"))==0){
            if ((b.compare("B"))==0){
                cout<<b<<endl;
                disco[poscont].unidad = b;

            }else if ((b.compare("K"))==0){
                cout<<b<<endl;
                disco[poscont].unidad = b;
                

            }else if ((b.compare("M"))==0){
                cout<<b<<endl;
                disco[poscont].unidad = b;
                

            }else{
                string e ="Error";
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

         
        fflush(stdin);
        cout<<" -nob "+disco[poscont].nombre<<endl;
        cout<<disco[poscont].path<<endl;
        fflush(stdin);
       // cout<<" -s";
       // cout<<disco[poscont].tamano<<endl;
        cout<<disco[poscont].ajuste;
        cout<<disco[poscont].unidad;
        result =0;
        cout<<disco[poscont].tamano<<endl;
    
        if (disco[poscont].tamano>0){
            if ((disco[poscont].ajuste.compare("Error"))==0){
                cout<<"mkdisk -f->Valor no valido. No se genera archivo bin"<<endl;

            }else{
                cout<<"Disco con -f->FF"<<endl;
                disco[poscont].ajuste = "FF";
            }

            if ((disco[poscont].unidad.compare("K"))==0){
                // de k a byte 
                cout<<"**********en k"<<endl;
                result = disco[poscont].tamano * 1024;
                generaarchivobin(disco[poscont].path, result);
                
            }else if((disco[poscont].unidad.compare("M"))==0){
                //de me a k 
                cout<<"*************NAAAAA DAAA  AA"<<endl;
                int m = 1024*1024;
                result = disco[poscont].tamano * m;
                generaarchivobin(disco[poscont].path, result);

            }else if ((disco[poscont].unidad.compare("Error"))==0){
                cout<<"mkdisk -u->Valor no valido. No se genera archivo bin"<<endl;
             
            }else{
                cout<<"Se crea disco de Megabytes"<<endl;
                int m = 1024*1024;
                result = disco[poscont].tamano * m;
                disco[poscont].unidad = "M";
            }


        
            cout<<"resulll "<<endl;
                cout<<result;
        }else{
            
            cout<<"mkdisk -s->Valor no valido! No se genero archivo bin"<<endl;
        }
        
     
    cout<<"------------"<<endl;
      //  cout<<" -pat"+disco[i].path; 

    }
    



void generaarchivobin(string pat, int result){
    cout<<"genera archivo bin"<<endl;
    cout<<result<<endl;
    cout<<pat<<endl;
        FILE *arch;
        const char * c = pat.c_str();

        arch = fopen(c, "wb");
        if (arch==NULL)
            exit(1);
            
            

        for (size_t i = 0; i < result; i++)
        {
            //una variable char pesa 1 byte 
            //en sizeof mandamos cuanto va a pesar el archivo en bytes 
            char valor1=0;
            fwrite(&valor1, sizeof(char), 1, arch);

        }
    

        fclose(arch);
        

}


void eliminarmkdisk(){
        cout<< "###############"<<endl;
        string arc;
    if (posrmkd>0){
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
        cout<<"en u"<<endl;
        if ((b.compare("B"))==0){
            cout<<b<<endl;
            fdisc[posfdisk].letra = b;
        }else if ((b.compare("K"))==0){
            cout<<b<<endl;
            fdisc[posfdisk].letra = b;
        }else if ((b.compare("M"))==0){
            cout<<b<<endl;
            fdisc[posfdisk].letra = b;
        }else{
            cout<<"fdisk -u->valor no valido"<<endl;
        }
        
    }else if ((a.compare("-path"))==0){
        
        std::string chars = "\"";                       
        for (char c: chars) {
            b.erase(std::remove(b.begin(), b.end(), c), b.end());
        }
        cout<<b<<endl;
        fdisc[posfdisk].path = b;
    }else if ((a.compare("-t"))==0){
        
        cout<<b<<endl;
        if ((b.compare("P"))==0){
            fdisc[posfdisk].tipoparti = b;
        }else if ((b.compare("E"))==0){
            fdisc[posfdisk].tipoparti = b;
        }else if ((b.compare("L"))==0){
            fdisc[posfdisk].tipoparti = b;
        }else{
            cout<<"fdisk -t->Valor no valido"<<endl;
        }
        
    }else if ((a.compare("-f"))==0){

            if ((b.compare("BestFit"))==0){
                cout<<b<<endl;
                fdisc[posfdisk].ajuste = b;

            }else if((b.compare("FirstFit"))==0){
                cout<<b<<endl;
                fdisc[posfdisk].ajuste = b;

            }else if ((b.compare("WorstFit"))==0){
                cout<<b<<endl;
                fdisc[posfdisk].ajuste = b;

            }else{
                cout<<"mkdisk -f->valor no valido"<<endl;
            }
    

    }else if ((a.compare("-delete"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].elimina = b;
    }else if ((a.compare("-name"))==0){
        
        std::string chars = "\"";
                            
        for (char c: chars) {
            b.erase(std::remove(b.begin(), b.end(), c), b.end());
        }
        cout<<b<<endl;
        std::string cadena = b;
        char buffer[20];
        strcpy(buffer,cadena.c_str());
      //  fdisc[posfdisk].nombre = b;
        
      //arrparticion.mbr_partition_1.part_name = b;
    }else if ((a.compare("-add"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].add = b;
}
}



void MBRcomando(){
    
    cout<<"00000000000000000  crear particion "<<endl;
        for (size_t j = 0; j < poscont; j++)
        {
            fflush(stdin);
            //PARA LOS ATRIBUTOS DEL MBR
            if((fdisc[posfdisk].path.compare(disco[j].path))==0){
                cout<<"entraa en iff ///////////////////////// "<<endl;
                cout<<fdisc[posfdisk].path<<endl;
                
                //tamano del disco
                if ((disco[j].unidad.compare("K"))==0){
                    // de k a byte 
                    cout<<"en k"<<endl;
                    result = disco[j].tamano * 1024;
                    
                    arrparticion.mbr_tamano = result;
                    
                    
                }else if((disco[j].unidad.compare("M"))==0){
                    //de me a k 
                    cout<<"NAAAAA DAAA  AA"<<endl;
                    int m = 1024*1024;
                    result = disco[j].tamano * m;
                    arrparticion.mbr_tamano = result;  

                }
                //fecha de creacion 
                horafechaactual();
                cout<<"en hora "<<endl; 
                cout << "currentDateTime()=" << horafechaactual() << endl; 
                arrparticion.mbr_fecha_creacion = horafechaactual();

                //número random 
                int a=0, valor=0;
                a = rand(); // Genera un valor entre 0 y RAND_MAX
                arrparticion.mbr_dsk_signature = a;
                

            
               // arrparticion.dsk_fit =fdisc[posfdisk].ajuste;
            

                cout<<a<<endl;
                cout<<"ddddd-----------------"<<endl;
                cout<<disco[j].nombre<<endl;
                cout<<disco[j].tamano<<endl;
                cout<<disco[j].unidad<<endl;
                cout<<disco[j].ajuste<<endl;
                cout<<disco[j].path<<endl;
                if ((disco[j].ajuste.compare("FF")==0)){
                    cout<<"FF-----------------"<<endl;

                    arrparticion.dsk_fit = 'F';

                }else if((disco[j].ajuste.compare("BF")==0)){
                    arrparticion.dsk_fit = 'B';

                }else if ((disco[j].ajuste.compare("WF")==0)){
                    arrparticion.dsk_fit = 'W';

                }

            

          

                //PARA LA PARTICIÓN 
                
                cout<<arrparticion.mbr_partition_1.part_status<<endl;

            
                cout<<arrparticion.mbr_tamano<<endl;
                cout<<arrparticion.mbr_dsk_signature<<endl;
                cout<<arrparticion.mbr_fecha_creacion<<endl;
                
                    
                particionn(disco[j].tamano);
                contparti++;
               
                

            }  
        
    }

}

const string horafechaactual() { 
    time_t now = time(0); 
    struct tm tstruct; 
    char buf[80]; 
    tstruct = *localtime(&now); 
  
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); 
    return buf; 
    } 

void particionn(int tamanodisc ){
        //si la particion es la primera

        
        cout<<"dentro de particion ------------------"<<endl;
        cout<<fdisc[posfdisk].tamano<<endl;
        cout<<fdisc[posfdisk].letra;
        cout<<fdisc[posfdisk].path<<endl;
        cout<<fdisc[posfdisk].tipoparti<<endl;
        cout<<fdisc[posfdisk].ajuste<<endl;
        arrparticion.mbr_partition_1.part_status = 'A'; 
            cout<<"-----------------------------------------------------"<<endl;

        if ((fdisc[posfdisk].tipoparti.compare("P"))==0){
            cout<<"tipo primaria "<<endl;
            arrparticion.mbr_partition_1.part_type = 'P';
            inicioparti();

        }else if ((fdisc[posfdisk].tipoparti.compare("E"))==0){
            cout<<"tipo Extendida "<<endl;
            arrparticion.mbr_partition_1.part_type = 'E';
            inicioparti();


        }else if ((fdisc[posfdisk].tipoparti.compare(""))==0){
            arrparticion.mbr_partition_1.part_type = 'P';
            cout<<"tipo Primaria"<<endl;
            fdisc[posfdisk].tipoparti = "P";
            inicioparti();
        }else{
            
            if ((fdisc[posfdisk].tipoparti.compare("L"))==0){
                cout<<"No puede crear una partición logica si No hay extendida"<<endl;
            }else{
                cout<<"fdisk -t->Valor invalido"<<endl;

            }
        }


         if ((fdisc[posfdisk].ajuste.compare("BestFit"))==0){
            cout<<"ajuste B "<<endl;
            arrparticion.mbr_partition_1.part_fit = 'B';

        }else if ((fdisc[posfdisk].ajuste.compare("FirstFit"))==0){
            arrparticion.mbr_partition_1.part_fit = 'F';
            cout<<"ajuste F "<<endl;

        }else if ((fdisc[posfdisk].ajuste.compare("WorsFit"))==0){
            arrparticion.mbr_partition_1.part_fit = 'W';
            cout<<"ajuste W "<<endl;

        }else if ((fdisc[posfdisk].ajuste.compare(""))==0){
            arrparticion.mbr_partition_1.part_fit = 'W';
            fdisc[posfdisk].ajuste = "WorsFit";
        }else{
            cout<<"fdisk -f->Error"<<endl;
        }
  
      

}
void inicioparti(){
    cout<<"aquii "<<endl;
    if((fdisc[posfdisk].letra.compare("K")==0)){
        
        result = fdisc[posfdisk].tamano * 1024;
        cout<<arrparticion.mbr_tamano<<endl;
        cout<<result<<endl;
        espacio(result);

        }else if ((fdisc[posfdisk].letra.compare("B")==0)){
            cout<<"bytes"<<endl;
            result = fdisc[posfdisk].tamano;
            espacio(result);
        

        }else if ((fdisc[posfdisk].letra.compare("M")==0)){
            cout<<"megabytes"<<endl;
            int ss = 1024*1024;
            result = fdisc[posfdisk].tamano * ss;
            espacio(result);

        }else if ((fdisc[posfdisk].letra.compare("")==0)){
            cout<<"no tiene bytes se hace k "<<endl;
            result =1024;
            espacio(result);
        }

}

void espacio (int result){
     if (arrparticion.mbr_tamano>result){
       
            arrparticion.mbr_partition_1.part_start = 0;
            arrparticion.mbr_partition_1.part_s = arrparticion.mbr_tamano;
            
        }else{
            cout<<"No hay sufiente espacio en Disco"<<endl;
           
        }
}
