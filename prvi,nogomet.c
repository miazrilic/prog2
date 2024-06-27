/* Deklarirati strukturu nogomet u koju će se spremiti ovakvi ulazni 
podaci: naziv prve momcadi, naziv druge momcadi , golovi_1, golovi_2, datum.
Nazivi momčadi se mogu sastojati od više riječi, dok varijabla golovi_1 predstavlja broj golova
koje je zabila prva momčad, a dok varijabla golovi_2 predstavlja broj golova koje je zabila
druga momčad i može biti samo cijeli broj.
U program se prvo unosi broj utakmica n (0<n<100).
S tipkovnice unijeti sve podatke za svaki od n utakmica. 
	Primjer ulaznih podataka
	 2
	 Njemacka
	 Skotska
	 2
	 0
	 14.06.2024.
	 Spanjolska
	 Hrvatska
	 1
	 2
	 15.06.2024.
    
Nakon ključne riječi REZULTATI: ispisati sve pobjednike u odigranim utakmicama tijekom 6. mjeseca.
Primjer ispisa:
	REZULTATI:  
    Njemacka
    Spanjolska
    */
    #include<stdio.h>
    #include<stdlib.h>
    typedef struct Datum{
        int dan;
        int mjesec;
        int godina;
    }DATUM;
    typedef struct Nogomet{
        char tim1[50];
        char tim2[50];
        int golovi_1;
        int golovi_2;
        DATUM datum;
        
    }NOGOMET;
    int main(){
        
        
         int n;
         do{
            scanf("%d",&n);
        }while(n<=0 ||  n>=100);
        NOGOMET* turnir=(NOGOMET*)malloc(n*sizeof(NOGOMET)); 
        if(turnir==NULL){
            return 1;
        }
        
        
        
        for(int i=0;i<n;i++){
            getchar();
            scanf(" %[^\n]",turnir[i].tim1);
            getchar();
            scanf(" %[^\n]",turnir[i].tim2);
            
            scanf("%d",&turnir[i].golovi_1);
            scanf("%d",&turnir[i].golovi_2);
            scanf("%d.%d.%d",&turnir[i].datum.dan,&turnir[i].datum.mjesec,&turnir[i].datum.godina);
            
        }
       
       printf("REZULTATI:\n");
       for(int i=0;i<n;i++){
           if(turnir[i].datum.mjesec==6 || turnir[i].datum.mjesec==06){
               if(turnir[i].golovi_1<turnir[i].golovi_2){
                   printf("%s\n",turnir[i].tim2);
               }
               else if(turnir[i].golovi_1>turnir[i].golovi_2){
                   printf("%s\n",turnir[i].tim1);
               }
               
               
           }
               
               
           }
           
           
       
       free(turnir);
       return 0;
    }
