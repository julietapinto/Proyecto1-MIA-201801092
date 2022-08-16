#include <iostream>
#include <string>
#include <time.h>

void objpartiTipo(int,char);
void objpartiAjuste(int, char);
void objpartiStatus(int , char );
void objpartiStart(int, int);
void objpartiPart_S(int , int);


using namespace std;

struct  partition
{
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_s;
    char part_name [16]; 
    
};
struct mbr{
    int mbr_tamano;
    time_t mbr_fecha_creacion;
    int mbr_dsk_signature;
    char dsk_fit;
    struct partition mbr_partition_1;
    struct partition mbr_partition_2;
    struct partition mbr_partition_3;
    struct partition mbr_partition_4;
    
    
}objmbr,objparti;

void  objpartiTipo(int ne, char carac){
    if (ne==1){
        objparti.mbr_partition_1.part_type = carac;

    }else if (ne==2){
        objparti.mbr_partition_2.part_type = carac;

    }else if (ne == 3){
        objparti.mbr_partition_3.part_type = carac;

    }else if (ne== 4){
        objparti.mbr_partition_4.part_type = carac;

    }

}
void objpartiStatus(int ne, char carac){

        if (ne==1){
                objparti.mbr_partition_1.part_status = carac;
            }else if (ne==2){
                objparti.mbr_partition_2.part_status = carac;

            }else if (ne==3){
                objparti.mbr_partition_3.part_status = carac;

            }else if (ne==4){
                objparti.mbr_partition_4.part_status = carac;

            }

}
void objpartiAjuste(int ne , char carac){
        if (ne==1){
            objparti.mbr_partition_1.part_fit = carac;
        }else if (ne==2){
            objparti.mbr_partition_2.part_fit = carac;

        }else if (ne==3){
            objparti.mbr_partition_3.part_fit = carac;

        }else if (ne==4){
            objparti.mbr_partition_4.part_fit = carac;

        }

}
void objpartiStart(int ne,int tamtotal){
        if (ne==1){
            objparti.mbr_partition_1.part_start = tamtotal;
        }else if (ne==2){
            objparti.mbr_partition_2.part_start = tamtotal;

        }else if (ne==3){
            objparti.mbr_partition_3.part_start = tamtotal;

        }else if (ne==4){
            objparti.mbr_partition_4.part_start = tamtotal;

        }

}
void objpartiPart_S(int ne , int conver){
        if (ne==1){
            objparti.mbr_partition_1.part_s = conver;
        }else if (ne==2){
            objparti.mbr_partition_2.part_s = conver;

        }else if (ne==3){
            objparti.mbr_partition_3.part_s = conver;

        }else if (ne==4){
            objparti.mbr_partition_4.part_s = conver;

        }

}

