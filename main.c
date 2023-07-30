#include <stdio.h>
#include <stdlib.h>
FILE* fpr, * fpw;
int i, x, y;

char tmusteriadi[15];
char musteriadi[15];
char tmusterisoyadi[15];
char musterisoyadi[15];
long long ta[9999999][9];
long long tmusterino, tbutce, tpassword,tcekilenpara,tyatanpara;
long long musterino,password,cekilenpara,yatanpara,butce;
long long pass,mus;
int a;


int main() {
	printf("(1) Musteri Ol!\n");
	printf("(2) Giris Yap!\n");
	printf("Lutfen islem seciniz:");
	scanf("%d", &i);
	if (i == 1) {
		fpw = fopen("atm.txt", "a");
		tbutce=0;
		printf("Musteri No(TC KIMLIK) Giriniz:");
		scanf("%lld", &tmusterino);
		ta[x][0] = tmusterino;
		printf("Adiniz:");
		scanf("%s", &tmusteriadi);
		printf("Soyadiniz:");
		scanf("%s", &tmusterisoyadi);
		printf("Lutfen sifrenizi olusturun:");
		scanf("%lld",&tpassword);
		ta[x][1]=tpassword;
		printf("\nLutfen Yatirilacak para miktarini girin:");
		scanf("%lld",&tbutce);
		ta[x][2]=tbutce;
		fprintf(fpw,"%lld %s %s %lld %lld\n",tmusterino, tmusteriadi,tmusterisoyadi,tpassword,tbutce);
		
	}
	if(i==2){

		fpr=fopen("atmaz.txt","r");
		printf("Musteri No:");
		scanf("%lld",&mus);
		long long gecici;
		while(fscanf(fpr,"%lld %s %s %lld %lld\n",&musterino,&musteriadi,&musterisoyadi,&password,&butce)!=EOF){
		if(musterino==mus){
		printf("Sifrenizi Girin:");
		scanf("%lld",&pass);
		if(password==pass){
		printf("(1) Hesap Bakiyesi Ogrenme\n");
		printf("(2) Para Cekme\n");
		printf("(3) Para Yatirma\n");
		printf("Lutfen islem seciniz:");
		scanf("%d",&a);
			
			switch(a){
				while(fscanf(fpr,"%lld",&butce)!=EOF){
				case 1:printf("Bakiyeniz:%lld",butce);
				break;
				case 2:
				printf("Cekilecek Miktari Giriniz:");
				scanf("%lld",&gecici);
				butce=butce-gecici;
				printf("Yeni Bakiyeniz:%lld",butce); 
				fprintf(fpw,"%lld",butce);
				
			
				break;
				case 3:printf("Yatirilacak Para:");
				scanf("%lld",&gecici);
				butce=butce+gecici;
				printf("Yeni Bakiyeniz",butce);
				fprintf(fpw,"%lld",butce);
				break;
				
				default:printf("Gecerli Bir Islem Secmediniz!!");
						
					}
			
			}
	}
	else
			printf("Musteri No veya Sifrenizi Kontrol Ediniz!!");
		//printf("%lld %s %s %lld %lld\n",musterino,musteriadi,musterisoyadi,password,butce);
	}
		}
		fclose(fpr);
		}
fclose(fpw);
}


