#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// /*\ Atlantis /*\ Dog-Shelter Program
/// My function names are pretty descriptive so I didn't use comments on top of every function, but rather I used them where there might be confusions.

struct date{

int day;
int month;
int year;
};

typedef struct table{

int size;
float ratio;
int occupied;

}table;

typedef struct shelter_dog{

int identifier;
char name[30];
float weight;
float height;
struct date entry;
struct date leave;
int hasher;
int adopted;

}shelter_dog;


int main(){

int menu=0;
float ratio;
table hash;
hash.size=11,hash.occupied=0;           //A/Here i'm trying to be smart and using the "table" struct above, i'm trying to hold the ratio of my hash table.
//ratio = hash.size/hash.occupied;
shelter_dog dog[hash.size];

while(menu != 4){

    printf("Please choose what you would like to do.\n1- Add Dog\n2- Adopt\n3- Search\n4- Exit\n");
    scanf("%d",&menu);

    switch(menu){
        case 1: insert(dog,hash.size);break;
        case 2: adopt(dog,hash.size);break;
        case 3: search(dog,hash.size);break;
        case 4: break;
        default: printf("The option you entered is invalid, try again.");scanf("%d",&menu);break;}

}

return 0;
}

//T/ This function uses identifier and hash table size to find the key.

int h(int identifier,int size){

    int key = identifier % size;
    return key;
}

//L/ This function here is where we insert now dogs to the shelter.

int insert(shelter_dog dog[],int size){

    int identifier,hasher=1;
    printf("\nEnter unique identifier: ");
    scanf("%d",&identifier);
    int key = h(identifier, size);

    while (dog[key].identifier != NULL){
        key = (key + (hasher*hasher))%size;     //A/ I added a "hasher" here to be able to do the quadratic probing.
        hasher++;
      //  printf("in while");
    }
//printf("out while");
//printf("this is hasher:  %d\n",hasher);
    dog[key].identifier= key;
    printf("Enter name: ");
    scanf("%s",&dog[key].name);
    printf("Enter weight: ");                   //N/ Adding the dog to the array.
    scanf("%f",&dog[key].weight);
    printf("Enter height: ");
    scanf("%f",&dog[key].height);
    printf("Enter entry date: ");
    scanf("%d.%d.%d",&dog[key].entry.day,&dog[key].entry.month,&dog[key].entry.year);
    printf("%s has been added to the dog shelter.\n",dog[key].name);
    dog[key].adopted = 0;                                               //T/ I added an "adopted" attribute to my struct for the dog. To easily check if it's adopted or not.

//printf("date entry: %d.%d.%d\n",dog[key].entry.day,dog[key].entry.month,dog[key].entry.year);
//printf("name is : %s \n",dog[key].name);
//printf("weight is: %f \n",dog[key].weight);
//printf("height is: %f \n",dog[key].height);
//printf("identifier is: %d \n",dog[key].identifier);

return dog;
}

int search(shelter_dog dog[],int size){

    int identifier,hasher=1,fake_key;
    printf("\nEnter unique identifier: ");
    scanf("%d",&identifier);
    int key = h(identifier, size);              //I/ Added a "fake key" to be able to go back to the last probed dog with the same key.
    fake_key = key;

    if(dog[key].identifier == NULL){
        printf("\nNo dog is found.\n");
        return key;
    }

    while (dog[fake_key].identifier != NULL){
        fake_key = (fake_key + (hasher*hasher))%size;
        hasher++;
      //  printf("in while");
    }

    if(dog[key].identifier != NULL){
        hasher = hasher - 2;                    //S/ This helps me find the wanted dog by searching for the NULL identifier and going 2 steps back as mentioned above
        key = (key + (hasher * hasher))%size;   //A/ Setting the real key to be used for the rest of the code here.
    }

    printf("Name: %s \n",dog[key].name);
    printf("Weight: %f \n",dog[key].weight);            //T/ Printing the wanted dog.
    printf("Height: %f \n",dog[key].height);
    printf("Entry Date: %d.%d.%d\n",dog[key].entry.day,dog[key].entry.month,dog[key].entry.year);


return key;          //L/ Returning the key to be used in "adopt" function. To make things easier in a way. This return has no use in main!!
}

int adopt(shelter_dog dog[],int size){

    int key;
    key = search(dog,size);      //A/ Printing the dog if the dog is found with use of "search" function and setting the key for the rest.

     if(dog[key].identifier == NULL){
        return dog;
     }
     else if (dog[key].adopted == 1){
        printf("Dog is already adopted!\n");            //N/ Checking if the dog is adopted or not.
        return dog;
     }

    else{
        dog[key].adopted = 1;               //T/ If not adopted setting adopted to 1 and getting a leave date. The dog is adopted at this point.
        printf("Enter leave date: ");
        scanf("%d.%d.%d",&dog[key].leave.day,&dog[key].leave.month,&dog[key].leave.year);
        return dog;
        }
}

//Used **ATLANTIS** as a signature. Thanks for everything.
