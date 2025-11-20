#include <stdio.h>
#include <string.h>

#define MAX 100 

struct Student {
	char name [50] ;
	int age ;
	float grade ;
};

int inputInfor(struct Student student1[]){
	int n ; 
	printf("Nhap so luong hoc sinh : ");
	scanf("%d" , &n);
	getchar();
	
	for(int i = 0 ; i < n ; i++){
		printf("Sinh vien %d\n" , i + 1);
		printf("Nhap ten : ");
		fgets(student1[i].name , 50 , stdin);
		student1[i].name[strcspn(student1[i].name , "\n")] = '\0';
		printf("\nNhap tuoi : ");
		scanf("%d" , &student1[i].age);
		printf("\nNhap diem trung binh : ");
		scanf("%f" , &student1[i].grade);
		getchar();
	}
	return n ;
}

void display (struct Student student1[] , int n){
	if(n == 0){
		printf("Khong co thong tin !\n");
		return ;
	}
	for(int i = 0 ; i < n ; i++){
		printf("Thong tin cua sinh vien\n");
		printf("Ten : %s\n" , student1[i].name);
		printf("Tuoi : %d\n" , student1[i].age);
		printf("Diem trung binh : %.2f\n" , student1[i].grade);
	}
}
float averGrade(struct Student student1[] , int n){
	if(n == 0) return 0 ;
	float sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		sum += student1[i].grade;
	}
	return sum/n ;
}

int main (){
	int choice , n = 0 ;
	struct Student student1 [MAX];
	do {
		printf("+---------------Thong tin sinh vien--------------+\n");
		printf("|1. Nhap thong tin sinh vien                     |\n");
		printf("|2. Hien thi thong tin sinh vien                 |\n");
		printf("|3. Diem trung binh cua tat ca sinh vien         |\n");
		printf("|4. Thoat                                        |\n");
		printf("+------------------------------------------------+\n");
		
		printf("Nhap lua chon : ");
		scanf("%d" , &choice);
		
		switch (choice) {
			case 1 : n = inputInfor (student1); break ;
			case 2 : display(student1 , n); break ;
			case 3 : {
				if(n == 0){
					printf("Khong co thong tin !\n");
				}else {
					printf("Diem trung binh = %.2f" , averGrade(student1 , n));
				}
				break;
			}
			case 4 : printf("Thoat chuong trinh !\n") ;break ;
			default : printf("Lua chon khong hop le ! \n");
		}
	}while ( choice != 4 );
	return 0 ; 
}
