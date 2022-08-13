#include <iostream>
#include <string>



using namespace std;

struct  partition
{
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_s;
    char part_name [20]; 
    
};
struct mbr{
    int mbr_tamano;
    string mbr_fecha_creacion;
    int mbr_dsk_signature;
    char dsk_fit;
    struct partition mbr_partition_1;
    struct partition mbr_partition_2;
    struct partition mbr_partition_3;
    struct partition mbr_partition_4;
    
    
}arrparticion;
