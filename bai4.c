#include <stdio.h>
#include <string.h>

#define MAX 100 

struct Date {
	int day , month , year ;
};

struct Order {
	char id[15] ;
	char customerName [50] ;
	float total ;
	char status [50] ;
	struct Date dateReceipt ;
};

int inputOrder(struct Order orders[] , int n ){
	int x ; 
	printf("Nhap so luong hang : ");
	scanf("%d" , &x);
	getchar();
	
	for (int i = 0 ; i < n ; i++){
		printf("Don hang %d\n" , i + 1);
		printf("Ma don hang: ");
        fgets(orders[n].id, sizeof(orders[n].id), stdin);
        orders[n].id[strcspn(orders[n].id, "\n")] = '\0';

        printf("Ten khach hang: ");
        fgets(orders[n].customerName, sizeof(orders[n].customerName), stdin);
        orders[n].customerName[strcspn(orders[n].customerName, "\n")] = '\0';

        printf("Ngay dat hang (d m y): ");
        scanf("%d %d %d", &orders[n].dateReceipt.day, &orders[n].dateReceipt.month, &orders[n].dateReceipt.year);

        printf("Tong tien: ");
        scanf("%f", &orders[n].total);
        getchar();

        printf("Trang thai (Dang xu ly / Da giao / Huy): ");
        fgets(orders[n].status, sizeof(orders[n].status), stdin);
        orders[n].status[strcspn(orders[n].status, "\n")] = '\0';

        n++;
	}
	return n ; 
}

void printOrder (struct Order orders[] , int n){
	if (n == 0) {
        printf("Danh sach don hang rong!\n");
        return;
    }

    printf("\nDANH SACH DON HANG\n");
    for (int i = 0; i < n; i++) {
        printf("\nDon hang %d:\n", i + 1);
        printf("Ma don: %s\n", orders[i].id);
        printf("Khach hang: %s\n", orders[i].customerName);
        printf("Ngay dat: %02d/%02d/%04d\n",
               orders[i].dateReceipt.day, orders[i].dateReceipt.month, orders[i].dateReceipt.year);
        printf("Tong tien: %.2f\n", orders[i].total);
        printf("Trang thai: %s\n", orders[i].status);
    }
}

void updateStatus(struct Order orders[], int n) {
    char code[20];
    getchar();
    printf("Nhap ma don hang can cap nhat: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(orders[i].id, code) == 0) {
            printf("Nhap trang thai moi: ");
            fgets(orders[i].status, sizeof(orders[i].status), stdin);
            orders[i].status[strcspn(orders[i].status, "\n")] = '\0';
            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay ma don hang!\n");
}

int deleteOrder(struct Order orders[], int n) {
    char code[20];
    getchar();
    printf("Nhap ma don hang can xoa: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(orders[i].id, code) == 0) {
            for (int j = i; j < n - 1; j++)
                orders[j] = orders[j + 1];
            printf("Xoa thanh cong!\n");
            return n - 1;
        }
    }

    printf("Khong tim thay ma don hang!\n");
    return n;
}

void sortOrders(struct Order orders[], int n) {
    int choice;
    printf("1. Tang dan\n2. Giam dan\nChon: ");
    scanf("%d", &choice);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int needSwap = 0;

            if (choice == 1 && orders[i].total > orders[j].total)
                needSwap = 1;
            else if (choice == 2 && orders[i].total < orders[j].total)
                needSwap = 1;

            if (needSwap) {
                struct Order tmp = orders[i];
                orders[i] = orders[j];
                orders[j] = tmp;
            }
        }
    }

    printf("Sap xep thanh cong!\n");
}

void searchOrder(struct Order orders[], int n) {
    char code[20];
    getchar();
    printf("Nhap ma don hang can tim: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(orders[i].id, code) == 0) {
            printf("\n--- Don hang tim thay ---\n");
            printf("Ma don: %s\n", orders[i].id);
            printf("Khach hang: %s\n", orders[i].customerName);
            printf("Ngay dat: %02d/%02d/%04d\n",
                   orders[i].dateReceipt.day, orders[i].dateReceipt.month, orders[i].dateReceipt.year);
            printf("Tong tien: %.2f\n", orders[i].total);
            printf("Trang thai: %s\n", orders[i].status);
            return;
        }
    }

    printf("Khong tim thay don hang!\n");
}

int main (){
	struct Order orders[MAX];
    int n = 0;
    int choice;

    do {
        printf("\n+--------------MENU-------------+\n");
        printf("|1. Nhap don hang                 |\n");
        printf("|2. Hien thi                      |\n");
        printf("|3. Cap nhat trang thai           |\n");
        printf("|4. Xoa don hang                  |\n");
        printf("|5. Sap xep theo tong tien        |\n");
        printf("|6. Tim kiem                      |\n");
        printf("|7. Thoat                         |\n");
        printf("+---------------------------------+\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: n = inputOrder(orders, n); break;
            case 2: printOrder(orders, n); break;
            case 3: updateStatus(orders, n); break;
            case 4: n = deleteOrder(orders, n); break;
            case 5: sortOrders(orders, n); break;
            case 6: searchOrder(orders, n); break;
            case 7: printf("Thoat!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }

    } while (choice != 7);

    return 0;
}
