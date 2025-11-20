#include <stdio.h>
#include <string.h>

#define MAX 100 

struct Contact {
	char name[50] , phoneNumber[15] , email[50] ;
};

int addContact (struct Contact contacts[] , int n ){
	if(n >= MAX){
		printf("Danh ba day !\n");
		return n ;
	}
	getchar();
	
	printf("Nhap ten : ");
	fgets(contacts[n].name , 50 , stdin);
	contacts[n].name[strcspn(contacts[n].name , "\n")] = '\0';
	
	printf("Nhap so dien thoai : ");
	fgets(contacts[n].phoneNumber , 15 , stdin);
	contacts[n].phoneNumber[strcspn(contacts[n].phoneNumber , "\n")] = '\0';
	
	printf("Nhap email : ");
	fgets(contacts[n].email , 50 , stdin);
	contacts[n].email[strcspn(contacts[n].email , "\n")] = '\0';
	
	printf("Them lien he thanh cong ! \n");
	return n + 1 ;
}

void printContact (struct Contact contacts[] , int n){
	if(n == 0){
		printf("Khong co thong tin lien he !\n");
		return ;
	}
	for(int i = 0 ; i < n ; i++){
		printf("Thong tin lien he %d\n" , i + 1);
		printf("Ten : %s\n" , contacts[i].name);
		printf("So dien thoai : %s\n" , contacts[i].phoneNumber);
		printf("Email : %s\n" , contacts[i].email);
	}
}

void findContact (struct Contact contacts[] , int n){
	char nameContact[50] ;
	getchar();
	printf("Nhap ten lien he can tim : ");
	fgets(nameContact , 50 , stdin);
	nameContact[strcspn(nameContact , "\n")] = '\0';
	
	int flag = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(strstr(contacts[i].name , nameContact) != NULL){
			if(!flag){
				printf("Ket qua tim kiem : ");
				flag = 1 ;
			}
			printf("\nTen : %s \nSo dien thoai : %s \nEmail : %s \n" , contacts[i].name , contacts[i].phoneNumber , contacts[i].email);
		}
	}
	if(!flag){
		printf("Khong tim thay !\n");
	}
}

int deleteContact (struct Contact contacts[] , int n ){
	char deleteName[50] ;
	getchar();
	
	printf("Nhap ten lien he can xoa : ");
	fgets(deleteName , 50 , stdin);
	deleteName[strcspn(deleteName , "\n")] = '\0';
	
	int found = -1 ;
	for(int i = 0 ; i < n ; i++){
		if(strcmp(contacts[i].name , deleteName) == 0){
			found = i ;
			break ;
		}
	}
	
	if(found == -1){
		printf("Khong tim thay ten lien he de xoa !\n");
		return n ;
	}
	
	for (int i = found ; i < n - 1 ; i++){
		contacts[i] = contacts[i+1];
	}
	printf("Xoa lien he thanh cong !\n");
	return n - 1;
}

int main (){
	struct Contact contacts[MAX];
	int choice ;
	int n = 0 ;
	do {
		printf("+----------Thong tin lien he----------+\n");
		printf("|1. Them moi lien he                  |\n");
		printf("|2. Hien thi tat ca lien he           |\n");
		printf("|3. Tim kiem theo ten lien he         |\n");
		printf("|4. Xoa lien he theo ten lien he      |\n");
		printf("|5. Thoat                             |\n");
		printf("+-------------------------------------+\n");
		
		printf("Nhap lua chon : ");
		scanf("%d" , &choice);
		
		switch (choice) {
			case 1 : n = addContact(contacts , n); break ;
			case 2 : printContact(contacts , n); break ;
			case 3 : findContact(contacts , n); break ;
			case 4 : n = deleteContact(contacts , n); break ;
			case 5 : printf("Thoat chuong trinh !"); break ;
			default : printf("Lua chon khong hop le !\n");
		}
	}while (choice != 5);
	return 0 ;
}
