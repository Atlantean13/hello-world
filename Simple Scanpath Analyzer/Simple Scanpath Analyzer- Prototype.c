#include<stdio.h>
#include<stdlib.h>

// Abdullah Küçük 2243533
// *A*T*L*A*N*T*I*S* //

struct graphHead{
	int count;
	struct graphVertex *first;
};

struct graphVertex{
	struct graphVertex *next;
	char data[15]; //Data to save in a node/vertex
	int processed; //Can be used a flag, such as visited or unvisited in traversal
	struct graphArc *firstArc;
};

struct graphArc{
	struct graphVertex *destination;
	struct graphArc *next;
	float similarity; //Storing similarity amount to print later.
};

struct graphHead * createGraph(void){
	struct graphHead *head = (struct graphHead *)malloc(sizeof(struct graphHead));
	head->count = 0;
	head->first = NULL;
	return head;
}

//Inserting / creating vertex.
void insertVertex(struct graphHead * head, char filename[]){

    char string[15];
    struct graphVertex *vertex;
    int i;
    FILE* fp;
    fp = fopen(filename,"r");
   while( fgets (string, 15, fp)!=NULL ){
       // string = fgets(filename);
        vertex = (struct graphVertex *)malloc(sizeof(struct graphVertex));
        vertex->next = NULL;
        strcpy(vertex->data,string);
        vertex->firstArc = NULL;
        head->count++;
        if(head->first == NULL){
            head->first = vertex;
        }
        else{
            struct graphVertex *temp = head->first;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = vertex;
        }
    }
    fclose(fp);
    printf("%s is the data",head->first->data);
    printf("%s is the data",head->first->next->data);
    printf("%s is the data",head->first->next->next->data);             //Checking if the data is placed correctly, can be commented out.
    printf("%s is the data",head->first->next->next->next->data);
    printf("%s is the data",head->first->next->next->next->next->data);

}
//Inserting / creating edges.
int insertArc(struct graphHead *head){

    int S,big;
	struct graphArc *arc = (struct graphArc *) malloc(sizeof(struct graphArc));
	struct graphVertex *fromVertex = NULL, *toVertex = NULL;

	struct graphArc *tempArc = NULL;
	fromVertex = head->first;

    while(fromVertex!=NULL)
    {
        toVertex = fromVertex->next;
        while(toVertex!=NULL)
        {

            if(strlen(toVertex->data) > strlen(fromVertex->data)){
                big = strlen(toVertex->data);
            }
            else{
                big = strlen(fromVertex->data);

            }
            S = 100* (1 - (editDist(fromVertex->data,toVertex->data,strlen(fromVertex->data),strlen(toVertex->data))/big)); //Finding similarity here.
            arc->destination = toVertex;
            tempArc = fromVertex->firstArc;

            if (S>50){

                if (tempArc == NULL){
            fromVertex->firstArc = arc;
            arc->similarity = S;
            arc->next = NULL;
            return 1; //Success as the first arc
                }

                else{
                    while(tempArc->next != NULL){
                        tempArc = tempArc->next;
                    }
                    tempArc->next = arc;
                    arc->next= NULL;
                    return 1; //Success as the last arc
                }
            }
        }
    }
}

int editDist(char s1[], char s2[], int m, int n) {
    if (m == 0)
    return n;
    if (n == 0)
    return m;                       //Given in the assignment pdf for editing distance that helps us find Similarity.
    if (s1[m - 1] == s2[n - 1])
    return editDist (s1, s2, m - 1, n - 1);
    return 1 + min(editDist(s1, s2, m, n - 1), editDist(s1, s2, m - 1, n), editDist(s1, s2, m - 1, n - 1));
}

int min(int a,int b,int c)
{
    if( (a<b) && (a<c) )
   {
      return a;
   }
   else if(b<c)
   {
      return b;         //Comparing function to find min.
   }
   else
   {
      return c;
   }
}

void displayGraph(struct graphHead * head){
	struct graphVertex *tempVertex = NULL;
	struct graphArc * tempArc = NULL;

	tempVertex = head->first;
	while(tempVertex != NULL){
		printf("Vertex (Data: %d-)\n", tempVertex->data);
		tempArc = tempVertex->firstArc;
		printf("Arcs:\n");
		while(tempArc != NULL){
			printf("Destination (Data: %d)\n", tempArc->destination->data);
			tempArc = tempArc->next;
		}
		printf("\n");
		tempVertex = tempVertex->next;
	}
}  //Printing function.. work in progress.


//Testing purposes!
int main(){
	struct graphHead *head = createGraph();
    char name[50];
    printf("Enter the name of the file: ");
    scanf("%s",name);
    insertVertex(head,name);
    insertArc(head);
    displayGraph(head);
	return 0;
}
