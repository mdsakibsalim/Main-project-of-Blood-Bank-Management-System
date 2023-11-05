#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int id;
  char name[50];
  char blood_group[10];
  int age;
  char contact_number[10];
  char address[100];
} donor_info;

donor_info *donors;
int num_donors = 0;

void add_donor() {
  donor_info *donor = malloc(sizeof(donor_info));

  printf("Enter donor ID: ");
  scanf("%d", &donor->id);

  printf("Enter donor name: ");
  scanf("%s", donor->name);

  printf("Enter donor blood group: ");
  scanf("%s", donor->blood_group);

  printf("Enter donor age: ");
  scanf("%d", &donor->age);

  printf("Enter donor contact number: ");
  scanf("%s", donor->contact_number);

  printf("Enter donor address: ");
  scanf("%s", donor->address);

  donors = realloc(donors, (num_donors + 1) * sizeof(donor_info));
  donors[num_donors++] = *donor;
}

void edit_donor() {
  int id;
  donor_info *donor;

  printf("Enter donor ID to edit: ");
  scanf("%d", &id);

  donor = &donors[id - 1];

  printf("Enter donor name: ");
  scanf("%s", donor->name);

  printf("Enter donor blood group: ");
  scanf("%s", donor->blood_group);

  printf("Enter donor age: ");
  scanf("%d", &donor->age);

  printf("Enter donor contact number: ");
  scanf("%s", donor->contact_number);

  printf("Enter donor address: ");
  scanf("%s", donor->address);
}

void delete_donor() {
  int id;

  printf("Enter donor ID to delete: ");
  scanf("%d", &id);

  for (int i = id - 1; i < num_donors - 1; i++) {
    donors[i] = donors[i + 1];
  }

  num_donors--;
}

void print_donors() {
  printf("Donor list:\n");
  printf("ID\tName\tBlood Group\tAge\tContact Number\tAddress\n");

  for (int i = 0; i < num_donors; i++) {
    donor_info *donor = &donors[i];
    printf("%d\t%s\t%s\t%d\t%s\t%s\n", donor->id, donor->name, donor->blood_group, donor->age, donor->contact_number, donor->address);
  }
}


int main() {
    int choice;
    char name[10];
    int password;


    printf("\n");
    printf("*******************************************************\n");
    printf("*                                                     *\n");
    printf("*    Welcome to the Blood Bank Management System      *\n");
    printf("*                                                     *\n");
    printf("*******************************************************\n");
    printf("\n");

    sleep(2);
    system("cls");



    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your password: ");
    scanf("%d", &password);

    if (strcmp(name, "sakib") == 0 && password == 123) {
       donors = malloc(sizeof(donor_info));

  while (1) {
    printf("\nBlood Bank Management System\n");
    printf("1. Add donor\n");
    printf("2. Edit donor\n");
    printf("3. Delete donor\n");
    printf("4. Print donor list\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_donor();
        break;
      case 2:
        edit_donor();
        break;
      case 3:
        delete_donor();
        break;
      case 4:
        print_donors();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }

  }

    } else {
        printf("not valid");
    }

    return 0;
}
