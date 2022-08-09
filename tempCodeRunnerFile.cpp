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
                cout<<"ddddd"<<endl;