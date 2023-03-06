typedef struct ro{
	char name[20];
	int phno;
}ro;

typedef struct {
        char name[20];
        int phno;
        int id;
	int x;
	int y;
}cu;// current user
struct item{ 
        char name[20];
        int no;
        int price;
        struct item * next;
};

struct oitem{
	char name[20];
	int qty;
	int price;
	struct oitem * next;
};

struct restaurant{// done by Aaditya Gole IMT2022087
        char name[20];
        char location[50];
        struct item * head;
	int x;
	int y;
};

struct restaurant1
{
        char username[100];
        char password[100];
};

struct user
{
        char username[100];
        char password[100];
	char number[20];
	char email[100];
};

