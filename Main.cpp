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

#include <time.h>

#include <cstdio>
#include <stdio.h>

using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;

string primer;
int poscont;
int posrmkd;
int posfdisk;
int valu;
int contparti;
void leer();
void crearchivobin();
void guardamkdisk(string,string );
void eliminarmkdisk();
void guardafdisk(string,string,int& );
void generaarchivobin(string, int);
void funcionMBR();
void MBRregistro();
void gestionarchivobin();

void espacio (int, string, int);
void consultararchivobin(string, int&, int&);
void particion(int, int);

void posicionarchibin(string, int);
void particiones(int);



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

            if ((primer.compare("mkdisk"))==0){
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
                MBRregistro();


            poscont++;

            //funcionMBR();

            }else if ((primer.compare("rmdisk"))==0){
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
            }else if((primer.compare("fdisk"))==0){
                int vl= 0;
                for (size_t i = 0; i < valu; i++)
                {

                        string a = datos[cc];
                        guardafdisk(a,datos[i], vl);
                       // cout<<"salio"<<endl;
                        //cout<<vl<<endl;
                        if (vl ==1){
                            cout<<"entra"<<endl;
                            break;
                        }

                }
                if (vl == 0){
                    string t = texto.erase(0, texto.find_first_not_of(" "));
                    string a = datos[cc];
                    cout<<"en fdis"<<endl;
                    guardafdisk(a,t, vl);

                    gestionarchivobin();

                }




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
                int r = disco[poscont].tamano * 1024;
                generaarchivobin(disco[poscont].path, r);

            }else if((disco[poscont].unidad.compare("M"))==0){
                //de me a k
                cout<<"*************NAAAAA DAAA  AA"<<endl;
                int m = 1024*1024;
                int re = disco[poscont].tamano * m;
                generaarchivobin(disco[poscont].path, re);

            }else if ((disco[poscont].unidad.compare("Error"))==0){
                cout<<"mkdisk -u->Valor no valido. No se genera archivo bin"<<endl;

            }else{
                cout<<"Se crea disco de Megabytes"<<endl;
                int m = 1024*1024;
                int res = disco[poscont].tamano * m;
                generaarchivobin(disco[poscont].path, res);
                disco[poscont].unidad = "M";
            }

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
void MBRregistro(){
            cout<<"entraa en iff ///////////////////////// "<<endl;
            cout<<fdisc[posfdisk].path<<endl;

            //tamano del disco
            if ((disco[poscont].unidad.compare("B"))==0){
                cout<<"son bytes"<<endl;
                int r = disco[poscont].tamano;
                objmbr.mbr_tamano = r;

            }else if ((disco[poscont].unidad.compare("K"))==0){
                // de k a byte
                cout<<"-en k"<<endl;
                cout<<disco[poscont].tamano<<endl;
                int re = disco[poscont].tamano * 1024;
                cout<<re<<endl;
                objmbr.mbr_tamano =  re;
                
            }else if((disco[poscont].unidad.compare("M"))==0){
                //de me a k
                cout<<"NAAAAA DAAA  AA"<<endl;
                int m = 1024*1024;
                int ress = disco[poscont].tamano * m;
                objmbr.mbr_tamano = ress;

            }else if (disco[poscont].unidad.compare("")){
                int ri = 1024;
                cout<<"***entra acaaa"<<endl;
                objmbr.mbr_tamano = ri;

            }
            //fecha de creacion
            
            
            objmbr.mbr_fecha_creacion = time(NULL);
            //número random
            int a=0, valor=0;
            a = rand(); // Genera un valor entre 0 y RAND_MAX
            objmbr.mbr_dsk_signature = a;




            if ((disco[poscont].ajuste.compare("FF")==0)){
                cout<<"FF-----------------"<<endl;

                objmbr.dsk_fit = 'F';

            }else if((disco[poscont].ajuste.compare("BF")==0)){
                objmbr.dsk_fit = 'B';

            }else if ((disco[poscont].ajuste.compare("WF")==0)){
                objmbr.dsk_fit = 'W';

            }


            fstream fichero;
            const char * c = disco[poscont].path.c_str();
            fichero.open (c, ios::in | ios::binary | ios::out);
            fichero.seekp(0); //posición cero del archivo bin
            fichero.write((char*)&objmbr, sizeof(mbr));
            
            int pos = fichero.tellp();
            
            printf("Posicion del puntero de archivo luego grabar un struct:%i\n", pos);
            fichero.close();               
      

}

void guardafdisk(string a, string ty, int& vl){
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
            string s = "Error";
            fdisc[posfdisk].letra = s;
            vl = 1;


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
            vl = 1;
        }


    }else if ((fdisc[posfdisk].tipoparti.compare(""))==0){
        cout<<"crea particion Primaria"<<endl;
        string pri = "P";
        fdisc[posfdisk].tipoparti = pri;

    } else if ((a.compare("-f"))==0){

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
                vl = 1;
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
        for (size_t i = 0; i < b.length(); i++)
        {
            /* code */
            fdisc[posfdisk].nombre[i]=b[i];
        }

        cout<<fdisc[posfdisk].nombre<<endl;

       // arrparticion.mbr_partition_1.part_name = c;
    }else if ((a.compare("-add"))==0){
        cout<<b<<endl;
        fdisc[posfdisk].add = b;
    }else if ((fdisc[posfdisk].ajuste.compare(""))==0){
        cout<<"Tiene el pero ajuste "<<endl;
        string wr = "WorstFit";
        fdisc[posfdisk].ajuste = wr;
}

}


void gestionarchivobin(){
    int wd=0;
    int ne =1;
    int tamtotal = 0;
    cout<<"00000000000000000  crear particion "<<endl;
        for (size_t j = 0; j < poscont; j++)
        {
            fflush(stdin);
            //PARA LOS ATRIBUTOS DEL MBR
            if((fdisc[posfdisk].path.compare(disco[j].path))==0){
                wd=0;
                //primero consultar si hay algo en mi archivo bin

                consultararchivobin(fdisc[posfdisk].path, ne, tamtotal);

                if (ne != 1){
                    cout<<"-Partición encontrada"<<endl;
                    cout<<tamtotal<<endl;
                    particion(ne, tamtotal);
              
                }else {
                    cout<<"-Partición no encontrada"<<endl;
                    cout<<tamtotal<<endl;
                    particion(ne, tamtotal);


                }


            }

    }if (wd==0){

    }else{
        cout<<"No se escontro ningun disco en esa ubicación"<<endl;
    }

}
void consultararchivobin(string pat, int& ne, int& tamtotal ){
    cout<<"Consultarrr"<<endl;
    char activa = 'A';

    FILE *arch;
    const char * c = pat.c_str();
    arch = fopen(c, "rb");

    if (arch == NULL)
        exit(1);

    mbr temp;
    fread(&temp, sizeof(mbr), 1, arch);
    while (!feof(arch))
    {
        
        
        if (temp.mbr_tamano !=0){
            cout<<"-------entra en connsultar "<<endl;
            printf("%i \n", temp.mbr_tamano );
            printf("%s", ctime(&temp.mbr_fecha_creacion));
            printf("%i \n", temp.mbr_dsk_signature );
            printf("%c \n", temp.dsk_fit);
            
            
        }
        if (temp.mbr_partition_1.part_status==activa) {  
            printf("%s \n",temp.mbr_partition_1.part_name);
            printf("%c \n",temp.mbr_partition_1.part_status);
            printf("%c \n",temp.mbr_partition_1.part_fit);
            printf("%i \n",temp.mbr_partition_1.part_start);
            printf("%i \n",temp.mbr_partition_1.part_s);
            printf("%s \n",temp.mbr_partition_1.part_name);
            cout<<"-----"<<endl;
            ne++;


        }

            if (ne == 1){
               // cout<<"AQUIIIIIIII"<<endl;
                temp.mbr_partition_1.part_start = sizeof(mbr);
                tamtotal = temp.mbr_partition_1.part_start;
            
        
            }else if(ne == 2){
                temp.mbr_partition_2.part_start = temp.mbr_partition_1.part_start;
                tamtotal =temp.mbr_partition_2.part_start;

            }else if (ne == 3){
                temp.mbr_partition_3.part_start = temp.mbr_partition_2.part_start;
                tamtotal=temp.mbr_partition_2.part_start;

            }else if (ne == 4){
                temp.mbr_partition_4.part_start = temp.mbr_partition_3.part_start;
                tamtotal = temp.mbr_partition_3.part_start;

            }
        
           


         
        
        
        fread(&temp, sizeof(mbr), 1, arch);
    }

            cout<<"saleee"<<endl;



    fclose(arch);


}

void particion(int ne, int tamtotal ){
    cout<<"dentro de particion ------------------"<<endl;
            
        if ((fdisc[posfdisk].ajuste.compare("")==0)){

            fdisc[posfdisk].ajuste = "WorsFit";
            objpartiAjuste(ne,'W');
            
            cout<<"fdisk -f->peor ajuste "<<endl;
        }
        
        for (size_t i = 0; i < 20; i++)
        {
            /* code */
            objparti.mbr_partition_1.part_name[i] = fdisc[posfdisk].nombre[i];
            if (ne==1){
                objparti.mbr_partition_1.part_name[i] = fdisc[posfdisk].nombre[i];;
            }else if (ne==2){
                objparti.mbr_partition_2.part_name[i] = fdisc[posfdisk].nombre[i];;

            }else if (ne==3){
                objparti.mbr_partition_3.part_name[i] = fdisc[posfdisk].nombre[i];;

            }else if (ne==4){
                objparti.mbr_partition_4.part_name[i]= fdisc[posfdisk].nombre[i];;

            }
        }
        cout<<"tamaño start"<<endl;
        cout<<tamtotal<<endl;
        objpartiStart(ne, tamtotal);
        objpartiStatus(ne, 'A');

        
            

        if ((fdisc[posfdisk].tipoparti.compare("P"))==0){
            cout<<"fdisk -t->P "<<endl;
            objpartiTipo(ne, 'P');
            

        }else if ((fdisc[posfdisk].tipoparti.compare("E"))==0){
        
                cout<<"fdisk -t->E"<<endl;
                objpartiTipo(ne, 'E');
          

        }else if ((fdisc[posfdisk].tipoparti.compare("L"))==0){
                cout<<"No hay extendidas. Error "<<endl;
                objpartiTipo(ne, 'L');
        }
        
        if ((fdisc[posfdisk].ajuste.compare("BestFit"))==0){
            cout<<"fdisk -f->BestFit "<<endl;
            objpartiAjuste(ne,'B');

        }else if ((fdisc[posfdisk].ajuste.compare("FirstFit"))==0){
            cout<<"fdisk -f->FirstFit  "<<endl;
            objpartiAjuste(ne,'F');

        }else if ((fdisc[posfdisk].ajuste.compare("WorsFit"))==0){
            cout<<"fdisk -f->WorstFit "<<endl;
            objpartiAjuste(ne,'W');

    
        }else{
           
        }
        
        
        string pat = fdisc[posfdisk].path;

        if((fdisc[posfdisk].letra.compare("K")==0)){

        int ac = fdisc[posfdisk].tamano * 1024;
        cout<<ac<<endl;
        objpartiPart_S(ne, ac);
        espacio(ac,pat,ne);

        }else if ((fdisc[posfdisk].letra.compare("B")==0)){
            cout<<"bytes"<<endl;
            int as = fdisc[posfdisk].tamano;
            cout<<as<<endl;

            objpartiPart_S(ne, as);
            espacio(as,pat,ne);


        }else if ((fdisc[posfdisk].letra.compare("M")==0)){
            cout<<"megabytes"<<endl;
            int ss = 1024*1024;
            int aw = fdisc[posfdisk].tamano * ss;  

            objpartiPart_S(ne, aw);
            espacio(aw,pat,ne);

        }else if ((fdisc[posfdisk].letra.compare("")==0)){
            cout<<"Particion en kilobytes"<<endl;
            int ao = fdisc[posfdisk].tamano *1024;

            objpartiPart_S(ne, ao);
            espacio(ao,pat,ne);
        }
        
}



void espacio (int result,string pat, int ne){

     if (objmbr.mbr_tamano>result){
        
            cout<<"Registro de particion  con exito"<<endl;
            cout<<objmbr.mbr_tamano<<endl;
            cout<<objmbr.mbr_fecha_creacion<<endl;
            cout<<objmbr.mbr_dsk_signature<<endl;
            cout<<objmbr.dsk_fit<<endl;
    

            if (ne==0){
                cout<<"guarda en el archivo bin "<<endl;
                int result =0;
                //guarda el MBR
                
                posicionarchibin(pat,result);
            }else{
                posicionarchibin(pat, result);
            }


        }else{
            cout<<"No hay sufiente espacio en Disco"<<endl;

        }
}





void posicionarchibin(string pat, int result){
    //resivira un numero (representan un byte en el archiv bin) para guardar la informacion 
    //de la particion 
    cout<<"escribe en archivo binario la particion--------------------------------------------"<<endl;

    fstream fichero;
    const char * c = pat.c_str();
    cout<<c<<endl;
    fichero.open (c, ios::in | ios::binary | ios::out); 
    fichero.seekp(sizeof(mbr)); 
    fichero.write((char*)&objparti, sizeof(mbr));
    fichero.close();



    cout<<"Consultarrr de nuevo "<<endl;
    char activa = 'A';
    FILE *arch;
 
    arch = fopen(c, "rb");

    if (arch == NULL)
        exit(1);

    mbr temp;
    fread(&temp, sizeof(mbr), 1, arch);
    while (!feof(arch))
    {
    
        
        if (temp.mbr_tamano !=0){
            cout<<"-------entra en if "<<endl;
           printf("%i \n", temp.mbr_tamano );
           printf("%s", ctime(&temp.mbr_fecha_creacion));
           printf("%i \n", temp.mbr_dsk_signature );
           printf("%c \n", temp.dsk_fit);
            
        
            cout<<"-----"<<endl;
        }
        if (temp.mbr_partition_1.part_status==activa) {  
            printf("%s \n",temp.mbr_partition_1.part_name);
            printf("%c \n",temp.mbr_partition_1.part_status);
            printf("%c \n",temp.mbr_partition_1.part_fit);
            printf("%i \n",temp.mbr_partition_1.part_start);
            printf("%i \n",temp.mbr_partition_1.part_s);
            printf("%s \n",temp.mbr_partition_1.part_name);

        }
        
        fread(&temp, sizeof(mbr), 1, arch);
    }

            cout<<"saleee"<<endl;



    fclose(arch);



}


void particiones(int ne){

}