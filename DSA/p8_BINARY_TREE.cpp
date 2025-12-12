#include        <stdio.h>
//#include        <conio.h>
#include        <stdlib.h>

typedef struct TreeData
{
        int key;
}Record;

typedef struct Node *ListPointer;
typedef struct Node
{
        ListPointer lLink;
        Record data;
        ListPointer rLink;
}Node;

ListPointer tree;

Record getNextRecord ( void )
{
        Record data;
        
        scanf ( "%d", &data.key );

        return data;
}

ListPointer getNode ( Record data )
{
        ListPointer temp;
        
        temp = ( ListPointer ) malloc ( sizeof ( *temp ) );
        
        if ( temp == NULL )
        {
                printf( "\n\n Allocation Failed\n\n" );
                getchar(); //getch();
                exit( EXIT_FAILURE );
        }
        else
        {
                temp->data = data;
                temp->lLink = temp->rLink = NULL;
        }
        
        return temp;
}

void inorder( ListPointer tree )
{
        if ( tree )
        {
                inorder( tree->lLink );
                printf( "%d\t", tree->data.key );
                inorder( tree->rLink );
        }
}

void preorder( ListPointer tree )
{
        if( tree )
        {
                printf( "%d\t", tree->data.key );
                preorder ( tree->lLink );                
                preorder ( tree->rLink );
        }
}

void postorder ( ListPointer tree )
{
        if ( tree )
        {
                postorder ( tree->lLink );                
                postorder ( tree->rLink );
                printf( "%d\t", tree->data.key );
        }
}

ListPointer modifiedSearch ( ListPointer tree, Record data )
{
        ListPointer parent = NULL;
        
        while ( tree )
        {
                parent = tree;
                if ( data.key == tree->data.key )
                {
                        return NULL;
                }
                if ( data.key < tree->data.key )
                {
                        tree = tree->lLink;
                }
                else
                {
                        tree = tree->rLink;
                }                 
        }
        return parent;
}

void insert ( Record data )
{
        ListPointer ptr, temp = modifiedSearch ( tree, data);
        if ( temp || !tree )
        {
                ptr = getNode( data );
                if ( tree )
                {
                        if ( data.key < temp->data.key )
                        {
                                temp->lLink = ptr;
                        }
                        else
                        {
                                temp->rLink = ptr;
                        }                                 
                }                        
                else 
                {
                        tree = ptr;
                }
        }
}        

int search(ListPointer tree, int key) {
   ListPointer current = tree;

   while (current != NULL) {
       if (key == current->data.key) {
           return 1; // Found
       } else if (key < current->data.key) {
           current = current->lLink; // Go left
       } else {
           current = current->rLink; // Go right
       }
   }
   return 0; // Not found
}

int main ( void )
{
        Record data;
        int nRecords;
        int choice;
        int i;
        
        printf("\n.. BINARY SEARCH TREE DEMONSTRATION ..\n");
        printf( "\n\n1. Insert\n");
        printf( "\n2. Inoreder \t3. Preorder \t4. Postorder\n");
printf( "\n5. Search\n");
        printf( "\n5. Exit\n");
        
        while ( 1 )
        {
                printf ( "\n\nChoice: " );
                scanf ( "%d", &choice );
                
                switch ( choice )
                {
                        case 1: printf("\n.. * INSERTION ..\n");
                                        printf( "\nHow many RECORDS: " );
                                    scanf( "%d", &nRecords );
                                        
                                        printf("\nGive %d record details one by one\n", nRecords);
                                        for ( i = 0; i < nRecords; ++ i )
                                        {
                                                data = getNextRecord();
                                                insert ( data );                                
                                        }
                                        break;
                        case 2: if ( tree )
                                        {
                                                printf( "\n\nInorder Traversal\n\n" );
                                                inorder ( tree );
                                        }
                                        else printf( "\n\nBST is Empty\n\n" );
                                        break;
                        case 3: if ( tree )
                                        {
                                                printf( "\n\nPreorder Traversal\n\n" );
                                                preorder ( tree );
                                        }
                                        else 
                                        {
                                                printf( "\n\nBST is Empty\n\n" );
                                        }
                                        break;
                        case 4: if ( tree )
                                        {
                                                printf( "\n\nPostorder Traversal\n\n" );
                                                postorder ( tree );
                                        }
                                        else 
                                        {
                                                printf( "\n\nBST is Empty\n\n" );
                                        }                                                 
                                        break;
                        case 5:
                                        printf("\n.. * SEARCH ..\n");
                                        printf("\nEnter key to search: ");
                                        scanf("%d", &data.key);
                                        if (search(tree, data.key)) {
                                                printf("Key %d found in the BST.\n", data.key);
                                        } else {
                                                printf("Key %d not found in the BST.\n", data.key);
                                        }
                                        break;

                        case 6: return 0;
                        
                        default: printf( "\nWrong Choice\n" );
                }
        }
}


