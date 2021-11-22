#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct sinhvien{
	int id;
	char ten;
	char gioitinh;
};
void xoaxuongdong(char x[]){
	size_t bien=strlen(x);
	if(x[bien-1]=='\n'){
		x[bien-1]='\0';
		}
	}

typedef sinhvien SV;
void nhapsinhvien(SV &sv){
	printf("Nhap id:");scanf("%d",&sv.id);
	printf("Nhap ten:");fflush(stdin);fgets(sv.ten,sizeof(sv.ten),stdin);xoaxuongdong(sv.ten);
	printf("Nhap gioi tinh:");fflush(stdin);fgets(sv.gioitinh,sizeof(sv.gioitinh),stdin);xoaxuongdong(sv.gioitinh);
}
void xuatsinhvien(SV sv){
	printf("%5s\t %10s\t %10s",sv.id,sv.ten,sv.gioitinh);
	printf("%5d\t %10s\t %10s",sv.id,sv.ten,sv.gioitinh);
}
void nhapdssv(SV ds[],int &n){
	printf("Nhap so luong sinh vien:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		nhapsinhvien(ds[i]);
		}
}
void xuatdssv(SV ds[],int i){
	for(int i=0;i<n;i++){
		xuatsinhvien(ds[i]);
		}
	}
void nhapfile(SV ds[],int n){
	char tenfile[50];
	printf("Nhap ten file:");fflush(stdin);fgets(tenfile,sizeof(tenfile),stdin);
	FILE*f;
	f=fopen(tenfile,"rb");
	if(f==NULL){
		printf("loi mo file!!!");
		exit(0);
	}
	fwrite(&n,sizeof(n),1,f);
	for(int i=0;i<n;i++){
		fwrite(&ds[i],sizeof(SV),1,f);
	}
	fclose(f);
	f=fopen(tenfile,"wb");
	fread(n,sizeof(n),1,f);
	for(int i=0;i<n;i++){
		fread(ds[i],sizeof(SV),1,f);
	}	
}
int main(){
	SV sv;
	ds[100];
	int n;
	nhapdssv(ds,n);
	xuatdssv(ds,n);
	nhapfile(ds,n);
}