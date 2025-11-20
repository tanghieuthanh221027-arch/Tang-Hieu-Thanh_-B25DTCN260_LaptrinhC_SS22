#include <stdio.h>
#include <string.h>

#define MAX 100 

struct Birthday {
    int day , month , year ;
};

struct Ustudent {
    char id[15];
    char fullname[50];
    char address[50];
    char phoneNumber[15];
    struct Birthday date;
};

void inputInfor(struct Ustudent students[], int index){
    getchar();
    printf("Nhap ma sinh vien: ");
    fgets(students[index].id, 15, stdin);
    students[index].id[strcspn(students[index].id, "\n")] = '\0';

    printf("Nhap ho va ten sinh vien: ");
    fgets(students[index].fullname, 50, stdin);
    students[index].fullname[strcspn(students[index].fullname, "\n")] = '\0';

    printf("Nhap ngay thang nam sinh: ");
    scanf("%d %d %d", &students[index].date.day, &students[index].date.month, &students[index].date.year);
    getchar();

    printf("Nhap dia chi: ");
    fgets(students[index].address, 50, stdin);
    students[index].address[strcspn(students[index].address, "\n")] = '\0';

    printf("Nhap so dien thoai: ");
    fgets(students[index].phoneNumber, 15, stdin);
    students[index].phoneNumber[strcspn(students[index].phoneNumber, "\n")] = '\0';
}

int inputList(struct Ustudent students[]){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("\nSinh vien %d\n", i + 1);
        inputInfor(students, i);  
    }
    return n;
}

void printList(struct Ustudent students[], int n){
    if(n == 0){
        printf("Danh sach trong!\n");
        return;
    }

    printf("\n--- Danh sach sinh vien ---\n");
    for(int i = 0; i < n; i++){
        printf("\nSinh vien %d\n", i + 1);
        printf("Ma sinh vien: %s\n", students[i].id);
        printf("Ho va ten: %s\n", students[i].fullname);
        printf("Ngay sinh: %d/%d/%d\n", students[i].date.day, students[i].date.month, students[i].date.year);
        printf("Dia chi: %s\n", students[i].address);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }
}

int addStudent(struct Ustudent students[], int n){
    if(n >= MAX){
        printf("Danh sach full!\n");
        return n;
    }

    printf("Nhap thong tin sinh vien moi:\n");
    getchar();

    printf("Nhap id: ");
    fgets(students[n].id, 15, stdin);
    students[n].id[strcspn(students[n].id, "\n")] = '\0';

    printf("Nhap ho va ten: ");
    fgets(students[n].fullname, 50, stdin);
    students[n].fullname[strcspn(students[n].fullname, "\n")] = '\0';

    printf("Nhap ngay thang nam sinh: ");
    scanf("%d %d %d", &students[n].date.day, &students[n].date.month, &students[n].date.year);
    getchar();

    printf("Nhap dia chi: ");
    fgets(students[n].address, 50, stdin);
    students[n].address[strcspn(students[n].address, "\n")] = '\0';

    printf("Nhap so dien thoai: ");
    fgets(students[n].phoneNumber, 15, stdin);
    students[n].phoneNumber[strcspn(students[n].phoneNumber, "\n")] = '\0';

    printf("Them thanh cong!\n");
    return n + 1;
}

int deleteStudent(struct Ustudent students[], int n, char id[]){
    int found = -1;

    for(int i = 0; i < n; i++){
        if(strcmp(students[i].id, id) == 0){
            found = i;
            break;
        }
    }

    if(found == -1){
        printf("Khong tim thay id sinh vien!\n");
        return n;
    }

    for(int i = found; i < n - 1; i++){
        students[i] = students[i + 1];
    }

    printf("Xoa sinh vien thanh cong!\n");
    return n - 1;
}

void updateInfor(struct Ustudent students[], int n, char id[]){
    int pos = -1;

    for(int i = 0; i < n; i++){
        if(strcmp(students[i].id, id) == 0){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        printf("Khong tim thay id sinh vien!\n");
        return;
    }

    printf("Cap nhat thong tin cho %s\n", id);
    getchar();

    printf("Nhap ten moi: ");
    fgets(students[pos].fullname, 50, stdin);
    students[pos].fullname[strcspn(students[pos].fullname, "\n")] = '\0';

    printf("Nhap ngay thang nam sinh moi: ");
    scanf("%d %d %d", &students[pos].date.day, &students[pos].date.month, &students[pos].date.year);
    getchar();

    printf("Nhap dia chi moi: ");
    fgets(students[pos].address, 50, stdin);
    students[pos].address[strcspn(students[pos].address, "\n")] = '\0';

    printf("Nhap so dien thoai moi: ");
    fgets(students[pos].phoneNumber, 15, stdin);
    students[pos].phoneNumber[strcspn(students[pos].phoneNumber, "\n")] = '\0';

    printf("Cap nhat thong tin thanh cong!\n");
}

void arrangeName(struct Ustudent students[], int n){
    struct Ustudent temp;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(strcmp(students[i].fullname, students[j].fullname) > 0){
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("Sap xep thanh cong!\n");
}

void findStudent(struct Ustudent students[], int n, char id[]){
    for(int i = 0; i < n; i++){
        if(strcmp(students[i].id, id) == 0){
            printf("\nTim thay sinh vien!\n");
            printf("Ma sinh vien: %s\n", students[i].id);
            printf("Ho ten: %s\n", students[i].fullname);
            printf("Ngay sinh: %d/%d/%d\n", students[i].date.day, students[i].date.month, students[i].date.year); 
            printf("Dia chi: %s\n", students[i].address);
            printf("So dien thoai: %s\n", students[i].phoneNumber);
            return;
        }
    }
    printf("Khong tim thay sinh vien!\n");
}

int main(){
    int choice;
    int n = 0;
    struct Ustudent students[MAX];
    char id[15];

    do {
        printf("\n+----------------Danh sach sinh vien-------------+\n");
        printf("|1. Nhap thong tin sinh vien                     |\n");
        printf("|2. Hien thi danh sach sinh vien                 |\n");
        printf("|3. Them sinh vien                               |\n");
        printf("|4. Xoa sinh vien theo ma                         |\n");
        printf("|5. Cap nhat thong tin theo ma                    |\n");
        printf("|6. Sap xep theo ten                              |\n");
        printf("|7. Tim kiem sinh vien theo ma                    |\n");
        printf("|8. Thoat                                         |\n");
        printf("+------------------------------------------------+\n");

        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: n = inputList(students); break;
            case 2: printList(students, n); break;
            case 3: n = addStudent(students, n); break;

            case 4:
                printf("Nhap id de xoa: ");
                getchar();
                fgets(id, 15, stdin);
                id[strcspn(id, "\n")] = '\0';
                n = deleteStudent(students, n, id);
                break;

            case 5:
                printf("Nhap id de cap nhat: ");
                getchar();
                fgets(id, 15, stdin);
                id[strcspn(id, "\n")] = '\0';
                updateInfor(students, n, id); 
                break;

            case 6: arrangeName(students, n); break;

            case 7:
                printf("Nhap id de tim: ");
                getchar();
                fgets(id, 15, stdin);
                id[strcspn(id, "\n")] = '\0';
                findStudent(students, n, id);
                break;

            case 8:
                printf("Thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(choice != 8);
    return 0;
}

