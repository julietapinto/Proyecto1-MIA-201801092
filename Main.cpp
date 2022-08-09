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
using std::cout; using std::cin;
using std::endl; using std::string;

constexpr int CHAR_LENGTH = 1;
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
void MBR();
void particionn(int);

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
           
            cout<<"antes "<<endl;
            cout<<primer<<endl;
            }else if(primer.compare("fdisk")==0){
              
                
                
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
    
    crearchivobin();
    eliminarmkdisk();
    cout<<"sale"<<endl;
    MBR();
   
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
            
            if((b.compare("K"))==0){
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
            if ((disco[i].unidad.compare("K"))==0){
                // de k a byte 
                cout<<"**********en k"<<endl;
                result = disco[i].tamano * 1024;
                
                for (size_t i = 0; i < result; i++)
                {
                    //una variable char pesa 1 byte 
                    //en sizeof mandamos cuanto va a pesar el archivo en bytes 
                    char valor1=0;
                    fwrite(&valor1, sizeof(char), 1, arch);
        
                }
                if ((disco[i].ajuste.compare(""))==0){
                cout<<"ajuste en cero f "<<endl;
                disco[i].ajuste = "FF";
                 }
                
                
            }else if((disco[i].unidad.compare("M"))==0){
                //de me a k 
                cout<<"*************NAAAAA DAAA  AA"<<endl;
                int m = 1024*1024;
                result = disco[i].tamano * m;
                for (size_t i = 0; i < result; i++)
                {
                    //una variable char pesa 1 byte 
                    //en sizeof mandamos cuanto va a pesar el archivo en bytes 
                    char valor1=0;
                    fwrite(&valor1, sizeof(char), 1, arch);
        
                }
                 if ((disco[i].ajuste.compare(""))==0){
                cout<<"ajuste en cero f "<<endl;
                disco[i].ajuste = "FF";
                 }

            }else if ((disco[i].unidad.compare(""))==0){
                cout<<"***********no tiene nadaaaaa en u"<<endl;
                int m = 1024*1024;
                result = disco[i].tamano * m;
                disco[i].unidad = "M";

                for (size_t i = 0; i < result; i++)
                {
                    //una variable char pesa 1 byte 
                    //en sizeof mandamos cuanto va a pesar el archivo en bytes 
                    char valor1=0;
                    fwrite(&valor1, sizeof(char), 1, arch);
        
                }
                if ((disco[i].ajuste.compare(""))==0){
                cout<<"ajuste en cero f "<<endl;
                disco[i].ajuste = "FF";
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
        cout<<b<<endl;
        fdisc[posfdisk].letra = b;
    }else if ((a.compare("-path"))==0){
        
        std::string chars = "\"";                       
        for (char c: chars) {
            b.erase(std::remove(b.begin(), b.end(), c), b.end());
        }
        cout<<b<<endl;
        fdisc[posfdisk].path = b;
    }else if ((a.compare("-t"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].tipoparti = b;
    }else if ((a.compare("-f"))==0){
            cout<<b<<endl;
            fdisc[posfdisk].ajuste = b;
    

    }else if ((a.compare("-delete"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].elimina = b;
    }else if ((a.compare("-name"))==0){
        
        std::string chars = "\"";
                            
        for (char c: chars) {
            b.erase(std::remove(b.begin(), b.end(), c), b.end());
        }
        cout<<b<<endl;
        fdisc[posfdisk].nombre = b;
    }else if ((a.compare("-add"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].add = b;
}
}



void MBR(){
    
    cout<<"00000000000000000  crear particion "<<endl;
   // cout<<posfdisk<<endl;
   // cout<<poscont<<endl;
    for (size_t i = 0; i < (posfdisk); i++)
    {    
        for (size_t j = 0; j < poscont; j++)
        {
            fflush(stdin);
            //PARA LOS ATRIBUTOS DEL MBR

           
            if((fdisc[i].path.compare(disco[j].path))==0){
                cout<<"entraa en iff ///////////////////////// "<<endl;
                cout<<fdisc[i].path<<endl;
                
                //tamano del disco
                if ((disco[j].unidad.compare("K"))==0){
                    // de k a byte 
                    cout<<"en k"<<endl;
                    result = disco[j].tamano * 1024;
                    
                    arrparticion[contparti].mbr_tamano = result;
                    
                    
                }else if((disco[j].unidad.compare("M"))==0){
                    //de me a k 
                    cout<<"NAAAAA DAAA  AA"<<endl;
                    int m = 1024*1024;
                    result = disco[j].tamano * m;
                    arrparticion[contparti].mbr_tamano = result;  

                }
                //fecha de creacion 
                horafechaactual();
                cout<<"en hora "<<endl; 
                cout << "currentDateTime()=" << horafechaactual() << endl; 
                arrparticion[contparti].mbr_fecha_creacion = horafechaactual();

                //número random 
                int a=0, valor=0;
                a = rand(); // Genera un valor entre 0 y RAND_MAX
                arrparticion[contparti].mbr_dsk_signature = a;
                

            
               // arrparticion[contparti].dsk_fit =fdisc[i].ajuste;
            

                cout<<a<<endl;
                cout<<"ddddd-----------------"<<endl;
                                cout<<disco[j].nombre<<endl;
                cout<<disco[j].tamano<<endl;
                cout<<disco[j].unidad<<endl;
                cout<<disco[j].ajuste<<endl;
                cout<<disco[j].path<<endl;
                if ((disco[j].ajuste.compare("FF")==0)){
                    cout<<"FF-----------------"<<endl;

                    arrparticion[contparti].dsk_fit = 'F';

                }else if((disco[j].ajuste.compare("BF")==0)){
                    arrparticion[contparti].dsk_fit = 'B';

                }else if ((disco[j].ajuste.compare("WF")==0)){
                    arrparticion[contparti].dsk_fit = 'W';

                }
            
               
          

                //PARA LA PARTICIÓN 
                
                cout<<arrparticion[contparti].mbr_partition_1.part_status<<endl;

                
                particionn(i);
                contparti++;
               
                

            }
            
        }
        

    }
/*    cout<<"-------------forrrr "<<endl;
    cout<<"----------dentro de particion ------------------"<<endl;
    cout<<posfdisk<<endl;
    for (size_t i = 0; i < (posfdisk); i++)
    {
                
        cout<<fdisc[i].tamano<<endl;
        cout<<fdisc[i].letra;
        cout<<fdisc[i].path<<endl;
        cout<<fdisc[i].tipoparti<<endl;
        cout<<fdisc[i].ajuste<<endl;
        cout<<"--------fuera de particion ------------"<<endl;

    }
    */


}

const string horafechaactual() { 
    time_t now = time(0); 
    struct tm tstruct; 
    char buf[80]; 
    tstruct = *localtime(&now); 
  
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct); 
    return buf; 
    } 

void particionn(int i ){
        cout<<"dentro de particion ------------------"<<endl;
        cout<<fdisc[i].tamano<<endl;
        cout<<fdisc[i].letra;
        cout<<fdisc[i].path<<endl;
        cout<<fdisc[i].tipoparti<<endl;
        cout<<fdisc[i].ajuste<<endl;
        arrparticion[contparti].mbr_partition_1.part_status = 'A';

        if ((fdisc[i].tipoparti.compare("P"))==0){
            cout<<"tipo p "<<endl;
            arrparticion[contparti].mbr_partition_1.part_type = 'P';

        }else if ((fdisc[i].tipoparti.compare("E"))==0){
            cout<<"tipo E "<<endl;
            arrparticion[contparti].mbr_partition_1.part_type = 'E';

        }else if ((fdisc[i].tipoparti.compare("L"))==0){
            arrparticion[contparti].mbr_partition_1.part_type = 'L';
            cout<<"tipo L "<<endl;

        }else if ((fdisc[i].tipoparti.compare(""))==0){
            arrparticion[contparti].mbr_partition_1.part_type = 'P';
            cout<<"tipo P"<<endl;
            fdisc[i].tipoparti = "P";
        }


         if ((fdisc[i].ajuste.compare("BestFit"))==0){
            cout<<"ajuste B "<<endl;
            arrparticion[contparti].mbr_partition_1.part_fit = 'B';

        }else if ((fdisc[i].ajuste.compare("FirstFit"))==0){
            arrparticion[contparti].mbr_partition_1.part_fit = 'F';
            cout<<"ajuste F "<<endl;

        }else if ((fdisc[i].ajuste.compare("WorsFit"))==0){
            arrparticion[contparti].mbr_partition_1.part_fit = 'W';
            cout<<"ajuste W "<<endl;

        }else if ((fdisc[i].ajuste.compare(""))==0){
            arrparticion[contparti].mbr_partition_1.part_fit = 'W';
            fdisc[i].ajuste = "WorsFit";
        }else{
            cout<<"fdisk -f->Error"<<endl;
        }
        

       
        cout<<fdisc[i].elimina<<endl;
        cout<<fdisc[i].nombre<<endl;
        cout<<fdisc[i].add<<endl;

}