#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

int base,octet1,octet2,octet3,octet4,subnet1,subnet2,subnet3,subnet4,menu,binNum,i,remainder,length1,length2,length3,first,second,third,hosts,counter,counter1,counter2,counter3,counter4;
char oct11,oct12,oct21,oct22,oct31,oct32,oct41,oct42,sub11,sub12,sub21,sub22,sub31,sub32,sub41,sub42; // For base 16 //  //oct11 representing octet1 1st character //
int origoct1,origoct2,origoct3,origoct4,origsub1,origsub2,origsub3,origsub4,origgsub1,origgsub2,origgsub3,origgsub4;

while (menu != 6){


printf("Please enter the Base of your IP Address (10/16) :");
scanf("%d",&base);

while (base != 10 && base != 16){

    printf("\nSorry that is not a valid base!\n");
    printf("Please enter the Base of your IP Address (10/16) :");
    scanf("%d",&base);
}

if (base == 10){
    printf("Please enter the IP Address :\n");
    scanf("%d.%d.%d.%d",&octet1,&octet2,&octet3,&octet4);

    if( (octet1 < 256) && (octet2 < 256) && (octet3 < 256) && (octet4 < 256)){

        printf("Thanks it is a valid IP Address.\n");
        printf("Please enter the Subnet Mask :\n");
        scanf("%d.%d.%d.%d",&subnet1,&subnet2,&subnet3,&subnet4);

        if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }

        else {

            printf("Please enter the Subnet Mask :\n");
            scanf("%d.%d.%d.%d",&subnet1,&subnet2,&subnet3,&subnet4);

        }
    }

    else{

        printf("Please enter the IP Address :\n");
        scanf("%d.%d.%d.%d",&octet1,&octet2,&octet3,&octet4);

        if( (octet1 < 256) && (octet2 < 256) && (octet3 < 256) && (octet4 < 256)){

        printf("Thanks it is a valid IP Address.\n");
        printf("Please enter the Subnet Mask :\n");
        scanf("%d.%d.%d.%d",&subnet1,&subnet2,&subnet3,&subnet4);

        if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
            }

        else {

            printf("Please enter the Subnet Mask :\n");
            scanf("%d.%d.%d.%d",&subnet1,&subnet2,&subnet3,&subnet4);

        }

        }
    }

origoct1 = octet1;
origoct2 = octet2;
origoct3 = octet3;
origoct4 = octet4;

origsub1 = subnet1;
origsub2 = subnet2;
origsub3 = subnet3;        // Here I prevented the user to get the binary of the subnet or the IP , and after that trying to find host addresses.
origsub4 = subnet4;         // Which is a problem because it converts the IP or the Subnet to binary twice, which concludes in wrong stuff.

origgsub1 = subnet1;
origgsub2 = subnet2;
origgsub3 = subnet3;           // This is to fix an error which caused an error using menu function 4 after the 3rd one.
origgsub4 = subnet4;


}

else if (base == 16){

printf("Please enter the IP Address :\n");

scanf(" %c %c. %c %c. %c %c. %c %c",&oct11,&oct12,&oct21,&oct22,&oct31,&oct32,&oct41,&oct42);

oct11 = (oct11 - 48);
oct12 = (oct12 - 48);
oct21 = (oct21 - 48);
oct22 = (oct22 - 48);
oct31 = (oct31 - 48);
oct32 = (oct32 - 48);
oct41 = (oct41 - 48);
oct42 = (oct42 - 48);

if (oct11 > 10){
    oct11 = oct11 - 7;}
if (oct12 > 10){
    oct12 = oct12 - 7;}
if (oct21 > 10){
    oct21 = oct21 - 7;}
if (oct22 > 10){
    oct22 = oct22 - 7;}
if (oct31 > 10){
    oct31 = oct31 - 7;}
if (oct32 > 10){
    oct32 = oct32 - 7;}
if (oct41 > 10){
    oct41 = oct41 - 7;}
if (oct42 > 10){
    oct42 = oct42 - 7;}            // Here, I am working with the ASCII values so if anything above 10 is remaining it'll print stuff we don't have, that's why I'm subtracting another 7 which will make A = 10 and so on //


octet1 = (oct11 * 16) + oct12;
octet2 = (oct21 * 16) + oct22;
octet3 = (oct31 * 16) + oct32;  // Where the magic happens. //
octet4 = (oct41 * 16) + oct42;



if( (octet1 < 256) && (octet2 < 256) && (octet3 < 256) && (octet4 < 256)){

        printf("Thanks it is a valid IP Address.\n");
        printf("Please enter the Subnet Mask :\n");
        scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 = sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;


if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }


else {

    printf("Please enter the Subnet Mask :\n");
    scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 =sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;


if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }


}

}

else {

    printf("Please enter the IP Address :\n");

scanf(" %c %c. %c %c. %c %c. %c %c",&oct11,&oct12,&oct21,&oct22,&oct31,&oct32,&oct41,&oct42);

oct11 = (oct11 - 48);
oct12 = (oct12 - 48);
oct21 = (oct21 - 48);
oct22 = (oct22 - 48);
oct31 = (oct31 - 48);
oct32 = (oct32 - 48);
oct41 = (oct41 - 48);
oct42 = (oct42 - 48);

if (oct11 > 10){
    oct11 = oct11 - 7;}
if (oct12 > 10){
    oct12 = oct12 - 7;}
if (oct21 > 10){
    oct21 = oct21 - 7;}
if (oct22 > 10){
    oct22 = oct22 - 7;}
if (oct31 > 10){
    oct31 = oct31 - 7;}
if (oct32 > 10){
    oct32 = oct32 - 7;}
if (oct41 > 10){
    oct41 = oct41 - 7;}
if (oct42 > 10){
    oct42 = oct42 - 7;}            // Here, I am working with the ASCII values so if anything above 10 is remaining it'll print stuff we don't have, that's why I'm subtracting another 7 which will make A = 10 and so on //


octet1 = (oct11 * 16) + oct12;
octet2 = (oct21 * 16) + oct22;
octet3 = (oct31 * 16) + oct32;  // Where the magic happens. //
octet4 = (oct41 * 16) + oct42;


if( (octet1 < 256) && (octet2 < 256) && (octet3 < 256) && (octet4 < 256)){

        printf("Thanks it is a valid IP Address.\n");
        printf("Please enter the Subnet Mask :\n");
        scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 =sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;


if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }

else {

    printf("Please enter the Subnet Mask :\n");
        scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 =sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;


if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }



}


        printf("Please enter the Subnet Mask :\n");
        scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 =sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;




}


}





origoct1 = octet1;
origoct2 = octet2;
origoct3 = octet3;
origoct4 = octet4;

origsub1 = subnet1;
origsub2 = subnet2;
origsub3 = subnet3;        // Here I prevented the user to get the binary of the subnet or the IP , and after that trying to find host addresses.
origsub4 = subnet4;         // Which is a problem because it converts the IP or the Subnet to binary twice, which concludes in wrong stuff.

origgsub1 = subnet1;
origgsub2 = subnet2;
origgsub3 = subnet3;           // This is to fix an error which caused an error using menu function 4 after the 3rd one.
origgsub4 = subnet4;

}


printf("-------------------------------------------------\n");
printf("1. Convert IP address to binary\n2. Convert subnet mask to binary\n3. Specify the class of the IP address\n4. Specify the number of host addresses available\n5. Provide new IP Address and subnet mask\n6. Exit\n");
printf("-------------------------------------------------\n");
scanf("%d",&menu);



if (menu == 1){

        binNum = 0, i = 1, remainder = 0;

        while (octet1 != 0)
        {
            remainder = octet1%2;
            octet1 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        octet1 = binNum;

        binNum = 0, i = 1, remainder = 0;

        while (octet2 != 0)
        {
            remainder = octet2%2;
            octet2 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        octet2 = binNum;

        binNum = 0, i = 1, remainder = 0;

        while (octet3 != 0)
        {
            remainder = octet3%2;
            octet3 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        octet3 = binNum;


        binNum = 0, i = 1, remainder = 0;

        while (octet4 != 0)
        {
            remainder = octet4%2;
            octet4 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        octet4 = binNum;


    printf("Binary representation of IP Address: %d.%d.%d.%d \n",octet1,octet2,octet3,octet4);



printf("-------------------------------------------------\n");
printf("1. Convert IP address to binary\n2. Convert subnet mask to binary\n3. Specify the class of the IP address\n4. Specify the number of host addresses available\n5. Provide new IP Address and subnet mask\n6. Exit\n");
printf("-------------------------------------------------\n");
scanf("%d",&menu);
}

if (menu == 2){

        binNum = 0, i = 1, remainder = 0;

        while (subnet1 != 0)
        {
            remainder = subnet1%2;
            subnet1 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        subnet1 = binNum;

        binNum = 0, i = 1, remainder = 0;

        while (subnet2 != 0)
        {
            remainder = subnet2%2;
            subnet2 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        subnet2 = binNum;

        binNum = 0, i = 1, remainder = 0;

        while (subnet3 != 0)
        {
            remainder = subnet3%2;
            subnet3 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        subnet3 = binNum;


        binNum = 0, i = 1, remainder = 0;

        while (subnet4 != 0)
        {
            remainder = subnet4%2;
            subnet4 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        subnet4 = binNum;


    printf("Binary representation of Subnet Mask: %d.%d.%d.%d \n",subnet1,subnet2,subnet3,subnet4);


printf("-------------------------------------------------\n");
printf("1. Convert IP address to binary\n2. Convert subnet mask to binary\n3. Specify the class of the IP address\n4. Specify the number of host addresses available\n5. Provide new IP Address and subnet mask\n6. Exit\n");
printf("-------------------------------------------------\n");
scanf("%d",&menu);
}

if (menu == 3){

        binNum = 0, i = 1, remainder = 0;

        while (origoct1 != 0)
        {
            remainder = origoct1%2;
            origoct1 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        origoct1 = binNum;

    printf("%d",origoct1);

    length1 = (log10(origoct1));
    length2 = (log10(origoct1)-1);
    length3 = (log10(origoct1)-2);

    first = origoct1 / pow(10,length1);
    second = origoct1 / pow(10,length2);
    third = origoct1 / pow(10,length3);

    if (first == 0){

        printf("The class of the given IP Address is: A\n");

    }

    else if (second == 10){

        printf("The class of the given IP Address is: B\n");

    }

    else if (third == 110){

        printf("The class of the given IP Address is: C\n");

    }

    else{

       printf("The class of the given IP Adress is: D\n");
    }

printf("-------------------------------------------------\n");
printf("1. Convert IP address to binary\n2. Convert subnet mask to binary\n3. Specify the class of the IP address\n4. Specify the number of host addresses available\n5. Provide new IP Address and subnet mask\n6. Exit\n");
printf("-------------------------------------------------\n");
scanf("%d",&menu);
    }

if (menu == 4){

        binNum = 0, i = 1, remainder = 0;

        while (origgsub1 != 0)
        {
            remainder = origgsub1%2;
            origgsub1 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        origgsub1 = binNum;

        binNum = 0, i = 1, remainder = 0;

        while (origgsub2 != 0)
        {
            remainder = origgsub2%2;
            origgsub2 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        origgsub2 = binNum;

        binNum = 0, i = 1, remainder = 0;

        while (origgsub3 != 0)
        {
            remainder = origgsub3%2;
            origgsub3 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        origgsub3 = binNum;


        binNum = 0, i = 1, remainder = 0;

        while (origgsub4 != 0)
        {
            remainder = origgsub4%2;
            origgsub4 /= 2;
            binNum += remainder*i;
            i *= 10;
        }
        origgsub4 = binNum;


    counter = 0;

    for (counter1=0; origgsub1 != 0 ; origgsub1=origgsub1/10){

        if (origgsub1 % 2 == 0){
            counter1++;}
    }
    for (counter2=0; origgsub2 != 0 ; origgsub2=origgsub2/10){

        if (origgsub2 % 2 == 0){
            counter2++;}
    }
    for (counter3=0; origgsub3 != 0 ; origgsub3=origgsub3/10){

        if (origgsub3 % 2 == 0){
            counter3++;}
    }
    for (counter4=0; origgsub4 != 0 ; origgsub4=origgsub4/10){

        if (origgsub4 % 2 == 0){
            counter4++;}
    }
    counter = counter1 + counter2 + counter3 + counter4;

    hosts = (pow(2,counter)) - 2;

    printf("The number of available host addresses for the given Subnet Mask: %d\n", hosts);

printf("-------------------------------------------------\n");
printf("1. Convert IP address to binary\n2. Convert subnet mask to binary\n3. Specify the class of the IP address\n4. Specify the number of host addresses available\n5. Provide new IP Address and subnet mask\n6. Exit\n");
printf("-------------------------------------------------\n");
scanf("%d",&menu);
}

if (menu == 5){

printf("Please enter the Base of your IP Address (10/16) :");
scanf("%d",&base);

while (base != 10 && base != 16){

    printf("\nSorry that is not a valid base!\n");
    printf("Please enter the Base of your IP Address (10/16) :");
    scanf("%d",&base);
}

if ( base == 10){
     printf("Please enter the IP Address :\n");
    scanf("%d.%d.%d.%d",&octet1,&octet2,&octet3,&octet4);

    if( (octet1 < 256) && (octet2 < 256) && (octet3 < 256) && (octet4 < 256)){

        printf("Thanks it is a valid IP Address.\n");
        printf("Please enter the Subnet Mask :\n");
        scanf("%d.%d.%d.%d",&subnet1,&subnet2,&subnet3,&subnet4);

        if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }

        else {

            printf("Please enter the Subnet Mask :\n");
            scanf("%d.%d.%d.%d",&subnet1,&subnet2,&subnet3,&subnet4);

        }
    }

    else{

        printf("Please enter the IP Address :\n");
        scanf("%d.%d.%d.%d",&octet1,&octet2,&octet3,&octet4);

        if( (octet1 < 256) && (octet2 < 256) && (octet3 < 256) && (octet4 < 256)){

        printf("Thanks it is a valid IP Address.\n");
        printf("Please enter the Subnet Mask :\n");
        scanf("%d.%d.%d.%d",&subnet1,&subnet2,&subnet3,&subnet4);

        if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
            }

        else {

            printf("Please enter the Subnet Mask :\n");
            scanf("%d.%d.%d.%d",&subnet1,&subnet2,&subnet3,&subnet4);

        }

        }
    }

origoct1 = octet1;
origoct2 = octet2;
origoct3 = octet3;
origoct4 = octet4;

origsub1 = subnet1;
origsub2 = subnet2;
origsub3 = subnet3;        // Here I prevented the user to get the binary of the subnet or the IP , and after that trying to find host addresses.
origsub4 = subnet4;         // Which is a problem because it converts the IP or the Subnet to binary twice, which concludes in wrong stuff.

origgsub1 = subnet1;
origgsub2 = subnet2;
origgsub3 = subnet3;           // This is to fix an error which caused an error using menu function 4 after the 3rd one.
origgsub4 = subnet4;


printf("-------------------------------------------------\n");
printf("1. Convert IP address to binary\n2. Convert subnet mask to binary\n3. Specify the class of the IP address\n4. Specify the number of host addresses available\n5. Provide new IP Address and subnet mask\n6. Exit\n");
printf("-------------------------------------------------\n");
scanf("%d",&menu);
}

else if (base == 16){

printf("\nPlease enter the IP Address :\n");

scanf(" %c %c. %c %c. %c %c. %c %c",&oct11,&oct12,&oct21,&oct22,&oct31,&oct32,&oct41,&oct42);

oct11 = (oct11 - 48);
oct12 = (oct12 - 48);
oct21 = (oct21 - 48);
oct22 = (oct22 - 48);
oct31 = (oct31 - 48);
oct32 = (oct32 - 48);
oct41 = (oct41 - 48);
oct42 = (oct42 - 48);

if (oct11 > 10){
    oct11 = oct11 - 7;}
if (oct12 > 10){
    oct12 = oct12 - 7;}
if (oct21 > 10){
    oct21 = oct21 - 7;}
if (oct22 > 10){
    oct22 = oct22 - 7;}
if (oct31 > 10){
    oct31 = oct31 - 7;}
if (oct32 > 10){
    oct32 = oct32 - 7;}
if (oct41 > 10){
    oct41 = oct41 - 7;}
if (oct42 > 10){
    oct42 = oct42 - 7;}            // Here, I am working with the ASCII values so if anything above 10 is remaining it'll print stuff we don't have, that's why I'm subtracting another 7 which will make A = 10 and so on //


octet1 = (oct11 * 16) + oct12;
octet2 = (oct21 * 16) + oct22;
octet3 = (oct31 * 16) + oct32;  // Where the magic happens. //
octet4 = (oct41 * 16) + oct42;


if( (octet1 < 256) && (octet2 < 256) && (octet3 < 256) && (octet4 < 256)){

        printf("Thanks it is a valid IP Address.\n");
        printf("Please enter the Subnet Mask :\n");
        scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 =sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;


if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }


else {

    printf("Please enter the Subnet Mask :\n");
        scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 =sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;


if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }


}

}

else {

    printf("Please enter the IP Address :\n");

scanf(" %c %c. %c %c. %c %c. %c %c",&oct11,&oct12,&oct21,&oct22,&oct31,&oct32,&oct41,&oct42);

oct11 = (oct11 - 48);
oct12 = (oct12 - 48);
oct21 = (oct21 - 48);
oct22 = (oct22 - 48);
oct31 = (oct31 - 48);
oct32 = (oct32 - 48);
oct41 = (oct41 - 48);
oct42 = (oct42 - 48);

if (oct11 > 10){
    oct11 = oct11 - 7;}
if (oct12 > 10){
    oct12 = oct12 - 7;}
if (oct21 > 10){
    oct21 = oct21 - 7;}
if (oct22 > 10){
    oct22 = oct22 - 7;}
if (oct31 > 10){
    oct31 = oct31 - 7;}
if (oct32 > 10){
    oct32 = oct32 - 7;}
if (oct41 > 10){
    oct41 = oct41 - 7;}
if (oct42 > 10){
    oct42 = oct42 - 7;}            // Here, I am working with the ASCII values so if anything above 10 is remaining it'll print stuff we don't have, that's why I'm subtracting another 7 which will make A = 10 and so on //


octet1 = (oct11 * 16) + oct12;
octet2 = (oct21 * 16) + oct22;
octet3 = (oct31 * 16) + oct32;  // Where the magic happens. //
octet4 = (oct41 * 16) + oct42;


if( (octet1 < 256) && (octet2 < 256) && (octet3 < 256) && (octet4 < 256)){

        printf("Thanks it is a valid IP Address.\n");
        printf("Please enter the Subnet Mask :\n");
        scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 =sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;


if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }

else {

    printf("Please enter the Subnet Mask :\n");
        scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 =sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;


if ((subnet1<256)&&(subnet2<256)&&(subnet3<256)&&(subnet4<256)){

            printf("Thanks it is a valid Subnet Mask.\n");
        }



}


        printf("Please enter the Subnet Mask :\n");
        scanf(" %c %c. %c %c. %c %c. %c %c",&sub11,&sub12,&sub21,&sub22,&sub31,&sub32,&sub41,&sub42);

sub11 = sub11 - 48;
sub12 = sub12 - 48;
sub21 = sub21 - 48;
sub22 = sub22 - 48;
sub31 = sub31 - 48;
sub32 = sub32 - 48;
sub41 = sub41 - 48;
sub42 = sub42 - 48;

if (sub11 > 10){
    sub11 = sub11 - 7;}
if (sub12 > 10){
    sub12 = sub12 - 7;}
if (sub21 > 10){
    sub21 = sub21 - 7;}
if (sub22 > 10){
    sub22 = sub22 - 7;}
if (sub31 > 10){
    sub31 = sub31 - 7;}
if (sub32 > 10){
    sub32 = sub32 - 7;}
if (sub41 > 10){
    sub41 = sub41 - 7;}
if (sub42 > 10){
    sub42 =sub42 - 7;}


subnet1 = (sub11 * 16) + sub12;
subnet2 = (sub21 * 16) + sub22;
subnet3 = (sub31 * 16) + sub32;  // Where the magic happens. //
subnet4 = (sub41 * 16) + sub42;




}


}





origoct1 = octet1;
origoct2 = octet2;
origoct3 = octet3;
origoct4 = octet4;

origsub1 = subnet1;
origsub2 = subnet2;
origsub3 = subnet3;        // Here I prevented the user to get the binary of the subnet or the IP , and after that trying to find host addresses.
origsub4 = subnet4;         // Which is a problem because it converts the IP or the Subnet to binary twice, which concludes in wrong stuff.


printf("-------------------------------------------------\n");
printf("1. Convert IP address to binary\n2. Convert subnet mask to binary\n3. Specify the class of the IP address\n4. Specify the number of host addresses available\n5. Provide new IP Address and subnet mask\n6. Exit\n");
printf("-------------------------------------------------\n");
scanf("%d",&menu);

                }


            }

        }


return 0;
    }


